/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2011 Andreas Krieger
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

#include "fb_app_lightcontrol_dimmer.h"


/**
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
*
*
*/
unsigned char __idata __at (0x00) RAM  [00];

#ifndef FB_DEBUG
// Wenn Debug aktiv ist werden die Werte in der restart_app() geschrieben damit die Konfiguration nicht
// immer neu geschrieben werden muss.
// Ger�teparameter setzen, diese k�nnen von der ETS �bschrieben werden wenn Schreibschutz nicht aktiv
static __code unsigned char __at (EEPROM_ADDR + 0x00) option_reg={0xFF};            // Option Register, ETS will write 0xFF
static __code unsigned char __at (EEPROM_ADDR + 0x01) fw_version[2]={VER_MAJ,VER_MIN};// Man. Data, used for FW Version
static __code unsigned char __at (EEPROM_ADDR + 0x03) manufacturer[2]={0x00,0x04};  // Herstellercode 0x0004 = Jung *
static __code unsigned char __at (EEPROM_ADDR + 0x05) device_type[2]={0x30,0x18};   // 0x03018 = 3 Kanal Dimmer #
static __code unsigned char __at (EEPROM_ADDR + 0x07) vd_version={0x01};            // VD Version V0.1 #
static __code unsigned char __at (EEPROM_ADDR + 0x08) eeprom_chk_limit={0xFF};      // EEPROM Check Limit
static __code unsigned char __at (EEPROM_ADDR + 0x09) pei_type={0x00};              // Required PEI Type, written by VD
static __code unsigned char __at (EEPROM_ADDR + 0x0C) port_A_direction={0x00};      // PORT A Direction Bit Setting *
static __code unsigned char __at (EEPROM_ADDR + 0x0D) run_error={0xFB};             // Run Time Error Flags, set when 0
static __code unsigned int  __at (EEPROM_ADDR + 0x17) start_pa={0xFFFF};            // Default PA is 15.15.255 *
#endif


void main(void)
{
	unsigned char n,count,send_nibble=0,pwm0=0,pwm1=0,pwm2=0,prog_button_level=0;
	signed char cal;
	static __code signed char __at (0x1BFF) trimsave;
	__bit prog_button_toggled=0;

	restart_hw();// Hardware zuruecksetzen
#ifdef FB_DEBUG
	RS_INIT_115200
#else
	RS_INIT_9600
#endif
	TI=1;
	TASTER=0;
	cal=trimsave;
	TRIM = TRIM+trimsave;


	for (n=0;n<50;n++) {		// Warten bis Bus stabil
		TR0=0;					// Timer 0 anhalten
		TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Ger�te unterschiedlich beginnen zu senden
		TL0=eeprom[ADDRTAB+2];
		TF0=0;					// �berlauf-Flag zur�cksetzen
		TR0=1;					// Timer 0 starten
		while(!TF0);
	}
	count=0;

	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	bus_return();							// Aktionen bei Busspannungswiederkehr

	do  {
#ifdef FB_DEBUG
		DEBUGPOINT
#endif
		if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt

			// Helligkeit nachf�hren
		if (dimmziel[count]==dimmwert[count]){
			if (helligkeit[count]!= dimmwert[count]){
				helligkeit[count]=dimmwert[count];
//				rs_send(read_obj_value(count+6));
//				rs_send(read_objflags(count+6));
				if (read_objflags(count+6)&0x40){
					send_obj_value(count+6);
				}
			}
		}
		if(count<2)count++;
		else count=0;

#ifndef FB_DEBUG
#ifdef applilpc
		if (TI){
			switch(send_nibble){
			case 0:
			pwm0=dimmpwm[0];
			RS_SEND(0x00+(pwm0<<4));
			break;
			case 1:
			RS_SEND(0x01+(pwm0 & 0xF0));
			break;
			case 2:
			pwm1=dimmpwm[1];
			RS_SEND(0x02+(pwm1<<4));
			break;
			case 3:
			RS_SEND(0x03+(pwm1 & 0xF0));
			break;
			case 4:
			pwm2=dimmpwm[2];
			RS_SEND(0x04+(pwm2<<4));
			break;
			case 5:
			RS_SEND(0x05+(pwm2& 0xF0));
			break;
			case 6:
			RS_SEND(0x06+(portbuffer & 0xF0));
			break;
			default:
				send_nibble=255;

			}// ende switch
		//RI=0;
		send_nibble++;

		} // ende if(TI)...
#endif
#endif
//		if(RI){

		//if(SBUF=='+')dimmziel[0]++;
		//if(SBUF=='-')dimmziel[0]--;
		//if(SBUF=='c')rs_send(0x55);
//		rs_send(helligkeit[SBUF]);

//		RI=0;
//		}



		if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf
/*			if(TF0 && (TMOD & 0x0F)==0x01) {	// Vollstrom f�r Relais ausschalten und wieder PWM ein
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
			if (dimmtimervorteiler>=10){//vorteiler wird alle 50�s in softpwm erh�ht
				dimmtimervorteiler-=10;//
				delay_timer();
			}// ergibt eine flanke von 0.50ms

*/
			if (portchanged)port_schalten();	// Ausg�nge schalten

			// portbuffer flashen, Abbruch durch ext-int wird akzeptiert und sp�ter neu probiert
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
		{			// wenn connected den timeout f�r Unicast connect behandeln
		RTCCON=0x61;// RTC flag l�schen
		if(connected_timeout <= 110)// 11x 520ms --> ca 6 Sekunden
			{
			connected_timeout ++;
			}
			else send_obj_value(T_DISCONNECT);// wenn timeout dann disconnect, flag und var wird in build_tel() gel�scht
		}

		n= tx_buffer[(tx_nextsend-1)&0x07];// ist die letzte objno
		if (tel_arrived || (n<6 && n>8 && tel_sent)) { //
			tel_arrived=0;
			tel_sent=0;
			process_tel();

		}

		// ### PROG Button ###

		TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER){ // Taster gedr�ckt
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


