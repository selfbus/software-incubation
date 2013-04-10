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
 *
 */

/*
 * G_STATE
 * 0	Idle
 * 1	Send Data to GIRA
 * 2	Rec  Data from GIRA
 * 3 	Convert data
 * 4 	Calculate and set data
 * 5	Send data to KNX
 */

#include <P89LPC922.h>
#include "../lib_LPC922/fb_lpc922.h"
#include "rm_app.h"

// Requests for GIRA
const unsigned char __at (0x1BDA) req[GIRA_COUNT_REQ][GIRA_SIZE_REQ] =  { {0x02, 0x30, 0x34, 0x36, 0x34, 0x03},   // Seriennummer
																		  {0x02, 0x30, 0x39, 0x36, 0x39, 0x03},   // Betriebszeit
																		  {0x02, 0x30, 0x42, 0x37, 0x32, 0x03},   // Rauchkammerrelevante Daten
																		  {0x02, 0x30, 0x43, 0x37, 0x33, 0x03},   // Batteriespannung und Temperaturen
																		  {0x02, 0x30, 0x44, 0x37, 0x34, 0x03},   // Anzahl (Test)alarme
																		  {0x02, 0x30, 0x45, 0x37, 0x35, 0x03} }; // Anzahl Testalarme

volatile __bit 				g_set_alarm = 0, 				// set remote test alarm
							g_set_test = 0;					// set remote alarm

__bit 						g_stat_alarm = 0, 				// local alarm detected
							g_stat_alarm_delay = 0,			// send local alarm delayed telegram?
							g_stat_test = 0;				// local test alarm detected

volatile unsigned char		g_state     = 0,				// state of state machine
							g_objno     = 0;				// object to process data and send to knx

unsigned char 				g_res[GIRA_SIZE_RES],			// Received raw data from GIRA
							g_res_conv[GIRA_SIZE_RES/2],	// Received converted data from GIRA
							g_res_pointer = 0;				// Position of first free byte in g_res for raw reading from gira

unsigned int 				g_timer;						// Counting seconds
unsigned int __idata		g_timer_alarm, 					// Cycle sending alarm
							g_timer_test;					// Cycle sending testalarm
unsigned int __idata		g_timer_alarm_delay,			// Delay for sending alarm
							g_timer_info;					// Cycle sending all infos

volatile unsigned long 		g_to_knx = 0;					// Data send to knx



// ********************** Serial communication to gira *************************
void rs_init(unsigned int baudrate)
{
	unsigned int brg;

	switch (baudrate) {
	case 96:		// 9600 Baud
		brg=0x02F0;
		break;
	case 192:		// 19200 Baud
		brg=0x0170;
		break;
	case 384:		// 38400 Baud
		brg=0x00B0;
		break;
	case 576:		// 57600 Baud
		brg=0x0070;
		break;
	default:		// 115200 Baud is default
		brg=0x0030;
	}
	BRGCON&=0xFE;	// Baudrate generator stop
	P1M1&=0xFC;		// Set RX and TX bidirectional
	P1M2&=0xFC;
	SCON=0x51;		// Mode 1, receive enable
	SSTAT|=0xE0;	// TI at end of stopbit, Interrupt only at RX and double TX buffer on
//	SSTAT|=0x60;	// TI at end of stopbit, Interrupt only at RX and double TX buffer off
	BRGCON|=0x02;	// use Baudrate generator but yet stopped
	BRGR1=brg>>8;	// Baudrate = cclk/((BRGR1,BRGR0)+16)
	BRGR0=brg;
	BRGCON|=0x01;	// Baudrate generator start
	TI=1;
}

void rs_send_c(unsigned char z)
{
	while(!TI);
 	TI=0;
	SBUF=z;
}

void rs_send_gira(unsigned char* z)
{
	unsigned char n=0;
	if (g_state == 0x01)
	{
		g_state++;
		while (1)
		{
			while(!TI);
			TI=0;
			SBUF=z[n];
			if (z[n]==GIRA_STOP_BIT)
				return;
			n++;
			if(n>GIRA_SIZE_REQ)
				return;
		};
	}
}

void rs_read_gira (unsigned char* z)
{
	unsigned char n=0, tmp;
	tmp = SBUF;
	RI = 0;
	if (!g_res_pointer)
	{
		if (tmp == GIRA_START_BIT)
			z[g_res_pointer++] = tmp;
	}
	else
	{
		z[g_res_pointer++] = tmp;
	}
	if (g_res_pointer >= GIRA_SIZE_RES)		// Abort!
	{
		rs_send_c(GIRA_ACK);
		rs_send_c(GIRA_ACK);
		g_res_pointer = 0;
		g_state = 0x00;
//		g_res_pointer = GIRA_SIZE_RES -1;
//		g_state++;
	}
	else
	{
		if (tmp == GIRA_STOP_BIT)
			g_state++;
	}
}


