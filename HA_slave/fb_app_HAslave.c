/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008-2013 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 * 
 * 09.11.08	- delay_timer geht nicht mehr über flash sondern über globale variable delrec
 * 			- delay_timer auf 24bit reduziert statt 32bit
 * 			- port_schalten nur noch eimal pro telegramm für alle pins
 * 			- interrupt-steuerung bei respond() rausgenommen
 * 			- globale variablen pah, pal, rmstate entfernt
 * 			- write_obj_value aufrufe rausgenommen
 * 
 * 23.11.08 - Soft PWM während der Vollstromphase
 * 			- Handbetätigung in delay_timer eingefügt (hierzu P1.3 nötig !)
 *  
 * 01.01.09	- Soft PWM rausgenommen
 * 			- write_obj_value wieder reingenommen mit Überprüfung ob INT unterbrochen hat
 * 			- Rückmeldung bei Busspannungswiederkehr funktioniert jetzt
 * 
 * 13.02.09	- owntele ist ein zähler, wie oft ein gesendetes telegramm intern erneut verarbeitet wurde
 *
 * 12.11.09 - umgestellt auf statemachine-library
 *
 * 18.12.09 - read_obj_value und write_obj_value aus der lib entfernt und in app implementiert
 * 			  kompletter Verzicht auf userram -> alle Stati in globalen Variablen
 *
 * 15.04.10 - Fehler mit den Logigverknüpfungen behoben
 * 
 * 02.01.11 - Ausgabe auf serielle Schieberegister für bistabile Relaise via Compilerschalter
 * 
 */
 

//#include <P89LPC922.h>
//#include "../lib_lpc922/Releases/fb_lpc922_1.53.h"
#include  "fb_app_HAslave.h"
//#include  "../com/debug.h"
#include "../com/fb_rs232.h"
#include"../com/watchdog.h"

//unsigned int __idata __at (0xFE-18)object_value[9];	// wird hier deklariert um den Speicher besser auszunutzen!
unsigned char objects[9];
unsigned char __idata __at(0xFE -17)timerbase[TIMERANZ];// Speicherplatz für die Zeitbasis und 4 status bits
unsigned char __idata __at(0xFE -34)timercnt[TIMERANZ];// speicherplatz für den timercounter und 1 status bit
unsigned int timer;		// Timer für Schaltverzögerungen, wird alle 130us hochgezählt

//unsigned char pattern_up,pattern_down;
unsigned char stepcounter[8],startup;
unsigned char Tval,Taster_ctr;
//unsigned char out_state;	// Werte der Objekte 0-7 (Ausgängsobjekte)
//unsigned char rm_state;		// Werte der Objekte 12-19 (Rückmeldeobjekte)
//unsigned char zf_state;		// Werte der Objekte 8-11 (Zusatzfunktionen 1-4)
unsigned char portbuffer;	// Zwischenspeicherung der Portzustände
unsigned char oldportbuffer;// Wert von portbuffer vor Änderung (war früher ...0x29)
//unsigned char blocked;		// Sperrung der 8 Ausgänge (1=gesperrt)
//unsigned char logicstate;	// Zustand der Verknüpfungen pro Ausgang
__bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszuführen
__bit portchanged;
//__bit zeropulse;
//unsigned char rm_send;		// die von der main zu sendenden Rückmeldungen
#ifdef zeroswitch
unsigned char portausgabe_on;
unsigned char portausgabe_off;
volatile unsigned char schalten_state;
unsigned char phival;
#endif
const unsigned char bitmask_1[8] ={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};











void write_value_req(unsigned char objno) 				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
{

  if (objno<8)
	  {
	  if(telegramm[8]>0 && (!objects[objno]))
		  {
		  startup |= bitmask_1[objno];
		  stepcounter[objno]=0;
		  }
	  objects[objno]=telegramm[8];    // speichern des Objektes
	  
	  if(eeprom[0xFC]& bitmask_1[objno])timercnt[objno+8]=eeprom[0xFE]; // wenn Überwachung aktiviert timer refreshen
	  }
  else objects[objno]=telegramm[7]&0x01;

}


