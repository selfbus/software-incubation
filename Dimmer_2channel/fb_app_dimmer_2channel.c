/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2011 Andreas Krieger
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 * 	Steuereinheit 3fach REG
 * 	2193REG
*/




#include <P89LPC922.h>
#include "../lib_lpc922/Releases/fb_lpc922_1.4x.h"
#include  "fb_app_dimmer_2channel.h"

#include "../com/fb_rs232.h"
#include "fb_i2c.h"
#define ledpwm

__data __at (00) RAM[];
__data __at (0x25)  unsigned char portbuffer;	// Zwischenspeicherung der Portzustände
__bit __at(0x28)M1;// bitadresse 0x28 ist byteadresse 0x25_0 (portbuffer_4)
__bit __at(0x29)M2;
__bit __at(0x2A)M3;
__bit __at(0x2B)M4;
__bit __at(0x2C)A1;// bitadresse 0x2C ist byteadresse 0x25_4 (portbuffer_4)
__bit __at(0x2D)A2;
__bit __at(0x2E)A3;
__bit __at(0x2F)A4;
__bit __at(0x40)S_1;// Die Sperren bitadressen für byte 0x28
__bit __at(0x41)S_2;
//__bit __at(0x42)S_3;
__bit __at(0x44)SM_1;// Die Sperrmerker
__bit __at(0x45)SM_2;
//__bit __at(0x46)SM_3;
__bit __at(0x20)dimmcompare_0;
__bit __at(0x21)dimmcompare_1;
__data __at (0x24) unsigned char dimmcompare;
__data __at (0x26) unsigned char schalten;
__data __at (0x27) unsigned char rueckmelden;
__data __at (0x28) unsigned char sperren;
__data __at (0x08) unsigned char dimmen[2];
__data __at (0x0B) unsigned char dimmziel[2];
__data __at (0x0E) unsigned char grundhelligkeit[2];
__data __at (0x11) unsigned char helligkeit[2];// 0E
__data __at (0x14) unsigned char lz[2];
__data __at (0x17) unsigned char dimmwert[2];//12
__data __at (0x1A) unsigned char dimmpwm[3];//14
 unsigned char helligkeit_RM[2];
 unsigned char kurzschluss;
 unsigned char lastausfall;


unsigned char ctaste;    //zähler für Taste welche gerade abgefragt wird
unsigned char mtaste[8]; //merker Taste mit zähler (Tastenprllung und langer tastendruck)  1-8 =tasten
 
unsigned char mk[2];
unsigned char aushell[2];
unsigned char timerstart[2];
unsigned char timerstate[2];
//unsigned char dimmtimervorteiler;
unsigned char timerbase[TIMERANZ];// Speicherplatz für die Zeitbasis und 4 status bits
unsigned char timercnt[TIMERANZ];// speicherplatz für den timercounter und 1 status bit


unsigned int timer;		// Timer für Schaltverzögerungen, wird alle 250µs hochgezählt


unsigned char Tval;

unsigned char oldportbuffer;// Wert von portbuffer vor Änderung (war früher ...0x29)

const unsigned char grundhelligkeit_tabelle[]={15,30,46,61,77,92,107,127};
const unsigned char prozentvalue[]={25,51,75,102,128,154,179,204,230,255};

const unsigned int timerflagmask[]={0x0000,0x0000,0x0008,0x0080,0x0800,0x8000};
const unsigned char bitmask_1[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
const unsigned char bitmask_0[]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};
const unsigned char bitmask_11[]={11,22,44,88};

//__bit sync_blocked;		// Sperrung der Syncronisation

__bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszuführen
__bit portchanged;


