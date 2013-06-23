/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2012-2013 Andreas Krieger
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 * 
* 
 */



#include <P89LPC922.h>
#include "../lib_lpc922/Releases/fb_lpc922_1.4x.h"
#include  "fb_app_rollo11.h"


unsigned char __at 0x00 RAM[00]; 
unsigned char __at 0x10 timerbase[TIMERANZ];//10-1F Speicherplatz für die Zeitbasis und 4 status bits
unsigned char  timercnt[TIMERANZ];// speicherplatz für den timercounter und 1 status bit
unsigned char timerstate[TIMERANZ];// speicherplatz für den timercounter und 1 status bit

unsigned int __at 0x09  timer;		// Timer für Schaltverzögerungen, wird alle 130us hochgezählt
unsigned char __at 0x09 delay_toggle;			// um nur jedes 8. Mal die delay routine auszuführen
//var überschneidung ist Absicht
static __code unsigned char __at 0x1BFD blockedsave;
unsigned char  Tval;
unsigned char __at 0x0B objects_move;	// Werte der Objekte 0-7 (Ausgängsobjekte)
unsigned char __at 0x0C objects_smove;		// Werte der Objekte 16/17 (Zusatzfunktionen 1-4)
unsigned char __at 0x0D portbuffer;	// Zwischenspeicherung der Portzustände
unsigned char __at 0x0E oldportbuffer;// Wert von portbuffer vor Änderung (war früher ...0x29)
unsigned char __at 0x0F blocked;		// Sperrung der 4 Kanäle (1=gesperrt)
//unsigned char logicstate;	// Zustand der Verknüpfungen pro Ausgang
//__bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszuführen
//__bit portchanged;
//unsigned char rm_send;		// die von der main zu sendenden Rückmeldungen

//unsigned char serbuf;			// Zwischenspeicher des Zustandes der Tasten (Handbetaetigung)

unsigned char zfstate;		// Zustand der Objekte 8-11 = Zusatzfunktionen 1-4
unsigned char oldblockvalue;//,zfout,zftyp;
//unsigned char logicstate;	// Zustand der Verknüpfungen pro Ausgang
//long timer;					// Timer für Schaltverzögerungen, wird alle 8 us hochgezählt
//unsigned char owntele;		// Anzahl der internen Verarbeitungen eines gesendeten Telegrammes (Rückmeldung)
//unsigned char respondpattern;// bit wird auf 1 gesetzt wenn objekt eine rückmeldung ausgelöst hat
unsigned char kanal[4];		// Wert des Kanalobjekts
unsigned char knr;

__bit portchanged,state;
__bit handmode;







#ifdef zeroswitch
unsigned char portausgabe_on;
unsigned char portausgabe_off;
volatile unsigned char schalten_state;
unsigned char phival;
#endif


void write_value_req(unsigned char objno) 				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
{

//	  unsigned char objflags,gapos,assno,n,gaposh;
	 
/*	    gaposh=0;

	    gapos=gapos_in_gat(telegramm[3],telegramm[4]);	// Position der Gruppenadresse in der Adresstabelle
	    if (gapos!=0xFF)	// =0xFF falls nicht vorhanden
	    {
		 // atp=eeprom[ASSOCTABPTR];			// Start Association Table
	      assno=eeprom[ASSOCTABPTR];			// Erster Eintrag = Anzahl Einträge
	      for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
	      {
	        gaposh=eeprom[eeprom[ASSOCTABPTR]+1+(n*2)];
	        if(gapos==gaposh)					// Wenn Positionsnummer übereinstimmt
	        {
	          objno=eeprom[eeprom[ASSOCTABPTR]+2+(n*2)];				// Objektnummer
	          objflags=read_objflags(objno);			// Objekt Flags lesen
*/
	         if (objno<8 && !handmode) object_schalten(objno,telegramm[7]&0x01);	// Objektnummer 0-4 entspricht den Kanälen 1-4
	 
	         if (objno>=16 && objno<=17)Sobject_schalten(objno,telegramm[7]&0x01);	// Objektnummer 16+17 entspricht den Sicherheitsfahrten 1 + 2

//	        	}// ende if(gapos...
//	        }// ende for(n=0;n...
	      //rollo if (portbuffer != userram[0x29])port_schalten(portbuffer);	//Port schalten wenn sich ein Pin geändert hat
//	    }//ende if(gapos!=...
	 //   owntele=0;
	 //   respondpattern=0;
	    //rs_send(blocked);
	}//ende void write_value_request(....
	
