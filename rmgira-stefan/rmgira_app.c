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

// Damit die Eclipse Code Analyse nicht so viele Warnungen anzeigt:
#ifndef SDCC
# define __idata
#endif


// Anzahl der bekannten Befehle an den Rauchmelder
#define GIRA_CMD_SIZE 6

// Anzahl der Daten Bytes der Antworten des Rauchmelders
#define GIRA_ANSWER_BYTES 4


// Befehle an den Rauchmelder
const unsigned char giraCmdTab[GIRA_CMD_COUNT][GIRA_CMD_SIZE] =
{
	{0x02, 0x30, 0x34, 0x36, 0x34, 0x03},   // GIRA_CMD_SERIAL
	{0x02, 0x30, 0x39, 0x36, 0x39, 0x03},   // GIRA_CMD_OPERATING_TIME
	{0x02, 0x30, 0x42, 0x37, 0x32, 0x03},   // GIRA_CMD_SMOKEBOX
	{0x02, 0x30, 0x43, 0x37, 0x33, 0x03},   // GIRA_CMD_BATTEMP
	{0x02, 0x30, 0x44, 0x37, 0x34, 0x03},   // GIRA_CMD_NUM_ALARMS
	{0x02, 0x30, 0x45, 0x37, 0x35, 0x03}	// GIRA_CMD_NUM_TEST_ALARMS
};


// Mapping von den Kommunikations-Objekten auf die Rauchmelder Requests
// und die Daten in der Rauchmelder Antwort. Der Index in die Tabelle ist
// die ID vom Kommunikations-Objekt (objid).
const struct
{
	unsigned const char cmd;       // Zu sendender GIRA_CMD Befehl
	unsigned const char offset;    // Byte-Offset in der Antwort
	unsigned const char dataType;  // Datentyp der Antwort
} objMappingTab[NUM_OBJS] =
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
	/*OBJ_CNT_TALARM_WIRE*/     { GIRA_CMD_NUM_ALARMS_2,    0, GIRA_TYPE_BYTE },
	/*OBJ_CNT_TALARM_WIRELESS*/ { GIRA_CMD_NUM_ALARMS_2,    1, GIRA_TYPE_BYTE },
	/*OBJ_STAT_ALARM*/          { GIRA_CMD_INTERNAL,        0, GIRA_TYPE_NONE },
	/*OBJ_STAT_ALARM_CENTRAL*/  { GIRA_CMD_INTERNAL,        0, GIRA_TYPE_NONE },
	/*OBJ_STAT_ALARM_DELAYED*/  { GIRA_CMD_INTERNAL,        0, GIRA_TYPE_NONE },
	/*OBJ_STAT_TALARM*/         { GIRA_CMD_INTERNAL,        0, GIRA_TYPE_NONE },
	/*OBJ_STAT_TALARM_CENTRAL*/ { GIRA_CMD_INTERNAL,        0, GIRA_TYPE_NONE }
};


// Flag für lokalen Alarm
__bit alarmLocal;

// Flag für remote Alarm
__bit alarmRemote;

// Flag für lokalen Testalarm
__bit testAlarmLocal;

// Flag für remote Testalarm
__bit testAlarmRemote;

// Zeit bis der remote Testalarm zu einem remote Alarm wird
unsigned char remoteAlarmWait;


// Flags für Com-Objekte lesen
unsigned long objReadReqFlags;

// Flags für Com-Objekte senden
unsigned long objSendReqFlags;

// Mask für objReadReqFlags bzw objSendReqFlags aus einer Com-Objekt Nummer berechnen
#define OBJ_FLAG_MASK(objno) (1L << (objno))


// Werte der Com-Objekte. Erster Index ist die der GIRA_CMD, zweiter Index sind die Daten.
unsigned char objValues[GIRA_CMD_COUNT][GIRA_ANSWER_BYTES];


// Nummer des Befehls an den Rauchmelder der gerade ausgeführt wird.
// GIRA_CMD_NONE wenn keiner.  So lange ein GIRA_CMD ausgeführt wird darf auf
// objValues[cmdCurrent] nicht zugegriffen werden. Es muss stattdessen objOldValue
// verwendet werden.
unsigned char cmdCurrent;

// Backup des Com-Objekt Wertebereichs der gerade von cmdCurrent neu vom
// Rauchmelder geholt wird.
__idata unsigned char objValueCurrent[GIRA_ANSWER_BYTES];

// Zähler für die Antwort-Zeichen vom Rauchmelder
__idata char receiveCount;


// Nummer des Com-Objekts das gerade bearbeitet wird. OBJ_NONE wenn keines.
unsigned char objnoCurrent;

// Zähler für die Zeit die auf eine Antwort vom Rauchmelder gewartet wird.
// Ist der Zähler 0 dann wird gerade auf keine Antwort gewartet.
unsigned char answerWait;

