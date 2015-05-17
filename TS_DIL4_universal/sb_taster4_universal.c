/*
 *    _____ ______ __   __________  __  _______ *
 *   / ___// ____// /  / ____/ __ )/ / / / ___/ *
 *   \__ \/ __/  / /  / /__ / __  / / / /\__ \  *
 *  ___/ / /__  / /__/ /__// /_/ / /_/ /___/ /  *
 * /____/_____//____/_/   /_____/\____//____/   *
 *
 *  Copyright (c) 2008,2009,2010 Andreas Krebs <kubi@krebsworld.de>
 *  Copyright (c) 2014, Andreas Krieger
 *  Copyright (c) 2014-2015, Stefan Haller
 *  Copyright (c) 2015, Erkan Colak
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

#include "sb_app_taster4_universal.h"
#include "watchdog.h"

#include "fb_rs232.h"

#define VERSION 103

/***********************************************
Define and Include 4Sense_Universal
***********************************************/
//#define DHT                                                                                             // Define DHT to enable DHT-Sensor support
#define DS_SERIES                                                                                     // Define DS_SERIES to enable DS-Sensor support
#ifdef DHT
  #define DHT_CHAN 1                                                                                    // PX_DHT_CHAN -> PX_1
#endif
/************************************************/
#include "..\..\4sense_universal\4Sense_Uni.c"
/************************************************/

#ifndef DEBUG_H_
// Wenn Debug aktiv ist werden die Werte in der restart_app() geschrieben damit die Konfiguration nicht
// immer neu geschrieben werden muss.
// Geraeteparameter setzen, diese können von der ETS uebschrieben werden wenn Schreibschutz nicht aktiv
__code unsigned char __at (EEPROM_ADDR +0x03) manufacturer[2]={0x00,0x4C};  // Herstellercode 0x004C = Bosch
__code unsigned char __at (EEPROM_ADDR +0x05) device_type[2]={0x04, 0x56};  // 0x0456 = Selfbus Taster4_universal
__code unsigned char __at (EEPROM_ADDR +0x0C) port_A_direction={0};         // PORT A Direction Bit Setting
__code unsigned char __at (EEPROM_ADDR +0x0D) run_state={255};              // Run-Status (00=stop FF=run)
__code unsigned int  __at (EEPROM_ADDR +0x17) start_pa={0xFFFF};            // Default PA is 15.15.255
#endif

#ifdef DEBUG_H_
  #warning Debug is active! UART is listening to the Debugger now!
  DEBUG_VARIABLES;
#endif

unsigned int __idata __at (0xFE-18)object_value[9];                                                     // wird hier deklariert um den Speicher besser auszunutzen!!!
unsigned char bitobject;                                                                                // fuer die unteren 8 Bitobjekte

