/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */



#include <P89LPC922.h>
#include "../lib_lpc922/fb_lpc922.h"
#include "../com/debug.h"
#include "fb_app_counter.h"
#include "../com/fb_rs232.h"

#ifdef IN8_2TE
#include "spi.h"
#endif


unsigned char portbuffer,p0h;
unsigned int objstate;		// Zwischenspeicher der Objektzustände x.1 (Bit 0-7) und x.2 (Bit 8-15)
unsigned const paraindex_timer[]={0xD6,0xD8,0xEC,0xEE}; 
unsigned const objno_timer[]={0,11,13,24}; 

unsigned char timer_base,timer_state;			// Timer für Schaltverzögerungen
unsigned char timer500;
unsigned char timer60;
unsigned char timerhour;
unsigned char timerday;
unsigned char timerflags;
unsigned char timerbase[TIMERANZ];// Speicherplatz für die Zeitbasis 
unsigned char timercnt[TIMERANZ];// speicherplatz für den timercounter und 1 status bit
//unsigned char timerstate[TIMERANZ];//
//unsigned char pinnoX4,para_adr;
unsigned char para_value;

unsigned long __at 0x08 counter_summe[4];
unsigned int  __at 0x18	counter_moment[4];
unsigned int bitobj_z1,bitobj_z2;
__bit objval=0,jobj=0;

__bit st_Flanke=0;

//unsigned char value[16];		
//__code unsigned char __at 0x1C00 userram[]={......
 volatile unsigned char precounter0;
 volatile unsigned char precounter1;
 volatile __bit counted0;
 volatile __bit counted1;


void keypad_isr  (void) __interrupt (7)
{
	unsigned char keybuffer;
  // clear interrupt flag
  KBCON = 0;//0xFE;
  keybuffer=P0;
  if(keybuffer&0x01 && !counted0){
	  precounter0++;
	  counted0=1;
  }
  if(!(keybuffer&0x01))counted0=0;

  if(keybuffer&0x04 && !counted1){
	  precounter1++;
	  counted1=1;
  }
  if(!(keybuffer&0x04))counted1=0;
  KBPATN=keybuffer;
}


void pin_changed(unsigned char pinno)
{

	unsigned char tmp;
	unsigned char objoffset,cno;
	unsigned char typ=0;
	unsigned char n,w;
	unsigned char deb_result;
	timer_base=0; tmp;
	para_value=0;
// Etwas warten wegen Entprellung
	for(n=0;n<250;n++){
		  	for(w=255;w>0;w--); 
	}// delay ca. 4,5µs
#ifndef IN8_2TE
  deb_result=((~(P0^p0h))& bitmask_1[pinno]);//ret=1;
#else
  deb_result=((~(spi_in_out()^p0h))& bitmask_1[pinno]);//ret=1;
#endif

  if (deb_result)			// Entprellzeit abwarten und prüfen
  {
	st_Flanke=(((portbuffer>>pinno)&0x01)==0) && (((p0h>>pinno)&0x01)==1);
	cno=(pinno&0x02);// counter nomber 0 0der 2
	objoffset=13*(cno>>1);
	if ((pinno==1)||(pinno==3)){
		write_obj_value(2+objoffset,st_Flanke);
		send_obj_value(2+objoffset);
	}
	
  }// end if (debounce)...

}// end function






int eis5conversion(unsigned long zahl)// wandelt 32 bit var in eis5 um
{
	unsigned char exp=0;
	 		while (zahl > 2047){//solange Mantisse größer 11 Bit
	 			zahl=zahl>>1;// Mantisse /2
	 			exp++;// und exponent um 1 erhöhen (ist ein 2^exp)
	 		}
	
 	return ((int)zahl+((int)exp<<11));// exponent dazu.
}

