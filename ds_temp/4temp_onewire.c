/*
 *    _____ ______ __   __________  __  _______
 *   / ___// ____// /  / ____/ __ )/ / / / ___/
 *   \__ \/ __/  / /  / /__ / __  / / / /\__ \
 *  ___/ / /__  / /__/ /__// /_/ / /_/ /___/ /
 * /____/_____//____/_/   /_____/\____//____/
 *
 *  Copyright (c) 2010 Jan Wegner
 *  Copyright (c) 2014 Stefan Haller
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */


#include <fb_lpc922.h>
#include "4temp_onewire.h"

unsigned char kanal;
#ifdef DHT
  unsigned char __idata __at (0xFE-0x25) dht_data[5];
  unsigned char __idata __at (0xFE-0x26) dht_crc;
  int __idata __at (0xFE-0x28) dht_temp;
  int __idata __at (0xFE-0x2A) dht_humid;
  unsigned char t, bit_count, wait_count;
#endif

// Initialize One-wire Device
#define mow_init( mPX_X, mPre ) { unsigned char n; mPX_X=0;  owdelay(OWDELAY_INIT); mPX_X=1; for(n=0;n<255;n++) mPre=mPre & mPX_X; }
__bit ow_init(void)
{
  __bit presence=1;
#ifdef OWDATA
  mow_init( OWDATA, presence );
#else
  switch (kanal) {
    case 0: mow_init( P0_0, presence );break;
    case 1: mow_init( P0_1, presence );break;
    case 2: mow_init( P0_2, presence );break;
    case 3: mow_init( P0_3, presence );break;
  }
#endif
  presence=!presence;
  return (presence);
}

// Send Byte to one-wire device
//     LSB first
//     1-Bit: 5us auf low dann auf high und 85us warten //260 HW, 23 SW
//     0-Bit: 90us auf low dann auf high                //275 HW, 25 SW
#define mow_write( mPX_X, owbyte) { unsigned char n,m; for (n=1;n!=0;n=n<<1) { if (owbyte & n) { for (m=0;m<2;m++){mPX_X=0;} mPX_X=1; owdelay(OWDELAY_WRITE_B1); } else { mPX_X=0; owdelay(OWDELAY_WRITE_B0); mPX_X=1; }}}
void ow_write( unsigned char owbyte ) // Send Byte to one-wire device
{
#ifdef OWDATA
  mow_write( OWDATA, owbyte);
#else
  switch (kanal) {
    case 0: mow_write( P0_0, owbyte);break;
    case 1: mow_write( P0_1, owbyte);break;
    case 2: mow_write( P0_2, owbyte);break;
    case 3: mow_write( P0_3, owbyte);break;
  }
#endif
}


// Read byte from one-wire device
//     140 HW, 13 SW
#define mow_read( mPX_X, d) { unsigned char n,m; for (n=1;n!=0;n=n<<1) { for (m=0;m<2;m++){mPX_X=0;} mPX_X=1; owdelay(1); if (mPX_X) {d|=n;} owdelay(OWDELAY_READ); } }
unsigned char ow_read(void) // Read byte from one-wire device
{
  unsigned char d=0;
#ifdef OWDATA
  mow_read( OWDATA, d);
#else
  switch (kanal) {
    case 0: mow_read( P0_0, d);break;
    case 1: mow_read( P0_1, d);break;
    case 2: mow_read( P0_2, d);break;
    case 3: mow_read( P0_3, d);break;
  }
#endif
  return(d);
}

// Read data-bit from one-wire
//     HW and SW delay -> 1
#define mow_read_bit( mPX_X, b) { unsigned char m; for (m=0;m<2;m++) {mPX_X=0;} mPX_X=1; owdelay(1); b=mPX_X; owdelay(OWDELAY_READ);}
__bit ow_read_bit( void ) // Read data-bit from one-wire
{
  __bit b=0x00;
#ifdef OWDATA
  mow_read_bit( OWDATA, b);
#else
  switch (kanal) {
    case 0: mow_read_bit( P0_0, b);break;
    case 1: mow_read_bit( P0_1, b);break;
    case 2: mow_read_bit( P0_2, b);break;
    case 3: mow_read_bit( P0_3, b);break;
  }
#endif
 return (b);
}

