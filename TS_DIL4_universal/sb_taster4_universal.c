/*
 *    _____ ______ __   __________  __  _______ *
 *   / ___// ____// /  / ____/ __ )/ / / / ___/ *
 *   \__ \/ __/  / /  / /__ / __  / / / /\__ \  *
 *  ___/ / /__  / /__/ /__// /_/ / /_/ /___/ /  *
 * /____/_____//____/_/   /_____/\____//____/   *
 *
 *  Copyright (c) 2014, Andreas Krieger
 *  Copyright (c) 2014-2015, Stefan Haller
 *  Copyright (c) 2015, Erkan Colak
 *  Copyright (c) 2008,2009,2010 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

/************************************************************************************************
* Device Info:
*     Herstellercode 0x004C = R. Bosch
*     Devicetype  = SB Taster, 4-fach
* Changes:
*    1.00  erste Version;
*    1.01    Bugfix ProgLED/BetriebsLED liegt auf Bit 0
*    1.02    Bugfix 1-Flächendimmer, Lichtszene
*    1.03    Bugfix Helligkeitswert nur 1x speichern, Remove NOPROGBUTTON
************************************************************************************************/

#include "sb_app_taster4_universal.h"
#include "watchdog.h"

#include "fb_rs232.h"

#define VERSION 103

/***********************************************
Include 4Sense_Universal
***********************************************/
#define DHT
//#define DS_SERIES
#include "..\..\4sense_universal\4Sense_Uni.c"
/************************************************/
#ifdef DHT
  unsigned char cSensorType;
  #define DHT_CHAN 1                 // PX_DHT_CHAN -> PX_1
#endif
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

unsigned int __idata __at (0xFE-18)object_value[9];  // wird hier deklariert um den Speicher besser auszunutzen!!!
unsigned char bitobject;                             // fuer die unteren 8 Bitobjekte

