/*
 *  Copyright (c) 2013 Stefan Taferner <stefan.taferner@gmx.at>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */

#include "rmgira_app.h"
#include "rmgira_const.h"

#include <P89LPC922.h>

#include <fb_lpc922.h>


// Rauchmelder Konstanten
#define GIRA_START_BYTE		0x02
#define GIRA_STOP_BYTE 		0x03
#define GIRA_ACK_BYTE	 	0x06
#define GIRA_CMD_COUNT      6
#define GIRA_CMD_SIZE		6
#define GIRA_ANSWER_SIZE    8
#define GIRA_ANSWER_MAX     16
#define GIRA_ANSWER_BYTES   4


// GIRA_CMD Befehle an den Rauchmelder
const unsigned char giraCmdTab[GIRA_CMD_COUNT][GIRA_CMD_SIZE] =
{
	{0x02, 0x30, 0x34, 0x36, 0x34, 0x03},   // GIRA_CMD_SERIAL
	{0x02, 0x30, 0x39, 0x36, 0x39, 0x03},   // GIRA_CMD_OPERATING_TIME
	{0x02, 0x30, 0x42, 0x37, 0x32, 0x03},   // GIRA_CMD_SMOKEBOX
	{0x02, 0x30, 0x43, 0x37, 0x33, 0x03},   // GIRA_CMD_BATTEMP
	{0x02, 0x30, 0x44, 0x37, 0x34, 0x03},   // GIRA_CMD_NUM_ALARMS
	{0x02, 0x30, 0x45, 0x37, 0x35, 0x03}	// GIRA_CMD_NUM_TEST_ALARMS
};


// Array mit den Daten aus den Antworten auf die GIRA_CMD Befehle
// Der erste Index ist der Befehl (GIRA_CMD_*), der zweite Index ist
// das Byte aus der Antwort.
unsigned char giraAnswerTab[GIRA_CMD_COUNT][GIRA_ANSWER_BYTES];


// Mapping von den Kommunikations-Objekten auf die Rauchmelder Requests
// und die Daten in der Rauchmelder Antwort. Der Index in die Tabelle ist
// die ID vom Kommunikations-Objekt (objid).
const struct
{
	unsigned const char cmd;       // Zu sendender GIRA_CMD Befehl
	unsigned const char offset;    // Byte-Offset in der Antwort
	unsigned const char dataType;  // Datentyp der Antwort
} objMappingTab[OBJ_MAX_INDEX] =
{
	/*OBJ_SET_ALARM*/           { GIRA_CMD_NONE,            0, GIRA_TYPE_NONE },
	/*OBJ_SET_TALARM*/          { GIRA_CMD_NONE,            0, GIRA_TYPE_NONE },
	/*OBJ_NOTUSED2*/            { GIRA_CMD_NONE,            0, GIRA_TYPE_NONE },
	/*OBJ_NOTUSED3*/            { GIRA_CMD_NONE,            0, GIRA_TYPE_NONE },
	/*OBJ_SERIAL*/              { GIRA_CMD_SERIAL,          0, GIRA_TYPE_LONG },
	/*OBJ_OPERATING_TIME*/      { GIRA_CMD_OPERATING_TIME,  0, GIRA_TYPE_LONG },
	/*OBJ_SMOKEBOX_VALUE*/      { GIRA_CMD_SMOKEBOX,        0, GIRA_TYPE_INT  },
	/*OBJ_POLLUTION*/           { GIRA_CMD_SMOKEBOX,        3, GIRA_TYPE_BYTE },
	/*OBJ_BAT_VOLTAGE*/         { GIRA_CMD_BATTEMP,         0, GIRA_TYPE_VOLT },
	/*OBJ_TEMP1*/               { GIRA_CMD_BATTEMP,         3, GIRA_TYPE_TEMP },
	/*OBJ_TEMP2*/               { GIRA_CMD_BATTEMP,         2, GIRA_TYPE_TEMP },
	/*OBJ_CNT_SMOKEALARM*/      { GIRA_CMD_SMOKEBOX,        2, GIRA_TYPE_BYTE },
	/*OBJ_CNT_TEMPALARM*/       { GIRA_CMD_NUM_ALARMS,      0, GIRA_TYPE_BYTE },
	/*OBJ_CNT_TESTALARM*/       { GIRA_CMD_NUM_ALARMS,      1, GIRA_TYPE_BYTE },
	/*OBJ_CNT_ALARM_WIRE*/      { GIRA_CMD_NUM_ALARMS,      2, GIRA_TYPE_BYTE },
	/*OBJ_CNT_ALARM_WIRELESS*/  { GIRA_CMD_NUM_ALARMS,      3, GIRA_TYPE_BYTE },
	/*OBJ_CNT_TALARM_WIRE*/     { GIRA_CMD_NUM_TEST_ALARMS, 0, GIRA_TYPE_BYTE },
	/*OBJ_CNT_TALARM_WIRELESS*/ { GIRA_CMD_NUM_TEST_ALARMS, 1, GIRA_TYPE_BYTE },
	/*OBJ_STAT_ALARM*/          { GIRA_CMD_NONE,            0, GIRA_TYPE_NONE },
	/*OBJ_STAT_ALARM_CENTRAL*/  { GIRA_CMD_NONE,            0, GIRA_TYPE_NONE },
	/*OBJ_STAT_ALARM_DELAYED*/  { GIRA_CMD_NONE,            0, GIRA_TYPE_NONE },
	/*OBJ_STAT_TALARM*/         { GIRA_CMD_NONE,            0, GIRA_TYPE_NONE },
	/*OBJ_STAT_TALARM_CENTRAL*/ { GIRA_CMD_NONE,            0, GIRA_TYPE_NONE }
};


