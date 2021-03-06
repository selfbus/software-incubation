/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008-2013 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 * 
* 
 */
 


#include  "fb_app_2i2o.h"
//#include  "../com/debug.h"
//#include "../com/fb_rs232.h"
//#include"../com/watchdog.h"
const unsigned char __at 0x1CFF PORTSAVE;

unsigned char timerbase[TIMERANZ];// Speicherplatz f�r die Zeitbasis und 4 status bits
 unsigned  char timercnt[TIMERANZ];// speicherplatz f�r den timercounter und 1 status bit
unsigned char timerstate[TIMERANZ];// Speicherplatz f�r die Aktionen die nach Ablauf ausgefuehrt werden sollen
//unsigned char timerstate[TIMERANZ];// Speicherplatz f�r die Aktionen die nach Ablauf ausgefuehrt werden sollen
unsigned int timer;		// Timer f�r Schaltverz�gerungen, wird alle 130us hochgez�hlt
unsigned char timer_base,timer_state;
unsigned char para_value,pinno,pinnoX4,para_adr;
unsigned char Tval,Taster_ctr;
unsigned char out_state;	// Werte der Objekte 0-7 (Ausg�ngsobjekte)
unsigned char rm_state;		// Werte der Objekte 12-19 (R�ckmeldeobjekte)
unsigned char zf_state;		// Werte der Objekte 8-11 (Zusatzfunktionen 1-4)
unsigned char portbuffer,p0h;	// Zwischenspeicherung der Portzust�nde
unsigned char oldportbuffer;// Wert von portbuffer vor �nderung (war fr�her ...0x29)
unsigned char blocked;		// Sperrung der 8 Ausg�nge (1=gesperrt)
unsigned char in_blocked;
unsigned char logicstate;	// Zustand der Verkn�pfungen pro Ausgang
__bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszuf�hren
__bit portchanged;
__bit objval=0,jobj=0;
__bit st_Flanke=0;
//__bit zeropulse;
unsigned char rm_send;		// die von der main zu sendenden R�ckmeldungen
unsigned char objects_l[2];// die unteren Objekte variabler Gr��e ( obj 2,3)
unsigned char objects_h[2];// die oberen Objekte variabler Gr��e (obj 10,11)


#ifdef zeroswitch
unsigned char portausgabe_on;
unsigned char portausgabe_off;
volatile unsigned char schalten_state;
unsigned char phival;
#endif


