                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Sun Dec 30 12:23:20 2012
                              5 ;--------------------------------------------------------
                              6 	.module fb_app_counter
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _objno_timer
                             13 	.globl _paraindex_timer
                             14 	.globl _find_first_objno
                             15 	.globl _read_objflags
                             16 	.globl _send_obj_value
                             17 	.globl _gapos_in_gat
                             18 	.globl _P3_1
                             19 	.globl _P3_0
                             20 	.globl _P1_7
                             21 	.globl _P1_6
                             22 	.globl _P1_5
                             23 	.globl _P1_4
                             24 	.globl _P1_3
                             25 	.globl _P1_2
                             26 	.globl _P1_1
                             27 	.globl _P1_0
                             28 	.globl _P0_7
                             29 	.globl _P0_6
                             30 	.globl _P0_5
                             31 	.globl _P0_4
                             32 	.globl _P0_3
                             33 	.globl _P0_2
                             34 	.globl _P0_1
                             35 	.globl _P0_0
                             36 	.globl _I2CON_0
                             37 	.globl _I2CON_2
                             38 	.globl _I2CON_3
                             39 	.globl _I2CON_4
                             40 	.globl _I2CON_5
                             41 	.globl _I2CON_6
                             42 	.globl _SCON_7
                             43 	.globl _SCON_6
                             44 	.globl _SCON_5
                             45 	.globl _SCON_4
                             46 	.globl _SCON_3
                             47 	.globl _SCON_2
                             48 	.globl _SCON_1
                             49 	.globl _SCON_0
                             50 	.globl _IP0_0
                             51 	.globl _IP0_1
                             52 	.globl _IP0_2
                             53 	.globl _IP0_3
                             54 	.globl _IP0_4
                             55 	.globl _IP0_5
                             56 	.globl _IP0_6
                             57 	.globl _IP1_0
                             58 	.globl _IP1_1
                             59 	.globl _IP1_2
                             60 	.globl _IP1_6
                             61 	.globl _IEN1_0
                             62 	.globl _IEN1_1
                             63 	.globl _IEN1_2
                             64 	.globl _IEN0_0
                             65 	.globl _IEN0_1
                             66 	.globl _IEN0_2
                             67 	.globl _IEN0_3
                             68 	.globl _IEN0_4
                             69 	.globl _IEN0_5
                             70 	.globl _IEN0_6
                             71 	.globl _IEN0_7
                             72 	.globl _TCON_0
                             73 	.globl _TCON_1
                             74 	.globl _TCON_2
                             75 	.globl _TCON_3
                             76 	.globl _TCON_4
                             77 	.globl _TCON_5
                             78 	.globl _TCON_6
                             79 	.globl _TCON_7
                             80 	.globl _PSW_7
                             81 	.globl _PSW_6
                             82 	.globl _PSW_5
                             83 	.globl _PSW_4
                             84 	.globl _PSW_3
                             85 	.globl _PSW_2
                             86 	.globl _PSW_1
                             87 	.globl _PSW_0
                             88 	.globl _IEN1
                             89 	.globl _IP0H
                             90 	.globl _WFEED2
                             91 	.globl _WFEED1
                             92 	.globl _WDL
                             93 	.globl _WDCON
                             94 	.globl _TRIM
                             95 	.globl _TAMOD
                             96 	.globl _SSTAT
                             97 	.globl _RTCL
                             98 	.globl _RTCH
                             99 	.globl _RTCCON
                            100 	.globl _RSTSRC
                            101 	.globl _PT0AD
                            102 	.globl _PCONA
                            103 	.globl _P3M2
                            104 	.globl _P3M1
                            105 	.globl _P1M2
                            106 	.globl _P1M1
                            107 	.globl _P0M2
                            108 	.globl _P0M1
                            109 	.globl _KBPATN
                            110 	.globl _KBMASK
                            111 	.globl _KBCON
                            112 	.globl _IP1H
                            113 	.globl _IP1
                            114 	.globl _I2STAT
                            115 	.globl _I2SCLL
                            116 	.globl _I2SCLH
                            117 	.globl _I2DAT
                            118 	.globl _I2CON
                            119 	.globl _I2ADR
                            120 	.globl _FMDATA
                            121 	.globl _FMCON
                            122 	.globl _FMADRL
                            123 	.globl _FMADRH
                            124 	.globl _DIVM
                            125 	.globl _CMP2
                            126 	.globl _CMP1
                            127 	.globl _BRGCON
                            128 	.globl _BRGR1
                            129 	.globl _BRGR0
                            130 	.globl _SADEN
                            131 	.globl _SADDR
                            132 	.globl _AUXR1
                            133 	.globl _SBUF
                            134 	.globl _SCON
                            135 	.globl _IP0
                            136 	.globl _IEN0
                            137 	.globl _TH1
                            138 	.globl _TH0
                            139 	.globl _TL1
                            140 	.globl _TL0
                            141 	.globl _TMOD
                            142 	.globl _TCON
                            143 	.globl _PCON
                            144 	.globl _DPH
                            145 	.globl _DPL
                            146 	.globl _SP
                            147 	.globl _B
                            148 	.globl _ACC
                            149 	.globl _PSW
                            150 	.globl _P3
                            151 	.globl _P1
                            152 	.globl _P0
                            153 	.globl _counted1
                            154 	.globl _counted0
                            155 	.globl _st_Flanke
                            156 	.globl _jobj
                            157 	.globl _objval
                            158 	.globl _precounter1
                            159 	.globl _precounter0
                            160 	.globl _bitobj_z2
                            161 	.globl _bitobj_z1
                            162 	.globl _counter_moment
                            163 	.globl _counter_summe
                            164 	.globl _para_value
                            165 	.globl _timercnt
                            166 	.globl _timerbase
                            167 	.globl _timerflags
                            168 	.globl _timerday
                            169 	.globl _timerhour
                            170 	.globl _timer60
                            171 	.globl _timer500
                            172 	.globl _timer_state
                            173 	.globl _timer_base
                            174 	.globl _objstate
                            175 	.globl _p0h
                            176 	.globl _portbuffer
                            177 	.globl _keypad_isr
                            178 	.globl _pin_changed
                            179 	.globl _eis5conversion
                            180 	.globl _delay_timer
                            181 	.globl _write_value_req
                            182 	.globl _checklevel
                            183 	.globl _read_value_req
                            184 	.globl _sendbychange
                            185 	.globl _write_send
                            186 	.globl _bus_return
                            187 	.globl _read_obj_value
                            188 	.globl _write_obj_value
                            189 	.globl _keypad_init
                            190 	.globl _restart_app
                            191 ;--------------------------------------------------------
                            192 ; special function registers
                            193 ;--------------------------------------------------------
                            194 	.area RSEG    (ABS,DATA)
   0000                     195 	.org 0x0000
                    0080    196 G$P0$0$0 == 0x0080
                    0080    197 _P0	=	0x0080
                    0090    198 G$P1$0$0 == 0x0090
                    0090    199 _P1	=	0x0090
                    00B0    200 G$P3$0$0 == 0x00b0
                    00B0    201 _P3	=	0x00b0
                    00D0    202 G$PSW$0$0 == 0x00d0
                    00D0    203 _PSW	=	0x00d0
                    00E0    204 G$ACC$0$0 == 0x00e0
                    00E0    205 _ACC	=	0x00e0
                    00F0    206 G$B$0$0 == 0x00f0
                    00F0    207 _B	=	0x00f0
                    0081    208 G$SP$0$0 == 0x0081
                    0081    209 _SP	=	0x0081
                    0082    210 G$DPL$0$0 == 0x0082
                    0082    211 _DPL	=	0x0082
                    0083    212 G$DPH$0$0 == 0x0083
                    0083    213 _DPH	=	0x0083
                    0087    214 G$PCON$0$0 == 0x0087
                    0087    215 _PCON	=	0x0087
                    0088    216 G$TCON$0$0 == 0x0088
                    0088    217 _TCON	=	0x0088
                    0089    218 G$TMOD$0$0 == 0x0089
                    0089    219 _TMOD	=	0x0089
                    008A    220 G$TL0$0$0 == 0x008a
                    008A    221 _TL0	=	0x008a
                    008B    222 G$TL1$0$0 == 0x008b
                    008B    223 _TL1	=	0x008b
                    008C    224 G$TH0$0$0 == 0x008c
                    008C    225 _TH0	=	0x008c
                    008D    226 G$TH1$0$0 == 0x008d
                    008D    227 _TH1	=	0x008d
                    00A8    228 G$IEN0$0$0 == 0x00a8
                    00A8    229 _IEN0	=	0x00a8
                    00B8    230 G$IP0$0$0 == 0x00b8
                    00B8    231 _IP0	=	0x00b8
                    0098    232 G$SCON$0$0 == 0x0098
                    0098    233 _SCON	=	0x0098
                    0099    234 G$SBUF$0$0 == 0x0099
                    0099    235 _SBUF	=	0x0099
                    00A2    236 G$AUXR1$0$0 == 0x00a2
                    00A2    237 _AUXR1	=	0x00a2
                    00A9    238 G$SADDR$0$0 == 0x00a9
                    00A9    239 _SADDR	=	0x00a9
                    00B9    240 G$SADEN$0$0 == 0x00b9
                    00B9    241 _SADEN	=	0x00b9
                    00BE    242 G$BRGR0$0$0 == 0x00be
                    00BE    243 _BRGR0	=	0x00be
                    00BF    244 G$BRGR1$0$0 == 0x00bf
                    00BF    245 _BRGR1	=	0x00bf
                    00BD    246 G$BRGCON$0$0 == 0x00bd
                    00BD    247 _BRGCON	=	0x00bd
                    00AC    248 G$CMP1$0$0 == 0x00ac
                    00AC    249 _CMP1	=	0x00ac
                    00AD    250 G$CMP2$0$0 == 0x00ad
                    00AD    251 _CMP2	=	0x00ad
                    0095    252 G$DIVM$0$0 == 0x0095
                    0095    253 _DIVM	=	0x0095
                    00E7    254 G$FMADRH$0$0 == 0x00e7
                    00E7    255 _FMADRH	=	0x00e7
                    00E6    256 G$FMADRL$0$0 == 0x00e6
                    00E6    257 _FMADRL	=	0x00e6
                    00E4    258 G$FMCON$0$0 == 0x00e4
                    00E4    259 _FMCON	=	0x00e4
                    00E5    260 G$FMDATA$0$0 == 0x00e5
                    00E5    261 _FMDATA	=	0x00e5
                    00DB    262 G$I2ADR$0$0 == 0x00db
                    00DB    263 _I2ADR	=	0x00db
                    00D8    264 G$I2CON$0$0 == 0x00d8
                    00D8    265 _I2CON	=	0x00d8
                    00DA    266 G$I2DAT$0$0 == 0x00da
                    00DA    267 _I2DAT	=	0x00da
                    00DD    268 G$I2SCLH$0$0 == 0x00dd
                    00DD    269 _I2SCLH	=	0x00dd
                    00DC    270 G$I2SCLL$0$0 == 0x00dc
                    00DC    271 _I2SCLL	=	0x00dc
                    00D9    272 G$I2STAT$0$0 == 0x00d9
                    00D9    273 _I2STAT	=	0x00d9
                    00F8    274 G$IP1$0$0 == 0x00f8
                    00F8    275 _IP1	=	0x00f8
                    00F7    276 G$IP1H$0$0 == 0x00f7
                    00F7    277 _IP1H	=	0x00f7
                    0094    278 G$KBCON$0$0 == 0x0094
                    0094    279 _KBCON	=	0x0094
                    0086    280 G$KBMASK$0$0 == 0x0086
                    0086    281 _KBMASK	=	0x0086
                    0093    282 G$KBPATN$0$0 == 0x0093
                    0093    283 _KBPATN	=	0x0093
                    0084    284 G$P0M1$0$0 == 0x0084
                    0084    285 _P0M1	=	0x0084
                    0085    286 G$P0M2$0$0 == 0x0085
                    0085    287 _P0M2	=	0x0085
                    0091    288 G$P1M1$0$0 == 0x0091
                    0091    289 _P1M1	=	0x0091
                    0092    290 G$P1M2$0$0 == 0x0092
                    0092    291 _P1M2	=	0x0092
                    00B1    292 G$P3M1$0$0 == 0x00b1
                    00B1    293 _P3M1	=	0x00b1
                    00B2    294 G$P3M2$0$0 == 0x00b2
                    00B2    295 _P3M2	=	0x00b2
                    00B5    296 G$PCONA$0$0 == 0x00b5
                    00B5    297 _PCONA	=	0x00b5
                    00F6    298 G$PT0AD$0$0 == 0x00f6
                    00F6    299 _PT0AD	=	0x00f6
                    00DF    300 G$RSTSRC$0$0 == 0x00df
                    00DF    301 _RSTSRC	=	0x00df
                    00D1    302 G$RTCCON$0$0 == 0x00d1
                    00D1    303 _RTCCON	=	0x00d1
                    00D2    304 G$RTCH$0$0 == 0x00d2
                    00D2    305 _RTCH	=	0x00d2
                    00D3    306 G$RTCL$0$0 == 0x00d3
                    00D3    307 _RTCL	=	0x00d3
                    00BA    308 G$SSTAT$0$0 == 0x00ba
                    00BA    309 _SSTAT	=	0x00ba
                    008F    310 G$TAMOD$0$0 == 0x008f
                    008F    311 _TAMOD	=	0x008f
                    0096    312 G$TRIM$0$0 == 0x0096
                    0096    313 _TRIM	=	0x0096
                    00A7    314 G$WDCON$0$0 == 0x00a7
                    00A7    315 _WDCON	=	0x00a7
                    00C1    316 G$WDL$0$0 == 0x00c1
                    00C1    317 _WDL	=	0x00c1
                    00C2    318 G$WFEED1$0$0 == 0x00c2
                    00C2    319 _WFEED1	=	0x00c2
                    00C3    320 G$WFEED2$0$0 == 0x00c3
                    00C3    321 _WFEED2	=	0x00c3
                    00B7    322 G$IP0H$0$0 == 0x00b7
                    00B7    323 _IP0H	=	0x00b7
                    00E8    324 G$IEN1$0$0 == 0x00e8
                    00E8    325 _IEN1	=	0x00e8
                            326 ;--------------------------------------------------------
                            327 ; special function bits
                            328 ;--------------------------------------------------------
                            329 	.area RSEG    (ABS,DATA)
   0000                     330 	.org 0x0000
                    00D0    331 G$PSW_0$0$0 == 0x00d0
                    00D0    332 _PSW_0	=	0x00d0
                    00D1    333 G$PSW_1$0$0 == 0x00d1
                    00D1    334 _PSW_1	=	0x00d1
                    00D2    335 G$PSW_2$0$0 == 0x00d2
                    00D2    336 _PSW_2	=	0x00d2
                    00D3    337 G$PSW_3$0$0 == 0x00d3
                    00D3    338 _PSW_3	=	0x00d3
                    00D4    339 G$PSW_4$0$0 == 0x00d4
                    00D4    340 _PSW_4	=	0x00d4
                    00D5    341 G$PSW_5$0$0 == 0x00d5
                    00D5    342 _PSW_5	=	0x00d5
                    00D6    343 G$PSW_6$0$0 == 0x00d6
                    00D6    344 _PSW_6	=	0x00d6
                    00D7    345 G$PSW_7$0$0 == 0x00d7
                    00D7    346 _PSW_7	=	0x00d7
                    008F    347 G$TCON_7$0$0 == 0x008f
                    008F    348 _TCON_7	=	0x008f
                    008E    349 G$TCON_6$0$0 == 0x008e
                    008E    350 _TCON_6	=	0x008e
                    008D    351 G$TCON_5$0$0 == 0x008d
                    008D    352 _TCON_5	=	0x008d
                    008C    353 G$TCON_4$0$0 == 0x008c
                    008C    354 _TCON_4	=	0x008c
                    008B    355 G$TCON_3$0$0 == 0x008b
                    008B    356 _TCON_3	=	0x008b
                    008A    357 G$TCON_2$0$0 == 0x008a
                    008A    358 _TCON_2	=	0x008a
                    0089    359 G$TCON_1$0$0 == 0x0089
                    0089    360 _TCON_1	=	0x0089
                    0088    361 G$TCON_0$0$0 == 0x0088
                    0088    362 _TCON_0	=	0x0088
                    00AF    363 G$IEN0_7$0$0 == 0x00af
                    00AF    364 _IEN0_7	=	0x00af
                    00AE    365 G$IEN0_6$0$0 == 0x00ae
                    00AE    366 _IEN0_6	=	0x00ae
                    00AD    367 G$IEN0_5$0$0 == 0x00ad
                    00AD    368 _IEN0_5	=	0x00ad
                    00AC    369 G$IEN0_4$0$0 == 0x00ac
                    00AC    370 _IEN0_4	=	0x00ac
                    00AB    371 G$IEN0_3$0$0 == 0x00ab
                    00AB    372 _IEN0_3	=	0x00ab
                    00AA    373 G$IEN0_2$0$0 == 0x00aa
                    00AA    374 _IEN0_2	=	0x00aa
                    00A9    375 G$IEN0_1$0$0 == 0x00a9
                    00A9    376 _IEN0_1	=	0x00a9
                    00A8    377 G$IEN0_0$0$0 == 0x00a8
                    00A8    378 _IEN0_0	=	0x00a8
                    00EA    379 G$IEN1_2$0$0 == 0x00ea
                    00EA    380 _IEN1_2	=	0x00ea
                    00E9    381 G$IEN1_1$0$0 == 0x00e9
                    00E9    382 _IEN1_1	=	0x00e9
                    00E8    383 G$IEN1_0$0$0 == 0x00e8
                    00E8    384 _IEN1_0	=	0x00e8
                    00FE    385 G$IP1_6$0$0 == 0x00fe
                    00FE    386 _IP1_6	=	0x00fe
                    00FA    387 G$IP1_2$0$0 == 0x00fa
                    00FA    388 _IP1_2	=	0x00fa
                    00F9    389 G$IP1_1$0$0 == 0x00f9
                    00F9    390 _IP1_1	=	0x00f9
                    00F8    391 G$IP1_0$0$0 == 0x00f8
                    00F8    392 _IP1_0	=	0x00f8
                    00BE    393 G$IP0_6$0$0 == 0x00be
                    00BE    394 _IP0_6	=	0x00be
                    00BD    395 G$IP0_5$0$0 == 0x00bd
                    00BD    396 _IP0_5	=	0x00bd
                    00BC    397 G$IP0_4$0$0 == 0x00bc
                    00BC    398 _IP0_4	=	0x00bc
                    00BB    399 G$IP0_3$0$0 == 0x00bb
                    00BB    400 _IP0_3	=	0x00bb
                    00BA    401 G$IP0_2$0$0 == 0x00ba
                    00BA    402 _IP0_2	=	0x00ba
                    00B9    403 G$IP0_1$0$0 == 0x00b9
                    00B9    404 _IP0_1	=	0x00b9
                    00B8    405 G$IP0_0$0$0 == 0x00b8
                    00B8    406 _IP0_0	=	0x00b8
                    0098    407 G$SCON_0$0$0 == 0x0098
                    0098    408 _SCON_0	=	0x0098
                    0099    409 G$SCON_1$0$0 == 0x0099
                    0099    410 _SCON_1	=	0x0099
                    009A    411 G$SCON_2$0$0 == 0x009a
                    009A    412 _SCON_2	=	0x009a
                    009B    413 G$SCON_3$0$0 == 0x009b
                    009B    414 _SCON_3	=	0x009b
                    009C    415 G$SCON_4$0$0 == 0x009c
                    009C    416 _SCON_4	=	0x009c
                    009D    417 G$SCON_5$0$0 == 0x009d
                    009D    418 _SCON_5	=	0x009d
                    009E    419 G$SCON_6$0$0 == 0x009e
                    009E    420 _SCON_6	=	0x009e
                    009F    421 G$SCON_7$0$0 == 0x009f
                    009F    422 _SCON_7	=	0x009f
                    00DE    423 G$I2CON_6$0$0 == 0x00de
                    00DE    424 _I2CON_6	=	0x00de
                    00DD    425 G$I2CON_5$0$0 == 0x00dd
                    00DD    426 _I2CON_5	=	0x00dd
                    00DC    427 G$I2CON_4$0$0 == 0x00dc
                    00DC    428 _I2CON_4	=	0x00dc
                    00DB    429 G$I2CON_3$0$0 == 0x00db
                    00DB    430 _I2CON_3	=	0x00db
                    00DA    431 G$I2CON_2$0$0 == 0x00da
                    00DA    432 _I2CON_2	=	0x00da
                    00D8    433 G$I2CON_0$0$0 == 0x00d8
                    00D8    434 _I2CON_0	=	0x00d8
                    0080    435 G$P0_0$0$0 == 0x0080
                    0080    436 _P0_0	=	0x0080
                    0081    437 G$P0_1$0$0 == 0x0081
                    0081    438 _P0_1	=	0x0081
                    0082    439 G$P0_2$0$0 == 0x0082
                    0082    440 _P0_2	=	0x0082
                    0083    441 G$P0_3$0$0 == 0x0083
                    0083    442 _P0_3	=	0x0083
                    0084    443 G$P0_4$0$0 == 0x0084
                    0084    444 _P0_4	=	0x0084
                    0085    445 G$P0_5$0$0 == 0x0085
                    0085    446 _P0_5	=	0x0085
                    0086    447 G$P0_6$0$0 == 0x0086
                    0086    448 _P0_6	=	0x0086
                    0087    449 G$P0_7$0$0 == 0x0087
                    0087    450 _P0_7	=	0x0087
                    0090    451 G$P1_0$0$0 == 0x0090
                    0090    452 _P1_0	=	0x0090
                    0091    453 G$P1_1$0$0 == 0x0091
                    0091    454 _P1_1	=	0x0091
                    0092    455 G$P1_2$0$0 == 0x0092
                    0092    456 _P1_2	=	0x0092
                    0093    457 G$P1_3$0$0 == 0x0093
                    0093    458 _P1_3	=	0x0093
                    0094    459 G$P1_4$0$0 == 0x0094
                    0094    460 _P1_4	=	0x0094
                    0095    461 G$P1_5$0$0 == 0x0095
                    0095    462 _P1_5	=	0x0095
                    0096    463 G$P1_6$0$0 == 0x0096
                    0096    464 _P1_6	=	0x0096
                    0097    465 G$P1_7$0$0 == 0x0097
                    0097    466 _P1_7	=	0x0097
                    00B0    467 G$P3_0$0$0 == 0x00b0
                    00B0    468 _P3_0	=	0x00b0
                    00B1    469 G$P3_1$0$0 == 0x00b1
                    00B1    470 _P3_1	=	0x00b1
                            471 ;--------------------------------------------------------
                            472 ; overlayable register banks
                            473 ;--------------------------------------------------------
                            474 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     475 	.ds 8
                            476 ;--------------------------------------------------------
                            477 ; overlayable bit register bank
                            478 ;--------------------------------------------------------
                            479 	.area BIT_BANK	(REL,OVR,DATA)
   0023                     480 bits:
   0023                     481 	.ds 1
                    8000    482 	b0 = bits[0]
                    8100    483 	b1 = bits[1]
                    8200    484 	b2 = bits[2]
                    8300    485 	b3 = bits[3]
                    8400    486 	b4 = bits[4]
                    8500    487 	b5 = bits[5]
                    8600    488 	b6 = bits[6]
                    8700    489 	b7 = bits[7]
                            490 ;--------------------------------------------------------
                            491 ; internal ram data
                            492 ;--------------------------------------------------------
                            493 	.area DSEG    (DATA)
                    0000    494 G$portbuffer$0$0==.
   0024                     495 _portbuffer::
   0024                     496 	.ds 1
                    0001    497 G$p0h$0$0==.
   0025                     498 _p0h::
   0025                     499 	.ds 1
                    0002    500 G$objstate$0$0==.
   0026                     501 _objstate::
   0026                     502 	.ds 2
                    0004    503 G$timer_base$0$0==.
   0028                     504 _timer_base::
   0028                     505 	.ds 1
                    0005    506 G$timer_state$0$0==.
   0029                     507 _timer_state::
   0029                     508 	.ds 1
                    0006    509 G$timer500$0$0==.
   002A                     510 _timer500::
   002A                     511 	.ds 1
                    0007    512 G$timer60$0$0==.
   002B                     513 _timer60::
   002B                     514 	.ds 1
                    0008    515 G$timerhour$0$0==.
   002C                     516 _timerhour::
   002C                     517 	.ds 1
                    0009    518 G$timerday$0$0==.
   002D                     519 _timerday::
   002D                     520 	.ds 1
                    000A    521 G$timerflags$0$0==.
   002E                     522 _timerflags::
   002E                     523 	.ds 1
                    000B    524 G$timerbase$0$0==.
   002F                     525 _timerbase::
   002F                     526 	.ds 4
                    000F    527 G$timercnt$0$0==.
   0033                     528 _timercnt::
   0033                     529 	.ds 4
                    0013    530 G$para_value$0$0==.
   0037                     531 _para_value::
   0037                     532 	.ds 1
                    0008    533 G$counter_summe$0$0 == 0x0008
                    0008    534 _counter_summe	=	0x0008
                    0018    535 G$counter_moment$0$0 == 0x0018
                    0018    536 _counter_moment	=	0x0018
                    0014    537 G$bitobj_z1$0$0==.
   0038                     538 _bitobj_z1::
   0038                     539 	.ds 2
                    0016    540 G$bitobj_z2$0$0==.
   003A                     541 _bitobj_z2::
   003A                     542 	.ds 2
                    0018    543 G$precounter0$0$0==.
   003C                     544 _precounter0::
   003C                     545 	.ds 1
                    0019    546 G$precounter1$0$0==.
   003D                     547 _precounter1::
   003D                     548 	.ds 1
                            549 ;--------------------------------------------------------
                            550 ; overlayable items in internal ram 
                            551 ;--------------------------------------------------------
                            552 	.area OSEG    (OVR,DATA)
                            553 ;--------------------------------------------------------
                            554 ; indirectly addressable internal ram data
                            555 ;--------------------------------------------------------
                            556 	.area ISEG    (DATA)
                            557 ;--------------------------------------------------------
                            558 ; absolute internal ram data
                            559 ;--------------------------------------------------------
                            560 	.area IABS    (ABS,DATA)
                            561 	.area IABS    (ABS,DATA)
                            562 ;--------------------------------------------------------
                            563 ; bit data
                            564 ;--------------------------------------------------------
                            565 	.area BSEG    (BIT)
                    0000    566 G$objval$0$0==.
   0000                     567 _objval::
   0000                     568 	.ds 1
                    0001    569 G$jobj$0$0==.
   0001                     570 _jobj::
   0001                     571 	.ds 1
                    0002    572 G$st_Flanke$0$0==.
   0002                     573 _st_Flanke::
   0002                     574 	.ds 1
                    0003    575 G$counted0$0$0==.
   0003                     576 _counted0::
   0003                     577 	.ds 1
                    0004    578 G$counted1$0$0==.
   0004                     579 _counted1::
   0004                     580 	.ds 1
                            581 ;--------------------------------------------------------
                            582 ; paged external ram data
                            583 ;--------------------------------------------------------
                            584 	.area PSEG    (PAG,XDATA)
                            585 ;--------------------------------------------------------
                            586 ; external ram data
                            587 ;--------------------------------------------------------
                            588 	.area XSEG    (XDATA)
                            589 ;--------------------------------------------------------
                            590 ; absolute external ram data
                            591 ;--------------------------------------------------------
                            592 	.area XABS    (ABS,XDATA)
                            593 ;--------------------------------------------------------
                            594 ; external initialized ram data
                            595 ;--------------------------------------------------------
                            596 	.area XISEG   (XDATA)
                            597 	.area HOME    (CODE)
                            598 	.area GSINIT0 (CODE)
                            599 	.area GSINIT1 (CODE)
                            600 	.area GSINIT2 (CODE)
                            601 	.area GSINIT3 (CODE)
                            602 	.area GSINIT4 (CODE)
                            603 	.area GSINIT5 (CODE)
                            604 	.area GSINIT  (CODE)
                            605 	.area GSFINAL (CODE)
                            606 	.area CSEG    (CODE)
                            607 ;--------------------------------------------------------
                            608 ; global & static initialisations
                            609 ;--------------------------------------------------------
                            610 	.area HOME    (CODE)
                            611 	.area GSINIT  (CODE)
                            612 	.area GSFINAL (CODE)
                            613 	.area GSINIT  (CODE)
                    0000    614 	G$restart_app$0$0 ==.
                    0000    615 	C$fb_app_counter.c$49$1$1 ==.
                            616 ;	..\fb_app_counter.c:49: __bit objval=0,jobj=0;
   009C C2 00               617 	clr	_objval
                    0002    618 	G$restart_app$0$0 ==.
                    0002    619 	C$fb_app_counter.c$49$1$1 ==.
                            620 ;	..\fb_app_counter.c:49: 
   009E C2 01               621 	clr	_jobj
                    0004    622 	G$restart_app$0$0 ==.
                    0004    623 	C$fb_app_counter.c$51$1$1 ==.
                            624 ;	..\fb_app_counter.c:51: __bit st_Flanke=0;
   00A0 C2 02               625 	clr	_st_Flanke
                            626 ;--------------------------------------------------------
                            627 ; Home
                            628 ;--------------------------------------------------------
                            629 	.area HOME    (CODE)
                            630 	.area HOME    (CODE)
                            631 ;--------------------------------------------------------
                            632 ; code
                            633 ;--------------------------------------------------------
                            634 	.area CSEG    (CODE)
                            635 ;------------------------------------------------------------
                            636 ;Allocation info for local variables in function 'keypad_isr'
                            637 ;------------------------------------------------------------
                            638 ;keybuffer                 Allocated to registers r7 
                            639 ;------------------------------------------------------------
                    0000    640 	G$keypad_isr$0$0 ==.
                    0000    641 	C$fb_app_counter.c$61$0$0 ==.
                            642 ;	..\fb_app_counter.c:61: void keypad_isr  (void) __interrupt (7)
                            643 ;	-----------------------------------------
                            644 ;	 function keypad_isr
                            645 ;	-----------------------------------------
   03EF                     646 _keypad_isr:
                    0007    647 	ar7 = 0x07
                    0006    648 	ar6 = 0x06
                    0005    649 	ar5 = 0x05
                    0004    650 	ar4 = 0x04
                    0003    651 	ar3 = 0x03
                    0002    652 	ar2 = 0x02
                    0001    653 	ar1 = 0x01
                    0000    654 	ar0 = 0x00
   03EF C0 E0               655 	push	acc
   03F1 C0 07               656 	push	ar7
   03F3 C0 D0               657 	push	psw
   03F5 75 D0 00            658 	mov	psw,#0x00
                    0009    659 	C$fb_app_counter.c$65$1$1 ==.
                            660 ;	..\fb_app_counter.c:65: KBCON = 0;//0xFE;
   03F8 75 94 00            661 	mov	_KBCON,#0x00
                    000C    662 	C$fb_app_counter.c$66$1$1 ==.
                            663 ;	..\fb_app_counter.c:66: keybuffer=P0;
                    000C    664 	C$fb_app_counter.c$67$1$1 ==.
                            665 ;	..\fb_app_counter.c:67: if(keybuffer&0x01 && !counted0){
   03FB E5 80               666 	mov	a,_P0
   03FD FF                  667 	mov	r7,a
   03FE 30 E0 07            668 	jnb	acc.0,00102$
   0401 20 03 04            669 	jb	_counted0,00102$
                    0015    670 	C$fb_app_counter.c$68$2$2 ==.
                            671 ;	..\fb_app_counter.c:68: precounter0++;
   0404 05 3C               672 	inc	_precounter0
                    0017    673 	C$fb_app_counter.c$69$2$2 ==.
                            674 ;	..\fb_app_counter.c:69: counted0=1;
   0406 D2 03               675 	setb	_counted0
   0408                     676 00102$:
                    0019    677 	C$fb_app_counter.c$71$1$1 ==.
                            678 ;	..\fb_app_counter.c:71: if(!(keybuffer&0x01))counted0=0;
   0408 EF                  679 	mov	a,r7
   0409 20 E0 02            680 	jb	acc.0,00105$
   040C C2 03               681 	clr	_counted0
   040E                     682 00105$:
                    001F    683 	C$fb_app_counter.c$73$1$1 ==.
                            684 ;	..\fb_app_counter.c:73: if(keybuffer&0x04 && !counted1){
   040E EF                  685 	mov	a,r7
   040F 30 E2 07            686 	jnb	acc.2,00107$
   0412 20 04 04            687 	jb	_counted1,00107$
                    0026    688 	C$fb_app_counter.c$74$2$3 ==.
                            689 ;	..\fb_app_counter.c:74: precounter1++;
   0415 05 3D               690 	inc	_precounter1
                    0028    691 	C$fb_app_counter.c$75$2$3 ==.
                            692 ;	..\fb_app_counter.c:75: counted1=1;
   0417 D2 04               693 	setb	_counted1
   0419                     694 00107$:
                    002A    695 	C$fb_app_counter.c$77$1$1 ==.
                            696 ;	..\fb_app_counter.c:77: if(!(keybuffer&0x04))counted1=0;
   0419 EF                  697 	mov	a,r7
   041A 20 E2 02            698 	jb	acc.2,00110$
   041D C2 04               699 	clr	_counted1
   041F                     700 00110$:
                    0030    701 	C$fb_app_counter.c$78$1$1 ==.
                            702 ;	..\fb_app_counter.c:78: KBPATN=keybuffer;
   041F 8F 93               703 	mov	_KBPATN,r7
   0421 D0 D0               704 	pop	psw
   0423 D0 07               705 	pop	ar7
   0425 D0 E0               706 	pop	acc
                    0038    707 	C$fb_app_counter.c$79$1$1 ==.
                    0038    708 	XG$keypad_isr$0$0 ==.
   0427 32                  709 	reti
                            710 ;	eliminated unneeded push/pop ar1
                            711 ;	eliminated unneeded push/pop ar0
                            712 ;	eliminated unneeded push/pop dpl
                            713 ;	eliminated unneeded push/pop dph
                            714 ;	eliminated unneeded push/pop b
                            715 ;------------------------------------------------------------
                            716 ;Allocation info for local variables in function 'pin_changed'
                            717 ;------------------------------------------------------------
                            718 ;pinno                     Allocated to registers r7 
                            719 ;tmp                       Allocated to registers 
                            720 ;objoffset                 Allocated to registers r6 
                            721 ;cno                       Allocated to registers r6 
                            722 ;typ                       Allocated to registers 
                            723 ;n                         Allocated to registers r6 
                            724 ;w                         Allocated to registers r5 
                            725 ;deb_result                Allocated to registers r6 
                            726 ;------------------------------------------------------------
                    0039    727 	G$pin_changed$0$0 ==.
                    0039    728 	C$fb_app_counter.c$82$1$1 ==.
                            729 ;	..\fb_app_counter.c:82: void pin_changed(unsigned char pinno)
                            730 ;	-----------------------------------------
                            731 ;	 function pin_changed
                            732 ;	-----------------------------------------
   0428                     733 _pin_changed:
   0428 AF 82               734 	mov	r7,dpl
                    003B    735 	C$fb_app_counter.c$90$1$1 ==.
                            736 ;	..\fb_app_counter.c:90: timer_base=0; tmp;
   042A 75 28 00            737 	mov	_timer_base,#0x00
                    003E    738 	C$fb_app_counter.c$91$1$1 ==.
                            739 ;	..\fb_app_counter.c:91: para_value=0;
   042D 75 37 00            740 	mov	_para_value,#0x00
                    0041    741 	C$fb_app_counter.c$93$1$1 ==.
                            742 ;	..\fb_app_counter.c:93: for(n=0;n<250;n++){
   0430 7E 00               743 	mov	r6,#0x00
   0432                     744 00110$:
   0432 BE FA 00            745 	cjne	r6,#0xFA,00131$
   0435                     746 00131$:
   0435 50 14               747 	jnc	00113$
                    0048    748 	C$fb_app_counter.c$94$1$1 ==.
                            749 ;	..\fb_app_counter.c:94: for(w=255;w>0;w--); 
   0437 7D FF               750 	mov	r5,#0xFF
   0439                     751 00106$:
   0439 ED                  752 	mov	a,r5
   043A 60 04               753 	jz	00116$
   043C 7C 01               754 	mov	r4,#0x01
   043E 80 02               755 	sjmp	00117$
   0440                     756 00116$:
   0440 7C 00               757 	mov	r4,#0x00
   0442                     758 00117$:
   0442 EC                  759 	mov	a,r4
   0443 60 03               760 	jz	00112$
   0445 1D                  761 	dec	r5
   0446 80 F1               762 	sjmp	00106$
   0448                     763 00112$:
                    0059    764 	C$fb_app_counter.c$93$1$1 ==.
                            765 ;	..\fb_app_counter.c:93: for(n=0;n<250;n++){
   0448 0E                  766 	inc	r6
   0449 80 E7               767 	sjmp	00110$
   044B                     768 00113$:
                    005C    769 	C$fb_app_counter.c$97$1$1 ==.
                            770 ;	..\fb_app_counter.c:97: deb_result=((~(P0^p0h))& bitmask_1[pinno]);//ret=1;
   044B E5 25               771 	mov	a,_p0h
   044D 65 80               772 	xrl	a,_P0
   044F F4                  773 	cpl	a
   0450 FE                  774 	mov	r6,a
   0451 EF                  775 	mov	a,r7
   0452 90 1C 6A            776 	mov	dptr,#_bitmask_1
   0455 93                  777 	movc	a,@a+dptr
   0456 FD                  778 	mov	r5,a
   0457 52 06               779 	anl	ar6,a
                    006A    780 	C$fb_app_counter.c$102$1$1 ==.
                            781 ;	..\fb_app_counter.c:102: if (deb_result)			// Entprellzeit abwarten und prüfen
   0459 EE                  782 	mov	a,r6
   045A 60 72               783 	jz	00114$
                    006D    784 	C$fb_app_counter.c$104$2$3 ==.
                            785 ;	..\fb_app_counter.c:104: st_Flanke=(((portbuffer>>pinno)&0x01)==0) && (((p0h>>pinno)&0x01)==1);
   045C 8F F0               786 	mov	b,r7
   045E 05 F0               787 	inc	b
   0460 E5 24               788 	mov	a,_portbuffer
   0462 80 02               789 	sjmp	00137$
   0464                     790 00136$:
   0464 C3                  791 	clr	c
   0465 13                  792 	rrc	a
   0466                     793 00137$:
   0466 D5 F0 FB            794 	djnz	b,00136$
   0469 54 01               795 	anl	a,#0x01
   046B FE                  796 	mov	r6,a
   046C B4 01 00            797 	cjne	a,#0x01,00138$
   046F                     798 00138$:
   046F E4                  799 	clr	a
   0470 33                  800 	rlc	a
   0471 FE                  801 	mov	r6,a
   0472 60 15               802 	jz	00118$
   0474 8F F0               803 	mov	b,r7
   0476 05 F0               804 	inc	b
   0478 E5 25               805 	mov	a,_p0h
   047A 80 02               806 	sjmp	00141$
   047C                     807 00140$:
   047C C3                  808 	clr	c
   047D 13                  809 	rrc	a
   047E                     810 00141$:
   047E D5 F0 FB            811 	djnz	b,00140$
   0481 54 01               812 	anl	a,#0x01
   0483 FE                  813 	mov	r6,a
   0484 BE 01 02            814 	cjne	r6,#0x01,00142$
   0487 80 04               815 	sjmp	00119$
   0489                     816 00142$:
   0489                     817 00118$:
   0489 C2 18               818 	clr	b0
   048B 80 02               819 	sjmp	00120$
   048D                     820 00119$:
   048D D2 18               821 	setb	b0
   048F                     822 00120$:
   048F A2 18               823 	mov	c,b0
   0491 92 02               824 	mov	_st_Flanke,c
                    00A4    825 	C$fb_app_counter.c$105$2$3 ==.
                            826 ;	..\fb_app_counter.c:105: cno=(pinno&0x02);// counter nomber 0 0der 2
   0493 74 02               827 	mov	a,#0x02
   0495 5F                  828 	anl	a,r7
                    00A7    829 	C$fb_app_counter.c$106$2$3 ==.
                            830 ;	..\fb_app_counter.c:106: objoffset=13*(cno>>1);
   0496 C3                  831 	clr	c
   0497 13                  832 	rrc	a
   0498 75 F0 0D            833 	mov	b,#0x0D
   049B A4                  834 	mul	ab
   049C FE                  835 	mov	r6,a
                    00AE    836 	C$fb_app_counter.c$107$2$3 ==.
                            837 ;	..\fb_app_counter.c:107: if ((pinno==1)||(pinno==3)){
   049D BF 01 02            838 	cjne	r7,#0x01,00143$
   04A0 80 03               839 	sjmp	00101$
   04A2                     840 00143$:
   04A2 BF 03 29            841 	cjne	r7,#0x03,00114$
   04A5                     842 00101$:
                    00B6    843 	C$fb_app_counter.c$108$3$4 ==.
                            844 ;	..\fb_app_counter.c:108: write_obj_value(2+objoffset,st_Flanke);
   04A5 A2 02               845 	mov	c,_st_Flanke
   04A7 E4                  846 	clr	a
   04A8 33                  847 	rlc	a
   04A9 FB                  848 	mov	r3,a
   04AA 7C 00               849 	mov	r4,#0x00
   04AC 7D 00               850 	mov	r5,#0x00
   04AE 7F 00               851 	mov	r7,#0x00
   04B0 0E                  852 	inc	r6
   04B1 0E                  853 	inc	r6
   04B2 C0 06               854 	push	ar6
   04B4 C0 03               855 	push	ar3
   04B6 C0 04               856 	push	ar4
   04B8 C0 05               857 	push	ar5
   04BA C0 07               858 	push	ar7
   04BC 8E 82               859 	mov	dpl,r6
   04BE 12 0F 60            860 	lcall	_write_obj_value
   04C1 E5 81               861 	mov	a,sp
   04C3 24 FC               862 	add	a,#0xfc
   04C5 F5 81               863 	mov	sp,a
   04C7 D0 06               864 	pop	ar6
                    00DA    865 	C$fb_app_counter.c$109$3$4 ==.
                            866 ;	..\fb_app_counter.c:109: send_obj_value(2+objoffset);
   04C9 8E 82               867 	mov	dpl,r6
   04CB 12 18 29            868 	lcall	_send_obj_value
   04CE                     869 00114$:
                    00DF    870 	C$fb_app_counter.c$114$1$1 ==.
                    00DF    871 	XG$pin_changed$0$0 ==.
   04CE 22                  872 	ret
                            873 ;------------------------------------------------------------
                            874 ;Allocation info for local variables in function 'eis5conversion'
                            875 ;------------------------------------------------------------
                            876 ;zahl                      Allocated to registers r4 r5 r6 r7 
                            877 ;exp                       Allocated to registers r3 
                            878 ;------------------------------------------------------------
                    00E0    879 	G$eis5conversion$0$0 ==.
                    00E0    880 	C$fb_app_counter.c$121$1$1 ==.
                            881 ;	..\fb_app_counter.c:121: int eis5conversion(unsigned long zahl)// wandelt 32 bit var in eis5 um
                            882 ;	-----------------------------------------
                            883 ;	 function eis5conversion
                            884 ;	-----------------------------------------
   04CF                     885 _eis5conversion:
   04CF AC 82               886 	mov	r4,dpl
   04D1 AD 83               887 	mov	r5,dph
   04D3 AE F0               888 	mov	r6,b
   04D5 FF                  889 	mov	r7,a
                    00E7    890 	C$fb_app_counter.c$124$1$1 ==.
                            891 ;	..\fb_app_counter.c:124: while (zahl > 2047){//solange Mantisse größer 11 Bit
   04D6 7B 00               892 	mov	r3,#0x00
   04D8                     893 00101$:
   04D8 ED                  894 	mov	a,r5
   04D9 54 F8               895 	anl	a,#0xF8
   04DB 70 06               896 	jnz	00109$
   04DD EE                  897 	mov	a,r6
   04DE 70 03               898 	jnz	00109$
   04E0 EF                  899 	mov	a,r7
   04E1 60 10               900 	jz	00103$
   04E3                     901 00109$:
                    00F4    902 	C$fb_app_counter.c$125$2$2 ==.
                            903 ;	..\fb_app_counter.c:125: zahl=zahl>>1;// Mantisse /2
   04E3 EF                  904 	mov	a,r7
   04E4 C3                  905 	clr	c
   04E5 13                  906 	rrc	a
   04E6 FF                  907 	mov	r7,a
   04E7 EE                  908 	mov	a,r6
   04E8 13                  909 	rrc	a
   04E9 FE                  910 	mov	r6,a
   04EA ED                  911 	mov	a,r5
   04EB 13                  912 	rrc	a
   04EC FD                  913 	mov	r5,a
   04ED EC                  914 	mov	a,r4
   04EE 13                  915 	rrc	a
   04EF FC                  916 	mov	r4,a
                    0101    917 	C$fb_app_counter.c$126$2$2 ==.
                            918 ;	..\fb_app_counter.c:126: exp++;// und exponent um 1 erhöhen (ist ein 2^exp)
   04F0 0B                  919 	inc	r3
   04F1 80 E5               920 	sjmp	00101$
   04F3                     921 00103$:
                    0104    922 	C$fb_app_counter.c$129$1$1 ==.
                            923 ;	..\fb_app_counter.c:129: return ((int)zahl+((int)exp<<11));// exponent dazu.
   04F3 EB                  924 	mov	a,r3
   04F4 C4                  925 	swap	a
   04F5 03                  926 	rr	a
   04F6 54 F8               927 	anl	a,#0xF8
   04F8 FF                  928 	mov	r7,a
   04F9 E4                  929 	clr	a
   04FA 2C                  930 	add	a,r4
   04FB F5 82               931 	mov	dpl,a
   04FD EF                  932 	mov	a,r7
   04FE 3D                  933 	addc	a,r5
   04FF F5 83               934 	mov	dph,a
                    0112    935 	C$fb_app_counter.c$130$1$1 ==.
                    0112    936 	XG$eis5conversion$0$0 ==.
   0501 22                  937 	ret
                            938 ;------------------------------------------------------------
                            939 ;Allocation info for local variables in function 'delay_timer'
                            940 ;------------------------------------------------------------
                            941 ;m                         Allocated to registers r6 
                            942 ;objno                     Allocated to registers r7 
                            943 ;n                         Allocated to registers r7 
                            944 ;------------------------------------------------------------
                    0113    945 	G$delay_timer$0$0 ==.
                    0113    946 	C$fb_app_counter.c$138$1$1 ==.
                            947 ;	..\fb_app_counter.c:138: void delay_timer(void)
                            948 ;	-----------------------------------------
                            949 ;	 function delay_timer
                            950 ;	-----------------------------------------
   0502                     951 _delay_timer:
                    0113    952 	C$fb_app_counter.c$145$1$1 ==.
                            953 ;	..\fb_app_counter.c:145: RTCCON=0x61;//	 RTC flag löschen
   0502 75 D1 61            954 	mov	_RTCCON,#0x61
                    0116    955 	C$fb_app_counter.c$147$1$1 ==.
                            956 ;	..\fb_app_counter.c:147: timerflags=0x01;//setzt das niedrigste bit 0  100ms base
   0505 75 2E 01            957 	mov	_timerflags,#0x01
                    0119    958 	C$fb_app_counter.c$149$1$1 ==.
                            959 ;	..\fb_app_counter.c:149: timer500++;// 500ms timer erhöhen
   0508 05 2A               960 	inc	_timer500
                    011B    961 	C$fb_app_counter.c$151$1$1 ==.
                            962 ;	..\fb_app_counter.c:151: if(timer500==5||timer500==10){
   050A 74 05               963 	mov	a,#0x05
   050C B5 2A 02            964 	cjne	a,_timer500,00168$
   050F 80 05               965 	sjmp	00101$
   0511                     966 00168$:
   0511 74 0A               967 	mov	a,#0x0A
   0513 B5 2A 03            968 	cjne	a,_timer500,00102$
   0516                     969 00101$:
                    0127    970 	C$fb_app_counter.c$152$2$2 ==.
                            971 ;	..\fb_app_counter.c:152: timerflags|=0x02;//bit 1 500ms base
   0516 75 2E 03            972 	mov	_timerflags,#0x03
   0519                     973 00102$:
                    012A    974 	C$fb_app_counter.c$154$1$1 ==.
                            975 ;	..\fb_app_counter.c:154: if(timer500>=10){
   0519 74 F6               976 	mov	a,#0x100 - 0x0A
   051B 25 2A               977 	add	a,_timer500
   051D 50 08               978 	jnc	00105$
                    0130    979 	C$fb_app_counter.c$155$2$3 ==.
                            980 ;	..\fb_app_counter.c:155: timerflags|=0x04;//bit 2 1s base
   051F 43 2E 04            981 	orl	_timerflags,#0x04
                    0133    982 	C$fb_app_counter.c$156$2$3 ==.
                            983 ;	..\fb_app_counter.c:156: timer500=0;
   0522 75 2A 00            984 	mov	_timer500,#0x00
                    0136    985 	C$fb_app_counter.c$157$2$3 ==.
                            986 ;	..\fb_app_counter.c:157: timer60++;
   0525 05 2B               987 	inc	_timer60
   0527                     988 00105$:
                    0138    989 	C$fb_app_counter.c$160$1$1 ==.
                            990 ;	..\fb_app_counter.c:160: if(timer60>=60){	// bit 3 1min base
   0527 74 C4               991 	mov	a,#0x100 - 0x3C
   0529 25 2B               992 	add	a,_timer60
   052B 50 08               993 	jnc	00107$
                    013E    994 	C$fb_app_counter.c$161$2$4 ==.
                            995 ;	..\fb_app_counter.c:161: timerflags|=0x08;
   052D 43 2E 08            996 	orl	_timerflags,#0x08
                    0141    997 	C$fb_app_counter.c$162$2$4 ==.
                            998 ;	..\fb_app_counter.c:162: timer60=0;
   0530 75 2B 00            999 	mov	_timer60,#0x00
                    0144   1000 	C$fb_app_counter.c$163$2$4 ==.
                           1001 ;	..\fb_app_counter.c:163: timerhour++;
   0533 05 2C              1002 	inc	_timerhour
   0535                    1003 00107$:
                    0146   1004 	C$fb_app_counter.c$166$1$1 ==.
                           1005 ;	..\fb_app_counter.c:166: if((timerhour>=60)){	// bit 4 1hour base
   0535 74 C4              1006 	mov	a,#0x100 - 0x3C
   0537 25 2C              1007 	add	a,_timerhour
   0539 50 08              1008 	jnc	00109$
                    014C   1009 	C$fb_app_counter.c$167$2$5 ==.
                           1010 ;	..\fb_app_counter.c:167: timerflags|=0x10;
   053B 43 2E 10           1011 	orl	_timerflags,#0x10
                    014F   1012 	C$fb_app_counter.c$168$2$5 ==.
                           1013 ;	..\fb_app_counter.c:168: timerhour=0;
   053E 75 2C 00           1014 	mov	_timerhour,#0x00
                    0152   1015 	C$fb_app_counter.c$169$2$5 ==.
                           1016 ;	..\fb_app_counter.c:169: timerday++;
   0541 05 2D              1017 	inc	_timerday
   0543                    1018 00109$:
                    0154   1019 	C$fb_app_counter.c$171$1$1 ==.
                           1020 ;	..\fb_app_counter.c:171: if((timerday>=24)){	// bit 5 1day base
   0543 74 E8              1021 	mov	a,#0x100 - 0x18
   0545 25 2D              1022 	add	a,_timerday
   0547 50 06              1023 	jnc	00111$
                    015A   1024 	C$fb_app_counter.c$172$2$6 ==.
                           1025 ;	..\fb_app_counter.c:172: timerflags|=0x20;
   0549 43 2E 20           1026 	orl	_timerflags,#0x20
                    015D   1027 	C$fb_app_counter.c$173$2$6 ==.
                           1028 ;	..\fb_app_counter.c:173: timerday=0;
   054C 75 2D 00           1029 	mov	_timerday,#0x00
   054F                    1030 00111$:
                    0160   1031 	C$fb_app_counter.c$175$1$1 ==.
                           1032 ;	..\fb_app_counter.c:175: if(timerflags&0x02)checklevel(0,0xff);
   054F E5 2E              1033 	mov	a,_timerflags
   0551 30 E1 0B           1034 	jnb	acc.1,00157$
   0554 C2 F0              1035 	clr	b[0]
   0556 85 F0 23           1036 	mov	bits,b
   0559 75 82 FF           1037 	mov	dpl,#0xFF
   055C 12 09 2D           1038 	lcall	_checklevel
                    0170   1039 	C$fb_app_counter.c$177$1$1 ==.
                           1040 ;	..\fb_app_counter.c:177: for(n=0;n<6;n++){
   055F                    1041 00157$:
   055F 7F 00              1042 	mov	r7,#0x00
   0561                    1043 00135$:
   0561 BF 06 00           1044 	cjne	r7,#0x06,00176$
   0564                    1045 00176$:
   0564 50 32              1046 	jnc	00138$
                    0177   1047 	C$fb_app_counter.c$178$2$7 ==.
                           1048 ;	..\fb_app_counter.c:178: if(timerflags & 0x01){// positive flags erzeugen und schieben
   0566 E5 2E              1049 	mov	a,_timerflags
   0568 30 E0 24           1050 	jnb	acc.0,00119$
                    017C   1051 	C$fb_app_counter.c$179$1$1 ==.
                           1052 ;	..\fb_app_counter.c:179: for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
   056B 7E 00              1053 	mov	r6,#0x00
   056D                    1054 00131$:
   056D BE 04 00           1055 	cjne	r6,#0x04,00179$
   0570                    1056 00179$:
   0570 50 1D              1057 	jnc	00119$
                    0183   1058 	C$fb_app_counter.c$180$4$9 ==.
                           1059 ;	..\fb_app_counter.c:180: if ((timerbase[m]& 0x0F)==n){// wenn die base mit der gespeicherten base übereinstimmt
   0572 EE                 1060 	mov	a,r6
   0573 24 2F              1061 	add	a,#_timerbase
   0575 F9                 1062 	mov	r1,a
   0576 87 05              1063 	mov	ar5,@r1
   0578 53 05 0F           1064 	anl	ar5,#0x0F
   057B ED                 1065 	mov	a,r5
   057C B5 07 0D           1066 	cjne	a,ar7,00133$
                    0190   1067 	C$fb_app_counter.c$181$5$10 ==.
                           1068 ;	..\fb_app_counter.c:181: if (timercnt[m]>0x80){// wenn der counter läuft...
   057F EE                 1069 	mov	a,r6
   0580 24 33              1070 	add	a,#_timercnt
   0582 F9                 1071 	mov	r1,a
   0583 E7                 1072 	mov	a,@r1
   0584 FD                 1073 	mov	r5,a
   0585 24 7F              1074 	add	a,#0xff - 0x80
   0587 50 03              1075 	jnc	00133$
                    019A   1076 	C$fb_app_counter.c$182$6$11 ==.
                           1077 ;	..\fb_app_counter.c:182: timercnt[m]=timercnt[m]-1;// den timer[m]decrementieren
   0589 ED                 1078 	mov	a,r5
   058A 14                 1079 	dec	a
   058B F7                 1080 	mov	@r1,a
   058C                    1081 00133$:
                    019D   1082 	C$fb_app_counter.c$179$3$8 ==.
                           1083 ;	..\fb_app_counter.c:179: for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
   058C 0E                 1084 	inc	r6
   058D 80 DE              1085 	sjmp	00131$
   058F                    1086 00119$:
                    01A0   1087 	C$fb_app_counter.c$187$2$7 ==.
                           1088 ;	..\fb_app_counter.c:187: timerflags = timerflags>>1;
   058F E5 2E              1089 	mov	a,_timerflags
   0591 C3                 1090 	clr	c
   0592 13                 1091 	rrc	a
   0593 F5 2E              1092 	mov	_timerflags,a
                    01A6   1093 	C$fb_app_counter.c$177$1$1 ==.
                           1094 ;	..\fb_app_counter.c:177: for(n=0;n<6;n++){
   0595 0F                 1095 	inc	r7
   0596 80 C9              1096 	sjmp	00135$
   0598                    1097 00138$:
                    01A9   1098 	C$fb_app_counter.c$192$3$13 ==.
                           1099 ;	..\fb_app_counter.c:192: for(objno=0;objno<4;objno++) {
   0598 7F 00              1100 	mov	r7,#0x00
   059A                    1101 00139$:
   059A BF 04 00           1102 	cjne	r7,#0x04,00184$
   059D                    1103 00184$:
   059D 40 03              1104 	jc	00185$
   059F 02 06 49           1105 	ljmp	00143$
   05A2                    1106 00185$:
                    01B3   1107 	C$fb_app_counter.c$193$2$12 ==.
                           1108 ;	..\fb_app_counter.c:193: if(timercnt[objno]==0x80) {
   05A2 EF                 1109 	mov	a,r7
   05A3 24 33              1110 	add	a,#_timercnt
   05A5 F9                 1111 	mov	r1,a
   05A6 87 06              1112 	mov	ar6,@r1
   05A8 BE 80 02           1113 	cjne	r6,#0x80,00186$
   05AB 80 03              1114 	sjmp	00187$
   05AD                    1115 00186$:
   05AD 02 06 45           1116 	ljmp	00141$
   05B0                    1117 00187$:
                    01C1   1118 	C$fb_app_counter.c$194$3$13 ==.
                           1119 ;	..\fb_app_counter.c:194: timercnt[objno]=eeprom[paraindex_timer[objno]];//Torzeit setzen
   05B0 EF                 1120 	mov	a,r7
   05B1 2F                 1121 	add	a,r7
   05B2 FE                 1122 	mov	r6,a
   05B3 FC                 1123 	mov	r4,a
   05B4 90 1C 72           1124 	mov	dptr,#_paraindex_timer
   05B7 93                 1125 	movc	a,@a+dptr
   05B8 CC                 1126 	xch	a,r4
   05B9 A3                 1127 	inc	dptr
   05BA 93                 1128 	movc	a,@a+dptr
   05BB FD                 1129 	mov	r5,a
   05BC 8C 82              1130 	mov	dpl,r4
   05BE 74 1D              1131 	mov	a,#(_eeprom >> 8)
   05C0 2D                 1132 	add	a,r5
   05C1 F5 83              1133 	mov	dph,a
   05C3 E4                 1134 	clr	a
   05C4 93                 1135 	movc	a,@a+dptr
   05C5 FB                 1136 	mov	r3,a
   05C6 F7                 1137 	mov	@r1,a
                    01D8   1138 	C$fb_app_counter.c$195$3$13 ==.
                           1139 ;	..\fb_app_counter.c:195: timerbase[objno]=eeprom[paraindex_timer[objno]+1];
   05C7 EF                 1140 	mov	a,r7
   05C8 24 2F              1141 	add	a,#_timerbase
   05CA F9                 1142 	mov	r1,a
   05CB EC                 1143 	mov	a,r4
   05CC 04                 1144 	inc	a
   05CD 90 1D 00           1145 	mov	dptr,#_eeprom
   05D0 93                 1146 	movc	a,@a+dptr
   05D1 FD                 1147 	mov	r5,a
   05D2 F7                 1148 	mov	@r1,a
                    01E4   1149 	C$fb_app_counter.c$196$3$13 ==.
                           1150 ;	..\fb_app_counter.c:196: if (!(objno&0x01))timerbase[objno]|= 0x80;// ;wenn Momentanwertzähler Löschung anfordern
   05D3 EF                 1151 	mov	a,r7
   05D4 20 E0 06           1152 	jb	acc.0,00121$
   05D7 87 05              1153 	mov	ar5,@r1
   05D9 74 80              1154 	mov	a,#0x80
   05DB 4D                 1155 	orl	a,r5
   05DC F7                 1156 	mov	@r1,a
   05DD                    1157 00121$:
                    01EE   1158 	C$fb_app_counter.c$197$3$13 ==.
                           1159 ;	..\fb_app_counter.c:197: if (read_obj_value((((objno&0x02)>>1)*13)+2)==0){// aktiven Tarif holen 
   05DD 74 02              1160 	mov	a,#0x02
   05DF 5F                 1161 	anl	a,r7
   05E0 C3                 1162 	clr	c
   05E1 13                 1163 	rrc	a
   05E2 75 F0 0D           1164 	mov	b,#0x0D
   05E5 A4                 1165 	mul	ab
   05E6 24 02              1166 	add	a,#0x02
   05E8 F5 82              1167 	mov	dpl,a
   05EA C0 07              1168 	push	ar7
   05EC C0 06              1169 	push	ar6
   05EE 12 0B 6C           1170 	lcall	_read_obj_value
   05F1 AA 82              1171 	mov	r2,dpl
   05F3 AB 83              1172 	mov	r3,dph
   05F5 AC F0              1173 	mov	r4,b
   05F7 FD                 1174 	mov	r5,a
   05F8 D0 06              1175 	pop	ar6
   05FA D0 07              1176 	pop	ar7
   05FC EA                 1177 	mov	a,r2
   05FD 4B                 1178 	orl	a,r3
   05FE 4C                 1179 	orl	a,r4
   05FF 4D                 1180 	orl	a,r5
   0600 70 22              1181 	jnz	00127$
                    0213   1182 	C$fb_app_counter.c$198$4$14 ==.
                           1183 ;	..\fb_app_counter.c:198: send_obj_value(objno_timer[objno]);// senden Tarif 1
   0602 EE                 1184 	mov	a,r6
   0603 FC                 1185 	mov	r4,a
   0604 90 1C 7A           1186 	mov	dptr,#_objno_timer
   0607 93                 1187 	movc	a,@a+dptr
   0608 CC                 1188 	xch	a,r4
   0609 A3                 1189 	inc	dptr
   060A 93                 1190 	movc	a,@a+dptr
   060B 8C 82              1191 	mov	dpl,r4
   060D C0 07              1192 	push	ar7
   060F 12 18 29           1193 	lcall	_send_obj_value
   0612 D0 07              1194 	pop	ar7
                    0225   1195 	C$fb_app_counter.c$199$4$14 ==.
                           1196 ;	..\fb_app_counter.c:199: if (timerbase[objno]& 0x80)timerbase[objno]&= (~0x40);// wenn Löschung, dann tarif2 löschen rücksetzen
   0614 EF                 1197 	mov	a,r7
   0615 24 2F              1198 	add	a,#_timerbase
   0617 F9                 1199 	mov	r1,a
   0618 E7                 1200 	mov	a,@r1
   0619 FD                 1201 	mov	r5,a
   061A 30 E7 28           1202 	jnb	acc.7,00141$
   061D 53 05 BF           1203 	anl	ar5,#0xBF
   0620 A7 05              1204 	mov	@r1,ar5
   0622 80 21              1205 	sjmp	00141$
   0624                    1206 00127$:
                    0235   1207 	C$fb_app_counter.c$202$4$15 ==.
                           1208 ;	..\fb_app_counter.c:202: send_obj_value(objno_timer[objno]+1);// senden Tarif 2
   0624 EE                 1209 	mov	a,r6
   0625 FD                 1210 	mov	r5,a
   0626 90 1C 7A           1211 	mov	dptr,#_objno_timer
   0629 93                 1212 	movc	a,@a+dptr
   062A CD                 1213 	xch	a,r5
   062B A3                 1214 	inc	dptr
   062C 93                 1215 	movc	a,@a+dptr
   062D ED                 1216 	mov	a,r5
   062E 04                 1217 	inc	a
   062F F5 82              1218 	mov	dpl,a
   0631 C0 07              1219 	push	ar7
   0633 12 18 29           1220 	lcall	_send_obj_value
   0636 D0 07              1221 	pop	ar7
                    0249   1222 	C$fb_app_counter.c$203$4$15 ==.
                           1223 ;	..\fb_app_counter.c:203: if (timerbase[objno]& 0x80)timerbase[objno]|= 0x40;// ;wenn Löschung, dann tarif2 löschen anfordern
   0638 EF                 1224 	mov	a,r7
   0639 24 2F              1225 	add	a,#_timerbase
   063B F9                 1226 	mov	r1,a
   063C E7                 1227 	mov	a,@r1
   063D FE                 1228 	mov	r6,a
   063E 30 E7 04           1229 	jnb	acc.7,00141$
   0641 74 40              1230 	mov	a,#0x40
   0643 4E                 1231 	orl	a,r6
   0644 F7                 1232 	mov	@r1,a
   0645                    1233 00141$:
                    0256   1234 	C$fb_app_counter.c$192$1$1 ==.
                           1235 ;	..\fb_app_counter.c:192: for(objno=0;objno<4;objno++) {
   0645 0F                 1236 	inc	r7
   0646 02 05 9A           1237 	ljmp	00139$
   0649                    1238 00143$:
                    025A   1239 	C$fb_app_counter.c$207$1$1 ==.
                    025A   1240 	XG$delay_timer$0$0 ==.
   0649 22                 1241 	ret
                           1242 ;------------------------------------------------------------
                           1243 ;Allocation info for local variables in function 'write_value_req'
                           1244 ;------------------------------------------------------------
                           1245 ;objno                     Allocated to stack - _bp +1
                           1246 ;objflags                  Allocated to registers r7 
                           1247 ;gapos                     Allocated to stack - _bp +2
                           1248 ;atp                       Allocated to registers r5 
                           1249 ;assno                     Allocated to stack - _bp +3
                           1250 ;n                         Allocated to stack - _bp +4
                           1251 ;gaposh                    Allocated to registers r3 
                           1252 ;tmp                       Allocated to stack - _bp +5
                           1253 ;objtype                   Allocated to registers r2 
                           1254 ;sloc0                     Allocated to stack - _bp +10
                           1255 ;sloc1                     Allocated to stack - _bp +6
                           1256 ;sloc2                     Allocated to stack - _bp +7
                           1257 ;------------------------------------------------------------
                    025B   1258 	G$write_value_req$0$0 ==.
                    025B   1259 	C$fb_app_counter.c$213$1$1 ==.
                           1260 ;	..\fb_app_counter.c:213: void write_value_req(void)		// Objekt-Wert setzen gemäß empfangenem EIS Telegramms
                           1261 ;	-----------------------------------------
                           1262 ;	 function write_value_req
                           1263 ;	-----------------------------------------
   064A                    1264 _write_value_req:
   064A C0 6D              1265 	push	_bp
   064C E5 81              1266 	mov	a,sp
   064E F5 6D              1267 	mov	_bp,a
   0650 24 0A              1268 	add	a,#0x0A
   0652 F5 81              1269 	mov	sp,a
                    0265   1270 	C$fb_app_counter.c$215$1$1 ==.
                           1271 ;	..\fb_app_counter.c:215: unsigned char objno,objflags,gapos,atp,assno,n,gaposh,tmp=0;
   0654 E5 6D              1272 	mov	a,_bp
   0656 24 05              1273 	add	a,#0x05
   0658 F8                 1274 	mov	r0,a
   0659 76 00              1275 	mov	@r0,#0x00
                    026C   1276 	C$fb_app_counter.c$218$1$1 ==.
                           1277 ;	..\fb_app_counter.c:218: if(APPLICATION_RUN){
   065B 90 1D 0D           1278 	mov	dptr,#(_eeprom + 0x000d)
   065E E4                 1279 	clr	a
   065F 93                 1280 	movc	a,@a+dptr
   0660 FE                 1281 	mov	r6,a
   0661 BE FF 02           1282 	cjne	r6,#0xFF,00178$
   0664 80 03              1283 	sjmp	00179$
   0666                    1284 00178$:
   0666 02 09 27           1285 	ljmp	00150$
   0669                    1286 00179$:
   0669 30 13 03           1287 	jnb	_connected,00180$
   066C 02 09 27           1288 	ljmp	00150$
   066F                    1289 00180$:
   066F E5 6C              1290 	mov	a,_status60
   0671 30 E0 03           1291 	jnb	acc.0,00181$
   0674 02 09 27           1292 	ljmp	00150$
   0677                    1293 00181$:
                    0288   1294 	C$fb_app_counter.c$219$2$2 ==.
                           1295 ;	..\fb_app_counter.c:219: gapos=gapos_in_gat(telegramm[3],telegramm[4]);
   0677 85 48 82           1296 	mov	dpl,(_telegramm + 0x0003)
   067A C0 49              1297 	push	(_telegramm + 0x0004)
   067C 12 15 CE           1298 	lcall	_gapos_in_gat
   067F AE 82              1299 	mov	r6,dpl
   0681 15 81              1300 	dec	sp
   0683 A8 6D              1301 	mov	r0,_bp
   0685 08                 1302 	inc	r0
   0686 08                 1303 	inc	r0
   0687 A6 06              1304 	mov	@r0,ar6
                    029A   1305 	C$fb_app_counter.c$220$2$2 ==.
                           1306 ;	..\fb_app_counter.c:220: if (gapos!=0xFF )	
   0689 A8 6D              1307 	mov	r0,_bp
   068B 08                 1308 	inc	r0
   068C 08                 1309 	inc	r0
   068D B6 FF 03           1310 	cjne	@r0,#0xFF,00182$
   0690 02 09 27           1311 	ljmp	00150$
   0693                    1312 00182$:
                    02A4   1313 	C$fb_app_counter.c$222$3$3 ==.
                           1314 ;	..\fb_app_counter.c:222: atp=eeprom[ASSOCTABPTR];		// Association Table Pointer
   0693 90 1D 11           1315 	mov	dptr,#(_eeprom + 0x0011)
   0696 E4                 1316 	clr	a
   0697 93                 1317 	movc	a,@a+dptr
                    02A9   1318 	C$fb_app_counter.c$223$3$3 ==.
                           1319 ;	..\fb_app_counter.c:223: assno=eeprom[atp];				// Erster Eintrag = Anzahl Einträge
   0698 FD                 1320 	mov	r5,a
   0699 F5 82              1321 	mov	dpl,a
   069B 75 83 1D           1322 	mov	dph,#(_eeprom >> 8)
   069E E4                 1323 	clr	a
   069F 93                 1324 	movc	a,@a+dptr
   06A0 FC                 1325 	mov	r4,a
   06A1 E5 6D              1326 	mov	a,_bp
   06A3 24 03              1327 	add	a,#0x03
   06A5 F8                 1328 	mov	r0,a
   06A6 A6 04              1329 	mov	@r0,ar4
                    02B9   1330 	C$fb_app_counter.c$225$5$5 ==.
                           1331 ;	..\fb_app_counter.c:225: for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
   06A8 74 02              1332 	mov	a,#0x02
   06AA 2D                 1333 	add	a,r5
   06AB FB                 1334 	mov	r3,a
   06AC E5 6D              1335 	mov	a,_bp
   06AE 24 06              1336 	add	a,#0x06
   06B0 F8                 1337 	mov	r0,a
   06B1 ED                 1338 	mov	a,r5
   06B2 04                 1339 	inc	a
   06B3 F6                 1340 	mov	@r0,a
   06B4 E5 6D              1341 	mov	a,_bp
   06B6 24 04              1342 	add	a,#0x04
   06B8 F8                 1343 	mov	r0,a
   06B9 76 00              1344 	mov	@r0,#0x00
   06BB                    1345 00146$:
   06BB E5 6D              1346 	mov	a,_bp
   06BD 24 04              1347 	add	a,#0x04
   06BF F8                 1348 	mov	r0,a
   06C0 E5 6D              1349 	mov	a,_bp
   06C2 24 03              1350 	add	a,#0x03
   06C4 F9                 1351 	mov	r1,a
   06C5 C3                 1352 	clr	c
   06C6 E6                 1353 	mov	a,@r0
   06C7 97                 1354 	subb	a,@r1
   06C8 40 03              1355 	jc	00183$
   06CA 02 09 27           1356 	ljmp	00150$
   06CD                    1357 00183$:
                    02DE   1358 	C$fb_app_counter.c$226$1$1 ==.
                           1359 ;	..\fb_app_counter.c:226: gaposh=eeprom[atp+1+(n*2)];
   06CD C0 03              1360 	push	ar3
   06CF E5 6D              1361 	mov	a,_bp
   06D1 24 04              1362 	add	a,#0x04
   06D3 F8                 1363 	mov	r0,a
   06D4 E6                 1364 	mov	a,@r0
   06D5 25 E0              1365 	add	a,acc
   06D7 FF                 1366 	mov	r7,a
   06D8 E5 6D              1367 	mov	a,_bp
   06DA 24 06              1368 	add	a,#0x06
   06DC F8                 1369 	mov	r0,a
   06DD EF                 1370 	mov	a,r7
   06DE 26                 1371 	add	a,@r0
   06DF 90 1D 00           1372 	mov	dptr,#_eeprom
   06E2 93                 1373 	movc	a,@a+dptr
   06E3 FB                 1374 	mov	r3,a
                    02F5   1375 	C$fb_app_counter.c$227$4$4 ==.
                           1376 ;	..\fb_app_counter.c:227: if(gapos==gaposh) {					// Wenn Positionsnummer übereinstimmt
   06E4 A8 6D              1377 	mov	r0,_bp
   06E6 08                 1378 	inc	r0
   06E7 08                 1379 	inc	r0
   06E8 E6                 1380 	mov	a,@r0
   06E9 B5 03 02           1381 	cjne	a,ar3,00184$
   06EC 80 05              1382 	sjmp	00185$
   06EE                    1383 00184$:
   06EE D0 03              1384 	pop	ar3
   06F0 02 09 1E           1385 	ljmp	00148$
   06F3                    1386 00185$:
   06F3 D0 03              1387 	pop	ar3
                    0306   1388 	C$fb_app_counter.c$228$1$1 ==.
                           1389 ;	..\fb_app_counter.c:228: objno=eeprom[atp+2+(n*2)];			// Objektnummer
   06F5 EF                 1390 	mov	a,r7
   06F6 2B                 1391 	add	a,r3
   06F7 90 1D 00           1392 	mov	dptr,#_eeprom
   06FA 93                 1393 	movc	a,@a+dptr
   06FB FD                 1394 	mov	r5,a
   06FC A8 6D              1395 	mov	r0,_bp
   06FE 08                 1396 	inc	r0
   06FF A6 05              1397 	mov	@r0,ar5
                    0312   1398 	C$fb_app_counter.c$229$5$5 ==.
                           1399 ;	..\fb_app_counter.c:229: objflags=read_objflags(objno);		// Objekt Flags lesen
   0701 A8 6D              1400 	mov	r0,_bp
   0703 08                 1401 	inc	r0
   0704 86 82              1402 	mov	dpl,@r0
   0706 C0 03              1403 	push	ar3
   0708 12 1A 6C           1404 	lcall	_read_objflags
   070B AD 82              1405 	mov	r5,dpl
   070D D0 03              1406 	pop	ar3
   070F 8D 07              1407 	mov	ar7,r5
                    0322   1408 	C$fb_app_counter.c$230$5$5 ==.
                           1409 ;	..\fb_app_counter.c:230: objtype=eeprom[eeprom[COMMSTABPTR]+objno*3+4];
   0711 90 1D 12           1410 	mov	dptr,#(_eeprom + 0x0012)
   0714 E4                 1411 	clr	a
   0715 93                 1412 	movc	a,@a+dptr
   0716 FD                 1413 	mov	r5,a
   0717 A8 6D              1414 	mov	r0,_bp
   0719 08                 1415 	inc	r0
   071A E6                 1416 	mov	a,@r0
   071B 75 F0 03           1417 	mov	b,#0x03
   071E A4                 1418 	mul	ab
   071F 2D                 1419 	add	a,r5
   0720 24 04              1420 	add	a,#0x04
   0722 90 1D 00           1421 	mov	dptr,#_eeprom
   0725 93                 1422 	movc	a,@a+dptr
   0726 FA                 1423 	mov	r2,a
                    0338   1424 	C$fb_app_counter.c$232$5$5 ==.
                           1425 ;	..\fb_app_counter.c:232: if((objflags&0x14)==0x14) {			// Kommunikation zulässig (Bit 2 = communication enable) + Schreiben zulässig (Bit 4 = write enable)
   0727 74 14              1426 	mov	a,#0x14
   0729 5F                 1427 	anl	a,r7
   072A FD                 1428 	mov	r5,a
   072B BD 14 02           1429 	cjne	r5,#0x14,00186$
   072E 80 03              1430 	sjmp	00187$
   0730                    1431 00186$:
   0730 02 09 1E           1432 	ljmp	00148$
   0733                    1433 00187$:
                    0344   1434 	C$fb_app_counter.c$233$6$6 ==.
                           1435 ;	..\fb_app_counter.c:233: if (objno<25) {					// Status der Eingangsobjekte 0-24
   0733 A8 6D              1436 	mov	r0,_bp
   0735 08                 1437 	inc	r0
   0736 B6 19 00           1438 	cjne	@r0,#0x19,00188$
   0739                    1439 00188$:
   0739 40 03              1440 	jc	00189$
   073B 02 09 1E           1441 	ljmp	00148$
   073E                    1442 00189$:
                    034F   1443 	C$fb_app_counter.c$234$7$7 ==.
                           1444 ;	..\fb_app_counter.c:234: if (objtype<=6){
   073E EA                 1445 	mov	a,r2
   073F 24 F9              1446 	add	a,#0xff - 0x06
   0741 40 39              1447 	jc	00102$
                    0354   1448 	C$fb_app_counter.c$235$1$1 ==.
                           1449 ;	..\fb_app_counter.c:235: tmp=telegramm[7]& 0x3F; //bit 6+7 löschen (0x40,0x80)
   0743 C0 03              1450 	push	ar3
   0745 E5 6D              1451 	mov	a,_bp
   0747 24 05              1452 	add	a,#0x05
   0749 F8                 1453 	mov	r0,a
   074A 74 3F              1454 	mov	a,#0x3F
   074C 55 4C              1455 	anl	a,(_telegramm + 0x0007)
   074E F6                 1456 	mov	@r0,a
                    0360   1457 	C$fb_app_counter.c$236$8$8 ==.
                           1458 ;	..\fb_app_counter.c:236: write_obj_value(objno,tmp);
   074F E5 6D              1459 	mov	a,_bp
   0751 24 05              1460 	add	a,#0x05
   0753 F8                 1461 	mov	r0,a
   0754 86 03              1462 	mov	ar3,@r0
   0756 7C 00              1463 	mov	r4,#0x00
   0758 7E 00              1464 	mov	r6,#0x00
   075A 7F 00              1465 	mov	r7,#0x00
   075C C0 03              1466 	push	ar3
   075E C0 02              1467 	push	ar2
   0760 C0 03              1468 	push	ar3
   0762 C0 04              1469 	push	ar4
   0764 C0 06              1470 	push	ar6
   0766 C0 07              1471 	push	ar7
   0768 A8 6D              1472 	mov	r0,_bp
   076A 08                 1473 	inc	r0
   076B 86 82              1474 	mov	dpl,@r0
   076D 12 0F 60           1475 	lcall	_write_obj_value
   0770 E5 81              1476 	mov	a,sp
   0772 24 FC              1477 	add	a,#0xfc
   0774 F5 81              1478 	mov	sp,a
   0776 D0 02              1479 	pop	ar2
   0778 D0 03              1480 	pop	ar3
                    038B   1481 	C$fb_app_counter.c$225$1$1 ==.
                           1482 ;	..\fb_app_counter.c:225: for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
   077A D0 03              1483 	pop	ar3
                    038D   1484 	C$fb_app_counter.c$236$7$7 ==.
                           1485 ;	..\fb_app_counter.c:236: write_obj_value(objno,tmp);
   077C                    1486 00102$:
                    038D   1487 	C$fb_app_counter.c$238$7$7 ==.
                           1488 ;	..\fb_app_counter.c:238: if((objno==11 &&  bitobj_z1 & 0x40)||
   077C A8 6D              1489 	mov	r0,_bp
   077E 08                 1490 	inc	r0
   077F B6 0B 05           1491 	cjne	@r0,#0x0B,00111$
   0782 E5 38              1492 	mov	a,_bitobj_z1
   0784 20 E6 29           1493 	jb	acc.6,00107$
   0787                    1494 00111$:
                    0398   1495 	C$fb_app_counter.c$239$7$7 ==.
                           1496 ;	..\fb_app_counter.c:239: (objno==12 &&  bitobj_z1 & 0x0100)||
   0787 A8 6D              1497 	mov	r0,_bp
   0789 08                 1498 	inc	r0
   078A B6 0C 05           1499 	cjne	@r0,#0x0C,00113$
   078D E5 39              1500 	mov	a,(_bitobj_z1 + 1)
   078F 20 E0 1E           1501 	jb	acc.0,00107$
   0792                    1502 00113$:
                    03A3   1503 	C$fb_app_counter.c$240$7$7 ==.
                           1504 ;	..\fb_app_counter.c:240: (objno==24 &&  bitobj_z2 & 0x40)||
   0792 A8 6D              1505 	mov	r0,_bp
   0794 08                 1506 	inc	r0
   0795 B6 18 05           1507 	cjne	@r0,#0x18,00115$
   0798 E5 3A              1508 	mov	a,_bitobj_z2
   079A 20 E6 13           1509 	jb	acc.6,00107$
   079D                    1510 00115$:
                    03AE   1511 	C$fb_app_counter.c$241$7$7 ==.
                           1512 ;	..\fb_app_counter.c:241: (objno==25 &&  bitobj_z2 & 0x0100)){
   079D A8 6D              1513 	mov	r0,_bp
   079F 08                 1514 	inc	r0
   07A0 B6 19 02           1515 	cjne	@r0,#0x19,00200$
   07A3 80 03              1516 	sjmp	00201$
   07A5                    1517 00200$:
   07A5 02 08 57           1518 	ljmp	00108$
   07A8                    1519 00201$:
   07A8 E5 3B              1520 	mov	a,(_bitobj_z2 + 1)
   07AA 20 E0 03           1521 	jb	acc.0,00202$
   07AD 02 08 57           1522 	ljmp	00108$
   07B0                    1523 00202$:
   07B0                    1524 00107$:
                    03C1   1525 	C$fb_app_counter.c$243$8$9 ==.
                           1526 ;	..\fb_app_counter.c:243: if (objtype==8)write_obj_value(objno,telegramm[9]+(telegramm[8]<<8));
   07B0 BA 08 35           1527 	cjne	r2,#0x08,00104$
   07B3 C0 03              1528 	push	ar3
   07B5 AE 4E              1529 	mov	r6,(_telegramm + 0x0009)
   07B7 7F 00              1530 	mov	r7,#0x00
   07B9 AB 4D              1531 	mov	r3,(_telegramm + 0x0008)
   07BB 8B 04              1532 	mov	ar4,r3
   07BD E4                 1533 	clr	a
   07BE 2E                 1534 	add	a,r6
   07BF FE                 1535 	mov	r6,a
   07C0 EC                 1536 	mov	a,r4
   07C1 3F                 1537 	addc	a,r7
   07C2 FF                 1538 	mov	r7,a
   07C3 33                 1539 	rlc	a
   07C4 95 E0              1540 	subb	a,acc
   07C6 FC                 1541 	mov	r4,a
   07C7 FB                 1542 	mov	r3,a
   07C8 C0 03              1543 	push	ar3
   07CA C0 02              1544 	push	ar2
   07CC C0 06              1545 	push	ar6
   07CE C0 07              1546 	push	ar7
   07D0 C0 04              1547 	push	ar4
   07D2 C0 03              1548 	push	ar3
   07D4 A8 6D              1549 	mov	r0,_bp
   07D6 08                 1550 	inc	r0
   07D7 86 82              1551 	mov	dpl,@r0
   07D9 12 0F 60           1552 	lcall	_write_obj_value
   07DC E5 81              1553 	mov	a,sp
   07DE 24 FC              1554 	add	a,#0xfc
   07E0 F5 81              1555 	mov	sp,a
   07E2 D0 02              1556 	pop	ar2
   07E4 D0 03              1557 	pop	ar3
                    03F7   1558 	C$fb_app_counter.c$225$1$1 ==.
                           1559 ;	..\fb_app_counter.c:225: for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
   07E6 D0 03              1560 	pop	ar3
                    03F9   1561 	C$fb_app_counter.c$243$8$9 ==.
                           1562 ;	..\fb_app_counter.c:243: if (objtype==8)write_obj_value(objno,telegramm[9]+(telegramm[8]<<8));
   07E8                    1563 00104$:
                    03F9   1564 	C$fb_app_counter.c$245$8$9 ==.
                           1565 ;	..\fb_app_counter.c:245: if (objtype==10)write_obj_value(objno,(unsigned int)(telegramm[11] | (telegramm[10] << 8)) |((unsigned long)(telegramm[9] | (telegramm[8] << 8)) << 16));//
   07E8 BA 0A 6C           1566 	cjne	r2,#0x0A,00108$
   07EB C0 03              1567 	push	ar3
   07ED AF 4F              1568 	mov	r7,(_telegramm + 0x000a)
   07EF 7E 00              1569 	mov	r6,#0x00
   07F1 AB 50              1570 	mov	r3,(_telegramm + 0x000b)
   07F3 7C 00              1571 	mov	r4,#0x00
   07F5 EB                 1572 	mov	a,r3
   07F6 42 06              1573 	orl	ar6,a
   07F8 EC                 1574 	mov	a,r4
   07F9 42 07              1575 	orl	ar7,a
   07FB AC 4D              1576 	mov	r4,(_telegramm + 0x0008)
   07FD 7B 00              1577 	mov	r3,#0x00
   07FF AA 4E              1578 	mov	r2,(_telegramm + 0x0009)
   0801 7D 00              1579 	mov	r5,#0x00
   0803 EA                 1580 	mov	a,r2
   0804 42 03              1581 	orl	ar3,a
   0806 ED                 1582 	mov	a,r5
   0807 42 04              1583 	orl	ar4,a
   0809 EC                 1584 	mov	a,r4
   080A 33                 1585 	rlc	a
   080B 95 E0              1586 	subb	a,acc
   080D E5 6D              1587 	mov	a,_bp
   080F 24 07              1588 	add	a,#0x07
   0811 F8                 1589 	mov	r0,a
   0812 08                 1590 	inc	r0
   0813 08                 1591 	inc	r0
   0814 08                 1592 	inc	r0
   0815 A6 04              1593 	mov	@r0,ar4
   0817 18                 1594 	dec	r0
   0818 A6 03              1595 	mov	@r0,ar3
   081A 18                 1596 	dec	r0
   081B 76 00              1597 	mov	@r0,#0x00
   081D 18                 1598 	dec	r0
   081E 76 00              1599 	mov	@r0,#0x00
   0820 8E 04              1600 	mov	ar4,r6
   0822 8F 05              1601 	mov	ar5,r7
   0824 E4                 1602 	clr	a
   0825 FE                 1603 	mov	r6,a
   0826 FF                 1604 	mov	r7,a
   0827 E5 6D              1605 	mov	a,_bp
   0829 24 07              1606 	add	a,#0x07
   082B F8                 1607 	mov	r0,a
   082C E6                 1608 	mov	a,@r0
   082D 42 04              1609 	orl	ar4,a
   082F 08                 1610 	inc	r0
   0830 E6                 1611 	mov	a,@r0
   0831 42 05              1612 	orl	ar5,a
   0833 08                 1613 	inc	r0
   0834 E6                 1614 	mov	a,@r0
   0835 42 06              1615 	orl	ar6,a
   0837 08                 1616 	inc	r0
   0838 E6                 1617 	mov	a,@r0
   0839 42 07              1618 	orl	ar7,a
   083B C0 03              1619 	push	ar3
   083D C0 04              1620 	push	ar4
   083F C0 05              1621 	push	ar5
   0841 C0 06              1622 	push	ar6
   0843 C0 07              1623 	push	ar7
   0845 A8 6D              1624 	mov	r0,_bp
   0847 08                 1625 	inc	r0
   0848 86 82              1626 	mov	dpl,@r0
   084A 12 0F 60           1627 	lcall	_write_obj_value
   084D E5 81              1628 	mov	a,sp
   084F 24 FC              1629 	add	a,#0xfc
   0851 F5 81              1630 	mov	sp,a
   0853 D0 03              1631 	pop	ar3
                    0466   1632 	C$fb_app_counter.c$225$1$1 ==.
                           1633 ;	..\fb_app_counter.c:225: for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
   0855 D0 03              1634 	pop	ar3
                    0468   1635 	C$fb_app_counter.c$245$7$7 ==.
                           1636 ;	..\fb_app_counter.c:245: if (objtype==10)write_obj_value(objno,(unsigned int)(telegramm[11] | (telegramm[10] << 8)) |((unsigned long)(telegramm[9] | (telegramm[8] << 8)) << 16));//
   0857                    1637 00108$:
                    0468   1638 	C$fb_app_counter.c$247$7$7 ==.
                           1639 ;	..\fb_app_counter.c:247: if ( tmp!=0){// bei 'EIN' Tele
   0857 E5 6D              1640 	mov	a,_bp
   0859 24 05              1641 	add	a,#0x05
   085B F8                 1642 	mov	r0,a
   085C E6                 1643 	mov	a,@r0
   085D 70 03              1644 	jnz	00207$
   085F 02 09 1E           1645 	ljmp	00148$
   0862                    1646 00207$:
                    0473   1647 	C$fb_app_counter.c$248$8$10 ==.
                           1648 ;	..\fb_app_counter.c:248: if(objno==7)send_obj_value(11);// Anforderungen
   0862 A8 6D              1649 	mov	r0,_bp
   0864 08                 1650 	inc	r0
   0865 B6 07 0A           1651 	cjne	@r0,#0x07,00117$
   0868 75 82 0B           1652 	mov	dpl,#0x0B
   086B C0 03              1653 	push	ar3
   086D 12 18 29           1654 	lcall	_send_obj_value
   0870 D0 03              1655 	pop	ar3
   0872                    1656 00117$:
                    0483   1657 	C$fb_app_counter.c$249$8$10 ==.
                           1658 ;	..\fb_app_counter.c:249: if(objno==9)send_obj_value(12);
   0872 A8 6D              1659 	mov	r0,_bp
   0874 08                 1660 	inc	r0
   0875 B6 09 0A           1661 	cjne	@r0,#0x09,00119$
   0878 75 82 0C           1662 	mov	dpl,#0x0C
   087B C0 03              1663 	push	ar3
   087D 12 18 29           1664 	lcall	_send_obj_value
   0880 D0 03              1665 	pop	ar3
   0882                    1666 00119$:
                    0493   1667 	C$fb_app_counter.c$250$8$10 ==.
                           1668 ;	..\fb_app_counter.c:250: if(objno==20)send_obj_value(24);
   0882 A8 6D              1669 	mov	r0,_bp
   0884 08                 1670 	inc	r0
   0885 B6 14 0A           1671 	cjne	@r0,#0x14,00121$
   0888 75 82 18           1672 	mov	dpl,#0x18
   088B C0 03              1673 	push	ar3
   088D 12 18 29           1674 	lcall	_send_obj_value
   0890 D0 03              1675 	pop	ar3
   0892                    1676 00121$:
                    04A3   1677 	C$fb_app_counter.c$251$8$10 ==.
                           1678 ;	..\fb_app_counter.c:251: if(objno==22)send_obj_value(25);
   0892 A8 6D              1679 	mov	r0,_bp
   0894 08                 1680 	inc	r0
   0895 B6 16 0A           1681 	cjne	@r0,#0x16,00123$
   0898 75 82 19           1682 	mov	dpl,#0x19
   089B C0 03              1683 	push	ar3
   089D 12 18 29           1684 	lcall	_send_obj_value
   08A0 D0 03              1685 	pop	ar3
   08A2                    1686 00123$:
                    04B3   1687 	C$fb_app_counter.c$252$8$10 ==.
                           1688 ;	..\fb_app_counter.c:252: if(objno==8)write_obj_value(11,0);// löschungen
   08A2 A8 6D              1689 	mov	r0,_bp
   08A4 08                 1690 	inc	r0
   08A5 B6 08 19           1691 	cjne	@r0,#0x08,00125$
   08A8 C0 03              1692 	push	ar3
   08AA E4                 1693 	clr	a
   08AB C0 E0              1694 	push	acc
   08AD C0 E0              1695 	push	acc
   08AF C0 E0              1696 	push	acc
   08B1 C0 E0              1697 	push	acc
   08B3 75 82 0B           1698 	mov	dpl,#0x0B
   08B6 12 0F 60           1699 	lcall	_write_obj_value
   08B9 E5 81              1700 	mov	a,sp
   08BB 24 FC              1701 	add	a,#0xfc
   08BD F5 81              1702 	mov	sp,a
   08BF D0 03              1703 	pop	ar3
   08C1                    1704 00125$:
                    04D2   1705 	C$fb_app_counter.c$253$8$10 ==.
                           1706 ;	..\fb_app_counter.c:253: if(objno==10)write_obj_value(12,0);
   08C1 A8 6D              1707 	mov	r0,_bp
   08C3 08                 1708 	inc	r0
   08C4 B6 0A 19           1709 	cjne	@r0,#0x0A,00127$
   08C7 C0 03              1710 	push	ar3
   08C9 E4                 1711 	clr	a
   08CA C0 E0              1712 	push	acc
   08CC C0 E0              1713 	push	acc
   08CE C0 E0              1714 	push	acc
   08D0 C0 E0              1715 	push	acc
   08D2 75 82 0C           1716 	mov	dpl,#0x0C
   08D5 12 0F 60           1717 	lcall	_write_obj_value
   08D8 E5 81              1718 	mov	a,sp
   08DA 24 FC              1719 	add	a,#0xfc
   08DC F5 81              1720 	mov	sp,a
   08DE D0 03              1721 	pop	ar3
   08E0                    1722 00127$:
                    04F1   1723 	C$fb_app_counter.c$254$8$10 ==.
                           1724 ;	..\fb_app_counter.c:254: if(objno==21)write_obj_value(24,0);
   08E0 A8 6D              1725 	mov	r0,_bp
   08E2 08                 1726 	inc	r0
   08E3 B6 15 19           1727 	cjne	@r0,#0x15,00129$
   08E6 C0 03              1728 	push	ar3
   08E8 E4                 1729 	clr	a
   08E9 C0 E0              1730 	push	acc
   08EB C0 E0              1731 	push	acc
   08ED C0 E0              1732 	push	acc
   08EF C0 E0              1733 	push	acc
   08F1 75 82 18           1734 	mov	dpl,#0x18
   08F4 12 0F 60           1735 	lcall	_write_obj_value
   08F7 E5 81              1736 	mov	a,sp
   08F9 24 FC              1737 	add	a,#0xfc
   08FB F5 81              1738 	mov	sp,a
   08FD D0 03              1739 	pop	ar3
   08FF                    1740 00129$:
                    0510   1741 	C$fb_app_counter.c$255$8$10 ==.
                           1742 ;	..\fb_app_counter.c:255: if(objno==23)write_obj_value(25,0);
   08FF A8 6D              1743 	mov	r0,_bp
   0901 08                 1744 	inc	r0
   0902 B6 17 19           1745 	cjne	@r0,#0x17,00148$
   0905 C0 03              1746 	push	ar3
   0907 E4                 1747 	clr	a
   0908 C0 E0              1748 	push	acc
   090A C0 E0              1749 	push	acc
   090C C0 E0              1750 	push	acc
   090E C0 E0              1751 	push	acc
   0910 75 82 19           1752 	mov	dpl,#0x19
   0913 12 0F 60           1753 	lcall	_write_obj_value
   0916 E5 81              1754 	mov	a,sp
   0918 24 FC              1755 	add	a,#0xfc
   091A F5 81              1756 	mov	sp,a
   091C D0 03              1757 	pop	ar3
   091E                    1758 00148$:
                    052F   1759 	C$fb_app_counter.c$225$3$3 ==.
                           1760 ;	..\fb_app_counter.c:225: for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
   091E E5 6D              1761 	mov	a,_bp
   0920 24 04              1762 	add	a,#0x04
   0922 F8                 1763 	mov	r0,a
   0923 06                 1764 	inc	@r0
   0924 02 06 BB           1765 	ljmp	00146$
   0927                    1766 00150$:
   0927 85 6D 81           1767 	mov	sp,_bp
   092A D0 6D              1768 	pop	_bp
                    053D   1769 	C$fb_app_counter.c$263$1$1 ==.
                    053D   1770 	XG$write_value_req$0$0 ==.
   092C 22                 1771 	ret
                           1772 ;------------------------------------------------------------
                           1773 ;Allocation info for local variables in function 'checklevel'
                           1774 ;------------------------------------------------------------
                           1775 ;check                     Allocated to registers r7 
                           1776 ;fullcheck                 Allocated to registers b0 
                           1777 ;ctg                       Allocated to registers r5 
                           1778 ;c_paraptr                 Allocated to registers r4 
                           1779 ;c_para                    Allocated to stack - _bp +1
                           1780 ;c_valptr                  Allocated to registers r2 
                           1781 ;obj_counter               Allocated to stack - _bp +2
                           1782 ;obj                       Allocated to stack - _bp +3
                           1783 ;c_val                     Allocated to stack - _bp +4
                           1784 ;checken                   Allocated to registers b1 
                           1785 ;------------------------------------------------------------
                    053E   1786 	G$checklevel$0$0 ==.
                    053E   1787 	C$fb_app_counter.c$265$1$1 ==.
                           1788 ;	..\fb_app_counter.c:265: void checklevel(__bit fullcheck,unsigned char check)// vergleiche Momentanwert mit Grenzwert
                           1789 ;	-----------------------------------------
                           1790 ;	 function checklevel
                           1791 ;	-----------------------------------------
   092D                    1792 _checklevel:
   092D C0 6D              1793 	push	_bp
   092F E5 81              1794 	mov	a,sp
   0931 F5 6D              1795 	mov	_bp,a
   0933 24 05              1796 	add	a,#0x05
   0935 F5 81              1797 	mov	sp,a
   0937 AF 82              1798 	mov	r7,dpl
                    054A   1799 	C$fb_app_counter.c$273$3$4 ==.
                           1800 ;	..\fb_app_counter.c:273: for (ctg=0;ctg<=7;ctg++){
   0939 74 02              1801 	mov	a,#0x02
   093B 5F                 1802 	anl	a,r7
   093C FE                 1803 	mov	r6,a
   093D 53 07 40           1804 	anl	ar7,#0x40
   0940 7D 00              1805 	mov	r5,#0x00
   0942                    1806 00128$:
   0942 ED                 1807 	mov	a,r5
   0943 24 F8              1808 	add	a,#0xff - 0x07
   0945 50 03              1809 	jnc	00150$
   0947 02 0A A8           1810 	ljmp	00132$
   094A                    1811 00150$:
                    055B   1812 	C$fb_app_counter.c$274$2$2 ==.
                           1813 ;	..\fb_app_counter.c:274: checken=1;
   094A D2 19              1814 	setb	b1
                    055D   1815 	C$fb_app_counter.c$275$2$2 ==.
                           1816 ;	..\fb_app_counter.c:275: if (ctg&0x04){// zähler 2
   094C ED                 1817 	mov	a,r5
   094D 30 E2 18           1818 	jnb	acc.2,00106$
                    0561   1819 	C$fb_app_counter.c$276$3$3 ==.
                           1820 ;	..\fb_app_counter.c:276: obj_counter=13;
   0950 A8 6D              1821 	mov	r0,_bp
   0952 08                 1822 	inc	r0
   0953 08                 1823 	inc	r0
   0954 76 0D              1824 	mov	@r0,#0x0D
                    0567   1825 	C$fb_app_counter.c$277$3$3 ==.
                           1826 ;	..\fb_app_counter.c:277: c_paraptr=0xE9;
   0956 7C E9              1827 	mov	r4,#0xE9
                    0569   1828 	C$fb_app_counter.c$278$3$3 ==.
                           1829 ;	..\fb_app_counter.c:278: c_valptr=0xF0;
   0958 7A F0              1830 	mov	r2,#0xF0
                    056B   1831 	C$fb_app_counter.c$279$3$3 ==.
                           1832 ;	..\fb_app_counter.c:279: obj=16;
   095A E5 6D              1833 	mov	a,_bp
   095C 24 03              1834 	add	a,#0x03
   095E F8                 1835 	mov	r0,a
   095F 76 10              1836 	mov	@r0,#0x10
                    0572   1837 	C$fb_app_counter.c$280$3$3 ==.
                           1838 ;	..\fb_app_counter.c:280: if((check&0x02)==0)checken=0;
   0961 EE                 1839 	mov	a,r6
   0962 70 1A              1840 	jnz	00107$
   0964 C2 19              1841 	clr	b1
   0966 80 16              1842 	sjmp	00107$
   0968                    1843 00106$:
                    0579   1844 	C$fb_app_counter.c$283$3$4 ==.
                           1845 ;	..\fb_app_counter.c:283: obj_counter=0;
   0968 A8 6D              1846 	mov	r0,_bp
   096A 08                 1847 	inc	r0
   096B 08                 1848 	inc	r0
   096C 76 00              1849 	mov	@r0,#0x00
                    057F   1850 	C$fb_app_counter.c$284$3$4 ==.
                           1851 ;	..\fb_app_counter.c:284: c_paraptr=0xD3;
   096E 7C D3              1852 	mov	r4,#0xD3
                    0581   1853 	C$fb_app_counter.c$285$3$4 ==.
                           1854 ;	..\fb_app_counter.c:285: c_valptr=0xDA;
   0970 7A DA              1855 	mov	r2,#0xDA
                    0583   1856 	C$fb_app_counter.c$286$3$4 ==.
                           1857 ;	..\fb_app_counter.c:286: obj=3;
   0972 E5 6D              1858 	mov	a,_bp
   0974 24 03              1859 	add	a,#0x03
   0976 F8                 1860 	mov	r0,a
   0977 76 03              1861 	mov	@r0,#0x03
                    058A   1862 	C$fb_app_counter.c$287$3$4 ==.
                           1863 ;	..\fb_app_counter.c:287: if(check&0x02)checken=0;
   0979 EE                 1864 	mov	a,r6
   097A 60 02              1865 	jz	00107$
   097C C2 19              1866 	clr	b1
   097E                    1867 00107$:
                    058F   1868 	C$fb_app_counter.c$289$2$2 ==.
                           1869 ;	..\fb_app_counter.c:289: if(ctg&0x02){// tarif 2
   097E ED                 1870 	mov	a,r5
   097F 30 E1 18           1871 	jnb	acc.1,00113$
                    0593   1872 	C$fb_app_counter.c$290$3$5 ==.
                           1873 ;	..\fb_app_counter.c:290: obj_counter+=1;
   0982 A8 6D              1874 	mov	r0,_bp
   0984 08                 1875 	inc	r0
   0985 08                 1876 	inc	r0
   0986 06                 1877 	inc	@r0
                    0598   1878 	C$fb_app_counter.c$291$3$5 ==.
                           1879 ;	..\fb_app_counter.c:291: c_paraptr++;
   0987 0C                 1880 	inc	r4
                    0599   1881 	C$fb_app_counter.c$292$3$5 ==.
                           1882 ;	..\fb_app_counter.c:292: c_valptr+=4;
   0988 EA                 1883 	mov	a,r2
   0989 24 04              1884 	add	a,#0x04
   098B FA                 1885 	mov	r2,a
                    059D   1886 	C$fb_app_counter.c$293$3$5 ==.
                           1887 ;	..\fb_app_counter.c:293: obj+=2;
   098C E5 6D              1888 	mov	a,_bp
   098E 24 03              1889 	add	a,#0x03
   0990 F8                 1890 	mov	r0,a
   0991 06                 1891 	inc	@r0
   0992 06                 1892 	inc	@r0
                    05A4   1893 	C$fb_app_counter.c$294$3$5 ==.
                           1894 ;	..\fb_app_counter.c:294: if(!(check&0x40))checken=0;
   0993 EF                 1895 	mov	a,r7
   0994 70 09              1896 	jnz	00114$
   0996 C2 19              1897 	clr	b1
   0998 80 05              1898 	sjmp	00114$
   099A                    1899 00113$:
                    05AB   1900 	C$fb_app_counter.c$297$3$6 ==.
                           1901 ;	..\fb_app_counter.c:297: if(check & 0x40)checken=0;
   099A EF                 1902 	mov	a,r7
   099B 60 02              1903 	jz	00114$
   099D C2 19              1904 	clr	b1
   099F                    1905 00114$:
                    05B0   1906 	C$fb_app_counter.c$300$1$1 ==.
                           1907 ;	..\fb_app_counter.c:300: c_para=eeprom[c_paraptr];
   099F C0 07              1908 	push	ar7
   09A1 8C 82              1909 	mov	dpl,r4
   09A3 75 83 1D           1910 	mov	dph,#(_eeprom >> 8)
   09A6 E4                 1911 	clr	a
   09A7 93                 1912 	movc	a,@a+dptr
   09A8 FF                 1913 	mov	r7,a
   09A9 A8 6D              1914 	mov	r0,_bp
   09AB 08                 1915 	inc	r0
   09AC A6 07              1916 	mov	@r0,ar7
                    05BF   1917 	C$fb_app_counter.c$301$2$2 ==.
                           1918 ;	..\fb_app_counter.c:301: if(ctg&0x01){
   09AE ED                 1919 	mov	a,r5
   09AF D0 07              1920 	pop	ar7
   09B1 30 E0 10           1921 	jnb	acc.0,00116$
                    05C5   1922 	C$fb_app_counter.c$302$3$7 ==.
                           1923 ;	..\fb_app_counter.c:302: c_para=c_para>>4;
   09B4 A8 6D              1924 	mov	r0,_bp
   09B6 08                 1925 	inc	r0
   09B7 E6                 1926 	mov	a,@r0
   09B8 C4                 1927 	swap	a
   09B9 54 0F              1928 	anl	a,#0x0F
   09BB F6                 1929 	mov	@r0,a
                    05CD   1930 	C$fb_app_counter.c$303$3$7 ==.
                           1931 ;	..\fb_app_counter.c:303: c_valptr+=2;// grenzwert 2
   09BC 0A                 1932 	inc	r2
   09BD 0A                 1933 	inc	r2
                    05CF   1934 	C$fb_app_counter.c$304$3$7 ==.
                           1935 ;	..\fb_app_counter.c:304: obj++;
   09BE E5 6D              1936 	mov	a,_bp
   09C0 24 03              1937 	add	a,#0x03
   09C2 F8                 1938 	mov	r0,a
   09C3 06                 1939 	inc	@r0
   09C4                    1940 00116$:
                    05D5   1941 	C$fb_app_counter.c$307$1$1 ==.
                           1942 ;	..\fb_app_counter.c:307: c_val=(unsigned int)((eeprom[c_valptr]<<8)+(eeprom[c_valptr+1]));//*(unsigned int)((eeprom[c_calc]<<8)+(eeprom[c_calc+1]));
   09C4 C0 07              1943 	push	ar7
   09C6 8A 82              1944 	mov	dpl,r2
   09C8 75 83 1D           1945 	mov	dph,#(_eeprom >> 8)
   09CB E4                 1946 	clr	a
   09CC 93                 1947 	movc	a,@a+dptr
   09CD FF                 1948 	mov	r7,a
   09CE 7C 00              1949 	mov	r4,#0x00
   09D0 EA                 1950 	mov	a,r2
   09D1 04                 1951 	inc	a
   09D2 90 1D 00           1952 	mov	dptr,#_eeprom
   09D5 93                 1953 	movc	a,@a+dptr
   09D6 7B 00              1954 	mov	r3,#0x00
   09D8 2C                 1955 	add	a,r4
   09D9 FC                 1956 	mov	r4,a
   09DA EB                 1957 	mov	a,r3
   09DB 3F                 1958 	addc	a,r7
   09DC FF                 1959 	mov	r7,a
   09DD E5 6D              1960 	mov	a,_bp
   09DF 24 04              1961 	add	a,#0x04
   09E1 F8                 1962 	mov	r0,a
   09E2 A6 04              1963 	mov	@r0,ar4
   09E4 08                 1964 	inc	r0
   09E5 A6 07              1965 	mov	@r0,ar7
                    05F8   1966 	C$fb_app_counter.c$308$2$2 ==.
                           1967 ;	..\fb_app_counter.c:308: if((int)read_obj_value(obj_counter) > c_val){// überschreiten
   09E7 A8 6D              1968 	mov	r0,_bp
   09E9 08                 1969 	inc	r0
   09EA 08                 1970 	inc	r0
   09EB 86 82              1971 	mov	dpl,@r0
   09ED C0 06              1972 	push	ar6
   09EF C0 05              1973 	push	ar5
   09F1 C0 23              1974 	push	bits
   09F3 12 0B 6C           1975 	lcall	_read_obj_value
   09F6 AA 82              1976 	mov	r2,dpl
   09F8 AB 83              1977 	mov	r3,dph
   09FA AC F0              1978 	mov	r4,b
   09FC D0 23              1979 	pop	bits
   09FE D0 05              1980 	pop	ar5
   0A00 D0 06              1981 	pop	ar6
   0A02 E5 6D              1982 	mov	a,_bp
   0A04 24 04              1983 	add	a,#0x04
   0A06 F8                 1984 	mov	r0,a
   0A07 C3                 1985 	clr	c
   0A08 E6                 1986 	mov	a,@r0
   0A09 9A                 1987 	subb	a,r2
   0A0A 08                 1988 	inc	r0
   0A0B E6                 1989 	mov	a,@r0
   0A0C 9B                 1990 	subb	a,r3
   0A0D D0 07              1991 	pop	ar7
   0A0F 50 2D              1992 	jnc	00120$
                    0622   1993 	C$fb_app_counter.c$309$3$8 ==.
                           1994 ;	..\fb_app_counter.c:309: if(c_para & 0x03)sendbychange(obj,c_para&0x01);
   0A11 A8 6D              1995 	mov	r0,_bp
   0A13 08                 1996 	inc	r0
   0A14 E6                 1997 	mov	a,@r0
   0A15 54 03              1998 	anl	a,#0x03
   0A17 60 25              1999 	jz	00120$
   0A19 A8 6D              2000 	mov	r0,_bp
   0A1B 08                 2001 	inc	r0
   0A1C 74 01              2002 	mov	a,#0x01
   0A1E 56                 2003 	anl	a,@r0
   0A1F FC                 2004 	mov	r4,a
   0A20 C0 07              2005 	push	ar7
   0A22 C0 06              2006 	push	ar6
   0A24 C0 05              2007 	push	ar5
   0A26 C0 23              2008 	push	bits
   0A28 C0 04              2009 	push	ar4
   0A2A E5 6D              2010 	mov	a,_bp
   0A2C 24 03              2011 	add	a,#0x03
   0A2E F8                 2012 	mov	r0,a
   0A2F 86 82              2013 	mov	dpl,@r0
   0A31 12 0A D9           2014 	lcall	_sendbychange
   0A34 15 81              2015 	dec	sp
   0A36 D0 23              2016 	pop	bits
   0A38 D0 05              2017 	pop	ar5
   0A3A D0 06              2018 	pop	ar6
   0A3C D0 07              2019 	pop	ar7
   0A3E                    2020 00120$:
                    064F   2021 	C$fb_app_counter.c$311$2$2 ==.
                           2022 ;	..\fb_app_counter.c:311: if (fullcheck && checken){
   0A3E 30 18 63           2023 	jnb	b0,00130$
   0A41 30 19 60           2024 	jnb	b1,00130$
                    0655   2025 	C$fb_app_counter.c$312$1$1 ==.
                           2026 ;	..\fb_app_counter.c:312: if((int)read_obj_value(obj_counter) < c_val){// unterschreiten
   0A44 C0 07              2027 	push	ar7
   0A46 A8 6D              2028 	mov	r0,_bp
   0A48 08                 2029 	inc	r0
   0A49 08                 2030 	inc	r0
   0A4A 86 82              2031 	mov	dpl,@r0
   0A4C C0 06              2032 	push	ar6
   0A4E C0 05              2033 	push	ar5
   0A50 C0 23              2034 	push	bits
   0A52 12 0B 6C           2035 	lcall	_read_obj_value
   0A55 AA 82              2036 	mov	r2,dpl
   0A57 AB 83              2037 	mov	r3,dph
   0A59 AC F0              2038 	mov	r4,b
   0A5B D0 23              2039 	pop	bits
   0A5D D0 05              2040 	pop	ar5
   0A5F D0 06              2041 	pop	ar6
   0A61 E5 6D              2042 	mov	a,_bp
   0A63 24 04              2043 	add	a,#0x04
   0A65 F8                 2044 	mov	r0,a
   0A66 C3                 2045 	clr	c
   0A67 EA                 2046 	mov	a,r2
   0A68 96                 2047 	subb	a,@r0
   0A69 EB                 2048 	mov	a,r3
   0A6A 08                 2049 	inc	r0
   0A6B 96                 2050 	subb	a,@r0
   0A6C D0 07              2051 	pop	ar7
   0A6E 50 34              2052 	jnc	00130$
                    0681   2053 	C$fb_app_counter.c$313$4$10 ==.
                           2054 ;	..\fb_app_counter.c:313: if((c_para>>2)&0x03)sendbychange(obj,(c_para>>2)&0x01);
   0A70 A8 6D              2055 	mov	r0,_bp
   0A72 08                 2056 	inc	r0
   0A73 E6                 2057 	mov	a,@r0
   0A74 03                 2058 	rr	a
   0A75 03                 2059 	rr	a
   0A76 54 3F              2060 	anl	a,#0x3F
   0A78 FC                 2061 	mov	r4,a
   0A79 54 03              2062 	anl	a,#0x03
   0A7B 60 27              2063 	jz	00130$
   0A7D A8 6D              2064 	mov	r0,_bp
   0A7F 08                 2065 	inc	r0
   0A80 E6                 2066 	mov	a,@r0
   0A81 03                 2067 	rr	a
   0A82 03                 2068 	rr	a
   0A83 54 01              2069 	anl	a,#0x01
   0A85 FC                 2070 	mov	r4,a
   0A86 C0 07              2071 	push	ar7
   0A88 C0 06              2072 	push	ar6
   0A8A C0 05              2073 	push	ar5
   0A8C C0 23              2074 	push	bits
   0A8E C0 04              2075 	push	ar4
   0A90 E5 6D              2076 	mov	a,_bp
   0A92 24 03              2077 	add	a,#0x03
   0A94 F8                 2078 	mov	r0,a
   0A95 86 82              2079 	mov	dpl,@r0
   0A97 12 0A D9           2080 	lcall	_sendbychange
   0A9A 15 81              2081 	dec	sp
   0A9C D0 23              2082 	pop	bits
   0A9E D0 05              2083 	pop	ar5
   0AA0 D0 06              2084 	pop	ar6
   0AA2 D0 07              2085 	pop	ar7
   0AA4                    2086 00130$:
                    06B5   2087 	C$fb_app_counter.c$273$1$1 ==.
                           2088 ;	..\fb_app_counter.c:273: for (ctg=0;ctg<=7;ctg++){
   0AA4 0D                 2089 	inc	r5
   0AA5 02 09 42           2090 	ljmp	00128$
   0AA8                    2091 00132$:
   0AA8 85 6D 81           2092 	mov	sp,_bp
   0AAB D0 6D              2093 	pop	_bp
                    06BE   2094 	C$fb_app_counter.c$328$1$1 ==.
                    06BE   2095 	XG$checklevel$0$0 ==.
   0AAD 22                 2096 	ret
                           2097 ;------------------------------------------------------------
                           2098 ;Allocation info for local variables in function 'read_value_req'
                           2099 ;------------------------------------------------------------
                           2100 ;objno                     Allocated to registers r7 
                           2101 ;objflags                  Allocated to registers r6 
                           2102 ;------------------------------------------------------------
                    06BF   2103 	G$read_value_req$0$0 ==.
                    06BF   2104 	C$fb_app_counter.c$339$1$1 ==.
                           2105 ;	..\fb_app_counter.c:339: void read_value_req(void)
                           2106 ;	-----------------------------------------
                           2107 ;	 function read_value_req
                           2108 ;	-----------------------------------------
   0AAE                    2109 _read_value_req:
                    06BF   2110 	C$fb_app_counter.c$343$1$1 ==.
                           2111 ;	..\fb_app_counter.c:343: objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
   0AAE 85 48 82           2112 	mov	dpl,(_telegramm + 0x0003)
   0AB1 C0 49              2113 	push	(_telegramm + 0x0004)
   0AB3 12 1A 84           2114 	lcall	_find_first_objno
   0AB6 AF 82              2115 	mov	r7,dpl
   0AB8 15 81              2116 	dec	sp
                    06CB   2117 	C$fb_app_counter.c$344$1$1 ==.
                           2118 ;	..\fb_app_counter.c:344: if(objno!=0xFF) {	// falls Gruppenadresse nicht gefunden
   0ABA BF FF 02           2119 	cjne	r7,#0xFF,00109$
   0ABD 80 19              2120 	sjmp	00105$
   0ABF                    2121 00109$:
                    06D0   2122 	C$fb_app_counter.c$350$2$2 ==.
                           2123 ;	..\fb_app_counter.c:350: objflags=read_objflags(objno);		// Objekt Flags lesen
   0ABF 8F 82              2124 	mov	dpl,r7
   0AC1 C0 07              2125 	push	ar7
   0AC3 12 1A 6C           2126 	lcall	_read_objflags
   0AC6 AE 82              2127 	mov	r6,dpl
   0AC8 D0 07              2128 	pop	ar7
                    06DB   2129 	C$fb_app_counter.c$352$2$2 ==.
                           2130 ;	..\fb_app_counter.c:352: if((objflags&0x0C)==0x0C) send_obj_value(objno+0x40);// 0x40 ist bit für response Telegramm
   0ACA 53 06 0C           2131 	anl	ar6,#0x0C
   0ACD BE 0C 08           2132 	cjne	r6,#0x0C,00105$
   0AD0 74 40              2133 	mov	a,#0x40
   0AD2 2F                 2134 	add	a,r7
   0AD3 F5 82              2135 	mov	dpl,a
   0AD5 12 18 29           2136 	lcall	_send_obj_value
   0AD8                    2137 00105$:
                    06E9   2138 	C$fb_app_counter.c$354$1$1 ==.
                    06E9   2139 	XG$read_value_req$0$0 ==.
   0AD8 22                 2140 	ret
                           2141 ;------------------------------------------------------------
                           2142 ;Allocation info for local variables in function 'sendbychange'
                           2143 ;------------------------------------------------------------
                           2144 ;val                       Allocated to stack - _bp -3
                           2145 ;objno                     Allocated to registers r7 
                           2146 ;------------------------------------------------------------
                    06EA   2147 	G$sendbychange$0$0 ==.
                    06EA   2148 	C$fb_app_counter.c$357$1$1 ==.
                           2149 ;	..\fb_app_counter.c:357: void sendbychange(unsigned char objno,unsigned char val){
                           2150 ;	-----------------------------------------
                           2151 ;	 function sendbychange
                           2152 ;	-----------------------------------------
   0AD9                    2153 _sendbychange:
   0AD9 C0 6D              2154 	push	_bp
   0ADB 85 81 6D           2155 	mov	_bp,sp
   0ADE AF 82              2156 	mov	r7,dpl
                    06F1   2157 	C$fb_app_counter.c$358$1$1 ==.
                           2158 ;	..\fb_app_counter.c:358: if (val){
   0AE0 E5 6D              2159 	mov	a,_bp
   0AE2 24 FD              2160 	add	a,#0xfd
   0AE4 F8                 2161 	mov	r0,a
   0AE5 E6                 2162 	mov	a,@r0
   0AE6 60 28              2163 	jz	00106$
                    06F9   2164 	C$fb_app_counter.c$359$2$2 ==.
                           2165 ;	..\fb_app_counter.c:359: if(read_obj_value(objno)==0)write_send(objno,1);
   0AE8 8F 82              2166 	mov	dpl,r7
   0AEA C0 07              2167 	push	ar7
   0AEC 12 0B 6C           2168 	lcall	_read_obj_value
   0AEF AB 82              2169 	mov	r3,dpl
   0AF1 AC 83              2170 	mov	r4,dph
   0AF3 AD F0              2171 	mov	r5,b
   0AF5 FE                 2172 	mov	r6,a
   0AF6 D0 07              2173 	pop	ar7
   0AF8 EB                 2174 	mov	a,r3
   0AF9 4C                 2175 	orl	a,r4
   0AFA 4D                 2176 	orl	a,r5
   0AFB 4E                 2177 	orl	a,r6
   0AFC 70 36              2178 	jnz	00108$
   0AFE 74 01              2179 	mov	a,#0x01
   0B00 C0 E0              2180 	push	acc
   0B02 E4                 2181 	clr	a
   0B03 C0 E0              2182 	push	acc
   0B05 8F 82              2183 	mov	dpl,r7
   0B07 12 0B 37           2184 	lcall	_write_send
   0B0A 15 81              2185 	dec	sp
   0B0C 15 81              2186 	dec	sp
   0B0E 80 24              2187 	sjmp	00108$
   0B10                    2188 00106$:
                    0721   2189 	C$fb_app_counter.c$361$1$1 ==.
                           2190 ;	..\fb_app_counter.c:361: else if( read_obj_value(objno))write_send(objno,0);
   0B10 8F 82              2191 	mov	dpl,r7
   0B12 C0 07              2192 	push	ar7
   0B14 12 0B 6C           2193 	lcall	_read_obj_value
   0B17 AB 82              2194 	mov	r3,dpl
   0B19 AC 83              2195 	mov	r4,dph
   0B1B AD F0              2196 	mov	r5,b
   0B1D FE                 2197 	mov	r6,a
   0B1E D0 07              2198 	pop	ar7
   0B20 EB                 2199 	mov	a,r3
   0B21 4C                 2200 	orl	a,r4
   0B22 4D                 2201 	orl	a,r5
   0B23 4E                 2202 	orl	a,r6
   0B24 60 0E              2203 	jz	00108$
   0B26 E4                 2204 	clr	a
   0B27 C0 E0              2205 	push	acc
   0B29 C0 E0              2206 	push	acc
   0B2B 8F 82              2207 	mov	dpl,r7
   0B2D 12 0B 37           2208 	lcall	_write_send
   0B30 15 81              2209 	dec	sp
   0B32 15 81              2210 	dec	sp
   0B34                    2211 00108$:
   0B34 D0 6D              2212 	pop	_bp
                    0747   2213 	C$fb_app_counter.c$362$1$1 ==.
                    0747   2214 	XG$sendbychange$0$0 ==.
   0B36 22                 2215 	ret
                           2216 ;------------------------------------------------------------
                           2217 ;Allocation info for local variables in function 'write_send'
                           2218 ;------------------------------------------------------------
                           2219 ;value                     Allocated to stack - _bp -4
                           2220 ;objno                     Allocated to registers r7 
                           2221 ;------------------------------------------------------------
                    0748   2222 	G$write_send$0$0 ==.
                    0748   2223 	C$fb_app_counter.c$364$1$1 ==.
                           2224 ;	..\fb_app_counter.c:364: void write_send(unsigned char objno,unsigned int value){
                           2225 ;	-----------------------------------------
                           2226 ;	 function write_send
                           2227 ;	-----------------------------------------
   0B37                    2228 _write_send:
   0B37 C0 6D              2229 	push	_bp
   0B39 85 81 6D           2230 	mov	_bp,sp
   0B3C AF 82              2231 	mov	r7,dpl
                    074F   2232 	C$fb_app_counter.c$366$1$1 ==.
                           2233 ;	..\fb_app_counter.c:366: write_obj_value(objno,(unsigned long)value);
   0B3E E5 6D              2234 	mov	a,_bp
   0B40 24 FC              2235 	add	a,#0xfc
   0B42 F8                 2236 	mov	r0,a
   0B43 86 03              2237 	mov	ar3,@r0
   0B45 08                 2238 	inc	r0
   0B46 86 04              2239 	mov	ar4,@r0
   0B48 7D 00              2240 	mov	r5,#0x00
   0B4A 7E 00              2241 	mov	r6,#0x00
   0B4C C0 07              2242 	push	ar7
   0B4E C0 03              2243 	push	ar3
   0B50 C0 04              2244 	push	ar4
   0B52 C0 05              2245 	push	ar5
   0B54 C0 06              2246 	push	ar6
   0B56 8F 82              2247 	mov	dpl,r7
   0B58 12 0F 60           2248 	lcall	_write_obj_value
   0B5B E5 81              2249 	mov	a,sp
   0B5D 24 FC              2250 	add	a,#0xfc
   0B5F F5 81              2251 	mov	sp,a
   0B61 D0 07              2252 	pop	ar7
                    0774   2253 	C$fb_app_counter.c$367$1$1 ==.
                           2254 ;	..\fb_app_counter.c:367: send_obj_value(objno);
   0B63 8F 82              2255 	mov	dpl,r7
   0B65 12 18 29           2256 	lcall	_send_obj_value
   0B68 D0 6D              2257 	pop	_bp
                    077B   2258 	C$fb_app_counter.c$368$1$1 ==.
                    077B   2259 	XG$write_send$0$0 ==.
   0B6A 22                 2260 	ret
                           2261 ;------------------------------------------------------------
                           2262 ;Allocation info for local variables in function 'bus_return'
                           2263 ;------------------------------------------------------------
                    077C   2264 	G$bus_return$0$0 ==.
                    077C   2265 	C$fb_app_counter.c$371$1$1 ==.
                           2266 ;	..\fb_app_counter.c:371: void bus_return(void){
                           2267 ;	-----------------------------------------
                           2268 ;	 function bus_return
                           2269 ;	-----------------------------------------
   0B6B                    2270 _bus_return:
                    077C   2271 	C$fb_app_counter.c$377$1$1 ==.
                           2272 ;	..\fb_app_counter.c:377: }
                    077C   2273 	C$fb_app_counter.c$377$1$1 ==.
                    077C   2274 	XG$bus_return$0$0 ==.
   0B6B 22                 2275 	ret
                           2276 ;------------------------------------------------------------
                           2277 ;Allocation info for local variables in function 'read_obj_value'
                           2278 ;------------------------------------------------------------
                           2279 ;objno                     Allocated to registers r7 
                           2280 ;objvalue                  Allocated to stack - _bp +1
                           2281 ;objtype                   Allocated to registers 
                           2282 ;ctrno                     Allocated to registers r6 
                           2283 ;para                      Allocated to stack - _bp +5
                           2284 ;calc_para_ptr             Allocated to registers r3 
                           2285 ;tmp16                     Allocated to registers r7 r5 
                           2286 ;sloc0                     Allocated to stack - _bp +12
                           2287 ;sloc1                     Allocated to stack - _bp +13
                           2288 ;sloc2                     Allocated to stack - _bp +6
                           2289 ;sloc3                     Allocated to stack - _bp +10
                           2290 ;------------------------------------------------------------
                    077D   2291 	G$read_obj_value$0$0 ==.
                    077D   2292 	C$fb_app_counter.c$380$1$1 ==.
                           2293 ;	..\fb_app_counter.c:380: unsigned long read_obj_value(unsigned char objno)
                           2294 ;	-----------------------------------------
                           2295 ;	 function read_obj_value
                           2296 ;	-----------------------------------------
   0B6C                    2297 _read_obj_value:
   0B6C C0 6D              2298 	push	_bp
   0B6E E5 81              2299 	mov	a,sp
   0B70 F5 6D              2300 	mov	_bp,a
   0B72 24 0D              2301 	add	a,#0x0D
   0B74 F5 81              2302 	mov	sp,a
   0B76 AF 82              2303 	mov	r7,dpl
                    0789   2304 	C$fb_app_counter.c$382$1$1 ==.
                           2305 ;	..\fb_app_counter.c:382: unsigned long objvalue=0;
   0B78 A8 6D              2306 	mov	r0,_bp
   0B7A 08                 2307 	inc	r0
   0B7B E4                 2308 	clr	a
   0B7C F6                 2309 	mov	@r0,a
   0B7D 08                 2310 	inc	r0
   0B7E F6                 2311 	mov	@r0,a
   0B7F 08                 2312 	inc	r0
   0B80 F6                 2313 	mov	@r0,a
   0B81 08                 2314 	inc	r0
   0B82 F6                 2315 	mov	@r0,a
                    0794   2316 	C$fb_app_counter.c$383$1$1 ==.
                           2317 ;	..\fb_app_counter.c:383: unsigned char objtype,ctrno=0,para=0xD5;
   0B83 7E 00              2318 	mov	r6,#0x00
   0B85 E5 6D              2319 	mov	a,_bp
   0B87 24 05              2320 	add	a,#0x05
   0B89 F8                 2321 	mov	r0,a
   0B8A 76 D5              2322 	mov	@r0,#0xD5
                    079D   2323 	C$fb_app_counter.c$384$1$1 ==.
                           2324 ;	..\fb_app_counter.c:384: unsigned char calc_para_ptr=0;
   0B8C 7B 00              2325 	mov	r3,#0x00
                    079F   2326 	C$fb_app_counter.c$386$1$1 ==.
                           2327 ;	..\fb_app_counter.c:386: objtype=eeprom[eeprom[COMMSTABPTR]+objno*3+4];
   0B8E 90 1D 12           2328 	mov	dptr,#(_eeprom + 0x0012)
   0B91 E4                 2329 	clr	a
   0B92 93                 2330 	movc	a,@a+dptr
   0B93 FD                 2331 	mov	r5,a
   0B94 EF                 2332 	mov	a,r7
   0B95 75 F0 03           2333 	mov	b,#0x03
   0B98 A4                 2334 	mul	ab
   0B99 2D                 2335 	add	a,r5
   0B9A 24 04              2336 	add	a,#0x04
   0B9C 90 1D 00           2337 	mov	dptr,#_eeprom
   0B9F 93                 2338 	movc	a,@a+dptr
                    07B1   2339 	C$fb_app_counter.c$387$1$1 ==.
                           2340 ;	..\fb_app_counter.c:387: if (objno >=2 && objno <= 10){
   0BA0 BF 02 00           2341 	cjne	r7,#0x02,00165$
   0BA3                    2342 00165$:
   0BA3 40 39              2343 	jc	00102$
   0BA5 EF                 2344 	mov	a,r7
   0BA6 24 F5              2345 	add	a,#0xff - 0x0A
   0BA8 40 34              2346 	jc	00102$
                    07BB   2347 	C$fb_app_counter.c$388$2$2 ==.
                           2348 ;	..\fb_app_counter.c:388: objvalue = ((bitobj_z1 >>(objno-2)) & 0x01);
   0BAA 8F 04              2349 	mov	ar4,r7
   0BAC 7D 00              2350 	mov	r5,#0x00
   0BAE EC                 2351 	mov	a,r4
   0BAF 24 FE              2352 	add	a,#0xFE
   0BB1 FC                 2353 	mov	r4,a
   0BB2 ED                 2354 	mov	a,r5
   0BB3 34 FF              2355 	addc	a,#0xFF
   0BB5 8C F0              2356 	mov	b,r4
   0BB7 05 F0              2357 	inc	b
   0BB9 AC 38              2358 	mov	r4,_bitobj_z1
   0BBB AD 39              2359 	mov	r5,(_bitobj_z1 + 1)
   0BBD 80 07              2360 	sjmp	00169$
   0BBF                    2361 00168$:
   0BBF C3                 2362 	clr	c
   0BC0 ED                 2363 	mov	a,r5
   0BC1 13                 2364 	rrc	a
   0BC2 FD                 2365 	mov	r5,a
   0BC3 EC                 2366 	mov	a,r4
   0BC4 13                 2367 	rrc	a
   0BC5 FC                 2368 	mov	r4,a
   0BC6                    2369 00169$:
   0BC6 D5 F0 F6           2370 	djnz	b,00168$
   0BC9 53 04 01           2371 	anl	ar4,#0x01
   0BCC 7D 00              2372 	mov	r5,#0x00
   0BCE A8 6D              2373 	mov	r0,_bp
   0BD0 08                 2374 	inc	r0
   0BD1 A6 04              2375 	mov	@r0,ar4
   0BD3 08                 2376 	inc	r0
   0BD4 A6 05              2377 	mov	@r0,ar5
   0BD6 08                 2378 	inc	r0
   0BD7 76 00              2379 	mov	@r0,#0x00
   0BD9 08                 2380 	inc	r0
   0BDA 76 00              2381 	mov	@r0,#0x00
                    07ED   2382 	C$fb_app_counter.c$389$2$2 ==.
                           2383 ;	..\fb_app_counter.c:389: ctrno=1;
   0BDC 7E 01              2384 	mov	r6,#0x01
   0BDE                    2385 00102$:
                    07EF   2386 	C$fb_app_counter.c$391$1$1 ==.
                           2387 ;	..\fb_app_counter.c:391: if (objno >=15 && objno <= 23){
   0BDE BF 0F 00           2388 	cjne	r7,#0x0F,00170$
   0BE1                    2389 00170$:
   0BE1 40 39              2390 	jc	00105$
   0BE3 EF                 2391 	mov	a,r7
   0BE4 24 E8              2392 	add	a,#0xff - 0x17
   0BE6 40 34              2393 	jc	00105$
                    07F9   2394 	C$fb_app_counter.c$392$2$3 ==.
                           2395 ;	..\fb_app_counter.c:392: objvalue = ((bitobj_z2 >>(objno-15)) & 0x01);
   0BE8 8F 04              2396 	mov	ar4,r7
   0BEA 7D 00              2397 	mov	r5,#0x00
   0BEC EC                 2398 	mov	a,r4
   0BED 24 F1              2399 	add	a,#0xF1
   0BEF FC                 2400 	mov	r4,a
   0BF0 ED                 2401 	mov	a,r5
   0BF1 34 FF              2402 	addc	a,#0xFF
   0BF3 8C F0              2403 	mov	b,r4
   0BF5 05 F0              2404 	inc	b
   0BF7 AC 3A              2405 	mov	r4,_bitobj_z2
   0BF9 AD 3B              2406 	mov	r5,(_bitobj_z2 + 1)
   0BFB 80 07              2407 	sjmp	00174$
   0BFD                    2408 00173$:
   0BFD C3                 2409 	clr	c
   0BFE ED                 2410 	mov	a,r5
   0BFF 13                 2411 	rrc	a
   0C00 FD                 2412 	mov	r5,a
   0C01 EC                 2413 	mov	a,r4
   0C02 13                 2414 	rrc	a
   0C03 FC                 2415 	mov	r4,a
   0C04                    2416 00174$:
   0C04 D5 F0 F6           2417 	djnz	b,00173$
   0C07 53 04 01           2418 	anl	ar4,#0x01
   0C0A 7D 00              2419 	mov	r5,#0x00
   0C0C A8 6D              2420 	mov	r0,_bp
   0C0E 08                 2421 	inc	r0
   0C0F A6 04              2422 	mov	@r0,ar4
   0C11 08                 2423 	inc	r0
   0C12 A6 05              2424 	mov	@r0,ar5
   0C14 08                 2425 	inc	r0
   0C15 76 00              2426 	mov	@r0,#0x00
   0C17 08                 2427 	inc	r0
   0C18 76 00              2428 	mov	@r0,#0x00
                    082B   2429 	C$fb_app_counter.c$393$2$3 ==.
                           2430 ;	..\fb_app_counter.c:393: ctrno=1;
   0C1A 7E 01              2431 	mov	r6,#0x01
   0C1C                    2432 00105$:
                    082D   2433 	C$fb_app_counter.c$395$1$1 ==.
                           2434 ;	..\fb_app_counter.c:395: if(!ctrno){
   0C1C EE                 2435 	mov	a,r6
   0C1D 60 03              2436 	jz	00175$
   0C1F 02 0F 4D           2437 	ljmp	00140$
   0C22                    2438 00175$:
                    0833   2439 	C$fb_app_counter.c$396$2$4 ==.
                           2440 ;	..\fb_app_counter.c:396: if (objno <= 1){
   0C22 EF                 2441 	mov	a,r7
   0C23 24 FE              2442 	add	a,#0xff - 0x01
   0C25 40 13              2443 	jc	00108$
                    0838   2444 	C$fb_app_counter.c$397$3$5 ==.
                           2445 ;	..\fb_app_counter.c:397: ctrno=objno;//objvalue = counter_moment[objno]; Z1
   0C27 8F 06              2446 	mov	ar6,r7
                    083A   2447 	C$fb_app_counter.c$398$3$5 ==.
                           2448 ;	..\fb_app_counter.c:398: para=eeprom[0xD5]&0x0F;
   0C29 90 1D D5           2449 	mov	dptr,#(_eeprom + 0x00d5)
   0C2C E4                 2450 	clr	a
   0C2D 93                 2451 	movc	a,@a+dptr
   0C2E FD                 2452 	mov	r5,a
   0C2F E5 6D              2453 	mov	a,_bp
   0C31 24 05              2454 	add	a,#0x05
   0C33 F8                 2455 	mov	r0,a
   0C34 74 0F              2456 	mov	a,#0x0F
   0C36 5D                 2457 	anl	a,r5
   0C37 F6                 2458 	mov	@r0,a
                    0849   2459 	C$fb_app_counter.c$399$3$5 ==.
                           2460 ;	..\fb_app_counter.c:399: calc_para_ptr=0xE2;
   0C38 7B E2              2461 	mov	r3,#0xE2
   0C3A                    2462 00108$:
                    084B   2463 	C$fb_app_counter.c$401$2$4 ==.
                           2464 ;	..\fb_app_counter.c:401: if (objno>=11 && objno<=12){
   0C3A BF 0B 00           2465 	cjne	r7,#0x0B,00177$
   0C3D                    2466 00177$:
   0C3D 40 1B              2467 	jc	00110$
   0C3F EF                 2468 	mov	a,r7
   0C40 24 F3              2469 	add	a,#0xff - 0x0C
   0C42 40 16              2470 	jc	00110$
                    0855   2471 	C$fb_app_counter.c$402$3$6 ==.
                           2472 ;	..\fb_app_counter.c:402: ctrno=objno-7;//objvalue = counter_summe[objno-11]; Z1
   0C44 EF                 2473 	mov	a,r7
   0C45 24 F9              2474 	add	a,#0xF9
   0C47 FE                 2475 	mov	r6,a
                    0859   2476 	C$fb_app_counter.c$403$3$6 ==.
                           2477 ;	..\fb_app_counter.c:403: para=eeprom[0xD5]>>4;
   0C48 90 1D D5           2478 	mov	dptr,#(_eeprom + 0x00d5)
   0C4B E4                 2479 	clr	a
   0C4C 93                 2480 	movc	a,@a+dptr
   0C4D FD                 2481 	mov	r5,a
   0C4E E5 6D              2482 	mov	a,_bp
   0C50 24 05              2483 	add	a,#0x05
   0C52 F8                 2484 	mov	r0,a
   0C53 ED                 2485 	mov	a,r5
   0C54 C4                 2486 	swap	a
   0C55 54 0F              2487 	anl	a,#0x0F
   0C57 F6                 2488 	mov	@r0,a
                    0869   2489 	C$fb_app_counter.c$404$3$6 ==.
                           2490 ;	..\fb_app_counter.c:404: calc_para_ptr=0xE4;
   0C58 7B E4              2491 	mov	r3,#0xE4
   0C5A                    2492 00110$:
                    086B   2493 	C$fb_app_counter.c$406$2$4 ==.
                           2494 ;	..\fb_app_counter.c:406: if (objno >= 13 && objno<=14){
   0C5A BF 0D 00           2495 	cjne	r7,#0x0D,00180$
   0C5D                    2496 00180$:
   0C5D 40 1A              2497 	jc	00113$
   0C5F EF                 2498 	mov	a,r7
   0C60 24 F1              2499 	add	a,#0xff - 0x0E
   0C62 40 15              2500 	jc	00113$
                    0875   2501 	C$fb_app_counter.c$407$3$7 ==.
                           2502 ;	..\fb_app_counter.c:407: ctrno=objno-11;//objvalue = counter_moment[objno-11]; Z2
   0C64 EF                 2503 	mov	a,r7
   0C65 24 F5              2504 	add	a,#0xF5
   0C67 FE                 2505 	mov	r6,a
                    0879   2506 	C$fb_app_counter.c$408$3$7 ==.
                           2507 ;	..\fb_app_counter.c:408: para=eeprom[0xEB]&0x0F;
   0C68 90 1D EB           2508 	mov	dptr,#(_eeprom + 0x00eb)
   0C6B E4                 2509 	clr	a
   0C6C 93                 2510 	movc	a,@a+dptr
   0C6D FD                 2511 	mov	r5,a
   0C6E E5 6D              2512 	mov	a,_bp
   0C70 24 05              2513 	add	a,#0x05
   0C72 F8                 2514 	mov	r0,a
   0C73 74 0F              2515 	mov	a,#0x0F
   0C75 5D                 2516 	anl	a,r5
   0C76 F6                 2517 	mov	@r0,a
                    0888   2518 	C$fb_app_counter.c$409$3$7 ==.
                           2519 ;	..\fb_app_counter.c:409: calc_para_ptr=0xF8;
   0C77 7B F8              2520 	mov	r3,#0xF8
   0C79                    2521 00113$:
                    088A   2522 	C$fb_app_counter.c$411$2$4 ==.
                           2523 ;	..\fb_app_counter.c:411: if (objno>=24 && objno<=25){
   0C79 BF 18 00           2524 	cjne	r7,#0x18,00183$
   0C7C                    2525 00183$:
   0C7C 40 1B              2526 	jc	00116$
   0C7E EF                 2527 	mov	a,r7
   0C7F 24 E6              2528 	add	a,#0xff - 0x19
   0C81 40 16              2529 	jc	00116$
                    0894   2530 	C$fb_app_counter.c$412$3$8 ==.
                           2531 ;	..\fb_app_counter.c:412: ctrno=objno-18;//objvalue = counter_summe[objno-22]; Z2
   0C83 EF                 2532 	mov	a,r7
   0C84 24 EE              2533 	add	a,#0xEE
   0C86 FE                 2534 	mov	r6,a
                    0898   2535 	C$fb_app_counter.c$413$3$8 ==.
                           2536 ;	..\fb_app_counter.c:413: para=eeprom[0xEB]>>4;
   0C87 90 1D EB           2537 	mov	dptr,#(_eeprom + 0x00eb)
   0C8A E4                 2538 	clr	a
   0C8B 93                 2539 	movc	a,@a+dptr
   0C8C FF                 2540 	mov	r7,a
   0C8D E5 6D              2541 	mov	a,_bp
   0C8F 24 05              2542 	add	a,#0x05
   0C91 F8                 2543 	mov	r0,a
   0C92 EF                 2544 	mov	a,r7
   0C93 C4                 2545 	swap	a
   0C94 54 0F              2546 	anl	a,#0x0F
   0C96 F6                 2547 	mov	@r0,a
                    08A8   2548 	C$fb_app_counter.c$414$3$8 ==.
                           2549 ;	..\fb_app_counter.c:414: calc_para_ptr=0xFA;
   0C97 7B FA              2550 	mov	r3,#0xFA
   0C99                    2551 00116$:
                    08AA   2552 	C$fb_app_counter.c$416$2$4 ==.
                           2553 ;	..\fb_app_counter.c:416: if(ctrno<=3){// momentanzähler
   0C99 EE                 2554 	mov	a,r6
   0C9A 24 FC              2555 	add	a,#0xff - 0x03
   0C9C 50 03              2556 	jnc	00186$
   0C9E 02 0E 4D           2557 	ljmp	00137$
   0CA1                    2558 00186$:
                    08B2   2559 	C$fb_app_counter.c$417$3$9 ==.
                           2560 ;	..\fb_app_counter.c:417: tmp16=(unsigned int)((eeprom[calc_para_ptr]<<8)+eeprom[calc_para_ptr+1]);
   0CA1 8B 82              2561 	mov	dpl,r3
   0CA3 75 83 1D           2562 	mov	dph,#(_eeprom >> 8)
   0CA6 E4                 2563 	clr	a
   0CA7 93                 2564 	movc	a,@a+dptr
   0CA8 FD                 2565 	mov	r5,a
   0CA9 7F 00              2566 	mov	r7,#0x00
   0CAB EB                 2567 	mov	a,r3
   0CAC 04                 2568 	inc	a
   0CAD 90 1D 00           2569 	mov	dptr,#_eeprom
   0CB0 93                 2570 	movc	a,@a+dptr
   0CB1 FC                 2571 	mov	r4,a
   0CB2 7B 00              2572 	mov	r3,#0x00
   0CB4 2F                 2573 	add	a,r7
   0CB5 FF                 2574 	mov	r7,a
   0CB6 EB                 2575 	mov	a,r3
   0CB7 3D                 2576 	addc	a,r5
                    08C9   2577 	C$fb_app_counter.c$418$3$9 ==.
                           2578 ;	..\fb_app_counter.c:418: if(tmp16!=0){
   0CB8 FD                 2579 	mov	r5,a
   0CB9 4F                 2580 	orl	a,r7
   0CBA 70 03              2581 	jnz	00187$
   0CBC 02 0F 4D           2582 	ljmp	00140$
   0CBF                    2583 00187$:
                    08D0   2584 	C$fb_app_counter.c$419$1$1 ==.
                           2585 ;	..\fb_app_counter.c:419: objvalue=counter_moment[ctrno];//
   0CBF C0 07              2586 	push	ar7
   0CC1 C0 05              2587 	push	ar5
   0CC3 EE                 2588 	mov	a,r6
   0CC4 2E                 2589 	add	a,r6
   0CC5 FC                 2590 	mov	r4,a
   0CC6 24 18              2591 	add	a,#_counter_moment
   0CC8 F9                 2592 	mov	r1,a
   0CC9 87 03              2593 	mov	ar3,@r1
   0CCB 09                 2594 	inc	r1
   0CCC 87 07              2595 	mov	ar7,@r1
   0CCE A8 6D              2596 	mov	r0,_bp
   0CD0 08                 2597 	inc	r0
   0CD1 A6 03              2598 	mov	@r0,ar3
   0CD3 08                 2599 	inc	r0
   0CD4 A6 07              2600 	mov	@r0,ar7
   0CD6 08                 2601 	inc	r0
   0CD7 76 00              2602 	mov	@r0,#0x00
   0CD9 08                 2603 	inc	r0
   0CDA 76 00              2604 	mov	@r0,#0x00
                    08ED   2605 	C$fb_app_counter.c$420$4$10 ==.
                           2606 ;	..\fb_app_counter.c:420: if(para==4&&counter_moment[ctrno]>120)objvalue=((unsigned int)(counter_moment[ctrno]+67));//für 3,33 sec. signed für Windmesser Eltako misbraucht
   0CDC E5 6D              2607 	mov	a,_bp
   0CDE 24 05              2608 	add	a,#0x05
   0CE0 F8                 2609 	mov	r0,a
   0CE1 B6 04 02           2610 	cjne	@r0,#0x04,00188$
   0CE4 80 06              2611 	sjmp	00189$
   0CE6                    2612 00188$:
   0CE6 D0 05              2613 	pop	ar5
   0CE8 D0 07              2614 	pop	ar7
   0CEA 80 3B              2615 	sjmp	00119$
   0CEC                    2616 00189$:
   0CEC EC                 2617 	mov	a,r4
   0CED 24 18              2618 	add	a,#_counter_moment
   0CEF F9                 2619 	mov	r1,a
   0CF0 87 03              2620 	mov	ar3,@r1
   0CF2 09                 2621 	inc	r1
   0CF3 87 07              2622 	mov	ar7,@r1
   0CF5 C3                 2623 	clr	c
   0CF6 74 78              2624 	mov	a,#0x78
   0CF8 9B                 2625 	subb	a,r3
   0CF9 E4                 2626 	clr	a
   0CFA 9F                 2627 	subb	a,r7
   0CFB D0 05              2628 	pop	ar5
   0CFD D0 07              2629 	pop	ar7
   0CFF 50 26              2630 	jnc	00119$
   0D01 C0 07              2631 	push	ar7
   0D03 C0 05              2632 	push	ar5
   0D05 EC                 2633 	mov	a,r4
   0D06 24 18              2634 	add	a,#_counter_moment
   0D08 F9                 2635 	mov	r1,a
   0D09 87 03              2636 	mov	ar3,@r1
   0D0B 09                 2637 	inc	r1
   0D0C 87 07              2638 	mov	ar7,@r1
   0D0E 74 43              2639 	mov	a,#0x43
   0D10 2B                 2640 	add	a,r3
   0D11 FB                 2641 	mov	r3,a
   0D12 E4                 2642 	clr	a
   0D13 3F                 2643 	addc	a,r7
   0D14 FF                 2644 	mov	r7,a
   0D15 A8 6D              2645 	mov	r0,_bp
   0D17 08                 2646 	inc	r0
   0D18 A6 03              2647 	mov	@r0,ar3
   0D1A 08                 2648 	inc	r0
   0D1B A6 07              2649 	mov	@r0,ar7
   0D1D 08                 2650 	inc	r0
   0D1E 76 00              2651 	mov	@r0,#0x00
   0D20 08                 2652 	inc	r0
   0D21 76 00              2653 	mov	@r0,#0x00
                    0934   2654 	C$fb_app_counter.c$470$1$1 ==.
                           2655 ;	..\fb_app_counter.c:470: return(objvalue);
   0D23 D0 05              2656 	pop	ar5
   0D25 D0 07              2657 	pop	ar7
                    0938   2658 	C$fb_app_counter.c$420$4$10 ==.
                           2659 ;	..\fb_app_counter.c:420: if(para==4&&counter_moment[ctrno]>120)objvalue=((unsigned int)(counter_moment[ctrno]+67));//für 3,33 sec. signed für Windmesser Eltako misbraucht
   0D27                    2660 00119$:
                    0938   2661 	C$fb_app_counter.c$422$4$10 ==.
                           2662 ;	..\fb_app_counter.c:422: if(para==8){//byte 0-100%
   0D27 E5 6D              2663 	mov	a,_bp
   0D29 24 05              2664 	add	a,#0x05
   0D2B F8                 2665 	mov	r0,a
   0D2C B6 08 68           2666 	cjne	@r0,#0x08,00125$
                    0940   2667 	C$fb_app_counter.c$423$1$1 ==.
                           2668 ;	..\fb_app_counter.c:423: if(counter_moment[ctrno]<= tmp16){
   0D2F EC                 2669 	mov	a,r4
   0D30 24 18              2670 	add	a,#_counter_moment
   0D32 F9                 2671 	mov	r1,a
   0D33 87 02              2672 	mov	ar2,@r1
   0D35 09                 2673 	inc	r1
   0D36 87 03              2674 	mov	ar3,@r1
   0D38 C3                 2675 	clr	c
   0D39 EF                 2676 	mov	a,r7
   0D3A 9A                 2677 	subb	a,r2
   0D3B ED                 2678 	mov	a,r5
   0D3C 9B                 2679 	subb	a,r3
   0D3D 40 48              2680 	jc	00122$
                    0950   2681 	C$fb_app_counter.c$424$1$1 ==.
                           2682 ;	..\fb_app_counter.c:424: objvalue = 256*(unsigned long)counter_moment[ctrno];
   0D3F C0 07              2683 	push	ar7
   0D41 C0 05              2684 	push	ar5
   0D43 EC                 2685 	mov	a,r4
   0D44 24 18              2686 	add	a,#_counter_moment
   0D46 F9                 2687 	mov	r1,a
   0D47 87 03              2688 	mov	ar3,@r1
   0D49 09                 2689 	inc	r1
   0D4A 87 07              2690 	mov	ar7,@r1
   0D4C 8F 02              2691 	mov	ar2,r7
   0D4E 7D 00              2692 	mov	r5,#0x00
   0D50 A8 6D              2693 	mov	r0,_bp
   0D52 08                 2694 	inc	r0
   0D53 08                 2695 	inc	r0
   0D54 08                 2696 	inc	r0
   0D55 08                 2697 	inc	r0
   0D56 A6 05              2698 	mov	@r0,ar5
   0D58 18                 2699 	dec	r0
   0D59 A6 02              2700 	mov	@r0,ar2
   0D5B 18                 2701 	dec	r0
   0D5C A6 03              2702 	mov	@r0,ar3
   0D5E 18                 2703 	dec	r0
   0D5F 76 00              2704 	mov	@r0,#0x00
                    0972   2705 	C$fb_app_counter.c$425$6$12 ==.
                           2706 ;	..\fb_app_counter.c:425: objvalue-=counter_moment[ctrno];
   0D61 EC                 2707 	mov	a,r4
   0D62 24 18              2708 	add	a,#_counter_moment
   0D64 F9                 2709 	mov	r1,a
   0D65 87 05              2710 	mov	ar5,@r1
   0D67 09                 2711 	inc	r1
   0D68 87 07              2712 	mov	ar7,@r1
   0D6A 7B 00              2713 	mov	r3,#0x00
   0D6C 7A 00              2714 	mov	r2,#0x00
   0D6E A8 6D              2715 	mov	r0,_bp
   0D70 08                 2716 	inc	r0
   0D71 E6                 2717 	mov	a,@r0
   0D72 C3                 2718 	clr	c
   0D73 9D                 2719 	subb	a,r5
   0D74 F6                 2720 	mov	@r0,a
   0D75 08                 2721 	inc	r0
   0D76 E6                 2722 	mov	a,@r0
   0D77 9F                 2723 	subb	a,r7
   0D78 F6                 2724 	mov	@r0,a
   0D79 08                 2725 	inc	r0
   0D7A E6                 2726 	mov	a,@r0
   0D7B 9B                 2727 	subb	a,r3
   0D7C F6                 2728 	mov	@r0,a
   0D7D 08                 2729 	inc	r0
   0D7E E6                 2730 	mov	a,@r0
   0D7F 9A                 2731 	subb	a,r2
   0D80 F6                 2732 	mov	@r0,a
   0D81 D0 05              2733 	pop	ar5
   0D83 D0 07              2734 	pop	ar7
   0D85 80 10              2735 	sjmp	00125$
   0D87                    2736 00122$:
                    0998   2737 	C$fb_app_counter.c$428$6$13 ==.
                           2738 ;	..\fb_app_counter.c:428: objvalue=255;
   0D87 A8 6D              2739 	mov	r0,_bp
   0D89 08                 2740 	inc	r0
   0D8A 76 FF              2741 	mov	@r0,#0xFF
   0D8C E4                 2742 	clr	a
   0D8D 08                 2743 	inc	r0
   0D8E F6                 2744 	mov	@r0,a
   0D8F 08                 2745 	inc	r0
   0D90 F6                 2746 	mov	@r0,a
   0D91 08                 2747 	inc	r0
   0D92 F6                 2748 	mov	@r0,a
                    09A4   2749 	C$fb_app_counter.c$429$6$13 ==.
                           2750 ;	..\fb_app_counter.c:429: tmp16=1;
   0D93 7F 01              2751 	mov	r7,#0x01
   0D95 7D 00              2752 	mov	r5,#0x00
   0D97                    2753 00125$:
                    09A8   2754 	C$fb_app_counter.c$432$4$10 ==.
                           2755 ;	..\fb_app_counter.c:432: if(para==9)objvalue = 100*(unsigned long)counter_moment[ctrno];//byte 0-255%
   0D97 E5 6D              2756 	mov	a,_bp
   0D99 24 05              2757 	add	a,#0x05
   0D9B F8                 2758 	mov	r0,a
   0D9C B6 09 43           2759 	cjne	@r0,#0x09,00127$
   0D9F C0 07              2760 	push	ar7
   0DA1 C0 05              2761 	push	ar5
   0DA3 EC                 2762 	mov	a,r4
   0DA4 24 18              2763 	add	a,#_counter_moment
   0DA6 F9                 2764 	mov	r1,a
   0DA7 87 03              2765 	mov	ar3,@r1
   0DA9 09                 2766 	inc	r1
   0DAA 87 04              2767 	mov	ar4,@r1
   0DAC 8C 02              2768 	mov	ar2,r4
   0DAE 7C 00              2769 	mov	r4,#0x00
   0DB0 7F 00              2770 	mov	r7,#0x00
   0DB2 C0 03              2771 	push	ar3
   0DB4 C0 02              2772 	push	ar2
   0DB6 C0 04              2773 	push	ar4
   0DB8 C0 07              2774 	push	ar7
   0DBA 90 00 64           2775 	mov	dptr,#(0x64&0x00ff)
   0DBD E4                 2776 	clr	a
   0DBE F5 F0              2777 	mov	b,a
   0DC0 12 1B F6           2778 	lcall	__mullong
   0DC3 AB 82              2779 	mov	r3,dpl
   0DC5 AC 83              2780 	mov	r4,dph
   0DC7 AD F0              2781 	mov	r5,b
   0DC9 FF                 2782 	mov	r7,a
   0DCA E5 81              2783 	mov	a,sp
   0DCC 24 FC              2784 	add	a,#0xfc
   0DCE F5 81              2785 	mov	sp,a
   0DD0 A8 6D              2786 	mov	r0,_bp
   0DD2 08                 2787 	inc	r0
   0DD3 A6 03              2788 	mov	@r0,ar3
   0DD5 08                 2789 	inc	r0
   0DD6 A6 04              2790 	mov	@r0,ar4
   0DD8 08                 2791 	inc	r0
   0DD9 A6 05              2792 	mov	@r0,ar5
   0DDB 08                 2793 	inc	r0
   0DDC A6 07              2794 	mov	@r0,ar7
                    09EF   2795 	C$fb_app_counter.c$470$1$1 ==.
                           2796 ;	..\fb_app_counter.c:470: return(objvalue);
   0DDE D0 05              2797 	pop	ar5
   0DE0 D0 07              2798 	pop	ar7
                    09F3   2799 	C$fb_app_counter.c$432$4$10 ==.
                           2800 ;	..\fb_app_counter.c:432: if(para==9)objvalue = 100*(unsigned long)counter_moment[ctrno];//byte 0-255%
   0DE2                    2801 00127$:
                    09F3   2802 	C$fb_app_counter.c$433$4$10 ==.
                           2803 ;	..\fb_app_counter.c:433: objvalue /=tmp16;
   0DE2 7C 00              2804 	mov	r4,#0x00
   0DE4 7B 00              2805 	mov	r3,#0x00
   0DE6 C0 07              2806 	push	ar7
   0DE8 C0 05              2807 	push	ar5
   0DEA C0 04              2808 	push	ar4
   0DEC C0 03              2809 	push	ar3
   0DEE A8 6D              2810 	mov	r0,_bp
   0DF0 08                 2811 	inc	r0
   0DF1 86 82              2812 	mov	dpl,@r0
   0DF3 08                 2813 	inc	r0
   0DF4 86 83              2814 	mov	dph,@r0
   0DF6 08                 2815 	inc	r0
   0DF7 86 F0              2816 	mov	b,@r0
   0DF9 08                 2817 	inc	r0
   0DFA E6                 2818 	mov	a,@r0
   0DFB 12 1B 89           2819 	lcall	__divulong
   0DFE AB 82              2820 	mov	r3,dpl
   0E00 AC 83              2821 	mov	r4,dph
   0E02 AD F0              2822 	mov	r5,b
   0E04 FF                 2823 	mov	r7,a
   0E05 E5 81              2824 	mov	a,sp
   0E07 24 FC              2825 	add	a,#0xfc
   0E09 F5 81              2826 	mov	sp,a
   0E0B A8 6D              2827 	mov	r0,_bp
   0E0D 08                 2828 	inc	r0
   0E0E A6 03              2829 	mov	@r0,ar3
   0E10 08                 2830 	inc	r0
   0E11 A6 04              2831 	mov	@r0,ar4
   0E13 08                 2832 	inc	r0
   0E14 A6 05              2833 	mov	@r0,ar5
   0E16 08                 2834 	inc	r0
   0E17 A6 07              2835 	mov	@r0,ar7
                    0A2A   2836 	C$fb_app_counter.c$434$4$10 ==.
                           2837 ;	..\fb_app_counter.c:434: if(para==5)objvalue=eis5conversion(objvalue);//EIS5
   0E19 E5 6D              2838 	mov	a,_bp
   0E1B 24 05              2839 	add	a,#0x05
   0E1D F8                 2840 	mov	r0,a
   0E1E B6 05 02           2841 	cjne	@r0,#0x05,00196$
   0E21 80 03              2842 	sjmp	00197$
   0E23                    2843 00196$:
   0E23 02 0F 4D           2844 	ljmp	00140$
   0E26                    2845 00197$:
   0E26 A8 6D              2846 	mov	r0,_bp
   0E28 08                 2847 	inc	r0
   0E29 86 82              2848 	mov	dpl,@r0
   0E2B 08                 2849 	inc	r0
   0E2C 86 83              2850 	mov	dph,@r0
   0E2E 08                 2851 	inc	r0
   0E2F 86 F0              2852 	mov	b,@r0
   0E31 08                 2853 	inc	r0
   0E32 E6                 2854 	mov	a,@r0
   0E33 12 04 CF           2855 	lcall	_eis5conversion
   0E36 AD 82              2856 	mov	r5,dpl
   0E38 AF 83              2857 	mov	r7,dph
   0E3A A8 6D              2858 	mov	r0,_bp
   0E3C 08                 2859 	inc	r0
   0E3D A6 05              2860 	mov	@r0,ar5
   0E3F 08                 2861 	inc	r0
   0E40 A6 07              2862 	mov	@r0,ar7
   0E42 EF                 2863 	mov	a,r7
   0E43 33                 2864 	rlc	a
   0E44 95 E0              2865 	subb	a,acc
   0E46 08                 2866 	inc	r0
   0E47 F6                 2867 	mov	@r0,a
   0E48 08                 2868 	inc	r0
   0E49 F6                 2869 	mov	@r0,a
   0E4A 02 0F 4D           2870 	ljmp	00140$
   0E4D                    2871 00137$:
                    0A5E   2872 	C$fb_app_counter.c$458$3$14 ==.
                           2873 ;	..\fb_app_counter.c:458: objvalue=counter_summe[ctrno-4]/(unsigned int)(eeprom[calc_para_ptr+3] | (eeprom[calc_para_ptr+2] << 8)) |((unsigned long)(eeprom[calc_para_ptr+1] | (eeprom[calc_para_ptr] << 8)) << 16);
   0E4D EE                 2874 	mov	a,r6
   0E4E 24 FC              2875 	add	a,#0xFC
   0E50 25 E0              2876 	add	a,acc
   0E52 25 E0              2877 	add	a,acc
   0E54 24 08              2878 	add	a,#_counter_summe
   0E56 F9                 2879 	mov	r1,a
   0E57 E5 6D              2880 	mov	a,_bp
   0E59 24 06              2881 	add	a,#0x06
   0E5B F8                 2882 	mov	r0,a
   0E5C E7                 2883 	mov	a,@r1
   0E5D F6                 2884 	mov	@r0,a
   0E5E 09                 2885 	inc	r1
   0E5F E7                 2886 	mov	a,@r1
   0E60 08                 2887 	inc	r0
   0E61 F6                 2888 	mov	@r0,a
   0E62 09                 2889 	inc	r1
   0E63 E7                 2890 	mov	a,@r1
   0E64 08                 2891 	inc	r0
   0E65 F6                 2892 	mov	@r0,a
   0E66 09                 2893 	inc	r1
   0E67 E7                 2894 	mov	a,@r1
   0E68 08                 2895 	inc	r0
   0E69 F6                 2896 	mov	@r0,a
   0E6A 74 03              2897 	mov	a,#0x03
   0E6C 2B                 2898 	add	a,r3
   0E6D 90 1D 00           2899 	mov	dptr,#_eeprom
   0E70 93                 2900 	movc	a,@a+dptr
   0E71 FF                 2901 	mov	r7,a
   0E72 74 02              2902 	mov	a,#0x02
   0E74 2B                 2903 	add	a,r3
   0E75 90 1D 00           2904 	mov	dptr,#_eeprom
   0E78 93                 2905 	movc	a,@a+dptr
   0E79 FC                 2906 	mov	r4,a
   0E7A 7D 00              2907 	mov	r5,#0x00
   0E7C 8F 02              2908 	mov	ar2,r7
   0E7E 7E 00              2909 	mov	r6,#0x00
   0E80 ED                 2910 	mov	a,r5
   0E81 42 02              2911 	orl	ar2,a
   0E83 EC                 2912 	mov	a,r4
   0E84 42 06              2913 	orl	ar6,a
   0E86 8E 05              2914 	mov	ar5,r6
   0E88 7E 00              2915 	mov	r6,#0x00
   0E8A 7F 00              2916 	mov	r7,#0x00
   0E8C C0 03              2917 	push	ar3
   0E8E C0 02              2918 	push	ar2
   0E90 C0 05              2919 	push	ar5
   0E92 C0 06              2920 	push	ar6
   0E94 C0 07              2921 	push	ar7
   0E96 E5 6D              2922 	mov	a,_bp
   0E98 24 06              2923 	add	a,#0x06
   0E9A F8                 2924 	mov	r0,a
   0E9B 86 82              2925 	mov	dpl,@r0
   0E9D 08                 2926 	inc	r0
   0E9E 86 83              2927 	mov	dph,@r0
   0EA0 08                 2928 	inc	r0
   0EA1 86 F0              2929 	mov	b,@r0
   0EA3 08                 2930 	inc	r0
   0EA4 E6                 2931 	mov	a,@r0
   0EA5 12 1B 89           2932 	lcall	__divulong
   0EA8 C8                 2933 	xch	a,r0
   0EA9 E5 6D              2934 	mov	a,_bp
   0EAB 24 0A              2935 	add	a,#0x0a
   0EAD C8                 2936 	xch	a,r0
   0EAE A6 82              2937 	mov	@r0,dpl
   0EB0 08                 2938 	inc	r0
   0EB1 A6 83              2939 	mov	@r0,dph
   0EB3 08                 2940 	inc	r0
   0EB4 A6 F0              2941 	mov	@r0,b
   0EB6 08                 2942 	inc	r0
   0EB7 F6                 2943 	mov	@r0,a
   0EB8 E5 81              2944 	mov	a,sp
   0EBA 24 FC              2945 	add	a,#0xfc
   0EBC F5 81              2946 	mov	sp,a
   0EBE D0 03              2947 	pop	ar3
   0EC0 EB                 2948 	mov	a,r3
   0EC1 04                 2949 	inc	a
   0EC2 90 1D 00           2950 	mov	dptr,#_eeprom
   0EC5 93                 2951 	movc	a,@a+dptr
   0EC6 FF                 2952 	mov	r7,a
   0EC7 8B 82              2953 	mov	dpl,r3
   0EC9 75 83 1D           2954 	mov	dph,#(_eeprom >> 8)
   0ECC E4                 2955 	clr	a
   0ECD 93                 2956 	movc	a,@a+dptr
   0ECE FD                 2957 	mov	r5,a
   0ECF 7E 00              2958 	mov	r6,#0x00
   0ED1 8F 02              2959 	mov	ar2,r7
   0ED3 7B 00              2960 	mov	r3,#0x00
   0ED5 EE                 2961 	mov	a,r6
   0ED6 42 02              2962 	orl	ar2,a
   0ED8 ED                 2963 	mov	a,r5
   0ED9 42 03              2964 	orl	ar3,a
   0EDB EB                 2965 	mov	a,r3
   0EDC 33                 2966 	rlc	a
   0EDD 95 E0              2967 	subb	a,acc
   0EDF 8B 07              2968 	mov	ar7,r3
   0EE1 8A 06              2969 	mov	ar6,r2
   0EE3 E4                 2970 	clr	a
   0EE4 FB                 2971 	mov	r3,a
   0EE5 FA                 2972 	mov	r2,a
   0EE6 E5 6D              2973 	mov	a,_bp
   0EE8 24 0A              2974 	add	a,#0x0a
   0EEA F8                 2975 	mov	r0,a
   0EEB E6                 2976 	mov	a,@r0
   0EEC 42 02              2977 	orl	ar2,a
   0EEE 08                 2978 	inc	r0
   0EEF E6                 2979 	mov	a,@r0
   0EF0 42 03              2980 	orl	ar3,a
   0EF2 08                 2981 	inc	r0
   0EF3 E6                 2982 	mov	a,@r0
   0EF4 42 06              2983 	orl	ar6,a
   0EF6 08                 2984 	inc	r0
   0EF7 E6                 2985 	mov	a,@r0
   0EF8 42 07              2986 	orl	ar7,a
   0EFA A8 6D              2987 	mov	r0,_bp
   0EFC 08                 2988 	inc	r0
   0EFD A6 02              2989 	mov	@r0,ar2
   0EFF 08                 2990 	inc	r0
   0F00 A6 03              2991 	mov	@r0,ar3
   0F02 08                 2992 	inc	r0
   0F03 A6 06              2993 	mov	@r0,ar6
   0F05 08                 2994 	inc	r0
   0F06 A6 07              2995 	mov	@r0,ar7
                    0B19   2996 	C$fb_app_counter.c$459$3$14 ==.
                           2997 ;	..\fb_app_counter.c:459: switch(para){
   0F08 E5 6D              2998 	mov	a,_bp
   0F0A 24 05              2999 	add	a,#0x05
   0F0C F8                 3000 	mov	r0,a
   0F0D B6 02 02           3001 	cjne	@r0,#0x02,00198$
   0F10 80 0A              3002 	sjmp	00132$
   0F12                    3003 00198$:
   0F12 E5 6D              3004 	mov	a,_bp
   0F14 24 05              3005 	add	a,#0x05
   0F16 F8                 3006 	mov	r0,a
                    0B28   3007 	C$fb_app_counter.c$460$4$15 ==.
                           3008 ;	..\fb_app_counter.c:460: case 2:
   0F17 B6 05 33           3009 	cjne	@r0,#0x05,00140$
   0F1A 80 0D              3010 	sjmp	00133$
   0F1C                    3011 00132$:
                    0B2D   3012 	C$fb_app_counter.c$461$4$15 ==.
                           3013 ;	..\fb_app_counter.c:461: objvalue=0;
   0F1C A8 6D              3014 	mov	r0,_bp
   0F1E 08                 3015 	inc	r0
   0F1F E4                 3016 	clr	a
   0F20 F6                 3017 	mov	@r0,a
   0F21 08                 3018 	inc	r0
   0F22 F6                 3019 	mov	@r0,a
   0F23 08                 3020 	inc	r0
   0F24 F6                 3021 	mov	@r0,a
   0F25 08                 3022 	inc	r0
   0F26 F6                 3023 	mov	@r0,a
                    0B38   3024 	C$fb_app_counter.c$462$4$15 ==.
                           3025 ;	..\fb_app_counter.c:462: break;
                    0B38   3026 	C$fb_app_counter.c$463$4$15 ==.
                           3027 ;	..\fb_app_counter.c:463: case 5:
   0F27 80 24              3028 	sjmp	00140$
   0F29                    3029 00133$:
                    0B3A   3030 	C$fb_app_counter.c$464$4$15 ==.
                           3031 ;	..\fb_app_counter.c:464: objvalue=eis5conversion(objvalue);
   0F29 A8 6D              3032 	mov	r0,_bp
   0F2B 08                 3033 	inc	r0
   0F2C 86 82              3034 	mov	dpl,@r0
   0F2E 08                 3035 	inc	r0
   0F2F 86 83              3036 	mov	dph,@r0
   0F31 08                 3037 	inc	r0
   0F32 86 F0              3038 	mov	b,@r0
   0F34 08                 3039 	inc	r0
   0F35 E6                 3040 	mov	a,@r0
   0F36 12 04 CF           3041 	lcall	_eis5conversion
   0F39 AE 82              3042 	mov	r6,dpl
   0F3B AF 83              3043 	mov	r7,dph
   0F3D A8 6D              3044 	mov	r0,_bp
   0F3F 08                 3045 	inc	r0
   0F40 A6 06              3046 	mov	@r0,ar6
   0F42 08                 3047 	inc	r0
   0F43 A6 07              3048 	mov	@r0,ar7
   0F45 EF                 3049 	mov	a,r7
   0F46 33                 3050 	rlc	a
   0F47 95 E0              3051 	subb	a,acc
   0F49 08                 3052 	inc	r0
   0F4A F6                 3053 	mov	@r0,a
   0F4B 08                 3054 	inc	r0
   0F4C F6                 3055 	mov	@r0,a
                    0B5E   3056 	C$fb_app_counter.c$467$1$1 ==.
                           3057 ;	..\fb_app_counter.c:467: }
   0F4D                    3058 00140$:
                    0B5E   3059 	C$fb_app_counter.c$470$1$1 ==.
                           3060 ;	..\fb_app_counter.c:470: return(objvalue);
   0F4D A8 6D              3061 	mov	r0,_bp
   0F4F 08                 3062 	inc	r0
   0F50 86 82              3063 	mov	dpl,@r0
   0F52 08                 3064 	inc	r0
   0F53 86 83              3065 	mov	dph,@r0
   0F55 08                 3066 	inc	r0
   0F56 86 F0              3067 	mov	b,@r0
   0F58 08                 3068 	inc	r0
   0F59 E6                 3069 	mov	a,@r0
   0F5A 85 6D 81           3070 	mov	sp,_bp
   0F5D D0 6D              3071 	pop	_bp
                    0B70   3072 	C$fb_app_counter.c$471$1$1 ==.
                    0B70   3073 	XG$read_obj_value$0$0 ==.
   0F5F 22                 3074 	ret
                           3075 ;------------------------------------------------------------
                           3076 ;Allocation info for local variables in function 'write_obj_value'
                           3077 ;------------------------------------------------------------
                           3078 ;objvalue                  Allocated to stack - _bp -6
                           3079 ;objno                     Allocated to registers r7 
                           3080 ;objtype                   Allocated to registers 
                           3081 ;sloc0                     Allocated to stack - _bp +1
                           3082 ;------------------------------------------------------------
                    0B71   3083 	G$write_obj_value$0$0 ==.
                    0B71   3084 	C$fb_app_counter.c$475$1$1 ==.
                           3085 ;	..\fb_app_counter.c:475: void write_obj_value(unsigned char objno,unsigned long objvalue)
                           3086 ;	-----------------------------------------
                           3087 ;	 function write_obj_value
                           3088 ;	-----------------------------------------
   0F60                    3089 _write_obj_value:
   0F60 C0 6D              3090 	push	_bp
   0F62 E5 81              3091 	mov	a,sp
   0F64 F5 6D              3092 	mov	_bp,a
   0F66 24 04              3093 	add	a,#0x04
   0F68 F5 81              3094 	mov	sp,a
   0F6A AF 82              3095 	mov	r7,dpl
                    0B7D   3096 	C$fb_app_counter.c$479$1$1 ==.
                           3097 ;	..\fb_app_counter.c:479: objtype=eeprom[eeprom[COMMSTABPTR]+objno*3+4];
   0F6C 90 1D 12           3098 	mov	dptr,#(_eeprom + 0x0012)
   0F6F E4                 3099 	clr	a
   0F70 93                 3100 	movc	a,@a+dptr
   0F71 FE                 3101 	mov	r6,a
   0F72 EF                 3102 	mov	a,r7
   0F73 75 F0 03           3103 	mov	b,#0x03
   0F76 A4                 3104 	mul	ab
   0F77 2E                 3105 	add	a,r6
   0F78 24 04              3106 	add	a,#0x04
   0F7A 90 1D 00           3107 	mov	dptr,#_eeprom
   0F7D 93                 3108 	movc	a,@a+dptr
                    0B8F   3109 	C$fb_app_counter.c$481$1$1 ==.
                           3110 ;	..\fb_app_counter.c:481: if (objno <= 1)counter_moment[objno]=objvalue;
   0F7E EF                 3111 	mov	a,r7
   0F7F 24 FE              3112 	add	a,#0xff - 0x01
   0F81 40 14              3113 	jc	00102$
   0F83 EF                 3114 	mov	a,r7
   0F84 2F                 3115 	add	a,r7
   0F85 24 18              3116 	add	a,#_counter_moment
   0F87 F9                 3117 	mov	r1,a
   0F88 E5 6D              3118 	mov	a,_bp
   0F8A 24 FA              3119 	add	a,#0xfa
   0F8C F8                 3120 	mov	r0,a
   0F8D 86 05              3121 	mov	ar5,@r0
   0F8F 08                 3122 	inc	r0
   0F90 86 06              3123 	mov	ar6,@r0
   0F92 A7 05              3124 	mov	@r1,ar5
   0F94 09                 3125 	inc	r1
   0F95 A7 06              3126 	mov	@r1,ar6
   0F97                    3127 00102$:
                    0BA8   3128 	C$fb_app_counter.c$482$1$1 ==.
                           3129 ;	..\fb_app_counter.c:482: if (objno >=2 && objno <= 10)
   0F97 BF 02 00           3130 	cjne	r7,#0x02,00132$
   0F9A                    3131 00132$:
   0F9A 50 03              3132 	jnc	00133$
   0F9C 02 10 30           3133 	ljmp	00104$
   0F9F                    3134 00133$:
   0F9F EF                 3135 	mov	a,r7
   0FA0 24 F5              3136 	add	a,#0xff - 0x0A
   0FA2 50 03              3137 	jnc	00134$
   0FA4 02 10 30           3138 	ljmp	00104$
   0FA7                    3139 00134$:
                    0BB8   3140 	C$fb_app_counter.c$484$2$2 ==.
                           3141 ;	..\fb_app_counter.c:484: bitobj_z1 &= ~(0x01<<(objno-2));
   0FA7 8F 05              3142 	mov	ar5,r7
   0FA9 7E 00              3143 	mov	r6,#0x00
   0FAB ED                 3144 	mov	a,r5
   0FAC 24 FE              3145 	add	a,#0xFE
   0FAE FD                 3146 	mov	r5,a
   0FAF EE                 3147 	mov	a,r6
   0FB0 34 FF              3148 	addc	a,#0xFF
   0FB2 FE                 3149 	mov	r6,a
   0FB3 8D F0              3150 	mov	b,r5
   0FB5 05 F0              3151 	inc	b
   0FB7 7B 01              3152 	mov	r3,#0x01
   0FB9 7C 00              3153 	mov	r4,#0x00
   0FBB 80 06              3154 	sjmp	00136$
   0FBD                    3155 00135$:
   0FBD EB                 3156 	mov	a,r3
   0FBE 2B                 3157 	add	a,r3
   0FBF FB                 3158 	mov	r3,a
   0FC0 EC                 3159 	mov	a,r4
   0FC1 33                 3160 	rlc	a
   0FC2 FC                 3161 	mov	r4,a
   0FC3                    3162 00136$:
   0FC3 D5 F0 F7           3163 	djnz	b,00135$
   0FC6 EB                 3164 	mov	a,r3
   0FC7 F4                 3165 	cpl	a
   0FC8 FB                 3166 	mov	r3,a
   0FC9 EC                 3167 	mov	a,r4
   0FCA F4                 3168 	cpl	a
   0FCB FC                 3169 	mov	r4,a
   0FCC EB                 3170 	mov	a,r3
   0FCD 52 38              3171 	anl	_bitobj_z1,a
   0FCF EC                 3172 	mov	a,r4
   0FD0 52 39              3173 	anl	(_bitobj_z1 + 1),a
                    0BE3   3174 	C$fb_app_counter.c$485$1$1 ==.
                           3175 ;	..\fb_app_counter.c:485: bitobj_z1 |= ((objvalue&0x01)<<(objno-2));
   0FD2 C0 07              3176 	push	ar7
   0FD4 E5 6D              3177 	mov	a,_bp
   0FD6 24 FA              3178 	add	a,#0xfa
   0FD8 F8                 3179 	mov	r0,a
   0FD9 74 01              3180 	mov	a,#0x01
   0FDB 56                 3181 	anl	a,@r0
   0FDC FA                 3182 	mov	r2,a
   0FDD 7B 00              3183 	mov	r3,#0x00
   0FDF 7C 00              3184 	mov	r4,#0x00
   0FE1 7F 00              3185 	mov	r7,#0x00
   0FE3 8D F0              3186 	mov	b,r5
   0FE5 05 F0              3187 	inc	b
   0FE7 A8 6D              3188 	mov	r0,_bp
   0FE9 08                 3189 	inc	r0
   0FEA A6 02              3190 	mov	@r0,ar2
   0FEC 08                 3191 	inc	r0
   0FED A6 03              3192 	mov	@r0,ar3
   0FEF 08                 3193 	inc	r0
   0FF0 A6 04              3194 	mov	@r0,ar4
   0FF2 08                 3195 	inc	r0
   0FF3 A6 07              3196 	mov	@r0,ar7
   0FF5 18                 3197 	dec	r0
   0FF6 18                 3198 	dec	r0
   0FF7 18                 3199 	dec	r0
   0FF8 80 13              3200 	sjmp	00138$
   0FFA                    3201 00137$:
   0FFA E6                 3202 	mov	a,@r0
   0FFB 25 E0              3203 	add	a,acc
   0FFD F6                 3204 	mov	@r0,a
   0FFE 08                 3205 	inc	r0
   0FFF E6                 3206 	mov	a,@r0
   1000 33                 3207 	rlc	a
   1001 F6                 3208 	mov	@r0,a
   1002 08                 3209 	inc	r0
   1003 E6                 3210 	mov	a,@r0
   1004 33                 3211 	rlc	a
   1005 F6                 3212 	mov	@r0,a
   1006 08                 3213 	inc	r0
   1007 E6                 3214 	mov	a,@r0
   1008 33                 3215 	rlc	a
   1009 F6                 3216 	mov	@r0,a
   100A 18                 3217 	dec	r0
   100B 18                 3218 	dec	r0
   100C 18                 3219 	dec	r0
   100D                    3220 00138$:
   100D D5 F0 EA           3221 	djnz	b,00137$
   1010 AC 38              3222 	mov	r4,_bitobj_z1
   1012 AD 39              3223 	mov	r5,(_bitobj_z1 + 1)
   1014 7E 00              3224 	mov	r6,#0x00
   1016 7F 00              3225 	mov	r7,#0x00
   1018 A8 6D              3226 	mov	r0,_bp
   101A 08                 3227 	inc	r0
   101B E6                 3228 	mov	a,@r0
   101C 42 04              3229 	orl	ar4,a
   101E 08                 3230 	inc	r0
   101F E6                 3231 	mov	a,@r0
   1020 42 05              3232 	orl	ar5,a
   1022 08                 3233 	inc	r0
   1023 E6                 3234 	mov	a,@r0
   1024 42 06              3235 	orl	ar6,a
   1026 08                 3236 	inc	r0
   1027 E6                 3237 	mov	a,@r0
   1028 42 07              3238 	orl	ar7,a
   102A 8C 38              3239 	mov	_bitobj_z1,r4
   102C 8D 39              3240 	mov	(_bitobj_z1 + 1),r5
                    0C3F   3241 	C$fb_app_counter.c$494$1$1 ==.
                           3242 ;	..\fb_app_counter.c:494: if (objno>=24 && objno<=25)counter_summe[objno-22]=objvalue;
   102E D0 07              3243 	pop	ar7
                    0C41   3244 	C$fb_app_counter.c$485$1$1 ==.
                           3245 ;	..\fb_app_counter.c:485: bitobj_z1 |= ((objvalue&0x01)<<(objno-2));
   1030                    3246 00104$:
                    0C41   3247 	C$fb_app_counter.c$487$1$1 ==.
                           3248 ;	..\fb_app_counter.c:487: if (objno>=11 && objno<=12)counter_summe[objno-11]=objvalue;
   1030 BF 0B 00           3249 	cjne	r7,#0x0B,00139$
   1033                    3250 00139$:
   1033 40 23              3251 	jc	00107$
   1035 EF                 3252 	mov	a,r7
   1036 24 F3              3253 	add	a,#0xff - 0x0C
   1038 40 1E              3254 	jc	00107$
   103A EF                 3255 	mov	a,r7
   103B 24 F5              3256 	add	a,#0xF5
   103D 25 E0              3257 	add	a,acc
   103F 25 E0              3258 	add	a,acc
   1041 FE                 3259 	mov	r6,a
   1042 24 08              3260 	add	a,#_counter_summe
   1044 F8                 3261 	mov	r0,a
   1045 E5 6D              3262 	mov	a,_bp
   1047 24 FA              3263 	add	a,#0xfa
   1049 F9                 3264 	mov	r1,a
   104A E7                 3265 	mov	a,@r1
   104B F6                 3266 	mov	@r0,a
   104C 08                 3267 	inc	r0
   104D 09                 3268 	inc	r1
   104E E7                 3269 	mov	a,@r1
   104F F6                 3270 	mov	@r0,a
   1050 08                 3271 	inc	r0
   1051 09                 3272 	inc	r1
   1052 E7                 3273 	mov	a,@r1
   1053 F6                 3274 	mov	@r0,a
   1054 08                 3275 	inc	r0
   1055 09                 3276 	inc	r1
   1056 E7                 3277 	mov	a,@r1
   1057 F6                 3278 	mov	@r0,a
   1058                    3279 00107$:
                    0C69   3280 	C$fb_app_counter.c$488$1$1 ==.
                           3281 ;	..\fb_app_counter.c:488: if (objno >= 13 && objno<=14)counter_moment[objno-11]=objvalue;
   1058 BF 0D 00           3282 	cjne	r7,#0x0D,00142$
   105B                    3283 00142$:
   105B 40 1C              3284 	jc	00110$
   105D EF                 3285 	mov	a,r7
   105E 24 F1              3286 	add	a,#0xff - 0x0E
   1060 40 17              3287 	jc	00110$
   1062 EF                 3288 	mov	a,r7
   1063 24 F5              3289 	add	a,#0xF5
   1065 25 E0              3290 	add	a,acc
   1067 24 18              3291 	add	a,#_counter_moment
   1069 F9                 3292 	mov	r1,a
   106A E5 6D              3293 	mov	a,_bp
   106C 24 FA              3294 	add	a,#0xfa
   106E F8                 3295 	mov	r0,a
   106F 86 05              3296 	mov	ar5,@r0
   1071 08                 3297 	inc	r0
   1072 86 06              3298 	mov	ar6,@r0
   1074 A7 05              3299 	mov	@r1,ar5
   1076 09                 3300 	inc	r1
   1077 A7 06              3301 	mov	@r1,ar6
   1079                    3302 00110$:
                    0C8A   3303 	C$fb_app_counter.c$489$1$1 ==.
                           3304 ;	..\fb_app_counter.c:489: if (objno >=15 && objno <= 23)
   1079 BF 0F 00           3305 	cjne	r7,#0x0F,00145$
   107C                    3306 00145$:
   107C 50 03              3307 	jnc	00146$
   107E 02 11 12           3308 	ljmp	00113$
   1081                    3309 00146$:
   1081 EF                 3310 	mov	a,r7
   1082 24 E8              3311 	add	a,#0xff - 0x17
   1084 50 03              3312 	jnc	00147$
   1086 02 11 12           3313 	ljmp	00113$
   1089                    3314 00147$:
                    0C9A   3315 	C$fb_app_counter.c$491$2$3 ==.
                           3316 ;	..\fb_app_counter.c:491: bitobj_z2 &= ~(0x01<<(objno-15));
   1089 8F 05              3317 	mov	ar5,r7
   108B 7E 00              3318 	mov	r6,#0x00
   108D ED                 3319 	mov	a,r5
   108E 24 F1              3320 	add	a,#0xF1
   1090 FD                 3321 	mov	r5,a
   1091 EE                 3322 	mov	a,r6
   1092 34 FF              3323 	addc	a,#0xFF
   1094 FE                 3324 	mov	r6,a
   1095 8D F0              3325 	mov	b,r5
   1097 05 F0              3326 	inc	b
   1099 7B 01              3327 	mov	r3,#0x01
   109B 7C 00              3328 	mov	r4,#0x00
   109D 80 06              3329 	sjmp	00149$
   109F                    3330 00148$:
   109F EB                 3331 	mov	a,r3
   10A0 2B                 3332 	add	a,r3
   10A1 FB                 3333 	mov	r3,a
   10A2 EC                 3334 	mov	a,r4
   10A3 33                 3335 	rlc	a
   10A4 FC                 3336 	mov	r4,a
   10A5                    3337 00149$:
   10A5 D5 F0 F7           3338 	djnz	b,00148$
   10A8 EB                 3339 	mov	a,r3
   10A9 F4                 3340 	cpl	a
   10AA FB                 3341 	mov	r3,a
   10AB EC                 3342 	mov	a,r4
   10AC F4                 3343 	cpl	a
   10AD FC                 3344 	mov	r4,a
   10AE EB                 3345 	mov	a,r3
   10AF 52 3A              3346 	anl	_bitobj_z2,a
   10B1 EC                 3347 	mov	a,r4
   10B2 52 3B              3348 	anl	(_bitobj_z2 + 1),a
                    0CC5   3349 	C$fb_app_counter.c$492$1$1 ==.
                           3350 ;	..\fb_app_counter.c:492: bitobj_z2 |= ((objvalue&0x01)<<(objno-15));
   10B4 C0 07              3351 	push	ar7
   10B6 E5 6D              3352 	mov	a,_bp
   10B8 24 FA              3353 	add	a,#0xfa
   10BA F8                 3354 	mov	r0,a
   10BB 74 01              3355 	mov	a,#0x01
   10BD 56                 3356 	anl	a,@r0
   10BE FA                 3357 	mov	r2,a
   10BF 7B 00              3358 	mov	r3,#0x00
   10C1 7C 00              3359 	mov	r4,#0x00
   10C3 7F 00              3360 	mov	r7,#0x00
   10C5 8D F0              3361 	mov	b,r5
   10C7 05 F0              3362 	inc	b
   10C9 A8 6D              3363 	mov	r0,_bp
   10CB 08                 3364 	inc	r0
   10CC A6 02              3365 	mov	@r0,ar2
   10CE 08                 3366 	inc	r0
   10CF A6 03              3367 	mov	@r0,ar3
   10D1 08                 3368 	inc	r0
   10D2 A6 04              3369 	mov	@r0,ar4
   10D4 08                 3370 	inc	r0
   10D5 A6 07              3371 	mov	@r0,ar7
   10D7 18                 3372 	dec	r0
   10D8 18                 3373 	dec	r0
   10D9 18                 3374 	dec	r0
   10DA 80 13              3375 	sjmp	00151$
   10DC                    3376 00150$:
   10DC E6                 3377 	mov	a,@r0
   10DD 25 E0              3378 	add	a,acc
   10DF F6                 3379 	mov	@r0,a
   10E0 08                 3380 	inc	r0
   10E1 E6                 3381 	mov	a,@r0
   10E2 33                 3382 	rlc	a
   10E3 F6                 3383 	mov	@r0,a
   10E4 08                 3384 	inc	r0
   10E5 E6                 3385 	mov	a,@r0
   10E6 33                 3386 	rlc	a
   10E7 F6                 3387 	mov	@r0,a
   10E8 08                 3388 	inc	r0
   10E9 E6                 3389 	mov	a,@r0
   10EA 33                 3390 	rlc	a
   10EB F6                 3391 	mov	@r0,a
   10EC 18                 3392 	dec	r0
   10ED 18                 3393 	dec	r0
   10EE 18                 3394 	dec	r0
   10EF                    3395 00151$:
   10EF D5 F0 EA           3396 	djnz	b,00150$
   10F2 AC 3A              3397 	mov	r4,_bitobj_z2
   10F4 AD 3B              3398 	mov	r5,(_bitobj_z2 + 1)
   10F6 7E 00              3399 	mov	r6,#0x00
   10F8 7F 00              3400 	mov	r7,#0x00
   10FA A8 6D              3401 	mov	r0,_bp
   10FC 08                 3402 	inc	r0
   10FD E6                 3403 	mov	a,@r0
   10FE 42 04              3404 	orl	ar4,a
   1100 08                 3405 	inc	r0
   1101 E6                 3406 	mov	a,@r0
   1102 42 05              3407 	orl	ar5,a
   1104 08                 3408 	inc	r0
   1105 E6                 3409 	mov	a,@r0
   1106 42 06              3410 	orl	ar6,a
   1108 08                 3411 	inc	r0
   1109 E6                 3412 	mov	a,@r0
   110A 42 07              3413 	orl	ar7,a
   110C 8C 3A              3414 	mov	_bitobj_z2,r4
   110E 8D 3B              3415 	mov	(_bitobj_z2 + 1),r5
                    0D21   3416 	C$fb_app_counter.c$494$1$1 ==.
                           3417 ;	..\fb_app_counter.c:494: if (objno>=24 && objno<=25)counter_summe[objno-22]=objvalue;
   1110 D0 07              3418 	pop	ar7
                    0D23   3419 	C$fb_app_counter.c$492$1$1 ==.
                           3420 ;	..\fb_app_counter.c:492: bitobj_z2 |= ((objvalue&0x01)<<(objno-15));
   1112                    3421 00113$:
                    0D23   3422 	C$fb_app_counter.c$494$1$1 ==.
                           3423 ;	..\fb_app_counter.c:494: if (objno>=24 && objno<=25)counter_summe[objno-22]=objvalue;
   1112 BF 18 00           3424 	cjne	r7,#0x18,00152$
   1115                    3425 00152$:
   1115 40 23              3426 	jc	00118$
   1117 EF                 3427 	mov	a,r7
   1118 24 E6              3428 	add	a,#0xff - 0x19
   111A 40 1E              3429 	jc	00118$
   111C EF                 3430 	mov	a,r7
   111D 24 EA              3431 	add	a,#0xEA
   111F 25 E0              3432 	add	a,acc
   1121 25 E0              3433 	add	a,acc
   1123 FF                 3434 	mov	r7,a
   1124 24 08              3435 	add	a,#_counter_summe
   1126 F8                 3436 	mov	r0,a
   1127 E5 6D              3437 	mov	a,_bp
   1129 24 FA              3438 	add	a,#0xfa
   112B F9                 3439 	mov	r1,a
   112C E7                 3440 	mov	a,@r1
   112D F6                 3441 	mov	@r0,a
   112E 08                 3442 	inc	r0
   112F 09                 3443 	inc	r1
   1130 E7                 3444 	mov	a,@r1
   1131 F6                 3445 	mov	@r0,a
   1132 08                 3446 	inc	r0
   1133 09                 3447 	inc	r1
   1134 E7                 3448 	mov	a,@r1
   1135 F6                 3449 	mov	@r0,a
   1136 08                 3450 	inc	r0
   1137 09                 3451 	inc	r1
   1138 E7                 3452 	mov	a,@r1
   1139 F6                 3453 	mov	@r0,a
   113A                    3454 00118$:
   113A 85 6D 81           3455 	mov	sp,_bp
   113D D0 6D              3456 	pop	_bp
                    0D50   3457 	C$fb_app_counter.c$497$1$1 ==.
                    0D50   3458 	XG$write_obj_value$0$0 ==.
   113F 22                 3459 	ret
                           3460 ;------------------------------------------------------------
                           3461 ;Allocation info for local variables in function 'keypad_init'
                           3462 ;------------------------------------------------------------
                    0D51   3463 	G$keypad_init$0$0 ==.
                    0D51   3464 	C$fb_app_counter.c$499$1$1 ==.
                           3465 ;	..\fb_app_counter.c:499: void keypad_init  (void)// Eingänge 0,2 Zähler. Eingänge 1,3 Tarifumschaltung
                           3466 ;	-----------------------------------------
                           3467 ;	 function keypad_init
                           3468 ;	-----------------------------------------
   1140                    3469 _keypad_init:
                    0D51   3470 	C$fb_app_counter.c$502$1$1 ==.
                           3471 ;	..\fb_app_counter.c:502: KBPATN = 0x00;
   1140 75 93 00           3472 	mov	_KBPATN,#0x00
                    0D54   3473 	C$fb_app_counter.c$504$1$1 ==.
                           3474 ;	..\fb_app_counter.c:504: KBMASK = 0x05;
   1143 75 86 05           3475 	mov	_KBMASK,#0x05
                    0D57   3476 	C$fb_app_counter.c$506$1$1 ==.
                           3477 ;	..\fb_app_counter.c:506: KBCON = 0x00;
   1146 75 94 00           3478 	mov	_KBCON,#0x00
                    0D5A   3479 	C$fb_app_counter.c$509$1$1 ==.
                           3480 ;	..\fb_app_counter.c:509: IP1 &= 0xFD;
   1149 53 F8 FD           3481 	anl	_IP1,#0xFD
                    0D5D   3482 	C$fb_app_counter.c$510$1$1 ==.
                           3483 ;	..\fb_app_counter.c:510: IP1H &= 0xFD;
   114C 53 F7 FD           3484 	anl	_IP1H,#0xFD
                    0D60   3485 	C$fb_app_counter.c$513$1$1 ==.
                           3486 ;	..\fb_app_counter.c:513: EKBI = 1;
   114F D2 E9              3487 	setb	_IEN1_1
                    0D62   3488 	C$fb_app_counter.c$514$1$1 ==.
                    0D62   3489 	XG$keypad_init$0$0 ==.
   1151 22                 3490 	ret
                           3491 ;------------------------------------------------------------
                           3492 ;Allocation info for local variables in function 'restart_app'
                           3493 ;------------------------------------------------------------
                           3494 ;objno                     Allocated to registers r7 
                           3495 ;------------------------------------------------------------
                    0D63   3496 	G$restart_app$0$0 ==.
                    0D63   3497 	C$fb_app_counter.c$517$1$1 ==.
                           3498 ;	..\fb_app_counter.c:517: void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
                           3499 ;	-----------------------------------------
                           3500 ;	 function restart_app
                           3501 ;	-----------------------------------------
   1152                    3502 _restart_app:
                    0D63   3503 	C$fb_app_counter.c$523$1$1 ==.
                           3504 ;	..\fb_app_counter.c:523: P0M1=0x0F;	//P0 auf input only (high impedance!)
   1152 75 84 0F           3505 	mov	_P0M1,#0x0F
                    0D66   3506 	C$fb_app_counter.c$524$1$1 ==.
                           3507 ;	..\fb_app_counter.c:524: P0M2=0x00;
   1155 75 85 00           3508 	mov	_P0M2,#0x00
                    0D69   3509 	C$fb_app_counter.c$525$1$1 ==.
                           3510 ;	..\fb_app_counter.c:525: P0=0xFF;
   1158 75 80 FF           3511 	mov	_P0,#0xFF
                    0D6C   3512 	C$fb_app_counter.c$532$1$1 ==.
                           3513 ;	..\fb_app_counter.c:532: transparency=0;
   115B C2 12              3514 	clr	_transparency
                    0D6E   3515 	C$fb_app_counter.c$534$1$1 ==.
                           3516 ;	..\fb_app_counter.c:534: RTCCON=0x60;		// RTC anhalten und Flag löschen
   115D 75 D1 60           3517 	mov	_RTCCON,#0x60
                    0D71   3518 	C$fb_app_counter.c$535$1$1 ==.
                           3519 ;	..\fb_app_counter.c:535: RTCH=0x16;			//16 reload Real Time Clock
   1160 75 D2 16           3520 	mov	_RTCH,#0x16
                    0D74   3521 	C$fb_app_counter.c$536$1$1 ==.
                           3522 ;	..\fb_app_counter.c:536: RTCL=0x80;			//80 auf 100ms
   1163 75 D3 80           3523 	mov	_RTCL,#0x80
                    0D77   3524 	C$fb_app_counter.c$537$1$1 ==.
                           3525 ;	..\fb_app_counter.c:537: RTCCON=0x61;//	START_RTC	// RTC starten
   1166 75 D1 61           3526 	mov	_RTCCON,#0x61
                    0D7A   3527 	C$fb_app_counter.c$539$1$1 ==.
                           3528 ;	..\fb_app_counter.c:539: EA=0; 
   1169 C2 AF              3529 	clr	_IEN0_7
                    0D7C   3530 	C$fb_app_counter.c$540$1$1 ==.
                           3531 ;	..\fb_app_counter.c:540: START_WRITECYCLE
   116B 75 E4 00           3532 	mov	_FMCON,#0x00
                    0D7F   3533 	C$fb_app_counter.c$541$1$1 ==.
                           3534 ;	..\fb_app_counter.c:541: WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 00 76 = Robert Bosch
   116E 75 E7 1D           3535 	mov	_FMADRH,#0x1D
   1171 75 E6 03           3536 	mov	_FMADRL,#0x03
   1174 75 E5 00           3537 	mov	_FMDATA,#0x00
                    0D88   3538 	C$fb_app_counter.c$542$1$1 ==.
                           3539 ;	..\fb_app_counter.c:542: WRITE_BYTE(0x01,0x04,76)
   1177 75 E7 1D           3540 	mov	_FMADRH,#0x1D
   117A 75 E6 04           3541 	mov	_FMADRL,#0x04
   117D 75 E5 4C           3542 	mov	_FMDATA,#0x4C
                    0D91   3543 	C$fb_app_counter.c$543$1$1 ==.
                           3544 ;	..\fb_app_counter.c:543: WRITE_BYTE(0x01,0x05,0x04)	// Geräte Typ (2118) 04B0h
   1180 75 E7 1D           3545 	mov	_FMADRH,#0x1D
   1183 75 E6 05           3546 	mov	_FMADRL,#0x05
   1186 75 E5 04           3547 	mov	_FMDATA,#0x04
                    0D9A   3548 	C$fb_app_counter.c$544$1$1 ==.
                           3549 ;	..\fb_app_counter.c:544: WRITE_BYTE(0x01,0x06,0xB0)  // 	"	"	"
   1189 75 E7 1D           3550 	mov	_FMADRH,#0x1D
   118C 75 E6 06           3551 	mov	_FMADRL,#0x06
   118F 75 E5 B0           3552 	mov	_FMDATA,#0xB0
                    0DA3   3553 	C$fb_app_counter.c$545$1$1 ==.
                           3554 ;	..\fb_app_counter.c:545: WRITE_BYTE(0x01,0x07,0x01)	// Versionsnummer
   1192 75 E7 1D           3555 	mov	_FMADRH,#0x1D
   1195 75 E6 07           3556 	mov	_FMADRL,#0x07
   1198 75 E5 01           3557 	mov	_FMDATA,#0x01
                    0DAC   3558 	C$fb_app_counter.c$546$1$1 ==.
                           3559 ;	..\fb_app_counter.c:546: WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
   119B 75 E7 1D           3560 	mov	_FMADRH,#0x1D
   119E 75 E6 0C           3561 	mov	_FMADRL,#0x0C
   11A1 75 E5 00           3562 	mov	_FMDATA,#0x00
                    0DB5   3563 	C$fb_app_counter.c$547$1$1 ==.
                           3564 ;	..\fb_app_counter.c:547: WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
   11A4 75 E7 1D           3565 	mov	_FMADRH,#0x1D
   11A7 75 E6 0D           3566 	mov	_FMADRL,#0x0D
   11AA 75 E5 FF           3567 	mov	_FMDATA,#0xFF
                    0DBE   3568 	C$fb_app_counter.c$548$1$1 ==.
                           3569 ;	..\fb_app_counter.c:548: WRITE_BYTE(0x01,0x12,0x82)	// COMMSTAB Pointer
   11AD 75 E7 1D           3570 	mov	_FMADRH,#0x1D
   11B0 75 E6 12           3571 	mov	_FMADRL,#0x12
   11B3 75 E5 82           3572 	mov	_FMDATA,#0x82
                    0DC7   3573 	C$fb_app_counter.c$549$1$1 ==.
                           3574 ;	..\fb_app_counter.c:549: STOP_WRITECYCLE
   11B6 75 E4 68           3575 	mov	_FMCON,#0x68
                    0DCA   3576 	C$fb_app_counter.c$552$1$1 ==.
                           3577 ;	..\fb_app_counter.c:552: EA=1;
   11B9 D2 AF              3578 	setb	_IEN0_7
                    0DCC   3579 	C$fb_app_counter.c$554$2$2 ==.
                           3580 ;	..\fb_app_counter.c:554: for(objno=0;objno<4;objno++) {// zyclisch senden setzen
   11BB 7F 00              3581 	mov	r7,#0x00
   11BD                    3582 00101$:
   11BD BF 04 00           3583 	cjne	r7,#0x04,00110$
   11C0                    3584 00110$:
   11C0 50 29              3585 	jnc	00105$
                    0DD3   3586 	C$fb_app_counter.c$555$2$2 ==.
                           3587 ;	..\fb_app_counter.c:555: timercnt[objno]=eeprom[paraindex_timer[objno]];//Torzeit bzw timer setzen
   11C2 EF                 3588 	mov	a,r7
   11C3 24 33              3589 	add	a,#_timercnt
   11C5 F9                 3590 	mov	r1,a
   11C6 EF                 3591 	mov	a,r7
   11C7 2F                 3592 	add	a,r7
   11C8 FD                 3593 	mov	r5,a
   11C9 90 1C 72           3594 	mov	dptr,#_paraindex_timer
   11CC 93                 3595 	movc	a,@a+dptr
   11CD CD                 3596 	xch	a,r5
   11CE A3                 3597 	inc	dptr
   11CF 93                 3598 	movc	a,@a+dptr
   11D0 FE                 3599 	mov	r6,a
   11D1 8D 82              3600 	mov	dpl,r5
   11D3 74 1D              3601 	mov	a,#(_eeprom >> 8)
   11D5 2E                 3602 	add	a,r6
   11D6 F5 83              3603 	mov	dph,a
   11D8 E4                 3604 	clr	a
   11D9 93                 3605 	movc	a,@a+dptr
   11DA FC                 3606 	mov	r4,a
   11DB F7                 3607 	mov	@r1,a
                    0DED   3608 	C$fb_app_counter.c$556$2$2 ==.
                           3609 ;	..\fb_app_counter.c:556: timerbase[objno]=eeprom[paraindex_timer[objno]+1];// Basis setzen
   11DC EF                 3610 	mov	a,r7
   11DD 24 2F              3611 	add	a,#_timerbase
   11DF F9                 3612 	mov	r1,a
   11E0 ED                 3613 	mov	a,r5
   11E1 04                 3614 	inc	a
   11E2 90 1D 00           3615 	mov	dptr,#_eeprom
   11E5 93                 3616 	movc	a,@a+dptr
   11E6 FE                 3617 	mov	r6,a
   11E7 F7                 3618 	mov	@r1,a
                    0DF9   3619 	C$fb_app_counter.c$554$1$1 ==.
                           3620 ;	..\fb_app_counter.c:554: for(objno=0;objno<4;objno++) {// zyclisch senden setzen
   11E8 0F                 3621 	inc	r7
   11E9 80 D2              3622 	sjmp	00101$
   11EB                    3623 00105$:
                    0DFC   3624 	C$fb_app_counter.c$559$1$1 ==.
                    0DFC   3625 	XG$restart_app$0$0 ==.
   11EB 22                 3626 	ret
                           3627 	.area CSEG    (CODE)
                           3628 	.area CONST   (CODE)
                    0000   3629 G$paraindex_timer$0$0 == .
   1C72                    3630 _paraindex_timer:
   1C72 D6 00              3631 	.byte #0xD6,#0x00	; 214
   1C74 D8 00              3632 	.byte #0xD8,#0x00	; 216
   1C76 EC 00              3633 	.byte #0xEC,#0x00	; 236
   1C78 EE 00              3634 	.byte #0xEE,#0x00	; 238
                    0008   3635 G$objno_timer$0$0 == .
   1C7A                    3636 _objno_timer:
   1C7A 00 00              3637 	.byte #0x00,#0x00	; 0
   1C7C 0B 00              3638 	.byte #0x0B,#0x00	; 11
   1C7E 0D 00              3639 	.byte #0x0D,#0x00	; 13
   1C80 18 00              3640 	.byte #0x18,#0x00	; 24
                           3641 	.area XINIT   (CODE)
                           3642 	.area CABS    (ABS,CODE)
