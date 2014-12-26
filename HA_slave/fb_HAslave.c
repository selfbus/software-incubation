/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008-2011 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
/**
* @file   fb_out.c
* @author Andreas Krebs <kubi@krebsworld.de>
* @date   Tue Jan 01 17:44:47 2009
* 
*/
//#include <P89LPC922.h>
//#include "../lib_lpc922/Releases/fb_lpc922_1.53.h"
#include "fb_app_HAslave.h"
#include  "../com/debug.h"
#include "../com/fb_rs232.h"
#include"../com/watchdog.h"

/** 
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
* 
*
*/
#ifdef MAX_PORTS_4
	#ifdef SPIBISTAB
		#ifdef HAND
			#define TYPE 7
		#else	
			#define TYPE 6
		#endif
	#else	// kein SPIBISTAB
		#ifdef HAND
			#define TYPE 5
		#else	
			#define TYPE 4
		#endif
	#endif
#else		// MAX_PORTS_8
	#ifdef SPIBISTAB
		#ifdef HAND
			#define TYPE 3
		#else	
			#define TYPE 2
		#endif
	#else	// kein SPIBISTAB
		#ifdef HAND
			#define TYPE 1 
		#else	
			#define TYPE 0
		#endif
	#endif
#endif
#define VERSION 01

unsigned char __at 0x00 RAM[00]; 
__code unsigned int __at (EEPROM_ADDR + 0x17) start_pa={0xFFFF};      // Default PA is 15.15.255


void main(void)
{ 
	unsigned char timer_precounter=0;

	unsigned char n,cmd,tasterpegel=0;
	signed char cal;
//	unsigned int m;
	static __code signed char __at 0x1BFF trimsave;
#ifdef zeroswitch
	static __code unsigned char __at 0x1BFE phisave={16};
#endif
	unsigned char rm_count=0;
	__bit wduf;
	__bit tastergetoggelt=0;
	__bit bus_activ=0;

	wduf=WDCON&0x02;
	restart_hw();							// Hardware zuruecksetzen
// im folgendem wird der watchdof underflow abgefragt und mit gedrücktem Progtaster
// ein resetten der cal Variable veranlasst um wieder per rs232 trimmen zu können.	
	TASTER=1;
	if(!TASTER && wduf)cal=0;
	else cal=trimsave;
	TASTER=0;
	TRIM = (TRIM+trimsave);
	TRIM &= 0x3F;//oberen 2 bits ausblenden
#ifdef zeroswitch
	if(phisave<=52)	phival=phisave;
	else phival=16;
#endif
	TR0=1;
	if (!wduf){// BUS return verzögerung nur wenn nicht watchdog underflow
		for (n=0;n<50;n++) {		// Warten bis Bus stabil
			TR0=0;					// Timer 0 anhalten
			TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
			TL0=eeprom[ADDRTAB+2];
			TF0=0;					// Überlauf-Flag zurücksetzen
			TR0=1;					// Timer 0 starten
			while(!TF0);
		}
	}
	WATCHDOG_INIT
	WATCHDOG_START
	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	if(!wduf)bus_return();							// Aktionen bei Busspannungswiederkehr

#ifndef debugmode
	RS_INIT_600
#else
	RS_INIT_115200
#endif
	
#ifndef BUS_DOWN
# ifdef HAND
#  ifndef zeroswitch
	SBUF=0x55;
#  endif
# else
	SBUF=0x55;
# endif
#endif

	
// ################## main loop #########################	

	do  {
		WATCHDOG_FEED

		if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt

			if(RTCCON>=0x80){
				RTCCON=0x60;		// RTC Flag löschen
			    RTCH = 0x01;
				RTCL = 0x20;	// alle 5ms erzeugt in timerflags 10ms am bit 0
				//RTCH=0x03;			//0E reload Real Time Clock
				//RTCL=0x9A;			//A0 16ms +precounter x4
				RTCCON=0x61;		// RTC  Flag löschen
#ifdef HAND				
				handbedienung();// alle 16ms
#endif				
//				timer_precounter++;
//				if((timer_precounter&0x03)==3)
//				{
				delay_timer();	// timer handler jedes 4. mal--> 64ms
//				}
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
		#ifndef IO_BISTAB		
				TR0=1;
		#endif
	#endif
	
	#ifdef IO_BISTAB
				P0=0;// wenn Bistabile über IO diese ausschalten
	#endif
			}
#endif
		
			
#ifdef BUS_DOWN
			if(TxD){
				if(bus_activ)bus_down();
			}
			else bus_activ=1;
#endif			
			if (portchanged)port_schalten();	// Ausgänge schalten

/*			// Rückmeldungen senden
			if(rm_send) {	// wenn nichts zu senden ist keine Zeit vertrödeln
				if(rm_send & (1<<rm_count)) {
					if(send_obj_value(rm_count + 12)) {	// falls erfolgreich, dann nächste
						rm_send&=(0xFF-(1<<rm_count));
						rm_count++;
#ifdef MAX_PORTS_8
						rm_count&=0x07;
#else
						rm_count&=0x03;
#endif						
					}
				}
				else {	// RM sollte nicht gesendet werden
					rm_count++;
#ifdef MAX_PORTS_8
						rm_count&=0x07;
#else
						rm_count&=0x03;
#endif						
				}
			}
			else rm_count=0;	// Immer mal wieder auf Null setzen, damit Reihenfolge von 1 bis 8 geht


			// portbuffer flashen, Abbruch durch ext-int wird akzeptiert und später neu probiert
			// T1-int wird solange abgeschaltet, 

			if (fb_state==0 && (TH1<0XC0) && (!wait_for_ack)&& portbuffer!=eeprom[PORTSAVE]) {
				START_WRITECYCLE;
				WRITE_BYTE(0x01,PORTSAVE,portbuffer);
				STOP_WRITECYCLE;
			}
*/		
		}// end if(APPLICATION RUN
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
		if (tel_arrived || tel_sent) {
			tel_arrived=0;
			tel_sent=0;
			process_tel();
		}
		else {
			for(n=0;n<100;n++);	// falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann
		}
		cmd;
#ifndef BUS_DOWN
#ifndef debugmode		
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
				FMADRH= 0x1B;		
				FMADRL= 0xFE; 
				FMDATA= phival;
#else
				FMADRH= 0x1B;		
				FMADRL= 0xFF; 
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
				if(phival<51){
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
/*			
#ifdef MAX_PORTS_8
			if(cmd >=49 && cmd <= 56){
				portbuffer = portbuffer ^ (0x01<< (cmd-49));
				port_schalten();
			}
#else
			if(cmd >=49 && cmd <= 52){
				portbuffer = portbuffer ^ (0x01<< (cmd-49));
				port_schalten();
			}
#endif
*/						
		}//end if(RI...
#else //ifndef debugmode
DEBUGPOINT;
#endif
#endif // ifndef BUS_DOWN
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