// ********************** KNX communication *************************
/*
void write_value_req(void)	// process received write_value_request telegram
{
	unsigned char objno;

	objno=find_first_objno(telegramm[3],telegramm[4]);

	rs_send_c(objno);
	rs_send_c(telegramm[7]&0x01);

	if (objno==OBJ_SET_ALARM) {	// remote alarm
		if (telegramm[7]&0x01) {	// Alarm on
			g_set_alarm = 1;
		}
		else {						// Alarm off
			g_set_alarm = 0;
		}
	}

	if (objno==OBJ_SET_TALARM) {	// remote test
		if (telegramm[7]&0x01) {	// Test on
			g_set_test = 1;
		}
		else {						// Test off
			g_set_test = 0;
		}
	}
}
*/

void write_value_req(void)
{
	unsigned char objno,objflags,gapos,atp,assno,n,gaposh;

	// Gruppenadressposition aus Gruppenadresse bestimmen
	gapos=gapos_in_gat(telegramm[3],telegramm[4]);
	if (gapos!=0xFF)
	{
	    atp=eeprom[ASSOCTABPTR];			// Association Table Pointer
	    assno=eeprom[atp];					// Erster Eintrag = Anzahl Eintraege

	    for(n=0;n<assno;n++) {				// Schleife über alle Eintraege in der Ass-Table, denn es koennten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
	    	gaposh=eeprom[atp+1+(n*2)];			// Erste GA-Position aus ASS Tabelle lesen
	    	if(gapos==gaposh) {					// Wenn Positionsnummer uebereinstimmt
	    		objno=eeprom[atp+2+(n*2)];			// Objektnummer
	    		objflags=read_objflags(objno);		// Objekt Flags lesen
//	    		rs_send_c(objno);
//	    		rs_send_c(objflags);
//	    		rs_send_c(telegramm[7]&0x01);
	    		if((objflags&0x14)==0x14) {			// Kommunikation zulaessig (Bit 2 = communication enable) + Schreiben zulaessig (Bit 4 = write enable)
	    			if (objno==OBJ_SET_ALARM) {	// remote alarm
	    				if (telegramm[7]&0x01) {	// Alarm on
	    					g_set_alarm = 1;
	    				}
	    				else {						// Alarm off
	    					g_set_alarm = 0;
	    					g_stat_alarm_delay = 0;	// Do not send delayed alarm even if local alarm detected
//	    					g_set_test = 0;         // Test alarm also off
	    				}
	    			}

	    			if (objno==OBJ_SET_TALARM) {	// remote test
	    				if (telegramm[7]&0x01) {	// Test on
	    					g_set_test = 1;
	    				}
	    				else {						// Test off
	    					g_set_test = 0;
	    				}
	    			}
	    		}
	    	}
	    }
	}
}


void read_value_req(void)	// process received read_value_request telegram
{
	unsigned char objno, objflags;

	objno=find_first_objno(telegramm[3],telegramm[4]);
	objflags=read_objflags(objno);		// read object flags
	if((objflags&0x0C)==0x0C)		// Answer only when READ and COM flags are set
	{
		g_objno = objno;
		g_state = 0x01;
	}
}

unsigned long read_obj_value(unsigned char objno)
{
	unsigned char dummy = objno;
	return g_to_knx;
}


