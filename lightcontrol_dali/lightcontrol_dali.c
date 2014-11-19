/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008-2011 Andreas Krieger
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
/**
* @file   fb_out.c
* @author Andreas Krieger 
* 
*/
//#include <P89LPC922.h>
//#include "../lib_lpc922/Releases/fb_lpc922_1.4x.h"
#include "fb_app_lightcontrol_dali.h"

#include "../com/fb_rs232.h"


/** 
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
* 
*
*/
void main(void)
{ 
	unsigned char n,count;
	signed char cal;
	static __code signed char __at 0x1BFF trimsave;
	
	restart_hw();							// Hardware zuruecksetzen
	rs_init(1152);

	cal=trimsave;
	TRIM = TRIM+trimsave;
	TASTER=0;
	for (n=0;n<50;n++) {		// Warten bis Bus stabil
		TR0=0;					// Timer 0 anhalten
		TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
		TL0=eeprom[ADDRTAB+2];
		TF0=0;					// Überlauf-Flag zurücksetzen
		TR0=1;					// Timer 0 starten
		while(!TF0);
	}
	count=0;

	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	bus_return();							// Aktionen bei Busspannungswiederkehr

	do  {
		if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt

			// Helligkeit nachführen
		if(!fb_state && !D_f_busy ){

			if (dimmziel[count]==dimmwert[count]){
				if (helligkeit[count]!= dimmwert[count]){
					helligkeit[count]=dimmwert[count];
					while(D_f_busy);
					if (read_objflags(count+6)&0x40)send_obj_value(count+6);
				}
			}
			if (dimmpwm[count]!= D_hell[count]){
				if(schalten&bitmask_1[count]){
					DALI_send(0xFE00 | dimmpwm[count],count);
				}
				D_hell[count]=dimmpwm[count];
			}
			if(count<2)count++;
			else count=0;
		}
		if (portchanged)port_schalten();	// Ausgänge schalten
		
		
		
		if(RI){
		
//		rs_send(helligkeit[SBUF]);
//		DALI_send(0xFE00+SBUF,1);
		RI=0;
	}


		
		if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf
/*			if(TF0 && (TMOD & 0x0F)==0x01) {	// Vollstrom für Relais ausschalten und wieder PWM ein
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
*/

			

			// portbuffer flashen, Abbruch durch ext-int wird akzeptiert und später neu probiert
			// T1-int wird solange abgeschaltet, timeout_count wird ggf. um 4ms (flashzeit) reduziert
		/*	if (fb_state==0 && portbuffer!=eeprom[PORTSAVE]) {
				ET1=0;
				START_WRITECYCLE;
				WRITE_BYTE(0x01,PORTSAVE,portbuffer);
				STOP_WRITECYCLE;
				if (timeout_count>120) timeout_count-=120; else timeout_count=0;
				ET1=1;
			}
		*/
		}// end if(runstate)
		else if (RTCCON>=0x80 && connected)	// Realtime clock ueberlauf
			{			// wenn connected den timeout für Unicast connect behandeln
			RTCCON=0x61;// RTC flag löschen
			if(connected_timeout <= 110)// 11x 520ms --> ca 6 Sekunden
				{
				connected_timeout ++;
				}
				else send_obj_value(T_DISCONNECT);// wenn timeout dann disconnect, flag und var wird in build_tel() gelöscht
			}
		
		
		
		n= tx_buffer[(tx_nextsend-1)&0x07];// ist die letzte objno
		if (tel_arrived || (n<6 && n>8 && tel_sent)) { // 
			tel_arrived=0;
			tel_sent=0;
			process_tel();
			
		}
    	

		
		
		TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER) {				// Taster gedrückt
			for(n=0;n<100;n++) {}	// Entprell-Zeit
			n=0;
			while(!TASTER)			// warten bis Taster losgelassen
			 {
				while (RTCCON<0x80);
				if (n<=254)	n++;
				RTCCON=0x60;	// Real Time Clock stoppen
				RTCH=0x01;		// Real Time Clock auf 8ms laden (0,008s x 7372800 / 128)
				RTCL=0xCD;		// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
				RTCCON=0x61;	// ... und starten
			 }
				if(n<125){
					status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
				}
				else
				{					//länger als 1 Sekunde
					if (n<250){
						cal++;//kürzer als 2 sekunden
						TRIM+=1;
					}
					else{
						cal--;
						TRIM-=1;
					}
					EA=0;
					START_WRITECYCLE;	//cal an 0x1bff schreiben
					FMADRH= 0x1B;		
					FMADRL= 0xFF; 
					FMDATA=	cal; 
					STOP_WRITECYCLE;
					EA=1;				//int wieder freigeben
				}
				RTCCON=0x60;	// Real Time Clock stoppen
				RTCH=0x00;		// Real Time Clock auf 0.5ms laden (0,0005 x 7372800 / 128)
				RTCL=0x1D;		// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
				RTCCON=0x61;	// ... und starten


		}
		TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)

//		for(n=0;n<100;n++) {}	// falls Hauptroutine keine Zeit verbraucht, der LED etwas Zeit geben, damit sie auch leuchten kann
//		if (status60&0x01)ET0=0;
//		else ET0=1;
	} while(1);
}