/*+++++++++++  Auto reload interrupt TIMER 0 ++++++++++++++++ 
* zählt dimmcompare stetig hoch(überlauf)
* zählt dimmtimervorteiler hoch. (wird in main zurückgerechnet)
* schaltet P0_0 - P0_3 je nach dimmwert[pin] und schaltmerker A1-3  ein/aus
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void timer0_int  (void) interrupt 1 {// Interrupt T0 für soft PWM LED

  dimmcompare++;
  dimmtimervorteiler++;
  TF0=0;

  if (dimmcompare==0){
  {
     if (dimmpwm[0]!=0 ) P0_0 = 1;
     if (dimmpwm[1]!=0 ) P0_1 = 1;
     if (dimmpwm[2]!=0 ) P0_2 = 1;
    // if (dimmpwm[0]!=0 && A1) P0_0 = 1;
    // if (dimmpwm[1]!=0 && A2) P0_1 = 1;
    // if (dimmpwm[2]!=0 && A3) P0_2 = 1;
     if (dimmpwm[3]!=0 ) P0_3 = 1;
  }

  if (dimmcompare !=255)
  {
     if (dimmcompare==dimmpwm[0]) P0_0=0;
     if (dimmcompare==dimmpwm[1]) P0_1=0;
     if (dimmcompare==dimmpwm[2]) P0_2=0;
     if (dimmcompare==dimmpwm[3]) P0_3=0;
  }
}
}
*/
// Synconisation des Netzes
void ext0int(void) __interrupt (0){ //Interrupt ext0int für Netzsyncronisierung
/*	unsigned syncval=dimmcompare-19;
	IE0=0; // flankengesteuert???
	if (syncval>=128)syncval++;
	else syncval--;	//A5;//A2
	dimmcompare=syncval+19;
	
*/
#ifdef einkanal	
	__asm
	mov a,_dimmcompare	;dimmcompare in den akku
	subb a,#19;
		jz $00001			; wenn 0 dann nichts machen
		jb acc.7,$00002		; wenn kleiner 128 dann...
		jnb acc.1,$00003	; wenn >1 dann 2 zusätzlich erniedrigen
		dec a
		dec a
$00003:	dec a	;erniedrigen um auf 0 zu kommen
		sjmp $00001			;
$00002:	jb acc.1,$00004		;wenn < 0-1 dann 2 zusätzlich erhöhen
		inc a
		inc a
$00004:	inc a	;sonst erhöhen um auf 0 zu kommen
$00001:	add a,#19
		mov _dimmcompare,a
		__endasm;	
#else
		dimmcompare=61;// 19
#endif
}

/*
void timer0_int  (void) __interrupt (1) {// Interrupt T0 für abschnitt zeit= 10ms/256
	dimmcompare++;
//  dimmtimervorteiler++;
  TF0=0;
  // Diese variante mit festen Arraypointern ist die schnellste.
#ifdef ledpwm 
 	if ((dimmcompare<=dimmpwm[0]))P0_0=1;
  	else P0_0=0;
	#ifndef einkanal
	  	if ((dimmcompare<=dimmpwm[1]))P0_1=1;
		else P0_1=0;
	#endif	 
#else 
	if ((dimmcompare<=dimmpwm[0]))P0_0=0;
  	else P0_0=1;
	#ifndef einkanal
	  	if ((dimmcompare<=dimmpwm[1]))P0_1=0;
		else P0_1=1;
	#endif
#endif
} // timer0_int
*/

void timer0_int(void) __interrupt (1)         //n=nummer 0x03+8*n
{

  TL0=0x09;     // timer mit H=0xf9 L=0x09 2KHz = 0,5ms
  TH0=0xf9;     // timer mit 0xb7 200HZ = 5ms

  tastenauswertung();
    P0_3=(dimmpwm[0])?1:0;     //LED_zeile K1
    if(dimmpwm[0]>75) P0_2=1;
    else P0_2=0;
    if(dimmpwm[0]>125) P0_1=1;
    else P0_1=0;
    if(dimmpwm[0]>220) P0_0=1;
    else P0_0=0;

    P0_7=(dimmpwm[1])?1:0;     //LED_zeile K2
    if(dimmpwm[1]>75) P0_6=1;
    else P0_6=0;
    if(dimmpwm[1]>125) P0_5=1;
    else P0_5=0;
    if(dimmpwm[1]>220) P0_4=1;
    else P0_4=0;

  /*if(ie<40000)                   //interwallmäsiges senden kann evetuel raus
    ++ie;
   else
    {
    i2c_send_daten(dimm_I2C[0],dimm_I2C[1]);
    ie=0;
    }
	*/

    if(dimmpwm[0]!=mk[0]||dimmpwm[1]!=mk[1])   //i2c übertragen
     {
/*      //zum Testen rs232 Ausgabe
       rs_send_s("D=");//Dimmwert
       rs_send_hex(dimm_I2C[0]);
       rs_send(' ');
       rs_send_hex(dimm_I2C[1]);
       rs_send_s("\n");
*/
 //      ie=0;
       mk[0]=dimmpwm[0];
       mk[1]=dimmpwm[1];
       i2c_send_daten(dimmpwm[0],dimmpwm[1]);
     }
}