void pin_changed(unsigned char pin_no)
{
	unsigned char tmp;
	unsigned char objoffset=8;
	unsigned char typ=0;
	unsigned char n;
	timer_base=0;
	para_value=0;

	pinno=pin_no;
	pinnoX4=pinno*4;
	para_adr=0xD5+(pinnoX4);
	n;
	if (debounce(pinno))			// Entprellzeit abwarten und pr�fen
  {
//	timer_base=(eeprom[0xF6+((pinno+1)>>1)]>>(4*((pinno&0x01)^0x01)))&0x07  ;
	tmp=eeprom[0xCF]; // parameter f�r den switch holen
	if (pinno&0x01){
		tmp>>=4;	// wenn pinno==3 dann nach rechts schieben
		timer_base=(eeprom[0xF7]>>4); // parameter f�r Zeit basis holen
	}
	else{
		timer_base=(eeprom[0xF8]); //wenn pinno 2 dann parameter Zeitbasis holen
	}
	timer_base &= 0x07; // Parameter Zeitbasis maskieren
	tmp&=0x0F;			// Parameter f�r switch maskieren 
	st_Flanke=(((portbuffer>>pinno)&0x01)==0) && (((p0h>>pinno)&0x01)==1);
	timer_state=timerstate[pinno];
	
//	switch ((eeprom[0xCF] >> ((pinno & 0x01)*4)) & 0x0F)	// Funktion des Eingangs
	switch (tmp)
    {
    case 0x01:				// Funktion Schalten
#ifdef schalte	
#  ifdef zykls	// mit zyklisch senden Eingang normal behandeln
    	schalten(st_Flanke,pinno);			// Flanke Eingang x.1
		schalten(st_Flanke,pinno+8);		// Flanke Eingang x.2
#  else			// ohne zyklisch senden daf�r 2. schaltebene
		if(eeprom[para_adr]&0x0C){// 2. SE aktiviert?
	        tmp=(eeprom[para_adr+2]);//0xd7+pinno*4   bit 4,4 / 6,7 zykl senden aktiv 2. Schaltebene
	        if(((tmp&0xC0) && st_Flanke==1)||((tmp&0x30) && st_Flanke==0)){// f�r Obj x.2
	        	timercnt[pinno]= eeprom[para_adr+1]+ 0x80;//0xD6 Faktor Dauer )
	         	timerbase[pinno]=0;
	         	timer_state = 0x20|st_Flanke;//speichern des portzustandes
	         }
	         else {// kein zyklsenden, bzw loslassen
	         		if(timercnt[pinno]>0x80){ //Wenn Zeit beim loslassen noch lief
	         	    	schalten(st_Flanke,pinno);			// Flanke Eingang x.1
	         		}
	         		timercnt[pinno]=0;
	         }
		}//Ende 2. SE aktiviert?
		else{ // 2. SE NICHT aktiviert...
	    	schalten(st_Flanke,pinno);			// Flanke Eingang x.1
			schalten(st_Flanke,pinno+8);		// Flanke Eingang x.2
		}
#  endif
#endif
		break;  
     
      case 0x02:				// Funktion Dimmen
    		/***********************
    		 * Funktion Dimmen
    		 ***********************/
#ifdef dimmer    		
         if (st_Flanke){// Taster gedrueckt -> schauen wie lange gehalten
  			timercnt[pinno]=0x80+(eeprom[0xD7+(pinnoX4)]&0x7F);	// Faktor/Dauer			
			timerbase[pinno]=timer_base;

   			objval=(read_obj_value(pinno+8)>>3)&0x01;
  			switch (eeprom[para_adr]&0x70) {
  			case 0x00:	// UM Dimmen
  				objval = !objval;	// Dimmrichtung �ndern
  				break;
  			case 0x10:				// zweiflaechen heller parametriert
  			case 0x30:
  				objval=1;
  				break;
  			default:	
  			//case 0x20:			// zweiflaechen dunkler parametriert
  			//case 0x40:
  				objval=0;
  			}
  			if(objval){	// wenn heller dimmen soll
  				timer_state = ((eeprom[para_adr+0x01]&0x38)>>3)+ 0x48;	// dimmen
  				}
  			else{		// wenn dunkler dimmen soll
  				timer_state = (eeprom[para_adr+0x01]&0x07)+ 0x40;	// dimmen
  				}
          }
  		else {		// Taster losgelassen
  			if ((timer_state & 0x50)== 0x40) {		// wenn delaytimer noch laeuft, dann Schalten, also EIS1 telegramm senden
  	//		if (timercnt[pinno]>0x80) {		// wenn delaytimer noch laeuft, dann Schalten, also EIS1 telegramm senden
  		  				objval = read_obj_value(pinno);
  				switch (eeprom[para_adr]&0x70) {//Bedienkonzept angucken
  				case 0x10:	// zweiflaechen ein
  					objval=1;
  					break;
  				case 0x20:	// zweiflaechen aus
  					objval=0;
  					break;
  				default:	
  			//	case 0x00:	// UM Einflaeche
  			//	case 0x30:	// UM-heller
  			//	case 0x40:	// UM-dunkler
  					objval = !objval;
  				}
  				write_send(pinno,objval);
  				timercnt[pinno]=0;
  			}
  			else {	// Timer schon abgelaufen (also dimmen), dann beim loslassen stop-telegramm senden
  				tmp=read_obj_value(pinno+8);
  				if (eeprom[0xD5+(pinnoX4)] & 0x08) {	// ... natuerlich nur wenn parameter dementsprechend 
  					write_send(pinno+8, tmp & 0x08);		// Stop Telegramm
  				}
  				else write_obj_value(pinno+8,tmp & 0x08);	// auch wenn Stopp Telegramm nicht gesendet wird, Objektwert auf 0 setzen
				timer_state=0;
				timercnt[pinno]=0;
  			}
  			
  		}
#endif
        break;
#ifdef jalo       
        case 0x03:				//Funktion Jalousie
        	/****************************
        	 * Funktion Jalousie
        	 ****************************/
        	n=0xD8+(pinno*4);
			para_value=(eeprom[n]&0x30)>>4;//Jalofunktion holen
			switch (para_value){
				case 1:		//auf
					jobj=0;
				break;
				case 2:		//ab
					jobj=1;
				break;
				case 3:		//UM
	    			jobj=read_obj_value(pinno+8)^0x01;//neues Jaloobj invers zum langzeit
	    		break;
			}
			if (st_Flanke){// Taster gedrueckt -> schauen wie lange gehalten
            	if(eeprom[n]& 0x08){	//wenn Bedienkonzept lang-kurz ()
            		//timerbase[pinno]=0;
            		timer_state = jobj+0x80;
            		timercnt[pinno]=0x80;//langzeit in delay_timer SOFORT ausf�hren
            	}
            	else{								//wenn Bedienkonzept kurz-lang-kurz
	            	write_send( pinno, jobj);	// Kurzzeit telegramm immer bei Dr�cken senden
	    			timercnt[pinno]=0x80+eeprom[0xD6+(pinno*4)];//Faktor Dauer )
	    			timerbase[pinno]=timer_base;
	    			// Zeit zwischen kurz und langzeit)	
	     			//
	    			timer_state = jobj+0x80;
	            }// ende Bedienkonzept lang-kurz-lang
            }//ende steigende Flanke
    		else {	// Taster losgelassen
  			if (timer_state & 0x10) write_send( pinno, jobj);	// wenn delaytimer noch laueft und in T2 ist, dann kurzzeit telegramm senden
    			else timercnt[pinno]=0;	// T2 bereits abgelaufen
    		}
        break;
# endif
#ifdef wertgeber 
    	/**********************************************************
    	 * Funktion Wertgeber Dimmen,Temparatur,Helligkeit
    	 **********************************************************/
       
        case 0x04:// Dimmwertgeber
        	para_value=0xFF;
        	typ=0x01;
        	objoffset=0;//l�uft absichtlich in den n�chsten case
        	n=0xD5+(pinno*4);
        	tmp=(((eeprom[n]&0x04)>>2)|(eeprom[n+1]&0x80)>>6);//in tmp steigend fallend reaktion
        	if (st_Flanke){// Taster gedrueckt       in tmp bit0 steigend, bit1 fallend
        		
        		if(tmp&0x01) write_send( pinno+objoffset, eis5conversion((eeprom[n+2]& para_value),typ));	//wert senden
        	}//ende steigende Flanke
    		else {	// Taster losgelassen dimmwert senden
  			if (tmp>=0x02) write_send( pinno+objoffset, eis5conversion(eeprom[n+tmp]& para_value,typ));
    		}
         break;
 
         case 0x05:
    	/*******************************************
    	 * Funktion Wertgeber Lichtszenen
    	 *******************************************/
        	 n=0xD5+(pinno*4);
        	 para_value=eeprom[n] & 0x0C;
        	 
		if (st_Flanke){// Taster gedrueckt 
			if(para_value!=0x04) write_send( pinno,eeprom[n+2]&0x7F );	// Lichtszenennummer senden
		}
		else{
			if(para_value>=0x04) write_send( pinno,eeprom[n+3]&0x7F );	// Lichtszenennummer senden
		}
 	
        break;
#endif        

        
    }
	timerstate[pinno]=timer_state;
  }// end if (debounce)...
	
}

