;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
; This file was generated Sun Jun 23 16:20:03 2013
;--------------------------------------------------------
	.module fb_app_rollo11
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _svfaktorarray
	.globl _timerflagmask
	.globl _read_objflags
	.globl _send_obj_value
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
	.globl _handmode
	.globl _state
	.globl _portchanged
	.globl _ledport
	.globl _knr
	.globl _kanal
	.globl _oldblockvalue
	.globl _zfstate
	.globl _blocked
	.globl _oldportbuffer
	.globl _portbuffer
	.globl _objects_smove
	.globl _objects_move
	.globl _Tval
	.globl _delay_toggle
	.globl _timer
	.globl _timerstate
	.globl _timercnt
	.globl _timerbase
	.globl _RAM
	.globl _write_value_req
	.globl _read_value_req
	.globl _read_obj_value
	.globl _write_obj_value
	.globl _Sobject_schalten
	.globl _object_schalten
	.globl _delay_timer
	.globl _handsteuerung
	.globl _sobj_update
	.globl _set_pause
	.globl _set_entriegeln
	.globl _port_schalten
	.globl _bus_return
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
G$RAM$0$0 == 0x0000
_RAM	=	0x0000
G$timerbase$0$0 == 0x0010
_timerbase	=	0x0010
G$timercnt$0$0==.
_timercnt::
	.ds 16
G$timerstate$0$0==.
_timerstate::
	.ds 16
G$timer$0$0 == 0x0009
_timer	=	0x0009
G$delay_toggle$0$0 == 0x0009
_delay_toggle	=	0x0009
G$Tval$0$0==.
_Tval::
	.ds 1
G$objects_move$0$0 == 0x000b
_objects_move	=	0x000b
G$objects_smove$0$0 == 0x000c
_objects_smove	=	0x000c
G$portbuffer$0$0 == 0x000d
_portbuffer	=	0x000d
G$oldportbuffer$0$0 == 0x000e
_oldportbuffer	=	0x000e
G$blocked$0$0 == 0x000f
_blocked	=	0x000f
G$zfstate$0$0==.
_zfstate::
	.ds 1
G$oldblockvalue$0$0==.
_oldblockvalue::
	.ds 1
G$kanal$0$0==.
_kanal::
	.ds 4
G$knr$0$0==.
_knr::
	.ds 1
G$ledport$0$0==.
_ledport::
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
G$portchanged$0$0==.
_portchanged::
	.ds 1
G$state$0$0==.
_state::
	.ds 1
G$handmode$0$0==.
_handmode::
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
;Allocation info for local variables in function 'write_value_req'
;------------------------------------------------------------
;objno                     Allocated to registers r7 
;------------------------------------------------------------
	G$write_value_req$0$0 ==.
	C$fb_app_rollo11.c$73$0$0 ==.
;	..\fb_app_rollo11.c:73: void write_value_req(unsigned char objno) 				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
;	-----------------------------------------
;	 function write_value_req
;	-----------------------------------------
_write_value_req:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r7,dpl
	C$fb_app_rollo11.c$93$1$1 ==.
;	..\fb_app_rollo11.c:93: if (objno<8 && !handmode) object_schalten(objno,telegramm[7]&0x01);	// Objektnummer 0-4 entspricht den Kanälen 1-4
	cjne	r7,#0x08,00113$
00113$:
	jnc	00102$
	jb	_handmode,00102$
	mov	a,(_telegramm + 0x0007)
	anl	a,#0x01
	add	a,#0xff
	mov  b0,c
	mov	b[0],c
	push	ar7
	mov	bits,b
	mov	dpl,r7
	lcall	_object_schalten
	pop	ar7
00102$:
	C$fb_app_rollo11.c$95$1$1 ==.
;	..\fb_app_rollo11.c:95: if (objno>=16 && objno<=17)Sobject_schalten(objno,telegramm[7]&0x01);	// Objektnummer 16+17 entspricht den Sicherheitsfahrten 1 + 2
	cjne	r7,#0x10,00116$
00116$:
	jc	00107$
	mov	a,r7
	add	a,#0xff - 0x11
	jc	00107$
	mov	a,#0x01
	anl	a,(_telegramm + 0x0007)
	mov	r6,a
	push	ar6
	mov	dpl,r7
	lcall	_Sobject_schalten
	dec	sp
00107$:
	C$fb_app_rollo11.c$104$1$1 ==.
	XG$write_value_req$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_value_req'
;------------------------------------------------------------
;objno                     Allocated to registers r7 
;------------------------------------------------------------
	G$read_value_req$0$0 ==.
	C$fb_app_rollo11.c$221$1$1 ==.
;	..\fb_app_rollo11.c:221: void read_value_req(unsigned char objno)// Sendet nach Leseanfrage objektwert auf den BUS
;	-----------------------------------------
;	 function read_value_req
;	-----------------------------------------
_read_value_req:
	mov	r7,dpl
	C$fb_app_rollo11.c$223$1$1 ==.
;	..\fb_app_rollo11.c:223: send_obj_value(objno+64);
	mov	a,#0x40
	add	a,r7
	mov	dpl,a
	lcall	_send_obj_value
	C$fb_app_rollo11.c$237$1$1 ==.
	XG$read_value_req$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_obj_value'
;------------------------------------------------------------
;objno                     Allocated to registers r7 
;ret_val                   Allocated to registers r6 
;------------------------------------------------------------
	G$read_obj_value$0$0 ==.
	C$fb_app_rollo11.c$240$1$1 ==.
;	..\fb_app_rollo11.c:240: unsigned long read_obj_value(unsigned char objno) 	// gibt den Wert eines Objektes zurueck
;	-----------------------------------------
;	 function read_obj_value
;	-----------------------------------------
_read_obj_value:
	mov	r7,dpl
	C$fb_app_rollo11.c$242$1$1 ==.
;	..\fb_app_rollo11.c:242: unsigned char ret_val=0;
	mov	r6,#0x00
	C$fb_app_rollo11.c$244$1$1 ==.