// Ringpuffer für die Abfrage von Kommunikationsobjekten
unsigned char __idata readObjRing[8];

// Schreib Index für readObjRing
unsigned char __idata readObjRingNextWrite = 0;

// Lese Index für readObjRing
unsigned char __idata readObjRingNextRead = 0;

// Puffer für Antworten vom Rauchmelder
unsigned char __idata giraAnswer[GIRA_ANSWER_SIZE];

// Zähler für die Antwort-Zeichen vom Rauchmelder
char giraAnswerCount = -1;

// Alarm Typ
char alarmType = 0;

// Zeitpunkt bei dem ein Remote Alarm von Test-Alarm auf Alarm umschaltet
unsigned char remoteFullAlarmTime = 0;

// Zähler für halbe Sekunden
unsigned int timer = 0;


/**
 * Eine Bytefolge an den Rauchmelder senden. Es werden die ersten
 * GIRA_CMD_SIZE Bytes aus str gesendet.
 */
void gira_send_bytes(unsigned char* str)
{
	unsigned char idx = 0;
	while (idx < GIRA_CMD_SIZE)
	{
		while (!TI)
			;

		TI = 0;
		SBUF = str[idx];
		++idx;
	}
}


/**
 * Ein Kommunikations-Objekt abfragen und danach auf den Bus senden.
 *
 * Die Befehle werden in einem Ringpuffer abgelegt und der Reihe nach in
 * gira_process_commands() verarbeitet.
 *
 * @param objid - Objekt ID
 * @param isResponse - 1 wenn ein Response Telegramm gesendet werden soll, 0 für ein normales Telegramm.
 */
void gira_send_cmd(unsigned char objid, __bit isResponse)
{
	// Bei Überlauf oder ungültigem Befehl wird der Befehl ignoriert
	if (((readObjRingNextWrite + 1) & 7) != readObjRingNextRead && objid < OBJ_MAX_INDEX)
	{
		if (isResponse)
			objid |= RESPONSE_TEL_FLAG;

		readObjRing[readObjRingNextWrite] = objid;

		++readObjRingNextWrite;
		readObjRingNextWrite &= 7;
	}
}


/**
 * Ein Acknowledge an den Rauchmelder senden.
 */
