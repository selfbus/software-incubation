/*
 *    _____ ______ __   __________  __  _______ *
 *   / ___// ____// /  / ____/ __ )/ / / / ___/ *
 *   \__ \/ __/  / /  / /__ / __  / / / /\__ \  * 
 *  ___/ / /__  / /__/ /__// /_/ / /_/ /___/ /  * 
 * /____/_____//____/_/   /_____/\____//____/   *  
 *                                      
 *  Copyright (c) 2010-2014 Andreas Krieger
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 * 
* 
 */



#include <P89LPC922.h>
#include "../lib_lpc922/Releases/fb_lpc922_1.5x.h"
#include  "fb_app_jalo2204regh.h"
#include "../com/debug.h"

unsigned char __at 0x00 RAM[00];
unsigned char  positions_req;
unsigned char __idata __at 0xFE-48 l_position_s_stored[4];
unsigned char __idata __at 0xFE-44 j_position_s_stored[4];
unsigned char __idata __at 0xFE-40 l_position_target[4];
unsigned char __idata __at 0xFE-36 j_position_target[4];
unsigned char __idata __at 0xFE-32 l_position_last[4];
unsigned char __idata __at 0xFE-28 l_position_stored[4];
unsigned char __idata __at 0xFE-24 j_position_stored[4];
unsigned char __idata __at 0xFE-20 l_position[4];
unsigned char __idata __at 0xFE-16 j_position[4];
unsigned char __idata __at 0xFE-12 l_position_int[4];
unsigned char __idata __at 0xFE-8 j_position_int[4];
unsigned char __idata __at 0xFE-4 l_position_int_pre[4];