/** 
* Objektwert lesen wurde angefordert, read_value_response Telegramm zurücksenden
*
* 
* @return
* 
*/
void read_value_req(unsigned char objno)
{
 send_obj_value(objno+64);    
}


unsigned long read_obj_value(unsigned char objno) 	// gibt den Wert eines Objektes zurueck
{
	return objects[objno];
}


void write_obj_value(unsigned char objno,unsigned int objvalue)	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
{
	objects[objno]=objvalue;
}






void delay_timer(void)	// zählt alle 65ms die Variable Timer hoch und prüft Queue
{
	unsigned char objno,n,m;
	unsigned int timerflags;
	__bit changed=0;
	
	objno=0;

		timer++;
		timerflags = timer&(~(timer-1));
		for(n=0;n<16;n++){
			if(timerflags & 0x0001){// positive flags erzeugen und schieben
				for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
					if ((timerbase[m]& 0x0F)==n){// wenn die base mit der gespeicherten base übereinstimmt
						if (timercnt[m]){// wenn der counter läuft...
							timercnt[m]=timercnt[m]-1;// den timer [m]decrementieren
						}// end if (timercnt...
					}//end if(timerbase...
				}// end  for(m..
			}// end if timer...
			timerflags = timerflags>>1;
		}//end for (n=...
		
		
/*		// ab Hier die aktion...
		if(timercnt[8]==0x80){// Lauflicht timer 8 (up)
			timercnt[8]=eeprom[0+0xE2]|0x80;
			if(pattern_up&0x80){// wenn letzer Ausgang an lauflicht_up_out senden
				write_obj_value(10,1);
				send_obj_value(10);
			}
			pattern_up<<=1;// schieben
			portbuffer|=pattern_up;// in portbuffer übertragen 
			portchanged=1;		// Änderung melden
			for(n=0;n<8;n++){	// schauen welcher port an war
				if(bitmask_1[n]&pattern_up){// Ausschaltzeit setzen
					timercnt[n]=eeprom[2+0xE2]|0x80;
					timerbase[n]=eeprom[DELAYTAB+1]>>4;
				}
			}
		}
		if(timercnt[9]==0x80){ // lauflicht timer 9 (down)
			timercnt[9]=eeprom[1+0xE2]|0x80;
			if(pattern_down&0x01){// wenn Ausgang 1 ein dann Lauflicht_down_out senden
				write_obj_value(11,1);
				send_obj_value(11);
			}
			pattern_down>>=1;
			portbuffer|=pattern_down;// zuweisen
			portchanged=1;// Änderung melden
			for(n=0;n<8;n++){
				if(bitmask_1[n]&pattern_down){// Ausschaltzeit setzen
					timercnt[n]=eeprom[3+0xE2]|0x80;
					timerbase[n]=eeprom[DELAYTAB+1]&0x0F;
				}
			}
		}
		// hier die normalen 8 step timer
*/		for(objno=0;objno<=7;objno++) {
				if(!timercnt[objno])
				{
					timerbase[objno]=eeprom[0xEC+objno];
					timercnt[objno]=eeprom[0xF4+objno];
					stepcounter[objno]++;
					if(!(startup & bitmask_1[objno]))// wenn nicht startup zyklus: normal schalten
					{
						if (stepcounter[objno]>objects[objno])portbuffer &= (~bitmask_1[objno]);	//ausschalten
						if (stepcounter[objno]<objects[objno]) portbuffer|= bitmask_1[objno];	// einschalten
					}
					else// startup aktiv
					{
						if(stepcounter[objno]) // in dem Falle ist startup zyklus aktiv
						{
							portbuffer|= bitmask_1[objno]; // immer ein
						}
						else // Startupzyklus abgelaufen
						{
							startup &= (~(bitmask_1[objno])); // startup flag loeschen
						}
					}
				}
		}
		// hier die 8 Überwachungstimer timer
		for(objno=0;objno<=7;objno++) {
				if(!timercnt[objno+8]&& (eeprom[0xFC]& bitmask_1[objno]))
				{
					objects[objno]=eeprom[0xE4+objno]; // Ersatzstellgröße laden
					changed=1;
					timercnt[objno+8]=eeprom[0xFE];	// zeit neu setzen
				}
		}
		if(changed)
		{
			objects[8]=1;				// setzen des Fehler objects
			send_obj_value(8); // Fehler objekt senden
		}
		if(portbuffer!=oldportbuffer)portchanged=1;

}


