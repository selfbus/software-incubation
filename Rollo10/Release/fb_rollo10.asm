;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
; This file was generated Sun Apr 14 12:17:07 2013
;--------------------------------------------------------
	.module fb_rollo10
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _restart_app
	.globl _bus_return
	.globl _port_schalten
	.globl _delay_timer
	.globl _process_tel
	.globl _restart_hw
	.globl _P3_1
	.globl _P3_0
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _I2CON_0
	.globl _I2CON_2
	.globl _I2CON_3
	.globl _I2CON_4
	.globl _I2CON_5
	.globl _I2CON_6
	.globl _SCON_7
	.globl _SCON_6
	.globl _SCON_5
	.globl _SCON_4
	.globl _SCON_3
	.globl _SCON_2
	.globl _SCON_1
	.globl _SCON_0
	.globl _IP0_0
	.globl _IP0_1
	.globl _IP0_2
	.globl _IP0_3
	.globl _IP0_4
	.globl _IP0_5
	.globl _IP0_6
	.globl _IP1_0
	.globl _IP1_1
	.globl _IP1_2
	.globl _IP1_6
	.globl _IEN1_0
	.globl _IEN1_1
	.globl _IEN1_2
	.globl _IEN0_0
	.globl _IEN0_1
	.globl _IEN0_2
	.globl _IEN0_3
	.globl _IEN0_4
	.globl _IEN0_5
	.globl _IEN0_6
	.globl _IEN0_7
	.globl _TCON_0
	.globl _TCON_1
	.globl _TCON_2
	.globl _TCON_3
	.globl _TCON_4
	.globl _TCON_5
	.globl _TCON_6
	.globl _TCON_7
	.globl _PSW_7
	.globl _PSW_6
	.globl _PSW_5
	.globl _PSW_4
	.globl _PSW_3
	.globl _PSW_2
	.globl _PSW_1
	.globl _PSW_0
	.globl _IEN1
	.globl _IP0H
	.globl _WFEED2
	.globl _WFEED1
	.globl _WDL
	.globl _WDCON
	.globl _TRIM
	.globl _TAMOD
	.globl _SSTAT
	.globl _RTCL
	.globl _RTCH
	.globl _RTCCON
	.globl _RSTSRC
	.globl _PT0AD
	.globl _PCONA
	.globl _P3M2
	.globl _P3M1
	.globl _P1M2
	.globl _P1M1
	.globl _P0M2
	.globl _P0M1
	.globl _KBPATN
	.globl _KBMASK
	.globl _KBCON
	.globl _IP1H
	.globl _IP1
	.globl _I2STAT
	.globl _I2SCLL
	.globl _I2SCLH
	.globl _I2DAT
	.globl _I2CON
	.globl _I2ADR
	.globl _FMDATA
	.globl _FMCON
	.globl _FMADRL
	.globl _FMADRH
	.globl _DIVM
	.globl _CMP2
	.globl _CMP1
	.globl _BRGCON
	.globl _BRGR1
	.globl _BRGR0
	.globl _SADEN
	.globl _SADDR
	.globl _AUXR1
	.globl _SBUF
	.globl _SCON
	.globl _IP0
	.globl _IEN0
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _P3
	.globl _P1
	.globl _P0
	.globl _RAM
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$P0$0$0 == 0x0080
_P0	=	0x0080
G$P1$0$0 == 0x0090
_P1	=	0x0090
G$P3$0$0 == 0x00b0
_P3	=	0x00b0
G$PSW$0$0 == 0x00d0
_PSW	=	0x00d0
G$ACC$0$0 == 0x00e0
_ACC	=	0x00e0
G$B$0$0 == 0x00f0
_B	=	0x00f0
G$SP$0$0 == 0x0081
_SP	=	0x0081
G$DPL$0$0 == 0x0082
_DPL	=	0x0082
G$DPH$0$0 == 0x0083
_DPH	=	0x0083
G$PCON$0$0 == 0x0087
_PCON	=	0x0087
G$TCON$0$0 == 0x0088
_TCON	=	0x0088
G$TMOD$0$0 == 0x0089
_TMOD	=	0x0089
G$TL0$0$0 == 0x008a
_TL0	=	0x008a
G$TL1$0$0 == 0x008b
_TL1	=	0x008b
G$TH0$0$0 == 0x008c
_TH0	=	0x008c
G$TH1$0$0 == 0x008d
_TH1	=	0x008d
G$IEN0$0$0 == 0x00a8
_IEN0	=	0x00a8
G$IP0$0$0 == 0x00b8
_IP0	=	0x00b8
G$SCON$0$0 == 0x0098
_SCON	=	0x0098
G$SBUF$0$0 == 0x0099
_SBUF	=	0x0099
G$AUXR1$0$0 == 0x00a2
_AUXR1	=	0x00a2
G$SADDR$0$0 == 0x00a9
_SADDR	=	0x00a9
G$SADEN$0$0 == 0x00b9
_SADEN	=	0x00b9
G$BRGR0$0$0 == 0x00be
_BRGR0	=	0x00be
G$BRGR1$0$0 == 0x00bf
_BRGR1	=	0x00bf
G$BRGCON$0$0 == 0x00bd
_BRGCON	=	0x00bd
G$CMP1$0$0 == 0x00ac
_CMP1	=	0x00ac
G$CMP2$0$0 == 0x00ad
_CMP2	=	0x00ad
G$DIVM$0$0 == 0x0095
_DIVM	=	0x0095
G$FMADRH$0$0 == 0x00e7
_FMADRH	=	0x00e7
G$FMADRL$0$0 == 0x00e6
_FMADRL	=	0x00e6
G$FMCON$0$0 == 0x00e4
_FMCON	=	0x00e4
G$FMDATA$0$0 == 0x00e5
_FMDATA	=	0x00e5
G$I2ADR$0$0 == 0x00db
_I2ADR	=	0x00db
G$I2CON$0$0 == 0x00d8
_I2CON	=	0x00d8
G$I2DAT$0$0 == 0x00da
_I2DAT	=	0x00da
G$I2SCLH$0$0 == 0x00dd
_I2SCLH	=	0x00dd
G$I2SCLL$0$0 == 0x00dc
_I2SCLL	=	0x00dc
G$I2STAT$0$0 == 0x00d9
_I2STAT	=	0x00d9
G$IP1$0$0 == 0x00f8
_IP1	=	0x00f8
G$IP1H$0$0 == 0x00f7
_IP1H	=	0x00f7
G$KBCON$0$0 == 0x0094
_KBCON	=	0x0094
G$KBMASK$0$0 == 0x0086
_KBMASK	=	0x0086
G$KBPATN$0$0 == 0x0093
_KBPATN	=	0x0093
G$P0M1$0$0 == 0x0084
_P0M1	=	0x0084
G$P0M2$0$0 == 0x0085
_P0M2	=	0x0085
G$P1M1$0$0 == 0x0091
_P1M1	=	0x0091
G$P1M2$0$0 == 0x0092
_P1M2	=	0x0092
G$P3M1$0$0 == 0x00b1
_P3M1	=	0x00b1
G$P3M2$0$0 == 0x00b2
_P3M2	=	0x00b2
G$PCONA$0$0 == 0x00b5
_PCONA	=	0x00b5
G$PT0AD$0$0 == 0x00f6
_PT0AD	=	0x00f6
G$RSTSRC$0$0 == 0x00df
_RSTSRC	=	0x00df
G$RTCCON$0$0 == 0x00d1
_RTCCON	=	0x00d1
G$RTCH$0$0 == 0x00d2
_RTCH	=	0x00d2
G$RTCL$0$0 == 0x00d3
_RTCL	=	0x00d3
G$SSTAT$0$0 == 0x00ba
_SSTAT	=	0x00ba
G$TAMOD$0$0 == 0x008f
_TAMOD	=	0x008f
G$TRIM$0$0 == 0x0096
_TRIM	=	0x0096
G$WDCON$0$0 == 0x00a7
_WDCON	=	0x00a7
G$WDL$0$0 == 0x00c1
_WDL	=	0x00c1
G$WFEED1$0$0 == 0x00c2
_WFEED1	=	0x00c2
G$WFEED2$0$0 == 0x00c3
_WFEED2	=	0x00c3
G$IP0H$0$0 == 0x00b7
_IP0H	=	0x00b7
G$IEN1$0$0 == 0x00e8
_IEN1	=	0x00e8
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$PSW_0$0$0 == 0x00d0
_PSW_0	=	0x00d0
G$PSW_1$0$0 == 0x00d1
_PSW_1	=	0x00d1
G$PSW_2$0$0 == 0x00d2
_PSW_2	=	0x00d2
G$PSW_3$0$0 == 0x00d3
_PSW_3	=	0x00d3
G$PSW_4$0$0 == 0x00d4
_PSW_4	=	0x00d4
G$PSW_5$0$0 == 0x00d5
_PSW_5	=	0x00d5
G$PSW_6$0$0 == 0x00d6
_PSW_6	=	0x00d6
G$PSW_7$0$0 == 0x00d7
_PSW_7	=	0x00d7
G$TCON_7$0$0 == 0x008f
_TCON_7	=	0x008f
G$TCON_6$0$0 == 0x008e
_TCON_6	=	0x008e
G$TCON_5$0$0 == 0x008d
_TCON_5	=	0x008d
G$TCON_4$0$0 == 0x008c
_TCON_4	=	0x008c
G$TCON_3$0$0 == 0x008b
_TCON_3	=	0x008b
G$TCON_2$0$0 == 0x008a
_TCON_2	=	0x008a
G$TCON_1$0$0 == 0x0089
_TCON_1	=	0x0089
G$TCON_0$0$0 == 0x0088
_TCON_0	=	0x0088
G$IEN0_7$0$0 == 0x00af
_IEN0_7	=	0x00af
G$IEN0_6$0$0 == 0x00ae
_IEN0_6	=	0x00ae
G$IEN0_5$0$0 == 0x00ad
_IEN0_5	=	0x00ad
G$IEN0_4$0$0 == 0x00ac
_IEN0_4	=	0x00ac
G$IEN0_3$0$0 == 0x00ab
_IEN0_3	=	0x00ab
G$IEN0_2$0$0 == 0x00aa
_IEN0_2	=	0x00aa
G$IEN0_1$0$0 == 0x00a9
_IEN0_1	=	0x00a9
G$IEN0_0$0$0 == 0x00a8
_IEN0_0	=	0x00a8
G$IEN1_2$0$0 == 0x00ea
_IEN1_2	=	0x00ea
G$IEN1_1$0$0 == 0x00e9
_IEN1_1	=	0x00e9
G$IEN1_0$0$0 == 0x00e8
_IEN1_0	=	0x00e8
G$IP1_6$0$0 == 0x00fe
_IP1_6	=	0x00fe
G$IP1_2$0$0 == 0x00fa
_IP1_2	=	0x00fa
G$IP1_1$0$0 == 0x00f9
_IP1_1	=	0x00f9
G$IP1_0$0$0 == 0x00f8
_IP1_0	=	0x00f8
G$IP0_6$0$0 == 0x00be
_IP0_6	=	0x00be
G$IP0_5$0$0 == 0x00bd
_IP0_5	=	0x00bd
G$IP0_4$0$0 == 0x00bc
_IP0_4	=	0x00bc
G$IP0_3$0$0 == 0x00bb
_IP0_3	=	0x00bb
G$IP0_2$0$0 == 0x00ba
_IP0_2	=	0x00ba
G$IP0_1$0$0 == 0x00b9
_IP0_1	=	0x00b9
G$IP0_0$0$0 == 0x00b8
_IP0_0	=	0x00b8
G$SCON_0$0$0 == 0x0098
_SCON_0	=	0x0098
G$SCON_1$0$0 == 0x0099
_SCON_1	=	0x0099
G$SCON_2$0$0 == 0x009a
_SCON_2	=	0x009a
G$SCON_3$0$0 == 0x009b
_SCON_3	=	0x009b
G$SCON_4$0$0 == 0x009c
_SCON_4	=	0x009c
G$SCON_5$0$0 == 0x009d
_SCON_5	=	0x009d
G$SCON_6$0$0 == 0x009e
_SCON_6	=	0x009e
G$SCON_7$0$0 == 0x009f
_SCON_7	=	0x009f
G$I2CON_6$0$0 == 0x00de
_I2CON_6	=	0x00de
G$I2CON_5$0$0 == 0x00dd
_I2CON_5	=	0x00dd
G$I2CON_4$0$0 == 0x00dc
_I2CON_4	=	0x00dc
G$I2CON_3$0$0 == 0x00db
_I2CON_3	=	0x00db
G$I2CON_2$0$0 == 0x00da
_I2CON_2	=	0x00da
G$I2CON_0$0$0 == 0x00d8
_I2CON_0	=	0x00d8
G$P0_0$0$0 == 0x0080
_P0_0	=	0x0080
G$P0_1$0$0 == 0x0081
_P0_1	=	0x0081
G$P0_2$0$0 == 0x0082
_P0_2	=	0x0082
G$P0_3$0$0 == 0x0083
_P0_3	=	0x0083
G$P0_4$0$0 == 0x0084
_P0_4	=	0x0084
G$P0_5$0$0 == 0x0085
_P0_5	=	0x0085
G$P0_6$0$0 == 0x0086
_P0_6	=	0x0086
G$P0_7$0$0 == 0x0087
_P0_7	=	0x0087
G$P1_0$0$0 == 0x0090
_P1_0	=	0x0090
G$P1_1$0$0 == 0x0091
_P1_1	=	0x0091
G$P1_2$0$0 == 0x0092
_P1_2	=	0x0092
G$P1_3$0$0 == 0x0093
_P1_3	=	0x0093
G$P1_4$0$0 == 0x0094
_P1_4	=	0x0094
G$P1_5$0$0 == 0x0095
_P1_5	=	0x0095
G$P1_6$0$0 == 0x0096
_P1_6	=	0x0096
G$P1_7$0$0 == 0x0097
_P1_7	=	0x0097
G$P3_0$0$0 == 0x00b0
_P3_0	=	0x00b0
G$P3_1$0$0 == 0x00b1
_P3_1	=	0x00b1
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; overlayable bit register bank
;--------------------------------------------------------
	.area BIT_BANK	(REL,OVR,DATA)