void tastenauswertung(void)
{
  unsigned char retp0=P0;//port 0 merken
  P3_0=0;                //SCL damit i2c nicht meckert
  P0=0;
  if(ctaste<6)           //0 bis 5
    ctaste++;
  else ctaste=0;
  P0M1=~(1<<ctaste);    // Port 0  PIN Output
  P0M2=(1<<ctaste);
  P0=~(1<<ctaste);      //nur eine Taste aktivieren
  if(P1_3==0)           //abfrage Taste getrückt
    {
      if(mtaste[ctaste]<254)  mtaste[ctaste]++;
      if(mtaste[ctaste]==200) //langer tastendruck
        {
          if(ctaste==1)
            dimmen[0]=9;
          if(ctaste==2)
            dimmen[0]=1;
          if(ctaste==5)
            dimmen[1]=9;
          if(ctaste==6)
            dimmen[1]=1;
        }

     }
  else
    {
      if(mtaste[ctaste]>20)
        {
          if(mtaste[ctaste]>20&&mtaste[ctaste]<200) //kurzer tastendruck mit Tastenprellung
            {
              if(ctaste==1) object_schalten(0,1);
              if(ctaste==2) object_schalten(0,0);
              if(ctaste==5) object_schalten(1,1);
              if(ctaste==6) object_schalten(1,0);
            }
          if(mtaste[ctaste]>199) //langer tastendruck
            if(ctaste==1||ctaste==2)
              dimmen[0]=0;
            if(ctaste==5||ctaste==6)
              dimmen[1]=0;
        }
      mtaste[ctaste]=0;
    }
  P0=retp0;
  //wieder auf eingang stellen
  P0M1=0x00;    //ee   // Port 0  PIN 0 und 4 Output
  P0M2=0xFF;    //11
  P3_1=1;       //SDA damit i2c nicht meckert
  P3_0=1;       //SCL damit i2c nicht meckert


}