/*##### vom out8 ###
 *unsigned char objno,objflags,assno,n,gaposh,zfout,zftyp, gapos;
  unsigned char blockstart, blockend, block_polarity;
  unsigned char obj_bitpattern, zf_bitpattern;
 
    gaposh=0;

    gapos=gapos_in_gat(telegramm[3],telegramm[4]);	// Position der Gruppenadresse in der Adresstabelle
    if (gapos!=0xFF)					// =0xFF falls nicht vorhanden
    {
	  //atp=eeprom[ASSOCTABPTR];			// Start Association Table
      assno=eeprom[eeprom[ASSOCTABPTR]];				// Erster Eintrag = Anzahl Einträge
 
      for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
      {
        gaposh=eeprom[eeprom[ASSOCTABPTR]+1+(n*2)];
        if(gapos==gaposh)					// Wenn Positionsnummer übereinstimmt
        {
          objno=eeprom[eeprom[ASSOCTABPTR]+2+(n*2)];				// Objektnummer
          objflags=read_objflags(objno);			// Objekt Flags lesen
//obj_bitpattern prüfen !!!
          obj_bitpattern=0x01<<(objno-8);
          
          if (objno<8) object_schalten(objno,telegramm[7]&0x01);	// Objektnummer 0-7 entspricht den Ausgängen 1-8

          if (objno>7 && objno<12)	// Objektnummer 8-11 entspricht den Zusatzfunktionen 1-4
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
              case 0x00:			// Verknüpfung
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
						timercnt[zfout-1]=0;//delrec[(zfout-1)*4]=0;	// ggf. Eintrag für Schaltverzögerung löschen
                	}
                }
              //port_schalten(portbuffer);
              break;
              //case 0x02:			// Zwangsstellung
            }
          }
        }
      }
      if (portbuffer != oldportbuffer) portchanged=1;//post für port_schalten hinterlegen
      //port_schalten(portbuffer);	//Port schalten wenn sich ein Pin geändert hat
    }
    //owntele=0;
    //respondpattern=0;

}
*/

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
/*	unsigned char objno, objflags;
	unsigned int objvalue;
	
	objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
	if(objno!=0xFF) {	// falls Gruppenadresse nicht gefunden
		
		objvalue=read_obj_value(objno);		// Objektwert aus USER-RAM lesen (Standard Einstellung)

		objflags=read_objflags(objno);		// Objekt Flags lesen
		// Objekt lesen, nur wenn read enable gesetzt (Bit3) und Kommunikation zulaessig (Bit2)
		if((objflags&0x0C)==0x0C) send_obj_value(objno+64); //send_value(0,objno,objvalue);
    }
*/
}


unsigned long read_obj_value(unsigned char objno) 	// gibt den Wert eines Objektes zurueck
{
 	unsigned char ret_val=0;

	if(objno<8) {
		if(objects_move &(1<<objno)) ret_val=1;
	}
	else {
		if(objects_smove&(1<<(objno-16))) ret_val=1;
	}
	return(ret_val);
}


