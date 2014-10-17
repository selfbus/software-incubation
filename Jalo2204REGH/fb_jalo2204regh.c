/*
 *    _____ ______ __   __________  __  _______ *
 *   / ___// ____// /  / ____/ __ )/ / / / ___/ *
 *   \__ \/ __/  / /  / /__ / __  / / / /\__ \  * 
 *  ___/ / /__  / /__/ /__// /_/ / /_/ /___/ /  * 
 * /____/_____//____/_/   /_____/\____//____/   *  
 *                                      
 *  Copyright (c) 2010-2014 Andreas Krieger 
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
/*
* \par Changes:
*	2.00	Umstellung auf neue backendsoftware, neue timer
*/


//#include <P89LPC922.h>
//#include "../lib_lpc922/Releases/fb_lpc922_1.5x.h"
#include "fb_app_jalo2204regh.h"

#include "../com/fb_rs232.h"
#include"../com/watchdog.h"
//#include "../com/debug.h"

/** 
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
* 
*
*/
//

//#define debugger

#ifdef MAX_PORTS_8
	#define TYPE 4 
#endif
#ifdef MAX_PORTS_4
	#define TYPE 2
#endif

#define VERSION 11
unsigned char __at 0x00 RAM[00]; 

static __code unsigned char __at 0x1D03 manufacturer[2]={0,4};	// Herstellercode 0x0004 = Jung
static __code unsigned char __at 0x1D0C port_A_direction={0};	// PORT A Direction Bit Setting
static __code unsigned char __at 0x1D0D run_state={255};		// Run-Status (00=stop FF=run)

