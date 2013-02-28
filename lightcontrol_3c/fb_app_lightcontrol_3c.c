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
#include "../lib_lpc922/fb_lpc922.h"
#include  "fb_app_lightcontrol_3c.h"

#include "../com/fb_rs232.h"
__data __at (0x25)  unsigned char portbuffer;	// Zwischenspeicherung der Portzustände
__bit __at(0x28)M1;// bitadresse 0x28 ist byteadresse 0x25_0 (portbuffer_0)
__bit __at(0x29)M2;
__bit __at(0x2A)M3;
__bit __at(0x2B)M4;
__bit __at(0x2C)A1;// bitadresse 0x2C ist byteadresse 0x25_4 (portbuffer_4)
__bit __at(0x2D)A2;
__bit __at(0x2E)A3;
__bit __at(0x2F)A4;
__bit __at(0x40)S_1;// Die Sperren bitadressen für byte 0x28
__bit __at(0x41)S_2;
__bit __at(0x42)S_3;
__bit __at(0x44)SM_1;// Die Sperrmerker
__bit __at(0x45)SM_2;
__bit __at(0x46)SM_3;

__data __at (0x26) unsigned char schalten;
__data __at (0x27) unsigned char rueckmelden;
__data __at (0x28) unsigned char sperren;
//unsigned char dimmwert[4];
__data __at (0x08) unsigned char dimmen[3];
__data __at	(0x0B) unsigned char dimmziel[3];
__data __at (0x0E) unsigned char grundhelligkeit[3];
__data __at (0x11) unsigned char helligkeit[3];
__data __at (0x14) unsigned char lz[3];
__data __at (0x17) unsigned char dimmwert[3];
__data __at (0x1A) unsigned char dimmpwm[4];
unsigned char aushell[3];
unsigned char timerstart[3];
unsigned char timerstate[3];
unsigned char dimmtimervorteiler;
unsigned char timerbase[TIMERANZ];// Speicherplatz für die Zeitbasis und 4 status bits
unsigned char timercnt[TIMERANZ];// speicherplatz für den timercounter und 1 status bit


unsigned int timer;		// Timer für Schaltverzögerungen, wird alle 250µs hochgezählt


unsigned char Tval,dimmcompare;
unsigned char out_state;	// Werte der Objekte 0-7 (Ausgängsobjekte)
unsigned char rm_state;		// Werte der Objekte 12-19 (Rückmeldeobjekte)
unsigned char zf_state;		// Werte der Objekte 8-11 (Zusatzfunktionen 1-4)

unsigned char oldportbuffer;// Wert von portbuffer vor Änderung (war früher ...0x29)
unsigned char blocked;		// Sperrung der 8 Ausgänge (1=gesperrt)
unsigned char logicstate;	// Zustand der Verknüpfungen pro Ausgang


__bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszuführen
__bit portchanged;



const unsigned char grundhelligkeit_tabelle[]={15,30,46,61,77,92,107,127};
const unsigned char prozentvalue[]={25,51,75,102,128,154,179,204,230,255};

const unsigned int timerflagmask[]={0x0000,0x0000,0x0008,0x0080,0x0800,0x8000};
const unsigned char bitmask_1[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
const unsigned char bitmask_0[]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};
const unsigned char bitmask_11[]={11,22,44,88};

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

void timer0_int  (void) __interrupt (1) {// Interrupt T0 für soft PWM LED
  dimmcompare++;
  dimmtimervorteiler++;
  TF0=0;
  // Diese variante mit festen Arraypointern ist die schnellste.
  if ((dimmcompare<=dimmpwm[0])&& A1)P0_0=1;
  else P0_0=0;
  if ((dimmcompare<=dimmpwm[1])&& A2)P0_1=1;
  else P0_1=0;
  if ((dimmcompare<=dimmpwm[2])&& A3)P0_2=1;
  else P0_2=0;
  if (dimmcompare<=dimmpwm[3])P0_3=1;
  else P0_3=0;

} // timer0_int



