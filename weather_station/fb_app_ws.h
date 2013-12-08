/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2013 Andreas Krieger
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
#ifndef FB_APP_LC
#define FB_APP_LC

// Parameter-Adressen im EEPROM

// Adressen zum speichern von Applikations Daten
#define PORTSAVE	0x99	// Portzustände
#define TIMERANZ	0x04	// timeranzahl





#define REFRESH \
		//P0= oldportbuffer;	// refresh des Portzustandes in der hal
							// für astabile Relaise 
// SPI Konfiguration
#define IDATA_START 0xFE-37
extern 	__bit portchanged;// globale variable, sie ist 1 wenn sich portbuffer geändert hat
extern unsigned char portbuffer;


extern const unsigned int timerflagmask[];
extern const unsigned char bitmask_1[];
extern const unsigned char bitmask_0[];
extern const unsigned char shift_at_2bit[];
extern unsigned char __idata __at IDATA_START+21 stream[];
extern unsigned char stream_ptr;		
extern unsigned char stream_bit_ctr;
extern __bit stream_comming_in;
extern __bit stream_arrived;
extern unsigned int updated_objects;
extern unsigned short __idata __at IDATA_START+13 wind_angle;





void timer0_int(void) __interrupt (1);
void EX0_int (void) __interrupt(0);
__bit checksume(unsigned char package_nomber); // prüft die checksume,gibt 1 zurück wenn ok.
int eis5conversion(signed int zahl);
void delay_timer(void);		// zählt alle 130ms die Variable Timer hoch und prüft Queue
void bus_return(void);		// Aktionen bei Busspannungswiederkehr
void restart_app(void);		// Alle Applikations-Parameter zurücksetzen
unsigned long read_obj_value(unsigned char objno);	// gibt den Wert eines Objektes konvertiert zurueck
int read_obj_data(unsigned char objno);// gibt den Wert eines Objektes in Rohdaten zurueck
void write_obj_value(unsigned char objno,unsigned int objvalue);	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
void update(void);
void sendbychange(unsigned char objno,unsigned char val);
void write_send(unsigned char objno,unsigned int value);

#endif