void write_obj_value(unsigned char objno,unsigned int objvalue)	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
{
	if(objno<8) {// kurz und lanzeit
		if(objvalue==0) objects_move &= 0xFF-(1<<objno);
		else objects_move |=1<<objno;
	}
	else{
		objno-=16;// sicherheitsfahrt 16+17
		if(objvalue==0) objects_smove &= (0xFF-(1<<objno));
		else objects_smove |=1<<objno;
	}
}
//									16,17			0,1
void Sobject_schalten(unsigned char objno,unsigned char val)// Schaltet die Sicherheitsfunktionen
{
unsigned char k,zuordnung,sobj,blockstart,blockend,action;
	
	if (objno >18){				// wenn bypass aus delay timer...
		sobj=objno&0x01;	// dann sobj ausfiltern
		state=0;				//state so setzen damit sperre aktiv wird
		val=0x01;		// dto für objektvalue
	}
	else{
		sobj=objno-16;				//sobj ("Sicherheitsobjektnummer")ist also 0 für Sicherheit1, 1 für Si 2
		state=!((eeprom[0xE2])& (0x40<<sobj));//Polarität

	}
		write_obj_value(objno & 0x1F ,val);		// Objektwert im userram speichern
			//if (val){
				if (state^(__bit)val) zfstate=zfstate |(0x0F<<(sobj<<2));// setzen der sicherhfahrt 1 in zfstate, xor verknüpft die polarität
				else {
					zfstate=zfstate & (0xFF-(0x0F<<(sobj<<2)));//in zfstate sind für sich1 0F und sich2 F0
					set_entriegeln(sobj + 9);// Update objekt macht refresh auf Zeit 9/10  Zyklusüberwachung
					}
				zuordnung=eeprom[0xF1] & zfstate;//in zuordnung jetzt eine 1 für jede sicherheit 
				blocked =zuordnung |((zuordnung >>4) | (zuordnung<<4)); //beide Sicherheitsergebnisse verodern..
			//}
			blockstart= blocked & ~oldblockvalue;//steigende Flanke der Blockade(sicherheit)
			blockend= ~blocked & oldblockvalue;	//fallende Flanke der Blockade(sicherheit)
			//START_WRITECYCLE
			//WRITE_BYTE(0x00,0x2A,blocked)		// 0xCA  blocked im userram sichern
			//STOP_WRITECYCLE
			if (!handmode){
			oldblockvalue=blocked;

			for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
				action=0;
				if(blockstart & 0x01){
					action=(eeprom[0xF0]>>(k<<1))&0x03;
				}// ende if(blockstart
				if(blockend & 0x01){
					action=(eeprom[0xEF]>>(k<<1))&0x03;
				}
				if(action){
						object_schalten(k+12,action>>1);
				}// ende if(action.. // (blockend...
				blockend=blockend>>1;
				blockstart=blockstart>>1;
			}// ende for(k=0;k...
		}//ende if !handmode
}//ende Sobject_schalten





