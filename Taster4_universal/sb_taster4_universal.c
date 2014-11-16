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
* @file   fb_taster.c
* @author Andreas Krebs <kubi@krebsworld.de>
* @date   2009
*
* @brief The Freebus Taster Application, Firmware fuer einen 4-fach Taster mit 4 LEDs
*		Herstellercode 0x0004 = Jung
*		Devicetype  = Jung Tastsensor 2094
*		in ETS das Applikationsprogramm "Universal/Schalten " auswaehlen
*
* \par Changes:
*		1.00	erste Version;
*		1.01	eigenes Telegramm wird ausgewertet, "Affengriff" entprellt
* 		1.02	div. bugs behoben
* 		1.03	Fehler bei Lamellenverstellzeit (T2) behoben
* 		1.04	LEDs dimmbar, neue backendsoft, fehlende Funktionen zugefuegt,
* 				trimbar ueber RS
* 		1.05	neue LIB
* 		1.06	Anpassung fuer LPC936, Lib 1.5, Cleanup
*/

// Options
//#define debugmode
#define SENSOR_TYPE     0   // !=1 DS18B20

#define NOPROGLED //typ 0,2 Die Progled blinkt im Progmodus da sie auch Betriebs LED ist
//#define NOPROGBUTTON	//typ 1,3 es ist kein prog Taster vorhanden sondern progmode wird durch druecken von taste 1&3 oder 2&4 aktiviert


// Geraeteparameter setzen, diese koennen von der ETS uebschrieben werden
// Daher zusaetzlich bei jedem restart_app neu schreiben
//static __code unsigned char __at (0x3903) manufacturer[2]={0x00,0x4C};  // Herstellercode 0x004C = Bosch
//static __code unsigned char __at (0x3905) device_type[2]={0x04, 0x56};  // 0x0456 = Selfbus Taster4_universal
//static __code unsigned char __at (0x390C) port_A_direction={0};         // PORT A Direction Bit Setting
//static __code unsigned char __at (0x390D) run_state={255};              // Run-Status (00=stop FF=run)

// DEBUG
// Temperatur Sensor
unsigned char sequence;
int th;
int temp;
unsigned int solltemp;
unsigned char spreizung;


#include "sb_app_taster4_universal.h"
#include "watchdog.h"

#include "fb_rs232.h"
#include "onewire.h"
#include "debug.h"


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

#define VERSION		106

#ifdef DEBUG_H_
	DEBUG_VARIABLES;
#endif
//unsigned char __at (0x00) RAM[00];
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
	static __code unsigned char __at (0x1CFE) LED_hell;
	/*// Temperatur Sensor
	unsigned char sequence;
    int th;
    int temp;
*/
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
#ifdef debugmode
	DEBUG_SETUP
#endif

	verstellt=0;
	// Default LED Helligkeit holen
	dimmwert = LED_hell;
	//dimmwert = 255;// eeprom[0xD1];	// Neue VD setzt Defaultwert in EEPROM

	do  {
		WATCHDOG_FEED
		if (RTCCON>=0x80)	// Realtime clock ueberlauf
			{
			RTCCON=0x61;// RTC flag loeschen
			if(!connected)delay_timer();// die normal RTC Behandlung
			else// wenn connected den timeout fuer Unicast connect behandeln
				{
				if(connected_timeout <= 110)// 11x 520ms --> ca 6 Sekunden
					{
					connected_timeout ++;
					}
				else send_obj_value(T_DISCONNECT);// wenn timeout dann disconnect, flag und var wird in build_tel() geloescht
				}
			}

		//		if (RTCCON>=0x80) delay_timer();	// Realtime clock ueberlauf

		n=timer;
		blink=((n>>2) & 0x01);

		verstell=n & 0x01;

		if (verstell==0)verstellt=0;

		if (status60 & 0x01){			//wenn progmode aktiv ist...
			if ((PORT & 0x0F)==0x0E){	// Taste 1 gedrueck
				if ((dimmwert<254) && (verstell==1)&& verstellt==0){
					dimmwert++;
					verstellt=1;
				}
			}
			if ((PORT & 0x0F)==0x0D){ // Taste 2 gedrueckt
				if ((dimmwert>1) && (verstell==1)&& verstellt==0){
					dimmwert--;
					verstellt=1;
					}
			}
		}

		else{	//Wenn also Modul nicht im Progmode ist..
			//##### TASTERABFRAGE ######

			if(APPLICATION_RUN)	{// nur wenn im Run modus und nicht connected
				if ((PORT & 0x0F) != button_buffer) port_changed(PORT & 0x0F);	// ein Taster wurde gedrueckt

				// Temperatur verarbeiten
				if(eeprom[0xFC]&0x80){// Temperaturmessung aktiviert
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
	                    interrupted=0;
	                    // Temperatur einlesen + uebergabe Sensortyp
	                    th=read_temp(SENSOR_TYPE);
	                    if (!interrupted)
	                    {
	                        // Bei Sensorfehler wird letzter Messwert gehalten TODO Fehler Com-Objekt einfuegen??
	                    	if(th != 0xFFFF)temp=th + ((int)(signed char)(eeprom[0xFD]))*10; //nur positive Temperaturen, Offset verrechnen
	                    	else temp=0;

	                        sequence=0; // TODO, wenn wir hier sind haben wir einen gueltigen Messwert
//	                        object_value[8]=temp;
	                        object_value[4]=eis5conversion(temp);
/*	                        solltemp = (((int)eeprom [0xE9]<<8 )| eeprom[0xEA])*10;
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
*/	            			timerbase[8]=eeprom[0xFC]&0x07; //1
	            			timercnt[8]=eeprom[0xFB];
	            			send_obj_value(12);
/*	            			send_obj_value(4);
//	            			send_obj_value(13);
*/	                    }// if(!interrupted..
	                }// else if(sequence==3..
				}// if(eeprom... aktiv?
			    }//if(APLICATION RUN??..
		}// else... wenn modul nicht im progmode
		// LED Behandlung:
		val=0;// val ist hier pattern fuer das LED Blinken
		blink=((n >>3)&0x01);
		for (x=0;x<4;x++)
		{
			val |=((~((eeprom[0xE3 + x]>>7)&0x01))|blink)<<(x+4);
		}
		LEDVAL=LEDSTATE & val;

		if (tel_arrived || tel_sent) {//
			tel_sent=0;
			process_tel();
		}
		else {
			for(n=0;n<100;n++);
		}

#ifdef debugmode
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
						FMADRH= 0x1C;//EEPROM_ADDR_H;    // Write to EEPROM area above USERRAM
						FMADRL= 0xFE;
						//FMADRL= 0xD1;
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
					FMADRH= 0x1c;WRITE_ADDR+0x01;    // Write to EEPROM area above USERRAM
					//FMADRL= 0xBE;
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
		if (status60 & 0x01) TASTER = blink;		// LED blinkt im Prog-Mode
		else TASTER = !(eeprom[0xE2] & 0x10);	// LED ist an oder aus gemaess Parameter fuer Betriebs-LED
#else
		if (status60 & 0x01) TASTER = 0;		// LED leuchtet im Prog-Mode
		else TASTER = 1;						// LED aus
#endif


	}  while(1);
}

