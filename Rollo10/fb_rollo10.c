/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2012 Andreas Krieger 
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


#include <P89LPC922.h>
#include <fb_lpc922_1.4x.h>
#include "fb_app_rollo10.h"

//#include "../com/fb_rs232.h"
#include <watchdog.h>

/** 
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
* 
*
*/
//#define 2TE
#ifdef HAND
	#define TYPE 1 
#else	
	#define TYPE 0
#endif

#define VERSION 10
unsigned char __at 0x00 RAM[00]; 

void main(void)
{ 
	unsigned char n,cmd,tasterpegel=0;
	signed char cal;
	static __code signed char __at(0x1BFF) trimsave;
#ifdef zeroswitch
	static __code unsigned char __at(0x1BFE) phisave;
#endif
	static __code unsigned char __at(0x1BFD) blockedsave;
	unsigned char rm_count=0;
	__bit wduf,tastergetoggelt=0;
	wduf=WDCON&0x02;
	restart_hw();							// Hardware zuruecksetzen
// im folgendem wird der watchdof underflow abgefragt und mit gedrï¿½cktem Progtaster
// ein resetten der cal Variable veranlasst um wieder per rs232 trimmen zu kï¿½nnen.
	TASTER=1;
	if(!TASTER && wduf)cal=0;
	else cal=trimsave;
	TRIM = (TRIM+trimsave);
	TRIM &= 0x3F;//oberen 2 bits ausblenden
#ifdef zeroswitch
	if(phisave<=36)	phival=phisave;
	else phival=0;
#endif
	if (!wduf){// BUS return verzï¿½gerung nur wenn nicht watchdog underflow
		for (n=0;n<50;n++) {		// Warten bis Bus stabil
			TR0=0;					// Timer 0 anhalten
			TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Gerï¿½te unterschiedlich beginnen zu senden
			TL0=eeprom[ADDRTAB+2];
			TF0=0;					// ï¿½berlauf-Flag zurï¿½cksetzen
			TR0=1;					// Timer 0 starten
			while(!TF0);
		}
	}
	WATCHDOG_INIT
	WATCHDOG_START
	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	if(!wduf)bus_return();							// Aktionen bei Busspannungswiederkehr
	//...rs_init...(6);im folgenden direkt:
	BRGCON&=0xFE;	// Baudrate Generator stoppen
	P1M1&=0xFC;		// RX und TX auf bidirectional setzen
	P1M2&=0xFC;
	SCON=0x50;		// Mode 1, receive enable
	SSTAT|=0xE0;	// TI wird am Ende des Stopbits gesetzt und Interrupt nur bei RX und double TX buffer an
	BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
	BRGR1=0x2F;	// Baudrate = cclk/((BRGR1,BRGR0)+16)
	BRGR0=0xF0;	// fï¿½r 115200 0030 nehmen, autocal: 600bd= 0x2FF0
	BRGCON|=0x01;	// Baudrate Generator starten
	SBUF=0x55;
	do  {
		WATCHDOG_FEED
		//hand =((eeprom[0xE5]& 0xC0)>0);
		if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt
/*			if (eeprom[0xE5]& 0xC0){
				if (((delay_toggle & 0x07)==0x07))handsteuerung();   // Handbetï¿½tigung nur jedes 8.mal ausfï¿½hren
			}
*/			if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf
#ifndef zeroswitch
			if(TF0 && (TMOD & 0x0F)==0x01) {	// Vollstrom fï¿½r Relais ausschalten und wieder PWM ein
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
			
			if (portchanged)port_schalten();	// Ausgï¿½nge schalten

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
*/

			// portbuffer flashen, Abbruch durch ext-int wird akzeptiert und spï¿½ter neu probiert
			// T1-int wird solange abgeschaltet, 
		if (fb_state==0 && (TH1<0XC0) && (!wait_for_ack)&& blocked!=blockedsave) {
			START_WRITECYCLE;
			FMADRH= 0x1B;		
			FMADRL= 0xFD; 
			FMDATA= blocked;
			STOP_WRITECYCLE;
		}

		
		}// end if(runstate...
		
		// Telegrammverarbeitung..
		if (tel_arrived ) {//|| tel_sent
			tel_arrived=0;
			tel_sent=0;
			process_tel();
		}
		else {
			for(n=0;n<100;n++);	// falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann
		}

//BREAKPOINT
//cmd;
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
		
		TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER){ // Taster gedrï¿½ckt
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


