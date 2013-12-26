/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2013 Andreas Krieger
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 * 
 * 	
 * 
 */




#include <P89LPC922.h>
#include "../lib_lpc922/Releases/fb_lpc922_1.4x.h"
#include  "fb_app_ws.h"
#include "../com/debug.h"

#include "../com/fb_rs232.h"
unsigned char portbuffer;	// Zwischenspeicherung der Portzustände

//unsigned char timerstart[3];
//unsigned char timerstate[3];
unsigned char timerbase[TIMERANZ];// Speicherplatz für die Zeitbasis und 4 status bits
unsigned char timercnt[TIMERANZ];// speicherplatz für den timercounter und 1 status bit



unsigned char timer,timer_m;		// Timer für Schaltverzögerungen, wird alle 100ms hochgezählt

__bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszuführen
__bit portchanged;
unsigned char __idata __at IDATA_START+21 stream[15];
__bit stream_comming_in;
__bit stream_arrived;
__bit rain;
unsigned long avg_tmp;

unsigned char stream_bit_ctr;
unsigned char stream_no;
unsigned char id[4];
unsigned int updated_objects;
signed int __idata __at IDATA_START temp[3];
unsigned char __idata __at IDATA_START+6 humidity[3];
unsigned short __idata __at IDATA_START+9 wind_speed_av;
unsigned short __idata __at IDATA_START+11 wind_speed_max;
unsigned short __idata __at IDATA_START+13 wind_angle;
unsigned short __idata __at IDATA_START+15 rain_value;
unsigned short __idata __at IDATA_START+17 rain_offset;
unsigned char __idata __at IDATA_START+19 GW_1_8;
unsigned char __idata __at IDATA_START+20 GW_9_16;
const unsigned char bitmask_1[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
const unsigned char bitmask_0[]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};
const unsigned char shift_at_2bit[]={0,2,4,6,0,2,4,6,0,2};
const unsigned char objno_timerno[]={0,0,0,1,1,1,2,2,2,3,3};

volatile unsigned char precounter0;
volatile unsigned char precounter1;
volatile unsigned char precounter2;
volatile __bit counted0;
volatile __bit counted1;
volatile __bit counted2;
volatile __bit counted3;


void keypad_isr  (void) __interrupt (7)
{
	unsigned char keybuffer;
 // clear interrupt flag
 KBCON = 0;//0xFE;
 keybuffer=~P0;
 if(keybuffer&0x01 && !counted0){
	  precounter0++;
	  counted0=1;
 }
 if(!(keybuffer&0x01))counted0=0;

 if(keybuffer&0x02 && !counted1){
	  precounter1++;
	  counted1=1;
 }
 if(!(keybuffer&0x02))counted1=0;

 if(keybuffer&0x04 && !counted2){
	  precounter2++;
	  counted2=1;
 }
 if(!(keybuffer&0x04))counted2=0;
 
 if((__bit)(keybuffer&0x08) != rain ^(__bit)(eeprom[0xE2]&0x04))
 {
	  rain = !rain;
	  updated_objects |=0x400;
 }

  KBPATN=~keybuffer;
}



void timer0_int  (void) __interrupt (1) {// Interrupt T0 overflow streambit
stream_bit_ctr=0;
TR0=0;
} // timer0_int

void EX0_int (void) __interrupt(0){
	unsigned char n;
	unsigned short bitpause=((TH0<<8)+TL0);
	TH0=0;
	TL0=0;
	TR0=1;
	if(!stream_arrived)
	{
		if(bitpause>=29491 && bitpause<=36864 )// 9ms = sync (8-10ms)
		{
			stream_comming_in = 1;
			stream_bit_ctr=0;
			for(n=stream_no;n <= ((stream_no)+4);n++)
			{
				stream[n]=0;
			}
		}
		else if (stream_comming_in)
		{
			if (bitpause>=12902 && bitpause <=16588 )//ca 4ms = 1-bit (3,5-4,5)
			{
				stream[stream_no+(stream_bit_ctr>>3)]|=bitmask_1[(stream_bit_ctr&0x07)];	
				stream_bit_ctr++; 
			}
			else if (bitpause>=5530 && bitpause <=9216 )//ca 2ms = 0-bit (1,5-2,5)
			{
				//stream[IDATA_START+(stream_bit_ctr>>2)]&=bitmask_0[stream_bit_ctr&0x03];	
				stream_bit_ctr++; 
			}else {
				stream_comming_in=0; //verwerfen
//				if(stream_no < 10)stream_no+=5;
			}
		}	
		if(stream_bit_ctr==36)
			{
			if(stream_no < 10)stream_no+=5;
			else 
				{
				stream_no=0;
				stream_arrived=1;
				}
			stream_comming_in=0;
			}
	}
}

