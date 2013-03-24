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
#include "rmgira_eeprom.h"

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


// Flag für lokalen Alarm und Wired Alarm (über grüne Klemme / Rauchmelderbus)
__bit alarmLocal;

// Flag für remote Alarm über EIB
__bit alarmBus;

// Flag für remote Alarm über LPC Alarm Pin auf JP2
__bit alarmExtra;

// Flag für lokalen Testalarm und Wired Testalarm
__bit testAlarmLocal;

// Flag für remote Testalarm über EIB
__bit testAlarmBus;

// Flag für den gewünschten Alarm Status wie wir ihn über den EIB empfangen haben
__bit setAlarmBus;

// Flag für den gewünschten Testalarm Status wie wir ihn über den EIB empfangen haben
__bit setTestAlarmBus;


// Zeit bis der remote Alarm als Alarm und nicht als Testalarm gemeldet wird
unsigned char remoteAlarmWait;


// Flags für Com-Objekte lesen
unsigned char objReadReqFlags[NUM_OBJ_FLAG_BYTES];

// Flags für Com-Objekte senden
unsigned char objSendReqFlags[NUM_OBJ_FLAG_BYTES];

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

// Initialwert für answerWait in 0,5s
#define INITIAL_ANSWER_WAIT 6


// Zähler für Alarm am JP2 - EXTRA_ALARM_PIN
unsigned char extraAlarmCounter;

// Schwelle für extraAlarmCounter in 0,5s
#define EXTRA_ALARM_LIMIT 5


// Countdown Zähler für zyklisches Senden eines Alarms oder Testalarms.
unsigned char alarmCounter;

// Countdown Zähler für zyklisches Senden des Alarm Zustands.
unsigned char alarmStatusCounter;

// Countdown Zähler für verzögertes Senden eines Alarms
unsigned char delayedAlarmCounter;

// Countdown Zähler für zyklisches Senden der (Info) Com-Objekte
unsigned char infoCounter;

// Nummer des Com-Objekts das bei zyklischem Info Senden als nächstes geprüft/gesendet wird
unsigned char infoSendObjno;

// Halbsekunden Zähler 0..119
unsigned char halfSeconds;


// Tabelle für 1<<x, d.h. pow2[3] == 1<<3
const unsigned char pow2[] = { 1, 2, 4, 8, 16, 32, 64, 128 };

// Im Byte Array arr das bitno-te Bit setzen
#define ARRAY_SET_BIT(arr, bitno) arr[bitno>>3] |= pow2[bitno & 7]

// Im Byte Array arr das bitno-te Bit löschen
#define ARRAY_CLEAR_BIT(arr, bitno) arr[bitno>>3] &= ~pow2[bitno & 7]

// Testen ob im Byte Array arr das bitno-te Bit gesetzt ist
#define ARRAY_IS_BIT_SET(arr, bitno) (arr[bitno>>3] & pow2[bitno & 7])


// Verwendet um Response Telegramme zu kennzeichnen.
#define OBJ_RESPONSE_FLAG 0x40


/**
 * Den Alarm Status auf den Bus senden falls noch nicht gesendet.
 *
 * @param newAlarm - neuer Alarm Status
 */
void send_obj_alarm(__bit newAlarm)
{
	__bit alarm = alarmLocal | alarmExtra;
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
	__bit alarm = testAlarmLocal;
	if (alarm != newAlarm)
		send_obj_value(OBJ_STAT_TALARM);
}


/**
 * Alarm-Status von JP2 Alarm-Pin setzen.
 */
void set_extra_alarm(__bit newAlarm)
{
	if (alarmExtra == newAlarm)
		return;

	alarmExtra = newAlarm;
	send_obj_value(OBJ_STAT_ALARM);
}


/**
 * Die empfangene Nachricht vom Rauchmelder verarbeiten.
 * Wird von gira_receive() aufgerufen.
 */