unsigned char __at 0x10 timerbase[TIMERANZ];//10-1F Speicherplatz für die Zeitbasis und 4 status bits
unsigned char  timercnt[TIMERANZ];// speicherplatz für den timercounter und 1 status bit
unsigned char timerstate[TIMERANZ];// speicherplatz für den timercounter und 1 status bit
const unsigned char bitmask_1[8] ={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
const unsigned char drivetime_add_div[16] ={255,200,100,67,50,33,25,20,17,14,13,11,10,8,6,3};
const unsigned char shift_count[]={0,3,0,3};
const unsigned char basefaktor[]={1,1,1,4,64,128};
const unsigned char sunlogic[]={0,18,20,30};// logic table
/*				|	&	S2	S1	X
SUNval		00	0	0	0	0	0
SUNval		01	1	0	0	1	0
SUNval		10	1	0	1	0	0
SUNval		11	1	1	1	1	0
	
*/	

unsigned int __at 0x09  timer;		// Timer für Schaltverzögerungen, wird alle 130us hochgezählt
unsigned char __at 0x09 delay_toggle;			// um nur jedes 8. Mal die delay routine auszuführen
//var überschneidung ist Absicht
static __code unsigned char __at 0x1CfA blockedsave;//__at 0x1BFD
unsigned char  Tval;
unsigned char __at 0x0B objects_move;	// Werte der Objekte 0-7 (Ausgängsobjekte)
unsigned char __at 0x0C objects_smove;		// Werte der Objekte 16/17 (Zusatzfunktionen 1-4)
unsigned char __at 0x0D portbuffer;	// Zwischenspeicherung der Portzustände
unsigned char __at 0x0E oldportbuffer;// Wert von portbuffer vor Änderung (war früher ...0x29)
unsigned char __at 0x0F blocked;		// Sperrung der 4 Kanäle (1=gesperrt)
unsigned char zfstate;		// Zustand der Objekte 8-11 = Zusatzfunktionen 1-4
unsigned char oldblockvalue;//,zfout,zftyp;
//unsigned char logicstate;	// Zustand der Verknüpfungen pro Ausgang
//long timer;					// Timer für Schaltverzögerungen, wird alle 8 us hochgezählt
//unsigned char owntele;		// Anzahl der internen Verarbeitungen eines gesendeten Telegrammes (Rückmeldung)
//unsigned char respondpattern;// bit wird auf 1 gesetzt wenn objekt eine rückmeldung ausgelöst hat
unsigned char kanal[4];		// Wert des Kanalobjekts
unsigned char knr;
unsigned char drive_priority;
__bit portchanged;
//__bit handmode;







#ifdef zeroswitch
unsigned char portausgabe_on;
unsigned char portausgabe_off;
volatile unsigned char schalten_state;
unsigned char phival;
#endif


void write_value_req(unsigned char objno) 				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
{
unsigned char mode=0,kanalno=objno&0x03;
__bit objval = telegramm[7]&0x01;

	         if (objno<8 ){
	        	 if((!(drive_priority & 0x40))||!positions_req)object_schalten(objno,0,0,objval);	// Objektnummer 0-4 entspricht den Kanälen 1-4
	         }
	         else if ( objno <=11 )//Position Jalosousie
	        	 {
	        	 positions_req |=bitmask_1[kanalno+4];
	        	 j_position_target[kanalno]=telegramm[8];
	        	 //l_position_last[objno]=l_position[objno];
	        	 }
	         else if(objno <=15)
	         {
	        	 positions_req |=bitmask_1[kanalno];
	        	 l_position_target[kanalno]=telegramm[8];
	         }
	         else Sobject_schalten(objno,telegramm[7]&0x01);	// Objektnummer 16+17 entspricht den Sicherheitsfahrten 1 + 2
}

/** 
* Objektwert lesen wurde angefordert, read_value_response Telegramm zurücksenden
*
* 
* @return
* 
*/

void read_value_req(unsigned char objno)// Sendet nach Leseanfrage objektwert auf den BUS
{
	send_obj_value(objno+64);
}


unsigned long read_obj_value(unsigned char objno) 	// gibt den Wert eines Objektes zurueck
{
 	unsigned char ret_val=0;

	if(objno<8)
	{
		if(objects_move &(bitmask_1[objno])) ret_val=1;// lang und kurzzeitobjekte
	}
	else if(objno<12)ret_val=j_position[objno-8];// jalousie position
	else if(objno<16)ret_val=l_position[objno-12];// Lamelle Position
	else
	{
		if(objects_smove&(bitmask_1[objno-16])) ret_val=1;// sicherheit und sonne
	}
	return(ret_val);
}

/*
void write_obj_value(unsigned char objno,unsigned int objvalue)	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
{
	if(objno<8) {// kurz und lanzeit
		if(objvalue==0) objects_move &= 0xFF-(bitmask_1[objno]);
		else objects_move |=bitmask_1[objno];
	}
	else{
		objno-=16;// sicherheitsfahrt 16+17 Sonne 18,19
		if(objvalue==0) objects_smove &= (0xFF-(bitmask_1[objno]));
		else objects_smove |=bitmask_1[objno];//1<<objno;
	}
}
*/

//							Sicherheit 16,17; Sonne 18,19
//									16,17..18,19			0,1
//unsigned char allgemein;
void Sobject_schalten(unsigned char objno,unsigned char val)// Schaltet die Sicherheitsfunktionen
{
unsigned char k,zuordnung=0,sobj,blockstart,blockend,action,sunval,pos,pos_restore,polarity;
blockstart;blockend;pos_restore=0;
	if (objno >=20){		// wenn bypass aus delay timer...(16,17)+32
		sobj=objno&0x01;	// dann sobj ausfiltern
		polarity=0;				//state so setzen damit sperre aktiv wird
		val=0x01;		// dto für objektvalue
	}
	else {
		sobj=objno-16;				//sobj ("Sicherheitsobjektnummer")ist also 0 für Sicherheit1, 1 für Si 2
		polarity=(~eeprom[0xE2])>>6;//Polarität
	}
		if(val)objects_smove |= bitmask_1[sobj];//write_obj_value(objno & 0x1F ,val);		// Objektwert im userram speichern
		else objects_smove &= ~bitmask_1[sobj];
			if (sobj<2){
				pos=(objects_smove ^polarity)& 0x03; //polarity* die beiden sperrobjekte
				if(~pos & (sobj+1))set_entriegeln(sobj + 9);// Update objekt macht refresh auf Zeit 9/10  Zyklusüberwachung
				pos_restore=((~pos) &(eeprom[0xE9]>>6));// Position nachführen aktiviert?
				
				if(pos&0x01)zuordnung=0x0F;
				if(pos&0x02)zuordnung|=0xF0;
				zuordnung&=eeprom[0xF1];
				blocked =zuordnung |((zuordnung >>4) | (zuordnung<<4));
			}
			
			
			
			blockstart= blocked & ~oldblockvalue;//steigende Flanke der Blockade(sicherheit)
			blockend= ~blocked & oldblockvalue;	//fallende Flanke der Blockade(sicherheit)
			
//			if (!handmode){
			oldblockvalue=blocked;

			for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
				action=0;
				if(blockstart & 0x01){
					action=(eeprom[0xF0]>>(k<<1))&0x03;
					l_position_s_stored[k]=l_position[k];
					j_position_s_stored[k]=j_position[k];
				}// ende if(blockstart
				if(blockend & 0x01){
					if(pos_restore)
					{// Position nachführen
						l_position_target[k]=l_position_s_stored[k];
						j_position_target[k]=j_position_s_stored[k];
						
						positions_req|=bitmask_1[k];
						positions_req|=bitmask_1[k+4];
						
					}
					else action=(eeprom[0xEF]>>(k<<1))&0x03;
				}
				if(action){
						object_schalten(k+20,0,0,action>>1);
				}// ende if(action.. // (blockend...
				blockend=blockend>>1;
				blockstart=blockstart>>1;

				if(sobj>=2 && !(bitmask_1[k]& blocked))
				{	
					polarity=(eeprom[0xF3]>>7)|((eeprom[0xF4]>>6)&0x02);// polaritätsbits holen
					sunval=((objects_smove&0x0C)>>2)^(polarity^0x03);// sunval bilden
					zuordnung=(eeprom[0xE2+(k >>1)]>>(shift_count[k]))&0x07;// zuordnung holen
					action=bitmask_1[zuordnung]& sunlogic[sunval];// action mit logiktabelle bilden
					pos=eeprom[0xF3+k];
					
					if(action)// Jalousie und Lamelle nach Sonne Positionieren
					{
						pos=pos&0x7F;
						j_position_stored[k]=j_position[k];
						j_position_target[k]=pos + pos + (pos/2) + (pos/20);
						l_position_stored[k]=l_position[k];
						pos=eeprom[0xF7+k]&0x7F;
						l_position_target[k]=pos + pos + (pos/2) + (pos/20);
					}
					else 
					{
						if((eeprom[0xF7+k])&0x80)// nach Sonnenfkt ende Position nachführen
							
						{
							j_position_target[k]=j_position_stored[k];
							l_position_target[k]=l_position_stored[k];
						}
						else
						{
						sunval=eeprom[0xFB+k]&0xC0;// Parameter Aktion nach Sonnenfkt - Ende, wenn nicht nachführen
						if(sunval==0x40)j_position_target[k]=0;		//auf
						if(sunval==0x80)j_position_target[k]=255;	// ab
						if(sunval==0x80)timercnt[k+4]=0;		//Langzeit stop
						}
					}
					positions_req|=(bitmask_1[k+4]|bitmask_1[k]);

				}
			
			}// ende for(k=0;k...
			
//		}//ende if !handmode
}//ende Sobject_schalten