void write_value_req(unsigned char objno)	// Objekte steuern gemäß EIS  Protokoll (an/aus/dimm/set)
{
  unsigned char obj,Dimmschritt,valtmp,tmp;

          obj=objno%2;// modulo 3 ergibt die Kanalnummer
          valtmp=telegramm[7]&0x0F;

          // Objektbehandlung:
         if((objno<10 || objno>11)&&(!(sperren & bitmask_1[obj]))){ // alles ausser Sperren.. und wenn nicht gesperrt
          //############################################################
          if ((objno<2)&&(!(sperren & bitmask_1[obj+4]))){	// Objekt 0-2 Schaltobjekt nicht bei Sperrmerker schalten
        	  object_schalten(objno,valtmp);	// Objektnummer 0-2 entspricht den Ausgängen 1-3
          }
          //############################################################
          if (objno>1 && objno<4)	// Objektnummer 2,3 Dimmen
          {
            write_obj_value(objno,valtmp);
            Dimmschritt = 255>>((valtmp&0x07)-1);
            //obj=objno-3;
            if (valtmp&0x07){// wenn gedimmt werden soll,Zeit laden
                if (valtmp&0x08){//aufwärts dimmen
                	if(dimmwert[obj]<=(255-Dimmschritt)){
                		dimmziel[obj]=dimmwert[obj]+Dimmschritt;
                	}
                	else dimmziel[obj]=255;
                }
                else{	//abwärts dimmen
                	if(dimmwert[obj]>=(Dimmschritt + grundhelligkeit[obj])){
                		dimmziel[obj]=dimmwert[obj] - Dimmschritt;
                	}
                	else dimmziel[obj]=grundhelligkeit[obj];
                }
            	
            	if (!obj){// Dimmobjekt 2
	                timerbase[0]=(eeprom[0xc6])&0x07;
	            }
	            else{		// Dimmobjekt 3
		               	timerbase[1]=((eeprom[0xc6]>>4)&0x07);	
		        }    
	            timerstart[obj]=eeprom[0xc8+obj];
	            
            }
            else{			// dimmen: stop!
            	//valtmp hier mit Parameter laden
            	if(!obj){// 			A1: Parameter Ausschaltfunktion holen
            		valtmp=eeprom[0xCE]&0x0F;
            	}
            	else {	//A2: Parameter Ausschaltfunktion holen
           			valtmp=eeprom[0xCE]>>4;
            	}
            	if((valtmp&0x08)&&(dimmziel[obj] < dimmwert[obj])){//	 schauen ob Ausschaltfunktion aktiviert
            		if(dimmwert[obj] < eeprom[0xCB + obj]){// wenn dimmwert<parameter..
            			timercnt[objno] = eeprom[0xCF + obj];//faktor laden
            			timerbase[objno] = valtmp&0x07;// base laden
            			timerstate[obj] |= 0x01;// status aus verz setzen.
            		}//ende if(dimmwert...
            	}// ende if((valtmp...
            	dimmziel[obj]=dimmwert[obj];
            }// ende bei stop!
          }// ende if (objno>)..Dimmen
          //####################################################################
          // ++++ Helligkeit +++++
          
          if (objno>3 && objno<6)	// Objektnummer 4,5 Helligkeit
          {
        	  write_obj_value(objno, telegramm[8]);
        	  hell_stellen(obj,telegramm[8]);
          }// ende if (objno ..
        } // ende alles ausser sperren

         //#############################################################
         //++++++ Lichtszenen +++++++
         //
         // LZ werden extra behandelt da sie auch bei Sperrmerker gesperrt sind
         //
        if (objno>11 && objno<14 && (!(sperren&(bitmask_11[obj])))){
       	valtmp=telegramm[8];
       	if((valtmp&0x7F)< 8){//Nur 8 LZ möglich
	        	write_obj_value(objno,valtmp);
	        	if (valtmp & 0x80){// LZ speichern tele
	    			EA=0;		// Interrupts sperren, damit flashen nicht unterbrochen wird
	    			START_WRITECYCLE
	    			WRITE_BYTE(0x01,0xE7+(valtmp&0x07)+(obj*8),dimmwert[obj])
	    			STOP_WRITECYCLE // Lichtszene speichern
	    			EA=1;
	        	}
	        	else{ // normales LZ tele
	        	tmp=eeprom[0xE7+(obj*8)+ (valtmp&0x07)];
	        	hell_stellen(obj,tmp);	
	        	}
       	}// ende if(((valtmp&0x07)<8....nur 8 LZ	
         }// ende if(objno>14... Lichtszene
         //
         //
         //###########################################################
          //
          //++++++ Sperren +++++++++++
          // pol.: 0xC3 bit 3,4,5: beginn:0xDF,E0,E1 je 0-3 Ende:0xDF,E0,E1 je 4-7
        if(objno>9 && objno<12){
        	  //obj=objno-12;
        	  //write_obj_value(objno,valtmp&0x01);
        	  //tmp=0;
        	  if(((valtmp&0x01)^(eeprom[0xC3]& bitmask_1[obj+3]))&& !(sperren & bitmask_1[obj])){//bit 3,4,5 polarität, Beginn Sperre(flanke)
        		  tmp=eeprom[0xDF+obj];//Parameter verhalten bei Sperrbeginn
        		  if((tmp>>4)==14) sperren|=bitmask_1[obj+4];//Nur Sperrmerker setzen da nachgeführt werden darf/soll
        		  else sperren|=bitmask_1[obj];// Objekte sperren(Sperre setzen)
        		  tmp &= 0x0F;
        		  dimmpwm[obj]=sperrvalue(tmp,obj);
        	  }// ende beginn Sperre
        	  if(((valtmp&0x01)^(eeprom[0xC3]& bitmask_1[obj+3]))&& (sperren & bitmask_1[obj])){	// Ende Sperre (flanke)
        		  tmp=eeprom[0xDF+obj]>>4;//Parameter Verhalten bei SPerrende
        		  sperren &= bitmask_0[obj];// Sperre löschen
        		  sperren &= bitmask_0[obj+4];//Sperrmerker löschen
        		  if (tmp==14) valtmp=dimmwert[obj];//nachgeführten Wert übernehmen
        		  else valtmp=sperrvalue(tmp,obj);
        		  dimmziel[obj]=valtmp;
    			  dimmwert[obj]=valtmp;
        	  }// ende ende Sperre
         } //   ende  sperrobjekt
          //###########################################################
      if (portbuffer&0xF0 != oldportbuffer&0xF0) portchanged=1;//post für port_schalten hinterlegen

}
unsigned char sperrvalue(unsigned char index,unsigned char obj){
	unsigned char retval=0;
	// Dimmwert beginn-ende aus Dimmwerttabelle holen
	if(index==1)retval=grundhelligkeit[obj];
	if (index>1 && index<12)retval=prozentvalue[index-2];
	if (index==12)retval=dimmwert[obj];
 	if (index==13){
 		if (aushell[obj]>=grundhelligkeit[obj])retval=aushell[obj];// gespeicherte Helligkeit falls nicht kleiner 
 		else retval=grundhelligkeit[obj];							// Grundhelligkeit
 	}

	return retval;
}


