/*
 *    _____ ______ __   __________  __  _______ *
 *   / ___// ____// /  / ____/ __ )/ / / / ___/ *
 *   \__ \/ __/  / /  / /__ / __  / / / /\__ \  *
 *  ___/ / /__  / /__/ /__// /_/ / /_/ /___/ /  *
 * /____/_____//____/_/   /_____/\____//____/   *
 *
 *  Copyright (c) 2014, Andreas Krieger
 *  Copyright (c) 2014, Stefan Haller
 *  Copyright (c) 2008,2009,2010 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
/**
* @file   sb_taster4_universal.c
* @date   2014
*
* @brief The Selfbus Taster Application, Firmware fuer einen 4-fach Taster mit 4 LEDs
*		 Herstellercode 0x004C = R. Bosch
*		 Devicetype  = SB Taster, 4-fach
*
* \par Changes:
*		1.00    erste Version
*       1.01    Bugfix ProgLED/BetriebsLED liegt auf Bit 0
*/

#include "sb_app_taster4_universal.h"
#include "watchdog.h"

#include "fb_rs232.h"
#include "onewire.h"

// Options
#define SENSOR_TYPE     0   // !=1 DS18B20

#define NOPROGLED //typ 0,2 Die Progled blinkt im Progmodus da sie auch Betriebs LED ist
//#define NOPROGBUTTON	//typ 1,3 es ist kein prog Taster vorhanden sondern progmode wird durch druecken von taste 1&3 oder 2&4 aktiviert


#ifndef DEBUG_H_
// Wenn Debug aktiv ist werden die Werte in der restart_app() geschrieben damit die Konfiguration nicht
// immer neu geschrieben werden muss.
// Geraeteparameter setzen, diese können von der ETS uebschrieben werden wenn Schreibschutz nicht aktiv
__code unsigned char __at (EEPROM_ADDR +0x03) manufacturer[2]={0x00,0x4C};  // Herstellercode 0x004C = Bosch
__code unsigned char __at (EEPROM_ADDR +0x05) device_type[2]={0x04, 0x56};  // 0x0456 = Selfbus Taster4_universal
__code unsigned char __at (EEPROM_ADDR +0x0C) port_A_direction={0};         // PORT A Direction Bit Setting
__code unsigned char __at (EEPROM_ADDR +0x0D) run_state={255};              // Run-Status (00=stop FF=run)
__code unsigned int __at  (EEPROM_ADDR +0x17) start_pa={0xFFFF};            // Default PA is 15.15.255
#endif



// DEBUG
// Temperatur Sensor
unsigned char sequence;
int th;
int temp;
unsigned int solltemp;
unsigned char spreizung;



#ifdef NOPROGBUTTON
	#ifdef NOPROGLED
		#define TYPE 3
	#else
		#define TYPE 1
	#endif
#else
	#ifdef NOPROGLED
		#define TYPE 2
	#else
		#define TYPE 0
	#endif
#endif

#define VERSION		101

#ifdef DEBUG_H_
    #warning Debug is active! UART is listening to the Debugger now!
	DEBUG_VARIABLES;
#endif

unsigned int __idata __at (0xFE-18)object_value[9];	// wird hier deklariert um den Speicher besser auszunutzen!!!
unsigned char bitobject; // fuer die unteren 8 Bitobjekte