void write_value_req(void)	// Objekte steuern gemäß EIS  Protokoll (an/aus/dimm/set)
{
  unsigned char objno,objflags,assno,n,gaposh,valtmp,tmp;//,zfout,zftyp;
  //unsigned char blockstart, blockend, block_polarity;
  unsigned char obj,Dimmschritt;//, zf_bitpattern;

  //  unsigned int ui_tmp;
    gaposh=0;

    //gapos=gapos_in_gat(telegramm[3],telegramm[4]);	// Position der Gruppenadresse in der Adresstabelle
    if (gapos_in_gat(telegramm[3],telegramm[4])!=0xFF)					// =0xFF falls nicht vorhanden
    {
	  //atp=eeprom[ASSOCTABPTR];			// Start Association Table
      assno=eeprom[eeprom[ASSOCTABPTR]];				// Erster Eintrag = Anzahl Einträge
      //tel8=telegramm[8];
      for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
      {
        gaposh=eeprom[eeprom[ASSOCTABPTR]+1+(n*2)];
        if(gapos_in_gat(telegramm[3],telegramm[4])==gaposh)					// Wenn Positionsnummer übereinstimmt
        {
          objno=eeprom[eeprom[ASSOCTABPTR]+2+(n*2)];				// Objektnummer
          objflags=read_objflags(objno);			// Objekt Flags lesen
          obj=objno%3;// modulo 3 ergibt die Kanalnummer
          valtmp=telegramm[7]&0x0F;

          // Objektbehandlung:
         if((objno<12 || objno>14)&&(!(sperren & bitmask_1[obj]))){ // alles ausser Sperren.. und wenn nicht gesperrt
          //############################################################
          if ((objno<3)&&(!(sperren & bitmask_1[obj+4]))){	// Objekt 0-2 Schaltobjekt nicht bei Sperrmerker schalten
        	  object_schalten(objno,valtmp);	// Objektnummer 0-2 entspricht den Ausgängen 1-3
          }
          //############################################################
          if (objno>2 && objno<6)	// Objektnummer 3-5 Dimmen
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
            	
            	if (!obj){// Dimmobjekt 3
	                timerbase[0]=(eeprom[0xc6])&0x07;
	            }
	            else{
		            if(obj==1){// Dimmobjekt 4
		               	timerbase[1]=((eeprom[0xc6]>>4)&0x07);	
		            }
		            else{// Dimmobjekt 5
		            	timerbase[2]=eeprom[0xc7]&0x07;	
		            }
		        }    
	            timerstart[obj]=eeprom[0xc8+obj];
	            
            }
            else{			// dimmen: stop!
            	//valtmp hier mit Parameter laden
            	if(!obj){// 			A1: Parameter Ausschaltfunktion holen
            		valtmp=eeprom[0xCE]&0x0F;
            	}
            	else {
            		if (obj&0x01){// 			A2: Parameter Ausschaltfunktion holen
            			valtmp=eeprom[0xCE]>>4;
            		}
            		else valtmp=eeprom[0xC5]>>4;//A3: Parameter Ausschaltfunktion holen
            	}
            	if((valtmp&0x08)&&(dimmziel[obj] < dimmwert[obj])){//	 schauen ob Ausschaltfunktion aktiviert
            		if(dimmwert[obj] < eeprom[0xCB + obj]){// wenn dimmwert<parameter..
            			timercnt[objno] = eeprom[0xCF + obj];//faktor laden
            			timerbase[objno] = valtmp&0x07;// base laden
            			timerstate[obj] |= 0x01;// status aus verz setzen.
            		}//ende if(dimmwert...
            	}// ende if((valtmp...
            	dimmziel[obj]=dimmwert[obj];
            	//helligkeit[obj]=dimmwert[obj];
            	//if (read_objflags(obj+6)&0x40)send_obj_value(obj+6);
            }// ende bei stop!
          }// ende if (objno>2 && objno<6)..Dimmen
          //####################################################################
          // ++++ Helligkeit +++++
          
          if (objno>5 && objno<9)	// Objektnummer 6-8 Helligkeit
          {
           write_obj_value(objno, telegramm[8]);
           //obj=objno-6;
           hell_stellen(obj,telegramm[8]);

          }// ende if (objno 5-8...
          //
        } // ende alles ausser sperren

         //#############################################################
         //++++++ Lichtszenen +++++++
         //
         // LZ werden extra behandelt da sie auch bei Sperrmerker gesperrt sind
         //
        if (objno>14 && objno<18 && (!(sperren&(bitmask_11[obj])))){
       	valtmp=telegramm[8];
       	//obj=objno-15;
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
        if(objno>11 && objno<15){
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
          
        }// ende if gaspos in gat...
      }// ende for(n....
      if (portbuffer&0xF0 != oldportbuffer&0xF0) portchanged=1;//post für port_schalten hinterlegen
      //port_schalten(portbuffer);	//Port schalten wenn sich ein Pin geändert hat
    }
    //owntele=0;
    //respondpattern=0;
}
unsigned char sperrvalue(unsigned char index,unsigned char obj){
	unsigned char retval=0;
	// Dimmwert beginn-ende aus Dimmwerttabelle holen
	if(index==1)retval=grundhelligkeit[obj];
	if (index>1 && index<12)retval=prozentvalue[index-2];
	if (index==12)retval=dimmwert[obj];
 	if (index==13) retval=aushell[obj];// gespeicherte Helligkeit
	return retval;
}