void object_schalten(unsigned char objno,unsigned char value, unsigned char mode ,__bit objstate)	// Schaltet einen Ausgang gemäß objstate und den zugörigen Parametern
{
    unsigned int lamelle_total=0; 
	unsigned char port_pattern,kwin,kwout,faktor=1,lz_ue,tmp; //,objflags
	unsigned char delay_target,pluszeit,diff=0;//,delay_onoff,
	__bit off_disable;


	off_disable;
		kwin = kanal[objno & 0x03]& 0x0f;// kwin heisst KanalWertIN. Bit 0+1 Relaise status, Bit 4+5 gewünschter Relaise status
		kwout=kwin;
		port_pattern=bitmask_1[objno&0x07];//done. port_pattern=0x01<<(objno&0x0F)
		if (objstate) objects_move|=port_pattern;//write_obj_value(objno & 0x07,1);		// Objektwert im userram speichern
		else objects_move&=(~port_pattern);//write_obj_value(objno & 0x07,0);
		if((port_pattern & blocked)==0  ||(objno >=16)) {	// Sperre behandeln
		objno=objno&0x07;	// damit die bypassobjekte 8-15 wieder 0-7 sind!

		
// Pausezeit berechnen..

			if (objno<0x04){			//+++++ kurzzeitobjekt +++++
				if(!mode)
				{
				delay_target = (eeprom[0xE8+(objno>>1)]>>(shift_count[(objno)])&0x07)|0x80;// zeitbasis aus eeprom holen
				faktor=eeprom[0xEA+objno];// faktor holen um dann auf 0 zu prüfen
				}
				else
				{
				//zeit berechnen
					delay_target=0x42;//32ms
					diff=value - l_position[objno];
					l_position_target[objno]= value;
					if(value>l_position[objno])objstate=1;// soll > ist -->  ab
					else if(diff)// wenn tmp nicht 0 dann ist soll < ist --> auf
					{
					objstate=0;// state auf auf
					diff= -diff;// differenz negieren
					}
					else
						{
						faktor=0;
						positions_req &= (~bitmask_1[objno]);
						}

				}
				pluszeit=faktor + (faktor/drivetime_add_div[(eeprom[0xE5]>>2)&0x0F]);// 3% zeit bei "auf" 
				if(pluszeit<faktor)pluszeit=255;
				if(faktor){
					if (kwin&0x33){					// wenn faehrt,dann stop
						  set_pause(objno,kwin&0x03);
						  //write_delay_record((objno&0x03)+11, 0x02, timer + pause);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
						  kwout=kwin&0xCC;	// Fahrt in beide Richtungen stoppen
						  timerbase[objno]&=0x3F;	// kurzzeit löschen
						  timerstate[objno]=0;	// kurzzeit löschen
						  timerbase[objno+4]&=0x3F;  // lanzeit löschen
						  timerstate[objno+4]=0;  // lanzeit löschen
					}
					else if(faktor){
						timerbase[objno]=delay_target;
						timerstate[objno]=0x01+objstate;
						if (objstate==0){	//----- auf -----
						  //if ((faktor)){//(!(kwin&0x33))&&	//wenn stillstand und faktor>0  dann step
							  kwout=kwin|0x10;
							  kwout=kwout&0xDF;
							  //timerbase[objno]=delay_target;
							  timercnt[objno]=pluszeit;
							 // timerstate[objno]=0x01;
						  //}
						}
						else{				//----- ab -----
						  //if ((faktor)){//(!(kwin&0x33))&&		// wenn stillstand dann step
							  kwout=kwin|0x20;
							  kwout=kwout&0xEF;
							  //timerbase[objno]=delay_target;
							  timercnt[objno]=faktor;
							 // timerstate[objno]=0x02;
						 // }
						}//ende ab
					}// ende if (faktor)
				}// ende wenn fährt
			}// ende kurzzeitobjekte
			
			else{				//++++++ Langzeitobjekt +++++++
					//delay_target=zeit(0xFB,0xFC,0xDA,objno&0x03);// zeit aus eeprom holen

					delay_target=((eeprom[0xFB+((objno&0x03)>>1)]>>(shift_count[objno&0x01]))&0x07) | 0x80;// zeitbasis aus eeprom holen
					tmp = eeprom[0xDA+(objno&0x03)];//  fahrzeit-faktor
					
					if(!mode)
					{
						faktor = tmp + (tmp>>2);// +25% zeit bei langzeit 
					}
					else // mode Positionieren
					{
						diff=value-j_position[objno&0x03];
						if(value>j_position[objno&0x03])objstate=1;// soll > ist -->  ab
						else	// wenn tmp nicht 0 dann ist soll < ist --> auf
						{
						objstate=0;// state auf auf
						diff= -diff;// differenz negieren
						}
						faktor=((unsigned int )tmp*diff)>>8;
						tmp=faktor;
					}
					pluszeit=faktor + (faktor/drivetime_add_div[(eeprom[0xE5]>>2)&0x0F]);// zeit bei "auf" 
					if(faktor<tmp)faktor=255; // bei overflow auf 255 setzen
					if(pluszeit<faktor)	pluszeit=255;// bei overflow auf 255 setzen
					lz_ue=((eeprom[0xF2]>>objno)&0x01);		//lz_ue bedeutet: langzeit unendlich
					if(faktor){
			        	l_position_last[0]= l_position_last[0];//Dieser Unsinn spart vie flash...
						if (objstate==0){// --- auf ----
							if (!lz_ue) timerstate[objno]=0x01;
							else  timerstate[objno]=0x09;
							kwout=kwin|0x10;
							timercnt[objno]=pluszeit;
	
							if (kwin&0x11){		//läuft bereits, also nachtriggern
								timerbase[objno]=delay_target;
							 }
							if (!(kwin&0x33)){	//wenn stillstand, dann move
								timerbase[objno]=delay_target;
							  }
							   if (kwin&0x22){		// wenn fahrt in andere richtung
								  set_pause(objno,0x05);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
								  kwout=kwout&0xDF;
								  timerbase[objno]=delay_target & 0x7F;// timer-run für den move löschen
							  }
						}//ende auf
	
						else{			//  --- ab ----
							if (!lz_ue) timerstate[objno]=0x02;
							else  timerstate[objno]=0x0A;
							 kwout=kwin|0x20;//  neu setzen da in delay nach rechts kommt
							 timercnt[objno]=faktor;
	
							if (kwin&0x22){		//läuft bereits, also nachtriggern
								timerbase[objno]=delay_target;
							 }
							if (!(kwin&0x33)){	//wenn stillstand, dann move
								timerbase[objno]=delay_target;
							  }
							if (kwin&0x11){					// wenn fahrt in andere richtung
								set_pause(objno, 0x06);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
								kwout=kwout&0xEF;
								timerbase[objno]=delay_target & 0x7F;// timer run des langzeit löschen
							  }
						}//ende ab
					}
					else positions_req &= (~bitmask_1[objno]);
					timercnt[objno-4]=0;
					timerstate[objno-4]=0;
					timerbase[objno-4]&=0x3F; 
			}// ende langzeitobjekte +++++++
			
			kwin=kwout;
			if (objno<=7){
				tmp=timerstate[((objno & 0x03)+11)]& 0x07;
				//rs_send(tmp);
				if (((tmp&0x07)<4)&& (tmp & (kwout>>4) & 0x03)){
				//	rs_send('L');
					timerbase[(objno&0x03)+11]=0; 
					timercnt[(objno&0x03)+11]=0;//gleiche Richtung: Pause löschen
					timerstate[(objno&0x03)+11]=0;
					tmp=0;
				}
				
				if(tmp & 0x04){//wenn Pause wegen umschalten läuft,Kanal "ist" löschen.
				//	rs_send('P');
					kwout=kwout&0xF0;
				}
				else {
					if(!(tmp&0x07)){
					kwout=kwin>>4;//wenn keine Pause Läuft, dann kanal "soll" in "ist" kopieren
				//	rs_send ('S');
					}
				}
			}
			kanal[objno&0x03]=kwout;
			portchanged=1;
		} 

} //ende object_schalten(Objno,position,mode,bitval)	