/** 
* zaehlt alle 100ms die  Timer hoch und prueft Eintraege
*
* \param void
* @return void
*/
void delay_timer(void)
{

	unsigned char  m,objno,n;



	RTCCON=0x61;//	 RTC flag löschen
	
	timerflags=0x01;//setzt das niedrigste bit 0  100ms base

	timer500++;// 500ms timer erhöhen

	if(timer500==5||timer500==10){
		timerflags|=0x02;//bit 1 500ms base
	}
	if(timer500>=10){
		timerflags|=0x04;//bit 2 1s base
		timer500=0;
		timer60++;
	}

	if(timer60>=60){	// bit 3 1min base
		timerflags|=0x08;
		timer60=0;
		timerhour++;
	}

	if((timerhour>=60)){	// bit 4 1hour base
		timerflags|=0x10;
		timerhour=0;
		timerday++;
	}
	if((timerday>=24)){	// bit 5 1day base
		timerflags|=0x20;
		timerday=0;
	}
	if(timerflags&0x02)checklevel(0,0xff);

	for(n=0;n<6;n++){
		if(timerflags & 0x01){// positive flags erzeugen und schieben
			for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
				if ((timerbase[m]& 0x0F)==n){// wenn die base mit der gespeicherten base übereinstimmt
					if (timercnt[m]>0x80){// wenn der counter läuft...
						timercnt[m]=timercnt[m]-1;// den timer[m]decrementieren
					}// end if (timercnt...
				}//end if(timerbase...
			}// end  for(m..
		}// end if timer...
		timerflags = timerflags>>1;
	}//end for (n=...

// Im folgenden die Aktionen bei abgelaufenen Timern
	
	for(objno=0;objno<4;objno++) {
		if(timercnt[objno]==0x80) {
			timercnt[objno]=eeprom[paraindex_timer[objno]];//Torzeit setzen
			timerbase[objno]=eeprom[paraindex_timer[objno]+1];
			if (!(objno&0x01))timerbase[objno]|= 0x80;// ;wenn Momentanwertzähler Löschung anfordern
			if (read_obj_value((((objno&0x02)>>1)*13)+2)==0){// aktiven Tarif holen 
				send_obj_value(objno_timer[objno]);// senden Tarif 1
				if (timerbase[objno]& 0x80)timerbase[objno]&= (~0x40);// wenn Löschung, dann tarif2 löschen rücksetzen
			}
			else{
				send_obj_value(objno_timer[objno]+1);// senden Tarif 2
				if (timerbase[objno]& 0x80)timerbase[objno]|= 0x40;// ;wenn Löschung, dann tarif2 löschen anfordern
 			}
		}// end if(timercnt...
	} // end for(objno...
}





void write_value_req(void)		// Objekt-Wert setzen gemäß empfangenem EIS Telegramms
{
	unsigned char objno,objflags,gapos,atp,assno,n,gaposh,tmp=0;
	unsigned char objtype;
	//unsigned long long_tmp;
	if(APPLICATION_RUN){
	    gapos=gapos_in_gat(telegramm[3],telegramm[4]);
	    if (gapos!=0xFF )	
	    {
	    	atp=eeprom[ASSOCTABPTR];		// Association Table Pointer
	    	assno=eeprom[atp];				// Erster Eintrag = Anzahl Einträge
	 
	    	for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
	    		gaposh=eeprom[atp+1+(n*2)];
	    		if(gapos==gaposh) {					// Wenn Positionsnummer übereinstimmt
	    			objno=eeprom[atp+2+(n*2)];			// Objektnummer
	    			objflags=read_objflags(objno);		// Objekt Flags lesen
	    			objtype=eeprom[eeprom[COMMSTABPTR]+objno*3+4];
	   			
	    			if((objflags&0x14)==0x14) {			// Kommunikation zulässig (Bit 2 = communication enable) + Schreiben zulässig (Bit 4 = write enable)
	    				if (objno<25) {					// Status der Eingangsobjekte 0-24
	    					if (objtype<=6){
	    						tmp=telegramm[7]& 0x3F; //bit 6+7 löschen (0x40,0x80)
		    					write_obj_value(objno,tmp);
		    				}
	    					if((objno==11 &&  bitobj_z1 & 0x40)||
	    					   (objno==12 &&  bitobj_z1 & 0x0100)||
	    					   (objno==24 &&  bitobj_z2 & 0x40)||
	    					   (objno==25 &&  bitobj_z2 & 0x0100)){
	    						//if (objtype==7)write_obj_value(objno,telegramm[8]);
			    				if (objtype==8)write_obj_value(objno,telegramm[9]+(telegramm[8]<<8));
			    			//	long_tmp = ;
			    				if (objtype==10)write_obj_value(objno,(unsigned int)(telegramm[11] | (telegramm[10] << 8)) |((unsigned long)(telegramm[9] | (telegramm[8] << 8)) << 16));//
	    					}
		    				if ( tmp!=0){// bei 'EIN' Tele
		    					if(objno==7)send_obj_value(11);// Anforderungen
		    					if(objno==9)send_obj_value(12);
		    					if(objno==20)send_obj_value(24);
		    					if(objno==22)send_obj_value(25);
		    					if(objno==8)write_obj_value(11,0);// löschungen
		    					if(objno==10)write_obj_value(12,0);
		    					if(objno==21)write_obj_value(24,0);
		    					if(objno==23)write_obj_value(25,0);
		    				}
	    				}
	    			}//ende if objflags...
	    		}//ende if gapos...
	    	}// ende for n=....
	    }// ende if gapos !=0
	}// ende if APPLIKATION
}// end function