void hell_stellen (unsigned char obj,unsigned char value){
    // parameter für andimmen holen

	if (!obj){					// Helligkeit 4
        timerbase[0]=(eeprom[0xc6])&0x0F;
    }
    else{						// Helligkeit 5
           	timerbase[1]=((eeprom[0xc6]>>4)&0x0F);	
        }
	//eventuell auto EIN
	if (value){// wenn Helligkeit >0
		portbuffer|=bitmask_1[obj+4];// einschalten
		portchanged=1;
		schalten|=bitmask_1[obj];//write_obj_value(obj,1);// schaltobjekte setzen
		if (value>=grundhelligkeit[obj]){
	   		dimmziel[obj]=value;
		}
		else{
			dimmziel[obj]=grundhelligkeit[obj];//Helligkeitswert minimal grundhelligkeit setzen..
		}
	}
	else{// bei Helligkeit=0
		dimmziel[obj]=0;
		portbuffer|=bitmask_1[obj];// ausschalten merken
		portchanged=1;
		schalten&=bitmask_0[obj];// schaltobjekte rücksetzen
	}
	
	if (timerbase[obj]&0x08){	//anspringen
		dimmwert[obj]=dimmziel[obj];
	}
 	else{ //andimmen
        timerstart[obj]=eeprom[0xc8+obj];    
 	}    

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
	send_obj_value(objno+64);	
}


unsigned long read_obj_value(unsigned char objno)	// gibt den Wert eines Objektes zurueck
{
	unsigned char ret_val=0,obj;
	obj = objno % 2;
	if(objno<2) {
		if(schalten & bitmask_1[obj]) ret_val=1;
	}
	if(objno>=2 && objno<4) {
		ret_val = dimmen[obj];
	}
	if(objno>=4 && objno<6) {
		ret_val = helligkeit[obj];
	}
	if(objno>=6 && objno <8) {
		if(rueckmelden &(bitmask_1[obj])) ret_val=1;
	}
	if(objno>=8 && objno<10) {
		ret_val = helligkeit_RM[obj];
	}
	if(objno>=10 && objno <12) {
		if(sperren &(bitmask_1[obj])) ret_val=1;
	}
	if(objno>=12 && objno <14) {
		ret_val= lz[obj];
	}
	if(objno>=14 && objno <16) {
		if(kurzschluss &(bitmask_1[obj])) ret_val=1;
	}
	if(objno>=16 && objno <18) {
		if(lastausfall &(bitmask_1[obj])) ret_val=1;
	}
	
	return(ret_val);
}


void write_obj_value(unsigned char objno,unsigned int objvalue)	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
{
unsigned char obj;
	obj = objno % 2;
	if(objno<2) {
		if(objvalue==0) schalten &= bitmask_0[obj];
		else schalten |= bitmask_1[obj];
	}
	if(objno>=2 && objno<4) {
		dimmen[obj]=objvalue;
	}
	if(objno>=4 && objno<6) {
		helligkeit[obj]=objvalue;
	}
	if(objno>=6 && objno <8) {
		if(objvalue==0) rueckmelden &= bitmask_0[obj];
		else rueckmelden|=bitmask_1[obj];
	}
	if(objno>=8 && objno<10) {
		helligkeit_RM[obj]=objvalue;
	}
	if(objno>=10 && objno <12) {
		if(objvalue==0) sperren &= bitmask_0[obj];
		else sperren |= bitmask_1[obj];
	}
	if(objno>=12 && objno <14) {
		lz[obj]=objvalue;
	}
	

}