unsigned int calculate_position(unsigned char kanal)
{
	unsigned char n=kanal&0x03,base;
	unsigned int l_laufzeit;
	base = eeprom[0xFD+(n>>1)];//basen der Lamellenlaufzeit Kanal 1,2/3,4
	if(n&0x01)base=base>>3;		// wenn ungerade Kanalzahl 3 nach rechts
	base=base&0x07;				// basis maskieren  //
	if (base>=3)l_laufzeit=((unsigned int)(eeprom[0xDE + n])* basefaktor[base]);
	else l_laufzeit=(unsigned int)eeprom[0xDE + n]>>2;
	if(kanal<4)// Lamellenposition berechnen
    {
		l_position[n]= ((((unsigned int)l_position_int[n])<<8)-l_position_int[n])/l_laufzeit;
    }
    if(kanal<8)
	j_position[n]=(((unsigned int)j_position_int[n]<<8)-j_position_int[n])/eeprom[0xDA + n];
    return l_laufzeit;// Lamellenlaufzeit zurückgeben
 //   else
 //   {
   	
 //   }
}

const unsigned int timerflagmask[]={0x0000,0x0000,0x0000,0x0008,0x0080,0x0800};

void delay_timer(void)	// zählt alle 8 ms die Variable Timer hoch und prüft Queue
{
	
	unsigned char objno,delay_state,m,n;//
	unsigned int timerflags;

	RTCCON=0x61;		// RTC Flag löschen
	objno=0;
	timer++;
		timerflags = timer&(~(timer-1));
//		for(n=0;n<4;n++){
//			if(timerflags & 0x0001)// positive flags erzeugen und schieben
				for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
				n=m&0x03;//n ist die der timer entsprechenden Kanalnummer
				if(timerbase[m]& 0xC0){// wenn run-bit gesetzt
					if((timerbase[m]==0x82)||(timerflags & (timerflagmask[timerbase[m]&0x3f]))){// wenn das flag mit der gespeicherten base übereinstimmt						
						if (timercnt[m]>0x00 && timerbase[m]&0x80){// wenn der counter läuft...
							timercnt[m]=timercnt[m]-1;// den timer [m]decrementieren
						}// end if (timercnt...
						if( m<8&&(timerflags & (timerflagmask[timerbase[n+4]&0x3f])))// posiotion Jalo if(m>=4 && m<8)
							{
								if (kanal[n]&0x01)// er fährt auf
							{
								if (j_position_int[n])j_position_int[n]--;
								
							}
							if (kanal[n]&0x02)// er fährt ab
							{
								if (j_position_int[n]< eeprom[0xDA + n])j_position_int[n]++;
							}
						}
					}
				}
					if(m<8 &&(timercnt[m]>0)){ // Position Lamelle Basis= 8ms intern!!
						if (kanal[n]&0x01)// er fährt auf
						{
							l_position_int_pre[n]--;
							if ((l_position_int_pre[n]&0x03)==0 && l_position_int[n])l_position_int[n]--;
							
							//l_position[n]=(int)timercnt[m]/
						}
						if (kanal[n]&0x02)// er fährt ab
						{
							l_position_int_pre[n]++;
							if((l_position_int_pre[n]&0x03)==3)
							{
							//	base = eeprom[0xFD+(n>>1)];//basen der Lamellenlaufzeit Kanal 1,2/3,4
							//	if(n&0x01)base=base>>3;		// wenn ungerade Kanalzahl 3 nach rechts
							//	base=base&0x07;				// basis maskieren (eeprom[0xDE + n])* basefaktor[base])
								if (l_position_int[n]< calculate_position(n+8)) l_position_int[n]++;
							}
						}
						calculate_position(n);
						if(timerbase[n]&0x40)
						{
							if(kanal[n]&0x01 && l_position[n]<=l_position_target[n])
								{
								timercnt[n]=0x00;
								timerbase[n]=0x80;
								}
							if(kanal[n]&0x02 && l_position[n]>=l_position_target[n])
								{
								timercnt[n]=0x00;
								timerbase[n]=0x80;
								}
							
						}
						
					}// end position Lamelle

				 // }//end if(timerbase...
				  
				}// end  for(m..
		
		// ab Hier die aktion..
		//Positionen nachführen
	// Adressen der ermittleten Fahrzeit: faktor: 0xDA+objno; basis 0xFB,0xFC..0-2,3-5
	// basis= eeprom[0xFB+(m>>1)]>>((m&0x01)*3))&0x03
	//(eeprom[0xFB+((objno&0x03)>>1)]>>(3*(objno&0x01))&0x07)

		for(objno=0;objno<=15;objno++) {
			//n=m&0x03;
			delay_state=timerstate[objno];			//status des timer-records
			if(delay_state) {	//delay_state!=0x00				// 0x00 = delay Eintrag ist leer   
				if(timercnt[objno]==0 && (timerbase[objno]&0x80)) { 	// wenn der cnt null und run=1, also zeit ist abgelaufen...
					if (objno<=7){// wenns ein kurz oder langzeit objekt ist...
						timerbase[objno]&=0x3F;
						//timercnt[objno]=0; // ist doch eh schon 0 !
						if(!(timerstate[objno]&0x08)){
							kanal[objno&0x03]=0x00;
						}
						else kanal[objno&0x03]|=kanal[objno&0x03]<<4;
						
						timerstate[objno]=0;
					    set_pause(objno,(delay_state));// einsch. verz "pause" für eventuelle Fahrt in gegenrichtung
					    if(objno>=4 && positions_req & bitmask_1[objno])
					    {
					    l_position_target[objno-4]= l_position_last[objno-4];
					    positions_req&=(~bitmask_1[objno]);
					    positions_req|=bitmask_1[objno-4];
					    }
					    if(objno<4 && positions_req & bitmask_1[objno])
					    {
					    	 positions_req&=(~bitmask_1[objno]);
					    						   
					    }
					}
					if (objno==9 ){	//Sicherheit 1
						if (delay_state == 0x01){
							timerstate[9]=0x02;// wenn ziel erreicht in delrec sichern
							Sobject_schalten(48,1);// und Sicherheitsobjekt über bypass schalten 16+32
						}
						//rs_send('1');
					}
					if (objno==10 ){	//Sicherheit 2
						if (delay_state == 0x01){
							timerstate[10]=0x02;// wenn ziel erreicht in delrec sichern
							Sobject_schalten(49,1);// und Sicherheitsobjekt über bypass schalten 17+32
						}
						//rs_send('2');
					}
					if ((objno>=11) && (objno<=14)){// die Pausezeit der Kanaele
					kanal[objno-11]=kanal[objno-11]>>4;			// die oberen 4 bit des kanals sind die neue value.
					timerbase[objno]=0;
					timercnt[objno]=0;			//timer loeschen
					timerstate[objno]=0;
					if(timerstate[objno-7]&0xF7)timerbase[objno-7]|=0x80;// timer run-bit des zugehörigen Langzeitobjektes setzen
					}
/*					if (objno>=15){// handmode kurz/langtele + einschaltverz + ausschaltverz
						//hand
						if (delay_state == 0x12) timerstate[15]=0x22; // wenn ziel 2 erreicht,  sichern
						if (delay_state == 0x01){
							timerbase[15]=0x80 + 3;
							timerstate[15]=0x12;
							timercnt[15]= 20;// wenn ziel 1 erreicht , sichern und restzeit fuer ziel 2 schreiben
						}
							 //2sek.langer Tastendruck setzen
						if (delay_state == 0x04) timerstate[15]= 0x08;// wenn ziel erreicht , sichern
					}
*/				 portchanged=1;
				}//ende if(deval==..
			}//ende if(delay_state...
		}//ende for (objno=0;...
