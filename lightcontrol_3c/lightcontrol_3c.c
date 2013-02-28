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

#include <P89LPC922.h>
#include "../lib_lpc922/fb_lpc922.h"
#include "fb_app_lightcontrol_3c.h"

#include "../com/fb_rs232.h"

#define TYPE 0
#define VERSION 0
/** 
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
* 
*
*/
void main(void)
{ 
	unsigned char n,count,cmd,tasterpegel=0;
	signed char cal;
	static __code signed char __at 0x1BFF trimsave;
	__bit tastergetoggelt=0;
	restart_hw();							// Hardware zuruecksetzen

	cal=trimsave;
	TRIM = TRIM+trimsave;
	//...rs_init...(6);im folgenden direkt:
	BRGCON&=0xFE;	// Baudrate Generator stoppen
	P1M1&=0xFC;		// RX und TX auf bidirectional setzen
	P1M2&=0xFC;
	SCON=0x50;		// Mode 1, receive enable
	SSTAT|=0xE0;	// TI wird am Ende des Stopbits gesetzt und Interrupt nur bei RX und double TX buffer an
	BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
	BRGR1=0x2f;	// Baudrate = cclk/((BRGR1,BRGR0)+16)
	BRGR0=0xf0;	// für 115200 0030 nehmen, autocal: 600bd= 0x2FF0
	BRGCON|=0x01;	// Baudrate Generator starten
	SBUF=0x55;

	
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
		if(eeprom[RUNSTATE]==0xFF) {	// nur wenn run-mode gesetzt

			// Helligkeit nachführen
		if (dimmziel[count]==dimmwert[count]){
			if (helligkeit[count]!= dimmwert[count]){
				helligkeit[count]=dimmwert[count];
//				rs_send(read_obj_value(count+6));
//				rs_send(read_objflags(count+6));
				if (read_objflags(count+6)&0x40)send_obj_value(count+6);
			}
		}
		if(count<2)count++;
		else count=0;
		
		
		
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


		
		//if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf
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
			if (dimmtimervorteiler>=10){//vorteiler wird alle 50µs in softpwm erhöht
				dimmtimervorteiler-=10;//
				delay_timer();
			}// ergibt eine flanke von 0.50ms

			
			if (portchanged)port_schalten();	// Ausgänge schalten

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
		n= tx_buffer[(tx_nextsend-1)&0x07];// ist die letzte objno
		if (tel_arrived || (n<6 && n>8 && tel_sent)) { // 
			tel_arrived=0;
			tel_sent=0;
			process_tel();
			
		}
    	

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
		
		

//		for(n=0;n<100;n++) {}	// falls Hauptroutine keine Zeit verbraucht, der LED etwas Zeit geben, damit sie auch leuchten kann
//		if (status60&0x01)ET0=0;
//		else ET0=1;
	} while(1);
}