void gira_process_msg(unsigned char* bytes, unsigned char len)
{
	unsigned char objno, cmd, msgType;
	unsigned char byteno, mask;

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
			objValueCurrent = objValues[cmd];
			cmdCurrent = cmd;
			objValues[cmd] = *(unsigned long*)(bytes + 1);
			cmdCurrent = GIRA_CMD_NONE;

			// Versand der erhaltenen Com-Objekte einleiten. Dazu alle Com-Objekte suchen
			// auf die die empfangenen Daten passen und diese senden. Sofern sie für
			// den Versand vorgemerkt sind.
			for (objno = 0; objno < NUM_OBJS; ++objno, mask <<= 1)
			{
				byteno = objno >> 3;
				mask = pow2[objno & 7];

				if (objReadReqFlags[byteno] & mask)
				{
					send_obj_value(objno | OBJ_RESPONSE_FLAG);
					objReadReqFlags[byteno] &= ~mask;
				}
				if (objSendReqFlags[byteno] & mask)
				{
					send_obj_value(objno);
					objSendReqFlags[byteno] &= ~mask;
				}
			}
		}
	}
	else if (msgType == 0x82 && len >= 5) // Status Meldung
	{
		unsigned char subType = bytes[1];
		__bit newAlarm;

		if (subType & 0x20)   // (Alarm) Status
		{
			unsigned char status = bytes[2];

			// Lokaler Alarm: Rauch Alarm | Temperatur Alarm | Wired Alarm
			newAlarm = (subType & 0x10) | (status & (0x04 | 0x08));
			send_obj_alarm(newAlarm);
			alarmLocal = newAlarm;

			// Lokaler Testalarm: (lokaler) Testalarm || Wired Testalarm
			newAlarm = status & (0x20 | 0x40);
			send_obj_test_alarm(newAlarm);
			testAlarmLocal = newAlarm;

			// Bus Alarm
			alarmBus = status & 0x10;

			// Bus Testalarm
			testAlarmBus = status & 0x80;

			// TODO Batterie schwach
			// status & 0x01
		}

		if (subType & 0x08)  // Taste am Rauchmelder gedrückt
		{
			if (setAlarmBus)
			{
				setAlarmBus = 0;
				send_obj_value(OBJ_STAT_ALARM);
			}

			if (setTestAlarmBus)
			{
				setTestAlarmBus = 0;
				send_obj_value(OBJ_STAT_TALARM);
			}
		}

//		if (subType & 0x02)  // Defekt am Rauchmelder
//		{
//			unsigned char status = bytes[4];
//
//			// TODO Defekt melden
//		}
	}
}


/**
 * Empfangenes read_value_request Telegramm verarbeiten.
 */