/*		
		if (eeprom[0xE5]& 0xC0){
			handsteuerung();   // Handbetätigung nur jedes 8.mal ausführen
		}
*/
		
}// ende delay_timer
	

unsigned char ledport;
/*
void handsteuerung(void)
{
	//#ifdef HAND		// für Handbetätigung
		unsigned char n;
		unsigned char tmph;
		unsigned char key_pattern,Tasten;
		key_pattern,tmph;
	//#endif

	if((TMOD&0x0F)==0x02 && fb_state==0) {
//	ET1=0;	
//	while(  (!PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen
	
#ifdef MAX_PORTS_8

while(  (!PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen

#endif
#ifdef MAX_PORTS_4
while( (TMOD&0x0F)==0x02 && ( TL0>0x72));// PWM scannen um "Hand"-Tasten abzufragen
#endif


#ifdef MAX_PORTS_8		
		key_pattern=(0x01<<(delay_toggle&0x07));
		P0 = ~key_pattern;
		if (!P1_3 && !ledport)ledport=0x08+(delay_toggle&0x07);
#endif
#ifdef MAX_PORTS_4
		key_pattern=(0x01<<(delay_toggle&0x03));
		P0 = ~key_pattern;
		P0_5=1;
		if(!P0_5 && !ledport)ledport=0x08+(delay_toggle&0x03);	
#endif	
		P0=oldportbuffer; 
		
		//if (interrupted)Tasten=8; // wenn unterbrochen wurde verwerfen wir die Taste
#ifdef MAX_PORTS_8		
		if (key_pattern==0x80)
#endif
#ifdef MAX_PORTS_4			
		if (key_pattern==0x08)
#endif
		{
			Tasten=ledport;
			ledport=0;
		

			//	Tasten = Tval; // ##############  <----- Hier wird Handbetätigung quasi mit ausgeschaltet !! #########################
			if (Tasten & 0x08 ){
				if (!Tval ){// steigende Flanke des Tasters 
					//????? tmph=timerstate[15];
					//write_delay_record(15,0x01,timer+50);//50 kurz-lang 0,4 sek
					timerstate[15]=0x01;
					timerbase[15]=0x80 + 2;
					timercnt[15]= 50;
				}
			}	
			else{
				if ( Tval & 0x08){ // wenn tasten >7 und Tval <=7 also taste losgelassen...
					if (timerstate[15]&0x20){
						handmode = !handmode;
						timerbase[15]=0;
						timerstate[15]=0;
						timercnt[15]=0;
						if (handmode){
							for(n=0;n<=3;n++) kanal[n]=0x00;
							portchanged=1;
						}
						else{//wenn nach dem toggeln nicht handmode also ausgeschaltet
							sobj_update();
						}
					}
					if (handmode){// wenn handmode aktiv...
						if (timerstate[15]&0x02){// status der zeit=2 also abgelaufen..
							object_schalten(((Tval&0x07)>>1)+12,0,(Tval&0x01));
							}
						else{
							object_schalten(((Tval&0x07)>>1)+8,0,(Tval&0x01));
						}	
					}//ende if(handmode...		
					//write_delay_record(15,0x04,timer+1875);//handbetätigung aus starten
					timerbase[15]=0x80 + 3;//130ms
					timerstate[15]=0x04;
					timercnt[15]=116;//=15 Sekunden
				}// ende if Tval
			}	
		Tval=Tasten;

		if(timerstate[15]&0x08){
			handmode=0;//handmode automatisch ausschalten
			//clear_delay_record(15);
			timerbase[15]=0;
			timerstate[15]=0;
			timercnt[15]=0;
			sobj_update();
		}
//		ET1=1;
	  }// ende if (key_pattern...
	}// ende if( (TMOD&0x0F)==0x02
}//ende handsteuerung...
*/