void checklevel(__bit fullcheck,unsigned char check)// vergleiche Momentanwert mit Grenzwert
				// fullcheck ermöglicht ein vergleich auf: Zähler < Konstantwert
				//bit1 Zähler2, bit6(0x40)Tarif2
//e2,e4,f8,fa
{
	unsigned char ctg,c_paraptr,c_para,c_valptr,obj_counter,obj;
	unsigned int c_val;
	__bit checken;
	for (ctg=0;ctg<=7;ctg++){
		checken=1;
		if (ctg&0x04){// zähler 2
			obj_counter=13;
			c_paraptr=0xE9;
			c_valptr=0xF0;
			obj=16;
			if((check&0x02)==0)checken=0;
		}
		else {// zähler 1
			obj_counter=0;
			c_paraptr=0xD3;
			c_valptr=0xDA;
			obj=3;
			if(check&0x02)checken=0;
		}
		if(ctg&0x02){// tarif 2
			obj_counter+=1;
			c_paraptr++;
			c_valptr+=4;
			obj+=2;
			if(!(check&0x40))checken=0;
		}
		else {//tarif 1
			if(check & 0x40)checken=0;
		}

		c_para=eeprom[c_paraptr];
		if(ctg&0x01){
			c_para=c_para>>4;
			c_valptr+=2;// grenzwert 2
			obj++;
		}
		
		c_val=(unsigned int)((eeprom[c_valptr]<<8)+(eeprom[c_valptr+1]));//*(unsigned int)((eeprom[c_calc]<<8)+(eeprom[c_calc+1]));
		if((int)read_obj_value(obj_counter) > c_val){// überschreiten
			if(c_para & 0x03)sendbychange(obj,c_para&0x01);
		}
		if (fullcheck && checken){
			if((int)read_obj_value(obj_counter) < c_val){// unterschreiten
				if((c_para>>2)&0x03)sendbychange(obj,(c_para>>2)&0x01);
			}
		}
				

/*		if(counter_moment[ctg>>1] > c_val){// überschreiten
			if(c_para & 0x03)sendbychange(obj,c_para&0x01);
		}
		if (fullcheck && checken){
			if(counter_moment[ctg>>1] < c_val){// unterschreiten
				if((c_para>>2)&0x03)sendbychange(obj,(c_para>>2)&0x01);
			}
		}
		
*/	}
}