/*******************************************************************************
* The start point of the program, init all libraries, start the bus interface,
* the application and check the status of the program button.
********************************************************************************/
void main(void)
{
  unsigned char n,tasterpegel=0,val=0,x; __bit blink, tastergetoggelt=0; 
  static __code unsigned char __at (EEPROM_ADDR +0xFE) LED_hell;

  // ***************************************************************************
  // Initialize
  // ***************************************************************************
  restart_hw(); TASTER=0;                                                                               // Reset the Hardware
  

  // ***************************************************************************
  // Wait until the bus is stable (nach Busspannungswiederkehr)
  // ***************************************************************************
  for (n=0;n<50;n++) { TR0=0;                                                                           // Timer 0 anhalten
    TH0=eeprom[ADDRTAB+1]; TL0=eeprom[ADDRTAB+2];                                                       // Timer 0 setzen mit phys. Adr. damit Geraete unterschiedlich beginnen zu senden
    TF0=0;                                                                                              // ueberlauf-Flag zuruecksetzen
    TR0=1;                                                                                              // Timer 0 starten
    while(!TF0); 
  }

  WATCHDOG_INIT
  WATCHDOG_START
  restart_app();                                                                                        // RESET application specific settings
  
  // ***************************************************************************
  // main loop
  // ***************************************************************************
  do 
  { 
    WATCHDOG_FEED
    if ( RTCCON>=0x80 ) {                                                                               // RealTimeClock overflow. If connected handle timeout for Unicast connect
      RTCCON=0x61;                                                                                      // Delete RealTimeClock RTC flag
      if( connected ) { if(connected_timeout <= 110) { connected_timeout++; }                           // 11x 520ms --> appr. 6 Sec.
      else { send_obj_value(T_DISCONNECT); } }                                                          // if timeout then disconnect, flag and var will be deleted in build_tel()
      else { delay_timer(); }                                                                           // !connected. Then normal RTC handling
    } n = timer;                                                                                        // get timer
    
    // ***************************************************************************
    // APPLICATION_RUN
    // ***************************************************************************
    if(APPLICATION_RUN)                                                                                 // only in run mode
    {
      if(RTCCON>=0x80) delay_timer();                                                                   // RealTimeClock overflow
      if ((PORT & 0x0F) != button_buffer) { port_changed(PORT & 0x0F); }                                // A button is pressed
#ifdef DS_SERIES
      if(eeprom[0xFC]&0x80) {                                                                           // Is the Sensor measurement activated? ( No need sensor type  check! DS is comppiled!)
        if (sequence==1) { interrupted=0; start_tempconversion(); if (!interrupted) sequence=2; }       // Konvertierung starten
        else if (sequence==2) { if (ow_read_bit()) sequence=3; }                                        // Konvertierung abgeschlossen
        else if (sequence==3) { int iReadTemp=read_temp();                                              // Read temperature with auto detected sensor type
          if(iReadTemp >-5600) {                                                                        // TODO: Fehler Com-Objekt einfuegen: Bei Sensorfehler wird kein Messwert mehr gesendet
            object_value[4]=eis5conversion(iReadTemp + ((signed char)(eeprom[0xFD]))*10);               // only positive temperatures + calc the Offset
            send_obj_value(12); timercnt[8]=eeprom[0xFB];
          } else { timercnt[8]=0x01; }                                                                  // Restart after 1 second
          // TODO: Warum schreiben wir die base immer neu??
          timerbase[8]=eeprom[0xFC]&0x07;                                                               //Timer for temperature
          sequence=0;                                                                                   // Here we got a valid value. Restart will be triggert  by the timer (delay_timer)
        } // else if(sequence==3 ...
      } // if(eeprom ...
#endif // #ifdef DS_SERIES
#ifdef DHT
      // eeprom[0xFC]: DHT/Temp Config
      // Bit 7 -> Temperature sensor: ON/OFF for DHT and DS
      // Bit 5 -> Relative humidity sensor: ON/OFF  for DHT 
      // Bit 4 -> DHT sensor type: 0:DHT1x_SENSOR 1:DHT2x_SENSOR
      if(eeprom[0xFC]&0x80 && sequence == 1 )                                                           // Is the Sensor measurement activated? and min 2 sec. delay
      {
        if((eeprom[0xFC]&0x10) ? DHT2x_SENSOR : DHT1x_SENSOR == DHT1x_SENSOR) { dht1x_init(DHT_CHAN); } // Initialize. Need only for DTH1x Sensor
        if(dht_ow_receive(DHT_CHAN) == 0) {                                                             // Receive Temperature and Relative humidity
          if(dht_decode((eeprom[0xFC]&0x10) ? DHT2x_SENSOR : DHT1x_SENSOR)) {                           // Decode Temperature and Relative humidity
            if(dht_temp  >-5600 && dht_humid >-1 ) {                                                    // dht_temp   -> Temperature in C° [min:-40 C° max:+80 C° ]  and dht_humid  -> Relative humidity in %RH [min:0 %RH  max:99,9 %RH ]
              object_value[4]=eis5conversion(dht_temp + ((signed char)(eeprom[0xFD]))*10);              // nur positive Temperaturen, Offset verrechnen
              send_obj_value(12);                                                                       // send dht_temp to com-object 12 offset to adress 0xFD
              if(eeprom[0xFC]&0x20) {
                object_value[6]=eis5conversion(dht_humid + ((signed char)(eeprom[0xFA]))*10);           // nur positive humidity, Offset verrechnen
                send_obj_value(14);                                                                     // send dht_humid to com-object 14 offset to adress 0xFA
              } timercnt[8]=eeprom[0xFB]; 
            } else { timercnt[8]=0x01; }                                                                // Restart after 1 second
          }// if(dht_decode...
        } // if(dht_ow_receive...
        timerbase[8]= eeprom[0xFC]&0x07;                                                                // Timer for temperature
        sequence= 0;                                                                                    // to restart the timer, set here to 0 (restart will be set in (delay_timer))
      } // if(eeprom[0xFC]&0x80...
#endif // #ifdef DHT
    } //if(APLICATION RUN??..

    // ***************************************************************************
    // LED Behandlung
    // ***************************************************************************
    val=0;  // val ist hier pattern fuer das LED Blinken.
    blink=((n >>3)&0x01);
    for (x=0;x<4;x++) { val |=((~((eeprom[0xE3 + x]>>7)&0x01))|blink)<<(x+4); }
    LEDVAL=LEDSTATE & val;

    // ***************************************************************************
    // Telegrammverarbeitung
    // ***************************************************************************
    if (tel_arrived || tel_sent) { tel_sent=0; process_tel(); } 
    else { for(n=0;n<100;n++); }                                                                          // falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann

    // ***************************************************************************
    // Tasterabfrage
    // ***************************************************************************
    TASTER=1;                                                                                             // Pin als Eingang schalten um Programmiertaster abzufragen
    if(!TASTER) {                                                                                         // Taster gedrueckt
      if(tasterpegel<255) tasterpegel++;
      else { if(!tastergetoggelt) { tastergetoggelt=1; status60^=0x81; } }                                // Prog-Bit und Parity-Bit im system_state toggeln
    } else { if(tasterpegel>0) tasterpegel--; else tastergetoggelt=0; }

    // ***************************************************************************
    // Prog LED
    // ***************************************************************************
    if (status60 & 0x01) TASTER = blink;                                                                  // LED leuchtet im Prog-Mode
    else TASTER = !(eeprom[0xE2] & 0x01);                                                                 // LED ON/OFF read from eeprom

  } while(1); // do
}