#ifdef DS_SERIES
// Temperaturmessung starten
void start_tempconversion(void)
{
  if (ow_init()) {
    ow_write(0xCC);     // Skip-ROM command: alle parallel angeschlossenen Geräte werden angesprochen
    ow_write(0x44);     // start single temperature conversion command
  }
}

// Temperatur einlesen
signed int read_temp(unsigned char sensortyp)
{
  signed int t;
  if (ow_init())
  {
    unsigned char sign,lsb,msb;
    unsigned int t2;

    ow_write(0xCC);     // Skip-ROM command: alle parallel angeschlossenen Geräte werden angesprochen
    ow_write(0xBE);     // read scratchpad command: Speicher einlesen
    lsb=ow_read();      // LSB von Temperaturwert
    msb=ow_read();      // MSB von Temperaturwert

    if(sensortyp==1)
    {   // DS18S20
      unsigned char counts;
      counts=ow_read();
      counts=ow_read();
      counts=ow_read();
      counts=ow_read();
      counts=ow_read(); // counts remaining

      msb&=0xF8;        // oberen 3 Bits von LSB in untere 3 von MSB
      msb+=(lsb>>5)&0x07;

      lsb=lsb<<3;       // LSB um 3 Bit nach oben verschieben
      lsb&=0xF0;        // alles unterhalb 2^0 abschneiden
      lsb+=(16-counts);
    }

    sign=msb&0x80;
    t2=msb*256+lsb;
    if (sign) t2=(0xFFFF-t2)+1;

    t=t2*6;
    t2=t2>>2;
    t=t+t2;             // hier ist t die Teperatur in 0,01°C

    if(sensortyp==1){   // DS18S20
      t-=25;
    }

    if (sign) t=-t;     // Vorzeichen
  }
  else t=0xFFFF;        // im Fehlerfall 0xFFFF zurückmelden

  return (t);
}
#endif

#ifdef DHT
// Do a long reset-puls on DHT1x Sensors
void dht1x_init( unsigned char hw_channel)
{
  P0 &= ~bitmask_1[hw_channel];     // Leseanvorderung DHT 1x Sensoren
  owdelay(OWDELAY_DHT_RECEIVE);     // Pull low, min. 18ms (17ms hier, 1.3ms später) // Release in receive_1wire_dht
}

__bit dht_decode(unsigned char sensor_type)
{
  __bit bRet= 1; // OK

  // Calculate own checksum - Zum Senden wird an DS1820 Format angepasst
	if( dht_data[4] == ( (dht_data[0]+dht_data[1]+dht_data[2]+dht_data[3]) &0xFF) )
  {
		// Calculate Humidity and Temperature and Convert into double
		switch(sensor_type)
		{
		  case DHT1x_SENSOR:
    	{
    	  // Humidity DHT1x Sensors
    		dht_humid = dht_data[0]*100;

    		// Temperature DHT1x ( with handled negative temperatures )
   			if (dht_data[2] & 0x80) dht_temp = ((0x7F & dht_data[2]) *-100);
   			else  dht_temp = dht_data[2]*100;
   		}
   		break;

		  case DHT2x_SENSOR:
    	{
   			// Humidity DHT2x Sensors
   			dht_humid =  ((dht_data[0]<<8) + dht_data[1])*10 ;

   			// Temperature DHT2x ( with handled negative temperatures )
   			if (dht_data[2] & 0x80) dht_temp =  (((0x7F & dht_data[2])<<8) + dht_data[3])*10;
   			else  dht_temp =  ((dht_data[2]<<8) + dht_data[3])*10;
    	}
    	break;

   		default:
   		  bRet= 0; // CRC Error | Failure
   		break;
    }
  }
	return bRet;
}

