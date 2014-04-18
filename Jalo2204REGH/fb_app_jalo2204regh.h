/*
 *    _____ ______ __   __________  __  _______ 
 *   / ___// ____// /  / ____/ __ )/ / / / ___/ 
 *   \__ \/ __/  / /  / /__ / __  / / / /\__ \   
 *  ___/ / /__  / /__/ /__// /_/ / /_/ /___/ /   
 * /____/_____//____/_/   /_____/\____//____/     
 *                                      
 *  Copyright (c) 2010-2014 Andreas Krieger
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

unsigned char __at 0x00 RAM[00]; 


#ifndef FB_APP_JALO
#define FB_APP_JALO


#define MAX_PORTS_8		// Anzahl Ausgänge (nur 4 oder 8 erlaubt)
//#define HAND				// Handsteuerung aktiv (auskommentieren wenn nicht gewünscht)
//#define SPIBISTAB			// Serielle Ausgabe für bistabile relaise aktivieren
//#define zeroswitch			// für Platine mit Nullspannungserkennung
// Parameter-Adressen im EEPROM

#define FUNCASS		0xD8	// Startadresse der Zuordnung der Zusatzfunktionen (2 Byte)
#define OFFDISABLE	0xEB	// Aus-Telegramm ignorieren
#define FUNCTYP		0xED	// Typ der Zusatzfunktion
#define LOGICTYP	0xEE	// Verknüpfungs Typ 0=keine 1=ODER 2=UND 3=UND mir Rückführung
#define BLOCKACT	0xEF    // Verhalten beim Sperren
#define BLOCKPOL	0xF1	// Polarität der Sperrobjekte
#define RELMODE		0xF2	// Relaisbetrieb (Öffner/Schließer)
#define RMINV		0xF3	// Rückmeldung invertiert oder normal
#define	DELAYTAB	0xF9	// Start der Tabelle für Verzögerungswerte (Basis)

// Adressen zum speichern von Applikations Daten
#define PORTSAVE	0x99	// Portzustände
#define TIMERANZ	16	// timeranzahl


#define DUTY	0x50	// 0xFF=immer low 0x00=immer high


#define REFRESH \
		P0= oldportbuffer;	// refresh des Portzustandes in der hal
							// für astabile Relaise 
// SPI Konfiguration
#define CLK			P0_3
#define BOT_OUT		P0_0
#define MID_OUT		P0_1
#define WRITE		P0_2
extern static __code unsigned char __at 0x1CFA blockedsave;
extern __bit handmode;
extern 	__bit portchanged;// globale variable, sie ist 1 wenn sich portbuffer geändert hat
extern unsigned char __at 0x0D portbuffer;
extern unsigned char __at 0x0F blocked;
extern unsigned char __at 0x09 delay_toggle;
extern unsigned char __at 0x10 timerbase[TIMERANZ];
extern unsigned char timerstate[TIMERANZ];
extern unsigned char timercnt[TIMERANZ];
extern unsigned char kanal[4];		// Wert des Kanalobjekts
extern unsigned char  positions_req;
extern unsigned char drive_priority;
extern unsigned char __idata __at 0xFE-40 l_position_target[4];
extern unsigned char __idata __at 0xFE-36 j_position_target[4];
extern unsigned char __idata __at 0xFE-32 l_position_last[4];
extern unsigned char __idata __at 0xFE-28 l_position_stored[4];
extern unsigned char __idata __at 0xFE-24 j_position_stored[4];
extern unsigned char __idata __at 0xFE-20 l_position[4];
extern unsigned char __idata __at 0xFE-16 j_position[4];
extern unsigned char __idata __at 0xFE-12 l_position_int[4];
extern unsigned char __idata __at 0xFE-8 j_position_int[4];
extern unsigned char __idata __at 0xFE-4 l_position_int_pre[4];

extern const unsigned char bitmask_1[8];
//extern const unsigned char drivetime_add_div[16];
// um nur jedes 2. Mal die delay routine auszuführen
//extern unsigned char rm_send;		// die von der main zu sendenden Rückmeldungen
#ifdef zeroswitch
extern unsigned char portausgabe_on; // einzuschaltende IO, die dann im ext 0 int übernommen werden
extern unsigned char portausgabe_off; // auszuschaltende IO, die dann im t 0 int übernommen werden
extern volatile unsigned char schalten_state; // status T0 int
extern unsigned char phival;
#endif

//void write_delay_record(unsigned char objno, unsigned char delay_status, long delay_target);	// Schreibt die Schalt-Verzoegerungswerte ins Flash
//void clear_delay_record(unsigned char objno); // Loescht den Delay Eintrag
void handsteuerung(void);
//void write_value_req(unsigned char objno) ;		// Hauptroutine für Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
//void read_value_req(unsigned char objno) ;
unsigned int calculate_position(unsigned char kanal);
void delay_timer(void);		// zählt alle 130ms die Variable Timer hoch und prüft Queue
void port_schalten(void);	// Ausgänge schalten
void object_schalten(unsigned char objno,unsigned char value,unsigned char pos, __bit objstate);	// Objekt schalten
void Sobject_schalten(unsigned char objno,unsigned char val);// Schaltet die Sicherheitsfunktionen
void set_entriegeln(unsigned char zeitnr);// Setzt die zyklische überwachungszeit
unsigned long zeit(unsigned char base_low,unsigned char base_high,unsigned char faktor_adr,unsigned char obj);
void sobj_update(void);
void set_pause(unsigned char objnr,unsigned char Pstate);// setzt die Pausezeit und traegt Pstate in delreg[] ein
void spi_2_out(unsigned int daten);
unsigned int sort_output(unsigned char portbuffer);
void bus_return(void);		// Aktionen bei Busspannungswiederkehr
void restart_app(void) ;		// Alle Applikations-Parameter zurücksetzen

unsigned long read_obj_value(unsigned char objno) ;	// gibt den Wert eines Objektes zurueck
void write_obj_value(unsigned char objno,unsigned int objvalue);	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
#ifdef zeroswitch
void EX0_int(void) __interrupt (0);
void timer0_int(void) __interrupt (1) ;
#endif

#endif