__bit checksume(unsigned char p_no)
{
	unsigned char byte_no;
	unsigned char check=0x0F;// alle anderen Telegramme
	unsigned char nextcheck_hi,nextcheck_lo;
	__bit rain=0;
	if((stream[p_no+1]&0x76)==0x36)// Regen Telegramm
	{
		check=0x07;
		rain=1;
	}
	for(byte_no=p_no;byte_no<=(p_no+3);byte_no++)// die checksume der 8 Nibbles berechnen 
	{
		nextcheck_hi = stream[byte_no]>>4;
		nextcheck_lo= stream[byte_no]&0x0F;
		if(rain)// für Regen Telegramm
		{
			check+=nextcheck_hi;
			check+=nextcheck_lo;
		}
		else	// oder alle anderen Telegramme
		{
			check-=nextcheck_hi;
			check-=nextcheck_lo;
		}
	}
	if((check&0x0F) == stream[p_no+4])return 1;
	else return 0;
}


void update(void)// update der Objekte nach Funk Telegramm Empfang
{
	unsigned char p_no,channel;
	for(p_no=0;p_no<=10;p_no+=5)
	{
		if(checksume(p_no))
		{	
/*			channel=0;// Kanal 0-3, Kanal 4 = Fehler/ID nicht gefunden
			for (n=0;n<=2;n++)
			{
				if (id[n]==stream[p_no])
					{
					channel=(((stream[p_no]&0x20)>>5)|((stream[p_no]&0x10)>>3))+1;// bit 5,4 ist sind die Kanalbit 0,1
					}
			}
			if(channel)
*/
			channel=(((stream[p_no]&0x20)>>5)|((stream[p_no]&0x10)>>3));// bit 5,4 ist sind die Kanalbit 0,1
			if(!id[channel])// wenn channel-ID leer 
			{
				id[channel]=stream[p_no];
			}
			else
			{
				if((GW_9_16 & 0x40) && id[channel]!= stream[p_no])// reset objekt aktiviert
				{
					id[channel]=stream[p_no];// channel-ID eintragen
					GW_9_16 &= ~0x40;		// Reset objekt löschen
				}
			}
			if(id[channel]==stream[p_no])
			{
				if((stream[p_no+1]&0x06)==0x06)// alles ausser temperatur/feuchte
				{
					switch(stream[p_no+1]&0x70)
					{
					case 0x10:
						if(!(eeprom[0xD7]&0x10))
							{
							wind_speed_av=stream[p_no+3]*50;
							updated_objects |= 0x40;
							}
					break;
					case 0x70:
						if(!(eeprom[0xD7]&0x20))
						{
						wind_speed_max=stream[p_no+3]*50;
						}
						wind_angle=(stream[p_no+2]<<1)+(stream[p_no+1]>>7);
						updated_objects|= 0x0180;
					break;
					case 0x30:
						if(!(eeprom[0xD7]&0x40))
						{
						rain_value=(((stream[p_no+3]<<8)+stream[p_no+2]))-rain_offset;
						updated_objects |= 0x200;
						}
					break;
					default:
						
					}
				}
				else// temp/feuchte
				{
					humidity[channel-1]=((stream[p_no+3]>>4)*10)+(stream[p_no+3]&0x0F);
					if(stream[p_no+2]& 0x80)// negative temperatur
					{
						temp[channel-1]=((((int)stream[p_no+2])<<4)|0xF000)|((stream[p_no+1]>>4))*10;// temperatur
					}
					else
					{
						temp[channel-1]=((((int)stream[p_no+2])<<4)+(stream[p_no+1]>>4))*10;// temperatur

					}
					updated_objects |= bitmask_1[channel-1];// bit 0-2
					updated_objects|= bitmask_1[channel+2];// bit 3-5
				}
			}// end if (channel...
			//else if(id_counter<=3)
			//{
			//	id[id_counter]=stream[p_no];
			//	id_counter++;
			//}
		}// end if(checksume...
	}// end for(p_no...
}//end function