#ifdef schalte
void schalten(__bit risefall, unsigned char pinno)	// Schaltbefehl senden
{
	unsigned char func,sendval=0;
											// pinno 2,3 entspricht Eingang 1,2
		func=eeprom[0xD7+(pinno & 0x07)*4]; //0xD7
		if (pinno>=8)func=func>>4;			// wenn 2. Schaltobjekt dann obere 4 bit
		if (risefall) func=(func>>2);		// Funktion bei steigender Flanke obere 2 bit
		func=func&0x03;					// Funktion maskieren
		if (func!=0 || !bus_return_ready)// bypass f�r bus return, damit immer Eingangszustand auch dann gesendet wird wenn flanken nicht parametriert
		{
			if (func==0x03) sendval=read_obj_value(pinno) ^0x01;  //UM
			else sendval = func & 0x01;	// EIN   AUS
			write_send(pinno,sendval);
		}
	
}
#endif

unsigned char debounce(unsigned char pinno)	// Entprellzeit abwarten und pr�fen !!
{
  unsigned char debtime,n,w;//,ret;//,port_help;
  debtime=eeprom[DEBTIME];			// Entprellzeit in 0,5ms Schritten
  if (debtime>0) {
	  for(n=0;n<debtime;n++){
	  	for(w=112;w>0;w--); 
	  	}// delay ca. 4,5�s
  }
  return ((~(P0^p0h))& bitmask_1[pinno]);//ret=1;
}


  void (write_send)(unsigned char objno,unsigned int value){

  	write_obj_value(objno,value);
  	send_obj_value(objno);
  }


