/*
 *  Copyright (c) 2013 Stefan Taferner <stefan.taferner@gmx.at>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */

#include "tor_app.h"
#include "tor_const.h"

#include <mcs51/P89LPC922.h>
#include <fb_lpc922_1.4x.h>


// Zähler für Timer Events
unsigned char tenthSeconds;

// Alter Zustand der IO-Port Eingänge
unsigned char lastInputsState;

// Gewünschte Bewegung des Tors. Siehe DIR_ Konstanten in tor_const.h
unsigned char targetDirection;

// Derzeitige Bewegung des Tors. Siehe DIR_ Konstanten in tor_const.h
unsigned char currentDirection;

// Abwärts Zähler für Druck der Öffnen Taste, bei 0 wird der P_OUT_OPEN wieder auf 0 gesetzt
unsigned char openDuration;

// Abwärts Zähler für Druck der Schließen Taste, bei 0 wird der P_OUT_CLOSE wieder auf 0 gesetzt
unsigned char closeDuration;

// Hilfsvariable für Debugging
unsigned int debugValue;
unsigned char debugCounter;
unsigned char debugPins;


/**
 * Tor Richtung steuern
 */
void handle_direction()
{
	__bit pressOpen = 0;

	switch (targetDirection)
	{
	case DIR_OPEN:
		if (P_OPENED | P_OPENING)
			targetDirection = DIR_UNSPECIFIED;
		else pressOpen = 1;
		break;

	case DIR_CLOSE:
		if (P_CLOSED | P_CLOSING)
			targetDirection = DIR_UNSPECIFIED;
		else pressOpen = 1;
		break;

	case DIR_STOP:
		if (P_OPENING | P_CLOSING)
			pressOpen = 1;
		else targetDirection = DIR_UNSPECIFIED;
		break;
	}

	if (pressOpen)
	{
		P_OUT_OPEN = 1;
		openDuration = OPENCLOSE_TIME;
	}
}


/**
 * Die Eingangs-Pins behandeln.
 */
void process_inputs()
{
	unsigned char newInputsState = P0 & PMASK_INPUTS;
	debugPins = P0;

	if (lastInputsState == newInputsState)
		return; // nichts zu tun

	lastInputsState = newInputsState;

	if (P_OPENING) currentDirection = DIR_OPEN;
	else if (P_CLOSING) currentDirection = DIR_CLOSE;
	else currentDirection = DIR_STOP;

	if (openDuration && P_OUT_OPEN)
	{
		P_OUT_OPEN = 0;
		openDuration = OPENCLOSE_TIME;
	}
}


/**
 * Timer Event.
 */
void timer_event()
{
	RTCCON = 0x60;  // RTC anhalten und Flag löschen
	RTCH = 0x16; 	// RTC neu laden (1s = 0xE100; 0,5s = 0x7080; 0,25s = 0x3840; 0,1s = 0x1680)
	RTCL = 0x80;
	RTCCON = 0x61;  // RTC starten

	--tenthSeconds;

	if (openDuration)
	{
		--openDuration;
		if (openDuration == 0)
		{
			if (P_OUT_OPEN)
			{
				// Timer abgelaufen (sonst hätten wir in process_inputs) schon umgeschaltet
				P_OUT_OPEN = 0;
				targetDirection = DIR_UNSPECIFIED;
			}
			else
			{
				handle_direction();
			}
		}
	}
}


/**
 * Wert eines Com-Objekts liefern.
 *
 * @param objno - die ID des Kommunikations-Objekts
 * @return Den Wert des Kommunikations Objekts
 */
unsigned long read_obj_value(unsigned char objno)
{
	objno+=0;
	return 0;
}


/**
 * Empfangenes read_value_request Telegramm verarbeiten.
 */
void read_value_req(unsigned char objno)
{
	objno+=0;
}


/**
 * Empfangenes write_value_request Telegramm verarbeiten
 *
 * @param objno - Nummer des betroffenen Kommunikations-Objekts
 */
void write_value_req(unsigned char objno)
{
	__bit value = telegramm[7] & 1;

	debugValue = (objno<<8) | telegramm[7];
	++debugCounter;

	if (objno == OBJ_OPEN)
	{
		if (targetDirection == DIR_UNSPECIFIED)
			targetDirection = value ? DIR_OPEN : DIR_CLOSE;
		else targetDirection = DIR_STOP;

		handle_direction();
	}
	else if (objno == OBJ_CLOSE)
	{
	}
}


/**
 * Alle Applikations-Parameter zurücksetzen
 */
void restart_app()
{
	// P0.1 .. P0.6 auf Eingang; P0.7 und P0.8 auf Ausgang (Push Pull)
	P0M1 = 0x3F;
	P0M2 = 0xC0;
	P0 = 0;

	RTCH = 0x16;	// RTC neu laden (1s = 0xE100; 0,5s = 0x7080; 0,25s = 0x3840; 0,1s = 0x1680)
	RTCL = 0x80;
	RTCCON = 0x61;  // RTC starten

	// Variablen initialisieren
	lastInputsState = 0xff;
	tenthSeconds = 1;
	openDuration = 0;
	closeDuration = 0;
	currentDirection = DIR_STOP;

	// EEPROM initialisieren

	EA = 0;							// Interrupts sperren, damit Flashen nicht unterbrochen wird
	START_WRITECYCLE;
	WRITE_BYTE(0x01, 0x03, 0x00);	// Herstellercode 0x004C = Bosch
	WRITE_BYTE(0x01, 0x04, 0x4C);
	WRITE_BYTE(0x01, 0x05, 0x04);	// Devicetype 1060 (0x0424)
	WRITE_BYTE(0x01, 0x06, 0x24);
	WRITE_BYTE(0x01, 0x07, 0x01);	// Version der Applikation: 0.1
	WRITE_BYTE(0x01, 0x0C, 0x00);	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01, 0x0D, 0xFF);	// Run-Status (00=stop FF=run)
	STOP_WRITECYCLE;
	EA = 1;							// Interrupts freigeben

	// init reload value and prescaler
	// select Watchdog clock at 400kHz
	// start watchdog
	WDL = 0xFF;
	EA = 0;
	WDCON = 0xE5;
	WFEED1 = 0xA5;
	WFEED2 = 0x5A;
	EA = 1;
}