// Initialwert für answerWait
#define INITIAL_ANSWER_WAIT 6


// Verwendet um Response Telegramme zu kennzeichnen.
#define OBJ_RESPONSE_FLAG 0x40


/**
 * Ein Acknowledge an den Rauchmelder senden.
 */
void gira_send_ack()
{
	while (!TI)
		;

 	TI = 0;
	SBUF = ACK;
}


/**
 * Einen Befehl an den Rauchmelder senden.
 *
 * @param cmd - der zu sendende GIRA_CMD Befehl
 */
void gira_send_cmd(unsigned char cmd)
{
	const unsigned char* cmdBytes = giraCmdTab[cmd];
	unsigned char idx;

	// Wenn der Rauchmelder gerade etwas sendet dann warten bis er fertig ist.
	// TODO

	// Alten Wert sichern, für den Fall dass während des Empfangens
	// jemand den Wert des Com-Objekts lesen will.
	for (idx = 0; idx < GIRA_ANSWER_BYTES; ++idx)
		objValueCurrent[idx] = objValues[cmd][idx];

	cmdCurrent = cmd;

	for (idx = 0; idx < GIRA_CMD_SIZE; ++idx)
	{
		while (!TI)
			;

		TI = 0;
		SBUF = cmdBytes[idx];
	}
}


/**
 * Die Antwort vom Rauchmelder verarbeiten.
 */
void gira_process_answer()
{
	unsigned long mask;

	// Der Empfang der Antwort ist fertig
	cmdCurrent = GIRA_CMD_NONE;

	// Versand des eigentlich angeforderten Com-Objekts einleiten
	mask = OBJ_FLAG_MASK(objnoCurrent);
	if (objReadReqFlags & mask)
	{
		send_obj_value(objnoCurrent | OBJ_RESPONSE_FLAG);
		objReadReqFlags &= ~mask;
	}
	if (objSendReqFlags & mask)
	{
		send_obj_value(objnoCurrent);
		objSendReqFlags &= ~mask;
	}

	// Fertig
	answerWait = 0;
	objnoCurrent = OBJ_NONE;
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

	// Am Anfang auf das Start Byte warten
	if (receiveCount < 0)
	{
		if (ch == STX)
			++receiveCount;
		return;
	}

	// Am Ende den Empfang bestätigen und die erhaltene Antwort verarbeiten
	if (ch == ETX)
	{
		gira_send_ack();
		gira_process_answer();
		return;
	}

	idx = receiveCount >> 1;

	// Bei Überlauf die restlichen Zeichen ignorieren, u.A. das Checksum-Byte
	if (idx >= GIRA_ANSWER_BYTES)
		return;

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

	if (receiveCount & 1)
	{
		objValues[cmdCurrent][idx] <<= 4;
		objValues[cmdCurrent][idx] |= ch;
	}
	else objValues[cmdCurrent][idx] = ch;

	++receiveCount;
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
 * Empfangenes read_value_request Telegramm verarbeiten.
 */
void read_value_req()
{
	unsigned char objno, objflags;

	objno = find_first_objno(telegramm[3], telegramm[4]);
	objflags = read_objflags(objno);

	// Wir antworten nur wenn READ und COM Flags
	if ((objflags&0x0C) == 0x0C)
		objReadReqFlags |= OBJ_FLAG_MASK(objno);
}


/**
 * Wert eines Com-Objekts liefern.
 *
 * @param objno - die ID des Kommunikations-Objekts
 * @return Den Wert des Kommunikations Objekts
 */
unsigned long read_obj_value(unsigned char objno)
{
	unsigned char cmd = objMappingTab[objno].cmd;

	// Interne Com-Objekte behandeln
	if (cmd == GIRA_CMD_INTERNAL)
	{
		switch (objno)
		{
		case OBJ_STAT_ALARM:          // TODO gehören die Fälle wirklich so zusammen?
		case OBJ_STAT_ALARM_CENTRAL:
		case OBJ_STAT_ALARM_DELAYED:
			return alarmLocal;

		case OBJ_STAT_TALARM:         // TODO gehören die Fälle wirklich so zusammen?
		case OBJ_STAT_TALARM_CENTRAL:
			return testAlarmLocal;
		}
	}
	// Com-Objekte verarbeiten die Werte vom Rauchmelder darstellen
	else if (cmd != GIRA_CMD_NONE)
	{
		unsigned long result = 0;
		unsigned char* answer;

		if (cmd == cmdCurrent) answer = objValueCurrent;
		else answer = objValues[cmd];
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

		default: // Fehler: unbekannter Datentyp
			return (unsigned long) -2;
		}
	}

	// Fehler: unbekanntes Com Objekt
	return (unsigned long) -1;
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
			testAlarmRemote = 1;
			remoteAlarmWait = 10;  // TODO über Parameter steuern
		}
		else alarmRemote = 0;
	}
	else if (objno == OBJ_SET_TALARM) // Remote Test Alarm
	{
		testAlarmRemote = telegramm[7] & 0x01;
		remoteAlarmWait = 0;
	}
}


