/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 20013 Andreas Krieger
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
/**
* @file   meldetableau24.c
* @author Andreas Krieger 
* 
*/

#ifndef LPC936
	#include <P89LPC922.h>
#else
	#include <P89LPC935_6.h>
#endif	

//#include <P89LPC922.h>
//#include "../lib_lpc922/Releases/fb_lpc922_1.4x.h"
#include "fb_app_ws.h"
#include "../com/debug.h"
//#include "../com/debug.c"
#include "../com/fb_rs232.h"
#include"../com/watchdog.h"
//#include"../com/watchdog.c"

#define debugmode
#define TYPE 0
#define VERSION 0
/** 
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
* 
*
*/

unsigned char __at 0x00 RAM[00]; //nur für die debug ausgabe


void main(void)
{ 
	unsigned char n,cmd,prog_button_level=0;
	signed char cal;
	static __code signed char __at 0x1BFF trimsave;
	__bit prog_button_toggled=0;

	restart_hw();							// Hardware zuruecksetzen
	TASTER=0;
	cal=trimsave;
	TRIM = TRIM+trimsave;
	
#ifndef debugmode
	RS_INIT_600
#else
	RS_INIT_115200
#endif

	SBUF=0x55;

	TASTER=0;
	for (n=0;n<50;n++) {		// Warten bis Bus stabil
		TR0=0;					// Timer 0 anhalten
		TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
		TL0=eeprom[ADDRTAB+2];
		TF0=0;					// Überlauf-Flag zurücksetzen
		TR0=1;					// Timer 0 starten
		while(!TF0);
	}
	WATCHDOG_INIT //watchdog_init();
	WATCHDOG_START //watchdog_start();

	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	bus_return();							// Aktionen bei Busspannungswiederkehr
	keypad_init();							// keyboard interrupt initialisieren

	do  {
		
	WATCHDOG_FEED //watchdog_feed();	

		if(stream_arrived && !TR0)
		{
			update();
			stream_arrived=0;
		}
	 if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt
		EKBI = 1; // wenn die aplikation  läuft keyboard int einschalten
	 	if (RTCCON &0x80)
	 	{	
		delay_timer();
	 	}
		else if (RTCCON>=0x80 && connected)	// Realtime clock ueberlauf
			{			// wenn connected den timeout für Unicast connect behandeln
			RTCCON=0x61;// RTC flag löschen
			if(connected_timeout <= 110)// 11x 520ms --> ca 6 Sekunden
				{
				connected_timeout ++;
				}
				else send_obj_value(T_DISCONNECT);// wenn timeout dann disconnect, flag und var wird in build_tel() gelöscht
			}
		


//				 #########  checken der Grenzwerte ###########
//		
		for(n=0;n<10;n++)// n ist Nummer des Universal grenzwertes
			
		{	
			unsigned char GWE= (eeprom[0xD3+(n/4)]>>shift_at_2bit[n])&0x03;//Grenzwertereignis
			__bit polarity_param ;
			unsigned int GW;	// Genzwert
			unsigned char quellobj;
			if (n&0x01)quellobj = eeprom[0xE3+(n>>1)]>>4;
			else quellobj = eeprom[0xE3+(n>>1)]&0x0F;
				
			if (n<=7)GW= ((int)eeprom [0xE9+n+n]<<8 )| eeprom[0xEA+n+n];// 0-7 integer
			else GW= eeprom[ 249-8 +n];// 8,9 char

			if( eeprom[0xE1+n/8]& bitmask_1[n%8]) polarity_param = 1;// sendeparameter des Grenzwertes
			else polarity_param = 0;
			if(GWE & 0x01)// Überschreiten, nur vergleichen wenn aktiviert
			{
				if(read_obj_data(quellobj)> GW)
				{
					if(GWE & 0x02)// also GWE=3, bei Über und Unterschreiten
					{
						sendbychange(n+11,1^polarity_param);	
					}
					else	// GWE=1, bei Überschreiten
					{
						sendbychange(n+11,polarity_param);
					}
				}
			}
			if(GWE & 0x02)// Unterschreiten, nur vergleichen wenn aktiviert
			{
				if(read_obj_data(quellobj)< GW)
				{
					if(GWE & 0x01)// also GWE=3, bei Über und Unterschreiten
					{
						sendbychange(n+11,0^polarity_param);	
					}
					else
					{
						sendbychange(n+11,polarity_param);// GWE=2, bei Unterschreiten
					}
				}
			}

		}
		for ( n=0;n<4;n++)// checken der 4 Windrichtungs-Grenzwerte
		{
			unsigned char GW_von = eeprom[251+n]&0x07;
			unsigned char GW_bis = (eeprom[251+n]>>4)&0x07;
			unsigned char wr_val;
			unsigned char uchar_wind_angle=(unsigned char)wind_angle;
			__bit polarity_param,match=0;
			
			if(eeprom[0xE2]& bitmask_1[n+4])// nur wenn aktiviert ist..
			{
			
				if(eeprom[251+n]&0x08)polarity_param=1;
				else polarity_param=0;
	
				if(uchar_wind_angle==14)wr_val=6;//lowbyte bei 270° WR=6
				else if(uchar_wind_angle==59)wr_val=7;//lowbyte bei315° WR=7
				else wr_val= uchar_wind_angle/45;
	
				if(GW_von<=GW_bis)// Wenn (von <= bis), dann normal zwischen von und bis auswerten
					{
						if((wr_val >= GW_von) && (wr_val <= GW_bis))match=1; 
						else match=0;
					}
				else{	// wenn (bis < von), dann vergleiche über den Überlauf(0)
						if((wr_val >= GW_von)||(wr_val <= GW_bis))match=1;
						else match=0;
					}
				sendbychange(21+n,match^polarity_param);//
			}
		}


			
		cmd;	
#ifndef debugmode		
		if (RI){
			RI=0;
			cmd=SBUF;
			if(cmd=='c'){
				while(!TI);
				TI=0;
				SBUF=0x55;
			}
			if(cmd=='+'){
				TRIM--;
				cal--;
			}
			if(cmd=='-'){
				TRIM++;
				cal++;
			}
			if(cmd=='w'){
				EA=0;
				START_WRITECYCLE;	//cal an 0x1bff schreiben

				FMADRH= 0x1B;		
				FMADRL= 0xFF; 

				FMDATA=	cal;
				STOP_WRITECYCLE;
				EA=1;				//int wieder freigeben
			}
			if(cmd=='p')status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
			if(cmd=='v'){
				while(!TI);
				TI=0;
				SBUF=VERSION;
			}
			if(cmd=='t'){
				while(!TI);
				TI=0;
				SBUF=TYPE;
			}
		}//end if(RI...
#else		
		DEBUGPOINT
//		if(RI){wind_angle=SBUF;
//		RI=0;
//		}
#endif


		
				
		}// end if(runstate)
		else   EKBI = 0; // wenn die aplikation nicht läuft keyboard int abschalten
	
		
		n= tx_buffer[(tx_nextsend-1)&0x07];//n ist die letzte objno
		if (tel_arrived || (n==25 && tel_sent)) { // 
			tel_arrived=0;
			tel_sent=0;
			process_tel();
			
		}
		
	// ### PROG Button ###

		TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER){ // Taster gedrückt
			if(prog_button_level<255)	prog_button_level++;
			else{
				if(!prog_button_toggled)status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
				prog_button_toggled=1;
			}
		}
		else {
			if(prog_button_level>0)prog_button_level--;
			else prog_button_toggled=0;
		}
		TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
		
		

		for(n=0;n<100;n++) {}	// falls Hauptroutine keine Zeit verbraucht, der LED etwas Zeit geben, damit sie auch leuchten kann
	} while(1);
}