void read_value_req()
{
	unsigned char objno; //, objflags;

	objno = find_first_objno(telegramm[3], telegramm[4]);

	// TODO Nur antworten wenn READ und COM Flag gesetzt sind
//	objflags = read_objflags(objno);
//	if ((objflags&0x0C) == 0x0C)
		ARRAY_SET_BIT(objReadReqFlags, objno);
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
			return alarmLocal | alarmExtra;

		case OBJ_STAT_TALARM:
		case OBJ_STAT_TALARM_CENTRAL:
			return testAlarmLocal;
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

 		// Wenn wir lokalen Alarm haben dann Bus Alarm wieder auslösen
		// damit der Status der anderen Rauchmelder stimmt
 		if (!setAlarmBus && alarmLocal)
 			send_obj_value(OBJ_STAT_ALARM);
	}
	else if (objno == OBJ_SET_TALARM) // Bus Test Alarm
	{
		setTestAlarmBus = telegramm[7] & 0x01;

 		// Wenn wir lokalen Testalarm haben dann Bus Testalarm wieder auslösen
		// damit der Status der anderen Rauchmelder stimmt
 		if (!setTestAlarmBus && testAlarmLocal)
 			send_obj_value(OBJ_STAT_TALARM);
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

	if (cmd == GIRA_CMD_NONE || cmd == GIRA_CMD_INTERNAL)
	{
		// Der Wert des Com-Objekts ist bekannt, also sofort senden

		unsigned char byteno = objno >> 3;
		unsigned char mask = pow2[objno & 7];

		if (objReadReqFlags[byteno] & mask)
		{
			send_obj_value(objno | OBJ_RESPONSE_FLAG);
			objReadReqFlags[byteno] &= ~mask;
		}
		if (objSendReqFlags[byteno] & mask)
		{
			send_obj_value(objno);
			objSendReqFlags[byteno] &= ~mask;
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
	unsigned char mask, byteno, objno;

	// Nichts tun wenn gerade auf eine Antwort vom Rauchmelder gewartet wird
	if (answerWait > 0)
		return;

	for (objno = 0; objno < NUM_OBJS; ++objno)
	{
		byteno = objno >> 3;
		mask = pow2[objno & 7];

		if ((objReadReqFlags[byteno] & mask) || (objSendReqFlags[byteno] & mask))
		{
			process_obj(objno);
			break;
		}
	}
}


/**
 * Den Zustand der Alarme bearbeiten. Wenn wir der Meinung sind der Bus-Alarm soll einen
 * bestimmten Zustand haben dann wird das dem Rauchmelder so lange gesagt bis der auch
 * der gleichen Meinung ist.
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
	RTCH = 0x70;    // RTC neu laden (1s = 0xE100; 0,5s = 0x7080; 0,25s = 0x3840)
	RTCL = 0x80;
	RTCCON = 0x61;  // RTC starten

	--halfSeconds;

	if (answerWait)
		--answerWait;

	// Alarm über JP2 behandeln
	if (!EXTRA_ALARM_PIN)
	{
		if (extraAlarmCounter < EXTRA_ALARM_LIMIT)
		{
			++extraAlarmCounter;
		}
		else
		{
			send_obj_alarm(1);
			alarmExtra = 1;
		}
	}
	else if (extraAlarmCounter)
	{
		// Wenn Alarm, dann nach x Zyklen beenden wenn der Pin nicht mehr Low ist
		--extraAlarmCounter;
		if (!extraAlarmCounter)
		{
			send_obj_alarm(0);
			alarmExtra = 0;
		}
	}

	// Alles danach wird nur jede Sekunde gemacht
	if (halfSeconds & 1)
		return;

	// Alarm: verzögert und zyklisch senden
	if (alarmLocal | alarmExtra)
	{
		// Alarm verzögert senden
		if (delayedAlarmCounter)
		{
			--delayedAlarmCounter;
			if (!delayedAlarmCounter)
			{
				send_obj_alarm(1); // FIXME
			}
		}
		else // Alarm zyklisch senden
		{
			unsigned char conf = eeprom[CONF_A_ZYKLISCH];
			if (conf & 0x80)
			{
				--alarmCounter;
				if (!alarmCounter)
				{
					alarmCounter = conf & 0x7f;
					// TODO
				}
			}
		}
	}

	// Testalarm: zyklisch senden
	if (testAlarmLocal)
	{
		unsigned char conf = eeprom[CONF_S_ZYKLISCH];
		if (conf & 0x80)
		{
			--alarmCounter;
			if (!alarmCounter)
			{
				alarmCounter = conf & 0x7f;
				// TODO
			}
		}
	}

	// Jede Sekunde ein Status Com-Objekt senden.
	// Aber nur senden wenn kein Alarm anliegt.
	if (infoSendObjno &&
	    !(alarmLocal | alarmBus | alarmExtra | testAlarmLocal | testAlarmBus))
	{
		// Info Objekt zum Senden vormerken wenn es dafür konfiguriert ist.
		if ((infoSendObjno >= 11 && (eeprom[CONF_INFO_11TO17] & pow2[infoSendObjno - 11])) ||
			(infoSendObjno >= 4 && (eeprom[CONF_INFO_4TO10] & pow2[infoSendObjno - 4])))
		{
			ARRAY_SET_BIT(objSendReqFlags, infoSendObjno);
		}

		--infoSendObjno;
	}

	if (!halfSeconds) // einmal pro Minute
	{
		halfSeconds = 120;

		// Status Informationen zyklisch senden
		if (eeprom[CONF_INFO_ZYKLISCH] & 0x80)
		{
			--infoCounter;
			if (!infoCounter)
			{
				infoCounter = eeprom[CONF_INFO_ZYKLISCH] & 0x7f;
				infoSendObjno = OBJ_HIGH_INFO_SEND;
			}
		}
	}
}


/**
 * Alle Applikations-Parameter zurücksetzen
 */
void restart_app()
{
	unsigned char i;

	P0M1 = 0x03;   // P0.0 and P0.1 open drain. all other pins of P0 as bidirectional
	P0M2 = 0x03;
	P0 = ~0x04;	   // P0.2 low to enable serial communication. all other pins of p0 high

	P1M1 |= (1 << 2); // P1.2 to Rauchmelder open drain with external pullup
	P1M2 |= (1 << 2);
	P1 |= (1 << 2);	  // P1.2 high

	gira_init();

	RTCH = 0x70;	// Reload Real Time Clock (1s = 0xE100; 0,5s = 0x7080; 0,25s = 0x3840)
	RTCL = 0x80;	// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
	RTCCON = 0x61;	// ... und starten

	// Werte initialisieren

	for (i = 0; i < NUM_OBJ_FLAG_BYTES; ++i)
	{
		objReadReqFlags[i] = 0;
		objSendReqFlags[i] = 0;
	}

	answerWait = 0;
	cmdCurrent = GIRA_CMD_NONE;
	remoteAlarmWait = 0;
	recvCount = -1;
	halfSeconds = eeprom[ADDRTAB + 2] & 127;

	alarmBus = 0;
	alarmLocal = 0;
	alarmExtra = 0;

	testAlarmBus = 0;
	testAlarmLocal = 0;

	setAlarmBus = 0;
	setTestAlarmBus = 0;

	infoSendObjno = 0;
	infoCounter = 1;
	alarmCounter = 1;
	alarmStatusCounter = 1;
	delayedAlarmCounter = 0;
	extraAlarmCounter = 0;

	// EEPROM initialisieren

	EA = 0;							// Interrupts sperren, damit Flashen nicht unterbrochen wird
	START_WRITECYCLE;
	WRITE_BYTE(0x01, 0x03, 0x00);	// Herstellercode 0x004C = Bosch
	WRITE_BYTE(0x01, 0x04, 0x4C);
	WRITE_BYTE(0x01, 0x05, 0x03);	// Devicetype 1010 (0x03F2)
	WRITE_BYTE(0x01, 0x06, 0xF2);
	WRITE_BYTE(0x01, 0x07, 0x01);	// Version der Applikation: 1
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

	// TODO Alarm-Status vom Rauchmelder abfragen
}