void object_schalten(unsigned char objno, __bit objstate)	// Schaltet einen Ausgang gemäß objstate und den zugörigen Parametern
{

	unsigned char port_pattern,objflags,kwin,kwout,faktor,lz_ue,tmp;
	unsigned char delay_target,pluszeit;//,delay_onoff,
	__bit off_disable;


	off_disable;
		kwin = kanal[objno & 0x03]& 0x0f;// kwin heisst KanalWertIN. Bit 0+1 Relaise status, Bit 4+5 gewünschter Relaise status
		kwout=kwin;
		if (objstate) write_obj_value(objno & 0x07,1);		// Objektwert im userram speichern
		else write_obj_value(objno & 0x07,0);
		objflags=read_objflags(objno&0x07);			// Objekt Flags lesen
		port_pattern=0x01<<(objno&0x07);//port_pattern=0x01<<(objno&0x0F)
//		zfno=0;
//		logicfunc=0;
		if((port_pattern & blocked)==0 && (objflags&0x14)==0x14 ||(objno >=8)) {	// Objekt ist nicht gesperrt und Kommunikation zulässig (Bit 2 = communication enable) und Schreiben zulässig (Bit 4 = write enable)
		objno=objno&0x07;	// damit die bypassobjekte 8-15 wieder 0-7 sind!

// Pausezeit berechnen..

			if (objno<0x04){			//+++++ kurzzeitobjekt +++++
				delay_target = (eeprom[0xE8+(objno>>1)]>>(3*(objno&0x01))&0x07)|0x80;// zeitbasis aus eeprom holen
				faktor=eeprom[0xEA+objno];// faktor holen um dann auf 0 zu prüfen
				pluszeit=faktor + (faktor>>5);// 3% zeit bei "auf" 

				if (objstate==0){	//----- auf -----

					if (kwin&0x33){					// wenn faehrt,dann stop
						  set_pause(objno,kwin&0x03);
						  //write_delay_record((objno&0x03)+11, 0x02, timer + pause);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
						  kwout=kwin&0xCC;	// Fahrt in beide Richtungen stoppen
						  timerbase[objno]=0;	// kurzzeit löschen
						  timerstate[objno]=0;	// kurzzeit löschen
						  timerbase[objno+4]=0;  // lanzeit löschen
						  timerstate[objno+4]=0;  // lanzeit löschen
					  }
					else 
					  if ((!(kwin&0x33))&&(faktor)){	//wenn stillstand und faktor>0  dann step
						  kwout=kwin|0x10;
						  kwout=kwout&0xDF;
						  //write_delay_record(objno, 0x01, timer + pluszeit );
						  timerbase[objno]=delay_target;
						  timercnt[objno]=pluszeit;
						  timerstate[objno]=0x01;
					  }
				}
				else{				//----- ab -----

					if (kwin&0x33){					// wenn faehrt, dann stop
						  set_pause(objno,kwin&0x03); //einsch. verz "pause" für eventuelle Faht in gegenrichtung
						  kwout=kwin&0xCC;
						  //clear_delay_record(objno);	// kurzzeit löschen
						  //clear_delay_record(objno+4);	//langzeit löschen
						  timerbase[objno]=0;
						  timerstate[objno]=0;
						  timerbase[objno+4]=0;
						  timerstate[objno+4]=0;
					  }
					  if ((!(kwin&0x33))&&(faktor)){		// wenn stillstand dann step
						  kwout=kwin|0x20;
						  kwout=kwout&0xEF;
						  //write_delay_record(objno, 0x02, timer + delay_target);
						  timerbase[objno]=delay_target;
						  timercnt[objno]=faktor;
						  timerstate[objno]=0x02;
					  }
				}//ende ab
			}// ende kurzzeitobjekte
			
				else{				//++++++ Langzeitobjekt +++++++
					//delay_target=zeit(0xFB,0xFC,0xDA,objno&0x03);// zeit aus eeprom holen
					delay_target=(eeprom[0xFB+((objno&0x03)>>1)]>>(3*(objno&0x01))&0x07) | 0x80;// zeitbasis aus eeprom holen
					faktor = eeprom[0xDA+(objno&0x03)];
					faktor = faktor + (faktor>>2);// +25% zeit bei langzeit 
					pluszeit=faktor + (faktor>>5);// 3% zeit bei "auf" 
					lz_ue=((eeprom[0xF2]>>objno)&0x01);		//lz_ue bedeutet: langzeit unendlich
					if (objstate==0){// --- auf ----
						if (kwin&0x11){		//läuft bereits, also nachtriggern
							kwout=kwin|0x10;// auch hier neu setzen da in delay nach rechts kommt
							  timercnt[objno-4]=0;//kurzzeit löschen
							  timerstate[objno-4]=0;
							  timerbase[objno-4]=0;
							if (!lz_ue){
								//write_delay_record(objno, 0x01, timer + pluszeit);
								  timerbase[objno]=delay_target;
								  timercnt[objno]=pluszeit;
								  timerstate[objno]=0x01;
							}
						 }
						if (!(kwin&0x33)){	//wenn stillstand, dann move
							kwout=kwin|0x10;
							 // kwout=kwout&0xDF;
							  
							if (!lz_ue){
								//write_delay_record(objno, 0x01, timer + pluszeit);
								  timerbase[objno]=delay_target;
								  timercnt[objno]=pluszeit;
								  timerstate[objno]=0x01;
								
							}
						  }
						   if (kwin&0x22){		// wenn fahrt in andere richtung
							  set_pause(objno,0x05);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
							  kwout=kwin|0x10;
							  kwout=kwout&0xDF;
							  if (!lz_ue){
								  //write_delay_record(objno, 0x01, timer  + pluszeit);
								  timerbase[objno]=delay_target & 0x7F;// timer-run für den move löschen
								  timercnt[objno]=pluszeit;
								  timerstate[objno]=0x01;
							  }
						  }
					}//ende auf

					else{			//  --- ab ----
						 if (kwin&0x22){		//läuft bereits, also nachtriggern
							 kwout=kwin|0x20;// auch hier neu setzen da in delay nach rechts kommt
							 timerbase[objno-4]=0; 
							 timercnt[objno-4]=0;
							 timerstate[objno-4]=0;
							 // clear_delay_record(objno-4);//kurzzeit löschen
							 if (!lz_ue){
								 //write_delay_record(objno, 0x02, timer + delay_target);
								  timerbase[objno]=delay_target;
								  timercnt[objno]=faktor;
								  timerstate[objno]=0x02;
							 }
						 }
						if (!(kwin&0x33)){	//wenn stillstand, dann move
							  kwout=kwin|0x20;// kanal setzen
							  // kwout=kwout&0xEF;
							  // clear_delay_record(objno-4);//kurzzeit löschen
							  timerbase[objno-4]=0; 
							  timercnt[objno-4]=0;
							  timerstate[objno-4]=0;
							  if (!lz_ue){
								  //write_delay_record(objno, 0x02, timer + delay_target );
								  timerbase[objno]=delay_target;
								  timercnt[objno]=faktor;
								  timerstate[objno]=0x02;
							  }
						  }
						if (kwin&0x11){					// wenn fahrt in andere richtung
							  set_pause(objno, 0x06);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
							  kwout=kwin|0x20;
							  kwout=kwout&0xEF;
							  //clear_delay_record(objno-4);
							  timerbase[objno-4]=0; // kurzzeit löschen
							  timercnt[objno-4]=0;
							  timerstate[objno-4]=0;
							  if (!lz_ue){
								  //write_delay_record(objno, 0x02, timer  + delay_target );
								  timerbase[objno]=delay_target & 0x7F;// timer run des langzeit löschen
								  timercnt[objno]=faktor;
								  timerstate[objno]=0x02;
							  }
						  }

					
					}//ende ab
					
			}// ende langzeitobjekte +++++++
			
			kwin=kwout;
			if (objno<=7){
				tmp=timerstate[((objno & 0x03)+11)]& 0x07;
				//rs_send(tmp);
				if ((tmp<4)&& (tmp & (kwout>>4) & 0x03)){
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
					if(!(tmp)){
					kwout=kwin>>4;//wenn keiene Pause Läuft, dann kanal "soll" in "ist" kopieren
				//	rs_send ('S');
					}
				}
			}

			kanal[objno&0x03]=kwout;
			portchanged=1;
	
		} 

} //end function	



