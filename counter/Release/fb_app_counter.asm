;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
; This file was generated Sun Nov 25 23:48:06 2012
;--------------------------------------------------------
	.module fb_app_counter
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _objno_timer
	.globl _paraindex_timer
	.globl _find_first_objno
	.globl _read_objflags
	.globl _send_obj_value
	.globl _gapos_in_gat
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
	.globl _counted1
	.globl _counted0
	.globl _st_Flanke
	.globl _jobj
	.globl _objval
	.globl _precounter1
	.globl _precounter0
	.globl _bitobj_z2
	.globl _bitobj_z1
	.globl _counter_moment
	.globl _counter_summe
	.globl _para_value
	.globl _timercnt
	.globl _timerbase
	.globl _timerflags
	.globl _timerday
	.globl _timerhour
	.globl _timer60
	.globl _timer500
	.globl _timer_state
	.globl _timer_base
	.globl _objstate
	.globl _p0h
	.globl _portbuffer
	.globl _keypad_isr
	.globl _pin_changed
	.globl _eis5conversion
	.globl _delay_timer
	.globl _write_value_req
	.globl _checklevel
	.globl _read_value_req
	.globl _sendbychange
	.globl _write_send
	.globl _bus_return
	.globl _read_obj_value
	.globl _write_obj_value
	.globl _keypad_init
	.globl _restart_app
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
G$portbuffer$0$0==.
_portbuffer::
	.ds 1
G$p0h$0$0==.
_p0h::
	.ds 1
G$objstate$0$0==.
_objstate::
	.ds 2
G$timer_base$0$0==.
_timer_base::
	.ds 1
G$timer_state$0$0==.
_timer_state::
	.ds 1
G$timer500$0$0==.
_timer500::
	.ds 1
G$timer60$0$0==.
_timer60::
	.ds 1
G$timerhour$0$0==.
_timerhour::
	.ds 1
G$timerday$0$0==.
_timerday::
	.ds 1
G$timerflags$0$0==.
_timerflags::
	.ds 1
G$timerbase$0$0==.
_timerbase::
	.ds 4
G$timercnt$0$0==.
_timercnt::
	.ds 4
G$para_value$0$0==.
_para_value::
	.ds 1
G$counter_summe$0$0 == 0x0008
_counter_summe	=	0x0008
G$counter_moment$0$0 == 0x0018
_counter_moment	=	0x0018
G$bitobj_z1$0$0==.
_bitobj_z1::
	.ds 2
G$bitobj_z2$0$0==.
_bitobj_z2::
	.ds 2
G$precounter0$0$0==.
_precounter0::
	.ds 1
G$precounter1$0$0==.
_precounter1::
	.ds 1
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area OSEG    (OVR,DATA)
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
G$objval$0$0==.
_objval::
	.ds 1
G$jobj$0$0==.
_jobj::
	.ds 1
G$st_Flanke$0$0==.
_st_Flanke::
	.ds 1
G$counted0$0$0==.
_counted0::
	.ds 1
G$counted1$0$0==.
_counted1::
	.ds 1
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
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	G$restart_app$0$0 ==.
	C$fb_app_counter.c$49$1$1 ==.
;	..\fb_app_counter.c:49: __bit objval=0,jobj=0;
	clr	_objval
	G$restart_app$0$0 ==.
	C$fb_app_counter.c$49$1$1 ==.
;	..\fb_app_counter.c:49: 
	clr	_jobj
	G$restart_app$0$0 ==.
	C$fb_app_counter.c$51$1$1 ==.
;	..\fb_app_counter.c:51: __bit st_Flanke=0;
	clr	_st_Flanke
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'keypad_isr'
;------------------------------------------------------------
;keybuffer                 Allocated to registers r7 
;------------------------------------------------------------
	G$keypad_isr$0$0 ==.
	C$fb_app_counter.c$61$0$0 ==.
;	..\fb_app_counter.c:61: void keypad_isr  (void) __interrupt (7)
;	-----------------------------------------
;	 function keypad_isr
;	-----------------------------------------
_keypad_isr:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	push	acc
	push	ar7
	push	psw
	mov	psw,#0x00
	C$fb_app_counter.c$65$1$1 ==.
;	..\fb_app_counter.c:65: KBCON = 0;//0xFE;
	mov	_KBCON,#0x00
	C$fb_app_counter.c$66$1$1 ==.
;	..\fb_app_counter.c:66: keybuffer=P0;
	C$fb_app_counter.c$67$1$1 ==.