void gira_send_ack()
{
	while (!TI)
		;

 	TI = 0;
	SBUF = GIRA_ACK_BYTE;
}


/**
 * Einen Wert auf DPT 9.001 2 Byte Float Format wandeln
 *
 * @param val - der zu wandelnde Wert
 * @return Der Wert val im DPT 9.001 Format
 */
unsigned long conv_dpt_9_001(unsigned long val)
{
	unsigned int div = 0;
	while (val >= 2047)
	{
		++div;
		val >>= 1;
	}
	val  |= div << 11;
	return val;
}


/**
 * Empfangenes write_value_request Telegramm verarbeiten
 *
 * @param objno - Nummer des betroffenen Kommunikations-Objekts
 */
void write_value_obj(unsigned char objno)
{
	if (objno == OBJ_SET_ALARM) // Remote Alarm
	{
		if (telegramm[7] & 0x01)
		{
			alarmType |= ALARM_REMOTE_TEST;
			remoteFullAlarmTime = timer + 10;
		}
		else alarmType &= ~ALARM_REMOTE;
	}
	else if (objno == OBJ_SET_TALARM) // Remote Test Alarm
	{
		if (telegramm[7] & 0x01)
			alarmType |= ALARM_REMOTE_TEST;
		else alarmType &= ~ALARM_REMOTE_TEST;
	}
}


/**
 * Empfangenes write_value_request Telegramm verarbeiten
 */
void write_value_req()
{
	unsigned char objno, objflags, gapos, atp, assno, idx, gaposh;

	// Gruppenadressposition aus Gruppenadresse bestimmen
	gapos = gapos_in_gat(telegramm[3], telegramm[4]);
	if (gapos != 0xFF)
	{
		atp = eeprom[ASSOCTABPTR];  // Association Table Pointer
		assno = eeprom[atp];		// Erster Eintrag = Anzahl Einträge

		// Schleife über alle Eintraege in der Ass-Table, denn es könnten mehrere Objekte
		// der gleichen Gruppenadresse zugeordnet sein.
		for (idx = 0; idx < assno; idx++)
		{
			gaposh = eeprom[atp + 1 + (idx * 2)];	// Erste GA-Position aus ASS Tabelle lesen

			if (gapos == gaposh) // Wenn Positionsnummer übereinstimmt
			{
				objno = eeprom[atp + 2 + (idx * 2)];	// Objektnummer
				objflags = read_objflags(objno);		// Objekt Flags lesen

				// Wenn Kommunikation zulässig (Bit 2 = communication enable) und
				// Schreiben zulaessig (Bit 4 = write enable)
//				if ((objflags & 0x14) == 0x14)
//				{
					write_value_obj(objno);
//				}
			}
		}
	}
}


/**
 * Empfangenes read_value_request Telegramm verarbeiten.
 */
void read_value_req()
{
	unsigned char objno, objflags;

	objno = find_first_objno(telegramm[3], telegramm[4]);
	objflags = read_objflags(objno);	// Read object flags
	if ((objflags&0x0C) == 0x0C)		// Answer only when READ and COM flags are set
	{
		gira_send_cmd(objno, 1);
	}
}


/**
 * Wert eines Kommunikations-Objekts liefern.
 *
 * @param objno - die ID des Kommunikations-Objekts
 * @return Den Wert des Kommunikations Objekts
 */
