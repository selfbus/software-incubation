/*
 *  Copyright (c) 2013 Stefan Taferner <stefan.taferner@gmx.at>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */
#ifndef tor_const_h
#define tor_const_h

// Damit die Eclipse Code Analyse nicht so viele Warnungen anzeigt:
#ifndef SDCC
# define __idata
# define __code
#endif

// Ein Byte auf der seriellen Schnittstelle ausgeben
#define DEBUG_WRITE_BYTE(x) { while (!TI); TI = 0; SBUF = (x); }


//-----------------------------------------------------------------------------
// IO Pins
//-----------------------------------------------------------------------------

/**
 * Pin Eingang: Motor öffnet
 */
#define P_OPENING P0_0

/**
 * Pin Eingang: Motor schließt
 */
#define P_CLOSING P0_1

/**
 * Pin Eingang: Endschalter Tor offen
 */
#define P_OPENED P0_2

/**
 * Pin Eingang: Endschalter Tor geschlossen
 */
#define P_CLOSED P0_3

/**
 * Pin Eingang: Status Lampe
 */
#define P_STATUS P0_4

/**
 * Pin Eingang: Unbenutzt
 */
#define P_UNUSED P0_5

/**
 * Pin Ausgang: Tor öffnen
 */
#define P_OUT_OPEN P0_6

/**
 * Pin Ausgang: Tor schließen / Richtung umschalte
 */
#define P_OUT_CLOSE P0_7

/**
 * Port Maske für Eingänge
 */
#define PMASK_INPUTS 0x3f

/**
 * Port Maske für Ausgänge
 */
#define PMASK_OUTPUTS 0xC0


//-----------------------------------------------------------------------------
// Tor Richtung
//-----------------------------------------------------------------------------

// Tor stoppen
#define DIR_STOP	0

// Tor öffnen
#define DIR_OPEN	1

// Tor schließen
#define DIR_CLOSE	2

// Keine Richtungsangaben
#define DIR_UNSPECIFIED 64


//-----------------------------------------------------------------------------
// Kommunikations Objekte
//-----------------------------------------------------------------------------

// Tor öffnen
#define OBJ_OPEN				0

// Tor schließen
#define OBJ_CLOSE				1

// Tor Status offen
#define OBJ_STAT_OPENED			2

// Tor Status geschlossen
#define OBJ_STAT_CLOSED			3

// Tor Status öffnet
#define OBJ_STAT_OPENING		4

// Tor Status schließt
#define OBJ_STAT_CLOSING		5

// Status Lampe
#define OBJ_STATUS_LAMP			6


//-----------------------------------------------------------------------------
// ETS VD Konfigurations-Parameter
// Zugriff auf diese Parameter über das globale Array eeprom[]
//-----------------------------------------------------------------------------

// Typ der Ansteuerung des Torantriebs: CONTROL_TYPE_1BUTTON, CONTROL_TYPE_2BUTTON
#define CONF_CONTROL_TYPE		500

// Verzögerung für Umschalten des Torantriebs in 0,1sek
#define CONF_SWITCH_DELAY		501



// Typ der Ansteuerung des Torantriebs in CONF_CONTROL_TYPE:
// 1 Knopf (Auf/Stopp/Zu/Stopp)
#define CONTROL_TYPE_1BUTTON	0

// Typ der Ansteuerung des Torantriebs in CONF_CONTROL_TYPE:
// 2 Knopf (Auf/Zu)
#define CONTROL_TYPE_2BUTTON	1


//-----------------------------------------------------------------------------
// Sonstige Konstanten
//-----------------------------------------------------------------------------

// Dauer eines Tor Richtungs Knopfdrucks in Timer Timeouts (0.1s)
#define OPENCLOSE_TIME 150


#endif /*tor_const_h*/