/**
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
*
* @return
*/
void main(void)
{
	unsigned char n,tasterpegel=0,val=0,x;//
	__bit blink, verstell, verstellt,tastergetoggelt=0;

	signed char buttonpattern=1;
//	static __code signed char __at (USERRAM_ADDR + 0xBF) trimsave;
	static __code unsigned char __at (EEPROM_ADDR +0xFE) LED_hell;

	// Verions bit 6 und 7 fuer die varianten, bit 0-5 fuer die verionen (63)
	//Varianten sind hier noprogbutton=0x040, noprogled=0x80
	__bit wduf;

	wduf=WDCON&0x02;
	verstellt;verstell;

	restart_hw();							// Hardware zuruecksetzen
	// TODO, sequence in restart_app verschieben
	sequence=1;
/*
#ifdef NOPROGBUTTON
	if((((PORT & 0x0F)== 0x03) || ((PORT & 0x0F)== 0x0C)) && wduf) cal=0;
//	else cal=trimsave;

#else
	TASTER=1;
	if(!TASTER && wduf)cal=0;
//	else cal=trimsave;
#endif
	TRIM = (TRIM+trimsave);
	TRIM &= 0x3F;				//oberen 2 bits ausblenden
*/
	WATCHDOG_INIT
	WATCHDOG_START
	TASTER=0;
	for (n=0;n<50;n++) {
		TR0=0;					// Timer 0 anhalten
		TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geraete unterschiedlich beginnen zu senden
		TL0=eeprom[ADDRTAB+2];
		TF0=0;					// ueberlauf-Flag zuruecksetzen
		TR0=1;					// Timer 0 starten
		while(!TF0);
	}
	restart_app();				// Anwendungsspezifische Einstellungen zuruecksetzen

#ifdef DEBUG_H_
	DEBUG_SETUP
#endif

	verstellt=0;
	dimmwert = LED_hell;        // Default Helligkeit aus EEPROM laden
	object_value[5]=dimmwert;   // TODO dimmwert direkt in object_value behandeln

	do {
		WATCHDOG_FEED
		if (RTCCON>=0x80)	// Realtime clock ueberlauf
		{
			RTCCON=0x61;    // RTC flag loeschen
			if(!connected) delay_timer();   // die normal RTC Behandlung
			else    // wenn connected den timeout fuer Unicast connect behandeln
            {
			    if(connected_timeout <= 110)    // 11x 520ms --> ca 6 Sekunden
			        connected_timeout ++;
			    else
			        send_obj_value(T_DISCONNECT);// wenn timeout dann disconnect, flag und var wird in build_tel() geloescht
            }
		}

		n=timer;
		blink=((n>>2) & 0x01);

		verstell=n & 0x01;

		if (verstell==0)verstellt=0;

		if (status60 & 0x01) {			// wenn progmode aktiv ist...
			if ((PORT & 0x0F)==0x0E) {	// Taste 1 gedrueck
				if ((dimmwert<254) && (verstell==1)&& verstellt==0) {
					dimmwert++;
					verstellt=1;
				}
			}
			if ((PORT & 0x0F)==0x0D) { // Taste 2 gedrueckt
				if ((dimmwert>1) && (verstell==1)&& verstellt==0) {
					dimmwert--;
					verstellt=1;
				}
			}
		}

		else {	//Wenn also Modul nicht im Progmode ist..
			//##### TASTERABFRAGE ######

			if(APPLICATION_RUN)	{// nur wenn im Run modus und nicht connected
				if ((PORT & 0x0F) != button_buffer) port_changed(PORT & 0x0F);	// ein Taster wurde gedrueckt

				// Temperatur verarbeiten
				if(eeprom[0xFC]&0x80) {// Temperaturmessung aktiviert
	                if (sequence==1)
	                {
	                    interrupted=0;
	                    start_tempconversion();         // Konvertierung starten
	                    if (!interrupted) sequence=2;
	                }
	                else if (sequence==2)
	                {
	                    if (ow_read_bit()) sequence=3;  // Konvertierung abgeschlossen
	                }
	                else if (sequence==3)
	                {
	                    // Temperatur einlesen + uebergabe Sensortyp
	                    th=read_temp(SENSOR_TYPE);
                        // Bei Sensorfehler wird kein Messwert mehr gesendet
	                    // TODO Fehler Com-Objekt einfuegen??
                        if(th >-5600)
                        {
                            temp=th + ((signed char)(eeprom[0xFD]))*10; //nur positive Temperaturen, Offset verrechnen
                            object_value[4]=eis5conversion(temp);
                            send_obj_value(12);
                            timercnt[8]=eeprom[0xFB];
                        }
                        else
                        {
                            timercnt[8]=0x01;   // Restart after 1 second
                        }
                        // TODO, warum schreiben wir die base immer neu??
                        timerbase[8]=eeprom[0xFC]&0x07; //Timer for temperature
                        sequence=0; // wenn wir hier sind haben wir einen gueltigen Messwert, neustart durch timer



/*  DIES IST DER PI REGLER
                        solltemp = (((int)eeprom [0xE9]<<8 )| eeprom[0xEA])*10;
                        spreizung = eeprom[0xED];
                        if (temp<solltemp)val=1;
                        if (temp>solltemp)val=0;
                        object_value[6]=val;
                        if(temp<solltemp)
                        {
                            if((solltemp-temp)<=spreizung)object_value[7]=((solltemp-temp)*255)/spreizung;
                            else object_value[7]=255;
                        }
                        else
                        {
                            object_value[7]=0;
                        }
	           			send_obj_value(4);
	           			send_obj_value(13);
*/
	                }// else if(sequence==3..
				}// if(eeprom... aktiv?
			    }//if(APLICATION RUN??..
		}// else... wenn modul nicht im progmode
		// LED Behandlung:
		val=255;    // val ist hier pattern fuer das LED Blinken
		blink=((n >>3)&0x01);
		for (x=0;x<4;x++)
		{
		    if (eeprom[0xE3 +x] & 0x80) // blinken
		    {
		        val &= ~(blink<<(x+4));
		    }
		}
		LEDVAL=LEDSTATE & val;

		if (tel_arrived || tel_sent) {
			tel_sent=0;
			process_tel();
		}
		else {
			for(n=0;n<100;n++);
		}

#ifdef DEBUG_H_
		DEBUG_POINT
#endif

#ifndef NOPROGBUTTON
		TASTER=1;				        	// Pin als Eingang schalten um Programmiertaster abzufragen
		if(!TASTER){ // Taster gedrueckt
			if(tasterpegel<255)	tasterpegel++;
			else{
				if(!tastergetoggelt)status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
				tastergetoggelt=1;
					if((status60 & 0x01)==0){	//wenn ausgemacht, Dimmwert speichern
						EA=0;
						START_WRITECYCLE;
						FMADRH= EEPROM_ADDR_H;    // Write to EEPROM area above USERRAM
						FMADRL= 0xFE;
						FMDATA=	dimmwert;
						STOP_WRITECYCLE;
						EA=1;
					}
			}
		}
		else {
			if(tasterpegel>0) tasterpegel--;
			else tastergetoggelt=0;
			}

#else
		// progmode wird durch Taste 1&2 bzw. 3&4 getoggelt
		if (((PORT & 0x0F)== 0x03) || ((PORT & 0x0F)== 0x0C)) {
			if(tasterpegel<255)	tasterpegel++;
			else{
				if(!tastergetoggelt)status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
				tastergetoggelt=1;
				if((status60 & 0x01)==0){	//wenn ausgemacht Dimmwert speichern
					EA=0;
					START_WRITECYCLE;
					FMADRH= EEPROM_ADDR_H;    // Write to EEPROM area above USERRAM
					FMADRL= 0xFE;
					FMDATA=	dimmwert;
					STOP_WRITECYCLE;
					EA=1;
				}

			}
		}

		if ((PORT & 0x0F)== 0x0F){ ;	// Warten bis alle Taster losgelassen
			if(tasterpegel>0) tasterpegel--;
			else tastergetoggelt=0;
			}
#endif

#ifdef NOPROGLED
		if (status60 & 0x01) TASTER = blink;    // LED blinkt im Prog-Mode
		else TASTER = (eeprom[0xE2] & 0x01);    // LED ist an oder aus gemaess Parameter fuer Betriebs-LED
#else
		if (status60 & 0x01) TASTER = 0;        // LED leuchtet im Prog-Mode
		else TASTER = 1;                        // LED aus
#endif


	}  while(1);
}