void write_value_req(unsigned char objno) 	// Ausg�nge schalten gem�� EIS 1 Protokoll (an/aus)
{
  unsigned char zfout,zftyp;
  unsigned char blockstart, blockend, block_polarity;
  unsigned char obj_bitpattern, zf_bitpattern;
  		obj_bitpattern=0x01<<(objno-8);
          if (objno<2) object_schalten(objno,telegramm[7]&0x01);	// Objektnummer 0-7 entspricht den Ausg�ngen 1-8
          if (objno>=2 ){
          write_obj_value(objno,telegramm[7]& 0x3F); //bit 6+7 l�schen (0x40,0x80)
          }
          if (objno>7 && objno<9)	// Objektnummer 8-9 entspricht den Zusatzfunktionen 1-2
          {
            write_obj_value(objno, telegramm[7]&0x01);
            zfout=0;
            blockstart=0;
            blockend=0;
            switch (objno-8)			// Zugeordneten Ausgang zu Zusatzfunktionsnr. in zfout speichern (1-8)
             {
              case 0x00:		
                zfout=eeprom[FUNCASS]&0x0F;
                blockstart=eeprom[BLOCKACT]&0x03;		// Verhalten bei Beginn der Sperrung
                blockend=(eeprom[BLOCKACT]>>2)&0x03;	// Verhalten bei Ende der Sperrung
              break;
              case 0x01:
                zfout=(eeprom[FUNCASS]&0xF0)>>4;
                blockstart=(eeprom[BLOCKACT]>>4)&0x03;	// Verhalten bei Beginn der Sperrung
                blockend=(eeprom[BLOCKACT]>>6)&0x03;	// Verhalten bei Ende der Sperrung
              break;
              case 0x02:
                zfout=eeprom[FUNCASS+1]&0x0F;
                blockstart=eeprom[BLOCKACT+1]&0x03;		// Verhalten bei Beginn der Sperrung
                blockend=(eeprom[BLOCKACT+1]>>2)&0x03;	// Verhalten bei Ende der Sperrung
              break;
              case 0x03:
                zfout=(eeprom[FUNCASS+1]&0xF0)>>4;
                blockstart=(eeprom[BLOCKACT+1]>>4)&0x03;	// Verhalten bei Beginn der Sperrung
                blockend=(eeprom[BLOCKACT+1]>>6)&0x03;		// Verhalten bei Ende der Sperrung
            }
            zftyp=((eeprom[FUNCTYP])>>((objno-8)*2)) & 0x03;	// Typ der Zusatzfunktion
            zf_bitpattern=0x01<<(zfout-1);
           
            switch (zftyp)
            {
              case 0x00:			// Verkn�pfung
                switch (telegramm[7])
                {
                  case 0x80:
                    logicstate=logicstate&(0xFF-zf_bitpattern);
                  break;
                  case 0x81:
                    logicstate=logicstate|zf_bitpattern;
                }
                object_schalten(zfout-1, read_obj_value(zfout-1));	//telegramm[7]&0x01);
              break;
              case 0x01:			// Sperren
            	block_polarity=eeprom[BLOCKPOL] & obj_bitpattern;
                if (((telegramm[7]==0x80) && (block_polarity==0)) ||
                	((telegramm[7]==0x81) && (block_polarity!=0)))
                {	// Ende der Sperrung
                	if((blocked & zf_bitpattern)!=0) {	// nur wenn Sperre aktiv war
						blocked=blocked&(0xFF-zf_bitpattern);
						if (blockend==0x01) portbuffer=portbuffer&(0xFF-zf_bitpattern);	// Bei Ende der Sperrung ausschalten
						if (blockend==0x02) portbuffer=portbuffer|zf_bitpattern;		// Bei Ende der Sperrung einschalten
                	}
                }
                  
                if (((telegramm[7]==0x81) && (block_polarity==0)) ||
                	((telegramm[7]==0x80) && (block_polarity!=0)))
                {	// Beginn der Sperrung
                	if((blocked & zf_bitpattern)==0) {	// nur wenn Sperre inaktiv war
						blocked=blocked|zf_bitpattern;
						if (blockstart==0x01) portbuffer=portbuffer&(0xFF-zf_bitpattern);	// Bei Beginn der Sperrung ausschalten
						if (blockstart==0x02) portbuffer=portbuffer|zf_bitpattern;		// Bei Beginn der Sperrung einschalten
						timercnt[zfout-1]=0;//delrec[(zfout-1)*4]=0;	// ggf. Eintrag f�r Schaltverz�gerung l�schen
                	}
                }
              break;
            }
          }
      if (portbuffer != oldportbuffer) portchanged=1;//post f�r port_schalten hinterlegen

}


/** 
* Objektwert lesen wurde angefordert, read_value_response Telegramm zur�cksenden
*
* 
* @return
* 
*/
void read_value_req(unsigned char objno)
{
 send_obj_value(objno+64);    
}


unsigned long read_obj_value(unsigned char objno) 	// gibt den Wert eines Objektes zurueck
{
	unsigned char ret_val=0;

	if(objno<2) {
		if(out_state&(1<<objno)) ret_val=1;
	}
	if(objno>=2 && objno<4) {
		ret_val=objects_l[objno-2];
	}
	if(objno>=8 && objno<10) {
		if(zf_state&(1<<(objno-8))) ret_val=1;
	}
	if(objno>=10 && objno<12) {
		ret_val=objects_h[objno-10];
	}
	if(objno>=16 && objno<18) {
		if(rm_state&(1<<(objno-16))) ret_val=1;
	}
	if(objno>=18) {
		if(in_blocked &(1<<(objno-18))) ret_val=1;
	}
	return(ret_val);
}


