;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
; This file was generated Sun Nov 25 23:48:41 2012
;--------------------------------------------------------
	.module fb_counter
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _space
	.globl _bitmask_1
	.globl _main
	.globl _checklevel
	.globl _bus_return
	.globl _restart_app
	.globl _read_obj_value
	.globl _delay_timer
	.globl _pin_changed
	.globl _keypad_init
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
	.ds	5
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	ljmp	_keypad_isr
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
;n                         Allocated to registers r6 
;cmd                       Allocated to registers r6 
;tasterpegel               Allocated to registers r7 
;tmp                       Allocated to registers r5 
;cal                       Allocated to stack - _bp +1
;pin                       Allocated to registers 
;wduf                      Allocated to registers b1 
;tastergetoggelt           Allocated to registers b0 
;------------------------------------------------------------
	G$main$0$0 ==.
	C$fb_counter.c$34$0$0 ==.
;	..\fb_counter.c:34: void main(void)
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
	push	_bp
	mov	_bp,sp
	inc	sp
	C$fb_counter.c$36$1$0 ==.
;	..\fb_counter.c:36: unsigned char n,cmd,tasterpegel=0,tmp;
	mov	r7,#0x00
	C$fb_counter.c$47$1$0 ==.
;	..\fb_counter.c:47: __bit wduf,tastergetoggelt=0;
	clr	b0
	C$fb_counter.c$48$1$1 ==.
;	..\fb_counter.c:48: wduf=WDCON&0x02;
	mov	a,_WDCON
	rr	a
	anl	a,#0x01
	mov	r6,a
	add	a,#0xff
	mov	b1,c
	C$fb_counter.c$49$1$1 ==.
;	..\fb_counter.c:49: TASTER=1;
	setb	_P1_7
	C$fb_counter.c$50$1$1 ==.
;	..\fb_counter.c:50: if(!TASTER && wduf)cal=0;
	jb	_P1_7,00102$
	jnb	b1,00102$
	mov	r0,_bp
	inc	r0
	mov	@r0,#0x00
	sjmp	00103$
00102$:
	C$fb_counter.c$51$1$1 ==.
;	..\fb_counter.c:51: else cal=trimsave;
	mov	dptr,#_main_trimsave_1_1
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	mov	r0,_bp
	inc	r0
	mov	@r0,ar5
00103$:
	C$fb_counter.c$52$1$1 ==.
;	..\fb_counter.c:52: TRIM = (TRIM+trimsave);
	mov	dptr,#_main_trimsave_1_1
	clr	a
	movc	a,@a+dptr
	mov	r4,_TRIM
	add	a,r4
	mov	r5,a
	mov	_TRIM,r5
	C$fb_counter.c$53$1$1 ==.
;	..\fb_counter.c:53: TRIM &= 0x3F;//oberen 2 bits ausblenden
	anl	_TRIM,#0x3F
	C$fb_counter.c$55$1$1 ==.
;	..\fb_counter.c:55: restart_hw();				// Hardware zurücksetzen
	push	ar7
	push	bits
	lcall	_restart_hw
	pop	bits
	C$fb_counter.c$58$1$1 ==.
;	..\fb_counter.c:58: BRGCON&=0xFE;	// Baudrate Generator stoppen
	anl	_BRGCON,#0xFE
	C$fb_counter.c$59$1$1 ==.
;	..\fb_counter.c:59: P1M1&=0xFC;		// RX und TX auf bidirectional setzen
	anl	_P1M1,#0xFC
	C$fb_counter.c$60$1$1 ==.
;	..\fb_counter.c:60: P1M2&=0xFC;
	anl	_P1M2,#0xFC
	C$fb_counter.c$61$1$1 ==.
;	..\fb_counter.c:61: SCON=0x50;		// Mode 1, receive enable
	mov	_SCON,#0x50
	C$fb_counter.c$62$1$1 ==.
;	..\fb_counter.c:62: SSTAT|=0xE0;	// TI wird am Ende des Stopbits gesetzt und Interrupt nur bei RX und double TX buffer an
	orl	_SSTAT,#0xE0
	C$fb_counter.c$63$1$1 ==.
;	..\fb_counter.c:63: BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
	orl	_BRGCON,#0x02
	C$fb_counter.c$64$1$1 ==.