void object_schalten(unsigned char objno, __bit objstate)	// Schaltet einen Ausgang gemäß objstate und den zugörigen Parametern
{
unsigned char obj;
	obj=objno&0x0F;
	switch (obj){
	case 0:
		//A1=objstate;// Kanal 0
		if(objstate){// wenn "ein" tele war
			timerbase[0]=eeprom[0xD2]&0x07;//zeiten soft "ein"
			timerstart[0]=eeprom[0xD3];
			A1=1;
			if(eeprom[0xDA]&0x08){// Zeitdimmer aktiviert
				timerbase[3]=eeprom[0xDA]&0x07;
				timercnt[3]=eeprom[0xDC];
				timerstate[0]|=0x02;
			}
		}
		else {// wenn "aus" tele war
			timerstate[0]&=0xFD;// timerstate Zeitdimmer löschen
			timerstart[0]=eeprom[0xD7];//soft "aus"
			if(timerstart[0]){
				timerbase[0]=eeprom[0xD6]&0x07;
				M1=1;
			}
			else A1=0;
		}
		break;
	case 1:
		//A2=objstate;// Kanal 1
		if(objstate){
			timerbase[1]=eeprom[0xD2]>>4;// soft "ein"
			timerstart[1]=eeprom[0xD4];
			A2=1;
			if(eeprom[0xDA]&0x80){// Zeitdimmer aktiviert
				timerbase[4]=(eeprom[0xDA]>>4)&0x07;
				timercnt[4]=eeprom[0xDD];
				timerstate[1]|=0x02;
			}
		}
		else {
			timerstate[1]&=0xFD;// timerstate Zeitdimmer löschen
			timerstart[1]=eeprom[0xD8];// soft "aus"
			if (timerstart[1]){
				timerbase[1]=eeprom[0xD6]>>4;
				M2=1;
			}
			else A2=0;
		}
	break;
/*	case 2:
		//A3=objstate;
		if(objstate){
			timerbase[2]=eeprom[0xc7]>>4;
			timerstart[2]=eeprom[0xD5];
			A3=1;
			if(eeprom[0xDB]&0x08){// Zeitdimmer aktiviert
				timerbase[5]=eeprom[0xDB]&0x07;
				timercnt[5]=eeprom[0xDE];
				timerstate[2]|=0x02;
			}
		}
		else {
			timerstate[2]&=0xFD;// timerstate Zeitdimmer löschen
			timerstart[2]=eeprom[0xD9];
			if	(timerstart[2]){
				timerbase[2]=(eeprom[0xDB]>>4);
				M3=1;
			}
			else A3=0;
		}
	break;
*/	}
	A4=A1|A2;
//	A4|=A3;
	portchanged=1;
	//
	//portbuffer=(A1<<0 | A2<<1 | A3<<2 | A4<<3)<<4;
	if(objno<0x02){// Einschalten-Einschalthelligkeit
		 if ((objstate) && ((portbuffer& bitmask_1[obj])||(!(oldportbuffer& bitmask_1[obj+4])))) {//einschalten Flanke((timerbase[objno]&0x02)|| 	
			 read_dimmziel(objno,0xC4);		
				if (!timerstart[objno])dimmwert[objno]=dimmziel[objno];
				portbuffer &= bitmask_0[objno];// ausschaltmerker löschen
		 }  
		  if ((!objstate)&&(oldportbuffer & bitmask_1[obj+4])) {//ausschalten Flanke
			  aushell[objno]=dimmwert[objno];
			  if (timerstart[obj]){// wenn soft "AUS"
				  dimmziel[obj]=0;
			  }
			  else dimmwert[obj]=0;// sofort aus
		  }
	}
	if (objno&0x20){		// bei Bus return ist dimmziel[x] schon geladen
		if(objstate){
		if(!timerstart[obj])dimmwert[obj]=dimmziel[obj];//anspringen
		}
	}

}// ende obj_schalten