void write_obj_value(unsigned char objno,unsigned int objvalue)	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
{
	if(objno<2) {
		if(objvalue==0) out_state&=0xFF-(1<<objno); // Ausg�nge 1,2
		else out_state|=1<<objno;
	}
	if(objno>=2 && objno<4) {						// Eingansobjekt 1,2 1.1/kurzzeit,schalt/wert/..variabel
		objects_l[objno-2]=objvalue;
	}
	if(objno>=8 && objno<10) {						// Sperre/Verkn�pfungen Ausg�nge
		if(objvalue==0) zf_state&=0x0F-(1<<(objno-8));
		else zf_state|=1<<(objno-8);
	}
	if(objno>=10 && objno<12) {						// Eingansobjekt 1,2 1.2/langzeit,Dimm..variabel
		objects_h[objno-10]=objvalue;
	}
	if(objno>=16 && objno<18) {						// R�ckmeldungen Ausg�nge
		if(objvalue==0) rm_state&=0xFF-(1<<(objno-16));
		else rm_state|=1<<(objno-16);
	}
	if(objno>=18) {	// Sperre Eing�nge
		objvalue&=0x01;
		objvalue^=((eeprom[0xd5+((objno-16)*4)]&0x02)>>1);
		if(objvalue==0) in_blocked &=0xFF-(1<<(objno-16));
		else {in_blocked |= 1<<(objno-16);}
		sperren(objno-16,objvalue);
	}
}



void sperren (unsigned char obj,unsigned char freigabe)
{	
	__bit objval=0;
	//sending=1;
	unsigned char sendobj=255;
	unsigned char paratmp;
	freigabe;paratmp;
#ifndef dimmer
	if (freigabe){
		paratmp=(eeprom[0xd5+obj*4]>>4)&0x03;
	}
	else{
		paratmp=eeprom[0xd8+obj*4]&0x03;
	}
#endif
	switch ((eeprom[0xCE+(obj>>1)] >> ((obj & 0x01)*4)) & 0x0F){// Funtion des zugeh�rigen Eingangs
	case 0x01:// funktion Schalten sperren
#ifdef schalte
		sendobj=obj;
		switch (paratmp){

			case 0x01:		//EIN
				objval=1;
			break;
			case 0x02:		//AUS
				objval=0;
			break;
			case 0x03:	//UM
				if (freigabe){ //ende sperre-> aktueller Zustand
				objval= (portbuffer>>obj)& 0x01;
				}
				else{	
    			objval=read_obj_value(obj)^0x01;//Tele invers senden
				}

			break;
			default:
			sendobj=255;
		}
#endif		
		//if (sending) write_send(obj,objval);
	break;	
	case 0x02:// funktion Dimmer-sperren
#ifdef dimmer
		objval = read_obj_value(obj);
		sendobj=obj;
		if (freigabe){		// Ende Sperre  
			if (eeprom[0xD5+(obj*4)]&0x80) objval=0;
			else sendobj=255;
		}
		else{				// Beginn Sperre
			switch (eeprom[0xD5+(obj*4)+1]& 0xC0) {//Bedienkonzept angucken
			case 0x40:	// zweiflaechen ein
				objval=1;
				break;
			case 0x80:	// zweiflaechen aus
				objval=0;
				break;
			case 0xC0:	// UM-heller
				objval = !objval;
				break;
			default:
			sendobj=255;
			}
		}
		//if (sending) write_send(obj,objval);	// value senden
#endif		
	break;
#ifdef jalo
	case 0x03:// Funktion Jalousie - Sperren
		sendobj=obj+8;
		switch (paratmp){
			case 0x01:		//ab
				objval=0;
			break;
			case 0x02:		//auf
				objval=1;
			break;
			case 0x03:	//UM
    			objval=read_obj_value(obj+8)^0x01;//neues Jaloobj invers zum langzeit
    		break;
			default:
			sendobj=255;	
		}
		//if (sending) write_send(obj+8,objval);
	break;
#endif	
	}// Ende switch funktion
	if(sendobj<=16){
		write_obj_value(sendobj,objval);
		while(!send_obj_value(sendobj));
	}
	
}// End function



