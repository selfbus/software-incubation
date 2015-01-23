/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008,2009,2010 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
/**
* @file   fb_app_taster.h
* @author Andreas Krebs <kubi@krebsworld.de>
* @date    2008
* 
* @brief The Freebus Taster Application, Firmware fuer einen 8-fach Taster mit 8 LEDs
* 
* 
*/

#ifndef FB_APP
#define FB_APP


#ifndef LPC936
	#include <P89LPC922.h>
#else
	#include <P89LPC935_6.h>
#endif	

#include "../lib_lpc922/Releases/fb_lpc922_1.55.h"



#define TASTER_8
#define HIGH_ACTIV

#define POWERLED		0xCD
#define LED_DURATION	0xCE
#define FUNCTION		0xCF	// Funktion der Taster
#define COMMAND			0xD3	// Funktion der LEDs und Befehle der Taster
#define DEL_FACTOR2		0xD6


extern unsigned int timer,timerflags;				// Timer fuer Schaltverzoegerungen, wird alle 130us hochgezaehlt
extern unsigned char __idata __at(0xFE-16)timercnc[16];
extern unsigned char __idata __at(0xFE-32)timerbase[16];
extern unsigned char __idata __at(0xFE-48)timerstate[16];
extern __bit delay_toggle;		// um nur jedes 2. Mal die delay routine auszufuehren
extern unsigned char LEDSTATE,dimmcompare,dimmwert; // den LED status speichern um Dimmbar zu machen
extern unsigned char button_buffer;	// puffer fuer taster werte

extern unsigned int object_value[8];
extern unsigned char bit_obj[8];
void timer0_int(void) __interrupt (1);
void port_changed(unsigned char portval);		// ein Taster wurde gedrueckt oder losgelassen
void button_changed(unsigned char buttonno, __bit buttonval);	// Taster Aktion abarbeiten

#ifdef TASTER_8
void switch_led(unsigned char ledno, __bit onoff);	// LED schalten
#endif

void delay_timer(void);			// zaehlt alle 130ms die Variable Timer hoch und prueft Queue
unsigned long read_obj_value(unsigned char objno);
void write_obj_value(unsigned char objno, unsigned int objval);

#endif