/*
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
*/
void main(void)
{
  unsigned char n,tasterpegel=0,val=0,x;
  __bit blink, tastergetoggelt=0;
  static __code unsigned char __at (EEPROM_ADDR +0xFE) LED_hell;

  // ***************************************************************************
  // Initialize
  // ***************************************************************************
  restart_hw();       // Hardware zuruecksetzen
  TASTER=0;

  // Warten bis Bus stabil, nach Busspannungswiederkehr
  for (n=0;n<50;n++)
  {
    TR0=0;                  // Timer 0 anhalten
    TH0=eeprom[ADDRTAB+1];  // Timer 0 setzen mit phys. Adr. damit Geraete unterschiedlich beginnen zu senden
    TL0=eeprom[ADDRTAB+2];
    TF0=0;                  // ueberlauf-Flag zuruecksetzen
    TR0=1;                  // Timer 0 starten
    while(!TF0);
  }

  WATCHDOG_INIT
  WATCHDOG_START
  restart_app();            // Anwendungsspezifische Einstellungen zuruecksetzen
  
  // ***************************************************************************
  // main loop
  // ***************************************************************************
  do 
  { 
    WATCHDOG_FEED

    if ( RTCCON>=0x80 )                       // Realtime clock ueberlauf und wenn connected den timeout für Unicast connect behandeln
    {
      RTCCON=0x61;                            // RTC flag löschen
      if( connected )
      {
        if(connected_timeout <= 110)          // 11x 520ms --> ca 6 Sekunden
        {           
          connected_timeout++;
        } 
        else 
        {
          send_obj_value(T_DISCONNECT);       // wenn timeout dann disconnect, flag und var wird in build_tel() gelöscht
        }
      }
      else // !connected
      {
        delay_timer();                        // die normal RTC Behandlung
      }
    }
    n = timer;                                // Zeittakt holen
    
    // ***************************************************************************
    // APPLICATION_RUN
    // ***************************************************************************
    if(APPLICATION_RUN)                       // nur wenn im Run modus
    {
      if(RTCCON>=0x80) delay_timer();         // Realtime clock Ueberlauf

      if ((PORT & 0x0F) != button_buffer) 
      {
        port_changed(PORT & 0x0F);            // ein Taster wurde gedrueckt
      }

#ifdef DS_SERIES
      if(eeprom[0xFC]&0x80) { // Temperatur sensor measurement activated? ( No need sensor type  check! DS is comppiled!)
        if (sequence==1) {
          interrupted=0;
          start_tempconversion();                              // Konvertierung starten
          if (!interrupted) sequence=2;
        }
        else if (sequence==2) {
          if (ow_read_bit()) sequence=3;                       // Konvertierung abgeschlossen
        }
        else if (sequence==3) {                                // 
          int iReadTemp=read_temp();                           // Read temperature with auto detected sensor type
          // Bei Sensorfehler wird kein Messwert mehr gesendet
          // TODO Fehler Com-Objekt einfuegen??
          if(iReadTemp >-5600) {
            object_value[4]=eis5conversion(iReadTemp + ((signed char)(eeprom[0xFD]))*10); //nur positive Temperaturen, Offset verrechnen
            send_obj_value(12);
            timercnt[8]=eeprom[0xFB];
          } else {
            timercnt[8]=0x01;   // Restart after 1 second
          }
          // TODO, warum schreiben wir die base immer neu??
          timerbase[8]=eeprom[0xFC]&0x07; //Timer for temperature
          sequence=0; // wenn wir hier sind haben wir einen gueltigen Messwert, neustart durch timer (delay_timer)
          /*  // DIES IST DER PI REGLER
          solltemp = (((int)eeprom [0xE9]<<8 )| eeprom[0xEA])*10;
          spreizung = eeprom[0xED];
          if (iRetTemp<solltemp) val=1;
          if (iRetTemp>solltemp) val=0;
          object_value[6]=val;
          if(iRetTemp<solltemp) {
            if((solltemp-iRetTemp)<=spreizung) { 
              object_value[7]=((solltemp-iRetTemp)*255)/spreizung;
            } else { 
              object_value[7]=255;
            }
          } else {
            object_value[7]=0;
          }
          send_obj_value(4);
          send_obj_value(13);
          */
        } // else if(sequence==3 ...
      } // if(eeprom ...
#endif // #ifdef DS_SERIES
#ifdef DHT
      // Is sensor activated?
      // If sensor is activated, cSensorType is sense type.
      if( (cSensorType= (eeprom[0xFC]&0x80) ? ((eeprom[0xFC]&0x10) ? DHT2x_SENSOR : DHT1x_SENSOR) :2) < 2) // Is the sensor measurement activated and is sensor type  0:DHT1x_SENSOR or 1:DHT2x_SENSOR ? ( 0:DHT1x_SENSOR 1:DHT2x_SENSOR 2:DS_SERIES )
      {
        // eeprom[0xFC]: DHT/Temp Config
        // Bit 7 -> Temperature sensor: ON/OFF for DHT and DS
        // Bit 5 -> Relative humidity sensor: ON/OFF  for DHT 
        // Bit 4 -> DHT sensor type: 0:DHT1x_SENSOR 1:DHT2x_SENSOR
        if( sequence==1 ) // min 2 sec. delay
        { 
          if(cSensorType == DHT1x_SENSOR)
          {
            dht1x_init(DHT_CHAN);               // Initialize. Need only for DTH1x Sensor
          }
          if(dht_ow_receive(DHT_CHAN) == 0)     // Receive Temperature and Relative humidity
          {
            if(dht_decode(cSensorType))         // Decode Temperature and Relative humidity
            {
              if(dht_temp  >-5600 &&            // dht_temp   -> Temperature in C°          [min:-40 C° max:+80 C° ]
                 dht_humid >-1      )           // dht_humid  -> Relative humidity in %RH   [min:0 %RH  max:99,9 %RH ]
              {
                object_value[4]=eis5conversion(dht_temp + ((signed char)(eeprom[0xFD]))*10); //nur positive Temperaturen, Offset verrechnen
                send_obj_value(12);             // send dht_temp to com-object 12 offset to adress 0xFD
                if(eeprom[0xFC]&0x20)
                {
                  object_value[6]=eis5conversion(dht_humid + ((signed char)(eeprom[0xFA]))*10); //nur positive humidity, Offset verrechnen
                  send_obj_value(14);           // send dht_humid to com-object 14 offset to adress 0xFA
                }
                timercnt[8]=eeprom[0xFB];
              } else {
                timercnt[8]=0x01;               // Restart after 1 second
              }
            }
          }
          timerbase[8]= eeprom[0xFC]&0x07; // Timer for temperature
          sequence= 0; // to restart the timer, set here to 0 (restart will be set in (delay_timer))
        } // if(sequence==1...
      } // if((cSensorType=...
#endif // #ifdef DHT
    } //if(APLICATION RUN??..

    // ***************************************************************************
    // LED Behandlung
    // ***************************************************************************
    val=0;  // val ist hier pattern fuer das LED Blinken.
    blink=((n >>3)&0x01);
    for (x=0;x<4;x++)
    {
      val |=((~((eeprom[0xE3 + x]>>7)&0x01))|blink)<<(x+4);
    }
    LEDVAL=LEDSTATE & val;

    // ***************************************************************************
    // Telegrammverarbeitung
    // ***************************************************************************
    if (tel_arrived || tel_sent) { tel_sent=0; process_tel(); } 
    else { for(n=0;n<100;n++); } // falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann

    // ***************************************************************************
    // Tasterabfrage
    // ***************************************************************************
    TASTER=1;                               // Pin als Eingang schalten um Programmiertaster abzufragen
    if(!TASTER)                             // Taster gedrueckt
    { 
      if(tasterpegel<255) tasterpegel++;
      else 
      { if(!tastergetoggelt) 
        {
          tastergetoggelt=1;
          status60^=0x81;                   // Prog-Bit und Parity-Bit im system_state toggeln
        } 
      } 
    } else { if(tasterpegel>0) tasterpegel--; else tastergetoggelt=0; }

    // ***************************************************************************
    // Prog LED
    // ***************************************************************************
    if (status60 & 0x01) TASTER = blink;    // LED leuchtet im Prog-Mode
    else TASTER = !(eeprom[0xE2] & 0x01);   // LED ON/OFF read from eeprom

  } while(1); // do
}
