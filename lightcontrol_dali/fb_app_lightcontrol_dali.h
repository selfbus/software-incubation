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

#ifndef FB_APP_LC
#define FB_APP_LC
//#define debugmode
#ifdef LPC936
	#include <fb_lpc936_1.53.h>
#else
#include <fb_lpc922_1.53.h>
#endif


//#define HAND				// Handsteuerung aktiv (auskommentieren wenn nicht gewünscht)
#define MAX_PORTS_4			// Anzahl Ausgänge (nur 4 oder 8 erlaubt)
//#define SPIBISTAB			// Serielle Ausgabe für bistabile relaise aktivieren
// Parameter-Adressen im EEPROM
#define FUNCASS		0xD8	// Startadresse der Zuordnung der Zusatzfunktionen (2 Byte)
#define OFFDISABLE	0xEB	// Aus-Telegramm ignorieren
#define FUNCTYP		0xED	// Typ der Zusatzfunktion
#define LOGICTYP	0xEE	// Verknüpfungs Typ 0=keine 1=ODER 2=UND 3=UND mir Rückführung
#define BLOCKACT	0xEF	// Verhalten beim Sperren
#define BLOCKPOL	0xF1	// Polarität der Sperrobjekte
#define RELMODE		0xF2	// Relaisbetrieb (Öffner/Schließer)
#define RMINV		0xF3	// Rückmeldung invertiert oder normal
#define	DELAYTAB	0xF9	// Start der Tabelle für Verzögerungswerte (Basis)

// Adressen zum speichern von Applikations Daten
#define PORTSAVE	0x99	// Portzustände
#define TIMERANZ	0x06	// timeranzahl




#define DUTY	0x50	// 0xFF=immer low 0x00=immer high

#define REFRESH \
		//P0= oldportbuffer;	// refresh des Portzustandes in der hal
							// für astabile Relaise 
// SPI Konfiguration
#define CLK			P0_3
#define BOT_OUT		P0_0
#define MID_OUT		P0_1
#define WRITE		P0_2

extern 	__bit portchanged;// globale variable, sie ist 1 wenn sich portbuffer geändert hat
__data __at (0x25) extern unsigned char portbuffer;
__bit __at(0x2C)A1;// bitadresse 0x2C ist byteadresse 0x25_4 (portbuffer_4)
__bit __at(0x2D)A2;
__bit __at(0x2E)A3;
__bit __at(0x2F)A4;
__bit __at(0x44)SM_1;
__bit __at(0x45)SM_2;
__bit __at(0x46)SM_3;
__bit __at(0x40)S_1;// Die Sperren bitadressen für byte 0x28
__bit __at(0x41)S_2;
__bit __at(0x42)S_3;

extern unsigned char dimmtimervorteiler;
extern __data __at (23) unsigned char dimmwert[3];
extern __data __at (11) unsigned char dimmziel[3];
extern __data __at (26) unsigned char dimmpwm[4];
extern __data __at (0x28) unsigned char sperren;
extern __data __at (0x26) unsigned char schalten;
extern __data __at (0x11) unsigned char helligkeit[3];

extern unsigned char aushell[3];
extern __idata __at (0xFE-3)unsigned char D_hell[3];

extern unsigned int D_forward;
extern __bit D_value;
extern unsigned char D_f_busy;
extern unsigned char D_position;

extern const unsigned char grundhelligkeit_tabelle[];
extern const unsigned char prozentvalue[];

extern const unsigned int timerflagmask[];
extern const unsigned char bitmask_1[];
extern const unsigned char bitmask_0[];
extern const unsigned char bitmask_11[];

void timer0_int(void) __interrupt (1);
//void write_delay_record(unsigned char objno, unsigned char delay_status, long delay_target);	// Schreibt die Schalt-Verzoegerungswerte ins Flash
//void clear_delay_record(unsigned char objno); // Loescht den Delay Eintrag
//void write_value_req(void);		// Hauptroutine für Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
//void read_value_req(void);
void delay_timer(void);		// zählt alle 130ms die Variable Timer hoch und prüft Queue
void port_schalten(void);	// Ausgänge schalten
void object_schalten(unsigned char objno, __bit objstate);	// Objekt schalten
void spi_2_out(unsigned int daten);
unsigned int sort_output(unsigned char portbuffer);
void send_frame(void);
void bus_return(void);		// Aktionen bei Busspannungswiederkehr
void restart_app(void);		// Alle Applikations-Parameter zurücksetzen
void read_dimmziel(unsigned char objno,unsigned char offset);
unsigned long read_obj_value(unsigned char objno);	// gibt den Wert eines Objektes zurueck
void write_obj_value(unsigned char objno,unsigned int objvalue);	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
void hell_stellen (unsigned char obj,unsigned char value);// stellt die Helligkeit nach Helligkeit oder Lichszene tele ein
unsigned char sperrvalue(unsigned char index,unsigned char obj);// holt Sperrvalue nach index
void DALI_send(unsigned int D_send_value ,unsigned char Kanal) ;

#endif