/*
void sobj_update(void)
{
	Sobject_schalten(16,read_obj_value(16)&0x01);
	Sobject_schalten(17,read_obj_value(17)&0x01);
}
*/
void set_pause(unsigned char objnr,unsigned char Pstate)// setzt die Pausezeit und traegt Pstate in timerstate[ ] ein
{
	unsigned char pause,pauseobj;
	pauseobj=(objnr&0x03)+11;
	timerstate[pauseobj]=Pstate;
	switch ((eeprom[0xEE]>>((objnr&0x03)<<1))&0x03) { // Dauer zwischen auf und ab
	case 0:	// 0,5s
		pause=4 ;
	break;
	case 1:	// 1s
		pause=8 ;
	break;
	case 2:	// 2s
		pause=16 ;
	break;
	default:	// 5s
		pause=39 ;
	break;
	}
    calculate_position(objnr); // Position der Lamelle kalkulieren
    if(objnr>=4)send_obj_value((objnr&0x03)+4);							//in Pause-state sichern
    while(!send_obj_value((objnr&0x03)+12));// und senden
	timercnt[pauseobj]=pause;
	timerbase[pauseobj]= 3 | 0x80;

	//write_delay_record((objnr & 0x03)+ 11,Pstate,pause + timer);
}// ende set_pause()

