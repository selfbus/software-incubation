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
* @brief  The Freebus relais application to switch  up to 8 relais \n
* Manufactorer code is 0x04 = Jung \n
* Device type    8 out (2038.10) 0x2060 Ordernumber: 2138.10REG    or \n
* 		4 out Devicetype 0x2062 = Jung Aktor 2134.16 
*
* \par Changes:
 
* @todo:
	- Prio beim Senden implementieren \n
	- Zwangsstellungsobjekte implementieren \n
*/
//#include <P89LPC922.h>
//#include "fb_lpc922_1.53.h"
#include "fb_app_2i2o.h"
//#include  "../com/debug.h"
//#include "../com/fb_rs232.h"
//#include"../com/watchdog.h"



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
#define VERSION 39

unsigned char __idata __at 0x00 RAM[00];
static __code unsigned char __at 0x1D03 manufacturer[2]={0,4};	// Herstellercode 0x0004 = Jung
static __code unsigned char __at 0x1D0C port_A_direction={0};	// PORT A Direction Bit Setting
static __code unsigned char __at 0x1D0D run_state={255};		// Run-Status (00=stop FF=run)
__code unsigned int __at (EEPROM_ADDR + 0x17) start_pa={0xFFFF};      // Default PA is 15.15.255

__bit bus_return_ready=0; 
const unsigned char bitmask_1[8] ={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
//const unsigned char __at 0x1CFF PORTSAVE;
void main(void)
{ 
	unsigned char timer_precounter=0;

	unsigned char n,cmd,tasterpegel=0,pin=2;
	unsigned int base;
//	signed char cal;
//	unsigned int m;
	unsigned char rm_count=0;
	__bit wduf;
	__bit tastergetoggelt=0;
	__bit bus_activ=0;

	wduf=WDCON&0x02;
	restart_hw();							// Hardware zuruecksetzen
// im folgendem wird der watchdof underflow abgefragt und mit gedrücktem Progtaster
// ein resetten der cal Variable veranlasst um wieder per rs232 trimmen zu können.	
//	TASTER=1;
//	if(!TASTER && wduf)cal=0;
//	else cal=trimsave;
	TASTER=0;
//	TRIM = (TRIM+trimsave);
//	TRIM &= 0x3F;//oberen 2 bits ausblenden
	TR0=1;
	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	if(!wduf){
	  // Verzögerung Busspannungswiederkehr	
		  for(base=0;base<=(eeprom[0xD4]<<(eeprom[0xFE]>>4)) ;base++){//faktor startverz hohlen und um basis nach links schieben
		//	  start_rtc(130);		// rtc auf 130ms
				RTCCON=0x60;		// RTC anhalten und Flag löschen
				RTCH=0x1D;			// reload Real Time Clock für 65ms
				RTCL=0x40;
				RTCCON=0x61;		// RTC starten
			    while (RTCCON<=0x7F) ;	// Realtime clock ueberlauf abwarten
			    // feed the watchdog
			    EA = 0;
			    WFEED1 = 0xA5;
			    WFEED2 = 0x5A;
			    EA=1;

			    //	  stop_rtc;
		  }
	  }
		WATCHDOG_INIT
		WATCHDOG_START

	//if(!wduf)bus_return();							// Aktionen bei Busspannungswiederkehr

#ifndef debugmode
	RS_INIT_600
#else
	RS_INIT_115200
#endif
	SBUF=0x55;

// ################## main loop #########################	

	do  {
		WATCHDOG_FEED

	if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt


	  p0h=P0 & 0x0C;				// prüfen ob ein Eingang sich geändert hat

	  if(!bus_return_ready)
	  {
		  portbuffer=p0h;
	  	  if(!wduf)bus_return();			// Anwendungsspezifische Einstellungen zurücksetzen
	  	  bus_return_ready=1;
	  }
	  if (p0h!=portbuffer) 
	    {	

		  if (((p0h^portbuffer) & bitmask_1[pin])&& !(in_blocked & bitmask_1[pin]) )//kürzeste Version
	        {
	          pin_changed(pin);				// Änderung verarbeiten
	        }
	      portbuffer|=(p0h& bitmask_1[pin]);					// neuen Portzustand in buffer speichern
	      portbuffer&=(p0h| ~bitmask_1[pin]);					// neuen Portzustand in buffer speichern
	     // if(pin==3)pin=2;// maximal 2-3
	   //   else pin=3;	// nächsten pin prüfen..
	      pin^=0x01;// pin ist mit 2 initialisiert somit wird zwischen 2 und 3 hin und hergeschalten
	    }
	      
			
			
			
			
			if(RTCCON>=0x80){
				RTCCON=0x60;		// RTC Flag löschen
				RTCH=0x03;			//0E reload Real Time Clock
				RTCL=0x9A;			//A0 16ms +precounter x4
				RTCCON=0x61;		// RTC  Flag löschen
				timer_precounter++;
				if((timer_precounter&0x03)==3)
				{
					delay_timer();	// timer handler jedes 4. mal--> 64ms
				}
			}
			if(TF0 && (TMOD & 0x0F)==0x01) {	// Vollstrom für Relais ausschalten und wieder PWM ein
				TMOD=(TMOD & 0xF0) + 2;			// Timer 0 als PWM
				TAMOD=0x01;
				TH0=DUTY;
				TF0=0;
				AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben
				PWM=1;			// PWM Pin muss auf 1 gesetzt werden, damit PWM geht !!!
				TR0=1;
			}

		
			
			if (portchanged)port_schalten();	// Ausgänge schalten

			// Rückmeldungen senden
			if(rm_send&0x03) {	// wenn nichts zu senden ist keine Zeit vertrödeln
				if(rm_send & (1<<rm_count)) {
					if(send_obj_value(rm_count + 16)) {	// falls erfolgreich, dann nächste
						rm_send&=(0xFF-(1<<rm_count));
						rm_count^=0x01;
					}
				}
				else {	// RM sollte nicht gesendet werden
					rm_count^=0x01;
				}
			}
			else rm_count=0;


			// portbuffer flashen, Abbruch durch ext-int wird akzeptiert und später neu probiert
			// T1-int wird solange abgeschaltet, 

			if (fb_state==0 && (TH1<0XC0) && (!wait_for_ack)&& portbuffer!=PORTSAVE) {
				START_WRITECYCLE;
				WRITE_BYTE(0x00,0xFF,portbuffer);
				STOP_WRITECYCLE;
			}
		
		}// end if(APPLICATION RUN..
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
DEBUGPOINT;
//SNIFFPOINT;	
		
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