const unsigned int timerflagmask[]={0x0000,0x0000,0x0000,0x0008,0x0080,0x0800};
void delay_timer(void)	// zählt alle 8 ms die Variable Timer hoch und prüft Queue
{
	
	unsigned char objno,delay_state,m;//,delay_base;
	unsigned int timerflags;

// unsigned char port_pattern,delay_zeit,delay_onoff;
//	long delval;//,delay_target;
//	bit hand;
	RTCCON=0x61;		// RTC Flag löschen
	objno=0;
	timer++;
		timerflags = timer&(~(timer-1));
//		for(n=0;n<4;n++){
//			if(timerflags & 0x0001){// positive flags erzeugen und schieben
				for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
//					if (timerbase[m]==((n+2)|0x80)){// wenn die base mit der gespeicherten base übereinstimmt
				  if(timerbase[m]& 0x80){// wenn run-bit gesetzt
					if((timerbase[m]==0x82)||(timerflags & (timerflagmask[timerbase[m]&0x7f]))){// wenn das flag mit der gespeicherten base übereinstimmt						
						if (timercnt[m]>0x00){// wenn der counter läuft...
							timercnt[m]=timercnt[m]-1;// den timer [m]decrementieren
						}// end if (timercnt...
					}
				  }//end if(timerbase...
				}// end  for(m..