void object_schalten(unsigned char objno, __bit objstate)	// Schaltet einen Ausgang gem�� objstate und den zug�rigen Parametern
{
	
	unsigned char delay_base,delay_state,logicfunc,zfno;
	unsigned char delay_onoff;
	__bit off_disable;

	off_disable=(((eeprom[OFFDISABLE]& eeprom[0xE9])>>objno)&0x01);	// nur ausschalten wenn AUS-Tele nicht ignoriert werden soll

	if ((!objstate && !off_disable) || objstate) {
		write_obj_value(objno,objstate);		// Objektwert speichern
		//objflags=read_objflags(objno);			// Objekt Flags lesen

		zfno=0;
		logicfunc=0;
		if((eeprom[FUNCASS]&0x0F)==(objno+1)) zfno=1;
		if(((eeprom[FUNCASS]&0xF0)>>4)==(objno+1)) zfno=2;
		if((eeprom[FUNCASS+1]&0x0F)==(objno+1)) zfno=3;
		if(((eeprom[FUNCASS+1]&0xF0)>>4)==(objno+1)) zfno=4;
		if(zfno) {
			if(((eeprom[FUNCTYP]>>((zfno-1)*2))&0x03)==0x00) logicfunc=((eeprom[LOGICTYP]>>((zfno-1)*2))&0x03);
		}
		if(((0x01<<objno) & blocked)==0)  {	//&& (read_objflags(objno)&0x14)==0x14) Objekt ist nicht gesperrt und Kommunikation zul�ssig (Bit 2 = communication enable) und Schreiben zul�ssig (Bit 4 = write enable)
			delay_base=eeprom[(((objno+1)>>1)+DELAYTAB)];   
			if((objno&0x01)==0x01) delay_base&=0x0F;
			else delay_base=(delay_base&0xF0)>>4;
			delay_onoff=0;
			delay_state=0;
					// Ausschalten

			if ( (objstate==0 && (logicfunc==0 || (logicfunc==1 && ((logicstate>>objno)&0x01)==0x00) || logicfunc>=2))
					|| (objstate==1 && (logicfunc>=2 && ((logicstate>>objno)&0x01)==0x00)) )
			{
				delay_onoff=eeprom[objno+0xE7];
				if(delay_onoff==0x00 ||(((eeprom[0xE9]>>objno)&0x01)==0x01)) {		// sofort ausschalten
					if (((eeprom[RELMODE]>>objno)&0x01)==0x00) portbuffer=portbuffer&~(0x01<<objno);	// Schliesserbetrieb
					else portbuffer=portbuffer|(0x01<<objno);						// �ffnerbetrieb
				}
				else delay_state=0x01;				// verz�gert ausschalten
			}
                    
          			// Einschalten
			if ( (objstate==1 && (logicfunc==0 || logicfunc==1 || (logicfunc>=2 && ((logicstate>>objno)&0x01)==0x01))) 
					|| (objstate==0 && (logicfunc==1 && ((logicstate>>objno)&0x01)==0x01)) )
			{
				delay_onoff=eeprom[objno+0xE5];
				if(delay_onoff==0x00) {// wenn keine Einschaltzeit eingestellt


					if(((eeprom[0xE9]>>objno)&0x01)==0x01) { 			// Zeitschaltfunktion
						delay_state=0x80;
						delay_onoff=eeprom[objno+0xE7];
					} 
					if (((eeprom[RELMODE]>>objno)&0x01)==0x00) portbuffer=portbuffer|(0x01<<objno);	// sofort einschalten (Schliesserbetrieb)
					else portbuffer=portbuffer&~(0x01<<objno);					// sofort einschalten (�ffnerbetrieb)
				}
				else delay_state=0x11;				// verz�gert einschalten
			}

			if(delay_state!=0) {				// wenn Verz�gerung, dann timer-Wert ins Flash schreiben  
				timercnt[objno]=delay_onoff|0x80;//delay_target=(delay_onoff<<delay_base)+timer;
				timerbase[objno]=delay_base|(delay_state & 0xF0);//write_delay_record(objno,delay_state,delay_target);
			}
			else timercnt[objno]= 0;//clear_delay_record(objno);    
		}
	}
}


