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
#include <P89LPC922.h>
#include "../lib_lpc922/Releases/fb_lpc922_1.4x.h"
#include "fb_app_dimmer_2channel.h"

#include "../com/fb_rs232.h"
#include  "../com/debug.h"
#include "fb_i2c.h"

/** 
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
* 
*
*/
void main(void)
{ 
	unsigned char n,count,send_nibble=0,pwm0=0,pwm1=0,pwm2=0,tasterpegel=0;
	signed char cal;
	__bit tastergetoggelt=0;
	static __code signed char __at 0x1BFF trimsave;

	restart_hw();							// Hardware zuruecksetzen
	RS_INIT_600

	SBUF= 0x55;
	
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
   i2c_ma_init();

	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	bus_return();							// Aktionen bei Busspannungswiederkehr

	do  {

//DEBUGPOINT
		if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt

			// Helligkeit RM nachführen	
		if (dimmziel[count]==dimmwert[count]){	// wenn das dimmziel erreicht...
			if (helligkeit_RM[count]!= dimmwert[count]){// und das RMO nicht schon gesetzt
				helligkeit_RM[count]=dimmwert[count];// dann setzen 
				send_obj_value(count+8);			// und senden
			}
		}

		if(count<2)count++;
		else count=0;
#ifdef applilpc		
		if (TI){
			switch(send_nibble){	
			case 0:
			pwm0=dimmpwm[0];	
			rs_send(0x00+(pwm0<<4));
			break;
			case 1:
			rs_send(0x01+(pwm0 & 0xF0));
			break;
			case 2:
			pwm1=dimmpwm[1];	
			rs_send(0x02+(pwm1<<4));
			break;
			case 3:
			rs_send(0x03+(pwm1 & 0xF0));
			break;
			case 4:
			pwm2=dimmpwm[2];	
			rs_send(0x04+(pwm2<<4));
			break;
			case 5:
			rs_send(0x05+(pwm2& 0xF0));
			break;
			case 6:
			rs_send(0x06+(portbuffer & 0xF0));
			break;
			default:
				send_nibble=255;
				
			}// ende switch
		//RI=0;	
		send_nibble++;
			
		} // ende if(TI)...
#endif



		
		
		
		
		if(RTCCON>=0x80) delay_timer();	// Realtime clock Ereignis
		
		if (portchanged)port_schalten();	// virtuelle Ausgänge schalten

		}// end if(runstate)

		n= tx_buffer[(tx_nextsend-1)&0x07];// ist die letzte objno
		if (tel_arrived){// || (n<4 && n>5 && tel_sent)) { // 
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

	} while(1);
}


