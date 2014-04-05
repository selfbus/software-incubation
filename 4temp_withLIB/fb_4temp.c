/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2010 Jan Wegner
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

// Versionen:	1.00	erste Version

	

#include <P89LPC922.h>
#include <fb_lpc922_1.4x.h>
#include "4temp_delay.h"
#include "fb_app_4temp.h"
#include "4temp_onewire.h"



//#define VERSION		101

unsigned char __at 0x00 RAM[00];


void main(void)
{ 

	unsigned char n;

	int th;

	//
	//  Initialisierung
	//
	restart_hw();

	// Warten bis Bus stabil, nach Busspannungswiederkehr
	for (n = 0; n < 50; n++)
	{
		TR0 = 0;					// Timer 0 anhalten
		TH0 = eeprom[ADDRTAB + 1];  // Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
		TL0 = eeprom[ADDRTAB + 2];
		TF0 = 0;					// Überlauf-Flag zurücksetzen
		TR0 = 1;					// Timer 0 starten
		while (!TF0)
			;
	}
	restart_app();

	do  {

		// ***************************************************************************
		// Hier ist der Platz f�r wiederkehrende Abfragen, die nicht zeitkritisch sind
		// ***************************************************************************


		if (!TR1)	// Nur wenn nicht gerade TR1 l�uft, also Senden/Empfangen noch nicht abgeschlossen
		{
			if (sequence==1)
			{
				interrupted=0;
				start_tempconversion();				// Konvertierung starten
				if (!interrupted) sequence=2;
			}
			else if (sequence==2)
			{
				if (ow_read_bit()) sequence=3;		// Konvertierung abgeschlossen
			}
			else
			{
				interrupted=0;

				// Temperatur einlesen + �bergabe Sensortyp
				th=read_temp(  ((eeprom[0x6B+(kanal>>1)])>>(((~kanal)&0x01)<<2))&0x0F  );

				if (!interrupted)
				{
					temp[kanal]=th;

					// Grenzwerte
					grenzwert(kanal);

					// Messwertdifferenz
					messwert(kanal);

					// Buswiederkehr bearbeiten
					if (sende_sofort_bus_return)
					{
						bus_return();
					}

					sequence=1;

					// Kanalumschaltung
					kanal++;
					kanal&=0x03;
#ifdef multiplex					
					P0_0=kanal&0x01;
					P0_1=(kanal>>1)&0x01;
#endif
				}
			}
		}



		if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf


		//
		// Abfrage des Programmier-Tasters
		//
		TASTER = 1;
		if (!TASTER)
		{
			for (n = 0; n < 100; n++) // Entprellen
				;
			while (!TASTER) // Warten bis Taster losgelassen
				;
			status60 ^= 0x81;// Prog-Bit und Parity-Bit im system_state toggeln
		}
		TASTER = !(status60 & 0x01);// LED entsprechend Prog-Bit schalten (low=LED an)
  } while(1);
}