// ********************** Processing logic *************************
void state_machine(unsigned char objno)
{
	__bit return_knx_send;
	static unsigned int gira_read_timeout = 0;
	if (g_state)
	{
		if (g_state==0x01)
		{
			g_res_pointer = 0;
		}
		switch (objno)
		{
		case OBJ_SET_ALARM: /* 1Bit Remote alarm */
			if (g_state == 0x01)
			{
				g_to_knx = g_set_alarm;
				g_state = 0x05;
			}
			break;
		case OBJ_SET_TALARM: /* 1Bit Remote test */
			if (g_state == 0x01)
			{
				g_to_knx = g_set_test;
				g_state = 0x05;
			}
			break;
		case OBJ_NOTUSED2:  // Not used object 2
			g_state = 0x00;
			break;
		case OBJ_NOTUSED3:  // Not used object 3
			g_state = 0x00;
			break;
		case OBJ_SERIAL: /* 4Byte Serialnumber */
			rs_send_gira(req[0]);
			if (g_state == 0x04)
			{
				g_to_knx = g_res_conv[1];
				g_to_knx <<= 8;
				g_to_knx |= g_res_conv[2];
				g_to_knx <<= 8;
				g_to_knx |= g_res_conv[3];
				g_to_knx <<= 8;
				g_to_knx |= g_res_conv[4];
				g_state++;
			}
			break;
		case OBJ_OPERATING_TIME: /* 4Byte operating time */
			rs_send_gira(req[1]);
			if (g_state == 0x04)
			{
				g_to_knx = g_res_conv[1];
				g_to_knx <<= 8;
				g_to_knx |= g_res_conv[2];
				g_to_knx <<= 8;
				g_to_knx |= g_res_conv[3];
				g_to_knx <<= 8;
				g_to_knx |= g_res_conv[4];
				g_to_knx >>= 2;
				g_state++;
			}
			break;
		case OBJ_SMOKEBOX_VALUE: /* 2Byte smokebox value */
			rs_send_gira(req[2]);
			if (g_state == 0x04)
			{
				g_to_knx = ((g_res_conv[1]<<8)|g_res_conv[2]);
				g_state++;
			}
			break;
		case OBJ_POLLUTION: /* 1Byte degree of pollution */
			rs_send_gira(req[2]);
			if (g_state == 0x04)
			{
				g_to_knx = g_res_conv[4];
				g_state++;
			}
			break;
		case OBJ_BAT_VOLTAGE: /* 2Byte Battery voltage */
			rs_send_gira(req[3]);
			if (g_state == 0x04)
			{
				g_to_knx = ((g_res_conv[1]<<8)|g_res_conv[2]);
				g_to_knx *= 9184;
				g_to_knx /= 5000;
				conv_dpt_9_001 (&g_to_knx);
				g_state++;
			}
			break;
		case OBJ_TEMP1: /* 2Byte Temperature 1 */
			rs_send_gira(req[3]);
			if (g_state == 0x04)
			{
				g_to_knx = ((g_res_conv[4]*50)-2000) ;
				conv_dpt_9_001 (&g_to_knx);
				g_state++;
			}
			break;
		case OBJ_TEMP2: /* 2Byte Temperature 2 */
			rs_send_gira(req[3]);
			if (g_state == 0x04)
			{
				g_to_knx = ((g_res_conv[3]*50)-2000) ;
				conv_dpt_9_001 (&g_to_knx);
				g_state++;
			}
			break;
		case OBJ_CNT_SMOKEALARM: /* 1Byte Number of smokealarm */
			rs_send_gira(req[2]);
			if (g_state == 0x04)
			{
				g_to_knx = g_res_conv[3];
				g_state++;
			}
			break;
		case OBJ_CNT_TEMPALARM: /* 1Byte Number of temperaturealarm */
			rs_send_gira(req[4]);
			if (g_state == 0x04)
			{
				g_to_knx = g_res_conv[1];
				g_state++;
			}
			break;
		case OBJ_CNT_TESTALARM: /* 1Byte Number of testalarm */
			rs_send_gira(req[4]);
			if (g_state == 0x04)
			{
				g_to_knx = g_res_conv[2];
				g_state++;
			}
			break;
		case OBJ_CNT_ALARM_WIRE: /* 1Byte Number of alarm wire */
			rs_send_gira(req[4]);
			if (g_state == 0x04)
			{
				g_to_knx = g_res_conv[3];
				g_state++;
			}
			break;
		case OBJ_CNT_ALARM_WIRELESS: /* 1Byte Number of alarm wireless */
			rs_send_gira(req[4]);
			if (g_state == 0x04)
			{
				g_to_knx = g_res_conv[4];
				g_state++;
			}
			break;
		case OBJ_CNT_TALARM_WIRE: /* 1Byte Number of testalarm wire*/
			rs_send_gira(req[5]);
			if (g_state == 0x04)
			{
				g_to_knx = g_res_conv[1];
				g_state++;
			}
			break;
		case OBJ_CNT_TALARM_WIRELESS: /* 1Byte Number of testalarm wireless */
			rs_send_gira(req[5]);
			if (g_state == 0x04)
			{
				g_to_knx = g_res_conv[2];
				g_state++;
			}
			break;
		case OBJ_STAT_ALARM: /* 1Bit Alarm state */
			if (g_state == 0x01)
			{
				g_to_knx = g_stat_alarm;
				g_state = 0x05;
			}
			break;
		case OBJ_STAT_ALARM_CENTRAL: /* 1Bit Alarm state central */
			if (g_state == 0x01)
			{
				g_to_knx = g_stat_alarm;
				g_state = 0x05;
			}
			break;
		case OBJ_STAT_ALARM_DELAYED: /* 1Bit Alarm state delayed */
			if (g_state == 0x01)
			{
				g_to_knx = g_stat_alarm;
				g_state = 0x05;
			}
			break;
		case OBJ_STAT_TALARM: /* 1Bit Testalarm state */
			if (g_state == 0x01)
			{
				g_to_knx = g_stat_test;
				g_state = 0x05;
			}
			break;
		case OBJ_STAT_TALARM_CENTRAL: /* 1Bit Testalarm state central */
			if (g_state == 0x01)
			{
				g_to_knx = g_stat_test;
				g_state = 0x05;
			}
			break;

		}

		// Read answer from GIRA
		if (g_state == 0x02)
		{
			if (RI)
			{
				rs_read_gira(g_res);
				gira_read_timeout = 0;
			}
			else
			{
				if((gira_read_timeout++)==0x0600)	// Read Timeout
				{
					rs_send_c(GIRA_ACK);
					rs_send_c(GIRA_ACK);
					g_res_pointer = 0;
					g_state = 0x00;
#ifdef SEND_FFFFFFFF_ON_GIRA_COM_ERROR
					g_state = 0x05;
					g_to_knx = 0xFFFFFFFF;
#endif
				}
			}
		}

		// Send ACK to GIRA and recalculate data
		if (g_state == 0x03)
		{
			// ACK 1st time
			rs_send_c(GIRA_ACK);
			calculate (g_res,g_res_conv);
		}

		// Send data to KNX and ACK to Gira second time if data received
		if (g_state == 0x05)
		{
			return_knx_send = send_obj_value(objno);
			if (!return_knx_send)
			{
				// ACK 2nd time - data received
				if (g_res_pointer)
					rs_send_c(GIRA_ACK);

				g_res_pointer = 0;
				g_state = 0x00;
			}
		}
	}
}