void write_value_req(unsigned char objno)	// Objekte steuern gemäß EIS  Protokoll (an/aus/dimm/set)
{
  unsigned char valtmp;
  //unsigned char blockstart, blockend, block_polarity;
  //unsigned char obj,group;

  	//obj=objno%8;// modulo 3 ergibt die Gruppennummer
    // group=objno/8;
     valtmp=telegramm[7]&0x01;

	 // Objektbehandlung:
	 if(objno==25){ // die Reset objekte..
		 if(valtmp ) {
			 GW_9_16 |= 0x40;
		 }
		 else GW_9_16 &= ~0x40;
	 }
     if(objno==9)write_obj_value(9,(telegramm[8]<<8)+telegramm[9]);
     
}




/** 
* Objektwert lesen wurde angefordert, read_value_response Telegramm zurücksenden
*
* 
* @return
* 
*/
void read_value_req(unsigned char objno)
{
  send_obj_value(objno+64); // die 64 macht ein response Telegramm daraus
}


int read_obj_data(unsigned char objno)
// lesen der Objektwerte in 0,01 digits
// bzw bitformat
// wird von read_obj_value zum senden gelesen, sowie zum Vergleichen der Grenzwerte
{
	signed int ret_val=0,tmp;

	if (objno<=2)
	{
		ret_val= temp[objno];//°C
		if((eeprom[0xE8]&0x20))//°K
			ret_val=ret_val+27315;
		if((eeprom[0xE8]&0x10))//°K
		{
			tmp=ret_val/5;// wir müssen erst teilen sonst >35° overflow
			tmp=tmp*9;
			ret_val=tmp+3200;
		}
	}
	
	if(objno>=3 && objno<=5)ret_val=humidity[objno-3];
	if(objno==6)ret_val=wind_speed_av;
	if(objno==7)ret_val=wind_speed_max;
	if (objno>=6 && objno<=7)
	{
		if((eeprom[0xE8]&0xC0))// wenn als Einheit km/h gewählt..
		{
			tmp=ret_val*3;
			ret_val=tmp+(tmp/5);// =*3,6
		}
		if((eeprom[0xE8]&0x80))// wenn als Einheit kn gewählt..
		{
			tmp=ret_val/2;
			ret_val=tmp+(ret_val>>3);// *.5125 (korrekt 0.5144)
		}
		if((eeprom[0xE8]&0xC0)==0xc0)// wenn als Einheit bft gewählt..
		{
			ret_val=ret_val/5;//
		}
		
	}
	if(objno==8)ret_val=wind_angle;
	if(objno==9)
		{
		if(eeprom[0xD7]&0x40)ret_val=rain_value;// wenn Regenmenge auf Impulszählung
		else ret_val=rain_value*25;
		}
	if(objno==10)ret_val=rain;
	if(objno>=11 && objno<=18)
		{
		if(GW_1_8 & bitmask_1[objno-11])	ret_val=1;
		else ret_val=0;
		}
	if(objno>=19 && objno<=25)
		{
		if(GW_9_16 & bitmask_1[objno-19])ret_val=1;
		else ret_val=0;
		}
	return(ret_val);
	
}
unsigned long read_obj_value(unsigned char objno)	// gibt den Wert eines Objektes zurueck
{
	int returnvalue;
	unsigned char x;
	if(objno>=10 )
	{
		return (read_obj_data(objno));
	}
	else if(objno==8)returnvalue=wind_angle*100;
		else if(objno>=3 && objno<=5)// Feuchte %
		{
			x=humidity[objno-3];
			returnvalue=x*2 + x/2 + x/20;
		}
		else returnvalue=eis5conversion(read_obj_data(objno));
	return returnvalue;
}


void write_obj_value(unsigned char objno,unsigned int objvalue)	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
{
unsigned char obj,group;
	group= objno/8;
	obj = objno % 8;
	if(objno==9)
	{
		if (!objvalue)rain_offset+=rain_value;
	}
	if(objno==10)rain=objvalue;
	if (objno>=11&& objno<=18)
	{
		if (objvalue)GW_1_8 |= bitmask_1[objno-11];
		else GW_1_8 &= bitmask_0[objno-11];
	}
	if (objno>=19&& objno<=25)
	{
		if (objvalue)GW_9_16 |= bitmask_1[objno-19];
		else GW_9_16 &= bitmask_0[objno-19];
	}

}