void delay_timer(void)	// z�hlt alle 65ms die Variable Timer hoch und pr�ft Queue
{
	unsigned char objno,port_pattern,delay_zeit,delay_onoff,delay_base,n,m;
	unsigned int timerflags;
	
	objno=0;

		timer++;
		timerflags = timer&(~(timer-1));
		for(n=0;n<16;n++){
			if(timerflags & 0x0001){// positive flags erzeugen und schieben
				for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
					if ((timerbase[m]& 0x0F)==n){// wenn die base mit der gespeicherten base �bereinstimmt
						if (timercnt[m]>0x80){// wenn der counter l�uft...
							timercnt[m]=timercnt[m]-1;// den timer [m]decrementieren
						}// end if (timercnt...
					}//end if(timerbase...
				}// end  for(m..
			}// end if timer...
			timerflags = timerflags>>1;
		}//end for (n=...
		
		// ab Hier die aktion...
		for(objno=0;objno<=3;objno++) {
			timer_state=timerstate[objno];
			if(timercnt[objno]==0x80) {			//runbit 7 gesetzt und Zeit abgelaufen 
				if(objno<2){//		### Ausgaenge ###
					portchanged=1;
					port_pattern=0x01<<objno;
					if(timerbase[objno]&0x10) { //if(delay_state==0x81) {	// einschalten
						if (((eeprom[RELMODE]>>objno)&0x01)==0x00) {				
							portbuffer=portbuffer|port_pattern;		// Einschalten (Schliesserbetrieb)
						}
						else {
							portbuffer=portbuffer&~port_pattern;	// Einschalten (�ffnerbetrieb)
						}
						timercnt[objno]=0;
						//delay_zeit=;
						delay_zeit=((eeprom[0xE9]>>objno)&0x01);// schauen ob zeitschaltfunktion
						if(delay_zeit==0x01) {
							delay_base=eeprom[(((objno+1)>>1)+0xF9)];   // adr der basis berechnen
							if((objno&0x01)==0x01) delay_base&=0x0F;
							else delay_base=(delay_base&0xF0)>>4;		// basis holen
							delay_onoff=eeprom[objno+0xE7];
							if (delay_onoff!=0x00 && delay_zeit!=0x00) {  
								timercnt[objno]=delay_onoff|0x80;//
								timerbase[objno]=delay_base;// Schaltverz�gerung sichern
								
							}
						}
					}
					else {	// ausschalten
						if (((eeprom[RELMODE]>>objno)&0x01)==0x00) {
							portbuffer=portbuffer&~port_pattern;		// Ausschalten (Schliesserbetrieb)
						}
						else {
							portbuffer=portbuffer|port_pattern;			// Ausschalten (�ffnerbetrieb)
						}
						timercnt[objno]=0;
					}
				}
				else { //  also objno >=2 ### Eingaenge ###
#				ifdef schalte
#				ifndef zykls
							if (timer_state & 0x20){
									schalten(timer_state & 0x01,objno+8);
									timercnt[objno]=0;
							}
#				endif
#				endif
				#ifdef jalo			
							if (timer_state & 0x80) { // 0x80, 0x81 f�r langzeit telegramm senden
										write_send( objno+8, timer_state & 0x01);	// Langzeit Telegramm senden
										// *** delay record neu laden f�r Dauer Lamellenverstellung ***

						    			m = eeprom[0xD7+(objno*4)];	// Faktor Dauer	Lamelle	T2	
						    			if (m > 3){// wenn lamellenverstellzeit >3 dann zeit sichern und kurztele zwecks stop
						    				//d.h. bei minimum nach ETS Faktor=3 T2 ist abgeschaltet->kein stop
						    				//damit kann Jalousie als schalter mit 2 schaltebenen verwendung finden

						    				timerbase[objno]= ((eeprom[0xFA+((objno+1)>>1)]>>(4*((objno&0x01)^0x01)))&0x07);
						    				jobj=read_obj_value((objno&0x07)+8);
						    				timerstate[objno]= jobj|0x10; // 0x10,0x11 fuer ende T2 (lamellenvestellzeit)
						    				timercnt[objno]= m + 0x80;
						    			}
										else timercnt[objno]=0;
						    			//timerbase[objno]=0;
							}
				#endif			
							switch (timer_state & 0x50){		
							case 0x10:
										timerstate[objno]=0; // wenn T2 abgelaufen dann nichts mehr machen
							break;		
				#ifdef dimmer
							case 0x40:
								 // 0x4x fuer Dimmer Funktion
										write_send( objno+8, timer_state );	// Langzeit Telegramm senden
										timerstate[objno]|=0x10;
										timercnt[objno] = eeprom[0xD8+(objno*4)]| 0x80 ;//0xD6 Faktor Telegrammwiederholung
										timerbase[objno]=(eeprom[0xFA+((objno+1)>>1)]>>(4*((objno&0x01)^0x01)))&0x0F;	//Basis Tele wdg
							break;
							case 0x50: // 0x50 Dimmer telegramm wiederholung
										timercnt[objno] = eeprom[0xD8+(objno*4)]| 0x80 ;//0xD6 Faktor Telegrammwiederholung
										send_obj_value(objno+8);
							break;
				#endif
							default:
							}
				}
			}   // ende if (timercnt == 0x80
				
		}
}
//





void port_schalten(void)		// Schaltet die Ports mit PWM, DUTY ist Pulsverh�ltnis
{
	unsigned char n, pattern;
 	//normaler out8 oder out4
	if(portbuffer & ~oldportbuffer) {	// Vollstrom nur wenn ein relais eingeschaltet wird
		TR0=0;
		AUXR1&=0xE9;	// PWM von Timer 0 nicht mehr auf Pin ausgeben


		PWM=0;			// Vollstrom an

		P0=portbuffer|0x0C;		// Ports schalten
		TF0=0;			// Timer 0 f�r Haltezeit Vollstrom verwenden
		TH0=0x00;		// 16ms (10ms=6fff)
		TL0=0x00;
		TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;
	}
	else P0=portbuffer|0x0C;

	rm_state=portbuffer ^ eeprom[RMINV];	// R�ckmeldeobjekte setzen
	for (n=0;n<4;n++) {	// R�ckmeldung wenn ein Ausgag sich ge�ndert hat
		pattern=1<<n;
		if((portbuffer&pattern)!=(oldportbuffer&pattern)) rm_send|=pattern;		//send_obj_value(n+12);
	}
	
	oldportbuffer=portbuffer;
	portchanged=0;
}


