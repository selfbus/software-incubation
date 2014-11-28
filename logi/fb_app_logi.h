/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2009 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

#ifndef FB_APP_LOGI
#define FB_APP_LOGI

#ifdef LPC936
	#include <fb_lpc936_1.53.h>
#else
#include <fb_lpc922_1.53.h>
#endif


// Das REFRESH Makro wird unmittelbar nach Auslösen des Empfangs-Interrupts ausgeführt, falls
// man z.B. Portzustände vor der weiteren Verarbeitung restaurieren muss


extern unsigned char gate_a, gate_b, gate_q;


void delay_timer(void);			// zählt alle 130ms die Variable Timer hoch und prüft Queue

unsigned long read_obj_value(unsigned char objno);
void write_obj_value(unsigned char objno,unsigned int objvalue);

#endif