unsigned long read_obj_value(unsigned char objno)
{
	// Kommunikations-Objekte verarbeiten die Werte vom Rauchmelder darstellen
	if (objMappingTab[objno].cmd != GIRA_CMD_NONE)
	{
		unsigned long result = 0;
		unsigned char* answer = giraAnswerTab[objMappingTab[objno].cmd];
		answer += objMappingTab[objno].offset;

		switch (objMappingTab[objno].dataType)
		{
		case GIRA_TYPE_BYTE:
			return *answer;

		case GIRA_TYPE_LONG:
			return *(unsigned long*) answer;

		case GIRA_TYPE_INT:
			return *(unsigned int*) answer;

		case GIRA_TYPE_TEMP:
			result = *answer;
			result *= 50;
			result -= 2000;
			return conv_dpt_9_001(result);

		case GIRA_TYPE_VOLT:
			result = *(unsigned int*) answer;
			result *= 9184;
			result /= 5000;
			return conv_dpt_9_001(result);

		default: // Fehler
			return (unsigned long) -1;
		}
	}

	// Andere Kommunikations-Objekte
	switch (objno)
	{
	case OBJ_STAT_ALARM:
	case OBJ_STAT_ALARM_CENTRAL:
	case OBJ_STAT_ALARM_DELAYED:
		if (alarmType & ALARM_MASK) return 1;
		return 0;

	case OBJ_STAT_TALARM:
	case OBJ_STAT_TALARM_CENTRAL:
		if (alarmType & ALARM_TEST_MASK) return 1;
		return 0;
	}

	return (unsigned long) -2;
}


/**
 * Die Antwort vom Rauchmelder verarbeiten.
 */
void gira_process_answer()
{
	unsigned char objno = readObjRing[readObjRingNextRead];
	++readObjRingNextRead;
	readObjRingNextRead &= 7;

	send_obj_value(objno);
	gira_send_ack();
}


/**
 * Ein Byte über die Serielle vom Rauchmelder empfangen. Das Verarbeiten der
 * Nachricht auslösen wenn die empfangene Nachricht komplett ist.
 */
void gira_receive()
{
	char idx;

	unsigned char ch = SBUF;
	RI = 0;

	// Bei Überlauf die Antwort verwerfen
	if (giraAnswerCount >= GIRA_ANSWER_MAX)
	{
		giraAnswerCount = -1;
		gira_send_ack();
		gira_send_ack();
		return;
	}

	// Am Anfang auf das Start Byte warten, das Start Byte aber ignorieren
	if (giraAnswerCount < 0)
	{
		if (ch == GIRA_START_BYTE)
			++giraAnswerCount;
		return;
	}

	// Am Ende den Empfang bestätigen und die erhaltene Antwort verarbeiten
	if (ch == GIRA_STOP_BYTE)
	{
		gira_send_ack();
		gira_process_answer();
		return;
	}

	// Die empfangenen Zeichen sind ein Hex String.
	// D.h. jeweils zwei Zeichen ergeben ein Byte.
	// In giraAnswer gleich die dekodierten Bytes schreiben.
	//
	// Dieser Algorythmus ist fehlerhaft falls die Anzahl der empfangenen
	// Zeichen ungerade ist.

	if (ch >= '0' && ch <= '9')
		ch -= '0';
	else if (ch >= 'A' && ch <= 'F')
		ch -= 'A' - 10;
	else return; // Ungültige Zeichen ignorieren

	idx = giraAnswerCount >> 1;

	if (giraAnswerCount & 1)
		giraAnswer[idx] = (giraAnswer[idx] << 4) | ch;
	else giraAnswer[idx] = ch;

	++giraAnswerCount;
}


/**
 * Befehle aus dem Ringpuffer an den Rauchmelder senden und Antworten
 * vom Rauchmelder weiter verarbeiten.
 */
void process_commands()
{
	// Ein Byte von der Seriellen empfangen, Antwort verarbeiten wenn vollständig
	if (RI) gira_receive();

	// Den nächsten Befehl aus dem Ringpuffer senden
	if (readObjRingNextWrite != readObjRingNextRead)
	{
		unsigned char objno = readObjRing[readObjRingNextRead];
		unsigned char cmd = objMappingTab[objno].cmd;

		if (cmd < GIRA_CMD_COUNT)
			gira_send_bytes(giraCmdTab[cmd]);
		else send_obj_value(objno);
	}
}

/**
 * Timer Event.
 *
 * Wird alle 0,5 Sekunden aufgerufen.
 */