signed int eis5conversion(signed int zahl)// wandelt 32 bit var in eis5 um
{
	unsigned char exp=0;
	if(zahl>=0)
	{
		while (zahl > 2047){//solange Mantisse größer 11 Bit
			zahl=zahl>>1;// Mantisse /2
			exp++;// und exponent um 1 erhöhen (ist ein 2^exp)
		}
	}
	else
	{
		while (zahl < -2048){//solange Mantisse größer 11 Bit
			zahl=zahl >> 1;// Mantisse /2
			zahl=zahl|0x8000;// signed bit reparieren
			exp++;// und exponent um 1 erhöhen (ist ein 2^exp)
		}
		zahl=zahl & 0x87FF;
	}
 	return ((signed int)zahl|(exp<<11));// exponent dazu.
}

void sendbychange(unsigned char objno,unsigned char val){
	if (val){
			if(read_obj_data(objno)==0)write_send(objno,1);
			}
			else if( read_obj_data(objno))write_send(objno,0);
}

void write_send(unsigned char objno,unsigned int value){

	write_obj_value(objno,(unsigned long)value);
	while(!send_obj_value(objno));
}

void delay_timer(void)	// zählt alle 0,1s die Variable Timer hoch 
{
	unsigned char objno,n,m,tmp;
	unsigned int timerflags;
	objno;n;m;
	
	RTCCON=0x61;		// RTC starten, RUN Bit löschen
	
	timer++;// wird alle 1s aufgerufen
	timerflags = 1;
	if ((timer%10)==0){
		timerflags=3;
	}
	if (timer==60){
		timerflags=7;
		timer=0;
		timer_m++;
	}
	if (timer_m==60){
		timerflags=15;
		timer_m=0;
	}
//  timerbehandlung über 4 Basen, 1sec 10 sec 1min 1 std
	for(n=0;n<3;n++){
		if(timerflags & 0x0001){// positive flags erzeugen und schieben
			for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
				if ((timerbase[m]& 0x03)==n){// wenn die base mit der gespeicherten base übereinstimmt
					if (timercnt[m]>0x00){// wenn der counter läuft...
						timercnt[m]=timercnt[m]-1;// den timer [m]decrementieren
					}// end if (timercnt...
					else timercnt[m]=eeprom[0xDD + m];
				}//end if(timerbase...
			}// end  for(m..
		}// end if timer...
		timerflags = timerflags>>1;
	}//end for (n=...

	
		
	// ab Hier die aktion...
	 //				######  checken der update flags  #####
	
	for (n=0;n<=9;n++)// die 10 Wertobjekte testen ob sie gesendet werden sollen
	{
	// zyclisches senden parameter m ab 0xDA je 2 bit. T1..3 H1..3 wind-avg, wind-böe,windrichtung,regen
		m=(eeprom[0xDA+(n/4)]>>shift_at_2bit[n])&0x03;// m hier der zycl senden mode
		if (((updated_objects&(1<<n))&& (m==1 ||(m==2 && timercnt[objno_timerno[n]]==0)))||
			 (m==3 && timercnt[objno_timerno[n]]==0))
		{
			if(send_obj_value(n))updated_objects &= ~(1<<n);// Bei erfolgreichem Eintrag in den Ringspeicher löschen
		}
	}
	 // bearbeiten der precounter bei impulszählung
	 // wenn precounter was gezählt hat und keine Löschanforderung besteht
	m=eeprom[0xD9];
	if(eeprom[0xD7]&0x10)// wenn wind_avg auf Impulszählung
	{	// Torzeit 1 sekunden

		 tmp=precounter0;
		 precounter0=0;
		 avg_tmp=(avg_tmp <<8)- avg_tmp;
		 if(m)avg_tmp += ((tmp*m)<<8);// Berechnung Universal
		 else avg_tmp += ((long)((tmp+2)*34)<<8);// Berechnung für Eltako Windmesser
		 avg_tmp=avg_tmp>>8;
		 wind_speed_av = (int)(avg_tmp>>8);
	}

	if(eeprom[0xD7]&0x20)// wenn wind_böe auf Impulszählung
	{
		 tmp=precounter1;
		 precounter1=0;
		 if(m)wind_speed_max =tmp*m;// Berechnung Universal
		 else if(tmp)
			 wind_speed_max = (tmp+2)*34;// Berechnung für Eltako Windmesser
		 else wind_speed_max=0;
	 }