// reads 5 bytes from hw_channel
// returns 0 if OK
unsigned char dht_ow_receive(unsigned char hw_channel)
{
#ifdef DEBUG_H_
  // unsigned char bit_count, wait_count;
	// Debug
	P0_4 = P0_5 = P0_6 = 0;
#endif
  // Leseanvorderung DHT 2x Sensoren
  // DHT1x Sensoren vorher mit dht1x_init() initialisieren
  P0 &= ~bitmask_1[hw_channel];
  owdelay(OWDELAY_DHT_RECEIVE);  // Reset pulse, 1.3ms
  P0 |= bitmask_1[hw_channel];
  //    for (t = 0; t < 1; t++)
  //   ;

  wait_count = 0; // Wait for Falling Edge, DHT response is low for 80us
  while( P0 &bitmask_1[hw_channel])
	{
    wait_count++;
    if(wait_count > 100)
    {
      dht_data[0] = dht_data[1] = dht_data[2] = dht_data[3] = 0; // Delete previous sample
#ifdef DEBUG_H_
      dht_data[4] = 0xFF; // Something went wrong (for debug readability only)
#endif
      return 1; // Error: DHT Sensor LOW Timeout
    }
  }

  wait_count = 0; // Wait for Rising Edge, DHT response (high for 80us)
  while (!(P0 &bitmask_1[hw_channel]))
  {
    wait_count++;
		if(wait_count > 100)
		{
			dht_data[0] = dht_data[1] = dht_data[2] = dht_data[3] = 0; // Delete previous sample
#ifdef DEBUG_H_
			dht_data[4] = 0xFF; // Something went wrong (for debug readability only)
#endif
      return 2; // Error: DHT HIGH Response Timeout
		}
  }

  // Sample 40 bits, timeout after last bit ensures that sensor has ended transmission
  // DHT pulls bus low after 40bits, this will be sampled as 1, then Low timeout at bit 41
  for (bit_count = 0; bit_count<40; bit_count++)
  {
#ifdef DEBUG_H_
P0_4 = 1;
#endif
    // Wait for falling edge, start of next bit
    wait_count = 0;
    while (P0 &bitmask_1[hw_channel])
    {
      wait_count++;
      if(wait_count > 100) return 3;   // Error, "DHT Bit %d Falling Edge Timeout\n", bit_count
    }
#ifdef DEBUG_H_
P0_4 = 0;
P0_5 = 1;
#endif
		// Wait for rising edge, sample length. 26-28us = 0, 70us = 1
		wait_count = 0;
    while (!(P0 &bitmask_1[hw_channel]))
    {
      wait_count++;
      if(wait_count > 100) return 4;   // Error, "DHT Bit %d Timeout\n", bit_count
    }
#ifdef DEBUG_H_
P0_5 = 0;
#endif
    // Wait at least 28uS
    for (t = 0; t < DELAY_CONST_1WIRE_DHT_MASTER_1; t++) ;

#ifdef DEBUG_H_
P0_6 = 1;
#endif
    // Sample current bit
    if (P0 &bitmask_1[hw_channel])
      dht_data[bit_count/8] |= (1<<(7-(bit_count%8)));
    else
      dht_data[bit_count/8] &= ~(1<<(7-(bit_count%8)));
#ifdef DEBUG_H_
P0_6 = 0;
#endif
  }

  // After 40bits the transmission should be done
  // Sensor pulls bus low to indicate stop and will release it --> timeout if OK
  for (bit_count = 0; bit_count<2; bit_count++)
  {
    // Wait for falling edge to indicate stop
    wait_count = 0;
    while (P0 &bitmask_1[hw_channel])
    {
      wait_count++;
      if(wait_count > 100)
      {
        //"DHT Stop detected after %d Falling Edge  ", bit_count
        if(bit_count) return 0;   // OK, timeout during second run
        else return 5;   // Stop pulse missing
      }
    }

    // Wait for bus release
    while (!(P0 &bitmask_1[hw_channel]))
    {
      wait_count++;
      if(wait_count > 100) return 6;   // Error, "DHT Bus release %d Timeout\n", bit_count

    }
  }
  return 7;   // Got too many bits
}

#endif

