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


	

//#include <P89LPC922.h>
//#include "../lib_lpc922/Releases/fb_lpc922_1.4x.h"
#include "fb_app_counter.h"
#include"../com/watchdog.h"
//#include "../com/debug.h"
#ifdef IN8_2TE
#include "../com/spi.h"

#endif

const unsigned char bitmask_1[8] ={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
const unsigned char __at 0x01CE space[18];// Hier schreibt und liest die ETS !!
unsigned char __at 0x00 RAM[00]; 


void main(void)
{ 
	unsigned char n,cmd,tasterpegel=0,tmp;
	signed char cal;
	static __code signed char __at 0x1CFF trimsave; // unsigned int base;
	unsigned char pin=0;
#ifdef zykls
	unsigned char tmp,objno,objstate;
#else
	#ifdef zaehler
	unsigned char objno;
	#endif
#endif
	__bit wduf,tastergetoggelt=0;
	wduf=WDCON&0x02;
	TASTER=1;
	if(!TASTER && wduf)cal=0;
	else cal=trimsave;
	TRIM = (TRIM+trimsave);
	TRIM &= 0x3F;//oberen 2 bits ausblenden

	restart_hw();				// Hardware zurücksetzen

 //   rs_init(6);				// serielle Schnittstelle initialisieren
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


  


  restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
  keypad_init();			// keyboard interrupt initialisieren
  
#ifndef IN8_2TE
  portbuffer=0;			// wenn schalter ein, eine obj change erzeugen
  p0h=portbuffer;
#else
  portbuffer=spi_in_out();
  p0h=portbuffer;
#endif
  if(!wduf){
	  	TASTER=0;
  // Verzögerung Busspannungswiederkehr	
		for (n=0;n<50;n++) {		// Warten bis Bus stabil
			TR0=0;					// Timer 0 anhalten
			TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
			TL0=eeprom[ADDRTAB+2];
			TF0=0;					// Überlauf-Flag zurücksetzen
			TR0=1;					// Timer 0 starten
			while(!TF0);
		}
  }
 // watchdog_init();
 // watchdog_start();

  if(!wduf)bus_return();			// Anwendungsspezifische Einstellungen zurücksetzen

//  TASTER=1;// progled/taster
  do  {
//		watchdog_feed();
	    /* feed the watchdog
	    EA = 0;
	    WFEED1 = 0xA5;
	    WFEED2 = 0x5A;
	    EA=1;
*/

if(APPLICATION_RUN){
	  EKBI = 1;
#ifndef IN8_2TE
	  p0h=P0;				// prüfen ob ein Eingang sich geändert hat
#else
	  p0h=spi_in_out();
#endif
	    if (p0h!=portbuffer) 
	    {
	      for(n=1;n<4;n+=2)					// jeden Eingangspin einzel prüfen
	      {
	    	if ((p0h^portbuffer) & bitmask_1[n] )//kürzeste Version
	        {
	          pin_changed(n);				// Änderung verarbeiten
	        }
	      }
	      portbuffer=p0h;					// neuen Portzustand in buffer speichern
	    }
	    tmp;

	    //checken der precounter...
	    while (precounter0 && timerbase[0]<0x80){// wenn precounter0 was gezählt hat und keine Löschanforderung besteht
			tmp=precounter0;
			if(read_obj_value(2)==0){ // Tarif 1
				counter_moment[0]+=tmp;
				counter_summe[0]+=tmp;
			}
			else{	
									// Tarif 2
				counter_moment[1]+=tmp;
				counter_summe[1]+=tmp;
			}
			precounter0-=tmp;
		}
		while(precounter1 && timerbase [2]<0x80){// wenn precounter1 was gezählt hat und keine Löschanforderung besteht
			tmp=precounter1;
			if(read_obj_value(15)==0){ // Tarif 1
				counter_moment[2]+=tmp;
				counter_summe[2]+=tmp;
			}
			else{					// Tarif 2
				counter_moment[3]+=tmp;
				counter_summe[3]+=tmp;
			}
			precounter1-=tmp;
		}
		//}
  
	      
		if (RTCCON>=0x80){
			delay_timer();	// Realtime clock ueberlauf
		}
	        	 

  // löschen der Zählerwerte nach Lösch-Anforderung
		for (n=0;n<4;n+=2){
			if(timerbase[n]& 0x80){// wenn Löschanforderung besteht
				if (!TR1){// warten bis statemachine fertig ist...
					checklevel(1,(timerbase[n]& 0xC0)+n);//checkt hier alle, also auch solche die noch nicht die Zeit erreicht haben!!
					if (timerbase[n]& 0x40){// wenn Tarif 2
						counter_moment[n+1]=0;//Tarif2 löschen
					}
					else{
						counter_moment[n]=0;// sonst Tarif1 löschen
					}
					timerbase[n]&= 0x3F;// Löschanforderung und Tarifflag zurücksetzen
				}
				
			}
		}	
	//if(jede sekunde...)checklevel(0,0xff);// grenzwerte für Überschreiten alle Sekunde abchecken	
		
	}// end if(APLIAKTION_RUN...
	else
	{
		EKBI = 0; // wenn die aplikation nicht läuft keyboard int abschalten
		if (RTCCON>=0x80 && connected)	// Realtime clock ueberlauf
		{			// wenn connected den timeout für Unicast connect behandeln
		RTCCON=0x61;// RTC flag löschen
		if(connected_timeout <= 110)// 11x 520ms --> ca 6 Sekunden
			{
			connected_timeout ++;
			}
			else send_obj_value(T_DISCONNECT);// wenn timeout dann disconnect, flag und var wird in build_tel() gelöscht
		}
	}

	if (tel_arrived ) {//|| tel_sent 
		tel_arrived=0;
		tel_sent=0;
		process_tel();
	}
	else {
		for(n=0;n<100;n++);	// falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann
	}
	cmd;
	// Eingehendes Terminal Kommando verarbeiten...
//DEBUGPOINT

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
			START_WRITECYCLE;	//cal an 0x1CFF schreiben

			FMADRH= 0x1C;		
			FMADRL= 0xFF; 

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