void delay_timer(void)	// zählt alle 0,5ms die Variable Timer hoch 
{
	unsigned char objno,n,m;
	unsigned int timerflags;
	objno;n;m;
#ifdef HAND		// für Handbetätigung
//	unsigned char n;
	unsigned char ledport;
	unsigned char Tasten=0;
#endif
	
	RTCCON=0x61;		// RTC starten

	//	objno=0;

		timer++;// wird alle 0.50ms aufgerufen
		timerflags = timer&(~(timer-1));
				for(m=0;m < TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
					if((timerbase[m]==1)||(timerflags & (timerflagmask[timerbase[m]]))){// wenn das flag mit der gespeicherten base übereinstimmt
						if (timercnt[m]){// wenn der counter läuft...
							timercnt[m]=timercnt[m]-1;// den timer [m]decrementieren
						}// end if (timercnt...
					}//end if(timerbase...
				}// end  for(m..
		
		// ab Hier die aktion...
		for (n=0;n<2;n++){// autoreload der Dimm Timer
			if(timerbase[n]){
				if(! timercnt[n]){
					timercnt[n]=timerstart[n];
					if (dimmziel[n]>dimmwert[n]){ //aufwärts
						dimmwert[n]++;
						if(dimmwert[n]<grundhelligkeit[n])dimmwert[n]=grundhelligkeit[n];// NEU TODO testen
					}
					if(dimmziel[n]<dimmwert[n]){  //abwärts
						dimmwert[n]--;
						if(dimmwert[n]<grundhelligkeit[n])dimmwert[n]=0;// NEU TODO testen
					}
				}// if (! timercnt...
			}//if(timerbase..
			if (portbuffer& bitmask_1[n]){// Merker für "Soft Aus"
				if (!dimmwert[n]){
					portbuffer&=(bitmask_0[n]); //M1...2 und Ausgang abschalten ausschalten
					portbuffer&=(bitmask_0[n+4]);
					portchanged=1;
				}
			}
		}
		for (n=3;n<5;n++){// Zeiten für Aktionen wie Ausschalten(zeitdimmer...
			m=n-3;		// und Ausschaltverzögerung)	
			if(!timercnt[n]){// wenn timer inaktiv oder abgelaufen
				if (timerstate[m]& 0x01){// state.0: Ausschalthelligkeit 
					portbuffer &= bitmask_0[m+4];//Ausgang abschalten
					portchanged=1;
					timerstate[m] &= 0xFE;//state löschen
				}
				if(timerstate[m]& 0x02){// wenn zeitdimmer aktiviert war und abgelaufen
					object_schalten(m,0);// ausschalten
					//state wird in object_schalten gelöscht
				}
			}
		if(!(sperren & bitmask_11[m])){
			dimmpwm[m]=dimmwert[m];	
			if (dimmpwm[m]){
				if(dimmpwm[m]<grundhelligkeit[m])// wenn Wert<Grundhell
					dimmpwm[m]=grundhelligkeit[m];// dann Grundhell
				}
			}
		}
		// Summenberechnung:
		//dimmpwm[3]=(dimmpwm[0]/3)+(dimmpwm[1]/3)+(dimmpwm[2]/3);
		//A4=A1|A2;
		//A4|=A3;



}






void port_schalten(void)		// Schaltet die Ports 
{
	unsigned char n, pattern,m;
	pattern;
	pattern=(portbuffer ^ oldportbuffer)>>4;
	schalten=portbuffer>>4;
	rueckmelden=schalten;
	//sendobj|=(pattern>>4);
	//Rückmeldung
	//sync_blocked=1;
	for(n=0;n<1;n++){//<3
		if(pattern&bitmask_1[n]){
			
			send_obj_value(n+6);
			for(m=0;m<30;m++) // verzögerung wegen ft1.2
				while(dimmcompare);
			}

	}
	//Ausgänge setzen
	P0|=(portbuffer&0xF0);		// Ports Ausgänge zuordnen
	P0&=(portbuffer|0x0F);

	portchanged=0;					//postvariable zurücksetzen
	oldportbuffer=portbuffer;

}