void hell_stellen (unsigned char obj,unsigned char value){
    // parameter für andimmen holen

	if (!obj){					// Helligkeit 6
        timerbase[0]=(eeprom[0xc6])&0x0F;
    }
    else{
        if(obj==1){				// Helligkeit 7
           	timerbase[1]=((eeprom[0xc6]>>4)&0x0F);	
        }
        else{					// Helligkeit 8
        timerbase[2]=eeprom[0xc7]&0x0F;	
            }
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
void read_value_req(void)
{
	unsigned char objno, objflags;
	unsigned int objvalue;
	
	objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
	if(objno!=0xFF) {	// falls Gruppenadresse nicht gefunden
		
		objvalue=read_obj_value(objno);		// Objektwert aus USER-RAM lesen (Standard Einstellung)

		objflags=read_objflags(objno);		// Objekt Flags lesen
		// Objekt lesen, nur wenn read enable gesetzt (Bit3) und Kommunikation zulaessig (Bit2)
		if((objflags&0x0C)==0x0C) send_obj_value(objno+64); //send_value(0,objno,objvalue);
    }
}


unsigned long read_obj_value(unsigned char objno)	// gibt den Wert eines Objektes zurueck
{
	unsigned char ret_val=0,obj;
	obj = objno % 3;
	if(objno<3) {
		if(schalten & bitmask_1[obj]) ret_val=1;
	}
	if(objno>=3 && objno<6) {
		ret_val = dimmen[obj];
	}
	if(objno>=6 && objno<8) {
		ret_val = helligkeit[obj];
	}
	if(objno>=9 && objno <12) {
		if(rueckmelden &(bitmask_1[obj])) ret_val=1;
	}
	if(objno>=12 && objno <15) {
		if(sperren &(bitmask_1[obj])) ret_val=1;
	}
	if(objno>=15) {
		ret_val= lz[obj];
	}
	
	return(ret_val);
}


void write_obj_value(unsigned char objno,unsigned int objvalue)	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
{
unsigned char obj;
	obj = objno % 3;
	if(objno<3) {
		if(objvalue==0) schalten &= bitmask_0[obj];
		else schalten |= bitmask_1[obj];
	}
	if(objno>=3 && objno<6) {
		dimmen[obj]=objvalue;
	}
	if(objno>=6 && objno<8) {
		helligkeit[obj]=objvalue;
	}
	if(objno>=9 && objno <12) {
		if(objvalue==0) rueckmelden &= bitmask_0[obj];
		else rueckmelden|=bitmask_1[obj];
	}
	if(objno>=12 && objno <15) {
		if(objvalue==0) sperren &= bitmask_0[obj];
		else sperren |= bitmask_1[obj];
	}
	if(objno>=15) {
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
	case 2:
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
	}
	A4=A1|A2;
	A4|=A3;
	portchanged=1;
	//
	//portbuffer=(A1<<0 | A2<<1 | A3<<2 | A4<<3)<<4;
	if(objno<0x03){// Einschalten-Einschalthelligkeit
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
/*	
	RTCCON=0x60;		// RTC anhalten und Flag löschen
	RTCH=0x00;			// reload Real Time Clock
	RTCL=0x1D;			//0.5ms laden
	RTCCON=0x61;		// RTC starten
*/
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
		for (n=0;n<3;n++){// autoreload der Dimm Timer
			if(timerbase[n]){
				if(! timercnt[n]){
					timercnt[n]=timerstart[n];
					if (dimmziel[n]>dimmwert[n]){ //aufwärts
						dimmwert[n]++;
					}
					if(dimmziel[n]<dimmwert[n]){  //abwärts
						dimmwert[n]--;
					}
				}// if (! timercnt...
			}//if(timerbase..
			if (portbuffer& bitmask_1[n]){// Merker für "Soft Aus"
				if (!dimmwert[n]){
					portbuffer&=(bitmask_0[n]); //M1...3 und Ausgang abschalten ausschalten
					portbuffer&=(bitmask_0[n+4]);
					portchanged=1;
				}
			}
		}
		for (n=3;n<6;n++){// Zeiten für Aktionen wie Ausschalten(zeitdimmer...
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
		if(!(sperren & bitmask_11[m]))dimmpwm[m]=dimmwert[m];	
		}
		dimmpwm[3]=(dimmpwm[0]/3)+(dimmpwm[1]/3)+(dimmpwm[2]/3);
		A4=A1|A2;
		A4|=A3;

/*	
#ifdef HAND		//+++++++   Handbetätigung  ++++++++++

	if((TMOD&0x0F)==0x02 && fb_state==0) {
		ET1=0;


	#ifdef MAX_PORTS_4
		while( (TMOD&0x0F)==0x02 && ( TL0>0x72));// PWM scannen um "Hand"-Tasten abzufragen
	#endif
		interrupted=0;	  
		Tasten=0;				

	#ifdef MAX_PORTS_4
		ledport=0x01;
		for (n=0;n<4;n++) {  						
			P0=~ledport;
			P0_5=1;			//P0.5 auf 1, wird über Dioden und taster auf low IO gezogen.
			if (!P0_5){
		  		Tasten=Tasten|ledport;
		  		objno=n;
		  		n=3;
		  	}
		  	ledport=ledport<<1;
		} 
	#endif
		
		//if (interrupted==1) Tasten=Tval;  // wenn unterbrochen wurde verwerfen wir die Taste
		REFRESH;
		//	Tasten = Tval; // ##############  <----- Hier wird Handbetätigung quasi mit ausgeschaltet !! #########################
		if (Tasten != Tval)  {
			portbuffer=oldportbuffer;
		  	ledport=Tasten&~Tval; // ledport ist hier die Hilfsvariable für steigende Flanke
		  	if (ledport){
		  		portbuffer^=ledport; // bei gedrückter Taste toggeln
		  		portchanged=1;
		  	}
		  	Tval=Tasten;			//neue Tasten sichern
		}
		ET1=1;
	}
#endif
*/

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
	for(n=0;n<3;n++){
		if(pattern&bitmask_1[n]){
			send_obj_value(n+9);
			for(m=0;m<30;m++) // verzögerung wegen ft1.2
				while(dimmtimervorteiler);
			}
/*		da beim Einschalten Dimmziel sich ändert kann das entfallen
		if (((portbuffer&(~oldportbuffer))>>4)&&(read_objflags(n+6)&0x40)){ 
			//send_obj_value(n+6);
			//rs_send (helligkeit[n+6]);
			for(m=0;m<30;m++)
				while(dimmtimervorteiler);
			}
*/			
		//}
	}
	//Ausgänge setzen
	P0|=(portbuffer&0xF0);		// Ports Ausgänge zuordnen
	P0&=(portbuffer|0x0F);

	portchanged=0;					//postvariable zurücksetzen
	oldportbuffer=portbuffer;
/*
#ifdef SPIBISTAB	//serielle schiebeausgang für bistabile Relaise
		spi_2_out(sort_output(portbuffer));		// Ports schalten
		PWM=0;
		TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
		TH0=0x6f;		// 16ms (10ms=6fff)
		TL0=0xff;
		TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;

	rm_state=portbuffer ^ eeprom[RMINV];	// Rückmeldeobjekte setzen
	for (n=0;n<8;n++) {	// Rückmeldung wenn ein Ausgag sich geändert hat
		pattern=1<<n;
		if((portbuffer&pattern)!=(oldportbuffer&pattern)) send_obj_value(n+12);
	}

	oldportbuffer=portbuffer;
	portchanged=0;

#else	// also normaler out8 oder out4

	if(portbuffer & ~oldportbuffer) {	// Vollstrom nur wenn ein relais eingeschaltet wird
		TR0=0;
		AUXR1&=0xE9;	// PWM von Timer 0 nicht mehr auf Pin ausgeben


		PWM=0;			// Vollstrom an

		P0=portbuffer;		// Ports schalten
		TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
		TH0=0x00;		// 16ms (10ms=6fff)
		TL0=0x00;
		TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;
	}
	else P0=portbuffer;

	rm_state=portbuffer ^ eeprom[RMINV];	// Rückmeldeobjekte setzen
	for (n=0;n<8;n++) {	// Rückmeldung wenn ein Ausgag sich geändert hat
		pattern=1<<n;
		if((portbuffer&pattern)!=(oldportbuffer&pattern)) send_obj_value(n+12);
	}

	oldportbuffer=portbuffer;
	portchanged=0;
	
#endif
*/
}

/*
unsigned int sort_output(unsigned char portbuffer){
   unsigned char diff;
   unsigned int result;
   diff=portbuffer ^ oldportbuffer;
   result=0;
   // A1 
   if (diff & 0x01){
	   if(portbuffer & 0x01){
		   result|=0x1000;
	   }
	   else{
		   result|=0x2000;
	   }
   }

   // A2
   if (diff & 0x02){
	   if(portbuffer & 0x02){
	      result|=0x0004;
	   }
	   else{
	      result|=0x0008;
	   }
   }
   // A3
   if (diff & 0x04){
	   if(portbuffer & 0x04){
	      result|=0x4000;
	   }
	   else{
	      result|=0x8000;
	   }
   }
   // A4
   if (diff & 0x08){
	   if(portbuffer & 0x08){
	      result|=0x0001;
	   }
	   else{
	      result|=0x0002;
	   }
   }
   
   // A5
   if (diff & 0x10){
	   if(portbuffer & 0x10){
	      result|=0x0040;
	   }
	   else{
	      result|=0x0080;
	   }
   }
   // A6
   if (diff & 0x20){
   	   if(portbuffer & 0x20){
	      result|=0x0100;
	   }
	   else{
	      result|=0x0200;
	   }
   }
   
   // A7
   if (diff & 0x40){
	   if(portbuffer & 0x40){
	      result|=0x0010;
	   }
	   else{
	      result|=0x0020;
	   }
   }
   // A8
   if (diff & 0x80){
	   if(portbuffer & 0x80){
	      result|=0x0400;
	   }
	   else{
	      result|=0x0800;
	   }
   }
   return result;

}
*/
/*
void spi_2_out(unsigned int daten){

   unsigned char n, unten, mitte;

   unten=daten & 0xFF;
   mitte=daten>>8;

   WRITE=0;
   CLK=0;
   for(n=0;n<=7;n++){
      

      BOT_OUT=(unten & 0x080)>>7;
      unten<<=1;
      
      MID_OUT=(mitte & 0x080)>>7;
      mitte<<=1;

      CLK=1;
      CLK=0;

   }

   WRITE=1;

   WRITE=0;

}
*/





void bus_return(void)		// Aktionen bei Busspannungswiederkehr
{
	__bit bitval;
	unsigned char n,m;
	// Rückmeldung bei Busspannungswiederkehr
	for (n=9;n<12;n++) {
		send_obj_value(n);
		for(m=0;m<30;m++){// verzögerung wegen ft1.2
			while(dimmtimervorteiler);
		}
	}
	//A1=1;A2=1;A3=1;A4=1;
	grundhelligkeit[0]=grundhelligkeit_tabelle[eeprom[0xc2]&0x07];
	grundhelligkeit[1]=grundhelligkeit_tabelle[(eeprom[0xc2]&0x70)>>4];
	grundhelligkeit[2]=grundhelligkeit_tabelle[eeprom[0xc3]&0x07];
// hier einschaltverhalten bei busreturn rein...
	portbuffer=0;
	oldportbuffer=portbuffer;
	for(n=0;n<3;n++){
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
		else{
			if (n&0x02)	valtmp=eeprom[offset+1]&0x0F;//n=2
			else 	valtmp=(eeprom[offset]&0xF0)>>4;//n=1
		}
		if (!valtmp)bw=0;
		if(valtmp==1)bw=grundhelligkeit[n];
		if (valtmp>1&&valtmp<12)bw=prozentvalue[valtmp-2];
	    if (valtmp==13) bw=aushell[n];
	    dimmziel[n]=bw;
	
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen

{
//	unsigned char bw,bwh,n;
#ifdef HAND
	Tval=0x00;
#endif
	P0=0;
	P0M1=0x00;		// Port 0 Modus push-pull für Ausgang


	P0M2= 0xFF;
	
 
//	portbuffer=eeprom[PORTSAVE];	// Verhalten nach Busspannungs-Wiederkehr

//	bw=eeprom[0xF6];
//	for(n=0;n<=3;n++) {			// Ausgänge 1-3
//		bwh=(bw>>(2*n))&0x03; 
//		if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<n));
//		if(bwh==0x02)  portbuffer=portbuffer | (0x01<<n);
//	}
	

	
//	oldportbuffer=0; 	// auf 0 setzen, da sonst kein Vollstrom aktiviert wird
//	portchanged=1;		// Post hinterlegen damit in delaytimer nach portschalten springt


//	rm_state=portbuffer ^ eeprom[RMINV];	// Rückmeldeobjekte setzen


	
	ET0=0;			// Interrupt für Timer 0 sperren

//	zf_state=0x00;		// Zustand der Zusatzfunktionen 1-4
//	blocked=0x00;		// Ausgänge nicht gesperrt
	timer=0;			// Timer-Variable, wird alle 130ms inkrementiert
  
	
	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	START_WRITECYCLE
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
	WRITE_BYTE(0x01,0x04,0x04)
/*

#ifdef MAX_PORTS_4				// 4-fach Aktor
	WRITE_BYTE(0x01,0x05,0x30)	// Devicetype 0x2062 = Jung Aktor 2134.16
	WRITE_BYTE(0x01,0x06,0x18)
#endif

	WRITE_BYTE(0x01,0x07,0x01)	// Versionnumber of application programm
*/
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0x8A)	// COMMSTAB Pointer
	STOP_WRITECYCLE
	// set timer 0 autoreload 0.05ms
	TR0=0;
	TMOD &= 0xF0;
	TMOD |= 0x02;// T0 autoreload
	TH0=0x47; //47 bei 50µs  40 bei 52µ für 2400bd
	TL0=0x47; //47 bei 50µs  40 bei 52µ für 2400bd
	TR0=1;
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
	EA=1;						// Interrupts freigeben
	

}// Ende restart app