/** 
* Objektwert lesen wurde angefordert, read_value_response Telegramm zurücksenden
*
* 
* @return
* 
*/
void read_value_req(void)
{
	unsigned char objno, objflags;
	
	objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
	if(objno!=0xFF) {	// falls Gruppenadresse nicht gefunden
		
		//objvalue=read_obj_value(objno);		// Objektwert aus USER-RAM lesen (Standard Einstellung)


		
		objflags=read_objflags(objno);		// Objekt Flags lesen
		// Objekt lesen, nur wenn read enable gesetzt (Bit3) und Kommunikation zulaessig (Bit2)
		if((objflags&0x0C)==0x0C) send_obj_value(objno+0x40);// 0x40 ist bit für response Telegramm
    }
}


void sendbychange(unsigned char objno,unsigned char val){
	if (val){
			if(read_obj_value(objno)==0)write_send(objno,1);
			}
			else if( read_obj_value(objno))write_send(objno,0);
}

void write_send(unsigned char objno,unsigned int value){

	write_obj_value(objno,(unsigned long)value);
	send_obj_value(objno);
}


void bus_return(void){
	  //  ++++++++++++    Startverhalten bei Buswiederkehr ++++++++++
	//__bit objval=0;

	
	
}


unsigned long read_obj_value(unsigned char objno)
{
	unsigned long objvalue=0;
	unsigned char objtype,ctrno=0,para=0xD5;
	unsigned char calc_para_ptr=0;
	unsigned int tmp16;
	objtype=eeprom[eeprom[COMMSTABPTR]+objno*3+4];
	if (objno >=2 && objno <= 10){
		objvalue = ((bitobj_z1 >>(objno-2)) & 0x01);
		ctrno=1;
	}
	if (objno >=15 && objno <= 23){
		objvalue = ((bitobj_z2 >>(objno-15)) & 0x01);
		ctrno=1;
	}
	if(!ctrno){
		if (objno <= 1){
			ctrno=objno;//objvalue = counter_moment[objno]; Z1
			para=eeprom[0xD5]&0x0F;
			calc_para_ptr=0xE2;
		}
		if (objno>=11 && objno<=12){
			ctrno=objno-7;//objvalue = counter_summe[objno-11]; Z1
			para=eeprom[0xD5]>>4;
			calc_para_ptr=0xE4;
		}
		if (objno >= 13 && objno<=14){
			ctrno=objno-11;//objvalue = counter_moment[objno-11]; Z2
			para=eeprom[0xEB]&0x0F;
			calc_para_ptr=0xF8;
		}
		if (objno>=24 && objno<=25){
			ctrno=objno-18;//objvalue = counter_summe[objno-22]; Z2
			para=eeprom[0xEB]>>4;
			calc_para_ptr=0xFA;
		}
		if(ctrno<=3){// momentanzähler
			tmp16=(unsigned int)((eeprom[calc_para_ptr]<<8)+eeprom[calc_para_ptr+1]);
			if(tmp16!=0){
				objvalue=counter_moment[ctrno];//
				if(para==4&&counter_moment[ctrno]>120)objvalue=((unsigned int)(counter_moment[ctrno]+67));//für 3,33 sec. signed für Windmesser Eltako misbraucht
				//if(para==7)objvalue=(unsigned int)(counter_moment[ctrno]+2*tmp16)/3;
				if(para==8){//byte 0-100%
					if(counter_moment[ctrno]<= tmp16){
						objvalue = 256*(unsigned long)counter_moment[ctrno];
	                    objvalue-=counter_moment[ctrno];
					}
					else {
						objvalue=255;
						tmp16=1;
					}
				}
				if(para==9)objvalue = 100*(unsigned long)counter_moment[ctrno];//byte 0-255%
				objvalue /=tmp16;
				if(para==5)objvalue=eis5conversion(objvalue);//EIS5
				
/*				if((para!=8 &&  para!=9 ))	objvalue = counter_moment[ctrno]/tmp16;
				
				switch(para){
				case 5://EIS5
					objvalue=eis5conversion(objvalue);
				break;
				case 8://byte 0-100%
				if(counter_moment[ctrno]<= tmp16){
					objvalue = 256*(unsigned long)counter_moment[ctrno];
                    objvalue-=counter_moment[ctrno];
                    objvalue/=tmp16;
				}
				else objvalue=255;
				break;
				case 9://byte 0-255%
					objvalue = 100*(unsigned long)counter_moment[ctrno]/tmp16;//(unsigned int)((eeprom[calc_para_ptr]<<8)+eeprom[calc_para_ptr+1]);			break;
				default:
				break;
				}
*/			}	
		}
		else{		// Summenzähler
		objvalue=counter_summe[ctrno-4]/(unsigned int)(eeprom[calc_para_ptr+3] | (eeprom[calc_para_ptr+2] << 8)) |((unsigned long)(eeprom[calc_para_ptr+1] | (eeprom[calc_para_ptr] << 8)) << 16);
			 switch(para){
			case 2:
				objvalue=0;
			break;
			case 5:
				objvalue=eis5conversion(objvalue);
			break;
			default:
			}
		}
	}
	return(objvalue);
}