const unsigned char svfaktorarray[]={0,2,4,6,8,10,12,14,16,18,20,22,36,72,109,218};
void set_entriegeln(unsigned char zeitnr)// Setzt die zyklische überwachungszeit
{
	unsigned char svbase;
	zeitnr;
	//	long svzeit;
	svbase=eeprom[0xD9]&0x0F;
	if(svbase){
		timercnt[zeitnr]=svfaktorarray[svbase];
		timerbase[zeitnr]=5 | 0x80;
		timerstate[zeitnr]=0x01;
	}
	else{
		timerbase[zeitnr]=0;
		timerstate[zeitnr]=0;
	}

}



#ifdef zeroswitch
void EX0_int (void) __interrupt (0)
{	
	schalten_state=1;// Zeitverzögerung zum Einschalten setzen
	TR0=0;
	AUXR1&=0xE9;	// PWM von Timer 0 nicht mehr auf Pin ausgeben
	PWM=0;			// Vollstrom an
	TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
	TH0=0xF2;		// 1.8ms (10ms=6fff)
	TL0=0x80;		
	TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
	TAMOD=0x00;
	TR0=1;
	EX0=0;
	ET0=1;
	
}

	
void timer0_int(void) __interrupt(1)	
	{
	switch (schalten_state)
	{
		case 0 : // Zeitverzögerung zum Einschalten setzen
		break;
		case 1://Einschalten und zeitverzögerung zum Ausschalten setzen
			schalten_state=2;
			P0=portausgabe_on;
			TF0=0;			// Timer 0 für Ausschaltzeitpunkt
			TH0=0xFF-phival;		// phival= 0 bis 35 einstellbar(main)
			TL0=0xFF;		
			TR0=1;
			
			break;
		case 2:
			schalten_state=3;
			P0=portausgabe_off;
			TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
			TH0=0x02;		// 16ms (10ms=6fff)
			TL0=0x00;		
			TR0=1;
		break;
		case 3:// PWM wieder einschalten
			TMOD=(TMOD & 0xF0) + 2;			// Timer 0 als PWM
			TAMOD=0x01;
			TH0=DUTY;
			TF0=0;
			AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben
			PWM=1;			// PWM Pin muss auf 1 gesetzt werden, damit PWM geht !!!
			TR0=1;
			ET0=0;
			schalten_state=0;
		break;
		default:
		}
}
#endif