;	..\fb_counter.c:64: BRGR1=0x2f;	// Baudrate = cclk/((BRGR1,BRGR0)+16)
	mov	_BRGR1,#0x2F
	C$fb_counter.c$65$1$1 ==.
;	..\fb_counter.c:65: BRGR0=0xf0;	// für 115200 0030 nehmen, autocal: 600bd= 0x2FF0
	mov	_BRGR0,#0xF0
	C$fb_counter.c$66$1$1 ==.
;	..\fb_counter.c:66: BRGCON|=0x01;	// Baudrate Generator starten
	orl	_BRGCON,#0x01
	C$fb_counter.c$67$1$1 ==.
;	..\fb_counter.c:67: SBUF=0x55;
	mov	_SBUF,#0x55
	C$fb_counter.c$73$1$1 ==.
;	..\fb_counter.c:73: restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
	push	bits
	lcall	_restart_app
	pop	bits
	C$fb_counter.c$74$1$1 ==.
;	..\fb_counter.c:74: keypad_init();			// keyboard interrupt initialisieren
	push	bits
	lcall	_keypad_init
	pop	bits
	pop	ar7
	C$fb_counter.c$77$1$1 ==.
;	..\fb_counter.c:77: portbuffer=0;			// wenn schalter ein, eine obj change erzeugen
	mov	_portbuffer,#0x00
	C$fb_counter.c$78$1$1 ==.
;	..\fb_counter.c:78: p0h=portbuffer;
	mov	_p0h,#0x00
	C$fb_counter.c$83$1$1 ==.