void write_obj_value(unsigned char objno,unsigned long objvalue)
{
	unsigned char objtype;
	
	objtype=eeprom[eeprom[COMMSTABPTR]+objno*3+4];
	
	if (objno <= 1)counter_moment[objno]=objvalue;
	if (objno >=2 && objno <= 10)
	{
		bitobj_z1 &= ~(0x01<<(objno-2));
		bitobj_z1 |= ((objvalue&0x01)<<(objno-2));
	}
	if (objno>=11 && objno<=12)counter_summe[objno-11]=objvalue;
	if (objno >= 13 && objno<=14)counter_moment[objno-11]=objvalue;
	if (objno >=15 && objno <= 23)
	{
		bitobj_z2 &= ~(0x01<<(objno-15));
		bitobj_z2 |= ((objvalue&0x01)<<(objno-15));
	}
	if (objno>=24 && objno<=25)counter_summe[objno-22]=objvalue;
	

}

void keypad_init  (void)// Eingänge 0,2 Zähler. Eingänge 1,3 Tarifumschaltung
{
  // define pattern
  KBPATN = 0x00;
  // define P0 pins that trigger interrupt
  KBMASK = 0x05;
  // pattern must different
  KBCON = 0x00;

  // set isr priority to 0
  IP1 &= 0xFD;
  IP1H &= 0xFD;

  // enable keypad interrupt
  EKBI = 1;
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{

unsigned char objno;

#ifndef IN8_2TE
	P0M1=0x0F;	//P0 auf input only (high impedance!)
	P0M2=0x00;
	P0=0xFF;
#else
	P0M1=0x00;	// P0_1 Biderektional, Rest PushPull
	P0M2=0xFD;
	P0=0x22;	// WRITE=1 SER_IN=1
#endif

  transparency=0;

  RTCCON=0x60;		// RTC anhalten und Flag löschen
  RTCH=0x16;			//16 reload Real Time Clock
  RTCL=0x80;			//80 auf 100ms
  RTCCON=0x61;//	START_RTC	// RTC starten

  EA=0; 
  START_WRITECYCLE
  WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x00B4 = VELUX
  WRITE_BYTE(0x01,0x04,0xB4)
  WRITE_BYTE(0x01,0x05,0x04)	// Geräte Typ (2118) 04B0h
  WRITE_BYTE(0x01,0x06,0xB0)  // 	"	"	"
  WRITE_BYTE(0x01,0x07,0x01)	// Versionsnummer
  WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
  WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
  WRITE_BYTE(0x01,0x12,0x82)	// COMMSTAB Pointer
  STOP_WRITECYCLE


  EA=1;
  
	for(objno=0;objno<4;objno++) {// zyclisch senden setzen
				timercnt[objno]=eeprom[paraindex_timer[objno]];//Torzeit bzw timer setzen
      			timerbase[objno]=eeprom[paraindex_timer[objno]+1];// Basis setzen
	} // end for(objno...

}