unsigned char calculate(unsigned char* data_in, unsigned char* data_out)
{
	unsigned char x,data_tmp;
	unsigned char start_byte_fnd = 0;
	unsigned char no_dataset = 0;

	g_state++;

	// Init data_out
	for (x = 0; x < GIRA_SIZE_RES/2; x++)
		data_out[x] = 0x00;

//	for (x = 0; x < GIRA_SIZE_RES; x++)
	for (x = 0; x < g_res_pointer; x++)
	{
		// End character
		if (data_in[x] == GIRA_STOP_BIT)
			break;

			// Start character
		if (!start_byte_fnd)
		{
			if (data_in[x] == GIRA_START_BIT)
				start_byte_fnd = 1;
			continue;
		}

		// Conversion from ASCII Hex to Raw Hex
		// Data <> ASCII Hex is discarded
		data_tmp = 0x00;
		if (data_in[x] >= 0x30 && data_in[x] <= 0x39)
			data_tmp = data_in[x] - 0x30;
		if (data_in[x] >= 0x41 && data_in[x] <= 0x46)
			data_tmp = data_in[x] - 0x37;

		// Each dataset contains only max 4 bits. So pack two datasets into one
		if (no_dataset%2==0)
			data_out[no_dataset/2] = (data_tmp << 4);
		else
			data_out[no_dataset/2]  |= data_tmp;
		no_dataset++;
	}
	return no_dataset/2;
}

void set_gira_stat (unsigned char *p_sec_timer)
{
	// On local alarm
	if (g_stat_alarm || g_stat_test)
	{
		// Freeze P0.2 out to gira when local alarm
		return;
	}

	// Set Alarm or Test alarm
	if (g_set_alarm)
	{
		P1 &= ~(0x04);
	}
	else
	{
		if (g_set_test)
		{
			     if ((*p_sec_timer)&02)
			     {
			 		P1 &= ~(0x04);
			     }
			     else
			     {
					P1 |= (0x04);
			     }
		}
		else
		{
			P1 |= (0x04);
		}
	}
}

