//DEBUGGER;
#include"../com/debug.h"
volatile unsigned int debugadr;
void EX0_int (void) __interrupt (0){
	unsigned char inputchar;
//  RUN MODE
	if(debugadr){
		if((((unsigned int)RAM[SP-7]<<8)+RAM[SP-8])==debugadr) debugadr=0;
		else if(RI)debugadr=0;
	}
//  STEP MODE
	if(!debugadr){
		DEBUG RAM[SP-7];
		DEBUG RAM[SP-8];
		do{
			while(!RI);
			inputchar=SBUF;
			RI=0;
			if(inputchar=='a'){BREAKADR_IN}
			if(inputchar=='v'){VAR_IN(SBUF)}
			if(inputchar=='p'){DEBUG SP-9;}
			if(inputchar=='L'){DEBUG DPL;}
			if(inputchar=='H'){DEBUG DPH;}
			if(inputchar=='B'){DEBUG B;}
			if(inputchar=='0'){DEBUG P0;}
			if(inputchar=='1'){DEBUG P1;}
			if(inputchar=='3'){DEBUG P3;}
		}while(inputchar!='n');
	}
}