;	..\fb_app_rollo11.c:244: if(objno<8) {
	cjne	r7,#0x08,00113$
00113$:
	jnc	00106$
	C$fb_app_rollo11.c$245$2$2 ==.
;	..\fb_app_rollo11.c:245: if(objects_move &(1<<objno)) ret_val=1;
	mov	b,r7
	inc	b
	mov	r4,#0x01
	mov	r5,#0x00
	sjmp	00116$
00115$:
	mov	a,r4
	add	a,r4
	mov	r4,a
	mov	a,r5
	rlc	a
	mov	r5,a
00116$:
	djnz	b,00115$
	mov	r2,_objects_move
	mov	r3,#0x00
	mov	a,r2
	anl	ar4,a
	mov	a,r3
	anl	ar5,a
	mov	a,r4
	orl	a,r5
	jz	00107$
	mov	r6,#0x01
	sjmp	00107$
00106$:
	C$fb_app_rollo11.c$248$2$3 ==.
;	..\fb_app_rollo11.c:248: if(objects_smove&(1<<(objno-16))) ret_val=1;
	mov	r5,#0x00
	mov	a,r7
	add	a,#0xF0
	mov	r7,a
	mov	a,r5
	addc	a,#0xFF
	mov	b,r7
	inc	b
	mov	r7,#0x01
	mov	r5,#0x00
	sjmp	00119$
00118$:
	mov	a,r7
	add	a,r7
	mov	r7,a
	mov	a,r5
	rlc	a
	mov	r5,a
00119$:
	djnz	b,00118$
	mov	r3,_objects_smove
	mov	r4,#0x00
	mov	a,r3
	anl	ar7,a
	mov	a,r4
	anl	ar5,a
	mov	a,r7
	orl	a,r5
	jz	00107$
	mov	r6,#0x01
00107$:
	C$fb_app_rollo11.c$250$1$1 ==.
;	..\fb_app_rollo11.c:250: return(ret_val);
	mov	r7,#0x00
	mov	r5,#0x00
	mov	r4,#0x00
	mov	dpl,r6
	mov	dph,r7
	mov	b,r5
	mov	a,r4
	C$fb_app_rollo11.c$251$1$1 ==.
	XG$read_obj_value$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'write_obj_value'
;------------------------------------------------------------
;objvalue                  Allocated to stack - _bp -4
;objno                     Allocated to registers r7 
;------------------------------------------------------------
	G$write_obj_value$0$0 ==.
	C$fb_app_rollo11.c$254$1$1 ==.
;	..\fb_app_rollo11.c:254: void write_obj_value(unsigned char objno,unsigned int objvalue)	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
;	-----------------------------------------
;	 function write_obj_value
;	-----------------------------------------
_write_obj_value:
	push	_bp
	mov	_bp,sp
	mov	r7,dpl
	C$fb_app_rollo11.c$256$1$1 ==.
;	..\fb_app_rollo11.c:256: if(objno<8) {// kurz und lanzeit
	cjne	r7,#0x08,00115$
00115$:
	jnc	00108$
	C$fb_app_rollo11.c$257$2$2 ==.
;	..\fb_app_rollo11.c:257: if(objvalue==0) objects_move &= 0xFF-(1<<objno);
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
	mov	b,r7
	inc	b
	mov	a,#0x01
	sjmp	00120$
00118$:
	add	a,acc
00120$:
	djnz	b,00118$
	mov	r6,a
	mov	a,#0xFF
	clr	c
	subb	a,r6
	anl	_objects_move,a
	sjmp	00110$
00102$:
	C$fb_app_rollo11.c$258$2$2 ==.
;	..\fb_app_rollo11.c:258: else objects_move |=1<<objno;
	mov	b,r7
	inc	b
	mov	a,#0x01
	sjmp	00123$
00121$:
	add	a,acc
00123$:
	djnz	b,00121$
	mov	r6,a
	orl	_objects_move,a
	sjmp	00110$
00108$:
	C$fb_app_rollo11.c$261$2$3 ==.
;	..\fb_app_rollo11.c:261: objno-=16;// sicherheitsfahrt 16+17
	mov	a,r7
	add	a,#0xF0
	mov	r7,a
	C$fb_app_rollo11.c$262$2$3 ==.
;	..\fb_app_rollo11.c:262: if(objvalue==0) objects_smove &= (0xFF-(1<<objno));
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00105$
	mov	b,r7
	inc	b
	mov	a,#0x01
	sjmp	00127$
00125$:
	add	a,acc
00127$:
	djnz	b,00125$
	mov	r6,a
	mov	a,#0xFF
	clr	c
	subb	a,r6
	anl	_objects_smove,a
	sjmp	00110$
00105$:
	C$fb_app_rollo11.c$263$2$3 ==.
;	..\fb_app_rollo11.c:263: else objects_smove |=1<<objno;
	mov	b,r7
	inc	b
	mov	a,#0x01
	sjmp	00130$
00128$:
	add	a,acc
00130$:
	djnz	b,00128$
	mov	r7,a
	orl	_objects_smove,a
00110$:
	pop	_bp
	C$fb_app_rollo11.c$265$1$1 ==.
	XG$write_obj_value$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Sobject_schalten'
;------------------------------------------------------------
;val                       Allocated to stack - _bp -3
;objno                     Allocated to registers r7 
;k                         Allocated to registers r5 
;zuordnung                 Allocated to registers r7 
;sobj                      Allocated to registers r6 
;blockstart                Allocated to registers r7 
;blockend                  Allocated to registers r6 
;action                    Allocated to registers r4 
;------------------------------------------------------------
	G$Sobject_schalten$0$0 ==.
	C$fb_app_rollo11.c$267$1$1 ==.
;	..\fb_app_rollo11.c:267: void Sobject_schalten(unsigned char objno,unsigned char val)// Schaltet die Sicherheitsfunktionen
;	-----------------------------------------
;	 function Sobject_schalten
;	-----------------------------------------
_Sobject_schalten:
	push	_bp
	mov	_bp,sp
	C$fb_app_rollo11.c$271$1$1 ==.
;	..\fb_app_rollo11.c:271: if (objno >18){				// wenn bypass aus delay timer...
	mov	a,dpl
	mov	r7,a
	add	a,#0xff - 0x12
	jnc	00102$
	C$fb_app_rollo11.c$272$2$2 ==.
;	..\fb_app_rollo11.c:272: sobj=objno&0x01;	// dann sobj ausfiltern
	mov	a,#0x01
	anl	a,r7
	mov	r6,a
	C$fb_app_rollo11.c$273$2$2 ==.
;	..\fb_app_rollo11.c:273: state=0;				//state so setzen damit sperre aktiv wird
	clr	_state
	C$fb_app_rollo11.c$274$2$2 ==.
;	..\fb_app_rollo11.c:274: val=0x01;		// dto für objektvalue
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	@r0,#0x01
	sjmp	00103$
00102$:
	C$fb_app_rollo11.c$277$2$3 ==.
;	..\fb_app_rollo11.c:277: sobj=objno-16;				//sobj ("Sicherheitsobjektnummer")ist also 0 für Sicherheit1, 1 für Si 2
	mov	a,r7
	add	a,#0xF0
	mov	r6,a
	C$fb_app_rollo11.c$278$2$3 ==.
;	..\fb_app_rollo11.c:278: state=!((eeprom[0xE2])& (0x40<<sobj));//Polarität
	mov	dptr,#(_eeprom + 0x00e2)
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	mov	b,r6
	inc	b
	mov	r3,#0x40
	mov	r4,#0x00
	sjmp	00132$
00131$:
	mov	a,r3
	add	a,r3
	mov	r3,a
	mov	a,r4
	rlc	a
	mov	r4,a
00132$:
	djnz	b,00131$
	mov	r2,#0x00
	mov	a,r5
	anl	ar3,a
	mov	a,r2
	anl	ar4,a
	mov	a,r3
	orl	a,r4
	cjne	a,#0x01,00133$
00133$:
	clr	a
	rlc	a
	mov	r3,a
	add	a,#0xff
	mov	_state,c
00103$:
	C$fb_app_rollo11.c$281$1$1 ==.
;	..\fb_app_rollo11.c:281: write_obj_value(objno & 0x1F ,val);		// Objektwert im userram speichern
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	ar4,@r0
	mov	r5,#0x00
	anl	ar7,#0x1F
	push	ar6
	push	ar4
	push	ar5
	mov	dpl,r7
	lcall	_write_obj_value
	dec	sp
	dec	sp
	pop	ar6
	C$fb_app_rollo11.c$283$1$1 ==.
;	..\fb_app_rollo11.c:283: if (state^(__bit)val) zfstate=zfstate |(0x0F<<(sobj<<2));// setzen der sicherhfahrt 1 in zfstate, xor verknüpft die polarität
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	a,@r0
	add	a,#0xff
	mov  b0,c
	jnb	_state,00134$
	cpl	c
00134$:
	jnc	00105$
	mov	a,r6
	add	a,r6
	add	a,acc
	mov	r7,a
	mov	b,r7
	inc	b
	mov	a,#0x0F
	sjmp	00138$
00136$:
	add	a,acc
00138$:
	djnz	b,00136$
	mov	r7,a
	orl	_zfstate,a
	sjmp	00106$
00105$:
	C$fb_app_rollo11.c$285$2$4 ==.
;	..\fb_app_rollo11.c:285: zfstate=zfstate & (0xFF-(0x0F<<(sobj<<2)));//in zfstate sind für sich1 0F und sich2 F0
	mov	a,r6
	add	a,r6
	add	a,acc
	mov	r7,a
	mov	b,r7
	inc	b
	mov	a,#0x0F
	sjmp	00141$
00139$:
	add	a,acc
00141$:
	djnz	b,00139$
	mov	r7,a
	mov	a,#0xFF
	clr	c
	subb	a,r7
	anl	_zfstate,a
	C$fb_app_rollo11.c$286$2$4 ==.
;	..\fb_app_rollo11.c:286: set_entriegeln(sobj + 9);// Update objekt macht refresh auf Zeit 9/10  Zyklusüberwachung
	mov	a,#0x09
	add	a,r6
	mov	dpl,a
	lcall	_set_entriegeln
00106$:
	C$fb_app_rollo11.c$288$1$1 ==.
;	..\fb_app_rollo11.c:288: zuordnung=eeprom[0xF1] & zfstate;//in zuordnung jetzt eine 1 für jede sicherheit 
	mov	dptr,#(_eeprom + 0x00f1)
	clr	a
	movc	a,@a+dptr
	mov	r7,a
	mov	a,_zfstate
	anl	ar7,a
	C$fb_app_rollo11.c$289$1$1 ==.
;	..\fb_app_rollo11.c:289: blocked =zuordnung |((zuordnung >>4) | (zuordnung<<4)); //beide Sicherheitsergebnisse verodern..
	mov	a,r7
	swap	a
	orl	a,r7
	mov	_blocked,a
	C$fb_app_rollo11.c$291$1$1 ==.
;	..\fb_app_rollo11.c:291: blockstart= blocked & ~oldblockvalue;//steigende Flanke der Blockade(sicherheit)
	mov	a,_oldblockvalue
	cpl	a
	mov	r7,a
	mov	a,_blocked
	anl	ar7,a
	C$fb_app_rollo11.c$292$1$1 ==.
;	..\fb_app_rollo11.c:292: blockend= ~blocked & oldblockvalue;	//fallende Flanke der Blockade(sicherheit)
	mov	a,_blocked
	cpl	a
	mov	r6,a
	mov	a,_oldblockvalue
	anl	ar6,a
	C$fb_app_rollo11.c$296$1$1 ==.
;	..\fb_app_rollo11.c:296: if (!handmode){
	jnb	_handmode,00142$
	ljmp	00119$
00142$:
	C$fb_app_rollo11.c$297$2$5 ==.
;	..\fb_app_rollo11.c:297: oldblockvalue=blocked;
	mov	_oldblockvalue,_blocked
	C$fb_app_rollo11.c$299$2$1 ==.
;	..\fb_app_rollo11.c:299: for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
	mov	r5,#0x00
00115$:
	mov	a,r5
	add	a,#0xff - 0x03
	jnc	00143$
	ljmp	00119$
00143$:
	C$fb_app_rollo11.c$300$3$6 ==.
;	..\fb_app_rollo11.c:300: action=0;
	mov	r4,#0x00
	C$fb_app_rollo11.c$301$3$6 ==.
;	..\fb_app_rollo11.c:301: if(blockstart & 0x01){
	mov	a,r7
	jnb	acc.0,00108$
	C$fb_app_rollo11.c$302$2$1 ==.
;	..\fb_app_rollo11.c:302: action=(eeprom[0xF0]>>(k<<1))&0x03;
	push	ar6
	mov	dptr,#(_eeprom + 0x00f0)
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	mov	ar2,r5
	clr	a
	xch	a,r2
	add	a,acc
	xch	a,r2
	rlc	a
	mov	r6,a
	mov	b,r2
	inc	b
	mov	a,r3
	sjmp	00146$
00145$:
	clr	c
	rrc	a
00146$:
	djnz	b,00145$
	mov	r3,a
	mov	a,#0x03
	anl	a,r3
	mov	r4,a
	C$fb_app_rollo11.c$299$2$1 ==.
;	..\fb_app_rollo11.c:299: for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
	pop	ar6
	C$fb_app_rollo11.c$302$3$6 ==.
;	..\fb_app_rollo11.c:302: action=(eeprom[0xF0]>>(k<<1))&0x03;
00108$:
	C$fb_app_rollo11.c$304$3$6 ==.
;	..\fb_app_rollo11.c:304: if(blockend & 0x01){
	mov	a,r6
	jnb	acc.0,00110$
	C$fb_app_rollo11.c$305$2$1 ==.
;	..\fb_app_rollo11.c:305: action=(eeprom[0xEF]>>(k<<1))&0x03;
	push	ar6
	mov	dptr,#(_eeprom + 0x00ef)
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	mov	ar2,r5
	clr	a
	xch	a,r2
	add	a,acc
	xch	a,r2
	rlc	a
	mov	r6,a
	mov	b,r2
	inc	b
	mov	a,r3
	sjmp	00149$
00148$:
	clr	c
	rrc	a
00149$:
	djnz	b,00148$
	mov	r3,a
	mov	a,#0x03
	anl	a,r3
	mov	r4,a
	C$fb_app_rollo11.c$299$2$1 ==.
;	..\fb_app_rollo11.c:299: for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
	pop	ar6
	C$fb_app_rollo11.c$305$3$6 ==.
;	..\fb_app_rollo11.c:305: action=(eeprom[0xEF]>>(k<<1))&0x03;
00110$:
	C$fb_app_rollo11.c$307$3$6 ==.
;	..\fb_app_rollo11.c:307: if(action){
	mov	a,r4
	jz	00112$
	C$fb_app_rollo11.c$308$4$9 ==.
;	..\fb_app_rollo11.c:308: object_schalten(k+12,action>>1);
	mov	a,r4
	clr	c
	rrc	a
	add	a,#0xff
	mov	b0,c
	mov	a,#0x0C
	add	a,r5
	mov	r4,a
	mov	c,b0
	mov	b[0],c
	push	ar7
	push	ar6
	push	ar5
	mov	bits,b
	mov	dpl,r4
	lcall	_object_schalten
	pop	ar5
	pop	ar6
	pop	ar7
00112$:
	C$fb_app_rollo11.c$310$3$6 ==.
;	..\fb_app_rollo11.c:310: blockend=blockend>>1;
	mov	a,r6
	clr	c
	rrc	a
	mov	r6,a
	C$fb_app_rollo11.c$311$3$6 ==.
;	..\fb_app_rollo11.c:311: blockstart=blockstart>>1;
	mov	a,r7
	clr	c
	rrc	a
	mov	r7,a
	C$fb_app_rollo11.c$299$2$5 ==.
;	..\fb_app_rollo11.c:299: for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
	inc	r5
	ljmp	00115$
00119$:
	pop	_bp
	C$fb_app_rollo11.c$314$2$1 ==.
	XG$Sobject_schalten$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'object_schalten'
;------------------------------------------------------------
;objstate                  Allocated to registers b0 
;objno                     Allocated to registers r7 
;port_pattern              Allocated to registers 
;objflags                  Allocated to registers r3 
;kwin                      Allocated to stack - _bp +1
;kwout                     Allocated to registers r5 
;faktor                    Allocated to registers r3 
;lz_ue                     Allocated to stack - _bp +2
;tmp                       Allocated to registers r6 
;delay_target              Allocated to registers r4 
;pluszeit                  Allocated to registers r2 
;off_disable               Allocated to registers 
;------------------------------------------------------------
	G$object_schalten$0$0 ==.
	C$fb_app_rollo11.c$320$2$1 ==.
;	..\fb_app_rollo11.c:320: void object_schalten(unsigned char objno, __bit objstate)	// Schaltet einen Ausgang gemäß objstate und den zugörigen Parametern
;	-----------------------------------------
;	 function object_schalten
;	-----------------------------------------
_object_schalten:
	push	_bp
	mov	_bp,sp
	inc	sp
	inc	sp
	mov	r7,dpl
	C$fb_app_rollo11.c$329$1$1 ==.
;	..\fb_app_rollo11.c:329: kwin = kanal[objno & 0x03]& 0x0f;// kwin heisst KanalWertIN. Bit 0+1 Relaise status, Bit 4+5 gewünschter Relaise status
	mov	a,#0x03
	anl	a,r7
	add	a,#_kanal
	mov	r1,a
	mov	ar6,@r1
	mov	r0,_bp
	inc	r0
	mov	a,#0x0F
	anl	a,r6
	mov	@r0,a
	C$fb_app_rollo11.c$330$1$1 ==.
;	..\fb_app_rollo11.c:330: kwout=kwin;
	mov	r0,_bp
	inc	r0
	mov	ar5,@r0
	C$fb_app_rollo11.c$331$1$1 ==.
;	..\fb_app_rollo11.c:331: if (objstate) write_obj_value(objno & 0x07,1);		// Objektwert im userram speichern
	jnb	b0,00102$
	mov	a,#0x07
	anl	a,r7
	mov	dpl,a
	push	ar7
	push	ar5
	push	bits
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	lcall	_write_obj_value
	dec	sp
	dec	sp
	pop	bits
	pop	ar5
	pop	ar7
	sjmp	00103$
00102$:
	C$fb_app_rollo11.c$332$1$1 ==.
;	..\fb_app_rollo11.c:332: else write_obj_value(objno & 0x07,0);
	mov	a,#0x07
	anl	a,r7
	mov	dpl,a
	push	ar7
	push	ar5
	push	bits
	clr	a
	push	acc
	push	acc
	lcall	_write_obj_value
	dec	sp
	dec	sp
	pop	bits
	pop	ar5
	pop	ar7
00103$:
	C$fb_app_rollo11.c$333$1$1 ==.
;	..\fb_app_rollo11.c:333: objflags=read_objflags(objno&0x07);			// Objekt Flags lesen
	mov	a,#0x07
	anl	a,r7
	mov	r4,a
	mov	dpl,a
	push	ar7
	push	ar5
	push	ar4
	push	bits
	lcall	_read_objflags
	mov	r3,dpl
	pop	bits
	pop	ar4
	pop	ar5
	pop	ar7
	C$fb_app_rollo11.c$334$1$1 ==.
;	..\fb_app_rollo11.c:334: port_pattern=0x01<<(objno&0x07);//port_pattern=0x01<<(objno&0x0F)
	mov	b,r4
	inc	b
	mov	a,#0x01
	sjmp	00195$
00193$:
	add	a,acc
00195$:
	djnz	b,00193$
	C$fb_app_rollo11.c$337$1$1 ==.
;	..\fb_app_rollo11.c:337: if((port_pattern & blocked)==0 && (objflags&0x14)==0x14 ||(objno >=8)) {	// Objekt ist nicht gesperrt und Kommunikation zulässig (Bit 2 = communication enable) und Schreiben zulässig (Bit 4 = write enable)
	anl	a,_blocked
	jnz	00161$
	anl	ar3,#0x14
	cjne	r3,#0x14,00197$
	sjmp	00158$
00197$:
00161$:
	cjne	r7,#0x08,00198$
00198$:
	jnc	00199$
	ljmp	00162$
00199$:
00158$:
	C$fb_app_rollo11.c$338$2$2 ==.
;	..\fb_app_rollo11.c:338: objno=objno&0x07;	// damit die bypassobjekte 8-15 wieder 0-7 sind!
	anl	ar7,#0x07
	C$fb_app_rollo11.c$342$2$2 ==.
;	..\fb_app_rollo11.c:342: if (objno<0x04){			//+++++ kurzzeitobjekt +++++
	cjne	r7,#0x04,00200$
00200$:
	jc	00201$
	ljmp	00146$
00201$:
	C$fb_app_rollo11.c$343$3$3 ==.
;	..\fb_app_rollo11.c:343: delay_target = (eeprom[0xE8+(objno>>1)]>>(3*(objno&0x01))&0x07)|0x80;// zeitbasis aus eeprom holen
	mov	a,r7
	clr	c
	rrc	a
	add	a,#0xE8
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r4,a
	mov	a,#0x01
	anl	a,r7
	mov	b,#0x03
	mul	ab
	mov	b,a
	inc	b
	mov	a,r4
	sjmp	00203$
00202$:
	clr	c
	rrc	a
00203$:
	djnz	b,00202$
	anl	a,#0x07
	mov	r4,a
	orl	ar4,#0x80
	C$fb_app_rollo11.c$344$3$3 ==.
;	..\fb_app_rollo11.c:344: faktor=eeprom[0xEA+objno];// faktor holen um dann auf 0 zu prüfen
	mov	a,#0xEA
	add	a,r7
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	C$fb_app_rollo11.c$345$3$3 ==.
;	..\fb_app_rollo11.c:345: pluszeit=faktor + (faktor>>5);// 3% zeit bei "auf" 
	mov	r3,a
	swap	a
	rr	a
	anl	a,#0x07
	add	a,r3
	mov	r2,a
	C$fb_app_rollo11.c$347$3$3 ==.
;	..\fb_app_rollo11.c:347: if (objstate==0){	//----- auf -----
	jb	b0,00116$
	C$fb_app_rollo11.c$349$4$4 ==.
;	..\fb_app_rollo11.c:349: if (kwin&0x33){					// wenn faehrt,dann stop
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	anl	a,#0x33
	jz	00108$
	C$fb_app_rollo11.c$350$5$5 ==.
;	..\fb_app_rollo11.c:350: set_pause(objno,kwin&0x03);
	mov	r0,_bp
	inc	r0
	mov	a,#0x03
	anl	a,@r0
	mov	r6,a
	push	ar7
	push	ar6
	mov	dpl,r7
	lcall	_set_pause
	dec	sp
	pop	ar7
	C$fb_app_rollo11.c$352$5$5 ==.
;	..\fb_app_rollo11.c:352: kwout=kwin&0xCC;	// Fahrt in beide Richtungen stoppen
	mov	r0,_bp
	inc	r0
	mov	a,#0xCC
	anl	a,@r0
	mov	r5,a
	C$fb_app_rollo11.c$353$5$5 ==.
;	..\fb_app_rollo11.c:353: timerbase[objno]=0;	// kurzzeit löschen
	mov	a,r7
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$354$5$5 ==.
;	..\fb_app_rollo11.c:354: timerstate[objno]=0;	// kurzzeit löschen
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$355$5$5 ==.
;	..\fb_app_rollo11.c:355: timerbase[objno+4]=0;  // lanzeit löschen
	mov	a,#0x04
	add	a,r7
	mov	r6,a
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$356$5$5 ==.
;	..\fb_app_rollo11.c:356: timerstate[objno+4]=0;  // lanzeit löschen
	mov	a,r6
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x00
	ljmp	00147$
00108$:
	C$fb_app_rollo11.c$359$4$4 ==.
;	..\fb_app_rollo11.c:359: if ((!(kwin&0x33))&&(faktor)){	//wenn stillstand und faktor>0  dann step
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	anl	a,#0x33
	jz	00207$
	ljmp	00147$
00207$:
	mov	a,r3
	jnz	00208$
	ljmp	00147$
00208$:
	C$fb_app_rollo11.c$360$5$6 ==.
;	..\fb_app_rollo11.c:360: kwout=kwin|0x10;
	mov	r0,_bp
	inc	r0
	mov	a,#0x10
	orl	a,@r0
	mov	r5,a
	C$fb_app_rollo11.c$361$5$6 ==.
;	..\fb_app_rollo11.c:361: kwout=kwout&0xDF;
	anl	ar5,#0xDF
	C$fb_app_rollo11.c$363$5$6 ==.
;	..\fb_app_rollo11.c:363: timerbase[objno]=delay_target;
	mov	a,r7
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,ar4
	C$fb_app_rollo11.c$364$5$6 ==.
;	..\fb_app_rollo11.c:364: timercnt[objno]=pluszeit;
	mov	a,r7
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,ar2
	C$fb_app_rollo11.c$365$5$6 ==.
;	..\fb_app_rollo11.c:365: timerstate[objno]=0x01;
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x01
	ljmp	00147$
00116$:
	C$fb_app_rollo11.c$370$4$7 ==.
;	..\fb_app_rollo11.c:370: if (kwin&0x33){					// wenn faehrt, dann stop
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	anl	a,#0x33
	jz	00111$
	C$fb_app_rollo11.c$371$5$8 ==.
;	..\fb_app_rollo11.c:371: set_pause(objno,kwin&0x03); //einsch. verz "pause" für eventuelle Faht in gegenrichtung
	mov	r0,_bp
	inc	r0
	mov	a,#0x03
	anl	a,@r0
	mov	r6,a
	push	ar7
	push	ar4
	push	ar3
	push	ar6
	mov	dpl,r7
	lcall	_set_pause
	dec	sp
	pop	ar3
	pop	ar4
	pop	ar7
	C$fb_app_rollo11.c$372$5$8 ==.
;	..\fb_app_rollo11.c:372: kwout=kwin&0xCC;
	mov	r0,_bp
	inc	r0
	mov	a,#0xCC
	anl	a,@r0
	mov	r5,a
	C$fb_app_rollo11.c$375$5$8 ==.
;	..\fb_app_rollo11.c:375: timerbase[objno]=0;
	mov	a,r7
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$376$5$8 ==.
;	..\fb_app_rollo11.c:376: timerstate[objno]=0;
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$377$5$8 ==.
;	..\fb_app_rollo11.c:377: timerbase[objno+4]=0;
	mov	a,#0x04
	add	a,r7
	mov	r6,a
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$378$5$8 ==.
;	..\fb_app_rollo11.c:378: timerstate[objno+4]=0;
	mov	a,r6
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x00
00111$:
	C$fb_app_rollo11.c$380$4$7 ==.
;	..\fb_app_rollo11.c:380: if ((!(kwin&0x33))&&(faktor)){		// wenn stillstand dann step
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	anl	a,#0x33
	jz	00211$
	ljmp	00147$
00211$:
	mov	a,r3
	jnz	00212$
	ljmp	00147$
00212$:
	C$fb_app_rollo11.c$381$5$9 ==.
;	..\fb_app_rollo11.c:381: kwout=kwin|0x20;
	mov	r0,_bp
	inc	r0
	mov	a,#0x20
	orl	a,@r0
	mov	r5,a
	C$fb_app_rollo11.c$382$5$9 ==.
;	..\fb_app_rollo11.c:382: kwout=kwout&0xEF;
	anl	ar5,#0xEF
	C$fb_app_rollo11.c$384$5$9 ==.
;	..\fb_app_rollo11.c:384: timerbase[objno]=delay_target;
	mov	a,r7
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,ar4
	C$fb_app_rollo11.c$385$5$9 ==.
;	..\fb_app_rollo11.c:385: timercnt[objno]=faktor;
	mov	a,r7
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,ar3
	C$fb_app_rollo11.c$386$5$9 ==.
;	..\fb_app_rollo11.c:386: timerstate[objno]=0x02;
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x02
	ljmp	00147$
00146$:
	C$fb_app_rollo11.c$393$2$1 ==.
;	..\fb_app_rollo11.c:393: delay_target=(eeprom[0xFB+((objno&0x03)>>1)]>>(3*(objno&0x01))&0x07) | 0x80;// zeitbasis aus eeprom holen
	push	ar5
	mov	a,#0x03
	anl	a,r7
	mov	r6,a
	clr	c
	rrc	a
	add	a,#0xFB
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r5,a
	mov	a,#0x01
	anl	a,r7
	mov	b,#0x03
	mul	ab
	mov	b,a
	inc	b
	mov	a,r5
	sjmp	00214$
00213$:
	clr	c
	rrc	a
00214$:
	djnz	b,00213$
	anl	a,#0x07
	mov	r5,a
	mov	a,#0x80
	orl	a,r5
	mov	r4,a
	C$fb_app_rollo11.c$394$3$10 ==.
;	..\fb_app_rollo11.c:394: faktor = eeprom[0xDA+(objno&0x03)];
	mov	a,#0xDA
	add	a,r6
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	C$fb_app_rollo11.c$395$3$10 ==.
;	..\fb_app_rollo11.c:395: faktor = faktor + (faktor>>2);// +25% zeit bei langzeit 
	mov	r3,a
	rr	a
	rr	a
	anl	a,#0x3F
	add	a,r3
	C$fb_app_rollo11.c$396$3$10 ==.
;	..\fb_app_rollo11.c:396: pluszeit=faktor + (faktor>>5);// 3% zeit bei "auf" 
	mov	r3,a
	swap	a
	rr	a
	anl	a,#0x07
	add	a,r3
	mov	r2,a
	C$fb_app_rollo11.c$397$3$10 ==.
;	..\fb_app_rollo11.c:397: lz_ue=((eeprom[0xF2]>>objno)&0x01);		//lz_ue bedeutet: langzeit unendlich
	mov	dptr,#(_eeprom + 0x00f2)
	clr	a
	movc	a,@a+dptr
	mov	r6,a
	mov	b,r7
	inc	b
	mov	a,r6
	sjmp	00216$
00215$:
	clr	c
	rrc	a
00216$:
	djnz	b,00215$
	mov	r6,a
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,#0x01
	anl	a,r6
	mov	@r0,a
	C$fb_app_rollo11.c$398$2$1 ==.
;	..\fb_app_rollo11.c:398: if (objstate==0){// --- auf ----
	pop	ar5
	jnb	b0,00217$
	ljmp	00143$
00217$:
	C$fb_app_rollo11.c$399$4$11 ==.
;	..\fb_app_rollo11.c:399: if (kwin&0x11){		//läuft bereits, also nachtriggern
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	anl	a,#0x11
	jz	00121$
	C$fb_app_rollo11.c$400$5$12 ==.
;	..\fb_app_rollo11.c:400: kwout=kwin|0x10;// auch hier neu setzen da in delay nach rechts kommt
	mov	r0,_bp
	inc	r0
	mov	a,#0x10
	orl	a,@r0
	mov	r5,a
	C$fb_app_rollo11.c$401$5$12 ==.
;	..\fb_app_rollo11.c:401: timercnt[objno-4]=0;//kurzzeit löschen
	mov	a,r7
	add	a,#0xFC
	mov	r6,a
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$402$5$12 ==.
;	..\fb_app_rollo11.c:402: timerstate[objno-4]=0;
	mov	a,r6
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$403$5$12 ==.
;	..\fb_app_rollo11.c:403: timerbase[objno-4]=0;
	mov	a,r6
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$404$5$12 ==.
;	..\fb_app_rollo11.c:404: if (!lz_ue){
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	jnz	00121$
	C$fb_app_rollo11.c$406$6$13 ==.
;	..\fb_app_rollo11.c:406: timerbase[objno]=delay_target;
	mov	a,r7
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,ar4
	C$fb_app_rollo11.c$407$6$13 ==.
;	..\fb_app_rollo11.c:407: timercnt[objno]=pluszeit;
	mov	a,r7
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,ar2
	C$fb_app_rollo11.c$408$6$13 ==.
;	..\fb_app_rollo11.c:408: timerstate[objno]=0x01;
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x01
00121$:
	C$fb_app_rollo11.c$411$4$11 ==.
;	..\fb_app_rollo11.c:411: if (!(kwin&0x33)){	//wenn stillstand, dann move
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	anl	a,#0x33
	jnz	00125$
	C$fb_app_rollo11.c$412$5$14 ==.
;	..\fb_app_rollo11.c:412: kwout=kwin|0x10;
	mov	r0,_bp
	inc	r0
	mov	a,#0x10
	orl	a,@r0
	mov	r5,a
	C$fb_app_rollo11.c$415$5$14 ==.
;	..\fb_app_rollo11.c:415: if (!lz_ue){
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	jnz	00125$
	C$fb_app_rollo11.c$417$6$15 ==.
;	..\fb_app_rollo11.c:417: timerbase[objno]=delay_target;
	mov	a,r7
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,ar4
	C$fb_app_rollo11.c$418$6$15 ==.
;	..\fb_app_rollo11.c:418: timercnt[objno]=pluszeit;
	mov	a,r7
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,ar2
	C$fb_app_rollo11.c$419$6$15 ==.
;	..\fb_app_rollo11.c:419: timerstate[objno]=0x01;
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x01
00125$:
	C$fb_app_rollo11.c$423$4$11 ==.
;	..\fb_app_rollo11.c:423: if (kwin&0x22){		// wenn fahrt in andere richtung
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	anl	a,#0x22
	jnz	00223$
	ljmp	00147$
00223$:
	C$fb_app_rollo11.c$424$5$16 ==.
;	..\fb_app_rollo11.c:424: set_pause(objno,0x05);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
	push	ar7
	push	ar4
	push	ar2
	mov	a,#0x05
	push	acc
	mov	dpl,r7
	lcall	_set_pause
	dec	sp
	pop	ar2
	pop	ar4
	pop	ar7
	C$fb_app_rollo11.c$425$5$16 ==.
;	..\fb_app_rollo11.c:425: kwout=kwin|0x10;
	mov	r0,_bp
	inc	r0
	mov	a,#0x10
	orl	a,@r0
	mov	r5,a
	C$fb_app_rollo11.c$426$5$16 ==.
;	..\fb_app_rollo11.c:426: kwout=kwout&0xDF;
	anl	ar5,#0xDF
	C$fb_app_rollo11.c$427$5$16 ==.
;	..\fb_app_rollo11.c:427: if (!lz_ue){
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	jz	00224$
	ljmp	00147$
00224$:
	C$fb_app_rollo11.c$429$6$17 ==.
;	..\fb_app_rollo11.c:429: timerbase[objno]=delay_target & 0x7F;// timer-run für den move löschen
	mov	a,r7
	add	a,#_timerbase
	mov	r1,a
	mov	a,#0x7F
	anl	a,r4
	mov	@r1,a
	C$fb_app_rollo11.c$430$6$17 ==.
;	..\fb_app_rollo11.c:430: timercnt[objno]=pluszeit;
	mov	a,r7
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,ar2
	C$fb_app_rollo11.c$431$6$17 ==.
;	..\fb_app_rollo11.c:431: timerstate[objno]=0x01;
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x01
	ljmp	00147$
00143$:
	C$fb_app_rollo11.c$437$4$18 ==.
;	..\fb_app_rollo11.c:437: if (kwin&0x22){		//läuft bereits, also nachtriggern
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	anl	a,#0x22
	jz	00133$
	C$fb_app_rollo11.c$438$5$19 ==.
;	..\fb_app_rollo11.c:438: kwout=kwin|0x20;// auch hier neu setzen da in delay nach rechts kommt
	mov	r0,_bp
	inc	r0
	mov	a,#0x20
	orl	a,@r0
	mov	r5,a
	C$fb_app_rollo11.c$439$5$19 ==.
;	..\fb_app_rollo11.c:439: timerbase[objno-4]=0; 
	mov	a,r7
	add	a,#0xFC
	mov	r6,a
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$440$5$19 ==.
;	..\fb_app_rollo11.c:440: timercnt[objno-4]=0;
	mov	a,r6
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$441$5$19 ==.
;	..\fb_app_rollo11.c:441: timerstate[objno-4]=0;
	mov	a,r6
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$443$5$19 ==.
;	..\fb_app_rollo11.c:443: if (!lz_ue){
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	jnz	00133$
	C$fb_app_rollo11.c$445$6$20 ==.
;	..\fb_app_rollo11.c:445: timerbase[objno]=delay_target;
	mov	a,r7
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,ar4
	C$fb_app_rollo11.c$446$6$20 ==.
;	..\fb_app_rollo11.c:446: timercnt[objno]=faktor;
	mov	a,r7
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,ar3
	C$fb_app_rollo11.c$447$6$20 ==.
;	..\fb_app_rollo11.c:447: timerstate[objno]=0x02;
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x02
00133$:
	C$fb_app_rollo11.c$450$4$18 ==.
;	..\fb_app_rollo11.c:450: if (!(kwin&0x33)){	//wenn stillstand, dann move
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	anl	a,#0x33
	jnz	00137$
	C$fb_app_rollo11.c$451$5$21 ==.
;	..\fb_app_rollo11.c:451: kwout=kwin|0x20;// kanal setzen
	mov	r0,_bp
	inc	r0
	mov	a,#0x20
	orl	a,@r0
	mov	r5,a
	C$fb_app_rollo11.c$454$5$21 ==.
;	..\fb_app_rollo11.c:454: timerbase[objno-4]=0; 
	mov	a,r7
	add	a,#0xFC
	mov	r6,a
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$455$5$21 ==.
;	..\fb_app_rollo11.c:455: timercnt[objno-4]=0;
	mov	a,r6
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$456$5$21 ==.
;	..\fb_app_rollo11.c:456: timerstate[objno-4]=0;
	mov	a,r6
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$457$5$21 ==.
;	..\fb_app_rollo11.c:457: if (!lz_ue){
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	jnz	00137$
	C$fb_app_rollo11.c$459$6$22 ==.
;	..\fb_app_rollo11.c:459: timerbase[objno]=delay_target;
	mov	a,r7
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,ar4
	C$fb_app_rollo11.c$460$6$22 ==.
;	..\fb_app_rollo11.c:460: timercnt[objno]=faktor;
	mov	a,r7
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,ar3
	C$fb_app_rollo11.c$461$6$22 ==.
;	..\fb_app_rollo11.c:461: timerstate[objno]=0x02;
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x02
00137$:
	C$fb_app_rollo11.c$464$4$18 ==.
;	..\fb_app_rollo11.c:464: if (kwin&0x11){					// wenn fahrt in andere richtung
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	anl	a,#0x11
	jz	00147$
	C$fb_app_rollo11.c$465$5$23 ==.
;	..\fb_app_rollo11.c:465: set_pause(objno, 0x06);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
	push	ar7
	push	ar4
	push	ar3
	mov	a,#0x06
	push	acc
	mov	dpl,r7
	lcall	_set_pause
	dec	sp
	pop	ar3
	pop	ar4
	pop	ar7
	C$fb_app_rollo11.c$466$5$23 ==.
;	..\fb_app_rollo11.c:466: kwout=kwin|0x20;
	mov	r0,_bp
	inc	r0
	mov	a,#0x20
	orl	a,@r0
	mov	r5,a
	C$fb_app_rollo11.c$467$5$23 ==.
;	..\fb_app_rollo11.c:467: kwout=kwout&0xEF;
	anl	ar5,#0xEF
	C$fb_app_rollo11.c$469$5$23 ==.
;	..\fb_app_rollo11.c:469: timerbase[objno-4]=0; // kurzzeit löschen
	mov	a,r7
	add	a,#0xFC
	mov	r6,a
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$470$5$23 ==.
;	..\fb_app_rollo11.c:470: timercnt[objno-4]=0;
	mov	a,r6
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$471$5$23 ==.
;	..\fb_app_rollo11.c:471: timerstate[objno-4]=0;
	mov	a,r6
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$472$5$23 ==.
;	..\fb_app_rollo11.c:472: if (!lz_ue){
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	jnz	00147$
	C$fb_app_rollo11.c$474$6$24 ==.
;	..\fb_app_rollo11.c:474: timerbase[objno]=delay_target & 0x7F;// timer run des langzeit löschen
	mov	a,r7
	add	a,#_timerbase
	mov	r1,a
	mov	a,#0x7F
	anl	a,r4
	mov	@r1,a
	C$fb_app_rollo11.c$475$6$24 ==.
;	..\fb_app_rollo11.c:475: timercnt[objno]=faktor;
	mov	a,r7
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,ar3
	C$fb_app_rollo11.c$476$6$24 ==.
;	..\fb_app_rollo11.c:476: timerstate[objno]=0x02;
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x02
00147$:
	C$fb_app_rollo11.c$485$2$2 ==.
;	..\fb_app_rollo11.c:485: kwin=kwout;
	mov	r0,_bp
	inc	r0
	mov	@r0,ar5
	C$fb_app_rollo11.c$486$2$2 ==.
;	..\fb_app_rollo11.c:486: if (objno<=7){
	mov	a,r7
	add	a,#0xff - 0x07
	jc	00157$
	C$fb_app_rollo11.c$487$3$25 ==.
;	..\fb_app_rollo11.c:487: tmp=timerstate[((objno & 0x03)+11)]& 0x07;
	mov	a,#0x03
	anl	a,r7
	add	a,#0x0B
	add	a,#_timerstate
	mov	r1,a
	mov	ar6,@r1
	anl	ar6,#0x07
	C$fb_app_rollo11.c$489$3$25 ==.
;	..\fb_app_rollo11.c:489: if ((tmp<4)&& (tmp & (kwout>>4) & 0x03)){
	cjne	r6,#0x04,00233$
00233$:
	jnc	00149$
	mov	a,r5
	swap	a
	anl	a,#0x0F
	mov	r4,a
	anl	a,r6
	anl	a,#0x03
	jz	00149$
	C$fb_app_rollo11.c$491$4$26 ==.
;	..\fb_app_rollo11.c:491: timerbase[(objno&0x03)+11]=0; 
	mov	a,#0x03
	anl	a,r7
	add	a,#0x0B
	mov	r4,a
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$492$4$26 ==.
;	..\fb_app_rollo11.c:492: timercnt[(objno&0x03)+11]=0;//gleiche Richtung: Pause löschen
	mov	a,r4
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$493$4$26 ==.
;	..\fb_app_rollo11.c:493: timerstate[(objno&0x03)+11]=0;
	mov	a,r4
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$494$4$26 ==.
;	..\fb_app_rollo11.c:494: tmp=0;
	mov	r6,#0x00
00149$:
	C$fb_app_rollo11.c$497$3$25 ==.
;	..\fb_app_rollo11.c:497: if(tmp & 0x04){//wenn Pause wegen umschalten läuft,Kanal "ist" löschen.
	mov	a,r6
	jnb	acc.2,00154$
	C$fb_app_rollo11.c$499$4$27 ==.
;	..\fb_app_rollo11.c:499: kwout=kwout&0xF0;
	anl	ar5,#0xF0
	sjmp	00157$
00154$:
	C$fb_app_rollo11.c$502$4$28 ==.
;	..\fb_app_rollo11.c:502: if(!(tmp)){
	mov	a,r6
	jnz	00157$
	C$fb_app_rollo11.c$503$5$29 ==.
;	..\fb_app_rollo11.c:503: kwout=kwin>>4;//wenn keiene Pause Läuft, dann kanal "soll" in "ist" kopieren
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	swap	a
	anl	a,#0x0F
	mov	r5,a
00157$:
	C$fb_app_rollo11.c$509$2$2 ==.
;	..\fb_app_rollo11.c:509: kanal[objno&0x03]=kwout;
	mov	a,#0x03
	anl	a,r7
	add	a,#_kanal
	mov	r0,a
	mov	@r0,ar5
	C$fb_app_rollo11.c$510$2$2 ==.
;	..\fb_app_rollo11.c:510: portchanged=1;
	setb	_portchanged
00162$:
	mov	sp,_bp
	pop	_bp
	C$fb_app_rollo11.c$514$2$1 ==.
	XG$object_schalten$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay_timer'
;------------------------------------------------------------
;objno                     Allocated to registers r7 
;delay_state               Allocated to registers r6 
;m                         Allocated to registers r5 
;timerflags                Allocated to registers r6 r7 
;------------------------------------------------------------
	G$delay_timer$0$0 ==.
	C$fb_app_rollo11.c$519$2$1 ==.
;	..\fb_app_rollo11.c:519: void delay_timer(void)	// zählt alle 8 ms die Variable Timer hoch und prüft Queue
;	-----------------------------------------
;	 function delay_timer
;	-----------------------------------------
_delay_timer:
	C$fb_app_rollo11.c$528$1$1 ==.
;	..\fb_app_rollo11.c:528: RTCCON=0x61;		// RTC Flag löschen
	mov	_RTCCON,#0x61
	C$fb_app_rollo11.c$530$1$1 ==.
;	..\fb_app_rollo11.c:530: timer++;
	mov	a,#0x01
	add	a,_timer
	mov	_timer,a
	clr	a
	addc	a,(_timer + 1)
	mov	(_timer + 1),a
	C$fb_app_rollo11.c$531$1$1 ==.
;	..\fb_app_rollo11.c:531: timerflags = timer&(~(timer-1));
	mov	a,_timer
	add	a,#0xFF
	mov	r6,a
	mov	a,(_timer + 1)
	addc	a,#0xFF
	mov	r7,a
	mov	a,r6
	cpl	a
	mov	r6,a
	mov	a,r7
	cpl	a
	mov	r7,a
	mov	a,_timer
	anl	ar6,a
	mov	a,(_timer + 1)
	anl	ar7,a
	C$fb_app_rollo11.c$534$4$4 ==.
;	..\fb_app_rollo11.c:534: for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
	mov	r5,#0x00
00138$:
	cjne	r5,#0x10,00173$
00173$:
	jnc	00141$
	C$fb_app_rollo11.c$536$2$2 ==.
;	..\fb_app_rollo11.c:536: if(timerbase[m]& 0x80){// wenn run-bit gesetzt
	mov	a,r5
	add	a,#_timerbase
	mov	r1,a
	mov	a,@r1
	mov	r4,a
	jnb	acc.7,00140$
	C$fb_app_rollo11.c$537$3$3 ==.
;	..\fb_app_rollo11.c:537: if((timerbase[m]==0x82)||(timerflags & (timerflagmask[timerbase[m]&0x7f]))){// wenn das flag mit der gespeicherten base übereinstimmt						
	mov	a,r5
	add	a,#_timerbase
	mov	r1,a
	mov	ar4,@r1
	cjne	r4,#0x82,00176$
	sjmp	00103$
00176$:
	mov	a,r5
	add	a,#_timerbase
	mov	r1,a
	mov	ar4,@r1
	anl	ar4,#0x7F
	mov	a,r4
	add	a,r4
	mov	r3,a
	mov	dptr,#_timerflagmask
	movc	a,@a+dptr
	xch	a,r3
	inc	dptr
	movc	a,@a+dptr
	mov	r4,a
	mov	a,r6
	anl	ar3,a
	mov	a,r7
	anl	ar4,a
	mov	a,r3
	orl	a,r4
	jz	00140$
00103$:
	C$fb_app_rollo11.c$538$4$4 ==.
;	..\fb_app_rollo11.c:538: if (timercnt[m]>0x00){// wenn der counter läuft...
	mov	a,r5
	add	a,#_timercnt
	mov	r1,a
	mov	a,@r1
	mov	r4,a
	jz	00140$
	C$fb_app_rollo11.c$539$5$5 ==.
;	..\fb_app_rollo11.c:539: timercnt[m]=timercnt[m]-1;// den timer [m]decrementieren
	mov	a,r4
	dec	a
	mov	@r1,a
00140$:
	C$fb_app_rollo11.c$534$1$1 ==.
;	..\fb_app_rollo11.c:534: for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
	inc	r5
	sjmp	00138$
00141$:
	C$fb_app_rollo11.c$550$5$14 ==.
;	..\fb_app_rollo11.c:550: for(objno=0;objno<=15;objno++) {
	mov	r7,#0x00
00142$:
	mov	a,r7
	add	a,#0xff - 0x0F
	jnc	00179$
	ljmp	00145$
00179$:
	C$fb_app_rollo11.c$551$2$6 ==.
;	..\fb_app_rollo11.c:551: delay_state=timerstate[objno];			//status des timer-records
	mov	a,r7
	add	a,#_timerstate
	mov	r1,a
	C$fb_app_rollo11.c$552$2$6 ==.
;	..\fb_app_rollo11.c:552: if(delay_state!=0x00) {					// 0x00 = delay Eintrag ist leer   
	mov	a,@r1
	mov	r6,a
	jnz	00180$
	ljmp	00144$
00180$:
	C$fb_app_rollo11.c$553$3$7 ==.
;	..\fb_app_rollo11.c:553: if(timercnt[objno]==0 && (timerbase[objno]&0x80)) { 	// wenn der cnt null und run=1, also zeit ist abgelaufen...
	mov	a,r7
	add	a,#_timercnt
	mov	r0,a
	mov	a,@r0
	jz	00181$
	ljmp	00144$
00181$:
	mov	a,r7
	add	a,#_timerbase
	mov	r5,a
	push	ar0
	mov	r0,ar5
	mov	ar5,@r0
	pop	ar0
	mov	a,r5
	jb	acc.7,00182$
	ljmp	00144$
00182$:
	C$fb_app_rollo11.c$554$4$8 ==.
;	..\fb_app_rollo11.c:554: if (objno<=7){// wenns ein kurz oder langzeit objekt ist...
	mov	a,r7
	add	a,#0xff - 0x07
	jc	00109$
	C$fb_app_rollo11.c$555$5$9 ==.
;	..\fb_app_rollo11.c:555: timerbase[objno]=0;
	mov	a,r7
	add	a,#_timerbase
	push	ar0
	mov	r0,a
	mov	@r0,#0x00
	pop	ar0
	C$fb_app_rollo11.c$556$5$9 ==.
;	..\fb_app_rollo11.c:556: timercnt[objno]=0;
	C$fb_app_rollo11.c$557$5$9 ==.
;	..\fb_app_rollo11.c:557: timerstate[objno]=0;
	C$fb_app_rollo11.c$558$5$9 ==.
;	..\fb_app_rollo11.c:558: kanal[objno&0x03]=0x00;
	clr	a
	mov	@r0,a
	mov	@r1,a
	mov	a,#0x03
	anl	a,r7
	add	a,#_kanal
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$559$5$9 ==.
;	..\fb_app_rollo11.c:559: set_pause(objno,(delay_state));// einsch. verz "pause" für eventuelle Fahrt in gegenrichtung
	push	ar7
	push	ar6
	push	ar6
	mov	dpl,r7
	lcall	_set_pause
	dec	sp
	pop	ar6
	pop	ar7
00109$:
	C$fb_app_rollo11.c$562$4$8 ==.
;	..\fb_app_rollo11.c:562: if (objno==9 ){	//Sicherheit 1
	cjne	r7,#0x09,00113$
	C$fb_app_rollo11.c$563$5$10 ==.
;	..\fb_app_rollo11.c:563: if (delay_state == 0x01){
	cjne	r6,#0x01,00113$
	C$fb_app_rollo11.c$564$6$11 ==.
;	..\fb_app_rollo11.c:564: timerstate[9]=0x02;// wenn ziel erreicht in delrec sichern
	mov	(_timerstate + 0x0009),#0x02
	C$fb_app_rollo11.c$565$6$11 ==.
;	..\fb_app_rollo11.c:565: Sobject_schalten(48,1);// und Sicherheitsobjekt über bypass schalten
	push	ar7
	push	ar6
	mov	a,#0x01
	push	acc
	mov	dpl,#0x30
	lcall	_Sobject_schalten
	dec	sp
	pop	ar6
	pop	ar7
00113$:
	C$fb_app_rollo11.c$569$4$8 ==.
;	..\fb_app_rollo11.c:569: if (objno==10 ){	//Sicherheit 2
	cjne	r7,#0x0A,00117$
	C$fb_app_rollo11.c$570$5$12 ==.
;	..\fb_app_rollo11.c:570: if (delay_state == 0x01){
	cjne	r6,#0x01,00117$
	C$fb_app_rollo11.c$571$6$13 ==.
;	..\fb_app_rollo11.c:571: timerstate[10]=0x02;// wenn ziel erreicht in delrec sichern
	mov	(_timerstate + 0x000a),#0x02
	C$fb_app_rollo11.c$572$6$13 ==.
;	..\fb_app_rollo11.c:572: Sobject_schalten(49,1);// und Sicherheitsobjekt über bypass schalten
	push	ar7
	push	ar6
	mov	a,#0x01
	push	acc
	mov	dpl,#0x31
	lcall	_Sobject_schalten
	dec	sp
	pop	ar6
	pop	ar7
00117$:
	C$fb_app_rollo11.c$576$4$8 ==.
;	..\fb_app_rollo11.c:576: if ((objno>=11) && (objno<=14)){// die Pausezeit der Kanaele
	cjne	r7,#0x0B,00192$
00192$:
	jc	00121$
	mov	a,r7
	add	a,#0xff - 0x0E
	jc	00121$
	C$fb_app_rollo11.c$577$5$14 ==.
;	..\fb_app_rollo11.c:577: kanal[objno-11]=kanal[objno-11]>>4;			// die oberen 4 bit des kanals sind die neue value.
	mov	a,r7
	add	a,#0xF5
	add	a,#_kanal
	mov	r1,a
	mov	a,@r1
	swap	a
	anl	a,#0x0F
	mov	r5,a
	mov	@r1,a
	C$fb_app_rollo11.c$578$5$14 ==.
;	..\fb_app_rollo11.c:578: timerbase[objno]=0;
	mov	a,r7
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$579$5$14 ==.
;	..\fb_app_rollo11.c:579: timercnt[objno]=0;			//timer loeschen
	mov	a,r7
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$580$5$14 ==.
;	..\fb_app_rollo11.c:580: timerstate[objno]=0;
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$581$5$14 ==.
;	..\fb_app_rollo11.c:581: if(timerstate[objno-7])timerbase[objno-7]|=0x80;// timer run-bit des zugehörigen Langzeitobjektes setzen
	mov	a,r7
	add	a,#0xF9
	add	a,#_timerstate
	mov	r1,a
	mov	a,@r1
	jz	00121$
	mov	a,r7
	add	a,#0xF9
	mov	r5,a
	add	a,#_timerbase
	mov	r1,a
	mov	a,r5
	add	a,#_timerbase
	mov	r0,a
	mov	ar5,@r0
	mov	a,#0x80
	orl	a,r5
	mov	@r1,a
00121$:
	C$fb_app_rollo11.c$583$4$8 ==.
;	..\fb_app_rollo11.c:583: if (objno>=15){// handmode kurz/langtele + einschaltverz + ausschaltverz
	cjne	r7,#0x0F,00196$
00196$:
	jc	00130$
	C$fb_app_rollo11.c$585$5$15 ==.
;	..\fb_app_rollo11.c:585: if (delay_state == 0x12) timerstate[15]=0x22; // wenn ziel 2 erreicht,  sichern
	cjne	r6,#0x12,00124$
	mov	(_timerstate + 0x000f),#0x22
00124$:
	C$fb_app_rollo11.c$586$5$15 ==.
;	..\fb_app_rollo11.c:586: if (delay_state == 0x01){
	cjne	r6,#0x01,00126$
	C$fb_app_rollo11.c$587$6$16 ==.
;	..\fb_app_rollo11.c:587: timerbase[15]=0x80 + 3;
	mov	(_timerbase + 0x000f),#0x83
	C$fb_app_rollo11.c$588$6$16 ==.
;	..\fb_app_rollo11.c:588: timerstate[15]=0x12;
	mov	(_timerstate + 0x000f),#0x12
	C$fb_app_rollo11.c$589$6$16 ==.
;	..\fb_app_rollo11.c:589: timercnt[15]= 20;// wenn ziel 1 erreicht , sichern und restzeit fuer ziel 2 schreiben
	mov	(_timercnt + 0x000f),#0x14
00126$:
	C$fb_app_rollo11.c$592$5$15 ==.
;	..\fb_app_rollo11.c:592: if (delay_state == 0x04) timerstate[15]= 0x08;// wenn ziel erreicht , sichern
	cjne	r6,#0x04,00130$
	mov	(_timerstate + 0x000f),#0x08
00130$:
	C$fb_app_rollo11.c$594$4$8 ==.
;	..\fb_app_rollo11.c:594: portchanged=1;
	setb	_portchanged
00144$:
	C$fb_app_rollo11.c$550$1$1 ==.
;	..\fb_app_rollo11.c:550: for(objno=0;objno<=15;objno++) {
	inc	r7
	ljmp	00142$
00145$:
	C$fb_app_rollo11.c$604$1$1 ==.
;	..\fb_app_rollo11.c:604: if (eeprom[0xE5]& 0xC0){
	mov	dptr,#(_eeprom + 0x00e5)
	clr	a
	movc	a,@a+dptr
	mov	r7,a
	anl	a,#0xC0
	jz	00146$
	C$fb_app_rollo11.c$605$2$17 ==.
;	..\fb_app_rollo11.c:605: handsteuerung();   // Handbetätigung nur jedes 8.mal ausführen
	lcall	_handsteuerung
00146$:
	C$fb_app_rollo11.c$609$2$1 ==.
	XG$delay_timer$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'handsteuerung'
;------------------------------------------------------------
;n                         Allocated to registers r6 
;tmph                      Allocated to registers 
;key_pattern               Allocated to registers r7 
;Tasten                    Allocated to registers r7 
;------------------------------------------------------------
	G$handsteuerung$0$0 ==.
	C$fb_app_rollo11.c$684$2$1 ==.
;	..\fb_app_rollo11.c:684: void handsteuerung(void)
;	-----------------------------------------
;	 function handsteuerung
;	-----------------------------------------
_handsteuerung:
	C$fb_app_rollo11.c$699$1$1 ==.
;	..\fb_app_rollo11.c:699: if((TMOD&0x0F)==0x02 && fb_state==0) {
	mov	a,#0x0F
	anl	a,_TMOD
	mov	r7,a
	cjne	r7,#0x02,00155$
	sjmp	00156$
00155$:
	ljmp	00136$
00156$:
	mov	a,_fb_state
	jz	00157$
	ljmp	00136$
00157$:
	C$fb_app_rollo11.c$709$2$2 ==.
;	..\fb_app_rollo11.c:709: while( (TMOD&0x0F)==0x02 && ( TL0>0x72));// PWM scannen um "Hand"-Tasten abzufragen
00102$:
	mov	a,#0x0F
	anl	a,_TMOD
	mov	r7,a
	cjne	r7,#0x02,00104$
	mov	a,_TL0
	add	a,#0xff - 0x72
	jc	00102$
00104$:
	C$fb_app_rollo11.c$734$2$2 ==.
;	..\fb_app_rollo11.c:734: key_pattern=(0x01<<(delay_toggle&0x03));
	mov	a,#0x03
	anl	a,_delay_toggle
	mov	r7,a
	mov	b,r7
	inc	b
	mov	a,#0x01
	sjmp	00163$
00161$:
	add	a,acc
00163$:
	djnz	b,00161$
	C$fb_app_rollo11.c$735$2$2 ==.
;	..\fb_app_rollo11.c:735: P0 = ~key_pattern;
	mov	r7,a
	cpl	a
	mov	_P0,a
	C$fb_app_rollo11.c$736$2$2 ==.
;	..\fb_app_rollo11.c:736: P0_5=1;
	setb	_P0_5
	C$fb_app_rollo11.c$737$2$2 ==.
;	..\fb_app_rollo11.c:737: if(!P0_5 && !ledport)ledport=0x08+(delay_toggle&0x03);	
	jb	_P0_5,00106$
	mov	a,_ledport
	jnz	00106$
	mov	a,#0x03
	anl	a,_delay_toggle
	add	a,#0x08
	mov	_ledport,a
00106$:
	C$fb_app_rollo11.c$739$2$2 ==.
;	..\fb_app_rollo11.c:739: P0=oldportbuffer; 
	mov	_P0,_oldportbuffer
	C$fb_app_rollo11.c$746$2$2 ==.
;	..\fb_app_rollo11.c:746: if (key_pattern==0x08)
	cjne	r7,#0x08,00166$
	sjmp	00167$
00166$:
	ljmp	00136$
00167$:
	C$fb_app_rollo11.c$749$3$3 ==.
;	..\fb_app_rollo11.c:749: Tasten=ledport;
	mov	r7,_ledport
	C$fb_app_rollo11.c$750$3$3 ==.
;	..\fb_app_rollo11.c:750: ledport=0;
	mov	_ledport,#0x00
	C$fb_app_rollo11.c$754$3$3 ==.
;	..\fb_app_rollo11.c:754: if (Tasten & 0x08 ){
	mov	a,r7
	jnb	acc.3,00123$
	C$fb_app_rollo11.c$755$4$4 ==.
;	..\fb_app_rollo11.c:755: if (!Tval ){// steigende Flanke des Tasters 
	mov	a,_Tval
	jz	00169$
	ljmp	00124$
00169$:
	C$fb_app_rollo11.c$758$5$5 ==.
;	..\fb_app_rollo11.c:758: timerstate[15]=0x01;
	mov	(_timerstate + 0x000f),#0x01
	C$fb_app_rollo11.c$759$5$5 ==.
;	..\fb_app_rollo11.c:759: timerbase[15]=0x80 + 2;
	mov	(_timerbase + 0x000f),#0x82
	C$fb_app_rollo11.c$760$5$5 ==.
;	..\fb_app_rollo11.c:760: timercnt[15]= 50;
	mov	(_timercnt + 0x000f),#0x32
	ljmp	00124$
00123$:
	C$fb_app_rollo11.c$764$4$6 ==.
;	..\fb_app_rollo11.c:764: if ( Tval & 0x08){ // wenn tasten >7 und Tval <=7 also taste losgelassen...
	mov	a,_Tval
	jb	acc.3,00170$
	ljmp	00124$
00170$:
	C$fb_app_rollo11.c$765$5$7 ==.
;	..\fb_app_rollo11.c:765: if (timerstate[15]&0x20){
	mov	a,(_timerstate + 0x000f)
	jnb	acc.5,00114$
	C$fb_app_rollo11.c$766$6$8 ==.
;	..\fb_app_rollo11.c:766: handmode = !handmode;
	cpl	_handmode
	C$fb_app_rollo11.c$767$6$8 ==.
;	..\fb_app_rollo11.c:767: timerbase[15]=0;
	mov	(_timerbase + 0x000f),#0x00
	C$fb_app_rollo11.c$768$6$8 ==.
;	..\fb_app_rollo11.c:768: timerstate[15]=0;
	mov	(_timerstate + 0x000f),#0x00
	C$fb_app_rollo11.c$769$6$8 ==.
;	..\fb_app_rollo11.c:769: timercnt[15]=0;
	mov	(_timercnt + 0x000f),#0x00
	C$fb_app_rollo11.c$770$6$8 ==.
;	..\fb_app_rollo11.c:770: if (handmode){
	jnb	_handmode,00111$
	C$fb_app_rollo11.c$771$7$9 ==.
;	..\fb_app_rollo11.c:771: for(n=0;n<=3;n++) kanal[n]=0x00;
	mov	r6,#0x00
00132$:
	mov	a,r6
	add	a,#0xff - 0x03
	jc	00135$
	mov	a,r6
	add	a,#_kanal
	mov	r0,a
	mov	@r0,#0x00
	inc	r6
	sjmp	00132$
00135$:
	C$fb_app_rollo11.c$772$7$9 ==.
;	..\fb_app_rollo11.c:772: portchanged=1;
	setb	_portchanged
	sjmp	00114$
00111$:
	C$fb_app_rollo11.c$775$7$10 ==.
;	..\fb_app_rollo11.c:775: sobj_update();
	push	ar7
	lcall	_sobj_update
	pop	ar7
00114$:
	C$fb_app_rollo11.c$778$5$7 ==.
;	..\fb_app_rollo11.c:778: if (handmode){// wenn handmode aktiv...
	jnb	_handmode,00119$
	C$fb_app_rollo11.c$779$6$11 ==.
;	..\fb_app_rollo11.c:779: if (timerstate[15]&0x02){// status der zeit=2 also abgelaufen..
	mov	a,(_timerstate + 0x000f)
	jnb	acc.1,00116$
	C$fb_app_rollo11.c$780$7$12 ==.
;	..\fb_app_rollo11.c:780: object_schalten(((Tval&0x07)>>1)+12,(Tval&0x01));
	mov	a,_Tval
	anl	a,#0x01
	add	a,#0xff
	mov	b0,c
	mov	a,#0x07
	anl	a,_Tval
	clr	c
	rrc	a
	add	a,#0x0C
	mov	dpl,a
	mov	c,b0
	mov	b[0],c
	push	ar7
	mov	bits,b
	lcall	_object_schalten
	pop	ar7
	sjmp	00119$
00116$:
	C$fb_app_rollo11.c$783$7$13 ==.
;	..\fb_app_rollo11.c:783: object_schalten(((Tval&0x07)>>1)+8,(Tval&0x01));
	mov	a,_Tval
	anl	a,#0x01
	add	a,#0xff
	mov	b0,c
	mov	a,#0x07
	anl	a,_Tval
	clr	c
	rrc	a
	add	a,#0x08
	mov	dpl,a
	mov	c,b0
	mov	b[0],c
	push	ar7
	mov	bits,b
	lcall	_object_schalten
	pop	ar7
00119$:
	C$fb_app_rollo11.c$787$5$7 ==.
;	..\fb_app_rollo11.c:787: timerbase[15]=0x80 + 3;//130ms
	mov	(_timerbase + 0x000f),#0x83
	C$fb_app_rollo11.c$788$5$7 ==.
;	..\fb_app_rollo11.c:788: timerstate[15]=0x04;
	mov	(_timerstate + 0x000f),#0x04
	C$fb_app_rollo11.c$789$5$7 ==.
;	..\fb_app_rollo11.c:789: timercnt[15]=116;//=15 Sekunden
	mov	(_timercnt + 0x000f),#0x74
00124$:
	C$fb_app_rollo11.c$792$3$3 ==.
;	..\fb_app_rollo11.c:792: Tval=Tasten;
	mov	_Tval,r7
	C$fb_app_rollo11.c$794$3$3 ==.
;	..\fb_app_rollo11.c:794: if(timerstate[15]&0x08){
	mov	a,(_timerstate + 0x000f)
	jnb	acc.3,00136$
	C$fb_app_rollo11.c$795$4$14 ==.
;	..\fb_app_rollo11.c:795: handmode=0;//handmode automatisch ausschalten
	clr	_handmode
	C$fb_app_rollo11.c$797$4$14 ==.
;	..\fb_app_rollo11.c:797: timerbase[15]=0;
	mov	(_timerbase + 0x000f),#0x00
	C$fb_app_rollo11.c$798$4$14 ==.
;	..\fb_app_rollo11.c:798: timerstate[15]=0;
	mov	(_timerstate + 0x000f),#0x00
	C$fb_app_rollo11.c$799$4$14 ==.
;	..\fb_app_rollo11.c:799: timercnt[15]=0;
	mov	(_timercnt + 0x000f),#0x00
	C$fb_app_rollo11.c$800$4$14 ==.
;	..\fb_app_rollo11.c:800: sobj_update();
	lcall	_sobj_update
00136$:
	C$fb_app_rollo11.c$805$1$1 ==.
	XG$handsteuerung$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'sobj_update'
;------------------------------------------------------------
	G$sobj_update$0$0 ==.
	C$fb_app_rollo11.c$809$1$1 ==.
;	..\fb_app_rollo11.c:809: void sobj_update(void)
;	-----------------------------------------
;	 function sobj_update
;	-----------------------------------------
_sobj_update:
	C$fb_app_rollo11.c$811$1$1 ==.
;	..\fb_app_rollo11.c:811: Sobject_schalten(16,read_obj_value(16)&0x01);
	mov	dpl,#0x10
	lcall	_read_obj_value
	mov	r4,dpl
	anl	ar4,#0x01
	push	ar4
	mov	dpl,#0x10
	lcall	_Sobject_schalten
	dec	sp
	C$fb_app_rollo11.c$812$1$1 ==.
;	..\fb_app_rollo11.c:812: Sobject_schalten(17,read_obj_value(17)&0x01);
	mov	dpl,#0x11
	lcall	_read_obj_value
	mov	r4,dpl
	anl	ar4,#0x01
	push	ar4
	mov	dpl,#0x11
	lcall	_Sobject_schalten
	dec	sp
	C$fb_app_rollo11.c$813$1$1 ==.
	XG$sobj_update$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'set_pause'
;------------------------------------------------------------
;Pstate                    Allocated to stack - _bp -3
;objnr                     Allocated to registers r7 
;pause                     Allocated to registers r7 
;pauseobj                  Allocated to registers r6 
;------------------------------------------------------------
	G$set_pause$0$0 ==.
	C$fb_app_rollo11.c$814$1$1 ==.
;	..\fb_app_rollo11.c:814: void set_pause(unsigned char objnr,unsigned char Pstate)// setzt die Pausezeit und traegt Pstate in timerstate[ ] ein
;	-----------------------------------------
;	 function set_pause
;	-----------------------------------------
_set_pause:
	push	_bp
	mov	_bp,sp
	mov	r7,dpl
	C$fb_app_rollo11.c$817$1$1 ==.
;	..\fb_app_rollo11.c:817: pauseobj=(objnr&0x03)+11;
	anl	ar7,#0x03
	mov	a,#0x0B
	add	a,r7
	C$fb_app_rollo11.c$818$1$1 ==.
;	..\fb_app_rollo11.c:818: timerstate[pauseobj]=Pstate;
	mov	r6,a
	add	a,#_timerstate
	mov	r0,a
	mov	a,_bp
	add	a,#0xfd
	mov	r1,a
	mov	a,@r1
	mov	@r0,a
	C$fb_app_rollo11.c$819$1$1 ==.
;	..\fb_app_rollo11.c:819: switch ((eeprom[0xEE]>>((objnr&0x03)<<1))&0x03) { // Dauer zwischen auf und ab
	mov	dptr,#(_eeprom + 0x00ee)
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	clr	a
	xch	a,r7
	add	a,acc
	xch	a,r7
	rlc	a
	mov	r4,a
	mov	b,r7
	inc	b
	mov	a,r5
	sjmp	00112$
00111$:
	clr	c
	rrc	a
00112$:
	djnz	b,00111$
	anl	a,#0x03
	mov	r7,a
	jz	00101$
	cjne	r7,#0x01,00114$
	sjmp	00102$
00114$:
	C$fb_app_rollo11.c$820$2$2 ==.
;	..\fb_app_rollo11.c:820: case 0:	// 0,5s
	cjne	r7,#0x02,00104$
	sjmp	00103$
00101$:
	C$fb_app_rollo11.c$821$2$2 ==.
;	..\fb_app_rollo11.c:821: pause=4 ;
	mov	r7,#0x04
	C$fb_app_rollo11.c$822$2$2 ==.
;	..\fb_app_rollo11.c:822: break;
	C$fb_app_rollo11.c$823$2$2 ==.
;	..\fb_app_rollo11.c:823: case 1:	// 1s
	sjmp	00105$
00102$:
	C$fb_app_rollo11.c$824$2$2 ==.
;	..\fb_app_rollo11.c:824: pause=8 ;
	mov	r7,#0x08
	C$fb_app_rollo11.c$825$2$2 ==.
;	..\fb_app_rollo11.c:825: break;
	C$fb_app_rollo11.c$826$2$2 ==.
;	..\fb_app_rollo11.c:826: case 2:	// 2s
	sjmp	00105$
00103$:
	C$fb_app_rollo11.c$827$2$2 ==.
;	..\fb_app_rollo11.c:827: pause=16 ;
	mov	r7,#0x10
	C$fb_app_rollo11.c$828$2$2 ==.
;	..\fb_app_rollo11.c:828: break;
	C$fb_app_rollo11.c$829$2$2 ==.
;	..\fb_app_rollo11.c:829: default:	// 5s
	sjmp	00105$
00104$:
	C$fb_app_rollo11.c$830$2$2 ==.
;	..\fb_app_rollo11.c:830: pause=39 ;
	mov	r7,#0x27
	C$fb_app_rollo11.c$832$1$1 ==.
;	..\fb_app_rollo11.c:832: }
00105$:
	C$fb_app_rollo11.c$833$1$1 ==.
;	..\fb_app_rollo11.c:833: timercnt[pauseobj]=pause;
	mov	a,r6
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,ar7
	C$fb_app_rollo11.c$834$1$1 ==.
;	..\fb_app_rollo11.c:834: timerbase[pauseobj]= 3 | 0x80;
	mov	a,r6
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x83
	pop	_bp
	C$fb_app_rollo11.c$836$1$1 ==.
	XG$set_pause$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'set_entriegeln'
;------------------------------------------------------------
;zeitnr                    Allocated to registers r7 
;svbase                    Allocated to registers r6 
;------------------------------------------------------------
	G$set_entriegeln$0$0 ==.
	C$fb_app_rollo11.c$839$1$1 ==.
;	..\fb_app_rollo11.c:839: void set_entriegeln(unsigned char zeitnr)// Setzt die zyklische überwachungszeit
;	-----------------------------------------
;	 function set_entriegeln
;	-----------------------------------------
_set_entriegeln:
	mov	r7,dpl
	C$fb_app_rollo11.c$844$1$1 ==.
;	..\fb_app_rollo11.c:844: svbase=eeprom[0xD9]&0x0F;
	mov	dptr,#(_eeprom + 0x00d9)
	clr	a
	movc	a,@a+dptr
	C$fb_app_rollo11.c$845$1$1 ==.
;	..\fb_app_rollo11.c:845: if(svbase){
	anl	a,#0x0F
	mov	r6,a
	jz	00102$
	C$fb_app_rollo11.c$846$2$2 ==.
;	..\fb_app_rollo11.c:846: timercnt[zeitnr]=svfaktorarray[svbase];
	mov	a,r7
	add	a,#_timercnt
	mov	r1,a
	mov	a,r6
	mov	dptr,#_svfaktorarray
	movc	a,@a+dptr
	mov	r6,a
	mov	@r1,a
	C$fb_app_rollo11.c$847$2$2 ==.
;	..\fb_app_rollo11.c:847: timerbase[zeitnr]=5 | 0x80;
	mov	a,r7
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x85
	C$fb_app_rollo11.c$848$2$2 ==.
;	..\fb_app_rollo11.c:848: timerstate[zeitnr]=0x01;
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x01
	sjmp	00104$
00102$:
	C$fb_app_rollo11.c$851$2$3 ==.
;	..\fb_app_rollo11.c:851: timerbase[zeitnr]=0;
	mov	a,r7
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$852$2$3 ==.
;	..\fb_app_rollo11.c:852: timerstate[zeitnr]=0;
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x00
00104$:
	C$fb_app_rollo11.c$855$1$1 ==.
	XG$set_entriegeln$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'port_schalten'
;------------------------------------------------------------
;kmod                      Allocated to registers r7 
;------------------------------------------------------------
	G$port_schalten$0$0 ==.
	C$fb_app_rollo11.c$918$1$1 ==.
;	..\fb_app_rollo11.c:918: void port_schalten(void)		// Schaltet die Ports mit PWM, DUTY ist Pulsverhältnis
;	-----------------------------------------
;	 function port_schalten
;	-----------------------------------------
_port_schalten:
	C$fb_app_rollo11.c$922$1$1 ==.
;	..\fb_app_rollo11.c:922: portbuffer=0;
	mov	_portbuffer,#0x00
	C$fb_app_rollo11.c$923$1$1 ==.
;	..\fb_app_rollo11.c:923: if (eeprom[0xE4]& 0x80) kmod=0x01;		// bit 7 ist Kanal-mode
	mov	dptr,#(_eeprom + 0x00e4)
	clr	a
	movc	a,@a+dptr
	mov	r7,a
	jnb	acc.7,00102$
	mov	r7,#0x01
	sjmp	00103$
00102$:
	C$fb_app_rollo11.c$924$1$1 ==.
;	..\fb_app_rollo11.c:924: else kmod=0x03;
	mov	r7,#0x03
00103$:
	C$fb_app_rollo11.c$925$1$1 ==.
;	..\fb_app_rollo11.c:925: for (knr=0;knr<=0x03;knr++){
	mov	_knr,#0x00
00107$:
	mov	a,_knr
	add	a,#0xff - 0x03
	jc	00110$
	C$fb_app_rollo11.c$926$2$2 ==.
;	..\fb_app_rollo11.c:926: portbuffer=portbuffer|((kanal[knr & kmod]& 0x03)<<(knr<<1));
	mov	a,r7
	anl	a,_knr
	add	a,#_kanal
	mov	r1,a
	mov	ar6,@r1
	anl	ar6,#0x03
	mov	a,_knr
	add	a,_knr
	mov	r5,a
	mov	b,r5
	inc	b
	mov	a,r6
	sjmp	00121$
00119$:
	add	a,acc
00121$:
	djnz	b,00119$
	mov	r6,a
	orl	_portbuffer,a
	C$fb_app_rollo11.c$925$1$1 ==.
;	..\fb_app_rollo11.c:925: for (knr=0;knr<=0x03;knr++){
	inc	_knr
	sjmp	00107$
00110$:
	C$fb_app_rollo11.c$991$1$1 ==.
;	..\fb_app_rollo11.c:991: if(portbuffer & ~oldportbuffer) {	// Vollstrom nur wenn ein relais eingeschaltet wird
	mov	r6,_oldportbuffer
	mov	r7,#0x00
	mov	a,r6
	cpl	a
	mov	r6,a
	mov	a,r7
	cpl	a
	mov	r7,a
	mov	r4,_portbuffer
	mov	r5,#0x00
	mov	a,r4
	anl	ar6,a
	mov	a,r5
	anl	ar7,a
	mov	a,r6
	orl	a,r7
	jz	00105$
	C$fb_app_rollo11.c$992$2$3 ==.
;	..\fb_app_rollo11.c:992: TR0=0;
	clr	_TCON_4
	C$fb_app_rollo11.c$993$2$3 ==.
;	..\fb_app_rollo11.c:993: AUXR1&=0xE9;	// PWM von Timer 0 nicht mehr auf Pin ausgeben
	anl	_AUXR1,#0xE9
	C$fb_app_rollo11.c$996$2$3 ==.
;	..\fb_app_rollo11.c:996: PWM=0;			// Vollstrom an
	clr	_P1_2
	C$fb_app_rollo11.c$998$2$3 ==.
;	..\fb_app_rollo11.c:998: P0=portbuffer;		// Ports schalten
	mov	_P0,_portbuffer
	C$fb_app_rollo11.c$999$2$3 ==.
;	..\fb_app_rollo11.c:999: TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
	clr	_TCON_5
	C$fb_app_rollo11.c$1000$2$3 ==.
;	..\fb_app_rollo11.c:1000: TH0=0x00;		// 16ms (10ms=6fff)
	C$fb_app_rollo11.c$1001$2$3 ==.
;	..\fb_app_rollo11.c:1001: TL0=0x00;
	C$fb_app_rollo11.c$1002$2$3 ==.
;	..\fb_app_rollo11.c:1002: TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
	clr	a
	mov	_TH0,a
	mov	_TL0,a
	mov	a,#0xF0
	anl	a,_TMOD
	inc	a
	mov	_TMOD,a
	C$fb_app_rollo11.c$1003$2$3 ==.
;	..\fb_app_rollo11.c:1003: TAMOD=0x00;
	mov	_TAMOD,#0x00
	C$fb_app_rollo11.c$1004$2$3 ==.
;	..\fb_app_rollo11.c:1004: TR0=1;
	setb	_TCON_4
	sjmp	00106$
00105$:
	C$fb_app_rollo11.c$1006$1$1 ==.
;	..\fb_app_rollo11.c:1006: else P0=portbuffer;
	mov	_P0,_portbuffer
00106$:
	C$fb_app_rollo11.c$1009$1$1 ==.
;	..\fb_app_rollo11.c:1009: oldportbuffer=portbuffer;
	mov	_oldportbuffer,_portbuffer
	C$fb_app_rollo11.c$1010$1$1 ==.
;	..\fb_app_rollo11.c:1010: portchanged=0;
	clr	_portchanged
	C$fb_app_rollo11.c$1014$1$1 ==.
	XG$port_schalten$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'bus_return'
;------------------------------------------------------------
;n                         Allocated to registers r7 
;------------------------------------------------------------
	G$bus_return$0$0 ==.
	C$fb_app_rollo11.c$1136$1$1 ==.
;	..\fb_app_rollo11.c:1136: void bus_return(void)		// Aktionen bei Busspannungswiederkehr
;	-----------------------------------------
;	 function bus_return
;	-----------------------------------------
_bus_return:
	C$fb_app_rollo11.c$1139$1$1 ==.
;	..\fb_app_rollo11.c:1139: blocked=blockedsave;		// Ausgänge gesperrt?
	mov	dptr,#_blockedsave
	clr	a
	movc	a,@a+dptr
	mov	_blocked,a
	C$fb_app_rollo11.c$1140$1$1 ==.
;	..\fb_app_rollo11.c:1140: timer=0;			// Timer-Variable, wird alle 8 ms inkrementiert
	C$fb_app_rollo11.c$1141$2$2 ==.
;	..\fb_app_rollo11.c:1141: for (n=0;n<=15;n++){// Löschen aller zeiten
	clr	a
	mov	_timer,a
	mov	(_timer + 1),a
	mov	r7,a
00107$:
	mov	a,r7
	add	a,#0xff - 0x0F
	jc	00110$
	C$fb_app_rollo11.c$1142$2$2 ==.
;	..\fb_app_rollo11.c:1142: timerstate[n]=0;
	mov	a,r7
	add	a,#_timerstate
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$1143$2$2 ==.
;	..\fb_app_rollo11.c:1143: timerbase[n]=0;
	mov	a,r7
	add	a,#_timerbase
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$1144$2$2 ==.
;	..\fb_app_rollo11.c:1144: timercnt[n]=0;
	mov	a,r7
	add	a,#_timercnt
	mov	r0,a
	mov	@r0,#0x00
	C$fb_app_rollo11.c$1141$1$1 ==.
;	..\fb_app_rollo11.c:1141: for (n=0;n<=15;n++){// Löschen aller zeiten
	inc	r7
	sjmp	00107$
00110$:
	C$fb_app_rollo11.c$1146$1$1 ==.
;	..\fb_app_rollo11.c:1146: for (n=0;n<=3;n++){
	mov	r7,#0x00
00111$:
	mov	a,r7
	add	a,#0xff - 0x03
	jc	00114$
	C$fb_app_rollo11.c$1147$2$3 ==.
;	..\fb_app_rollo11.c:1147: if(((eeprom[0xF1]>>n)&0x11)==0 ){// wenn keine Sperrfunktion zugewiesen
	mov	dptr,#(_eeprom + 0x00f1)
	clr	a
	movc	a,@a+dptr
	mov	r6,a
	mov	b,r7
	inc	b
	mov	a,r6
	sjmp	00129$
00128$:
	clr	c
	rrc	a
00129$:
	djnz	b,00128$
	anl	a,#0x11
	jz	00131$
	sjmp	00102$
00131$:
	C$fb_app_rollo11.c$1148$3$4 ==.
;	..\fb_app_rollo11.c:1148: blocked &= ~(0x11<<n);  // dann blocked löschen, damit nach umpara
	mov	b,r7
	inc	b
	mov	a,#0x11
	sjmp	00134$
00132$:
	add	a,acc
00134$:
	djnz	b,00132$
	cpl	a
	mov	r6,a
	anl	_blocked,a
00102$:
	C$fb_app_rollo11.c$1150$2$3 ==.
;	..\fb_app_rollo11.c:1150: switch(eeprom[0xD9]& 0xC0){
	mov	dptr,#(_eeprom + 0x00d9)
	clr	a
	movc	a,@a+dptr
	mov	r6,a
	anl	ar6,#0xC0
	cjne	r6,#0x40,00135$
	sjmp	00103$
00135$:
	C$fb_app_rollo11.c$1151$3$5 ==.
;	..\fb_app_rollo11.c:1151: case 0x40:
	cjne	r6,#0x80,00113$
	sjmp	00104$
00103$:
	C$fb_app_rollo11.c$1152$3$5 ==.
;	..\fb_app_rollo11.c:1152: object_schalten(n+12,0);
	mov	a,#0x0C
	add	a,r7
	mov	dpl,a
	clr	b[0]
	push	ar7
	mov	bits,b
	lcall	_object_schalten
	pop	ar7
	C$fb_app_rollo11.c$1153$3$5 ==.
;	..\fb_app_rollo11.c:1153: break;
	C$fb_app_rollo11.c$1154$3$5 ==.
;	..\fb_app_rollo11.c:1154: case 0x80:
	sjmp	00113$
00104$:
	C$fb_app_rollo11.c$1155$3$5 ==.
;	..\fb_app_rollo11.c:1155: object_schalten(n+12,1);
	mov	a,#0x0C
	add	a,r7
	mov	dpl,a
	setb	b[0]
	push	ar7
	mov	bits,b
	lcall	_object_schalten
	pop	ar7
	C$fb_app_rollo11.c$1158$2$3 ==.
;	..\fb_app_rollo11.c:1158: }
00113$:
	C$fb_app_rollo11.c$1146$1$1 ==.
;	..\fb_app_rollo11.c:1146: for (n=0;n<=3;n++){
	inc	r7
	sjmp	00111$
00114$:
	C$fb_app_rollo11.c$1162$1$1 ==.
;	..\fb_app_rollo11.c:1162: oldportbuffer=0; 	// auf 0 setzen, da sonst kein Vollstrom aktiviert wird
	mov	_oldportbuffer,#0x00
	C$fb_app_rollo11.c$1163$1$1 ==.
;	..\fb_app_rollo11.c:1163: portchanged=1;		// Post hinterlegen damit in delaytimer nach portschalten springt
	setb	_portchanged
	C$fb_app_rollo11.c$1165$1$1 ==.
;	..\fb_app_rollo11.c:1165: set_entriegeln(9);	// Überwachungszeit Sicherheitsfahrt
	mov	dpl,#0x09
	lcall	_set_entriegeln
	C$fb_app_rollo11.c$1166$1$1 ==.
;	..\fb_app_rollo11.c:1166: set_entriegeln(10);	// dto
	mov	dpl,#0x0A
	lcall	_set_entriegeln
	C$fb_app_rollo11.c$1169$1$1 ==.
	XG$bus_return$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'restart_app'
;------------------------------------------------------------
	G$restart_app$0$0 ==.
	C$fb_app_rollo11.c$1171$1$1 ==.
;	..\fb_app_rollo11.c:1171: void restart_app(void) 		// Alle Applikations-Parameter zurücksetzen
;	-----------------------------------------
;	 function restart_app
;	-----------------------------------------
_restart_app:
	C$fb_app_rollo11.c$1174$1$1 ==.
;	..\fb_app_rollo11.c:1174: Tval=0x00;
	mov	_Tval,#0x00
	C$fb_app_rollo11.c$1175$1$1 ==.
;	..\fb_app_rollo11.c:1175: handmode=0;
	clr	_handmode
	C$fb_app_rollo11.c$1177$1$1 ==.
;	..\fb_app_rollo11.c:1177: P0=0;
	mov	_P0,#0x00
	C$fb_app_rollo11.c$1178$1$1 ==.
;	..\fb_app_rollo11.c:1178: P0M1=0x00;		// Port 0 Modus push-pull für Ausgang
	mov	_P0M1,#0x00
	C$fb_app_rollo11.c$1183$1$1 ==.
;	..\fb_app_rollo11.c:1183: P0M2=0x0F;
	mov	_P0M2,#0x0F
	C$fb_app_rollo11.c$1189$1$1 ==.
;	..\fb_app_rollo11.c:1189: TMOD=(TMOD & 0xF0) + 2;		// Timer 0 als PWM
	mov	a,#0xF0
	anl	a,_TMOD
	add	a,#0x02
	mov	_TMOD,a
	C$fb_app_rollo11.c$1190$1$1 ==.
;	..\fb_app_rollo11.c:1190: TAMOD=0x01;
	mov	_TAMOD,#0x01
	C$fb_app_rollo11.c$1191$1$1 ==.
;	..\fb_app_rollo11.c:1191: TH0=DUTY;		// Pulsverhältnis PWM
	mov	_TH0,#0x50
	C$fb_app_rollo11.c$1192$1$1 ==.
;	..\fb_app_rollo11.c:1192: AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
	orl	_AUXR1,#0x10
	C$fb_app_rollo11.c$1193$1$1 ==.
;	..\fb_app_rollo11.c:1193: TR0=1;			// Timer 0 starten (PWM)
	setb	_TCON_4
	C$fb_app_rollo11.c$1198$1$1 ==.
;	..\fb_app_rollo11.c:1198: ET0=0;			// Interrupt für Timer 0 sperren
	clr	_IEN0_1
	C$fb_app_rollo11.c$1199$1$1 ==.
;	..\fb_app_rollo11.c:1199: IT0=1;
	setb	_TCON_0
	C$fb_app_rollo11.c$1200$1$1 ==.
;	..\fb_app_rollo11.c:1200: blocked=0x00;		// Ausgänge nicht gesperrt
	C$fb_app_rollo11.c$1201$1$1 ==.
;	..\fb_app_rollo11.c:1201: timer=0;			// Timer-Variable, wird alle 8ms inkrementiert
	C$fb_app_rollo11.c$1204$1$1 ==.
;	..\fb_app_rollo11.c:1204: delay_toggle=0;
	clr	a
	mov	_blocked,a
	mov	_timer,a
	mov	(_timer + 1),a
	mov	_delay_toggle,a
	C$fb_app_rollo11.c$1206$1$1 ==.
;	..\fb_app_rollo11.c:1206: EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	clr	_IEN0_7
	C$fb_app_rollo11.c$1207$1$1 ==.
;	..\fb_app_rollo11.c:1207: START_WRITECYCLE
	mov	_FMCON,#0x00
	C$fb_app_rollo11.c$1208$1$1 ==.
;	..\fb_app_rollo11.c:1208: WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x03
	mov	_FMDATA,#0x00
	C$fb_app_rollo11.c$1209$1$1 ==.
;	..\fb_app_rollo11.c:1209: WRITE_BYTE(0x01,0x04,0x04)
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x04
	mov	_FMDATA,#0x04
	C$fb_app_rollo11.c$1213$1$1 ==.
;	..\fb_app_rollo11.c:1213: WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x0C
	mov	_FMDATA,#0x00
	C$fb_app_rollo11.c$1214$1$1 ==.
;	..\fb_app_rollo11.c:1214: WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x0D
	mov	_FMDATA,#0xFF
	C$fb_app_rollo11.c$1216$1$1 ==.
;	..\fb_app_rollo11.c:1216: STOP_WRITECYCLE
	mov	_FMCON,#0x68
	C$fb_app_rollo11.c$1217$1$1 ==.
;	..\fb_app_rollo11.c:1217: EA=1;						// Interrupts freigeben
	setb	_IEN0_7
	C$fb_app_rollo11.c$1219$1$1 ==.
;	..\fb_app_rollo11.c:1219: RTCCON=0x60;		// RTC Flag löschen
	mov	_RTCCON,#0x60
	C$fb_app_rollo11.c$1220$1$1 ==.
;	..\fb_app_rollo11.c:1220: RTCH=0x01;			// reload Real Time Clock
	mov	_RTCH,#0x01
	C$fb_app_rollo11.c$1221$1$1 ==.
;	..\fb_app_rollo11.c:1221: RTCL=0xCD;			// 8ms
	mov	_RTCL,#0xCD
	C$fb_app_rollo11.c$1222$1$1 ==.
;	..\fb_app_rollo11.c:1222: RTCCON=0x61;
	mov	_RTCCON,#0x61
	C$fb_app_rollo11.c$1223$1$1 ==.
	XG$restart_app$0$0 ==.
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
Ffb_app_rollo11$blockedsave$0$0 == 0x1bfd
_blockedsave	=	0x1bfd
G$timerflagmask$0$0 == .
_timerflagmask:
	.byte #0x00,#0x00	; 0
	.byte #0x00,#0x00	; 0
	.byte #0x00,#0x00	; 0
	.byte #0x08,#0x00	; 8
	.byte #0x80,#0x00	; 128
	.byte #0x00,#0x08	; 2048
G$svfaktorarray$0$0 == .
_svfaktorarray:
	.db #0x00	; 0
	.db #0x02	; 2
	.db #0x04	; 4
	.db #0x06	; 6
	.db #0x08	; 8
	.db #0x0A	; 10
	.db #0x0C	; 12
	.db #0x0E	; 14
	.db #0x10	; 16
	.db #0x12	; 18
	.db #0x14	; 20
	.db #0x16	; 22
	.db #0x24	; 36
	.db #0x48	; 72	'H'
	.db #0x6D	; 109	'm'
	.db #0xDA	; 218
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
