/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008-2012 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *
 *	Versionen:	1.00	erste Version
 * 				1.01	int freigabe bei empfangenen telegrammen war zu früh
 * 				1.02	Makros in Schleifen korrigiert
 * 				1.10	umgestellt auf Library, thx to tuxbow :-)
 * 				1.11	mit lib 1.31 kompiliert
 *
 */

#include "fb_app_ft.h"

#include "watchdog.h"



void main(void)
{
	unsigned char n;

	__bit wduf;
	__bit ES_save;
	wduf = WDCON & 0x02;

	restart_hw();					// Hardware zurücksetzen

	TASTER=0;
	for (n = 0; n < 50; n++)   		// Warten bis Bus stabil, nach Busspannungswiederkehr
	{
		TR0 = 0;				  	// Timer 0 anhalten
		TH0 = eeprom[ADDRTAB + 1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
		TL0 = eeprom[ADDRTAB + 2];
		TF0 = 0;					// Überlauf-Flag zurücksetzen
		TR0 = 1;					// Timer 0 starten
		while (!TF0)
			;
	}
	TASTER=1;// LED aus
	restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen

	watchdog_init();
	watchdog_start();

	do
	{
		if(!TASTER)P0=0x00;
		watchdog_feed();
		// atomic access
		ES_save = ES;
		ES = 0x00;
		  n = rsin_stat;
		  rsin_stat = RSIN_NONE;
		ES = ES_save;
// Frame von der ETS kommend verarbeiten
		if ((n == RSIN_VARFRAME) || (ft_process_var_frame_repeat_request == 1))
			ft_process_var_frame();
		if (n == RSIN_FIXFRAME)
			ft_process_fix_frame();
		
// Telegramm vom BUS kommend verarbeiten
		if (tel_arrived && !rsout_busy )
			ft_process_telegram();
// bestaetigtes Telegramm zu ETS hin beantworten
		if (L_Data_conf_done )
		{
			ft_send_bus_frame();
			L_Data_conf_done=0;
		}
		if (tel_acked && !rsout_busy)
			{
			ft_send_L_Data_conf();
			s_telegramm_belegt=0;
			}
/*		if(ft_ack_request&& !s_telegramm_belegt=0;)
		{
			SBUF=0xE5; 
			TB8=0; 
			for(n=1;n!=0;n=n<<1) { 
				if (0xE5 & n) TB8=!TB8; 
			} 
			while(!TI); 
			TI=0;

		}*/
// Kontroll LED Behandlung		
		if (RTCCON >= 0x80)
		{			// clock für die data LED
			RTCCON = 0x61;
			if (timer_data)
			{
				timer_data--;
				LED_data = 0;
			}
			else LED_data = 1;
		}
		//P0=switch_mode<<4;	// anzeige..
	} while (1);
}