void timer_event()
{
	RTCCON=0x60;		// RTC anhalten und Flag löschen
	RTCH=0x70;			// Reload Real Time Clock (0,5s = 0x7080)
	RTCL=0x80;

	timer++;

	if (timer & 1) /*bei ganzer Sekunde*/
	{
		// Initialen Remote Alarm nach Ablauf der Wartezeit auf Remote Alarm umschalten
		if ((alarmType & ALARM_REMOTE_INIT) && remoteFullAlarmTime == timer)
		{
			alarmType &= ~ALARM_REMOTE_INIT;
			alarmType |= ALARM_REMOTE;
		}
	}

	// TODO  zirkulär die Com Objekte senden
	// TODO  Alarm Pins behandeln

	RTCCON=0x61;		// RTC starten
}


/**
 * Serielle Kommunikation initialisieren
 */
void rs_init()
{
	unsigned int brg = 0x02F0; // 9600 Baud

	BRGCON&=0xFE;	// Baudrate generator stop

	P1M1&=0xFC;		// Set RX and TX bidirectional
	P1M2&=0xFC;
	SCON=0x51;		// Mode 1, receive enable
	SSTAT|=0xE0;	// TI at end of stopbit, Interrupt only at RX and double TX buffer on
//	SSTAT|=0x60;	// TI at end of stopbit, Interrupt only at RX and double TX buffer off
	BRGCON|=0x02;	// Use Baudrate generator but yet stopped
	BRGR1=brg>>8;	// Baudrate = cclk / ((BRGR1,BRGR0) + 16)
	BRGR0=brg;

	BRGCON|=0x01;	// Baudrate generator start
	TI=1;
}


/**
 * Alle Applikations-Parameter zurücksetzen
 */
void restart_app()
{
	P0M1 = 0x03;// P0.0 and P0.1 open drain. all other pins of P0 as bidirectional
	P0M2 = 0x03;
	P0 = ~0x04;	// P0.2 low to enable serial gira communication. all other pins of p0 high

	P1M1 |= (1 << 2);		// P1.2 to GIRA open drain with external pullup
	P1M2 |= (1 << 2);
	P1 |= (1 << 2);		// P1.2 high

	rs_init();

	RTCH = 0x70;	// reload Real Time Clock (0,5s=0x7080)
	RTCL = 0x80;	// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
	RTCCON = 0x61;	// ... und starten

	giraAnswerCount = -1;
	readObjRingNextRead = 0;
	readObjRingNextWrite = 0;
	alarmType = 0;

#if 0
	g_timer = 0;
	if (eeprom[CONF_A_ZYKLISCH])
		g_timer_alarm = g_timer + 2;
	if (eeprom[CONF_S_ZYKLISCH])
		g_timer_test = g_timer + 4;
	if (eeprom[CONF_INFO_ZYKLISCH])
		g_timer_info = g_timer + 6;
#endif

	// EEPROM initialisieren
	EA = 0;							// Interrupts sperren, damit Flashen nicht unterbrochen wird
	START_WRITECYCLE;
	WRITE_BYTE(0x01, 0x03, 0x00);	// Herstellercode 0x004C = Bosch
	WRITE_BYTE(0x01, 0x04, 0x4C);
	WRITE_BYTE(0x01, 0x05, 0x03);	// Devicetype 0x03F2
	WRITE_BYTE(0x01, 0x06, 0xF2);
	WRITE_BYTE(0x01, 0x07, 0x01);	// Version der Applikation
	WRITE_BYTE(0x01, 0x0C, 0x00);	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01, 0x0D, 0xFF);	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01, 0x12, 0xA0);	// COMMSTAB Pointer
	STOP_WRITECYCLE;
	EA = 1;							// Interrupts freigeben

	// init reload value and prescaler
	// select Watchdog clock at 400kHz
	// start watchdog
	WDL = 0xFF;
	//  eacopy = EA;
	EA = 0;
	WDCON = 0xE5;
	WFEED1 = 0xA5;
	WFEED2 = 0x5A;
	//  EA = eacopy;
	EA = 1;

	gira_send_ack();
	gira_send_ack();
}