void check_gira_stat(void)
{
	static unsigned char gira_stat = 0xFF, test_cnt = 0;
	static __bit stat_alarm_old, stat_test_old;
	static __bit stat_alarm_central, stat_test_central;
	static __bit set_delay_off=0;

	// Remote alarm
	if (g_set_alarm || g_set_test)
	{
		// Freeze g_stat_* when remote alarm
		return;
	}
	else
	{
		// Get GIRA data
		gira_stat <<= 1;
		gira_stat |= ((P1&0x04)>>2);

		// Bits 1111 -> No Alarm
		if ((gira_stat&0x0F) == 0x0F)
		{
			g_stat_alarm = 0;
			g_stat_test = 0;
			test_cnt = 0;
		}
		else
		{
			// Bits 0000 -> Alarm
			if (!(gira_stat&0x0F))
			{
				g_stat_alarm = 1;
				g_stat_test  = 0;
				test_cnt = 0;
			}
			// Bits contain 0 and 1 -> Test
			else
			{
				g_stat_alarm = 0;
				if (test_cnt < 4)
					test_cnt++;
				else
				{
					g_stat_test = 1;
				}
			}
		}
	}
	// Alarm: send if just changed and timeslot free
	if (!g_state && g_stat_alarm != stat_alarm_old)
	{
		stat_alarm_old = g_stat_alarm;
		g_objno = OBJ_STAT_ALARM;
		g_state = 0x01;

		// Init delayed telegram
		if (eeprom[CONF_A_DELAY]&0x80)
		{
			if (g_stat_alarm)
			{
				g_stat_alarm_delay = 1;
				if (eeprom[CONF_A_DELAY_BASIS])
					g_timer_alarm_delay=g_timer + (eeprom[CONF_A_DELAY_FAKTOR]&0x7F)*60;		// Min
				else
					g_timer_alarm_delay=g_timer + (eeprom[CONF_A_DELAY_FAKTOR]&0x7F);			// Sec
				g_timer_alarm_delay++;         // because g_timer will also increase 1 before first compare
			}
			else
			{
				// Only if delay telegram 1 was send, send 0 telegram also
				if (!g_stat_alarm_delay)
				{
					set_delay_off = 1;
				}
				g_stat_alarm_delay = 0;
			}
		}
	}
	// Testalarm:  send if just changed and timeslot free
	if (!g_state && g_stat_test != stat_test_old)
	{
		stat_test_old = g_stat_test;
		g_objno = OBJ_STAT_TALARM;
		g_state = 0x01;
	}
	// central object alarm: send if just changed and timeslot free
	if (!g_state && stat_alarm_central != g_stat_alarm)
	{
		stat_alarm_central = g_stat_alarm;
		g_objno = OBJ_STAT_ALARM_CENTRAL;
		g_state = 0x01;
	}
	// central object testalarm: send if just changed and timeslot free
	if (!g_state && stat_test_central != g_stat_test)
	{
		stat_test_central = g_stat_test;
		g_objno = OBJ_STAT_TALARM_CENTRAL;
		g_state = 0x01;
	}
	// send delayed 0 telegram (1 is send in delay_timer) send if timeslot free
	if (!g_state && set_delay_off)
	{
		set_delay_off = 0;
		g_objno = OBJ_STAT_ALARM_DELAYED;
		g_state = 0x01;
	}
}

void conv_dpt_9_001 (unsigned long *p_data)
{
	unsigned int tmp_div = 0;
	while (*p_data >= 2047)	// DPT 9.001
	{
		tmp_div++;
		(*p_data) /= 2;
	}
	(*p_data)  |= (tmp_div<<11);
}