//  Regen
		tmp=precounter2;
		precounter2=0;
		m=eeprom[0xD2];
		if(eeprom[0xD7]&0x40)// wenn Regenmenge auf Impulszählung
		{ 
			if(m) rain_value = rain_value + m; //wenn ein Volumen angegeben für Alternativmessgerät
			else
			{								// sonst WS155 Berechnung
			rain_value += 43;	// 5/6 * 0.5= 20.833
//				if ((rain_offset %5)==0)rain_value +=tmp;
//				else rain_value = rain_value +tmp+tmp;
			}
		}

	 // checken des Regensensors:
	 if (eeprom[0xD7]&0x04)
	 {	
		 if((updated_objects & 0x400)|| ((__bit)(eeprom[0xDC]&0x10)&& !timercnt[3]))
		 {	// senden wenn sich geändert hat oder zyklisches senden aktiviert und Zeit abgelaufen ist
			 if(send_obj_value(10)){
				 updated_objects &= ~0x400;// Bei erfolgreichem Eintrag in den Ringspeicher löschen
			 }
		 }
	 }
		
}





void keypad_init  (void)// Eingänge 0,2 Zähler. Eingänge 1,3 Tarifumschaltung
{

  // define pattern
  KBPATN = 0x0F;
  // define P0 pins that trigger interrupt
  KBMASK = 0x0F;
  // pattern must different
  KBCON = 0x00;

  // set isr priority to 0
  IP1 &= 0xFD;
  IP1H &= 0xFD;

  // enable keypad interrupt
  EKBI = 1;
}








void bus_return(void)		// Aktionen bei Busspannungswiederkehr
{
//	__bit bitval;
//	unsigned char n,m;
// hier einschaltverhalten bei busreturn rein...
}



void restart_app(void)		// Alle Applikations-Parameter zurücksetzen

{
	unsigned char n;

	P0M1=0x00;		// Port 0 Modus 
	P0M2=0x00;		//alle auf bidirektional
	P0=0xFF;
 


	
	ET0=0;			// Interrupt für Timer 0 sperren

	timer=0;			// Timer-Variable, wird alle 130ms inkrementiert
  
	
	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	START_WRITECYCLE
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x004C = Bosch
	WRITE_BYTE(0x01,0x04,0x4C)

				

	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	STOP_WRITECYCLE
//  set timer 0 autoreload 0.05ms
//	TR0=0;
//	TMOD &= 0xF0;
//	TMOD |= 0x02;// T0 autoreload
//	TH0=0x47; //47 bei 50µs  40 bei 52µ für 2400bd
//	TL0=0x47; //47 bei 50µs  40 bei 52µ für 2400bd
//	TR0=1;
	// prirority bits in p0 byte;bit     7     6     5    4      3    2     1     0
	//IP0* Interrupt priority 0 B8H -          PWDRT PBO  PS/PSR PT1  PX1   PT0   PX0
	//IP0H Interrupt priority 0 HIGH B7H -     PWDRT PBOH PSH/   PT1H PX1H  PT0H  PX0H
	
	//IP1* Interrupt priority 1    F8H   PAD   PST   -    -      -    PC    PKBI  PI2C
//	IP1H Interrupt priority 1 HIGH F7H   PADH  PSTH  -    -      -    PCH   PKBIH PI2CH

	// set timer 0 isr priority to 1
	IP0 &= 0xFD;
	IP0H &= 0xFD;
	IP0 |= 0x02;// level 1
	IP0H |= 0x08;//Timer 1 auf Level 2
	TF0=0; //timer0 flag löschen
	ET0=1;// timer 0 interupt freigeben	
	IE0=0;// interrupt flipflop löschen
	IT0=1;// EX0 flankengesteuert
	EX0=1;// EX0 interrupt einschalten

	EA=1;						// Interrupts freigeben
	
	RTCCON=0x60;		// RTC anhalten und Flag löschen
	RTCH=0xE1;//16;			// reload Real Time Clock
	RTCL=0x00;//80;		1s	//100ms laden
	RTCCON=0x61;		// RTC starten

	for(n=0;n<=3;n++)// die 4 timer basen laden
	{
		timerbase[n]=(eeprom[0xD8]>>shift_at_2bit[n])&0x03;
	}
//	timercnt[0]=1;
//	timercnt[1]=1;
	
	TR0=0;
	TMOD=(TMOD & 0xF0) + 9;			// Timer 0 als gate gesteuerter 16Bit counter
	TAMOD=0x01;
	TH0=0;
	TL0=0;
//	AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben
//	PWM=1;			// PWM Pin muss auf 1 gesetzt werden, damit PWM geht !!!
	TR0=1;

	
	
	stream_bit_ctr=0;
	stream_no=0;
	stream_arrived=0;
	
}// Ende restart app
