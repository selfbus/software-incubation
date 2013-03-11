/*
 *  Copyright (c) 2013 Stefan Taferner <stefan.taferner@gmx.at>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */

#include "rmgira_app.h"
#include "rmgira_const.h"
#include "rmgira_com.h"
#include "rmgira_conv.h"

#include <mcs51/P89LPC922.h>
#include <fb_lpc922.h>


// Befehle an den Rauchmelder
const unsigned char giraCmdTab[GIRA_CMD_COUNT] =
{
	0x04,   // GIRA_CMD_SERIAL
	0x09,   // GIRA_CMD_OPERATING_TIME
	0x0B,   // GIRA_CMD_SMOKEBOX
	0x0C,   // GIRA_CMD_BATTEMP
	0x0D,   // GIRA_CMD_NUM_ALARMS
	0x0E	// GIRA_CMD_NUM_TEST_ALARMS
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

// Flag für remote Alarm über grüne Klemme / Rauchmelderbus
__bit alarmWired;

// Flag für remote Alarm über EIB
__bit alarmBus;

// Flag für lokalen Testalarm
__bit testAlarmLocal;

// Flag für remote Testalarm über grüne Klemme / Rauchmelderbus
__bit testAlarmWired;

// Flag für remote Testalarm über EIB
__bit testAlarmBus;

// Flag für den gewünschten Alarm Status wie wir ihn über den EIB empfangen haben
__bit setAlarmBus;

// Flag für den gewünschten Testalarm Status wie wir ihn über den EIB empfangen haben
__bit setTestAlarmBus;


// Zeit bis der remote Alarm als Alarm und nicht als Testalarm gemeldet wird
unsigned char remoteAlarmWait;


// Flags für Com-Objekte lesen
unsigned long objReadReqFlags;

// Flags für Com-Objekte senden
unsigned long objSendReqFlags;

// Mask für objReadReqFlags bzw objSendReqFlags aus einer Com-Objekt Nummer berechnen
#define OBJ_FLAG_MASK(objno) (1L << (objno))


// Werte der Com-Objekte. Index ist die der GIRA_CMD
unsigned long objValues[GIRA_CMD_COUNT];


// Nummer des Befehls an den Rauchmelder der gerade ausgeführt wird.
// GIRA_CMD_NONE wenn keiner.  So lange ein GIRA_CMD ausgeführt wird darf auf
// objValues[cmdCurrent] nicht zugegriffen werden. Es muss stattdessen objOldValue
// verwendet werden.
unsigned char cmdCurrent;

// Backup des Com-Objekt Wertebereichs der gerade von cmdCurrent neu vom
// Rauchmelder geholt wird.
__idata unsigned long objValueCurrent;


// Zähler für die Zeit die auf eine Antwort vom Rauchmelder gewartet wird.
// Ist der Zähler 0 dann wird gerade auf keine Antwort gewartet.
unsigned char answerWait;

// Initialwert für answerWait
#define INITIAL_ANSWER_WAIT 6


// Verwendet um Response Telegramme zu kennzeichnen.
#define OBJ_RESPONSE_FLAG 0x40


/**
 * Den Alarm Status auf den Bus senden falls noch nicht gesendet.
 *
 * @param newAlarm - neuer Alarm Status
 */
void send_obj_alarm(__bit newAlarm)
{
	__bit alarm = alarmLocal | alarmWired;
	if (alarm != newAlarm)
		send_obj_value(OBJ_STAT_ALARM);
}


/**
 * Den Testalarm Status auf den Bus senden falls noch nicht gesendet.
 *
 * @param newAlarm - neuer Testalarm Status
 */
void send_obj_test_alarm(__bit newAlarm)
{
	__bit alarm = testAlarmLocal | testAlarmWired;
	if (alarm != newAlarm)
		send_obj_value(OBJ_STAT_TALARM);
}


/**
 * Die empfangene Nachricht vom Rauchmelder verarbeiten.
 * Wird von gira_receive() aufgerufen.
 */
void gira_process_msg(unsigned char* bytes, unsigned char len)
{
	unsigned char objno, cmd, msgType;
	unsigned long mask;

	msgType = bytes[0];
	if ((msgType & 0xf0) == 0xc0) // Com-Objekt Werte empfangen
	{
		answerWait = 0;
		msgType &= 0x0f;

		for (cmd = 0; cmd < GIRA_CMD_COUNT; ++cmd)
		{
			if (giraCmdTab[cmd] == msgType)
				break;
		}

		if (cmd < GIRA_CMD_COUNT)
		{
			cmdCurrent = cmd;
			objValueCurrent = objValues[cmd];
			cmdCurrent = GIRA_CMD_NONE;

			// Versand der erhaltenen Com-Objekte einleiten. Dazu alle Com-Objekte suchen
			// auf die die empfangenen Daten passen und diese senden. Sofern sie für
			// den Versand vorgemerkt sind.
			for (objno = 0, mask = 1; objno < NUM_OBJS; ++objno, mask <<= 1)
			{
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
		}
	}
	else if (msgType == 0x82 && len >= 5) // Alarm Status
	{
		if ((bytes[1] & 0xf0) == 0x20)
		{
			if (bytes[2] == 0x00)  // Alarm und Testalarm beendet
			{
				send_obj_alarm(0);
				send_obj_test_alarm(0);

				alarmBus = 0;
				alarmLocal = 0;
				alarmWired = 0;

				testAlarmBus = 0;
				testAlarmLocal = 0;
				testAlarmWired = 0;
			}
			// TODO Lokaler Temperatur- bzw Rauch-Alarm

			else if (bytes[2] == 0x20) // Lokaler Testalarm
			{
				send_obj_test_alarm(1);
				testAlarmLocal = 1;
			}
			else if (bytes[2] == 0x08) // Wired Alarm
			{
				send_obj_alarm(1);
				alarmWired = 1;
			}
			// TODO Wired Testalarm

			else if (bytes[2] == 0x10) // Bus Alarm
			{
				alarmBus = 1;
			}
			else if (bytes[2] == 0x80) // Bus Testalarm
			{
				testAlarmBus = 1;
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
		case OBJ_STAT_ALARM:
		case OBJ_STAT_ALARM_CENTRAL:
		case OBJ_STAT_ALARM_DELAYED:
			return alarmLocal | alarmWired;

		case OBJ_STAT_TALARM:
		case OBJ_STAT_TALARM_CENTRAL:
			return testAlarmLocal | testAlarmWired;
		}
	}
	// Com-Objekte verarbeiten die Werte vom Rauchmelder darstellen
	else if (cmd != GIRA_CMD_NONE)
	{
		unsigned long result = 0;
		unsigned char* answer;

		if (cmd == cmdCurrent) answer = (unsigned char*) &objValueCurrent;
		else answer = (unsigned char*) &objValues[cmd];
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
 	if (objno == OBJ_SET_ALARM) // Bus Alarm
	{
 		setAlarmBus = telegramm[7] & 0x01;
	}
	else if (objno == OBJ_SET_TALARM) // Bus Test Alarm
	{
		setTestAlarmBus = telegramm[7] & 0x01;
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
		// Den Wert des Com-Objekts vom Rauchmelder anfordern. Der Versand erfolgt
		// wenn die Antwort vom Rauchmelder erhalten wurde, in gira_process_msg().
		if (recvCount < 0)
		{
			gira_send_cmd(giraCmdTab[cmd]);
			answerWait = INITIAL_ANSWER_WAIT;
		}
	}
}


/**
 * Com-Objekte bearbeiten.
 */
void process_objs()
{
	unsigned long mask;
	unsigned char objno;

	// Nichts tun wenn gerade auf eine Antwort vom Rauchmelder gewartet wird
	if (answerWait > 0)
		return;

	// Gibt es zu bearbeitende Com-Objekte?
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
 * Den Zustand der Alarme bearbeiten.
 */
void process_alarm_stats()
{
	if (setAlarmBus && !alarmBus)
	{
		// Alarm auslösen
		gira_send_hexstr("030210");
		answerWait = INITIAL_ANSWER_WAIT;
	}
	else if (setTestAlarmBus && !testAlarmBus)
	{
		// Testalarm auslösen
		gira_send_hexstr("030280");
		answerWait = INITIAL_ANSWER_WAIT;
	}
	else if ((!setAlarmBus && alarmBus) || (!setTestAlarmBus && testAlarmBus))
	{
		// Alarm und Testalarm beenden
		gira_send_hexstr("030200");
		answerWait = INITIAL_ANSWER_WAIT;
	}
}


/**
 * Timer Event.
 */
void timer_event()
{
	RTCCON = 0x60;  // RTC anhalten und Flag löschen
	RTCH = 0x70;    // RTC neu laden (0,5s = 0x7080)
	RTCL = 0x80;

	if (answerWait)
		--answerWait;

	// TODO zyklisches Senden der Com-Objekte bzw Alarme

	RTCCON = 0x61;  // RTC starten
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

	gira_init();

	RTCH = 0x70;	// Reload Real Time Clock (0,5s = 0x7080)
	RTCL = 0x80;	// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
	RTCCON = 0x61;	// ... und starten

	// Werte initialisieren

	objReadReqFlags = 0;
	objSendReqFlags = 0;
	answerWait = 0;
	cmdCurrent = GIRA_CMD_NONE;
	remoteAlarmWait = 0;

	alarmBus = 0;
	alarmLocal = 0;
	alarmWired = 0;

	testAlarmBus = 0;
	testAlarmLocal = 0;
	testAlarmWired = 0;

	setAlarmBus = 0;
	setTestAlarmBus = 0;

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

	gira_send_byte(ACK);
	gira_send_byte(ACK);
}