//			}// end if timer...
//			timerflags = timerflags>>4;
//		}//end for (n=...
		
		// ab Hier die aktion...

		for(objno=0;objno<=15;objno++) {
			delay_state=timerstate[objno];			//status des timer-records
			if(delay_state!=0x00) {					// 0x00 = delay Eintrag ist leer   
				if(timercnt[objno]==0 && (timerbase[objno]&0x80)) { 	// wenn der cnt null und run=1, also zeit ist abgelaufen...
					if (objno<=7){// wenns ein kurz oder langzeit objekt ist...
						timerbase[objno]=0;
						timercnt[objno]=0;
						timerstate[objno]=0;
						kanal[objno&0x03]=0x00;
					    set_pause(objno,(delay_state));// einsch. verz "pause" für eventuelle Fahrt in gegenrichtung
					    								//in Pause-state sichern
					}
					if (objno==9 ){	//Sicherheit 1
						if (delay_state == 0x01){
							timerstate[9]=0x02;// wenn ziel erreicht in delrec sichern
							Sobject_schalten(48,1);// und Sicherheitsobjekt über bypass schalten
						}
						//rs_send('1');
					}
					if (objno==10 ){	//Sicherheit 2
						if (delay_state == 0x01){
							timerstate[10]=0x02;// wenn ziel erreicht in delrec sichern
							Sobject_schalten(49,1);// und Sicherheitsobjekt über bypass schalten
						}
						//rs_send('2');
					}
					if ((objno>=11) && (objno<=14)){// die Pausezeit der Kanaele
					kanal[objno-11]=kanal[objno-11]>>4;			// die oberen 4 bit des kanals sind die neue value.
					timerbase[objno]=0;
					timercnt[objno]=0;			//timer loeschen
					timerstate[objno]=0;
					if(timerstate[objno-7])timerbase[objno-7]|=0x80;// timer run-bit des zugehörigen Langzeitobjektes setzen
					}
					if (objno>=15){// handmode kurz/langtele + einschaltverz + ausschaltverz
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
				 portchanged=1;
				}//ende if(deval==..
		//		else{// also die zeit nicht abgelaufen...
		//#########  muss oben	if ( objno<=0x07 && ((timercnt[((objno & 0x03)+11)])>0x80)){//wenn zeit der pause läuft.. 
		//#########  rein !!!!	write_delay_record(objno,delay_state,delval+1);//trick : wegen der pause werden die zeiten geschoben
		//			}
		//		}//ende else zeit abgelaufen
			}//ende if(delay_state...
		}//ende for (objno=0;...
		
		if (eeprom[0xE5]& 0xC0){
			handsteuerung();   // Handbetätigung nur jedes 8.mal ausführen
		}

		
}
	