;	..\fb_app_counter.c:67: if(keybuffer&0x01 && !counted0){
	mov	a,_P0
	mov	r7,a
	jnb	acc.0,00102$
	jb	_counted0,00102$
	C$fb_app_counter.c$68$2$2 ==.
;	..\fb_app_counter.c:68: precounter0++;
	inc	_precounter0
	C$fb_app_counter.c$69$2$2 ==.
;	..\fb_app_counter.c:69: counted0=1;
	setb	_counted0
00102$:
	C$fb_app_counter.c$71$1$1 ==.
;	..\fb_app_counter.c:71: if(!(keybuffer&0x01))counted0=0;
	mov	a,r7
	jb	acc.0,00105$
	clr	_counted0
00105$:
	C$fb_app_counter.c$73$1$1 ==.
;	..\fb_app_counter.c:73: if(keybuffer&0x04 && !counted1){
	mov	a,r7
	jnb	acc.2,00107$
	jb	_counted1,00107$
	C$fb_app_counter.c$74$2$3 ==.
;	..\fb_app_counter.c:74: precounter1++;
	inc	_precounter1
	C$fb_app_counter.c$75$2$3 ==.
;	..\fb_app_counter.c:75: counted1=1;
	setb	_counted1
00107$:
	C$fb_app_counter.c$77$1$1 ==.
;	..\fb_app_counter.c:77: if(!(keybuffer&0x04))counted1=0;
	mov	a,r7
	jb	acc.2,00110$
	clr	_counted1
00110$:
	C$fb_app_counter.c$78$1$1 ==.
;	..\fb_app_counter.c:78: KBPATN=keybuffer;
	mov	_KBPATN,r7
	pop	psw
	pop	ar7
	pop	acc
	C$fb_app_counter.c$79$1$1 ==.
	XG$keypad_isr$0$0 ==.
	reti
;	eliminated unneeded push/pop ar1
;	eliminated unneeded push/pop ar0
;	eliminated unneeded push/pop dpl
;	eliminated unneeded push/pop dph
;	eliminated unneeded push/pop b
;------------------------------------------------------------
;Allocation info for local variables in function 'pin_changed'
;------------------------------------------------------------
;pinno                     Allocated to registers r7 
;tmp                       Allocated to registers 
;objoffset                 Allocated to registers r6 
;cno                       Allocated to registers r6 
;typ                       Allocated to registers 
;n                         Allocated to registers r6 
;w                         Allocated to registers r5 
;deb_result                Allocated to registers r6 
;------------------------------------------------------------
	G$pin_changed$0$0 ==.
	C$fb_app_counter.c$82$1$1 ==.
;	..\fb_app_counter.c:82: void pin_changed(unsigned char pinno)
;	-----------------------------------------
;	 function pin_changed
;	-----------------------------------------
_pin_changed:
	mov	r7,dpl
	C$fb_app_counter.c$90$1$1 ==.
;	..\fb_app_counter.c:90: timer_base=0; tmp;
	mov	_timer_base,#0x00
	C$fb_app_counter.c$91$1$1 ==.
;	..\fb_app_counter.c:91: para_value=0;
	mov	_para_value,#0x00
	C$fb_app_counter.c$93$1$1 ==.
;	..\fb_app_counter.c:93: for(n=0;n<250;n++){
	mov	r6,#0x00
00110$:
	cjne	r6,#0xFA,00131$
00131$:
	jnc	00113$
	C$fb_app_counter.c$94$1$1 ==.
;	..\fb_app_counter.c:94: for(w=255;w>0;w--); 
	mov	r5,#0xFF
00106$:
	mov	a,r5
	jz	00116$
	mov	r4,#0x01
	sjmp	00117$
00116$:
	mov	r4,#0x00
00117$:
	mov	a,r4
	jz	00112$
	dec	r5
	sjmp	00106$
00112$:
	C$fb_app_counter.c$93$1$1 ==.
;	..\fb_app_counter.c:93: for(n=0;n<250;n++){
	inc	r6
	sjmp	00110$
00113$:
	C$fb_app_counter.c$97$1$1 ==.
;	..\fb_app_counter.c:97: deb_result=((~(P0^p0h))& bitmask_1[pinno]);//ret=1;
	mov	a,_p0h
	xrl	a,_P0
	cpl	a
	mov	r6,a
	mov	a,r7
	mov	dptr,#_bitmask_1
	movc	a,@a+dptr
	mov	r5,a
	anl	ar6,a
	C$fb_app_counter.c$102$1$1 ==.
;	..\fb_app_counter.c:102: if (deb_result)			// Entprellzeit abwarten und prüfen
	mov	a,r6
	jz	00114$
	C$fb_app_counter.c$104$2$3 ==.
;	..\fb_app_counter.c:104: st_Flanke=(((portbuffer>>pinno)&0x01)==0) && (((p0h>>pinno)&0x01)==1);
	mov	b,r7
	inc	b
	mov	a,_portbuffer
	sjmp	00137$
00136$:
	clr	c
	rrc	a
00137$:
	djnz	b,00136$
	anl	a,#0x01
	mov	r6,a
	cjne	a,#0x01,00138$
00138$:
	clr	a
	rlc	a
	mov	r6,a
	jz	00118$
	mov	b,r7
	inc	b
	mov	a,_p0h
	sjmp	00141$
00140$:
	clr	c
	rrc	a
00141$:
	djnz	b,00140$
	anl	a,#0x01
	mov	r6,a
	cjne	r6,#0x01,00142$
	sjmp	00119$
00142$:
00118$:
	clr	b0
	sjmp	00120$
00119$:
	setb	b0
00120$:
	mov	c,b0
	mov	_st_Flanke,c
	C$fb_app_counter.c$105$2$3 ==.
;	..\fb_app_counter.c:105: cno=(pinno&0x02);// counter nomber 0 0der 2
	mov	a,#0x02
	anl	a,r7
	C$fb_app_counter.c$106$2$3 ==.
;	..\fb_app_counter.c:106: objoffset=13*(cno>>1);
	clr	c
	rrc	a
	mov	b,#0x0D
	mul	ab
	mov	r6,a
	C$fb_app_counter.c$107$2$3 ==.
;	..\fb_app_counter.c:107: if ((pinno==1)||(pinno==3)){
	cjne	r7,#0x01,00143$
	sjmp	00101$
00143$:
	cjne	r7,#0x03,00114$
00101$:
	C$fb_app_counter.c$108$3$4 ==.
;	..\fb_app_counter.c:108: write_obj_value(2+objoffset,st_Flanke);
	mov	c,_st_Flanke
	clr	a
	rlc	a
	mov	r3,a
	mov	r4,#0x00
	mov	r5,#0x00
	mov	r7,#0x00
	inc	r6
	inc	r6
	push	ar6
	push	ar3
	push	ar4
	push	ar5
	push	ar7
	mov	dpl,r6
	lcall	_write_obj_value
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar6
	C$fb_app_counter.c$109$3$4 ==.
;	..\fb_app_counter.c:109: send_obj_value(2+objoffset);
	mov	dpl,r6
	lcall	_send_obj_value
00114$:
	C$fb_app_counter.c$114$1$1 ==.
	XG$pin_changed$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'eis5conversion'
;------------------------------------------------------------
;zahl                      Allocated to registers r4 r5 r6 r7 
;exp                       Allocated to registers r3 
;------------------------------------------------------------
	G$eis5conversion$0$0 ==.
	C$fb_app_counter.c$121$1$1 ==.
;	..\fb_app_counter.c:121: int eis5conversion(unsigned long zahl)// wandelt 32 bit var in eis5 um
;	-----------------------------------------
;	 function eis5conversion
;	-----------------------------------------
_eis5conversion:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$fb_app_counter.c$124$1$1 ==.
;	..\fb_app_counter.c:124: while (zahl > 2047){//solange Mantisse größer 11 Bit
	mov	r3,#0x00
00101$:
	mov	a,r5
	anl	a,#0xF8
	jnz	00109$
	mov	a,r6
	jnz	00109$
	mov	a,r7
	jz	00103$
00109$:
	C$fb_app_counter.c$125$2$2 ==.
;	..\fb_app_counter.c:125: zahl=zahl>>1;// Mantisse /2
	mov	a,r7
	clr	c
	rrc	a
	mov	r7,a
	mov	a,r6
	rrc	a
	mov	r6,a
	mov	a,r5
	rrc	a
	mov	r5,a
	mov	a,r4
	rrc	a
	mov	r4,a
	C$fb_app_counter.c$126$2$2 ==.
;	..\fb_app_counter.c:126: exp++;// und exponent um 1 erhöhen (ist ein 2^exp)
	inc	r3
	sjmp	00101$
00103$:
	C$fb_app_counter.c$129$1$1 ==.
;	..\fb_app_counter.c:129: return ((int)zahl+((int)exp<<11));// exponent dazu.
	mov	a,r3
	swap	a
	rr	a
	anl	a,#0xF8
	mov	r7,a
	clr	a
	add	a,r4
	mov	dpl,a
	mov	a,r7
	addc	a,r5
	mov	dph,a
	C$fb_app_counter.c$130$1$1 ==.
	XG$eis5conversion$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay_timer'
;------------------------------------------------------------
;m                         Allocated to registers r6 
;objno                     Allocated to registers r7 
;n                         Allocated to registers r7 
;------------------------------------------------------------
	G$delay_timer$0$0 ==.
	C$fb_app_counter.c$138$1$1 ==.
;	..\fb_app_counter.c:138: void delay_timer(void)
;	-----------------------------------------
;	 function delay_timer
;	-----------------------------------------
_delay_timer:
	C$fb_app_counter.c$145$1$1 ==.
;	..\fb_app_counter.c:145: RTCCON=0x61;//	 RTC flag löschen
	mov	_RTCCON,#0x61
	C$fb_app_counter.c$147$1$1 ==.
;	..\fb_app_counter.c:147: timerflags=0x01;//setzt das niedrigste bit 0  100ms base
	mov	_timerflags,#0x01
	C$fb_app_counter.c$149$1$1 ==.
;	..\fb_app_counter.c:149: timer500++;// 500ms timer erhöhen
	inc	_timer500
	C$fb_app_counter.c$151$1$1 ==.
;	..\fb_app_counter.c:151: if(timer500==5||timer500==10){
	mov	a,#0x05
	cjne	a,_timer500,00168$
	sjmp	00101$
00168$:
	mov	a,#0x0A
	cjne	a,_timer500,00102$
00101$:
	C$fb_app_counter.c$152$2$2 ==.
;	..\fb_app_counter.c:152: timerflags|=0x02;//bit 1 500ms base
	mov	_timerflags,#0x03
00102$:
	C$fb_app_counter.c$154$1$1 ==.
;	..\fb_app_counter.c:154: if(timer500>=10){
	mov	a,#0x100 - 0x0A
	add	a,_timer500
	jnc	00105$
	C$fb_app_counter.c$155$2$3 ==.
;	..\fb_app_counter.c:155: timerflags|=0x04;//bit 2 1s base
	orl	_timerflags,#0x04
	C$fb_app_counter.c$156$2$3 ==.
;	..\fb_app_counter.c:156: timer500=0;
	mov	_timer500,#0x00
	C$fb_app_counter.c$157$2$3 ==.
;	..\fb_app_counter.c:157: timer60++;
	inc	_timer60
00105$:
	C$fb_app_counter.c$160$1$1 ==.
;	..\fb_app_counter.c:160: if(timer60>=60){	// bit 3 1min base
	mov	a,#0x100 - 0x3C
	add	a,_timer60
	jnc	00107$
	C$fb_app_counter.c$161$2$4 ==.
;	..\fb_app_counter.c:161: timerflags|=0x08;
	orl	_timerflags,#0x08
	C$fb_app_counter.c$162$2$4 ==.
;	..\fb_app_counter.c:162: timer60=0;
	mov	_timer60,#0x00
	C$fb_app_counter.c$163$2$4 ==.
;	..\fb_app_counter.c:163: timerhour++;
	inc	_timerhour
00107$:
	C$fb_app_counter.c$166$1$1 ==.
;	..\fb_app_counter.c:166: if((timerhour>=60)){	// bit 4 1hour base
	mov	a,#0x100 - 0x3C
	add	a,_timerhour
	jnc	00109$
	C$fb_app_counter.c$167$2$5 ==.
;	..\fb_app_counter.c:167: timerflags|=0x10;
	orl	_timerflags,#0x10
	C$fb_app_counter.c$168$2$5 ==.
;	..\fb_app_counter.c:168: timerhour=0;
	mov	_timerhour,#0x00
	C$fb_app_counter.c$169$2$5 ==.
;	..\fb_app_counter.c:169: timerday++;
	inc	_timerday
00109$:
	C$fb_app_counter.c$171$1$1 ==.
;	..\fb_app_counter.c:171: if((timerday>=24)){	// bit 5 1day base
	mov	a,#0x100 - 0x18
	add	a,_timerday
	jnc	00111$
	C$fb_app_counter.c$172$2$6 ==.
;	..\fb_app_counter.c:172: timerflags|=0x20;
	orl	_timerflags,#0x20
	C$fb_app_counter.c$173$2$6 ==.
;	..\fb_app_counter.c:173: timerday=0;
	mov	_timerday,#0x00
00111$:
	C$fb_app_counter.c$175$1$1 ==.
;	..\fb_app_counter.c:175: if(timerflags&0x02)checklevel(0,0xff);
	mov	a,_timerflags
	jnb	acc.1,00157$
	clr	b[0]
	mov	bits,b
	mov	dpl,#0xFF
	lcall	_checklevel
	C$fb_app_counter.c$177$1$1 ==.
;	..\fb_app_counter.c:177: for(n=0;n<6;n++){
00157$:
	mov	r7,#0x00
00135$:
	cjne	r7,#0x06,00176$
00176$:
	jnc	00138$
	C$fb_app_counter.c$178$2$7 ==.
;	..\fb_app_counter.c:178: if(timerflags & 0x01){// positive flags erzeugen und schieben
	mov	a,_timerflags
	jnb	acc.0,00119$
	C$fb_app_counter.c$179$1$1 ==.
;	..\fb_app_counter.c:179: for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
	mov	r6,#0x00
00131$:
	cjne	r6,#0x04,00179$
00179$:
	jnc	00119$
	C$fb_app_counter.c$180$4$9 ==.
;	..\fb_app_counter.c:180: if ((timerbase[m]& 0x0F)==n){// wenn die base mit der gespeicherten base übereinstimmt
	mov	a,r6
	add	a,#_timerbase
	mov	r1,a
	mov	ar5,@r1
	anl	ar5,#0x0F
	mov	a,r5
	cjne	a,ar7,00133$
	C$fb_app_counter.c$181$5$10 ==.
;	..\fb_app_counter.c:181: if (timercnt[m]>0x80){// wenn der counter läuft...
	mov	a,r6
	add	a,#_timercnt
	mov	r1,a
	mov	a,@r1
	mov	r5,a
	add	a,#0xff - 0x80
	jnc	00133$
	C$fb_app_counter.c$182$6$11 ==.
;	..\fb_app_counter.c:182: timercnt[m]=timercnt[m]-1;// den timer[m]decrementieren
	mov	a,r5
	dec	a
	mov	@r1,a
00133$:
	C$fb_app_counter.c$179$3$8 ==.
;	..\fb_app_counter.c:179: for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
	inc	r6
	sjmp	00131$
00119$:
	C$fb_app_counter.c$187$2$7 ==.
;	..\fb_app_counter.c:187: timerflags = timerflags>>1;
	mov	a,_timerflags
	clr	c
	rrc	a
	mov	_timerflags,a
	C$fb_app_counter.c$177$1$1 ==.
;	..\fb_app_counter.c:177: for(n=0;n<6;n++){
	inc	r7
	sjmp	00135$
00138$:
	C$fb_app_counter.c$192$3$13 ==.
;	..\fb_app_counter.c:192: for(objno=0;objno<4;objno++) {
	mov	r7,#0x00
00139$:
	cjne	r7,#0x04,00184$
00184$:
	jc	00185$
	ljmp	00143$
00185$:
	C$fb_app_counter.c$193$2$12 ==.
;	..\fb_app_counter.c:193: if(timercnt[objno]==0x80) {
	mov	a,r7
	add	a,#_timercnt
	mov	r1,a
	mov	ar6,@r1
	cjne	r6,#0x80,00186$
	sjmp	00187$
00186$:
	ljmp	00141$
00187$:
	C$fb_app_counter.c$194$3$13 ==.
;	..\fb_app_counter.c:194: timercnt[objno]=eeprom[paraindex_timer[objno]];//Torzeit setzen
	mov	a,r7
	add	a,r7
	mov	r6,a
	mov	r4,a
	mov	dptr,#_paraindex_timer
	movc	a,@a+dptr
	xch	a,r4
	inc	dptr
	movc	a,@a+dptr
	mov	r5,a
	mov	dpl,r4
	mov	a,#(_eeprom >> 8)
	add	a,r5
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	mov	@r1,a
	C$fb_app_counter.c$195$3$13 ==.
;	..\fb_app_counter.c:195: timerbase[objno]=eeprom[paraindex_timer[objno]+1];
	mov	a,r7
	add	a,#_timerbase
	mov	r1,a
	mov	a,r4
	inc	a
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r5,a
	mov	@r1,a
	C$fb_app_counter.c$196$3$13 ==.
;	..\fb_app_counter.c:196: if (!(objno&0x01))timerbase[objno]|= 0x80;// ;wenn Momentanwertzähler Löschung anfordern
	mov	a,r7
	jb	acc.0,00121$
	mov	ar5,@r1
	mov	a,#0x80
	orl	a,r5
	mov	@r1,a
00121$:
	C$fb_app_counter.c$197$3$13 ==.
;	..\fb_app_counter.c:197: if (read_obj_value((((objno&0x02)>>1)*13)+2)==0){// aktiven Tarif holen 
	mov	a,#0x02
	anl	a,r7
	clr	c
	rrc	a
	mov	b,#0x0D
	mul	ab
	add	a,#0x02
	mov	dpl,a
	push	ar7
	push	ar6
	lcall	_read_obj_value
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	pop	ar6
	pop	ar7
	mov	a,r2
	orl	a,r3
	orl	a,r4
	orl	a,r5
	jnz	00127$
	C$fb_app_counter.c$198$4$14 ==.
;	..\fb_app_counter.c:198: send_obj_value(objno_timer[objno]);// senden Tarif 1
	mov	a,r6
	mov	r4,a
	mov	dptr,#_objno_timer
	movc	a,@a+dptr
	xch	a,r4
	inc	dptr
	movc	a,@a+dptr
	mov	dpl,r4
	push	ar7
	lcall	_send_obj_value
	pop	ar7
	C$fb_app_counter.c$199$4$14 ==.
;	..\fb_app_counter.c:199: if (timerbase[objno]& 0x80)timerbase[objno]&= (~0x40);// wenn Löschung, dann tarif2 löschen rücksetzen
	mov	a,r7
	add	a,#_timerbase
	mov	r1,a
	mov	a,@r1
	mov	r5,a
	jnb	acc.7,00141$
	anl	ar5,#0xBF
	mov	@r1,ar5
	sjmp	00141$
00127$:
	C$fb_app_counter.c$202$4$15 ==.
;	..\fb_app_counter.c:202: send_obj_value(objno_timer[objno]+1);// senden Tarif 2
	mov	a,r6
	mov	r5,a
	mov	dptr,#_objno_timer
	movc	a,@a+dptr
	xch	a,r5
	inc	dptr
	movc	a,@a+dptr
	mov	a,r5
	inc	a
	mov	dpl,a
	push	ar7
	lcall	_send_obj_value
	pop	ar7
	C$fb_app_counter.c$203$4$15 ==.
;	..\fb_app_counter.c:203: if (timerbase[objno]& 0x80)timerbase[objno]|= 0x40;// ;wenn Löschung, dann tarif2 löschen anfordern
	mov	a,r7
	add	a,#_timerbase
	mov	r1,a
	mov	a,@r1
	mov	r6,a
	jnb	acc.7,00141$
	mov	a,#0x40
	orl	a,r6
	mov	@r1,a
00141$:
	C$fb_app_counter.c$192$1$1 ==.
;	..\fb_app_counter.c:192: for(objno=0;objno<4;objno++) {
	inc	r7
	ljmp	00139$
00143$:
	C$fb_app_counter.c$207$1$1 ==.
	XG$delay_timer$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'write_value_req'
;------------------------------------------------------------
;objno                     Allocated to stack - _bp +1
;objflags                  Allocated to registers r7 
;gapos                     Allocated to stack - _bp +2
;atp                       Allocated to registers r5 
;assno                     Allocated to stack - _bp +3
;n                         Allocated to stack - _bp +4
;gaposh                    Allocated to registers r3 
;tmp                       Allocated to stack - _bp +5
;objtype                   Allocated to registers r2 
;sloc0                     Allocated to stack - _bp +10
;sloc1                     Allocated to stack - _bp +6
;sloc2                     Allocated to stack - _bp +7
;------------------------------------------------------------
	G$write_value_req$0$0 ==.
	C$fb_app_counter.c$213$1$1 ==.
;	..\fb_app_counter.c:213: void write_value_req(void)		// Objekt-Wert setzen gemäß empfangenem EIS Telegramms
;	-----------------------------------------
;	 function write_value_req
;	-----------------------------------------
_write_value_req:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x0A
	mov	sp,a
	C$fb_app_counter.c$215$1$1 ==.
;	..\fb_app_counter.c:215: unsigned char objno,objflags,gapos,atp,assno,n,gaposh,tmp=0;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_counter.c$218$1$1 ==.
;	..\fb_app_counter.c:218: if(APPLICATION_RUN){
	mov	dptr,#(_eeprom + 0x000d)
	clr	a
	movc	a,@a+dptr
	mov	r6,a
	cjne	r6,#0xFF,00178$
	sjmp	00179$
00178$:
	ljmp	00150$
00179$:
	jnb	_connected,00180$
	ljmp	00150$
00180$:
	mov	a,_status60
	jnb	acc.0,00181$
	ljmp	00150$
00181$:
	C$fb_app_counter.c$219$2$2 ==.
;	..\fb_app_counter.c:219: gapos=gapos_in_gat(telegramm[3],telegramm[4]);
	mov	dpl,(_telegramm + 0x0003)
	push	(_telegramm + 0x0004)
	lcall	_gapos_in_gat
	mov	r6,dpl
	dec	sp
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,ar6
	C$fb_app_counter.c$220$2$2 ==.
;	..\fb_app_counter.c:220: if (gapos!=0xFF )	
	mov	r0,_bp
	inc	r0
	inc	r0
	cjne	@r0,#0xFF,00182$
	ljmp	00150$
00182$:
	C$fb_app_counter.c$222$3$3 ==.
;	..\fb_app_counter.c:222: atp=eeprom[ASSOCTABPTR];		// Association Table Pointer
	mov	dptr,#(_eeprom + 0x0011)
	clr	a
	movc	a,@a+dptr
	C$fb_app_counter.c$223$3$3 ==.
;	..\fb_app_counter.c:223: assno=eeprom[atp];				// Erster Eintrag = Anzahl Einträge
	mov	r5,a
	mov	dpl,a
	mov	dph,#(_eeprom >> 8)
	clr	a
	movc	a,@a+dptr
	mov	r4,a
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	@r0,ar4
	C$fb_app_counter.c$225$5$5 ==.
;	..\fb_app_counter.c:225: for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
	mov	a,#0x02
	add	a,r5
	mov	r3,a
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,r5
	inc	a
	mov	@r0,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	@r0,#0x00
00146$:
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	a,_bp
	add	a,#0x03
	mov	r1,a
	clr	c
	mov	a,@r0
	subb	a,@r1
	jc	00183$
	ljmp	00150$
00183$:
	C$fb_app_counter.c$226$1$1 ==.
;	..\fb_app_counter.c:226: gaposh=eeprom[atp+1+(n*2)];
	push	ar3
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	a,@r0
	add	a,acc
	mov	r7,a
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,r7
	add	a,@r0
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r3,a
	C$fb_app_counter.c$227$4$4 ==.
;	..\fb_app_counter.c:227: if(gapos==gaposh) {					// Wenn Positionsnummer übereinstimmt
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	cjne	a,ar3,00184$
	sjmp	00185$
00184$:
	pop	ar3
	ljmp	00148$
00185$:
	pop	ar3
	C$fb_app_counter.c$228$1$1 ==.
;	..\fb_app_counter.c:228: objno=eeprom[atp+2+(n*2)];			// Objektnummer
	mov	a,r7
	add	a,r3
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r5,a
	mov	r0,_bp
	inc	r0
	mov	@r0,ar5
	C$fb_app_counter.c$229$5$5 ==.
;	..\fb_app_counter.c:229: objflags=read_objflags(objno);		// Objekt Flags lesen
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	push	ar3
	lcall	_read_objflags
	mov	r5,dpl
	pop	ar3
	mov	ar7,r5
	C$fb_app_counter.c$230$5$5 ==.
;	..\fb_app_counter.c:230: objtype=eeprom[eeprom[COMMSTABPTR]+objno*3+4];
	mov	dptr,#(_eeprom + 0x0012)
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	mov	b,#0x03
	mul	ab
	add	a,r5
	add	a,#0x04
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r2,a
	C$fb_app_counter.c$232$5$5 ==.
;	..\fb_app_counter.c:232: if((objflags&0x14)==0x14) {			// Kommunikation zulässig (Bit 2 = communication enable) + Schreiben zulässig (Bit 4 = write enable)
	mov	a,#0x14
	anl	a,r7
	mov	r5,a
	cjne	r5,#0x14,00186$
	sjmp	00187$
00186$:
	ljmp	00148$
00187$:
	C$fb_app_counter.c$233$6$6 ==.
;	..\fb_app_counter.c:233: if (objno<25) {					// Status der Eingangsobjekte 0-24
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x19,00188$
00188$:
	jc	00189$
	ljmp	00148$
00189$:
	C$fb_app_counter.c$234$7$7 ==.
;	..\fb_app_counter.c:234: if (objtype<=6){
	mov	a,r2
	add	a,#0xff - 0x06
	jc	00102$
	C$fb_app_counter.c$235$1$1 ==.
;	..\fb_app_counter.c:235: tmp=telegramm[7]& 0x3F; //bit 6+7 löschen (0x40,0x80)
	push	ar3
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,#0x3F
	anl	a,(_telegramm + 0x0007)
	mov	@r0,a
	C$fb_app_counter.c$236$8$8 ==.
;	..\fb_app_counter.c:236: write_obj_value(objno,tmp);
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	ar3,@r0
	mov	r4,#0x00
	mov	r6,#0x00
	mov	r7,#0x00
	push	ar3
	push	ar2
	push	ar3
	push	ar4
	push	ar6
	push	ar7
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	lcall	_write_obj_value
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar2
	pop	ar3
	C$fb_app_counter.c$225$1$1 ==.
;	..\fb_app_counter.c:225: for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
	pop	ar3
	C$fb_app_counter.c$236$7$7 ==.
;	..\fb_app_counter.c:236: write_obj_value(objno,tmp);
00102$:
	C$fb_app_counter.c$238$7$7 ==.
;	..\fb_app_counter.c:238: if((objno==11 &&  bitobj_z1 & 0x40)||
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x0B,00111$
	mov	a,_bitobj_z1
	jb	acc.6,00107$
00111$:
	C$fb_app_counter.c$239$7$7 ==.
;	..\fb_app_counter.c:239: (objno==12 &&  bitobj_z1 & 0x0100)||
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x0C,00113$
	mov	a,(_bitobj_z1 + 1)
	jb	acc.0,00107$
00113$:
	C$fb_app_counter.c$240$7$7 ==.
;	..\fb_app_counter.c:240: (objno==24 &&  bitobj_z2 & 0x40)||
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x18,00115$
	mov	a,_bitobj_z2
	jb	acc.6,00107$
00115$:
	C$fb_app_counter.c$241$7$7 ==.
;	..\fb_app_counter.c:241: (objno==25 &&  bitobj_z2 & 0x0100)){
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x19,00200$
	sjmp	00201$
00200$:
	ljmp	00108$
00201$:
	mov	a,(_bitobj_z2 + 1)
	jb	acc.0,00202$
	ljmp	00108$
00202$:
00107$:
	C$fb_app_counter.c$243$8$9 ==.
;	..\fb_app_counter.c:243: if (objtype==8)write_obj_value(objno,telegramm[9]+(telegramm[8]<<8));
	cjne	r2,#0x08,00104$
	push	ar3
	mov	r6,(_telegramm + 0x0009)
	mov	r7,#0x00
	mov	r3,(_telegramm + 0x0008)
	mov	ar4,r3
	clr	a
	add	a,r6
	mov	r6,a
	mov	a,r4
	addc	a,r7
	mov	r7,a
	rlc	a
	subb	a,acc
	mov	r4,a
	mov	r3,a
	push	ar3
	push	ar2
	push	ar6
	push	ar7
	push	ar4
	push	ar3
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	lcall	_write_obj_value
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar2
	pop	ar3
	C$fb_app_counter.c$225$1$1 ==.
;	..\fb_app_counter.c:225: for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
	pop	ar3
	C$fb_app_counter.c$243$8$9 ==.
;	..\fb_app_counter.c:243: if (objtype==8)write_obj_value(objno,telegramm[9]+(telegramm[8]<<8));
00104$:
	C$fb_app_counter.c$245$8$9 ==.
;	..\fb_app_counter.c:245: if (objtype==10)write_obj_value(objno,(unsigned int)(telegramm[11] | (telegramm[10] << 8)) |((unsigned long)(telegramm[9] | (telegramm[8] << 8)) << 16));//
	cjne	r2,#0x0A,00108$
	push	ar3
	mov	r7,(_telegramm + 0x000a)
	mov	r6,#0x00
	mov	r3,(_telegramm + 0x000b)
	mov	r4,#0x00
	mov	a,r3
	orl	ar6,a
	mov	a,r4
	orl	ar7,a
	mov	r4,(_telegramm + 0x0008)
	mov	r3,#0x00
	mov	r2,(_telegramm + 0x0009)
	mov	r5,#0x00
	mov	a,r2
	orl	ar3,a
	mov	a,r5
	orl	ar4,a
	mov	a,r4
	rlc	a
	subb	a,acc
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	inc	r0
	inc	r0
	inc	r0
	mov	@r0,ar4
	dec	r0
	mov	@r0,ar3
	dec	r0
	mov	@r0,#0x00
	dec	r0
	mov	@r0,#0x00
	mov	ar4,r6
	mov	ar5,r7
	clr	a
	mov	r6,a
	mov	r7,a
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,@r0
	orl	ar4,a
	inc	r0
	mov	a,@r0
	orl	ar5,a
	inc	r0
	mov	a,@r0
	orl	ar6,a
	inc	r0
	mov	a,@r0
	orl	ar7,a
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	lcall	_write_obj_value
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar3
	C$fb_app_counter.c$225$1$1 ==.
;	..\fb_app_counter.c:225: for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
	pop	ar3
	C$fb_app_counter.c$245$7$7 ==.
;	..\fb_app_counter.c:245: if (objtype==10)write_obj_value(objno,(unsigned int)(telegramm[11] | (telegramm[10] << 8)) |((unsigned long)(telegramm[9] | (telegramm[8] << 8)) << 16));//
00108$:
	C$fb_app_counter.c$247$7$7 ==.
;	..\fb_app_counter.c:247: if ( tmp!=0){// bei 'EIN' Tele
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,@r0
	jnz	00207$
	ljmp	00148$
00207$:
	C$fb_app_counter.c$248$8$10 ==.
;	..\fb_app_counter.c:248: if(objno==7)send_obj_value(11);// Anforderungen
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x07,00117$
	mov	dpl,#0x0B
	push	ar3
	lcall	_send_obj_value
	pop	ar3
00117$:
	C$fb_app_counter.c$249$8$10 ==.
;	..\fb_app_counter.c:249: if(objno==9)send_obj_value(12);
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x09,00119$
	mov	dpl,#0x0C
	push	ar3
	lcall	_send_obj_value
	pop	ar3
00119$:
	C$fb_app_counter.c$250$8$10 ==.
;	..\fb_app_counter.c:250: if(objno==20)send_obj_value(24);
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x14,00121$
	mov	dpl,#0x18
	push	ar3
	lcall	_send_obj_value
	pop	ar3
00121$:
	C$fb_app_counter.c$251$8$10 ==.
;	..\fb_app_counter.c:251: if(objno==22)send_obj_value(25);
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x16,00123$
	mov	dpl,#0x19
	push	ar3
	lcall	_send_obj_value
	pop	ar3
00123$:
	C$fb_app_counter.c$252$8$10 ==.
;	..\fb_app_counter.c:252: if(objno==8)write_obj_value(11,0);// löschungen
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x08,00125$
	push	ar3
	clr	a
	push	acc
	push	acc
	push	acc
	push	acc
	mov	dpl,#0x0B
	lcall	_write_obj_value
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar3
00125$:
	C$fb_app_counter.c$253$8$10 ==.
;	..\fb_app_counter.c:253: if(objno==10)write_obj_value(12,0);
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x0A,00127$
	push	ar3
	clr	a
	push	acc
	push	acc
	push	acc
	push	acc
	mov	dpl,#0x0C
	lcall	_write_obj_value
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar3
00127$:
	C$fb_app_counter.c$254$8$10 ==.
;	..\fb_app_counter.c:254: if(objno==21)write_obj_value(24,0);
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x15,00129$
	push	ar3
	clr	a
	push	acc
	push	acc
	push	acc
	push	acc
	mov	dpl,#0x18
	lcall	_write_obj_value
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar3
00129$:
	C$fb_app_counter.c$255$8$10 ==.
;	..\fb_app_counter.c:255: if(objno==23)write_obj_value(25,0);
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x17,00148$
	push	ar3
	clr	a
	push	acc
	push	acc
	push	acc
	push	acc
	mov	dpl,#0x19
	lcall	_write_obj_value
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar3
00148$:
	C$fb_app_counter.c$225$3$3 ==.
;	..\fb_app_counter.c:225: for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	inc	@r0
	ljmp	00146$
00150$:
	mov	sp,_bp
	pop	_bp
	C$fb_app_counter.c$263$1$1 ==.
	XG$write_value_req$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'checklevel'
;------------------------------------------------------------
;check                     Allocated to registers r7 
;fullcheck                 Allocated to registers b0 
;ctg                       Allocated to registers r5 
;c_paraptr                 Allocated to registers r4 
;c_para                    Allocated to stack - _bp +1
;c_valptr                  Allocated to registers r2 
;obj_counter               Allocated to stack - _bp +2
;obj                       Allocated to stack - _bp +3
;c_val                     Allocated to stack - _bp +4
;checken                   Allocated to registers b1 
;------------------------------------------------------------
	G$checklevel$0$0 ==.
	C$fb_app_counter.c$265$1$1 ==.
;	..\fb_app_counter.c:265: void checklevel(__bit fullcheck,unsigned char check)// vergleiche Momentanwert mit Grenzwert
;	-----------------------------------------
;	 function checklevel
;	-----------------------------------------
_checklevel:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x05
	mov	sp,a
	mov	r7,dpl
	C$fb_app_counter.c$273$3$4 ==.
;	..\fb_app_counter.c:273: for (ctg=0;ctg<=7;ctg++){
	mov	a,#0x02
	anl	a,r7
	mov	r6,a
	anl	ar7,#0x40
	mov	r5,#0x00
00128$:
	mov	a,r5
	add	a,#0xff - 0x07
	jnc	00150$
	ljmp	00132$
00150$:
	C$fb_app_counter.c$274$2$2 ==.
;	..\fb_app_counter.c:274: checken=1;
	setb	b1
	C$fb_app_counter.c$275$2$2 ==.
;	..\fb_app_counter.c:275: if (ctg&0x04){// zähler 2
	mov	a,r5
	jnb	acc.2,00106$
	C$fb_app_counter.c$276$3$3 ==.
;	..\fb_app_counter.c:276: obj_counter=13;
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,#0x0D
	C$fb_app_counter.c$277$3$3 ==.
;	..\fb_app_counter.c:277: c_paraptr=0xE9;
	mov	r4,#0xE9
	C$fb_app_counter.c$278$3$3 ==.
;	..\fb_app_counter.c:278: c_valptr=0xF0;
	mov	r2,#0xF0
	C$fb_app_counter.c$279$3$3 ==.
;	..\fb_app_counter.c:279: obj=16;
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	@r0,#0x10
	C$fb_app_counter.c$280$3$3 ==.
;	..\fb_app_counter.c:280: if((check&0x02)==0)checken=0;
	mov	a,r6
	jnz	00107$
	clr	b1
	sjmp	00107$
00106$:
	C$fb_app_counter.c$283$3$4 ==.
;	..\fb_app_counter.c:283: obj_counter=0;
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,#0x00
	C$fb_app_counter.c$284$3$4 ==.
;	..\fb_app_counter.c:284: c_paraptr=0xD3;
	mov	r4,#0xD3
	C$fb_app_counter.c$285$3$4 ==.
;	..\fb_app_counter.c:285: c_valptr=0xDA;
	mov	r2,#0xDA
	C$fb_app_counter.c$286$3$4 ==.
;	..\fb_app_counter.c:286: obj=3;
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	@r0,#0x03
	C$fb_app_counter.c$287$3$4 ==.
;	..\fb_app_counter.c:287: if(check&0x02)checken=0;
	mov	a,r6
	jz	00107$
	clr	b1
00107$:
	C$fb_app_counter.c$289$2$2 ==.
;	..\fb_app_counter.c:289: if(ctg&0x02){// tarif 2
	mov	a,r5
	jnb	acc.1,00113$
	C$fb_app_counter.c$290$3$5 ==.
;	..\fb_app_counter.c:290: obj_counter+=1;
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	@r0
	C$fb_app_counter.c$291$3$5 ==.
;	..\fb_app_counter.c:291: c_paraptr++;
	inc	r4
	C$fb_app_counter.c$292$3$5 ==.
;	..\fb_app_counter.c:292: c_valptr+=4;
	mov	a,r2
	add	a,#0x04
	mov	r2,a
	C$fb_app_counter.c$293$3$5 ==.
;	..\fb_app_counter.c:293: obj+=2;
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	inc	@r0
	inc	@r0
	C$fb_app_counter.c$294$3$5 ==.
;	..\fb_app_counter.c:294: if(!(check&0x40))checken=0;
	mov	a,r7
	jnz	00114$
	clr	b1
	sjmp	00114$
00113$:
	C$fb_app_counter.c$297$3$6 ==.
;	..\fb_app_counter.c:297: if(check & 0x40)checken=0;
	mov	a,r7
	jz	00114$
	clr	b1
00114$:
	C$fb_app_counter.c$300$1$1 ==.
;	..\fb_app_counter.c:300: c_para=eeprom[c_paraptr];
	push	ar7
	mov	dpl,r4
	mov	dph,#(_eeprom >> 8)
	clr	a
	movc	a,@a+dptr
	mov	r7,a
	mov	r0,_bp
	inc	r0
	mov	@r0,ar7
	C$fb_app_counter.c$301$2$2 ==.
;	..\fb_app_counter.c:301: if(ctg&0x01){
	mov	a,r5
	pop	ar7
	jnb	acc.0,00116$
	C$fb_app_counter.c$302$3$7 ==.
;	..\fb_app_counter.c:302: c_para=c_para>>4;
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	swap	a
	anl	a,#0x0F
	mov	@r0,a
	C$fb_app_counter.c$303$3$7 ==.
;	..\fb_app_counter.c:303: c_valptr+=2;// grenzwert 2
	inc	r2
	inc	r2
	C$fb_app_counter.c$304$3$7 ==.
;	..\fb_app_counter.c:304: obj++;
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	inc	@r0
00116$:
	C$fb_app_counter.c$307$1$1 ==.
;	..\fb_app_counter.c:307: c_val=(unsigned int)((eeprom[c_valptr]<<8)+(eeprom[c_valptr+1]));//*(unsigned int)((eeprom[c_calc]<<8)+(eeprom[c_calc+1]));
	push	ar7
	mov	dpl,r2
	mov	dph,#(_eeprom >> 8)
	clr	a
	movc	a,@a+dptr
	mov	r7,a
	mov	r4,#0x00
	mov	a,r2
	inc	a
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r3,#0x00
	add	a,r4
	mov	r4,a
	mov	a,r3
	addc	a,r7
	mov	r7,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar7
	C$fb_app_counter.c$308$2$2 ==.
;	..\fb_app_counter.c:308: if((int)read_obj_value(obj_counter) > c_val){// überschreiten
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	dpl,@r0
	push	ar6
	push	ar5
	push	bits
	lcall	_read_obj_value
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	pop	bits
	pop	ar5
	pop	ar6
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	clr	c
	mov	a,@r0
	subb	a,r2
	inc	r0
	mov	a,@r0
	subb	a,r3
	pop	ar7
	jnc	00120$
	C$fb_app_counter.c$309$3$8 ==.
;	..\fb_app_counter.c:309: if(c_para & 0x03)sendbychange(obj,c_para&0x01);
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	anl	a,#0x03
	jz	00120$
	mov	r0,_bp
	inc	r0
	mov	a,#0x01
	anl	a,@r0
	mov	r4,a
	push	ar7
	push	ar6
	push	ar5
	push	bits
	push	ar4
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	dpl,@r0
	lcall	_sendbychange
	dec	sp
	pop	bits
	pop	ar5
	pop	ar6
	pop	ar7
00120$:
	C$fb_app_counter.c$311$2$2 ==.
;	..\fb_app_counter.c:311: if (fullcheck && checken){
	jnb	b0,00130$
	jnb	b1,00130$
	C$fb_app_counter.c$312$1$1 ==.
;	..\fb_app_counter.c:312: if((int)read_obj_value(obj_counter) < c_val){// unterschreiten
	push	ar7
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	dpl,@r0
	push	ar6
	push	ar5
	push	bits
	lcall	_read_obj_value
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	pop	bits
	pop	ar5
	pop	ar6
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	clr	c
	mov	a,r2
	subb	a,@r0
	mov	a,r3
	inc	r0
	subb	a,@r0
	pop	ar7
	jnc	00130$
	C$fb_app_counter.c$313$4$10 ==.
;	..\fb_app_counter.c:313: if((c_para>>2)&0x03)sendbychange(obj,(c_para>>2)&0x01);
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	rr	a
	rr	a
	anl	a,#0x3F
	mov	r4,a
	anl	a,#0x03
	jz	00130$
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	rr	a
	rr	a
	anl	a,#0x01
	mov	r4,a
	push	ar7
	push	ar6
	push	ar5
	push	bits
	push	ar4
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	dpl,@r0
	lcall	_sendbychange
	dec	sp
	pop	bits
	pop	ar5
	pop	ar6
	pop	ar7
00130$:
	C$fb_app_counter.c$273$1$1 ==.
;	..\fb_app_counter.c:273: for (ctg=0;ctg<=7;ctg++){
	inc	r5
	ljmp	00128$
00132$:
	mov	sp,_bp
	pop	_bp
	C$fb_app_counter.c$328$1$1 ==.
	XG$checklevel$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_value_req'
;------------------------------------------------------------
;objno                     Allocated to registers r7 
;objflags                  Allocated to registers r6 
;------------------------------------------------------------
	G$read_value_req$0$0 ==.
	C$fb_app_counter.c$339$1$1 ==.
;	..\fb_app_counter.c:339: void read_value_req(void)
;	-----------------------------------------
;	 function read_value_req
;	-----------------------------------------
_read_value_req:
	C$fb_app_counter.c$343$1$1 ==.
;	..\fb_app_counter.c:343: objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
	mov	dpl,(_telegramm + 0x0003)
	push	(_telegramm + 0x0004)
	lcall	_find_first_objno
	mov	r7,dpl
	dec	sp
	C$fb_app_counter.c$344$1$1 ==.
;	..\fb_app_counter.c:344: if(objno!=0xFF) {	// falls Gruppenadresse nicht gefunden
	cjne	r7,#0xFF,00109$
	sjmp	00105$
00109$:
	C$fb_app_counter.c$350$2$2 ==.
;	..\fb_app_counter.c:350: objflags=read_objflags(objno);		// Objekt Flags lesen
	mov	dpl,r7
	push	ar7
	lcall	_read_objflags
	mov	r6,dpl
	pop	ar7
	C$fb_app_counter.c$352$2$2 ==.
;	..\fb_app_counter.c:352: if((objflags&0x0C)==0x0C) send_obj_value(objno+0x40);// 0x40 ist bit für response Telegramm
	anl	ar6,#0x0C
	cjne	r6,#0x0C,00105$
	mov	a,#0x40
	add	a,r7
	mov	dpl,a
	lcall	_send_obj_value
00105$:
	C$fb_app_counter.c$354$1$1 ==.
	XG$read_value_req$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'sendbychange'
;------------------------------------------------------------
;val                       Allocated to stack - _bp -3
;objno                     Allocated to registers r7 
;------------------------------------------------------------
	G$sendbychange$0$0 ==.
	C$fb_app_counter.c$357$1$1 ==.
;	..\fb_app_counter.c:357: void sendbychange(unsigned char objno,unsigned char val){
;	-----------------------------------------
;	 function sendbychange
;	-----------------------------------------
_sendbychange:
	push	_bp
	mov	_bp,sp
	mov	r7,dpl
	C$fb_app_counter.c$358$1$1 ==.
;	..\fb_app_counter.c:358: if (val){
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	a,@r0
	jz	00106$
	C$fb_app_counter.c$359$2$2 ==.
;	..\fb_app_counter.c:359: if(read_obj_value(objno)==0)write_send(objno,1);
	mov	dpl,r7
	push	ar7
	lcall	_read_obj_value
	mov	r3,dpl
	mov	r4,dph
	mov	r5,b
	mov	r6,a
	pop	ar7
	mov	a,r3
	orl	a,r4
	orl	a,r5
	orl	a,r6
	jnz	00108$
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	dpl,r7
	lcall	_write_send
	dec	sp
	dec	sp
	sjmp	00108$
00106$:
	C$fb_app_counter.c$361$1$1 ==.
;	..\fb_app_counter.c:361: else if( read_obj_value(objno))write_send(objno,0);
	mov	dpl,r7
	push	ar7
	lcall	_read_obj_value
	mov	r3,dpl
	mov	r4,dph
	mov	r5,b
	mov	r6,a
	pop	ar7
	mov	a,r3
	orl	a,r4
	orl	a,r5
	orl	a,r6
	jz	00108$
	clr	a
	push	acc
	push	acc
	mov	dpl,r7
	lcall	_write_send
	dec	sp
	dec	sp
00108$:
	pop	_bp
	C$fb_app_counter.c$362$1$1 ==.
	XG$sendbychange$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'write_send'
;------------------------------------------------------------
;value                     Allocated to stack - _bp -4
;objno                     Allocated to registers r7 
;------------------------------------------------------------
	G$write_send$0$0 ==.
	C$fb_app_counter.c$364$1$1 ==.
;	..\fb_app_counter.c:364: void write_send(unsigned char objno,unsigned int value){
;	-----------------------------------------
;	 function write_send
;	-----------------------------------------
_write_send:
	push	_bp
	mov	_bp,sp
	mov	r7,dpl
	C$fb_app_counter.c$366$1$1 ==.
;	..\fb_app_counter.c:366: write_obj_value(objno,(unsigned long)value);
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	mov	r5,#0x00
	mov	r6,#0x00
	push	ar7
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	mov	dpl,r7
	lcall	_write_obj_value
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar7
	C$fb_app_counter.c$367$1$1 ==.
;	..\fb_app_counter.c:367: send_obj_value(objno);
	mov	dpl,r7
	lcall	_send_obj_value
	pop	_bp
	C$fb_app_counter.c$368$1$1 ==.
	XG$write_send$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'bus_return'
;------------------------------------------------------------
	G$bus_return$0$0 ==.
	C$fb_app_counter.c$371$1$1 ==.
;	..\fb_app_counter.c:371: void bus_return(void){
;	-----------------------------------------
;	 function bus_return
;	-----------------------------------------
_bus_return:
	C$fb_app_counter.c$377$1$1 ==.
;	..\fb_app_counter.c:377: }
	C$fb_app_counter.c$377$1$1 ==.
	XG$bus_return$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_obj_value'
;------------------------------------------------------------
;objno                     Allocated to registers r7 
;objvalue                  Allocated to stack - _bp +1
;objtype                   Allocated to registers 
;ctrno                     Allocated to registers r6 
;para                      Allocated to stack - _bp +5
;calc_para_ptr             Allocated to registers r3 
;tmp16                     Allocated to registers r7 r5 
;sloc0                     Allocated to stack - _bp +12
;sloc1                     Allocated to stack - _bp +13
;sloc2                     Allocated to stack - _bp +6
;sloc3                     Allocated to stack - _bp +10
;------------------------------------------------------------
	G$read_obj_value$0$0 ==.
	C$fb_app_counter.c$380$1$1 ==.
;	..\fb_app_counter.c:380: unsigned long read_obj_value(unsigned char objno)
;	-----------------------------------------
;	 function read_obj_value
;	-----------------------------------------
_read_obj_value:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x0D
	mov	sp,a
	mov	r7,dpl
	C$fb_app_counter.c$382$1$1 ==.
;	..\fb_app_counter.c:382: unsigned long objvalue=0;
	mov	r0,_bp
	inc	r0
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fb_app_counter.c$383$1$1 ==.
;	..\fb_app_counter.c:383: unsigned char objtype,ctrno=0,para=0xD5;
	mov	r6,#0x00
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,#0xD5
	C$fb_app_counter.c$384$1$1 ==.
;	..\fb_app_counter.c:384: unsigned char calc_para_ptr=0;
	mov	r3,#0x00
	C$fb_app_counter.c$386$1$1 ==.
;	..\fb_app_counter.c:386: objtype=eeprom[eeprom[COMMSTABPTR]+objno*3+4];
	mov	dptr,#(_eeprom + 0x0012)
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	mov	a,r7
	mov	b,#0x03
	mul	ab
	add	a,r5
	add	a,#0x04
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	C$fb_app_counter.c$387$1$1 ==.
;	..\fb_app_counter.c:387: if (objno >=2 && objno <= 10){
	cjne	r7,#0x02,00165$
00165$:
	jc	00102$
	mov	a,r7
	add	a,#0xff - 0x0A
	jc	00102$
	C$fb_app_counter.c$388$2$2 ==.
;	..\fb_app_counter.c:388: objvalue = ((bitobj_z1 >>(objno-2)) & 0x01);
	mov	ar4,r7
	mov	r5,#0x00
	mov	a,r4
	add	a,#0xFE
	mov	r4,a
	mov	a,r5
	addc	a,#0xFF
	mov	b,r4
	inc	b
	mov	r4,_bitobj_z1
	mov	r5,(_bitobj_z1 + 1)
	sjmp	00169$
00168$:
	clr	c
	mov	a,r5
	rrc	a
	mov	r5,a
	mov	a,r4
	rrc	a
	mov	r4,a
00169$:
	djnz	b,00168$
	anl	ar4,#0x01
	mov	r5,#0x00
	mov	r0,_bp
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	C$fb_app_counter.c$389$2$2 ==.
;	..\fb_app_counter.c:389: ctrno=1;
	mov	r6,#0x01
00102$:
	C$fb_app_counter.c$391$1$1 ==.
;	..\fb_app_counter.c:391: if (objno >=15 && objno <= 23){
	cjne	r7,#0x0F,00170$
00170$:
	jc	00105$
	mov	a,r7
	add	a,#0xff - 0x17
	jc	00105$
	C$fb_app_counter.c$392$2$3 ==.
;	..\fb_app_counter.c:392: objvalue = ((bitobj_z2 >>(objno-15)) & 0x01);
	mov	ar4,r7
	mov	r5,#0x00
	mov	a,r4
	add	a,#0xF1
	mov	r4,a
	mov	a,r5
	addc	a,#0xFF
	mov	b,r4
	inc	b
	mov	r4,_bitobj_z2
	mov	r5,(_bitobj_z2 + 1)
	sjmp	00174$
00173$:
	clr	c
	mov	a,r5
	rrc	a
	mov	r5,a
	mov	a,r4
	rrc	a
	mov	r4,a
00174$:
	djnz	b,00173$
	anl	ar4,#0x01
	mov	r5,#0x00
	mov	r0,_bp
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	C$fb_app_counter.c$393$2$3 ==.
;	..\fb_app_counter.c:393: ctrno=1;
	mov	r6,#0x01
00105$:
	C$fb_app_counter.c$395$1$1 ==.
;	..\fb_app_counter.c:395: if(!ctrno){
	mov	a,r6
	jz	00175$
	ljmp	00140$
00175$:
	C$fb_app_counter.c$396$2$4 ==.
;	..\fb_app_counter.c:396: if (objno <= 1){
	mov	a,r7
	add	a,#0xff - 0x01
	jc	00108$
	C$fb_app_counter.c$397$3$5 ==.
;	..\fb_app_counter.c:397: ctrno=objno;//objvalue = counter_moment[objno]; Z1
	mov	ar6,r7
	C$fb_app_counter.c$398$3$5 ==.
;	..\fb_app_counter.c:398: para=eeprom[0xD5]&0x0F;
	mov	dptr,#(_eeprom + 0x00d5)
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,#0x0F
	anl	a,r5
	mov	@r0,a
	C$fb_app_counter.c$399$3$5 ==.
;	..\fb_app_counter.c:399: calc_para_ptr=0xE2;
	mov	r3,#0xE2
00108$:
	C$fb_app_counter.c$401$2$4 ==.
;	..\fb_app_counter.c:401: if (objno>=11 && objno<=12){
	cjne	r7,#0x0B,00177$
00177$:
	jc	00110$
	mov	a,r7
	add	a,#0xff - 0x0C
	jc	00110$
	C$fb_app_counter.c$402$3$6 ==.
;	..\fb_app_counter.c:402: ctrno=objno-7;//objvalue = counter_summe[objno-11]; Z1
	mov	a,r7
	add	a,#0xF9
	mov	r6,a
	C$fb_app_counter.c$403$3$6 ==.
;	..\fb_app_counter.c:403: para=eeprom[0xD5]>>4;
	mov	dptr,#(_eeprom + 0x00d5)
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,r5
	swap	a
	anl	a,#0x0F
	mov	@r0,a
	C$fb_app_counter.c$404$3$6 ==.
;	..\fb_app_counter.c:404: calc_para_ptr=0xE4;
	mov	r3,#0xE4
00110$:
	C$fb_app_counter.c$406$2$4 ==.
;	..\fb_app_counter.c:406: if (objno >= 13 && objno<=14){
	cjne	r7,#0x0D,00180$
00180$:
	jc	00113$
	mov	a,r7
	add	a,#0xff - 0x0E
	jc	00113$
	C$fb_app_counter.c$407$3$7 ==.
;	..\fb_app_counter.c:407: ctrno=objno-11;//objvalue = counter_moment[objno-11]; Z2
	mov	a,r7
	add	a,#0xF5
	mov	r6,a
	C$fb_app_counter.c$408$3$7 ==.
;	..\fb_app_counter.c:408: para=eeprom[0xEB]&0x0F;
	mov	dptr,#(_eeprom + 0x00eb)
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,#0x0F
	anl	a,r5
	mov	@r0,a
	C$fb_app_counter.c$409$3$7 ==.
;	..\fb_app_counter.c:409: calc_para_ptr=0xF8;
	mov	r3,#0xF8
00113$:
	C$fb_app_counter.c$411$2$4 ==.
;	..\fb_app_counter.c:411: if (objno>=24 && objno<=25){
	cjne	r7,#0x18,00183$
00183$:
	jc	00116$
	mov	a,r7
	add	a,#0xff - 0x19
	jc	00116$
	C$fb_app_counter.c$412$3$8 ==.
;	..\fb_app_counter.c:412: ctrno=objno-18;//objvalue = counter_summe[objno-22]; Z2
	mov	a,r7
	add	a,#0xEE
	mov	r6,a
	C$fb_app_counter.c$413$3$8 ==.
;	..\fb_app_counter.c:413: para=eeprom[0xEB]>>4;
	mov	dptr,#(_eeprom + 0x00eb)
	clr	a
	movc	a,@a+dptr
	mov	r7,a
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,r7
	swap	a
	anl	a,#0x0F
	mov	@r0,a
	C$fb_app_counter.c$414$3$8 ==.
;	..\fb_app_counter.c:414: calc_para_ptr=0xFA;
	mov	r3,#0xFA
00116$:
	C$fb_app_counter.c$416$2$4 ==.
;	..\fb_app_counter.c:416: if(ctrno<=3){// momentanzähler
	mov	a,r6
	add	a,#0xff - 0x03
	jnc	00186$
	ljmp	00137$
00186$:
	C$fb_app_counter.c$417$3$9 ==.
;	..\fb_app_counter.c:417: tmp16=(unsigned int)((eeprom[calc_para_ptr]<<8)+eeprom[calc_para_ptr+1]);
	mov	dpl,r3
	mov	dph,#(_eeprom >> 8)
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	mov	r7,#0x00
	mov	a,r3
	inc	a
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r4,a
	mov	r3,#0x00
	add	a,r7
	mov	r7,a
	mov	a,r3
	addc	a,r5
	C$fb_app_counter.c$418$3$9 ==.
;	..\fb_app_counter.c:418: if(tmp16!=0){
	mov	r5,a
	orl	a,r7
	jnz	00187$
	ljmp	00140$
00187$:
	C$fb_app_counter.c$419$1$1 ==.
;	..\fb_app_counter.c:419: objvalue=counter_moment[ctrno];//
	push	ar7
	push	ar5
	mov	a,r6
	add	a,r6
	mov	r4,a
	add	a,#_counter_moment
	mov	r1,a
	mov	ar3,@r1
	inc	r1
	mov	ar7,@r1
	mov	r0,_bp
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar7
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	C$fb_app_counter.c$420$4$10 ==.
;	..\fb_app_counter.c:420: if(para==4&&counter_moment[ctrno]>120)objvalue=((unsigned int)(counter_moment[ctrno]+67));//für 3,33 sec. signed für Windmesser Eltako misbraucht
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	cjne	@r0,#0x04,00188$
	sjmp	00189$
00188$:
	pop	ar5
	pop	ar7
	sjmp	00119$
00189$:
	mov	a,r4
	add	a,#_counter_moment
	mov	r1,a
	mov	ar3,@r1
	inc	r1
	mov	ar7,@r1
	clr	c
	mov	a,#0x78
	subb	a,r3
	clr	a
	subb	a,r7
	pop	ar5
	pop	ar7
	jnc	00119$
	push	ar7
	push	ar5
	mov	a,r4
	add	a,#_counter_moment
	mov	r1,a
	mov	ar3,@r1
	inc	r1
	mov	ar7,@r1
	mov	a,#0x43
	add	a,r3
	mov	r3,a
	clr	a
	addc	a,r7
	mov	r7,a
	mov	r0,_bp
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar7
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	C$fb_app_counter.c$470$1$1 ==.
;	..\fb_app_counter.c:470: return(objvalue);
	pop	ar5
	pop	ar7
	C$fb_app_counter.c$420$4$10 ==.
;	..\fb_app_counter.c:420: if(para==4&&counter_moment[ctrno]>120)objvalue=((unsigned int)(counter_moment[ctrno]+67));//für 3,33 sec. signed für Windmesser Eltako misbraucht
00119$:
	C$fb_app_counter.c$422$4$10 ==.
;	..\fb_app_counter.c:422: if(para==8){//byte 0-100%
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	cjne	@r0,#0x08,00125$
	C$fb_app_counter.c$423$1$1 ==.
;	..\fb_app_counter.c:423: if(counter_moment[ctrno]<= tmp16){
	mov	a,r4
	add	a,#_counter_moment
	mov	r1,a
	mov	ar2,@r1
	inc	r1
	mov	ar3,@r1
	clr	c
	mov	a,r7
	subb	a,r2
	mov	a,r5
	subb	a,r3
	jc	00122$
	C$fb_app_counter.c$424$1$1 ==.
;	..\fb_app_counter.c:424: objvalue = 256*(unsigned long)counter_moment[ctrno];
	push	ar7
	push	ar5
	mov	a,r4
	add	a,#_counter_moment
	mov	r1,a
	mov	ar3,@r1
	inc	r1
	mov	ar7,@r1
	mov	ar2,r7
	mov	r5,#0x00
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	inc	r0
	mov	@r0,ar5
	dec	r0
	mov	@r0,ar2
	dec	r0
	mov	@r0,ar3
	dec	r0
	mov	@r0,#0x00
	C$fb_app_counter.c$425$6$12 ==.
;	..\fb_app_counter.c:425: objvalue-=counter_moment[ctrno];
	mov	a,r4
	add	a,#_counter_moment
	mov	r1,a
	mov	ar5,@r1
	inc	r1
	mov	ar7,@r1
	mov	r3,#0x00
	mov	r2,#0x00
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	clr	c
	subb	a,r5
	mov	@r0,a
	inc	r0
	mov	a,@r0
	subb	a,r7
	mov	@r0,a
	inc	r0
	mov	a,@r0
	subb	a,r3
	mov	@r0,a
	inc	r0
	mov	a,@r0
	subb	a,r2
	mov	@r0,a
	pop	ar5
	pop	ar7
	sjmp	00125$
00122$:
	C$fb_app_counter.c$428$6$13 ==.
;	..\fb_app_counter.c:428: objvalue=255;
	mov	r0,_bp
	inc	r0
	mov	@r0,#0xFF
	clr	a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fb_app_counter.c$429$6$13 ==.
;	..\fb_app_counter.c:429: tmp16=1;
	mov	r7,#0x01
	mov	r5,#0x00
00125$:
	C$fb_app_counter.c$432$4$10 ==.
;	..\fb_app_counter.c:432: if(para==9)objvalue = 100*(unsigned long)counter_moment[ctrno];//byte 0-255%
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	cjne	@r0,#0x09,00127$
	push	ar7
	push	ar5
	mov	a,r4
	add	a,#_counter_moment
	mov	r1,a
	mov	ar3,@r1
	inc	r1
	mov	ar4,@r1
	mov	ar2,r4
	mov	r4,#0x00
	mov	r7,#0x00
	push	ar3
	push	ar2
	push	ar4
	push	ar7
	mov	dptr,#(0x64&0x00ff)
	clr	a
	mov	b,a
	lcall	__mullong
	mov	r3,dpl
	mov	r4,dph
	mov	r5,b
	mov	r7,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	r0,_bp
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar7
	C$fb_app_counter.c$470$1$1 ==.
;	..\fb_app_counter.c:470: return(objvalue);
	pop	ar5
	pop	ar7
	C$fb_app_counter.c$432$4$10 ==.
;	..\fb_app_counter.c:432: if(para==9)objvalue = 100*(unsigned long)counter_moment[ctrno];//byte 0-255%
00127$:
	C$fb_app_counter.c$433$4$10 ==.
;	..\fb_app_counter.c:433: objvalue /=tmp16;
	mov	r4,#0x00
	mov	r3,#0x00
	push	ar7
	push	ar5
	push	ar4
	push	ar3
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	__divulong
	mov	r3,dpl
	mov	r4,dph
	mov	r5,b
	mov	r7,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	r0,_bp
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar7
	C$fb_app_counter.c$434$4$10 ==.
;	..\fb_app_counter.c:434: if(para==5)objvalue=eis5conversion(objvalue);//EIS5
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	cjne	@r0,#0x05,00196$
	sjmp	00197$
00196$:
	ljmp	00140$
00197$:
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	_eis5conversion
	mov	r5,dpl
	mov	r7,dph
	mov	r0,_bp
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar7
	mov	a,r7
	rlc	a
	subb	a,acc
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	ljmp	00140$
00137$:
	C$fb_app_counter.c$458$3$14 ==.
;	..\fb_app_counter.c:458: objvalue=counter_summe[ctrno-4]/(unsigned int)(eeprom[calc_para_ptr+3] | (eeprom[calc_para_ptr+2] << 8)) |((unsigned long)(eeprom[calc_para_ptr+1] | (eeprom[calc_para_ptr] << 8)) << 16);
	mov	a,r6
	add	a,#0xFC
	add	a,acc
	add	a,acc
	add	a,#_counter_summe
	mov	r1,a
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,@r1
	mov	@r0,a
	inc	r1
	mov	a,@r1
	inc	r0
	mov	@r0,a
	inc	r1
	mov	a,@r1
	inc	r0
	mov	@r0,a
	inc	r1
	mov	a,@r1
	inc	r0
	mov	@r0,a
	mov	a,#0x03
	add	a,r3
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r7,a
	mov	a,#0x02
	add	a,r3
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r4,a
	mov	r5,#0x00
	mov	ar2,r7
	mov	r6,#0x00
	mov	a,r5
	orl	ar2,a
	mov	a,r4
	orl	ar6,a
	mov	ar5,r6
	mov	r6,#0x00
	mov	r7,#0x00
	push	ar3
	push	ar2
	push	ar5
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	__divulong
	xch	a,r0
	mov	a,_bp
	add	a,#0x0a
	xch	a,r0
	mov	@r0,dpl
	inc	r0
	mov	@r0,dph
	inc	r0
	mov	@r0,b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar3
	mov	a,r3
	inc	a
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r7,a
	mov	dpl,r3
	mov	dph,#(_eeprom >> 8)
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	mov	r6,#0x00
	mov	ar2,r7
	mov	r3,#0x00
	mov	a,r6
	orl	ar2,a
	mov	a,r5
	orl	ar3,a
	mov	a,r3
	rlc	a
	subb	a,acc
	mov	ar7,r3
	mov	ar6,r2
	clr	a
	mov	r3,a
	mov	r2,a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	a,@r0
	orl	ar2,a
	inc	r0
	mov	a,@r0
	orl	ar3,a
	inc	r0
	mov	a,@r0
	orl	ar6,a
	inc	r0
	mov	a,@r0
	orl	ar7,a
	mov	r0,_bp
	inc	r0
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar6
	inc	r0
	mov	@r0,ar7
	C$fb_app_counter.c$459$3$14 ==.
;	..\fb_app_counter.c:459: switch(para){
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	cjne	@r0,#0x02,00198$
	sjmp	00132$
00198$:
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	C$fb_app_counter.c$460$4$15 ==.
;	..\fb_app_counter.c:460: case 2:
	cjne	@r0,#0x05,00140$
	sjmp	00133$
00132$:
	C$fb_app_counter.c$461$4$15 ==.
;	..\fb_app_counter.c:461: objvalue=0;
	mov	r0,_bp
	inc	r0
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fb_app_counter.c$462$4$15 ==.
;	..\fb_app_counter.c:462: break;
	C$fb_app_counter.c$463$4$15 ==.
;	..\fb_app_counter.c:463: case 5:
	sjmp	00140$
00133$:
	C$fb_app_counter.c$464$4$15 ==.
;	..\fb_app_counter.c:464: objvalue=eis5conversion(objvalue);
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	_eis5conversion
	mov	r6,dpl
	mov	r7,dph
	mov	r0,_bp
	inc	r0
	mov	@r0,ar6
	inc	r0
	mov	@r0,ar7
	mov	a,r7
	rlc	a
	subb	a,acc
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fb_app_counter.c$467$1$1 ==.
;	..\fb_app_counter.c:467: }
00140$:
	C$fb_app_counter.c$470$1$1 ==.
;	..\fb_app_counter.c:470: return(objvalue);
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	mov	sp,_bp
	pop	_bp
	C$fb_app_counter.c$471$1$1 ==.
	XG$read_obj_value$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'write_obj_value'
;------------------------------------------------------------
;objvalue                  Allocated to stack - _bp -6
;objno                     Allocated to registers r7 
;objtype                   Allocated to registers 
;sloc0                     Allocated to stack - _bp +1
;------------------------------------------------------------
	G$write_obj_value$0$0 ==.
	C$fb_app_counter.c$475$1$1 ==.
;	..\fb_app_counter.c:475: void write_obj_value(unsigned char objno,unsigned long objvalue)
;	-----------------------------------------
;	 function write_obj_value
;	-----------------------------------------
_write_obj_value:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x04
	mov	sp,a
	mov	r7,dpl
	C$fb_app_counter.c$479$1$1 ==.
;	..\fb_app_counter.c:479: objtype=eeprom[eeprom[COMMSTABPTR]+objno*3+4];
	mov	dptr,#(_eeprom + 0x0012)
	clr	a
	movc	a,@a+dptr
	mov	r6,a
	mov	a,r7
	mov	b,#0x03
	mul	ab
	add	a,r6
	add	a,#0x04
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	C$fb_app_counter.c$481$1$1 ==.
;	..\fb_app_counter.c:481: if (objno <= 1)counter_moment[objno]=objvalue;
	mov	a,r7
	add	a,#0xff - 0x01
	jc	00102$
	mov	a,r7
	add	a,r7
	add	a,#_counter_moment
	mov	r1,a
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	mov	@r1,ar5
	inc	r1
	mov	@r1,ar6
00102$:
	C$fb_app_counter.c$482$1$1 ==.
;	..\fb_app_counter.c:482: if (objno >=2 && objno <= 10)
	cjne	r7,#0x02,00132$
00132$:
	jnc	00133$
	ljmp	00104$
00133$:
	mov	a,r7
	add	a,#0xff - 0x0A
	jnc	00134$
	ljmp	00104$
00134$:
	C$fb_app_counter.c$484$2$2 ==.
;	..\fb_app_counter.c:484: bitobj_z1 &= ~(0x01<<(objno-2));
	mov	ar5,r7
	mov	r6,#0x00
	mov	a,r5
	add	a,#0xFE
	mov	r5,a
	mov	a,r6
	addc	a,#0xFF
	mov	r6,a
	mov	b,r5
	inc	b
	mov	r3,#0x01
	mov	r4,#0x00
	sjmp	00136$
00135$:
	mov	a,r3
	add	a,r3
	mov	r3,a
	mov	a,r4
	rlc	a
	mov	r4,a
00136$:
	djnz	b,00135$
	mov	a,r3
	cpl	a
	mov	r3,a
	mov	a,r4
	cpl	a
	mov	r4,a
	mov	a,r3
	anl	_bitobj_z1,a
	mov	a,r4
	anl	(_bitobj_z1 + 1),a
	C$fb_app_counter.c$485$1$1 ==.
;	..\fb_app_counter.c:485: bitobj_z1 |= ((objvalue&0x01)<<(objno-2));
	push	ar7
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,#0x01
	anl	a,@r0
	mov	r2,a
	mov	r3,#0x00
	mov	r4,#0x00
	mov	r7,#0x00
	mov	b,r5
	inc	b
	mov	r0,_bp
	inc	r0
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar7
	dec	r0
	dec	r0
	dec	r0
	sjmp	00138$
00137$:
	mov	a,@r0
	add	a,acc
	mov	@r0,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	@r0,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	@r0,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	@r0,a
	dec	r0
	dec	r0
	dec	r0
00138$:
	djnz	b,00137$
	mov	r4,_bitobj_z1
	mov	r5,(_bitobj_z1 + 1)
	mov	r6,#0x00
	mov	r7,#0x00
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	orl	ar4,a
	inc	r0
	mov	a,@r0
	orl	ar5,a
	inc	r0
	mov	a,@r0
	orl	ar6,a
	inc	r0
	mov	a,@r0
	orl	ar7,a
	mov	_bitobj_z1,r4
	mov	(_bitobj_z1 + 1),r5
	C$fb_app_counter.c$494$1$1 ==.
;	..\fb_app_counter.c:494: if (objno>=24 && objno<=25)counter_summe[objno-22]=objvalue;
	pop	ar7
	C$fb_app_counter.c$485$1$1 ==.
;	..\fb_app_counter.c:485: bitobj_z1 |= ((objvalue&0x01)<<(objno-2));
00104$:
	C$fb_app_counter.c$487$1$1 ==.
;	..\fb_app_counter.c:487: if (objno>=11 && objno<=12)counter_summe[objno-11]=objvalue;
	cjne	r7,#0x0B,00139$
00139$:
	jc	00107$
	mov	a,r7
	add	a,#0xff - 0x0C
	jc	00107$
	mov	a,r7
	add	a,#0xF5
	add	a,acc
	add	a,acc
	mov	r6,a
	add	a,#_counter_summe
	mov	r0,a
	mov	a,_bp
	add	a,#0xfa
	mov	r1,a
	mov	a,@r1
	mov	@r0,a
	inc	r0
	inc	r1
	mov	a,@r1
	mov	@r0,a
	inc	r0
	inc	r1
	mov	a,@r1
	mov	@r0,a
	inc	r0
	inc	r1
	mov	a,@r1
	mov	@r0,a
00107$:
	C$fb_app_counter.c$488$1$1 ==.
;	..\fb_app_counter.c:488: if (objno >= 13 && objno<=14)counter_moment[objno-11]=objvalue;
	cjne	r7,#0x0D,00142$
00142$:
	jc	00110$
	mov	a,r7
	add	a,#0xff - 0x0E
	jc	00110$
	mov	a,r7
	add	a,#0xF5
	add	a,acc
	add	a,#_counter_moment
	mov	r1,a
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	mov	@r1,ar5
	inc	r1
	mov	@r1,ar6
00110$:
	C$fb_app_counter.c$489$1$1 ==.
;	..\fb_app_counter.c:489: if (objno >=15 && objno <= 23)
	cjne	r7,#0x0F,00145$
00145$:
	jnc	00146$
	ljmp	00113$
00146$:
	mov	a,r7
	add	a,#0xff - 0x17
	jnc	00147$
	ljmp	00113$
00147$:
	C$fb_app_counter.c$491$2$3 ==.
;	..\fb_app_counter.c:491: bitobj_z2 &= ~(0x01<<(objno-15));
	mov	ar5,r7
	mov	r6,#0x00
	mov	a,r5
	add	a,#0xF1
	mov	r5,a
	mov	a,r6
	addc	a,#0xFF
	mov	r6,a
	mov	b,r5
	inc	b
	mov	r3,#0x01
	mov	r4,#0x00
	sjmp	00149$
00148$:
	mov	a,r3
	add	a,r3
	mov	r3,a
	mov	a,r4
	rlc	a
	mov	r4,a
00149$:
	djnz	b,00148$
	mov	a,r3
	cpl	a
	mov	r3,a
	mov	a,r4
	cpl	a
	mov	r4,a
	mov	a,r3
	anl	_bitobj_z2,a
	mov	a,r4
	anl	(_bitobj_z2 + 1),a
	C$fb_app_counter.c$492$1$1 ==.
;	..\fb_app_counter.c:492: bitobj_z2 |= ((objvalue&0x01)<<(objno-15));
	push	ar7
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,#0x01
	anl	a,@r0
	mov	r2,a
	mov	r3,#0x00
	mov	r4,#0x00
	mov	r7,#0x00
	mov	b,r5
	inc	b
	mov	r0,_bp
	inc	r0
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar7
	dec	r0
	dec	r0
	dec	r0
	sjmp	00151$
00150$:
	mov	a,@r0
	add	a,acc
	mov	@r0,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	@r0,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	@r0,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	@r0,a
	dec	r0
	dec	r0
	dec	r0
00151$:
	djnz	b,00150$
	mov	r4,_bitobj_z2
	mov	r5,(_bitobj_z2 + 1)
	mov	r6,#0x00
	mov	r7,#0x00
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	orl	ar4,a
	inc	r0
	mov	a,@r0
	orl	ar5,a
	inc	r0
	mov	a,@r0
	orl	ar6,a
	inc	r0
	mov	a,@r0
	orl	ar7,a
	mov	_bitobj_z2,r4
	mov	(_bitobj_z2 + 1),r5
	C$fb_app_counter.c$494$1$1 ==.
;	..\fb_app_counter.c:494: if (objno>=24 && objno<=25)counter_summe[objno-22]=objvalue;
	pop	ar7
	C$fb_app_counter.c$492$1$1 ==.
;	..\fb_app_counter.c:492: bitobj_z2 |= ((objvalue&0x01)<<(objno-15));
00113$:
	C$fb_app_counter.c$494$1$1 ==.
;	..\fb_app_counter.c:494: if (objno>=24 && objno<=25)counter_summe[objno-22]=objvalue;
	cjne	r7,#0x18,00152$
00152$:
	jc	00118$
	mov	a,r7
	add	a,#0xff - 0x19
	jc	00118$
	mov	a,r7
	add	a,#0xEA
	add	a,acc
	add	a,acc
	mov	r7,a
	add	a,#_counter_summe
	mov	r0,a
	mov	a,_bp
	add	a,#0xfa
	mov	r1,a
	mov	a,@r1
	mov	@r0,a
	inc	r0
	inc	r1
	mov	a,@r1
	mov	@r0,a
	inc	r0
	inc	r1
	mov	a,@r1
	mov	@r0,a
	inc	r0
	inc	r1
	mov	a,@r1
	mov	@r0,a
00118$:
	mov	sp,_bp
	pop	_bp
	C$fb_app_counter.c$497$1$1 ==.
	XG$write_obj_value$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'keypad_init'
;------------------------------------------------------------
	G$keypad_init$0$0 ==.
	C$fb_app_counter.c$499$1$1 ==.
;	..\fb_app_counter.c:499: void keypad_init  (void)// Eingänge 0,2 Zähler. Eingänge 1,3 Tarifumschaltung
;	-----------------------------------------
;	 function keypad_init
;	-----------------------------------------
_keypad_init:
	C$fb_app_counter.c$502$1$1 ==.
;	..\fb_app_counter.c:502: KBPATN = 0x00;
	mov	_KBPATN,#0x00
	C$fb_app_counter.c$504$1$1 ==.
;	..\fb_app_counter.c:504: KBMASK = 0x05;
	mov	_KBMASK,#0x05
	C$fb_app_counter.c$506$1$1 ==.
;	..\fb_app_counter.c:506: KBCON = 0x00;
	mov	_KBCON,#0x00
	C$fb_app_counter.c$509$1$1 ==.
;	..\fb_app_counter.c:509: IP1 &= 0xFD;
	anl	_IP1,#0xFD
	C$fb_app_counter.c$510$1$1 ==.
;	..\fb_app_counter.c:510: IP1H &= 0xFD;
	anl	_IP1H,#0xFD
	C$fb_app_counter.c$513$1$1 ==.
;	..\fb_app_counter.c:513: EKBI = 1;
	setb	_IEN1_1
	C$fb_app_counter.c$514$1$1 ==.
	XG$keypad_init$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'restart_app'
;------------------------------------------------------------
;objno                     Allocated to registers r7 
;------------------------------------------------------------
	G$restart_app$0$0 ==.
	C$fb_app_counter.c$517$1$1 ==.
;	..\fb_app_counter.c:517: void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
;	-----------------------------------------
;	 function restart_app
;	-----------------------------------------
_restart_app:
	C$fb_app_counter.c$523$1$1 ==.
;	..\fb_app_counter.c:523: P0M1=0x0F;	//P0 auf input only (high impedance!)
	mov	_P0M1,#0x0F
	C$fb_app_counter.c$524$1$1 ==.
;	..\fb_app_counter.c:524: P0M2=0x00;
	mov	_P0M2,#0x00
	C$fb_app_counter.c$525$1$1 ==.
;	..\fb_app_counter.c:525: P0=0xFF;
	mov	_P0,#0xFF
	C$fb_app_counter.c$532$1$1 ==.
;	..\fb_app_counter.c:532: transparency=0;
	clr	_transparency
	C$fb_app_counter.c$534$1$1 ==.
;	..\fb_app_counter.c:534: RTCCON=0x60;		// RTC anhalten und Flag löschen
	mov	_RTCCON,#0x60
	C$fb_app_counter.c$535$1$1 ==.
;	..\fb_app_counter.c:535: RTCH=0x16;			//16 reload Real Time Clock
	mov	_RTCH,#0x16
	C$fb_app_counter.c$536$1$1 ==.
;	..\fb_app_counter.c:536: RTCL=0x80;			//80 auf 100ms
	mov	_RTCL,#0x80
	C$fb_app_counter.c$537$1$1 ==.
;	..\fb_app_counter.c:537: RTCCON=0x61;//	START_RTC	// RTC starten
	mov	_RTCCON,#0x61
	C$fb_app_counter.c$539$1$1 ==.
;	..\fb_app_counter.c:539: EA=0; 
	clr	_IEN0_7
	C$fb_app_counter.c$540$1$1 ==.
;	..\fb_app_counter.c:540: START_WRITECYCLE
	mov	_FMCON,#0x00
	C$fb_app_counter.c$541$1$1 ==.
;	..\fb_app_counter.c:541: WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x00B4 = VELUX
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x03
	mov	_FMDATA,#0x00
	C$fb_app_counter.c$542$1$1 ==.
;	..\fb_app_counter.c:542: WRITE_BYTE(0x01,0x04,0xB4)
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x04
	mov	_FMDATA,#0xB4
	C$fb_app_counter.c$543$1$1 ==.
;	..\fb_app_counter.c:543: WRITE_BYTE(0x01,0x05,0x04)	// Geräte Typ (2118) 04B0h
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x05
	mov	_FMDATA,#0x04
	C$fb_app_counter.c$544$1$1 ==.
;	..\fb_app_counter.c:544: WRITE_BYTE(0x01,0x06,0xB0)  // 	"	"	"
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x06
	mov	_FMDATA,#0xB0
	C$fb_app_counter.c$545$1$1 ==.
;	..\fb_app_counter.c:545: WRITE_BYTE(0x01,0x07,0x01)	// Versionsnummer
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x07
	mov	_FMDATA,#0x01
	C$fb_app_counter.c$546$1$1 ==.
;	..\fb_app_counter.c:546: WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x0C
	mov	_FMDATA,#0x00
	C$fb_app_counter.c$547$1$1 ==.
;	..\fb_app_counter.c:547: WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x0D
	mov	_FMDATA,#0xFF
	C$fb_app_counter.c$548$1$1 ==.
;	..\fb_app_counter.c:548: WRITE_BYTE(0x01,0x12,0x82)	// COMMSTAB Pointer
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x12
	mov	_FMDATA,#0x82
	C$fb_app_counter.c$549$1$1 ==.
;	..\fb_app_counter.c:549: STOP_WRITECYCLE
	mov	_FMCON,#0x68
	C$fb_app_counter.c$552$1$1 ==.
;	..\fb_app_counter.c:552: EA=1;
	setb	_IEN0_7
	C$fb_app_counter.c$554$2$2 ==.
;	..\fb_app_counter.c:554: for(objno=0;objno<4;objno++) {// zyclisch senden setzen
	mov	r7,#0x00
00101$:
	cjne	r7,#0x04,00110$
00110$:
	jnc	00105$
	C$fb_app_counter.c$555$2$2 ==.
;	..\fb_app_counter.c:555: timercnt[objno]=eeprom[paraindex_timer[objno]];//Torzeit bzw timer setzen
	mov	a,r7
	add	a,#_timercnt
	mov	r1,a
	mov	a,r7
	add	a,r7
	mov	r5,a
	mov	dptr,#_paraindex_timer
	movc	a,@a+dptr
	xch	a,r5
	inc	dptr
	movc	a,@a+dptr
	mov	r6,a
	mov	dpl,r5
	mov	a,#(_eeprom >> 8)
	add	a,r6
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	mov	r4,a
	mov	@r1,a
	C$fb_app_counter.c$556$2$2 ==.
;	..\fb_app_counter.c:556: timerbase[objno]=eeprom[paraindex_timer[objno]+1];// Basis setzen
	mov	a,r7
	add	a,#_timerbase
	mov	r1,a
	mov	a,r5
	inc	a
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r6,a
	mov	@r1,a
	C$fb_app_counter.c$554$1$1 ==.
;	..\fb_app_counter.c:554: for(objno=0;objno<4;objno++) {// zyclisch senden setzen
	inc	r7
	sjmp	00101$
00105$:
	C$fb_app_counter.c$559$1$1 ==.
	XG$restart_app$0$0 ==.
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
G$paraindex_timer$0$0 == .
_paraindex_timer:
	.byte #0xD6,#0x00	; 214
	.byte #0xD8,#0x00	; 216
	.byte #0xEC,#0x00	; 236
	.byte #0xEE,#0x00	; 238
G$objno_timer$0$0 == .
_objno_timer:
	.byte #0x00,#0x00	; 0
	.byte #0x0B,#0x00	; 11
	.byte #0x0D,#0x00	; 13
	.byte #0x18,#0x00	; 24
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