;	..\fb_counter.c:83: if(!wduf){
	jb	b1,00109$
	C$fb_counter.c$85$1$1 ==.
;	..\fb_counter.c:85: for (n=0;n<50;n++) {		// Warten bis Bus stabil
	mov	r5,#0x00
00186$:
	cjne	r5,#0x32,00257$
00257$:
	jnc	00109$
	C$fb_counter.c$86$3$3 ==.
;	..\fb_counter.c:86: TR0=0;					// Timer 0 anhalten
	clr	_TCON_4
	C$fb_counter.c$87$3$3 ==.
;	..\fb_counter.c:87: TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
	mov	dptr,#(_eeprom + 0x0017)
	clr	a
	movc	a,@a+dptr
	mov	_TH0,a
	C$fb_counter.c$88$3$3 ==.
;	..\fb_counter.c:88: TL0=eeprom[ADDRTAB+2];
	mov	dptr,#(_eeprom + 0x0018)
	clr	a
	movc	a,@a+dptr
	mov	_TL0,a
	C$fb_counter.c$89$3$3 ==.
;	..\fb_counter.c:89: TF0=0;					// Überlauf-Flag zurücksetzen
	clr	_TCON_5
	C$fb_counter.c$90$3$3 ==.
;	..\fb_counter.c:90: TR0=1;					// Timer 0 starten
	setb	_TCON_4
	C$fb_counter.c$91$3$3 ==.
;	..\fb_counter.c:91: while(!TF0);
00105$:
	jnb	_TCON_5,00105$
	C$fb_counter.c$85$2$2 ==.
;	..\fb_counter.c:85: for (n=0;n<50;n++) {		// Warten bis Bus stabil
	inc	r5
	sjmp	00186$
00109$:
	C$fb_counter.c$97$1$1 ==.
;	..\fb_counter.c:97: if(!wduf)bus_return();			// Anwendungsspezifische Einstellungen zurücksetzen
	jb	b1,00111$
	push	ar7
	push	bits
	lcall	_bus_return
	pop	bits
	pop	ar7
00111$:
	C$fb_counter.c$99$1$1 ==.
;	..\fb_counter.c:99: TASTER=1;// progled/taster
	setb	_P1_7
	C$fb_counter.c$100$1$1 ==.
;	..\fb_counter.c:100: do  {
00183$:
	C$fb_counter.c$109$2$4 ==.
;	..\fb_counter.c:109: if(APPLICATION_RUN){
	mov	dptr,#(_eeprom + 0x000d)
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	cjne	r5,#0xFF,00261$
	sjmp	00262$
00261$:
	ljmp	00140$
00262$:
	jnb	_connected,00263$
	ljmp	00140$
00263$:
	mov	a,_status60
	jnb	acc.0,00264$
	ljmp	00140$
00264$:
	C$fb_counter.c$110$3$5 ==.
;	..\fb_counter.c:110: EKBI = 1;
	setb	_IEN1_1
	C$fb_counter.c$112$3$5 ==.
;	..\fb_counter.c:112: p0h=P0;				// prüfen ob ein Eingang sich geändert hat
	mov	_p0h,_P0
	C$fb_counter.c$116$3$5 ==.
;	..\fb_counter.c:116: if (p0h!=portbuffer) 
	mov	a,_portbuffer
	cjne	a,_p0h,00265$
	sjmp	00221$
00265$:
	C$fb_counter.c$118$5$7 ==.
;	..\fb_counter.c:118: for(n=1;n<4;n+=2)					// jeden Eingangspin einzel prüfen
	mov	r5,#0x01
00190$:
	cjne	r5,#0x04,00266$
00266$:
	jnc	00193$
	C$fb_counter.c$120$5$7 ==.
;	..\fb_counter.c:120: if ((p0h^portbuffer) & bitmask_1[n] )//kürzeste Version
	mov	a,_portbuffer
	xrl	a,_p0h
	mov	r4,a
	mov	a,r5
	mov	dptr,#_bitmask_1
	movc	a,@a+dptr
	mov	r3,a
	anl	a,r4
	jz	00192$
	C$fb_counter.c$122$6$8 ==.
;	..\fb_counter.c:122: pin_changed(n);				// Änderung verarbeiten
	mov	dpl,r5
	push	ar7
	push	ar5
	push	bits
	lcall	_pin_changed
	pop	bits
	pop	ar5
	pop	ar7
00192$:
	C$fb_counter.c$118$4$6 ==.
;	..\fb_counter.c:118: for(n=1;n<4;n+=2)					// jeden Eingangspin einzel prüfen
	inc	r5
	inc	r5
	sjmp	00190$
00193$:
	C$fb_counter.c$125$4$6 ==.
;	..\fb_counter.c:125: portbuffer=p0h;					// neuen Portzustand in buffer speichern
	mov	_portbuffer,_p0h
	C$fb_counter.c$130$1$1 ==.
;	..\fb_counter.c:130: while (precounter0 && timerbase[0]<0x80){// wenn precounter0 was gezählt hat und keine Löschanforderung besteht
00221$:
00120$:
	mov	a,_precounter0
	jnz	00269$
	ljmp	00225$
00269$:
	mov	a,#0x100 - 0x80
	add	a,_timerbase
	jnc	00270$
	ljmp	00225$
00270$:
	C$fb_counter.c$131$4$9 ==.
;	..\fb_counter.c:131: tmp=precounter0;
	mov	r5,_precounter0
	C$fb_counter.c$132$4$9 ==.
;	..\fb_counter.c:132: if(read_obj_value(2)==0){ // Tarif 1
	mov	dpl,#0x02
	push	ar7
	push	ar5
	push	bits
	lcall	_read_obj_value
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r6,a
	pop	bits
	pop	ar5
	pop	ar7
	mov	a,r2
	orl	a,r3
	orl	a,r4
	orl	a,r6
	C$fb_counter.c$133$5$10 ==.
;	..\fb_counter.c:133: counter_moment[0]+=tmp;
	jnz	00117$
	mov	ar4,r5
	mov	r6,a
	mov	a,r4
	add	a,_counter_moment
	mov	r4,a
	mov	a,r6
	addc	a,(_counter_moment + 1)
	mov	r6,a
	mov	(_counter_moment + 0),r4
	mov	(_counter_moment + 1),r6
	C$fb_counter.c$134$5$10 ==.
;	..\fb_counter.c:134: counter_summe[0]+=tmp;
	mov	ar2,r5
	clr	a
	mov	r3,a
	mov	r4,a
	mov	r6,a
	mov	a,r2
	add	a,_counter_summe
	mov	r2,a
	mov	a,r3
	addc	a,(_counter_summe + 1)
	mov	r3,a
	mov	a,r4
	addc	a,(_counter_summe + 2)
	mov	r4,a
	mov	a,r6
	addc	a,(_counter_summe + 3)
	mov	r6,a
	mov	(_counter_summe + 0),r2
	mov	(_counter_summe + 1),r3
	mov	(_counter_summe + 2),r4
	mov	(_counter_summe + 3),r6
	sjmp	00118$
00117$:
	C$fb_counter.c$138$5$11 ==.
;	..\fb_counter.c:138: counter_moment[1]+=tmp;
	mov	ar4,r5
	mov	r6,#0x00
	mov	a,r4
	add	a,(_counter_moment + 0x0002)
	mov	r4,a
	mov	a,r6
	addc	a,((_counter_moment + 0x0002) + 1)
	mov	r6,a
	mov	((_counter_moment + 0x0002) + 0),r4
	mov	((_counter_moment + 0x0002) + 1),r6
	C$fb_counter.c$139$5$11 ==.
;	..\fb_counter.c:139: counter_summe[1]+=tmp;
	mov	ar2,r5
	clr	a
	mov	r3,a
	mov	r4,a
	mov	r6,a
	mov	a,r2
	add	a,(_counter_summe + 0x0004)
	mov	r2,a
	mov	a,r3
	addc	a,((_counter_summe + 0x0004) + 1)
	mov	r3,a
	mov	a,r4
	addc	a,((_counter_summe + 0x0004) + 2)
	mov	r4,a
	mov	a,r6
	addc	a,((_counter_summe + 0x0004) + 3)
	mov	r6,a
	mov	((_counter_summe + 0x0004) + 0),r2
	mov	((_counter_summe + 0x0004) + 1),r3
	mov	((_counter_summe + 0x0004) + 2),r4
	mov	((_counter_summe + 0x0004) + 3),r6
00118$:
	C$fb_counter.c$141$4$9 ==.
;	..\fb_counter.c:141: precounter0-=tmp;
	mov	a,_precounter0
	clr	c
	subb	a,r5
	mov	_precounter0,a
	ljmp	00120$
	C$fb_counter.c$143$1$1 ==.
;	..\fb_counter.c:143: while(precounter1 && timerbase [2]<0x80){// wenn precounter1 was gezählt hat und keine Löschanforderung besteht
00225$:
00127$:
	mov	a,_precounter1
	jnz	00272$
	ljmp	00129$
00272$:
	mov	a,#0x100 - 0x80
	add	a,(_timerbase + 0x0002)
	jnc	00273$
	ljmp	00129$
00273$:
	C$fb_counter.c$144$4$12 ==.
;	..\fb_counter.c:144: tmp=precounter1;
	mov	r5,_precounter1
	C$fb_counter.c$145$4$12 ==.
;	..\fb_counter.c:145: if(read_obj_value(15)==0){ // Tarif 1
	mov	dpl,#0x0F
	push	ar7
	push	ar5
	push	bits
	lcall	_read_obj_value
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r6,a
	pop	bits
	pop	ar5
	pop	ar7
	mov	a,r2
	orl	a,r3
	orl	a,r4
	orl	a,r6
	C$fb_counter.c$146$5$13 ==.
;	..\fb_counter.c:146: counter_moment[2]+=tmp;
	jnz	00124$
	mov	ar4,r5
	mov	r6,a
	mov	a,r4
	add	a,(_counter_moment + 0x0004)
	mov	r4,a
	mov	a,r6
	addc	a,((_counter_moment + 0x0004) + 1)
	mov	r6,a
	mov	((_counter_moment + 0x0004) + 0),r4
	mov	((_counter_moment + 0x0004) + 1),r6
	C$fb_counter.c$147$5$13 ==.
;	..\fb_counter.c:147: counter_summe[2]+=tmp;
	mov	ar2,r5
	clr	a
	mov	r3,a
	mov	r4,a
	mov	r6,a
	mov	a,r2
	add	a,(_counter_summe + 0x0008)
	mov	r2,a
	mov	a,r3
	addc	a,((_counter_summe + 0x0008) + 1)
	mov	r3,a
	mov	a,r4
	addc	a,((_counter_summe + 0x0008) + 2)
	mov	r4,a
	mov	a,r6
	addc	a,((_counter_summe + 0x0008) + 3)
	mov	r6,a
	mov	((_counter_summe + 0x0008) + 0),r2
	mov	((_counter_summe + 0x0008) + 1),r3
	mov	((_counter_summe + 0x0008) + 2),r4
	mov	((_counter_summe + 0x0008) + 3),r6
	sjmp	00125$
00124$:
	C$fb_counter.c$150$5$14 ==.
;	..\fb_counter.c:150: counter_moment[3]+=tmp;
	mov	ar4,r5
	mov	r6,#0x00
	mov	a,r4
	add	a,(_counter_moment + 0x0006)
	mov	r4,a
	mov	a,r6
	addc	a,((_counter_moment + 0x0006) + 1)
	mov	r6,a
	mov	((_counter_moment + 0x0006) + 0),r4
	mov	((_counter_moment + 0x0006) + 1),r6
	C$fb_counter.c$151$5$14 ==.
;	..\fb_counter.c:151: counter_summe[3]+=tmp;
	mov	ar2,r5
	clr	a
	mov	r3,a
	mov	r4,a
	mov	r6,a
	mov	a,r2
	add	a,(_counter_summe + 0x000c)
	mov	r2,a
	mov	a,r3
	addc	a,((_counter_summe + 0x000c) + 1)
	mov	r3,a
	mov	a,r4
	addc	a,((_counter_summe + 0x000c) + 2)
	mov	r4,a
	mov	a,r6
	addc	a,((_counter_summe + 0x000c) + 3)
	mov	r6,a
	mov	((_counter_summe + 0x000c) + 0),r2
	mov	((_counter_summe + 0x000c) + 1),r3
	mov	((_counter_summe + 0x000c) + 2),r4
	mov	((_counter_summe + 0x000c) + 3),r6
00125$:
	C$fb_counter.c$153$4$12 ==.
;	..\fb_counter.c:153: precounter1-=tmp;
	mov	a,_precounter1
	clr	c
	subb	a,r5
	mov	_precounter1,a
	ljmp	00127$
00129$:
	C$fb_counter.c$158$3$5 ==.
;	..\fb_counter.c:158: if (RTCCON>=0x80){
	mov	a,#0x100 - 0x80
	add	a,_RTCCON
	jnc	00231$
	C$fb_counter.c$159$4$15 ==.
;	..\fb_counter.c:159: delay_timer();	// Realtime clock ueberlauf
	push	ar7
	push	bits
	lcall	_delay_timer
	pop	bits
	pop	ar7
	C$fb_counter.c$164$1$1 ==.
;	..\fb_counter.c:164: for (n=0;n<4;n+=2){
00231$:
	mov	r6,#0x00
00194$:
	cjne	r6,#0x04,00276$
00276$:
	jnc	00141$
	C$fb_counter.c$165$4$16 ==.
;	..\fb_counter.c:165: if(timerbase[n]& 0x80){// wenn Löschanforderung besteht
	mov	a,r6
	add	a,#_timerbase
	mov	r1,a
	mov	a,@r1
	mov	r5,a
	jnb	acc.7,00196$
	C$fb_counter.c$166$5$17 ==.
;	..\fb_counter.c:166: if (!TR1){// warten bis statemachine fertig ist...
	jb	_TCON_6,00196$
	C$fb_counter.c$167$6$18 ==.
;	..\fb_counter.c:167: checklevel(1,(timerbase[n]& 0xC0)+n);//checkt hier alle, also auch solche die noch nicht die Zeit erreicht haben!!
	anl	ar5,#0xC0
	mov	a,r6
	add	a,r5
	mov	r5,a
	setb	b[0]
	push	ar7
	push	ar6
	push	bits
	mov	bits,b
	mov	dpl,r5
	lcall	_checklevel
	pop	bits
	pop	ar6
	pop	ar7
	C$fb_counter.c$168$6$18 ==.
;	..\fb_counter.c:168: if (timerbase[n]& 0x40){// wenn Tarif 2
	mov	a,r6
	add	a,#_timerbase
	mov	r1,a
	mov	a,@r1
	mov	r5,a
	jnb	acc.6,00133$
	C$fb_counter.c$169$7$19 ==.
;	..\fb_counter.c:169: counter_moment[n+1]=0;//Tarif2 löschen
	mov	a,r6
	inc	a
	add	a,acc
	mov	r4,a
	add	a,#_counter_moment
	mov	r0,a
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	sjmp	00134$
00133$:
	C$fb_counter.c$172$7$20 ==.
;	..\fb_counter.c:172: counter_moment[n]=0;// sonst Tarif1 löschen
	mov	a,r6
	add	a,r6
	mov	r4,a
	add	a,#_counter_moment
	mov	r0,a
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
00134$:
	C$fb_counter.c$174$6$18 ==.
;	..\fb_counter.c:174: timerbase[n]&= 0x3F;// Löschanforderung und Tarifflag zurücksetzen
	mov	a,#0x3F
	anl	a,r5
	mov	@r1,a
00196$:
	C$fb_counter.c$164$3$5 ==.
;	..\fb_counter.c:164: for (n=0;n<4;n+=2){
	inc	r6
	inc	r6
	sjmp	00194$
00140$:
	C$fb_counter.c$182$2$4 ==.
;	..\fb_counter.c:182: else   EKBI = 0; // wenn die aplikation nicht läuft keyboard int abschalten
	clr	_IEN1_1
00141$:
	C$fb_counter.c$184$2$4 ==.
;	..\fb_counter.c:184: if (tel_arrived ) {//|| tel_sent 
	C$fb_counter.c$185$3$21 ==.
;	..\fb_counter.c:185: tel_arrived=0;
	jbc	_tel_arrived,00281$
	sjmp	00145$
00281$:
	C$fb_counter.c$186$3$21 ==.
;	..\fb_counter.c:186: tel_sent=0;
	clr	_tel_sent
	C$fb_counter.c$187$3$21 ==.
;	..\fb_counter.c:187: process_tel();
	push	ar7
	push	bits
	lcall	_process_tel
	pop	bits
	pop	ar7
	sjmp	00146$
00145$:
	C$fb_counter.c$190$3$4 ==.
;	..\fb_counter.c:190: for(n=0;n<100;n++);	// falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann
	mov	r6,#0x64
00200$:
	mov	ar5,r6
	dec	r5
	mov	ar6,r5
	mov	a,r6
	jnz	00200$
00146$:
	C$fb_counter.c$196$2$4 ==.
;	..\fb_counter.c:196: if (RI){
	C$fb_counter.c$197$3$23 ==.
;	..\fb_counter.c:197: RI=0;
	jbc	_SCON_0,00283$
	sjmp	00171$
00283$:
	C$fb_counter.c$198$3$23 ==.
;	..\fb_counter.c:198: cmd=SBUF;
	mov	r6,_SBUF
	C$fb_counter.c$199$3$23 ==.
;	..\fb_counter.c:199: if(cmd=='c'){
	cjne	r6,#0x63,00151$
	C$fb_counter.c$200$4$24 ==.
;	..\fb_counter.c:200: while(!TI);
00147$:
	C$fb_counter.c$201$4$24 ==.
;	..\fb_counter.c:201: TI=0;
	jbc	_SCON_1,00286$
	sjmp	00147$
00286$:
	C$fb_counter.c$202$4$24 ==.
;	..\fb_counter.c:202: SBUF=0x55;
	mov	_SBUF,#0x55
00151$:
	C$fb_counter.c$204$3$23 ==.
;	..\fb_counter.c:204: if(cmd=='+'){
	cjne	r6,#0x2B,00153$
	C$fb_counter.c$205$4$25 ==.
;	..\fb_counter.c:205: TRIM--;
	dec	_TRIM
	C$fb_counter.c$206$4$25 ==.
;	..\fb_counter.c:206: cal--;
	mov	r0,_bp
	inc	r0
	dec	@r0
00153$:
	C$fb_counter.c$208$3$23 ==.
;	..\fb_counter.c:208: if(cmd=='-'){
	cjne	r6,#0x2D,00155$
	C$fb_counter.c$209$4$26 ==.
;	..\fb_counter.c:209: TRIM++;
	inc	_TRIM
	C$fb_counter.c$210$4$26 ==.
;	..\fb_counter.c:210: cal++;
	mov	r0,_bp
	inc	r0
	inc	@r0
00155$:
	C$fb_counter.c$212$3$23 ==.
;	..\fb_counter.c:212: if(cmd=='w'){
	cjne	r6,#0x77,00157$
	C$fb_counter.c$213$4$27 ==.
;	..\fb_counter.c:213: EA=0;
	clr	_IEN0_7
	C$fb_counter.c$214$4$27 ==.
;	..\fb_counter.c:214: START_WRITECYCLE;	//cal an 0x1CFF schreiben
	mov	_FMCON,#0x00
	C$fb_counter.c$216$4$27 ==.
;	..\fb_counter.c:216: FMADRH= 0x1C;		
	mov	_FMADRH,#0x1C
	C$fb_counter.c$217$4$27 ==.
;	..\fb_counter.c:217: FMADRL= 0xFF; 
	mov	_FMADRL,#0xFF
	C$fb_counter.c$219$4$27 ==.
;	..\fb_counter.c:219: FMDATA=	cal;
	mov	r0,_bp
	inc	r0
	mov	_FMDATA,@r0
	C$fb_counter.c$220$4$27 ==.
;	..\fb_counter.c:220: STOP_WRITECYCLE;
	mov	_FMCON,#0x68
	C$fb_counter.c$221$4$27 ==.
;	..\fb_counter.c:221: EA=1;				//int wieder freigeben
	setb	_IEN0_7
00157$:
	C$fb_counter.c$223$3$23 ==.
;	..\fb_counter.c:223: if(cmd=='p')status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
	cjne	r6,#0x70,00159$
	xrl	_status60,#0x81
00159$:
	C$fb_counter.c$225$3$23 ==.
;	..\fb_counter.c:225: if(cmd=='v'){
	cjne	r6,#0x76,00164$
	C$fb_counter.c$226$4$28 ==.
;	..\fb_counter.c:226: while(!TI);
00160$:
	C$fb_counter.c$227$4$28 ==.
;	..\fb_counter.c:227: TI=0;
	jbc	_SCON_1,00297$
	sjmp	00160$
00297$:
	C$fb_counter.c$228$4$28 ==.
;	..\fb_counter.c:228: SBUF=VERSION;
	mov	_SBUF,#0x00
00164$:
	C$fb_counter.c$230$3$23 ==.
;	..\fb_counter.c:230: if(cmd=='t'){
	cjne	r6,#0x74,00171$
	C$fb_counter.c$231$4$29 ==.
;	..\fb_counter.c:231: while(!TI);
00165$:
	C$fb_counter.c$232$4$29 ==.
;	..\fb_counter.c:232: TI=0;
	jbc	_SCON_1,00300$
	sjmp	00165$
00300$:
	C$fb_counter.c$233$4$29 ==.
;	..\fb_counter.c:233: SBUF=TYPE;
	mov	_SBUF,#0x00
00171$:
	C$fb_counter.c$238$2$4 ==.
;	..\fb_counter.c:238: TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
	setb	_P1_7
	C$fb_counter.c$239$2$4 ==.
;	..\fb_counter.c:239: if(!TASTER){ // Taster gedrückt
	jb	_P1_7,00181$
	C$fb_counter.c$240$3$30 ==.
;	..\fb_counter.c:240: if(tasterpegel<255)	tasterpegel++;
	cjne	r7,#0xFF,00302$
00302$:
	jnc	00175$
	inc	r7
	sjmp	00182$
00175$:
	C$fb_counter.c$242$4$31 ==.
;	..\fb_counter.c:242: if(!tastergetoggelt)status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
	jb	b0,00173$
	xrl	_status60,#0x81
00173$:
	C$fb_counter.c$243$4$31 ==.
;	..\fb_counter.c:243: tastergetoggelt=1;
	setb	b0
	sjmp	00182$
00181$:
	C$fb_counter.c$247$3$32 ==.
;	..\fb_counter.c:247: if(tasterpegel>0) tasterpegel--;
	mov	a,r7
	jz	00178$
	dec	r7
	sjmp	00182$
00178$:
	C$fb_counter.c$248$3$32 ==.
;	..\fb_counter.c:248: else tastergetoggelt=0;
	clr	b0
00182$:
	C$fb_counter.c$250$2$4 ==.
;	..\fb_counter.c:250: TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
	mov	a,_status60
	anl	a,#0x01
	mov	r6,a
	cjne	a,#0x01,00306$
00306$:
	clr	a
	rlc	a
	mov	r6,a
	add	a,#0xff
	mov	_P1_7,c
	C$fb_counter.c$252$1$1 ==.
;	..\fb_counter.c:252: } while(1);
	ljmp	00183$
	dec	sp
	pop	_bp
	C$fb_counter.c$253$1$1 ==.
	XG$main$0$0 ==.
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
G$bitmask_1$0$0 == .
_bitmask_1:
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x04	; 4
	.db #0x08	; 8
	.db #0x10	; 16
	.db #0x20	; 32
	.db #0x40	; 64
	.db #0x80	; 128
G$space$0$0 == 0x01ce
_space	=	0x01ce
Lfb_counter.main$trimsave$1$1 == 0x1cff
_main_trimsave_1_1	=	0x1cff
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