void port_schalten(void)		// Schaltet die Ports mit PWM, DUTY ist Pulsverhältnis
{
	//unsigned char n, pattern;
	unsigned char kmod;
	portbuffer=0;
	if (eeprom[0xE4]& 0x80) kmod=0x01;		// bit 7 ist Kanal-mode
	else kmod=0x03;
	for (knr=0;knr<=0x03;knr++){
		portbuffer=portbuffer|((kanal[knr & kmod]& 0x03)<<(knr<<1));
		}
		
#ifdef zeroswitch //### Nullspannungsschalter ###
	
 #ifdef SPIBISTAB	//serielle schiebeausgang für bistabile Relaise
		spi_2_out(sort_output(portbuffer));		// Ports schalten
		PWM=0;
		TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
		TH0=0x6f;		// 16ms (10ms=6fff)
		TL0=0xff;
		TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;

/*	rm_state=portbuffer ^ eeprom[RMINV];	// Rückmeldeobjekte setzen
	for (n=0;n<8;n++) {	// Rückmeldung wenn ein Ausgag sich geändert hat
		pattern=1<<n;
		if((portbuffer&pattern)!=(oldportbuffer&pattern)) send_obj_value(n+12);
	}
*/
	oldportbuffer=portbuffer;
	portchanged=0;

 #else	// also normaler out8 oder out4 mit zeroswitch
	if(!EX0 && !schalten_state) {	//nur wenn schaltenstate inaktiv 
		portausgabe_on=portbuffer | oldportbuffer;
		portausgabe_off=portbuffer;//& oldportbuffer;

		IE0=0;// interrupt flipflop löschen
		EX0=1;// zero U interrupt einschalten


		rm_state=portbuffer ^ eeprom[RMINV];	// Rückmeldeobjekte setzen
		for (n=0;n<8;n++) {	// Rückmeldung wenn ein Ausgag sich geändert hat
			pattern=1<<n;
			//if((portbuffer&pattern)!=(oldportbuffer&pattern)) rm_send|=pattern;		//send_obj_value(n+12);
		}

		oldportbuffer=portbuffer;
		portchanged=0;
	}
 #endif
#else // sonst normaler sporatisch schaltender out
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


	oldportbuffer=portbuffer;
	portchanged=0;
	
#endif	
#endif
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
	unsigned char n;
	blocked=blockedsave;		// Ausgänge gesperrt?
	timer=0;			// Timer-Variable, wird alle 8 ms inkrementiert
	for (n=0;n<=15;n++){// Löschen aller zeiten
		timerstate[n]=0;
		timerbase[n]=0;
		timercnt[n]=0;
	}
	positions_req=0;
	for (n=0;n<=3;n++){
		if(((eeprom[0xF1]>>n)&0x11)==0 ){// wenn keine Sperrfunktion zugewiesen
			blocked &= ~(0x11<<n);  // dann blocked löschen, damit nach umpara
		}							// nicht stehen bleibt.
		switch(eeprom[0xD9]& 0xC0){
		case 0x40:
			object_schalten(n+20,0,0,0);
		break;
		case 0x80:
			object_schalten(n+20,0,0,1);
		break;
		default:
		}
		
	}

	oldportbuffer=0; 	// auf 0 setzen, da sonst kein Vollstrom aktiviert wird
	portchanged=1;		// Post hinterlegen damit in delaytimer nach portschalten springt
// nachfolgendes vorerst auskommentiert:
	set_entriegeln(9);	// Überwachungszeit Sicherheitsfahrt
	set_entriegeln(10);	// dto

 
}

void restart_app(void) 		// Alle Applikations-Parameter zurücksetzen
{

	Tval=0x00;
//	handmode=0;

	P0=0;
	P0M1=0x00;		// Port 0 Modus push-pull für Ausgang
#ifdef MAX_PORTS_8
	P0M2=0xFF;
#endif
#ifdef MAX_PORTS_4
	P0M2=0x0F;
#endif

#ifdef SPIBISTAB
	PWM=1;
#else 
	TMOD=(TMOD & 0xF0) + 2;		// Timer 0 als PWM
	TAMOD=0x01;
	TH0=DUTY;		// Pulsverhältnis PWM
	AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
	TR0=1;			// Timer 0 starten (PWM)
#endif
#ifdef zeroswitch
	schalten_state=0;
#endif	
	ET0=0;			// Interrupt für Timer 0 sperren
	IT0=1;
	blocked=0x00;		// Ausgänge nicht gesperrt
	timer=0;			// Timer-Variable, wird alle 8ms inkrementiert
  
//	logicstate=0;
/*	delay_toggle=0;
	
	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	START_WRITECYCLE
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
	WRITE_BYTE(0x01,0x04,0x04)
//	WRITE_BYTE(0x01,0x05,0x20)	// Devicetype 0x2069 = Jung Aktor 2204.02
//	WRITE_BYTE(0x01,0x06,0x70)	
//	WRITE_BYTE(0x01,0x07,0x01)	// Versionnumber of application programm
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
//	WRITE_BYTE(0x01,0x12,0x9A)	// COMMSTAB Pointer
	STOP_WRITECYCLE
	EA=1;						// Interrupts freigeben
*/
	RTCCON=0x60;		// RTC Flag löschen
	RTCH=0x01;			// reload Real Time Clock
	RTCL=0xCD;			// 8ms
	RTCCON=0x61;
	//if(eeprom[0xE3]&0x80) priority=0;
	//else priority=1;
	drive_priority=(eeprom[0xE3]&0xC0);

}