#ifdef HAND		// für Handbetätigung

void handbedienung(void)
{
	unsigned char n;
	unsigned char Tasten=0;
	unsigned char ledport,m,P0_old;
__bit Taste=0;
	Taster_ctr++;
	n=Taster_ctr&0x07;
//	unsigned char n;
ledport;

		//+++++++   Handbetätigung  ++++++++++

	if((TMOD&0x0F)==0x02 && fb_state==0) {
//		ET1=0;

		#ifdef MAX_PORTS_8

		while(  (!PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen

		#endif
		#ifdef MAX_PORTS_4
		while( (TMOD&0x0F)==0x02 && ( TL0>0x72));// PWM scannen um "Hand"-Tasten abzufragen
		#endif
		interrupted=0;	  
		P0_old=P0;// Port sichern
	#ifdef MAX_PORTS_8
		#ifdef zeroswitch
		P1_0=1;	// TXD wird über Dioden auf low gezogen.
		#else
		P1_3= 1;			    //int0 auf 1, wird über Dioden und taster auf low IO gezogen.
		#endif	
		P0=~bitmask_1[n];
		for(m=0;m<5;m++);
		#ifdef zeroswitch
			Taste=P1_0; // check TXD IO
		#else			
			Taste=P1_3;// check INT0 IO
		#endif	
			P0=P0_old;// port zurückschreiben
	#endif	
		 
	#ifdef MAX_PORTS_4
//		ledport=0x01;
//		for (n=0;n<4;n++) {  						
			P0=~bitmask_1[n];
			P0_5=1;			//P0.5 auf 1, wird über Dioden und taster auf low IO gezogen.
//			for(m=0;m<10;m++);
			if (!P0_5){
		  	Tasten=bitmask_1[n];
		  	}
//		  	ledport=ledport<<1;
//		}
//TODO
			P0=oldportbuffer|0x20;//|20 ist neu--> TESTEN  port zurückschreiben
	#endif
		//if (interrupted==1) Tasten=Tval;  // wenn unterbrochen wurde verwerfen wir die Taste
			//Tasten = Tval; // ##############  <----- Hier wird Handbetätigung quasi mit ausgeschaltet !! #########################
		if (!Taste){
  		Tasten= bitmask_1[n];
	  	}
		if ((Tasten&bitmask_1[n])!= (Tval&bitmask_1[n]))  {
			portbuffer=oldportbuffer;
		  	ledport=(Tasten&~Tval)& bitmask_1[n]; // ledport ist hier die Hilfsvariable für steigende Flanke
		  	if (ledport){
		  		portbuffer^=ledport; // bei gedrückter Taste toggeln
		  		portchanged=1;
		  	}
		  	Tval|=(Tasten & bitmask_1[n]);			//neue Taste sichern
		  	Tval&=(Tasten|(~bitmask_1[n]));
		}
//		ET1=1;
	}

}
#endif




#ifdef zeroswitch
void EX0_int (void) __interrupt (0)
{
		schalten_state=1;// Zeitverzögerung zum Einschalten setzen
		TR0=0;
		AUXR1&=0xE9;	// PWM von Timer 0 nicht mehr auf Pin ausgeben
		PWM=0;			// Vollstrom an
		TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
		TH0=einverzH;		// 1.8ms (10ms=6fff)
		TL0=einverzL;		
		TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;
		EX0=0; // war auskommentiert
		ET0=1;
}

	
void timer0_int(void) __interrupt(1)	
	{
	switch (schalten_state)
	{
		case 0 : // Zeitverzögerung zum Einschalten setzen
		break;
		case 1://Einschalten und zeitverzögerung zum Ausschalten setzen
			schalten_state=2;
			P0=portausgabe_on;
			TF0=0;			// Timer 0 für Ausschaltzeitpunkt
			TH0=ausverzH-phival;		// phival= 0 bis 51 einstellbar(main) default=16
			TL0=0xFF;		
			TR0=1;
			
			break;
		case 2:
			schalten_state=3;
			P0=portausgabe_off;
			TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
			TH0=0x02;		// 16ms (10ms=6fff)
			TL0=0x00;		
			TR0=1;
		break;
		case 3:// PWM wieder einschalten
			TMOD=(TMOD & 0xF0) + 2;			// Timer 0 als PWM
			TAMOD=0x01;
			TH0=DUTY;
			TF0=0;
			AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben
			PWM=1;			// PWM Pin muss auf 1 gesetzt werden, damit PWM geht !!!
			TR0=1;
			ET0=0;
			schalten_state=0;
		break;
		default:
		}
}
#endif


void port_schalten(void)		// Schaltet die Ports mit PWM, DUTY ist Pulsverhältnis
{
	unsigned char n, pattern;
n;pattern;
#ifdef zeroswitch //### Nullspannungsschalter ###
	
 #ifdef SPIBISTAB	//serielle schiebeausgang für bistabile Relaise
		spi_2_out(sort_output(portbuffer));		// Ports schalten
		PWM=0;
		TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
		TH0=0x6f;		// 16ms (10ms=6fff)
		TL0=0xff;
		TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;

	rm_state=portbuffer ^ eeprom[RMINV];	// Rückmeldeobjekte setzen
	for (n=0;n<8;n++) {	// Rückmeldung wenn ein Ausgag sich geändert hat
		pattern=1<<n;
		if((portbuffer&pattern)!=(oldportbuffer&pattern)) rm_send|=pattern;//send_obj_value(n+12);
	}

	oldportbuffer=portbuffer;
	portchanged=0;

 #else	// also normaler out8 oder out4 mit zeroswitch
	if(!EX0 && !schalten_state) {	//nur wenn schaltenstate inaktiv 
		portausgabe_on=portbuffer | oldportbuffer;
		portausgabe_off=portbuffer;//& oldportbuffer;

		IE0=0;// interrupt flipflop löschen
		EX0=1;// zero U interrupt einschalten


		rm_state=portbuffer ^ eeprom[RMINV];	// Rückmeldeobjekte setzen
		for (n=0;n<8;n++) {	// Rückmeldung wenn ein Ausgag sich geändert hat
			pattern=1<<n;
			if((portbuffer&pattern)!=(oldportbuffer&pattern)) rm_send|=pattern;		//send_obj_value(n+12);
		}

		oldportbuffer=portbuffer;
		portchanged=0;
	}
 #endif
#else // sonst normaler sporatisch schaltender out
 #ifdef SPIBISTAB	//serielle schiebeausgang für bistabile Relaise
		spi_2_out(sort_output(portbuffer));		// Ports schalten
		PWM=0;
		TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
		TH0=0x6f;		// 16ms (10ms=6fff)
		TL0=0xff;
		TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;

	rm_state=portbuffer ^ eeprom[RMINV];	// Rückmeldeobjekte setzen
	for (n=0;n<8;n++) {	// Rückmeldung wenn ein Ausgag sich geändert hat
		pattern=1<<n;
		if((portbuffer&pattern)!=(oldportbuffer&pattern)) rm_send|=pattern;//send_obj_value(n+12);
	}

	oldportbuffer=portbuffer;
	portchanged=0;

 #else	// also IO_Bistab oder normaler out8 oder out4
   #ifdef IO_BISTAB
	P0=sort_output(portbuffer)&0xFF;	// Ports schalten
	TR0=0;
	TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
	TH0=0x6f;		// 16ms (10ms=6fff)
	TL0=0xff;
	TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
	TAMOD=0x00;
	TR0=1;
	rm_state=portbuffer ^ eeprom[RMINV];	// Rückmeldeobjekte setzen
	for (n=0;n<8;n++) {	// Rückmeldung wenn ein Ausgag sich geändert hat
		pattern=1<<n;
		if((portbuffer&pattern)!=(oldportbuffer&pattern)) rm_send|=pattern;//send_obj_value(n+12);
	}

	oldportbuffer=portbuffer;
	portchanged=0;
	
	
	
   #else	//normaler out8 oder out4
	if(portbuffer & ~oldportbuffer) {	// Vollstrom nur wenn ein relais eingeschaltet wird
		TR0=0;
		AUXR1&=0xE9;	// PWM von Timer 0 nicht mehr auf Pin ausgeben


		PWM=0;			// Vollstrom an

		P0=portbuffer;		// Ports schalten
		TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
		TH0=0x00;		// 16ms (10ms=6fff)
		TL0=0x00;
		TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;
	}
	else P0=portbuffer;

/*	rm_state=portbuffer ^ eeprom[RMINV];	// Rückmeldeobjekte setzen
	#ifdef MAX_PORTS_8
	for (n=0;n<8;n++) {	// Rückmeldung wenn ein Ausgag sich geändert hat
		pattern=1<<n;
		if((portbuffer&pattern)!=(oldportbuffer&pattern)) rm_send|=pattern;		//send_obj_value(n+12);
	}
	#else
	for (n=0;n<4;n++) {	// Rückmeldung wenn ein Ausgag sich geändert hat
		pattern=1<<n;
		if((portbuffer&pattern)!=(oldportbuffer&pattern)) rm_send|=pattern;		//send_obj_value(n+12);
	}
	#endif	
*/
	oldportbuffer=portbuffer;
	portchanged=0;
	#endif	
  #endif	
#endif
}

unsigned int sort_output(unsigned char portbuffer){
   unsigned char diff;
   unsigned int result;
   diff=portbuffer ^ oldportbuffer;
   result=0;
   // A1 
#ifdef MAX_PORTS_8
   if (diff & 0x01){
	   if(portbuffer & 0x01){
		   result|=0x0020;
	   }
	   else{
		   result|=0x0010;
	   }
   }

   // A2
   if (diff & 0x02){
	   if(portbuffer & 0x02){
	      result|=0x0800;
	   }
	   else{
	      result|=0x0400;
	   }
   }
   // A3
   if (diff & 0x04){
	   if(portbuffer & 0x04){
	      result|=0x0080;
	   }
	   else{
	      result|=0x0040;
	   }
   }
   // A4
   if (diff & 0x08){
	   if(portbuffer & 0x08){
	      result|=0x0200;
	   }
	   else{
	      result|=0x0100;
	   }
   }
   
   // A5
   if (diff & 0x10){
	   if(portbuffer & 0x10){
	      result|=0x8000;
	   }
	   else{
	      result|=0x4000;
	   }
   }
   // A6
   if (diff & 0x20){
   	   if(portbuffer & 0x20){
	      result|=0x0002;
	   }
	   else{
	      result|=0x0001;
	   }
   }
   
   // A7
   if (diff & 0x40){
	   if(portbuffer & 0x40){
	      result|=0x2000;
	   }
	   else{
	      result|=0x1000;
	   }
   }
   // A8
   if (diff & 0x80){
	   if(portbuffer & 0x80){
	      result|=0x0008;
	   }
	   else{
	      result|=0x0004;
	   }
   }

#else
 #ifdef IO_BISTAB
   // A1
   if (diff & 0x01){
	   if(portbuffer & 0x01){
	      result|=0x0002;
	   }
	   else{
	      result|=0x0001;
	   }
   }
  // A2
   if (diff & 0x02){
	   if(portbuffer & 0x02){
	      result|=0x0008;
	   }
	   else{
	      result|=0x0004;
	   }
   }
   
   // A3
   if (diff & 0x04){
	   if(portbuffer & 0x04){
	      result|=0x0020;
	   }
	   else{
	      result|=0x0010;
	   }
   }
   
   // A4
   if (diff & 0x08){
	   if(portbuffer & 0x08){
	      result|=0x0080;
	   }
	   else{
	      result|=0x0040;
	   }   
   }
 #else
   // A2
   if (diff & 0x01){
	   if(portbuffer & 0x02){
	      result|=0x0004;
	   }
	   else{
	      result|=0x0008;
	   }
   }
  // A4
   if (diff & 0x02){
	   if(portbuffer & 0x08){
	      result|=0x0001;
	   }
	   else{
	      result|=0x0002;
	   }
   }
   
   // A5
   if (diff & 0x04){
	   if(portbuffer & 0x10){
	      result|=0x0040;
	   }
	   else{
	      result|=0x0080;
	   }
   }
   
   // A7
   if (diff & 0x08){
	   if(portbuffer & 0x40){
	      result|=0x0010;
	   }
	   else{
	      result|=0x0020;
	   }
   }
 #endif
#endif   
   return result;

}


void spi_2_out(unsigned int daten){
	   unsigned char n, unten, mitte,LED_pattern;
	   unsigned int spi_valid;

		do{   
		   unten=daten>>8;
		   mitte=daten & 0xFF;
		   LED_pattern=portbuffer;
		   WRITE=0;
		   CLK=0;
		   for(n=0;n<=7;n++){
		      BOT_OUT=(unten & 0x080)>>7;
		      unten<<=1;
		      CLK=1;
		      CLK=1;
		      CLK=0;
		// LEDs aktualisieren
		      LED_SER=(LED_pattern & 0x080)>>7;
		      LED_pattern<<=1;
		      LED_SCK=1;
		      LED_SCK=1;
		      LED_SCK=0;
		   }
		   LED_RCK=1;
		   LED_RCK=0;
		#ifdef MAX_PORTS_8     
		   for(n=0;n<=7;n++){
		
		      BOT_OUT=(mitte & 0x080)>>7;
		      mitte<<=1;
		      CLK=1;
		      CLK=1;
		      CLK=0;
		   }
		#endif
		   WRITE=1;	// Daten werden im latch gesichert...
		   spi_valid=0;
		   WRITE=0;
		   for(n=0;n<=15;n++){// und zurückgelesen
			 if (P1_3)spi_valid |=1;
			 CLK=1;
			 if(n<15)spi_valid<<=1;
			 CLK=0;
		   }   
		} while(spi_valid!=daten); // solange wiederholen bis Daten korrekt zurückgelesen wurden.
	}





void bus_return(void)		// Aktionen bei Busspannungswiederkehr
{
	unsigned char n, bw, bwh;

	portbuffer=eeprom[PORTSAVE];	// Verhalten nach Busspannungs-Wiederkehr

	bw=eeprom[0xF6];
	for(n=0;n<=3;n++) {			// Ausgänge 1-4
		bwh=(bw>>(2*n))&0x03;
		if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<n));
		if(bwh==0x02)  portbuffer=portbuffer | (0x01<<n);
	}

#ifdef MAX_PORTS_8
	bw=eeprom[0xF7];
	for(n=0;n<=3;n++) {			// Ausgänge 5-8
		bwh=(bw>>(2*n))&0x03;
		if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<(n+4)));
		if(bwh==0x02)  portbuffer=portbuffer | (0x01<<(n+4));
	}