/**
 * Empfangenes write_value_request Telegramm verarbeiten.
 * Ruft write_value_obj(objno) auf, das die eigentliche Arbeit macht.
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
 * Ein Com-Objekt bearbeiten.
 *
 * @param objno - die Nummer des zu bearbeitenden Com Objekts
 */
void process_obj(unsigned char objno)
{
	unsigned char cmd = objMappingTab[objno].cmd;

	if (cmd == GIRA_CMD_NONE)
	{
		// Der Wert des Com-Objekts ist bekannt, also sofort senden

		unsigned long mask = OBJ_FLAG_MASK(objno);

		if (objReadReqFlags & mask)
		{
			send_obj_value(objno | OBJ_RESPONSE_FLAG);
			objReadReqFlags &= ~mask;
		}
		if (objSendReqFlags & mask)
		{
			send_obj_value(objno);
			objSendReqFlags &= ~mask;
		}
	}
	else
	{
		// Den Wert des Com-Objekts vom Rauchmelder anfordern.
		// Der Versand erfolgt wenn die Antwort vom Rauchmelder
		// erhalten wurde, in gira_process_answer().

		objnoCurrent = objno;
		answerWait = INITIAL_ANSWER_WAIT;

		gira_send_cmd(cmd);
	}
}


/**
 * Com-Objekte bearbeiten.
 */
void process_objs()
{
	unsigned long mask;
	unsigned char objno;

	// Nichts tun wenn gerade ein Com-Objekt bearbeitet wird
	if (objnoCurrent != OBJ_NONE)
		return;

	// Gibts zu bearbeitende Com-Objekte?
	if (objReadReqFlags == 0 && objSendReqFlags == 0)
		return;

	for (objno = 0, mask = 1; objno < NUM_OBJS; ++objno, mask <<= 1)
	{
		if ((mask & objReadReqFlags) || (mask & objSendReqFlags))
		{
			process_obj(objno);
			break;
		}
	}
}


/**
 * Timer Event.
 */
void timer_event()
{
	RTCCON = 0x60;  // RTC anhalten und Flag löschen
	RTCH = 0x70;    // Reload Real Time Clock (0,5s = 0x7080)
	RTCL = 0x80;

	if (remoteAlarmWait)
	{
		--remoteAlarmWait;
		if (remoteAlarmWait == 0)
		{
			testAlarmRemote = 0;
			alarmRemote = 1;
		}
	}

	// TODO Alarm behandeln

	if (answerWait)
	{
		--answerWait;
		if (!answerWait)
		{
			// Timeout beim Warten auf Antwort vom Rauchmelder
			gira_send_ack();
			gira_send_ack();
			objnoCurrent = OBJ_NONE;
		}
	}

	RTCCON = 0x61;  // RTC starten
}


/**
 * Serielle Kommunikation mit dem Rauchmelder initialisieren
 */
void rs_init()
{
	unsigned int brg = 0x02F0; // 9600 Baud

	BRGCON&=0xFE;	// Baudrate generator stop

	P1M1&=0xFC;		// Set RX and TX bidirectional
	P1M2&=0xFC;
	SCON=0x51;		// Mode 1, receive enable
	SSTAT|=0xE0;	// TI at end of stopbit, Interrupt only at RX and double TX buffer on
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
	P0M1 = 0x03;   // P0.0 and P0.1 open drain. all other pins of P0 as bidirectional
	P0M2 = 0x03;
	P0 = ~0x04;	   // P0.2 low to enable serial gira communication. all other pins of p0 high

	P1M1 |= (1 << 2);   // P1.2 to GIRA open drain with external pullup
	P1M2 |= (1 << 2);
	P1 |= (1 << 2);		// P1.2 high

	rs_init();

	RTCH = 0x70;	// Reload Real Time Clock (0,5s = 0x7080)
	RTCL = 0x80;	// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
	RTCCON = 0x61;	// ... und starten

	// Werte initialisieren
	objReadReqFlags = 0;
	objSendReqFlags = 0;
	answerWait = 0;
	cmdCurrent = GIRA_CMD_NONE;
	objnoCurrent = OBJ_NONE;

	alarmLocal = 0;
	alarmRemote = 0;
	testAlarmLocal = 0;
	testAlarmRemote = 0;
	remoteAlarmWait = 0;

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
	EA = 0;
	WDCON = 0xE5;
	WFEED1 = 0xA5;
	WFEED2 = 0x5A;
	EA = 1;

	gira_send_ack();
	gira_send_ack();
}