void main(void)
{

	unsigned char n,cmd,tasterpegel=0,mode,objval;
	//signed char cal;
	//static __code signed char __at 0x1CFC trimsave;	//0x1BFF
#ifdef zeroswitch
	static __code unsigned char __at 0x1CFB phisave;	//0x1BFE
#endif
	static __code unsigned char __at 0x1CFF blockedsave;	//
	unsigned char rm_count=0;
	__bit wduf,tastergetoggelt=0,objbitval;
	wduf=WDCON&0x02;
	restart_hw();							// Hardware zuruecksetzen
// im folgendem wird der watchdog underflow abgefragt und mit gedrücktem Progtaster
// ein resetten der cal Variable veranlasst um wieder per rs232 trimmen zu können.	
//	TASTER=0;
//	if(!TASTER && wduf)cal=0;
//	else cal=trimsave;
//	TRIM = (TRIM+trimsave);
//	TRIM &= 0x3F;//oberen 2 bits ausblenden
#ifdef zeroswitch
	if(phisave<=36)	phival=phisave;
	else phival=0;
#endif
	TASTER=0;
	if (!wduf){// BUS return verzögerung nur wenn nicht watchdog underflow
		for (n=0;n<50;n++) {		// Warten bis Bus stabil
			TR0=0;					// Timer 0 anhalten
			TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
			TL0=255;//eeprom[ADDRTAB+2];
			TF0=0;					// Überlauf-Flag zurücksetzen
			TR0=1;					// Timer 0 starten
			while(!TF0);
		}
	}
	WATCHDOG_INIT
	WATCHDOG_START
	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	if(!wduf)bus_return();							// Aktionen bei Busspannungswiederkehr
#ifdef debugger
	RS_INIT_115200
	TI=1;
#else	
//	RS_INIT_600
//	SBUF=0x55;
#endif
	do  {
		WATCHDOG_FEED
		//hand =((eeprom[0xE5]& 0xC0)>0);
		if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt
/*			if (eeprom[0xE5]& 0xC0){
				if (((delay_toggle & 0x07)==0x07))handsteuerung();   // Handbetätigung nur jedes 8.mal ausführen
			}
*/			if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf
			for(n= eeprom[0xE8]&0x40? 0:4 ;n<8;n++)//parameter Jalo(1) versus Rollo(0)
			{// Abhandlung der Positionierungsanforderungen
			
				objbitval=0;objval=0;
				if(((~blocked)&positions_req & bitmask_1[n]) )
				{
					if((!timerstate[(n&0x03)+11])&& !(kanal[n&0x03]&0x33))
					{
						if(n<4 )// Lamelle angefordert.. 
						{
							objval=l_position_target[n];
					       	mode=0x02;// in mode wird die abzuziehende Objektnummer eincodiert
						}
						else
						{	// jalo angefordert
							if (!j_position_target[n&0x03])// bei 0 mache eine Langzeitfahrt auf 0
							{							//Lamelle nicht nachführen!
			        		 mode=0x00;// in mode wird die abzuziehende Objektnummer eincodiert
			        		 objbitval=0;
							}
							else 
							{
				        		 objbitval=1;
				        		 if (j_position_target[n&0x03]==255)// bei 255 mache eine Langzeitfahrt auf 1
				        		 {
				        			 mode=0x00;// in mode wird die abzuziehende Objektnummer eincodiert
				        		 }
				        		 else
				        			 {
				        			 mode=0x01;
				        			 objval=j_position_target[n&0x03];
				        			 }
							}
							if(mode)
							{							//nur wenn eine echte Jalosieposition gefahren wird
							positions_req |=bitmask_1[n&0x03];// Lamellenfahrt setzen
							l_position_last[n&0x03]= l_position[n&0x03];// merken der Lamelle
							}
						}// ende else if lamelle angefordert
						object_schalten(n,objval,mode&0x0F,objbitval);

					}//ende if ! timerstate
					else if (drive_priority & 0x40)// Priorität auf Sonne-> stoppen.
					{
						timercnt[n]=0;
						timercnt[n+4]=0;
					}
				}
		//n++;
		}



#ifndef zeroswitch
			if(TF0 && (TMOD & 0x0F)==0x01) {	// Vollstrom für Relais ausschalten und wieder PWM ein
	#ifndef SPIBISTAB
				TMOD=(TMOD & 0xF0) + 2;			// Timer 0 als PWM
				TAMOD=0x01;
				TH0=DUTY;
	#endif				
				TF0=0;
	#ifndef SPIBISTAB
				AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben
	#endif
				PWM=1;			// PWM Pin muss auf 1 gesetzt werden, damit PWM geht !!!
	#ifndef SPIBISTAB
				TR0=1;
	#else
				P0=portbuffer;
	#endif
			}
#endif
			
			if (portchanged)port_schalten();	// Ausgänge schalten


			// portbuffer flashen, Abbruch durch ext-int wird akzeptiert und später neu probiert
			// T1-int wird solange abgeschaltet, 
		if (fb_state==0 && (TH1<0XC0) && (!wait_for_ack)&& blocked!=blockedsave) {
			START_WRITECYCLE;
			FMADRH= 0x1c;		
			FMADRL= 0xFF; 
			FMDATA= blocked;
			STOP_WRITECYCLE;
		}

		
		}// end if(runstate...
		else if (RTCCON>=0x80 && connected)	// Realtime clock ueberlauf
			{			// wenn connected den timeout für Unicast connect behandeln
			RTCCON=0x61;// RTC flag löschen
			if(connected_timeout <= 110)// 11x 520ms --> ca 6 Sekunden
				{
				connected_timeout ++;
				}
				else send_obj_value(T_DISCONNECT);// wenn timeout dann disconnect, flag und var wird in build_tel() gelöscht
			}

		// Telegrammverarbeitung..
		if (tel_arrived ) {//|| tel_sent
			tel_arrived=0;
			tel_sent=0;
			process_tel();
		}
		else {
			for(n=0;n<100;n++);	// falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann
		}


cmd;
/*
#ifndef debugger
		// Eingehendes Terminal Kommando verarbeiten...
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
#ifdef zeroswitch
				FMADRH= 0x1c;		
				FMADRL= 0xfb; 
				FMDATA= phival;
#else
				FMADRH= 0x1c;		
				FMADRL= 0xfc; 
#endif
				FMDATA=	cal;
				STOP_WRITECYCLE;
				EA=1;				//int wieder freigeben
			}
			if(cmd=='p')status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
#ifdef zeroswitch
			if(cmd=='<'){
				if (phival){
					phival--;
					TI=0;
					SBUF=phival;
				}
			}	
			if(cmd=='>'){
				if(phival<35){
					phival++;	// 
					TI=0;
					SBUF=phival;
				}
			}
#endif			
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
*/
#ifdef debugger
	DEBUGPOINT
#endif
//#endif		
		TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER){ // Taster gedrückt
			if(tasterpegel<255)	tasterpegel++;
			else{
				if(!tastergetoggelt)status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
				tastergetoggelt=1;
			}
		}
		else {
			if(tasterpegel>0) tasterpegel--;
			else tastergetoggelt=0;
		}
		TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
  } while(1);
}