void bus_return(void)		// Aktionen bei Busspannungswiederkehr
{
	unsigned char n, bw, bwh,senden;
	__bit objval=0;
	portbuffer|= (PORTSAVE&0x0C);	// Verhalten nach Busspannungs-Wiederkehr
	portbuffer&=(PORTSAVE|0xF3);

	bw=eeprom[0xF6];
	for(n=0;n<=1;n++) {			// Ausg�nge 1-2
		bwh=(bw>>(2*n))&0x03;
		if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<n));
		if(bwh==0x02)  portbuffer=portbuffer | (0x01<<n);
	}
	oldportbuffer=0;
	portchanged=1;		// Post hinterlegen damit in delaytimer nach portschalten springt
	rm_state=portbuffer ^ eeprom[RMINV];	// R�ckmeldeobjekte setzen
	// R�ckmeldung bei Busspannungswiederkehr
	rm_send|=~portbuffer;// R�ckmeldung nur f�r Objekte mit Wert 0, da Wert 1 in normalem port_schalten eh gesendet wird
	
	for (n=2;n<4;n++){
		  senden=0;
		  timercnt[n]=0;// alle timer ausschalten
		  objects_l[n-2]=0;
		  objects_h[n-2]=0;
		  switch ((eeprom[0xCF] >> ((n & 0x01)*4)) & 0x0F)	// Funktion des objektes
			{
#ifndef dimmer
		  	case 0x01:// schalten
			timerstate[n]=0;
			case 0x03:// Jalousie
		//  case 0x04:// Wertgeber(lichtszene)		
				switch(eeprom[0xD5+(n*4)]&0xC0){
				case 0x40:
					objval=1;
					senden=1;
				break;	
				case 0x80:
					objval=0;
					senden=1;
				break;
				case 0xC0:
					portbuffer ^= (0x01<<n);//Bit im portbuffer invertieren, l�st eine Flanke aus
				}
			break;
#else
			case 0x02://dimmen austele
				if(eeprom[0xD7+(n*4)]&0x80){
					objval=0;
					senden=1;
					}
				if(eeprom[0xD8+(n*4)]&0x80){
					objval=1;
					senden=1;
				//ansonsten nichts tun !	
				}
			break;
#endif
			}
		  
		if (senden){
			write_obj_value(n,objval);// eis1, kein selftele, speichern ja
			while(!send_obj_value(n));
		}
		if((eeprom[0xD5+(n*4)]& 0x03)==2){ //bei invertierter Sperre Sperrobjekt setzen.
			in_blocked |= bitmask_1[n];
		}
		else{
			in_blocked &= (~bitmask_1[n]);
		}
	  }
	
}

void restart_app(void) 		// Alle Applikations-Parameter zur�cksetzen
{
	P0=0x0C;
	P0M1=0x00;		// Port 0 Modus push-pull f�r Ausgang
#ifdef MAX_PORTS_4
	P0M2= 0x03;// f�r 2in2out
#endif	
 

	TMOD=(TMOD & 0xF0) + 2;		// Timer 0 als PWM
	TAMOD=0x01;
	TH0=DUTY;		// Pulsverh�ltnis PWM
	AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
	TR0=1;			// Timer 0 starten (PWM)
	ET0=0;			// Interrupt f�r Timer 0 sperren
	IT0=1;			// Int type flag0, 1=flankengetriggert
	zf_state=0x00;		// Zustand der Zusatzfunktionen 1-4
	blocked=0x00;		// Ausg�nge nicht gesperrt
	timer=0;			// Timer-Variable, wird alle 130ms inkrementiert
  
	logicstate=0;
	delay_toggle=0;
	
/*	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	START_WRITECYCLE
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
	WRITE_BYTE(0x01,0x04,0x04)
#ifdef MAX_PORTS_4				// 4-fach Aktor
//	WRITE_BYTE(0x01,0x05,0x20)	// Devicetype 0x2062 = Jung Aktor 2134.16
//	WRITE_BYTE(0x01,0x06,0x71)// 2 out= 2071
#endif
//	WRITE_BYTE(0x01,0x07,0x01)	// Versionnumber of application programm
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
//	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	STOP_WRITECYCLE
	EA=1;						// Interrupts freigeben
	IT0=0;// ??
*/	RTCCON=0x81;				// RTC starten und OV flag setzen
	//EX0=1;
}