#endif

#ifdef SPIBISTAB
	oldportbuffer=~portbuffer; 	// auf 0 setzen, da sonst kein Vollstrom aktiviert wird
#else
	#ifdef IO_BISTAB
	oldportbuffer=~portbuffer; 	// auf 0 setzen, da sonst kein Vollstrom aktiviert wird
	#else
	oldportbuffer=0;
	#endif
#endif
	portchanged=1;		// Post hinterlegen damit in delaytimer nach portschalten springt


//	rm_state=portbuffer ^ eeprom[RMINV];	// Rückmeldeobjekte setzen


	// Rückmeldung bei Busspannungswiederkehr
//	rm_send|=~portbuffer;// Rückmeldung nur für Objekte mit Wert 0, da Wert 1 in normalem port_schalten eh gesendet wird

}
#ifdef BUS_DOWN
void bus_down (void)
{
	unsigned char or_mask=0;
	unsigned char and_mask=0;
	unsigned char n,mask_pattern;
	for(n=0;n<=3;n++)
	{
		mask_pattern=0x01<<n;
		or_mask=(((eeprom[0xF4]>>(n+1) )& (mask_pattern))|
		(((eeprom[0xF5]>>(n+1))& (mask_pattern))<<4));
		and_mask=~(((eeprom[0xF4]>>(n))& (mask_pattern))|
		((((eeprom[0xF5]>>(n))&(mask_pattern))<<4)));
	portbuffer&=and_mask;
	portbuffer|= or_mask;
	}
	//portbuffer=0;
	port_schalten();
	while(!TF0);
	for(n=0;n<250;n++)//ca 4 sekunden warten
	{	
		WATCHDOG_FEED
		TF0=0;
		while(!TF0);
	}
}
#endif

