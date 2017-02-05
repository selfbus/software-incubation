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

#include "fb_app_dimmer_2channel.h"

#include "../com/fb_rs232.h"
//#include  "../com/debug.h"
#include "fb_i2c.h"
#include"../com/watchdog.h"


/**
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
*
*
*/

#ifndef DEBUG_H_
// Wenn Debug aktiv ist werden die Werte in der restart_app() geschrieben damit die Konfiguration nicht
// immer neu geschrieben werden muss.
// Geräteparameter setzen, diese können von der ETS übschrieben werden wenn Schreibschutz nicht aktiv
static __code unsigned char __at (EEPROM_ADDR + 0x00) option_reg={0xFF};            // Option Register, ETS will write 0xFF
static __code unsigned char __at (EEPROM_ADDR + 0x01) fw_version[2]={VER_MAJ,VER_MIN};// Man. Data, used for FW Version
static __code unsigned char __at (EEPROM_ADDR + 0x03) manufacturer[2]={0x00,0x08};  // Herstellercode 0x0008 = G*ra
static __code unsigned char __at (EEPROM_ADDR + 0x05) device_type[2]={0x30,0x15};   // 0x3015 = Dimmen 301501 #
static __code unsigned char __at (EEPROM_ADDR + 0x07) vd_version={0x01};            // VD Version V0.1 #
static __code unsigned char __at (EEPROM_ADDR + 0x08) eeprom_chk_limit={0xFF};      // EEPROM Check Limit
static __code unsigned char __at (EEPROM_ADDR + 0x09) pei_type={0x00};              // Required PEI Type, written by VD
static __code unsigned char __at (EEPROM_ADDR + 0x0C) port_A_direction={0x00};      // PORT A Direction Bit Setting *
static __code unsigned char __at (EEPROM_ADDR + 0x0D) run_error={0xFB};             // Run Time Error Flags, set when 0
static __code unsigned int  __at (EEPROM_ADDR + 0x17) start_pa={0xFFFF};            // Default PA is 15.15.255 *
#endif


void main(void)
{
	unsigned char cmd,n,count,send_nibble=0,pwm0=0,pwm1=0,pwm2=0,tasterpegel=0;

	signed char cal;
	__bit wduf, tastergetoggelt=0;
	static __code signed char __at (0x1CFF) trimsave;

	wduf=WDCON&0x02;

	restart_hw();							// Hardware zuruecksetzen
	TASTER=1;
	if(!TASTER && wduf)cal=0;
	else cal=trimsave;

	TASTER=0;
	TRIM = (TRIM+trimsave);
	TRIM &= 0x3F;//oberen 2 bits ausblenden

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
	WATCHDOG_INIT;
	WATCHDOG_START;

	RS_INIT_600

	SBUF= 0x55;

    i2c_ma_init();

	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen

	bus_return();							// Aktionen bei Busspannungswiederkehr
	count=0;
	do  {
		WATCHDOG_FEED;

        // Disconnect timeout after 6 seconds
        if (RTCCON>=0x80 && connected)   // Realtime clock ueberlauf und
        {                                // wenn connected den timeout für Unicast connect behandeln
            RTCCON=0x61;// RTC flag löschen
            if(connected_timeout <= 110) // 11x 520ms --> ca 6 Sekunden
                connected_timeout++;
            else send_obj_value(T_DISCONNECT);// wenn timeout dann disconnect, flag und var wird in build_tel() gelöscht
        }


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

		}// end if(APPLICATION_RUN)

		cmd;		// Eingehendes Terminal Kommando verarbeiten...
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
						START_WRITECYCLE	//cal an 0x1bff schreiben
						FMADRH= 0x1C;
						FMADRL= 0xFF;
						FMDATA=	cal;
						STOP_WRITECYCLE
						EA=1;				//int wieder freigeben
					}
					if(cmd=='p')status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
					if(cmd=='v'){
						while(!TI);
						TI=0;
						SBUF=1;
					}
					if(cmd=='t'){
						while(!TI);
						TI=0;
						SBUF=2;
					}

				}//end if(RI...


		n= tx_buffer[(tx_nextsend-1)&0x07];// ist die letzte objno

		// Telegrammverarbeitung
		if (tel_arrived || tel_sent) {
		    tel_sent=0;
		    process_tel();
		}
		else
		{
           for(n=0;n<100;n++);     // falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann
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