/*	###### alt out8 
	
	
#ifdef HAND		// für Handbetätigung
//	unsigned char n;
	unsigned char ledport;
	unsigned char Tasten=0;
#endif
	
		
#ifdef HAND		//+++++++   Handbetätigung  ++++++++++

	if((TMOD&0x0F)==0x02 && fb_state==0) {
		ET1=0;

		#ifdef MAX_PORTS_8

		while(  (!PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen

		#endif
		#ifdef MAX_PORTS_4
		while( (TMOD&0x0F)==0x02 && ( TL0>0x72));// PWM scannen um "Hand"-Tasten abzufragen
		#endif

		interrupted=0;	  
		Tasten=0;				

	#ifdef MAX_PORTS_8
		P1_3= 1;			    //int0 auf 1, wird über Dioden und taster auf low IO gezogen.
		ledport=0x01;
		for (n=0;n<8;n++) {  						
			P0=~ledport;
		  	if (!P1_3){
		  		Tasten=Tasten|ledport;
		  		objno=n;
		  		n=7;
		  	}
		  	ledport=ledport<<1;
		} 
	#endif	
		
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
unsigned char ledport;

void handsteuerung(void)
{
	//#ifdef HAND		// für Handbetätigung
		unsigned char n;
		unsigned char tmph;
		unsigned char key_pattern,Tasten;
		key_pattern,tmph;
	//#endif
/*
	if (RI){//simulation..
		RI=0;
	serbuf=SBUF;
	//	rs_send(eeprom[SBUF]);// für sniffer
	}//ende simulation
*/
	if((TMOD&0x0F)==0x02 && fb_state==0) {
//	ET1=0;	
//	while(  (!PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen
	
#ifdef MAX_PORTS_8

while(  (!PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen

#endif
#ifdef MAX_PORTS_4
while( (TMOD&0x0F)==0x02 && ( TL0>0x72));// PWM scannen um "Hand"-Tasten abzufragen
#endif

		//while( TMOD==0x12 && (!PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen
		//interrupted=0;	  
		//Tasten=8;				// 
/*		P1_3= 1;			    //int0 auf 1; wird über taster, diode, IO auf gnd gezogen.
		ledport=0x01;
		for (n=0;n<=7;n++){  						
			P0=~ledport;
		  	if (!P1_3){
		  		Tasten=n;
		  		n=7;
		  	}
		  	ledport=ledport<<1;
		} 
*/
//		keyno++;
//		keyno=keyno&0x07;
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
							object_schalten(((Tval&0x07)>>1)+12,(Tval&0x01));
							}
						else{
							object_schalten(((Tval&0x07)>>1)+8,(Tval&0x01));
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



void sobj_update(void)
{
	Sobject_schalten(16,read_obj_value(16)&0x01);
	Sobject_schalten(17,read_obj_value(17)&0x01);
}
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
	timercnt[pauseobj]=pause;
	timerbase[pauseobj]= 3 | 0x80;
	//write_delay_record((objnr & 0x03)+ 11,Pstate,pause + timer);
}// ende Pausezeit

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
	for (n=0;n<=3;n++){
		if(((eeprom[0xF1]>>n)&0x11)==0 ){// wenn keine Sperrfunktion zugewiesen
			blocked &= ~(0x11<<n);  // dann blocked löschen, damit nach umpara
		}							// nicht stehen bleibt.
		switch(eeprom[0xD9]& 0xC0){
		case 0x40:
			object_schalten(n+12,0);
		break;
		case 0x80:
			object_schalten(n+12,1);
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
	handmode=0;

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
	delay_toggle=0;
	
	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	START_WRITECYCLE
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
	WRITE_BYTE(0x01,0x04,0x04)
//	WRITE_BYTE(0x01,0x05,0x20)	// Devicetype 0x2070 = Jung Aktor 2138.10
//	WRITE_BYTE(0x01,0x06,0x70)	
//	WRITE_BYTE(0x01,0x07,0x01)	// Versionnumber of application programm
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
//	WRITE_BYTE(0x01,0x12,0x9A)	// COMMSTAB Pointer
	STOP_WRITECYCLE
	EA=1;						// Interrupts freigeben

	RTCCON=0x60;		// RTC Flag löschen
	RTCH=0x01;			// reload Real Time Clock
	RTCL=0xCD;			// 8ms
	RTCCON=0x61;
}