void bus_return(void)		// Aktionen bei Busspannungswiederkehr
{
	__bit bitval;
	unsigned char n,m;
	// Rückmeldung bei Busspannungswiederkehr
	for (n=6;n<8;n++) {
//		send_obj_value(n);
		for(m=0;m<30;m++){// verzögerung wegen ft1.2	30
			while(dimmcompare);
		}
	}
	//A1=1;A2=1;A3=1;A4=1;
	grundhelligkeit[0]=grundhelligkeit_tabelle[eeprom[0xc2]&0x07];
	grundhelligkeit[1]=grundhelligkeit_tabelle[((eeprom[0xc2]&0x70)>>4)&0x07];
// hier einschaltverhalten bei busreturn rein...
	portbuffer=0;
	oldportbuffer=portbuffer;
	for(n=0;n<2;n++){
		timerstate[n]=0;
		dimmwert[n]=0;
		read_dimmziel(n,0xE2);
		bitval=0;
		if (dimmziel[n]) bitval=1;
		object_schalten(n|0x20,bitval);
	}
}

void read_dimmziel(unsigned char n,unsigned char offset){
unsigned char valtmp,bw=0;
	
		if (!n)valtmp=eeprom[offset]&0x0F;//n=0
		else valtmp=(eeprom[offset]&0xF0)>>4;//n=1
		
		if (!valtmp)bw=0;
		if(valtmp==1 )bw=grundhelligkeit[n];
		if (valtmp>1&&valtmp<12)bw=prozentvalue[valtmp-2];
	    if (valtmp==13&& offset==0xC4){// nur bei Einschalthelligkeit, nicht bei busreturn TODO testen
	    	if (aushell[n]>=grundhelligkeit[n]) 	bw=aushell[n];
	    	else bw=grundhelligkeit[n];
	    }
	    dimmziel[n]=bw;
	
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen

{
	
	Tval=0x00;
	timer=0;			// Timer-Variable, wird alle 130ms inkrementiert
	
	P0M1=0xEE;            // Port 0 Modus push-pull für Ausgang nur PIN 0 und 4 Output
	P0M2=0x11;            // nur PIN 0 und 4 Output
	P0=0;
	
	ET0=0;			// Interrupt für Timer 0 sperren

 
	RTCCON=0x60;		// RTC anhalten und Flag löschen
	RTCH=0x00;			// reload Real Time Clock
	RTCL=0x1D;			//0.5ms laden
	RTCCON=0x61;		// RTC starten

	
	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	// set timer 0 autoreload 0.05ms
	TR0=0;
    //Timer0 einstellen
    TMOD&=0xf0;   //register für Timer 0 löschen
    TMOD|=0x01;   // Timer 0 als 16bit, Timer 1 nicht ändern !
    TAMOD&=0xf0;
    TH0 = 0xff;
    AUXR1&=~0x10;      // toggled whenever Timer0 overflows ausschalten
    ET0=1;             // Interrupt für Timer 0 freigeben
    TR0=1;             // Timer 0 starten


	
	
	
	
	// prirority bits in p0 byte;bit     7     6     5    4      3    2     1     0
	//IP0* Interrupt priority 0 B8H -          PWDRT PBO  PS/PSR PT1  PX1   PT0   PX0
	//IP0H Interrupt priority 0 HIGH B7H -     PWDRT PBOH PSH/   PT1H PX1H  PT0H  PX0H
	
	//IP1* Interrupt priority 1    F8H   PAD   PST   -    -      -    PC    PKBI  PI2C
//	IP1H Interrupt priority 1 HIGH F7H   PADH  PSTH  -    -      -    PCH   PKBIH PI2CH


	// set timer 0 isr priority to level 0, timer 1 level 1, ext0int level 2, ext1 level 3
#ifdef einkanal
	IP0 &= 0xF6; //FC		F6	für flackerfrei bei 1 kanal
	IP0 |= 0x06; //0C		06	dto.
#else
	IP0 &= 0xFC; //FC		F6	für flackerfrei bei 1 kanal
	IP0 |= 0x0C; //0C		06	dto.
#endif
//	IP0H &= 0xF5;// 
//	IP0H |= 0x05;// 		Timer 1 auf Level 2
	TF0=0; //timer0 flag löschen
	IT0=1;// int mode auf fallende Flanke
	ET0=1;// timer 0 interupt freigeben	
//	EX0=1;//ext int freigeben

	START_WRITECYCLE
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0008 = GIRA
	WRITE_BYTE(0x01,0x04,0x08)
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	STOP_WRITECYCLE

	EA=1;						// Interrupts freigeben
	

}// Ende restart app