void restart_app(void) 		// Alle Applikations-Parameter zurücksetzen
{
	unsigned char n;
#ifdef HAND
	Tval=0x00;
#endif
	P0=0;
	P0M1=0x00;		// Port 0 Modus push-pull für Ausgang
#ifdef MAX_PORTS_8
	P0M2=0xFF;
#endif
#ifdef MAX_PORTS_4
  #ifdef IO_BISTAB
	P0M2=0xFF;
  #else
	P0M2= 0x0F;
  #endif
#endif	
 

#ifdef SPIBISTAB
	PWM=1;
#else 
	TMOD=(TMOD & 0xF0) + 2;		// Timer 0 als PWM
	TAMOD=0x01;
	TH0=DUTY;		// Pulsverhältnis PWM
	AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
	TR0=1;			// Timer 0 starten (PWM)
#endif
#ifdef zeroswitch
	schalten_state=0;
#endif	
	ET0=0;			// Interrupt für Timer 0 sperren
	IT0=1;			// Int type flag0, 1=flankengetriggert
//	zf_state=0x00;		// Zustand der Zusatzfunktionen 1-4
//	blocked=0x00;		// Ausgänge nicht gesperrt
	timer=0;			// Timer-Variable, wird alle 130ms inkrementiert
  
//	logicstate=0;
//	delay_toggle=0;
	
	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	START_WRITECYCLE
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x004C = Bosch
	WRITE_BYTE(0x01,0x04,0x4C)
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	STOP_WRITECYCLE
/*#ifdef MAX_PORTS_8				// 8-fach Aktor
	WRITE_BYTE(0x01,0x05,0x04)	// Devicetype 0x2060 = Jung Aktor 2138.10
	WRITE_BYTE(0x01,0x06,0x61)	
#endif
#ifdef MAX_PORTS_4				// 4-fach Aktor
	WRITE_BYTE(0x01,0x05,0x20)	// Devicetype 0x2062 = Jung Aktor 2134.16
	WRITE_BYTE(0x01,0x06,0x62)
#endif
	WRITE_BYTE(0x01,0x07,0x01)	// Versionnumber of application programm
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0x9A)	// COMMSTAB Pointer
*/	EA=1;						// Interrupts freigeben
	IT0=0;// ??
	RTCCON=0x81;
	//EX0=1;
	timerbase[8]=eeprom[DELAYTAB]>>4;//   basis von Obj 0 für timer 8 = patter_up.
//	timerbase[9]=eeprom[DELAYTAB+1]&0x0F;//   basis von Obj 1 für timer 9 = pattern_down.
	  for(n=0;n<8;n++)
		  {
		  objects[n]=0;    // speichern des Objektes
		  if(eeprom[0xFC]& bitmask_1[n])
			  {
			  timerbase[n+8]=eeprom[0xFD];
			  timercnt[n+8]=eeprom[0xFE]; // wenn Überwachung aktiviert timer refreshen
			  }
		  timerbase[n]=eeprom[0xEC];
		  timercnt[n]=eeprom[0xF4];
		  }
	  	objects[8]=0;
}