bits:
	.ds 1
	b0 = bits[0]
	b1 = bits[1]
	b2 = bits[2]
	b3 = bits[3]
	b4 = bits[4]
	b5 = bits[5]
	b6 = bits[6]
	b7 = bits[7]
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
G$RAM$0$0 == 0x0000
_RAM	=	0x0000
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area OSEG    (OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG	(DATA)
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	reti
	.ds	7
	reti
	.ds	7
	ljmp	_X1_int
	.ds	5
	ljmp	_T1_int
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	lcall	_main
;	return from main will lock up
	sjmp .
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;n                         Allocated to registers r5 
;cmd                       Allocated to registers r5 
;tasterpegel               Allocated to registers r7 
;cal                       Allocated to registers r6 
;rm_count                  Allocated to registers 
;wduf                      Allocated to registers b1 
;tastergetoggelt           Allocated to registers b0 
;------------------------------------------------------------
	G$main$0$0 ==.
	C$fb_rollo10.c$44$0$0 ==.
;	..\fb_rollo10.c:44: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	C$fb_rollo10.c$46$1$0 ==.
;	..\fb_rollo10.c:46: unsigned char n,cmd,tasterpegel=0;
	mov	r7,#0x00
	C$fb_rollo10.c$54$1$0 ==.
;	..\fb_rollo10.c:54: __bit wduf,tastergetoggelt=0;
	clr	b0
	C$fb_rollo10.c$55$1$1 ==.
;	..\fb_rollo10.c:55: wduf=WDCON&0x02;
	mov	a,_WDCON
	rr	a
	anl	a,#0x01
	add	a,#0xff
	mov	b1,c
	C$fb_rollo10.c$56$1$1 ==.
;	..\fb_rollo10.c:56: restart_hw();							// Hardware zuruecksetzen
	push	ar7
	push	bits
	lcall	_restart_hw
	pop	bits
	pop	ar7
	C$fb_rollo10.c$59$1$1 ==.
;	..\fb_rollo10.c:59: TASTER=1;
	setb	_P1_7
	C$fb_rollo10.c$60$1$1 ==.
;	..\fb_rollo10.c:60: if(!TASTER && wduf)cal=0;
	jb	_P1_7,00102$
	jnb	b1,00102$
	mov	r6,#0x00
	sjmp	00103$
00102$:
	C$fb_rollo10.c$61$1$1 ==.
;	..\fb_rollo10.c:61: else cal=trimsave;
	mov	dptr,#_main_trimsave_1_1
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	mov	r6,a
00103$:
	C$fb_rollo10.c$62$1$1 ==.
;	..\fb_rollo10.c:62: TRIM = (TRIM+trimsave);
	mov	dptr,#_main_trimsave_1_1
	clr	a
	movc	a,@a+dptr
	mov	r4,_TRIM
	add	a,r4
	mov	r5,a
	mov	_TRIM,r5
	C$fb_rollo10.c$63$1$1 ==.
;	..\fb_rollo10.c:63: TRIM &= 0x3F;//oberen 2 bits ausblenden
	anl	_TRIM,#0x3F
	C$fb_rollo10.c$68$1$1 ==.
;	..\fb_rollo10.c:68: if (!wduf){// BUS return verzögerung nur wenn nicht watchdog underflow
	jb	b1,00109$
	C$fb_rollo10.c$69$1$1 ==.
;	..\fb_rollo10.c:69: for (n=0;n<50;n++) {		// Warten bis Bus stabil
	mov	r5,#0x00
00170$:
	cjne	r5,#0x32,00221$
00221$:
	jnc	00109$
	C$fb_rollo10.c$70$3$3 ==.
;	..\fb_rollo10.c:70: TR0=0;					// Timer 0 anhalten
	clr	_TCON_4
	C$fb_rollo10.c$71$3$3 ==.
;	..\fb_rollo10.c:71: TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
	mov	dptr,#(_eeprom + 0x0017)
	clr	a
	movc	a,@a+dptr
	mov	_TH0,a
	C$fb_rollo10.c$72$3$3 ==.
;	..\fb_rollo10.c:72: TL0=eeprom[ADDRTAB+2];
	mov	dptr,#(_eeprom + 0x0018)
	clr	a
	movc	a,@a+dptr
	mov	_TL0,a
	C$fb_rollo10.c$73$3$3 ==.
;	..\fb_rollo10.c:73: TF0=0;					// Überlauf-Flag zurücksetzen
	clr	_TCON_5
	C$fb_rollo10.c$74$3$3 ==.
;	..\fb_rollo10.c:74: TR0=1;					// Timer 0 starten
	setb	_TCON_4
	C$fb_rollo10.c$75$3$3 ==.
;	..\fb_rollo10.c:75: while(!TF0);
00105$:
	jnb	_TCON_5,00105$
	C$fb_rollo10.c$69$2$2 ==.
;	..\fb_rollo10.c:69: for (n=0;n<50;n++) {		// Warten bis Bus stabil
	inc	r5
	sjmp	00170$
00109$:
	C$fb_rollo10.c$78$1$1 ==.
;	..\fb_rollo10.c:78: WATCHDOG_INIT
	mov	_WDL,#0xFF
	clr	_IEN0_7
	mov	_WDCON,#0xE5
	mov	_WFEED1,#0xA5
	mov	_WFEED2,#0x5A
	setb	_IEN0_7
	C$fb_rollo10.c$79$1$1 ==.
;	..\fb_rollo10.c:79: WATCHDOG_START
	clr	_IEN0_7
	orl	_WDCON,#0x04
	mov	_WFEED1,#0xA5
	mov	_WFEED2,#0x5A
	setb	_IEN0_7
	C$fb_rollo10.c$80$1$1 ==.
;	..\fb_rollo10.c:80: restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	push	ar7
	push	ar6
	push	bits
	lcall	_restart_app
	pop	bits
	pop	ar6
	pop	ar7
	C$fb_rollo10.c$81$1$1 ==.
;	..\fb_rollo10.c:81: if(!wduf)bus_return();							// Aktionen bei Busspannungswiederkehr
	jb	b1,00111$
	push	ar7
	push	ar6
	push	bits
	lcall	_bus_return
	pop	bits
	pop	ar6
	pop	ar7
00111$:
	C$fb_rollo10.c$83$1$1 ==.
;	..\fb_rollo10.c:83: BRGCON&=0xFE;	// Baudrate Generator stoppen
	anl	_BRGCON,#0xFE
	C$fb_rollo10.c$84$1$1 ==.
;	..\fb_rollo10.c:84: P1M1&=0xFC;		// RX und TX auf bidirectional setzen
	anl	_P1M1,#0xFC
	C$fb_rollo10.c$85$1$1 ==.
;	..\fb_rollo10.c:85: P1M2&=0xFC;
	anl	_P1M2,#0xFC
	C$fb_rollo10.c$86$1$1 ==.
;	..\fb_rollo10.c:86: SCON=0x50;		// Mode 1, receive enable
	mov	_SCON,#0x50
	C$fb_rollo10.c$87$1$1 ==.
;	..\fb_rollo10.c:87: SSTAT|=0xE0;	// TI wird am Ende des Stopbits gesetzt und Interrupt nur bei RX und double TX buffer an
	orl	_SSTAT,#0xE0
	C$fb_rollo10.c$88$1$1 ==.
;	..\fb_rollo10.c:88: BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
	orl	_BRGCON,#0x02
	C$fb_rollo10.c$89$1$1 ==.
;	..\fb_rollo10.c:89: BRGR1=0x2F;	// Baudrate = cclk/((BRGR1,BRGR0)+16)
	mov	_BRGR1,#0x2F
	C$fb_rollo10.c$90$1$1 ==.
;	..\fb_rollo10.c:90: BRGR0=0xF0;	// für 115200 0030 nehmen, autocal: 600bd= 0x2FF0
	mov	_BRGR0,#0xF0
	C$fb_rollo10.c$91$1$1 ==.
;	..\fb_rollo10.c:91: BRGCON|=0x01;	// Baudrate Generator starten
	orl	_BRGCON,#0x01
	C$fb_rollo10.c$92$1$1 ==.
;	..\fb_rollo10.c:92: SBUF=0x55;
	mov	_SBUF,#0x55
	C$fb_rollo10.c$93$1$1 ==.
;	..\fb_rollo10.c:93: do  {
00167$:
	C$fb_rollo10.c$94$2$4 ==.
;	..\fb_rollo10.c:94: WATCHDOG_FEED
	clr	_IEN0_7
	mov	_WFEED1,#0xA5
	mov	_WFEED2,#0x5A
	setb	_IEN0_7
	C$fb_rollo10.c$96$2$4 ==.
;	..\fb_rollo10.c:96: if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt
	mov	dptr,#(_eeprom + 0x000d)
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	cjne	r5,#0xFF,00125$
	jb	_connected,00125$
	mov	a,_status60
	jb	acc.0,00125$
	C$fb_rollo10.c$100$3$5 ==.
;	..\fb_rollo10.c:100: */			if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf
	mov	a,#0x100 - 0x80
	add	a,_RTCCON
	jnc	00113$
	push	ar7
	push	ar6
	push	bits
	lcall	_delay_timer
	pop	bits
	pop	ar6
	pop	ar7
00113$:
	C$fb_rollo10.c$102$3$5 ==.
;	..\fb_rollo10.c:102: if(TF0 && (TMOD & 0x0F)==0x01) {	// Vollstrom für Relais ausschalten und wieder PWM ein
	jnb	_TCON_5,00115$
	mov	a,#0x0F
	anl	a,_TMOD
	mov	r5,a
	cjne	r5,#0x01,00115$
	C$fb_rollo10.c$104$4$6 ==.
;	..\fb_rollo10.c:104: TMOD=(TMOD & 0xF0) + 2;			// Timer 0 als PWM
	mov	a,#0xF0
	anl	a,_TMOD
	add	a,#0x02
	mov	_TMOD,a
	C$fb_rollo10.c$105$4$6 ==.
;	..\fb_rollo10.c:105: TAMOD=0x01;
	mov	_TAMOD,#0x01
	C$fb_rollo10.c$106$4$6 ==.
;	..\fb_rollo10.c:106: TH0=DUTY;
	mov	_TH0,#0x50
	C$fb_rollo10.c$108$4$6 ==.
;	..\fb_rollo10.c:108: TF0=0;
	clr	_TCON_5
	C$fb_rollo10.c$110$4$6 ==.
;	..\fb_rollo10.c:110: AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben
	orl	_AUXR1,#0x10
	C$fb_rollo10.c$112$4$6 ==.
;	..\fb_rollo10.c:112: PWM=1;			// PWM Pin muss auf 1 gesetzt werden, damit PWM geht !!!
	setb	_P1_2
	C$fb_rollo10.c$114$4$6 ==.
;	..\fb_rollo10.c:114: TR0=1;
	setb	_TCON_4
00115$:
	C$fb_rollo10.c$121$3$5 ==.
;	..\fb_rollo10.c:121: if (portchanged)port_schalten();	// Ausgänge schalten
	jnb	_portchanged,00118$
	push	ar7
	push	ar6
	push	bits
	lcall	_port_schalten
	pop	bits
	pop	ar6
	pop	ar7
00118$:
	C$fb_rollo10.c$150$3$5 ==.
;	..\fb_rollo10.c:150: if (fb_state==0 && (TH1<0XC0) && (!wait_for_ack)&& blocked!=blockedsave) {
	mov	a,_fb_state
	jnz	00125$
	mov	a,#0x100 - 0xC0
	add	a,_TH1
	jc	00125$
	jb	_wait_for_ack,00125$
	mov	dptr,#_main_blockedsave_1_1
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	cjne	a,_blocked,00237$
	sjmp	00125$
00237$:
	C$fb_rollo10.c$151$4$7 ==.
;	..\fb_rollo10.c:151: START_WRITECYCLE;
	mov	_FMCON,#0x00
	C$fb_rollo10.c$152$4$7 ==.
;	..\fb_rollo10.c:152: FMADRH= 0x1B;		
	mov	_FMADRH,#0x1B
	C$fb_rollo10.c$153$4$7 ==.
;	..\fb_rollo10.c:153: FMADRL= 0xFD; 
	mov	_FMADRL,#0xFD
	C$fb_rollo10.c$154$4$7 ==.
;	..\fb_rollo10.c:154: FMDATA= blocked;
	mov	_FMDATA,_blocked
	C$fb_rollo10.c$155$4$7 ==.
;	..\fb_rollo10.c:155: STOP_WRITECYCLE;
	mov	_FMCON,#0x68
00125$:
	C$fb_rollo10.c$162$2$4 ==.
;	..\fb_rollo10.c:162: if (tel_arrived ) {//|| tel_sent
	C$fb_rollo10.c$163$3$8 ==.
;	..\fb_rollo10.c:163: tel_arrived=0;
	jbc	_tel_arrived,00238$
	sjmp	00129$
00238$:
	C$fb_rollo10.c$164$3$8 ==.
;	..\fb_rollo10.c:164: tel_sent=0;
	clr	_tel_sent
	C$fb_rollo10.c$165$3$8 ==.
;	..\fb_rollo10.c:165: process_tel();
	push	ar7
	push	ar6
	push	bits
	lcall	_process_tel
	pop	bits
	pop	ar6
	pop	ar7
	sjmp	00130$
00129$:
	C$fb_rollo10.c$168$3$4 ==.
;	..\fb_rollo10.c:168: for(n=0;n<100;n++);	// falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann
	mov	r5,#0x64
00176$:
	mov	ar4,r5
	dec	r4
	mov	ar5,r4
	mov	a,r5
	jnz	00176$
00130$:
	C$fb_rollo10.c$174$2$4 ==.
;	..\fb_rollo10.c:174: if (RI){
	C$fb_rollo10.c$175$3$10 ==.
;	..\fb_rollo10.c:175: RI=0;
	jbc	_SCON_0,00240$
	sjmp	00155$
00240$:
	C$fb_rollo10.c$176$3$10 ==.
;	..\fb_rollo10.c:176: cmd=SBUF;
	mov	r5,_SBUF
	C$fb_rollo10.c$177$3$10 ==.
;	..\fb_rollo10.c:177: if(cmd=='c'){
	cjne	r5,#0x63,00135$
	C$fb_rollo10.c$178$4$11 ==.
;	..\fb_rollo10.c:178: while(!TI);
00131$:
	C$fb_rollo10.c$179$4$11 ==.
;	..\fb_rollo10.c:179: TI=0;
	jbc	_SCON_1,00243$
	sjmp	00131$
00243$:
	C$fb_rollo10.c$180$4$11 ==.
;	..\fb_rollo10.c:180: SBUF=0x55;
	mov	_SBUF,#0x55
00135$:
	C$fb_rollo10.c$182$3$10 ==.
;	..\fb_rollo10.c:182: if(cmd=='+'){
	cjne	r5,#0x2B,00137$
	C$fb_rollo10.c$183$4$12 ==.
;	..\fb_rollo10.c:183: TRIM--;
	dec	_TRIM
	C$fb_rollo10.c$184$4$12 ==.
;	..\fb_rollo10.c:184: cal--;
	dec	r6
00137$:
	C$fb_rollo10.c$186$3$10 ==.
;	..\fb_rollo10.c:186: if(cmd=='-'){
	cjne	r5,#0x2D,00139$
	C$fb_rollo10.c$187$4$13 ==.
;	..\fb_rollo10.c:187: TRIM++;
	inc	_TRIM
	C$fb_rollo10.c$188$4$13 ==.
;	..\fb_rollo10.c:188: cal++;
	inc	r6
00139$:
	C$fb_rollo10.c$190$3$10 ==.
;	..\fb_rollo10.c:190: if(cmd=='w'){
	cjne	r5,#0x77,00141$
	C$fb_rollo10.c$191$4$14 ==.
;	..\fb_rollo10.c:191: EA=0;
	clr	_IEN0_7
	C$fb_rollo10.c$192$4$14 ==.
;	..\fb_rollo10.c:192: START_WRITECYCLE;	//cal an 0x1bff schreiben
	mov	_FMCON,#0x00
	C$fb_rollo10.c$198$4$14 ==.
;	..\fb_rollo10.c:198: FMADRH= 0x1B;		
	mov	_FMADRH,#0x1B
	C$fb_rollo10.c$199$4$14 ==.
;	..\fb_rollo10.c:199: FMADRL= 0xFF; 
	mov	_FMADRL,#0xFF
	C$fb_rollo10.c$201$4$14 ==.
;	..\fb_rollo10.c:201: FMDATA=	cal;
	mov	_FMDATA,r6
	C$fb_rollo10.c$202$4$14 ==.
;	..\fb_rollo10.c:202: STOP_WRITECYCLE;
	mov	_FMCON,#0x68
	C$fb_rollo10.c$203$4$14 ==.
;	..\fb_rollo10.c:203: EA=1;				//int wieder freigeben
	setb	_IEN0_7
00141$:
	C$fb_rollo10.c$205$3$10 ==.
;	..\fb_rollo10.c:205: if(cmd=='p')status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
	cjne	r5,#0x70,00143$
	xrl	_status60,#0x81
00143$:
	C$fb_rollo10.c$222$3$10 ==.
;	..\fb_rollo10.c:222: if(cmd=='v'){
	cjne	r5,#0x76,00148$
	C$fb_rollo10.c$223$4$15 ==.
;	..\fb_rollo10.c:223: while(!TI);
00144$:
	C$fb_rollo10.c$224$4$15 ==.
;	..\fb_rollo10.c:224: TI=0;
	jbc	_SCON_1,00254$
	sjmp	00144$
00254$:
	C$fb_rollo10.c$225$4$15 ==.
;	..\fb_rollo10.c:225: SBUF=VERSION;
	mov	_SBUF,#0x0A
00148$:
	C$fb_rollo10.c$227$3$10 ==.
;	..\fb_rollo10.c:227: if(cmd=='t'){
	cjne	r5,#0x74,00155$
	C$fb_rollo10.c$228$4$16 ==.
;	..\fb_rollo10.c:228: while(!TI);
00149$:
	C$fb_rollo10.c$229$4$16 ==.
;	..\fb_rollo10.c:229: TI=0;
	jbc	_SCON_1,00257$
	sjmp	00149$
00257$:
	C$fb_rollo10.c$230$4$16 ==.
;	..\fb_rollo10.c:230: SBUF=TYPE;
	mov	_SBUF,#0x00
00155$:
	C$fb_rollo10.c$235$2$4 ==.
;	..\fb_rollo10.c:235: TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
	setb	_P1_7
	C$fb_rollo10.c$236$2$4 ==.
;	..\fb_rollo10.c:236: if(!TASTER){ // Taster gedrückt
	jb	_P1_7,00165$
	C$fb_rollo10.c$237$3$17 ==.
;	..\fb_rollo10.c:237: if(tasterpegel<255)	tasterpegel++;
	cjne	r7,#0xFF,00259$
00259$:
	jnc	00159$
	inc	r7
	sjmp	00166$
00159$:
	C$fb_rollo10.c$239$4$18 ==.
;	..\fb_rollo10.c:239: if(!tastergetoggelt)status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
	jb	b0,00157$
	xrl	_status60,#0x81
00157$:
	C$fb_rollo10.c$240$4$18 ==.
;	..\fb_rollo10.c:240: tastergetoggelt=1;
	setb	b0
	sjmp	00166$
00165$:
	C$fb_rollo10.c$244$3$19 ==.
;	..\fb_rollo10.c:244: if(tasterpegel>0) tasterpegel--;
	mov	a,r7
	jz	00162$
	dec	r7
	sjmp	00166$
00162$:
	C$fb_rollo10.c$245$3$19 ==.
;	..\fb_rollo10.c:245: else tastergetoggelt=0;
	clr	b0
00166$:
	C$fb_rollo10.c$247$2$4 ==.
;	..\fb_rollo10.c:247: TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
	mov	a,_status60
	anl	a,#0x01
	mov	r5,a
	cjne	a,#0x01,00263$
00263$:
	clr	a
	rlc	a
	mov	r5,a
	add	a,#0xff
	mov	_P1_7,c
	C$fb_rollo10.c$248$1$1 ==.
;	..\fb_rollo10.c:248: } while(1);
	ljmp	00167$
	C$fb_rollo10.c$249$1$1 ==.
	XG$main$0$0 ==.
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
Lfb_rollo10.main$trimsave$1$1 == 0x1bff
_main_trimsave_1_1	=	0x1bff
Lfb_rollo10.main$blockedsave$1$1 == 0x1bfd
_main_blockedsave_1_1	=	0x1bfd
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