// ********************** Timer *************************
void delay_timer(void)
{
	static unsigned char sec_timer, send_info = 0;

	RTCCON=0x60;		// RTC anhalten und Flag löschen
	RTCH=0x70;			// reload Real Time Clock (0,5s=0x7080)
	RTCL=0x80;

	// Set/Reset alarm and test alarm
	set_gira_stat(&sec_timer);

	// Check local GIRA state
	check_gira_stat();

	// Enter only every 2nd run, to get 1 second
	if (sec_timer&01)
	{
		g_timer++;			// increment every second

		if (g_timer_alarm==g_timer && (eeprom[CONF_A_ZYKLISCH]&0x80)) 			// cyclic sending alarm state
		{
			if (g_state)												// If there is data pending to send in this timeslot
			{
				g_timer_alarm++;										// do your periodic send in the next timeslot
			}
			else
			{
				g_objno = OBJ_STAT_ALARM;// objno 18
				g_state = 0x01;
				if (eeprom[CONF_A_BASIS])
					g_timer_alarm=g_timer+(eeprom[CONF_A_FAKTOR]&0x7F)*60;		// Min
				else
					g_timer_alarm=g_timer+(eeprom[CONF_A_FAKTOR]&0x7F);		// Sec
			}
		}

		if (g_timer_test==g_timer && (eeprom[CONF_S_ZYKLISCH]&0x80)) 			// cyclic sending testalarm state
		{
			if (g_state)												// If there is data pending to send in this timeslot
			{
				g_timer_test++;											// do your periodic send in the next timeslot
			}
			else
			{
				g_objno = OBJ_STAT_TALARM;// objno 21
				g_state = 0x01;
				if (eeprom[CONF_S_BASIS])
					g_timer_test=g_timer+(eeprom[CONF_S_FAKTOR]&0x7F)*60;		// Min
				else
					g_timer_test=g_timer+(eeprom[CONF_S_FAKTOR]&0x7F);			// Sec
			}
		}

		if (g_stat_alarm_delay && g_timer_alarm_delay==g_timer && (eeprom[CONF_A_DELAY]&0x80)) 		// send delayed alarm telegram
		{
			if (g_state)												// If there is data pending to send in this timeslot
			{
				g_timer_alarm_delay++;									// do your periodic send in the next timeslot
			}
			else
			{
				g_stat_alarm_delay = 0;
				g_objno = OBJ_STAT_ALARM_DELAYED;
				g_state = 0x01;
			}
		}

		if (g_timer_info==g_timer && (eeprom[CONF_INFO_ZYKLISCH]&0x80)) 		// cyclic sending info
		{
			if (g_state)												// If there is data pending to send in this timeslot
			{
				g_timer_info++;											// do your periodic send in the next timeslot
			}
			else
			{
				// Send all Gira items
				send_info = 4;
				
				if(eeprom[CONF_INFO_FAKTOR]&0x80){
						if(eeprom[CONF_INFO_BASIS])
							g_timer_info=g_timer+(eeprom[CONF_INFO_FAKTOR]&0x7F)*60;		// Min
						else
							g_timer_info=g_timer+(eeprom[CONF_INFO_FAKTOR]&0x7F);		// Min
					}
			}
		}

		if (!g_state && send_info)										// Send all Gira info
		{
	
			if(send_info<=10){
				if((eeprom[CONF_INFO_4TO10]>> (send_info-4))&0x01){
					g_objno = send_info;
					g_state = 0x01;
				}
			}
			else{
				if((eeprom[CONF_INFO_11TO17]>> (send_info-11))&0x01){
					g_objno = send_info;
					g_state = 0x01;
					
				}

			}
			send_info++;
			if (send_info == 18)
				send_info = 0;
		}


	}


	sec_timer++;

	RTCCON=0x61;		// RTC starten
}


// ********************** Initialization *************************
void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{
	P0M1= 0x03;			// P0.0 and P0.1 open drain. all other pins of P0 as bidirectional
	P0M2= 0x03;
	P0 = ~0x04;			// P0.2 low to enable serial gira communication. all other pins of p0 high


	P1M1 |= (1<<2);		// P1.2 to GIRA open drain with external pullup
	P1M2 |= (1<<2);
	P1   |= (1<<2);		// P1.2 high

	rs_init(96);

	RTCH=0x70;			// reload Real Time Clock (0,5s=0x7080)
	RTCL=0x80;			// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)

	RTCCON=0x61;	// ... und starten

	g_timer=0;
	if (eeprom[CONF_A_ZYKLISCH])    g_timer_alarm=g_timer+2;
	if (eeprom[CONF_S_ZYKLISCH])    g_timer_test =g_timer+4;
	if (eeprom[CONF_INFO_ZYKLISCH]) g_timer_info =g_timer+6;

	// Beispiel für die Applikations-spezifischen Einträge im eeprom
	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	START_WRITECYCLE;
	WRITE_BYTE(0x01,0x03,0x00);	// Herstellercode 0x0000 = Freebus
	WRITE_BYTE(0x01,0x04,0x4C); // Herstellercode 0x004C = Bosch
	WRITE_BYTE(0x01,0x05,0x03);	// Devicetype 0x03F2
	WRITE_BYTE(0x01,0x06,0xF2);
	WRITE_BYTE(0x01,0x07,0x01);	// Versionnumber of application programm
	WRITE_BYTE(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0xA0);	// COMMSTAB Pointer
	STOP_WRITECYCLE;
	EA=1;						// Interrupts freigeben

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
	  EA=1;

	rs_send_c(GIRA_ACK);
	rs_send_c(GIRA_ACK);

}
