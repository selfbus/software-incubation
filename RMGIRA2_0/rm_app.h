/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2012 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
#ifndef FB_APP_GIRA
#define FB_APP_GIRA

// Gira defines
#define GIRA_SIZE_REQ		6
#define GIRA_COUNT_REQ		6
#define GIRA_SIZE_RES		16
#define GIRA_START_BIT 		0x02
#define GIRA_STOP_BIT  		0x03
#define GIRA_ACK		 	0x06
#undef  SEND_FFFFFFFF_ON_GIRA_COM_ERROR

// KNX config defines
#define CONF_A_ZYKLISCH 	250//0xF4
#define CONF_A_FAKTOR		250//0xF5
#define CONF_A_BASIS		251//0xF6
#define CONF_S_ZYKLISCH 	246//0xF7
#define CONF_S_FAKTOR		246//0xF8
#define CONF_S_BASIS		247//0xF9
#define CONF_A_DELAY		248//0xFA
#define CONF_A_DELAY_FAKTOR	248//0xFB
#define CONF_A_DELAY_BASIS	249//0xFC
#define CONF_INFO_ZYKLISCH	244//0xFD
#define CONF_INFO_FAKTOR	244//0xFE
#define CONF_INFO_BASIS		245//0xFE
#define CONF_INFO_4TO10		252//0xFE
#define CONF_INFO_11TO17	253//0xFE

// KNX object defines
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

// Global extern Variables
extern volatile unsigned char	g_objno;					// object to process data and send to knx

// Prototypes
void rs_init(unsigned int);									// init serial communication
void rs_send_c(unsigned char);								// send simple char - only for testing
void rs_send_gira(unsigned char*);							// send data to Gira
void rs_read_gira (unsigned char*);							// receive data from Gira

void write_value_req(void);									// process write telegram from knx
void read_value_req(void);									// process read  telegram from knx
unsigned long read_obj_value(unsigned char);				// set value to send to knx

void state_machine(unsigned char);							// Main state machine
unsigned char calculate(unsigned char*, unsigned char*);	// Convert ASCII Hex -> Raw Hex
void set_gira_stat (unsigned char*);						// Set/Reset alarm to Gira
void check_gira_stat(void);									// Read alarm from Gira
void conv_dpt_9_001 (unsigned long*);						// Generate 2 byte DPT 9.001


void delay_timer(void);										// Called every 0.5 seconds

void restart_app(void);										// init stuff

#endif
