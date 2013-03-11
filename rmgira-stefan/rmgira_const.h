/*
 *  Copyright (c) 2013 Stefan Taferner <stefan.taferner@gmx.at>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */
#ifndef rmgira_const_h
#define rmgira_const_h

// Damit die Eclipse Code Analyse nicht so viele Warnungen anzeigt:
#ifndef SDCC
# define __idata
# define __code
#endif


//-----------------------------------------------------------------------------
// Kommunikations Objekte
//-----------------------------------------------------------------------------

#define OBJ_NONE                31

#define OBJ_SET_ALARM			0
#define OBJ_SET_TALARM			1
#define OBJ_NOTUSED2			2
#define OBJ_NOTUSED3			3
#define OBJ_SERIAL				4
#define OBJ_OPERATING_TIME		5
#define OBJ_SMOKEBOX_VALUE		6
#define OBJ_POLLUTION			7
#define OBJ_BAT_VOLTAGE			8
#define OBJ_TEMP1				9
#define OBJ_TEMP2				10
#define OBJ_CNT_SMOKEALARM		11
#define OBJ_CNT_TEMPALARM		12
#define OBJ_CNT_TESTALARM		13
#define OBJ_CNT_ALARM_WIRE		14
#define OBJ_CNT_ALARM_WIRELESS	15
#define OBJ_CNT_TALARM_WIRE		16
#define OBJ_CNT_TALARM_WIRELESS	17
#define OBJ_STAT_ALARM			18
#define OBJ_STAT_ALARM_CENTRAL	19
#define OBJ_STAT_ALARM_DELAYED	20
#define OBJ_STAT_TALARM			21
#define OBJ_STAT_TALARM_CENTRAL	22
#define NUM_OBJS                23



//-----------------------------------------------------------------------------
// Befehle an den Rauchmelder
//-----------------------------------------------------------------------------

// Gira Command: Seriennummer abfragen
#define GIRA_CMD_SERIAL  0

// Gira Command: Betriebszeit abfragen
#define GIRA_CMD_OPERATING_TIME  1

// Gira Command: Rauchkammer Daten abfragen
#define GIRA_CMD_SMOKEBOX 2

// Gira Command: Batteriespannung und Temperaturen
#define GIRA_CMD_BATTEMP  3

// Gira Command: Anzahl der Alarme #1 abfragen
#define GIRA_CMD_NUM_ALARMS  4

// Gira Command: Anzahl der Alarme #2 abfragen
#define GIRA_CMD_NUM_ALARMS_2  5

// Anzahl der Gira Commands
#define GIRA_CMD_COUNT  6

// Gira Command: intern behandelt, kein Befehl an den Rauchmelder
#define GIRA_CMD_INTERNAL 14

// Gira Command: kein Befehl
#define GIRA_CMD_NONE  15


//-----------------------------------------------------------------------------
// Datentypen der Rauchmelder Antworten
//-----------------------------------------------------------------------------

// Rauchmelder Antwort: 4 Byte Zahl
#define GIRA_TYPE_LONG 1

// Rauchmelder Antwort: 2 Byte Zahl
#define GIRA_TYPE_INT  2

// Rauchmelder Antwort: 1 Byte Zahl
#define GIRA_TYPE_BYTE 3

// Rauchmelder Antwort: 1 Byte Temperatur
#define GIRA_TYPE_TEMP 4

// Rauchmelder Antwort: 2 Byte Spannung
#define GIRA_TYPE_VOLT 5

// Rauchmelder Antwort: Kein Typ
#define GIRA_TYPE_NONE 127


//-----------------------------------------------------------------------------
// Kommunikations Konstanten
//-----------------------------------------------------------------------------

// Start Byte
#define STX		0x02

// Ende Byte
#define ETX		0x03

// Acknowledged
#define ACK	 	0x06

// Not Acknowledged
#define NAK	 	0x15


#endif /*rmgira_const_h*/
