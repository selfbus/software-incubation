/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2010 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */


#include "fb_app_logi.h"
#include"../com/watchdog.h"




/** 
* Logische Verknüpfung
* 
*/

void main(void)
{ 
	unsigned char n, gateno,tasterpegel=0;
	__bit q=0, a=0, b=0;
	__bit wduf ;

	__bit tastergetoggelt=0;
	
	wduf= WDCON&0x02;
	restart_hw();				// Hardware zuruecksetzen

	TASTER=0;
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
	
	restart_app();				// Anwendungsspezifische Einstellungen zuruecksetzen

	do {
		WATCHDOG_FEED
		if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt

			for(gateno=0; gateno<8; gateno++) {		// Schleife über 8 Gatter
				a=(gate_a>>gateno) & 0x01;			// Eingang A
				b=(gate_b>>gateno) & 0x01;			// Eingang B
				switch(eeprom[0xF4+gateno]) {		// Gattertyp aus eeprom lesen
				case 0:		// AND
					q = a & b;
					break;
				case 1:		// OR
					q = a | b;
					break;
				case 2:		// NAND
					q = ! (a & b);
					break;
				case 3:		// NOR
					q = ! (a | b);
					break;
				case 4:		// EXOR
					q = a ^ b;
					break;
				case 5:		// NEXOR
					q = ! (a ^ b);
				}


				if(q!=((gate_q >> gateno)&0x01)) {	// Telegramm senden nur wenn sich Zustand geändert hat
					if(q) gate_q|=1<<gateno;		// neuen Zustand von Gatterausgang speichern
					else gate_q&=0xFF-(1<<gateno);
					send_obj_value(gateno*3+2);		// Telegramm senden
				}
			}
			P0=gate_q;					// Ausgänge der Gatter auf LEDs ausgeben
		}
		
		if (RTCCON>=0x80)
		{
			RTCCON=0x61;// RTC starten

			if( connected)	// Realtime clock ueberlauf
			{			// wenn connected den timeout für Unicast connect behandeln
				if(connected_timeout <= 110)// 11x 520ms --> ca 6 Sekunden
					{
					connected_timeout ++;
					}
					else send_obj_value(T_DISCONNECT);// wenn timeout dann disconnect, flag und var wird in build_tel() gelöscht
			}
			else
			{
			RTCCON=0x60;		// RTC Flag löschen
			RTCH = 0x01;
			RTCL = 0x20;	// alle 5ms erzeugt in timerflags 10ms am bit 0
			RTCCON=0x61;// RTC starten
			}
		}

		if(tel_arrived) {		// empfangenes Telegramm abarbeiten
			tel_arrived=0;
			process_tel();
		}
		else {
			for(n=0;n<100;n++);	// falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann
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

