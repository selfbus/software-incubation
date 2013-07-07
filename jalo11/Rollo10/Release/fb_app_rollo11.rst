                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Sun Jun 23 16:20:03 2013
                              5 ;--------------------------------------------------------
                              6 	.module fb_app_rollo11
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _svfaktorarray
                             13 	.globl _timerflagmask
                             14 	.globl _read_objflags
                             15 	.globl _send_obj_value
                             16 	.globl _P3_1
                             17 	.globl _P3_0
                             18 	.globl _P1_7
                             19 	.globl _P1_6
                             20 	.globl _P1_5
                             21 	.globl _P1_4
                             22 	.globl _P1_3
                             23 	.globl _P1_2
                             24 	.globl _P1_1
                             25 	.globl _P1_0
                             26 	.globl _P0_7
                             27 	.globl _P0_6
                             28 	.globl _P0_5
                             29 	.globl _P0_4
                             30 	.globl _P0_3
                             31 	.globl _P0_2
                             32 	.globl _P0_1
                             33 	.globl _P0_0
                             34 	.globl _I2CON_0
                             35 	.globl _I2CON_2
                             36 	.globl _I2CON_3
                             37 	.globl _I2CON_4
                             38 	.globl _I2CON_5
                             39 	.globl _I2CON_6
                             40 	.globl _SCON_7
                             41 	.globl _SCON_6
                             42 	.globl _SCON_5
                             43 	.globl _SCON_4
                             44 	.globl _SCON_3
                             45 	.globl _SCON_2
                             46 	.globl _SCON_1
                             47 	.globl _SCON_0
                             48 	.globl _IP0_0
                             49 	.globl _IP0_1
                             50 	.globl _IP0_2
                             51 	.globl _IP0_3
                             52 	.globl _IP0_4
                             53 	.globl _IP0_5
                             54 	.globl _IP0_6
                             55 	.globl _IP1_0
                             56 	.globl _IP1_1
                             57 	.globl _IP1_2
                             58 	.globl _IP1_6
                             59 	.globl _IEN1_0
                             60 	.globl _IEN1_1
                             61 	.globl _IEN1_2
                             62 	.globl _IEN0_0
                             63 	.globl _IEN0_1
                             64 	.globl _IEN0_2
                             65 	.globl _IEN0_3
                             66 	.globl _IEN0_4
                             67 	.globl _IEN0_5
                             68 	.globl _IEN0_6
                             69 	.globl _IEN0_7
                             70 	.globl _TCON_0
                             71 	.globl _TCON_1
                             72 	.globl _TCON_2
                             73 	.globl _TCON_3
                             74 	.globl _TCON_4
                             75 	.globl _TCON_5
                             76 	.globl _TCON_6
                             77 	.globl _TCON_7
                             78 	.globl _PSW_7
                             79 	.globl _PSW_6
                             80 	.globl _PSW_5
                             81 	.globl _PSW_4
                             82 	.globl _PSW_3
                             83 	.globl _PSW_2
                             84 	.globl _PSW_1
                             85 	.globl _PSW_0
                             86 	.globl _IEN1
                             87 	.globl _IP0H
                             88 	.globl _WFEED2
                             89 	.globl _WFEED1
                             90 	.globl _WDL
                             91 	.globl _WDCON
                             92 	.globl _TRIM
                             93 	.globl _TAMOD
                             94 	.globl _SSTAT
                             95 	.globl _RTCL
                             96 	.globl _RTCH
                             97 	.globl _RTCCON
                             98 	.globl _RSTSRC
                             99 	.globl _PT0AD
                            100 	.globl _PCONA
                            101 	.globl _P3M2
                            102 	.globl _P3M1
                            103 	.globl _P1M2
                            104 	.globl _P1M1
                            105 	.globl _P0M2
                            106 	.globl _P0M1
                            107 	.globl _KBPATN
                            108 	.globl _KBMASK
                            109 	.globl _KBCON
                            110 	.globl _IP1H
                            111 	.globl _IP1
                            112 	.globl _I2STAT
                            113 	.globl _I2SCLL
                            114 	.globl _I2SCLH
                            115 	.globl _I2DAT
                            116 	.globl _I2CON
                            117 	.globl _I2ADR
                            118 	.globl _FMDATA
                            119 	.globl _FMCON
                            120 	.globl _FMADRL
                            121 	.globl _FMADRH
                            122 	.globl _DIVM
                            123 	.globl _CMP2
                            124 	.globl _CMP1
                            125 	.globl _BRGCON
                            126 	.globl _BRGR1
                            127 	.globl _BRGR0
                            128 	.globl _SADEN
                            129 	.globl _SADDR
                            130 	.globl _AUXR1
                            131 	.globl _SBUF
                            132 	.globl _SCON
                            133 	.globl _IP0
                            134 	.globl _IEN0
                            135 	.globl _TH1
                            136 	.globl _TH0
                            137 	.globl _TL1
                            138 	.globl _TL0
                            139 	.globl _TMOD
                            140 	.globl _TCON
                            141 	.globl _PCON
                            142 	.globl _DPH
                            143 	.globl _DPL
                            144 	.globl _SP
                            145 	.globl _B
                            146 	.globl _ACC
                            147 	.globl _PSW
                            148 	.globl _P3
                            149 	.globl _P1
                            150 	.globl _P0
                            151 	.globl _handmode
                            152 	.globl _state
                            153 	.globl _portchanged
                            154 	.globl _ledport
                            155 	.globl _knr
                            156 	.globl _kanal
                            157 	.globl _oldblockvalue
                            158 	.globl _zfstate
                            159 	.globl _blocked
                            160 	.globl _oldportbuffer
                            161 	.globl _portbuffer
                            162 	.globl _objects_smove
                            163 	.globl _objects_move
                            164 	.globl _Tval
                            165 	.globl _delay_toggle
                            166 	.globl _timer
                            167 	.globl _timerstate
                            168 	.globl _timercnt
                            169 	.globl _timerbase
                            170 	.globl _RAM
                            171 	.globl _write_value_req
                            172 	.globl _read_value_req
                            173 	.globl _read_obj_value
                            174 	.globl _write_obj_value
                            175 	.globl _Sobject_schalten
                            176 	.globl _object_schalten
                            177 	.globl _delay_timer
                            178 	.globl _handsteuerung
                            179 	.globl _sobj_update
                            180 	.globl _set_pause
                            181 	.globl _set_entriegeln
                            182 	.globl _port_schalten
                            183 	.globl _bus_return
                            184 	.globl _restart_app
                            185 ;--------------------------------------------------------
                            186 ; special function registers
                            187 ;--------------------------------------------------------
                            188 	.area RSEG    (ABS,DATA)
   0000                     189 	.org 0x0000
                    0080    190 G$P0$0$0 == 0x0080
                    0080    191 _P0	=	0x0080
                    0090    192 G$P1$0$0 == 0x0090
                    0090    193 _P1	=	0x0090
                    00B0    194 G$P3$0$0 == 0x00b0
                    00B0    195 _P3	=	0x00b0
                    00D0    196 G$PSW$0$0 == 0x00d0
                    00D0    197 _PSW	=	0x00d0
                    00E0    198 G$ACC$0$0 == 0x00e0
                    00E0    199 _ACC	=	0x00e0
                    00F0    200 G$B$0$0 == 0x00f0
                    00F0    201 _B	=	0x00f0
                    0081    202 G$SP$0$0 == 0x0081
                    0081    203 _SP	=	0x0081
                    0082    204 G$DPL$0$0 == 0x0082
                    0082    205 _DPL	=	0x0082
                    0083    206 G$DPH$0$0 == 0x0083
                    0083    207 _DPH	=	0x0083
                    0087    208 G$PCON$0$0 == 0x0087
                    0087    209 _PCON	=	0x0087
                    0088    210 G$TCON$0$0 == 0x0088
                    0088    211 _TCON	=	0x0088
                    0089    212 G$TMOD$0$0 == 0x0089
                    0089    213 _TMOD	=	0x0089
                    008A    214 G$TL0$0$0 == 0x008a
                    008A    215 _TL0	=	0x008a
                    008B    216 G$TL1$0$0 == 0x008b
                    008B    217 _TL1	=	0x008b
                    008C    218 G$TH0$0$0 == 0x008c
                    008C    219 _TH0	=	0x008c
                    008D    220 G$TH1$0$0 == 0x008d
                    008D    221 _TH1	=	0x008d
                    00A8    222 G$IEN0$0$0 == 0x00a8
                    00A8    223 _IEN0	=	0x00a8
                    00B8    224 G$IP0$0$0 == 0x00b8
                    00B8    225 _IP0	=	0x00b8
                    0098    226 G$SCON$0$0 == 0x0098
                    0098    227 _SCON	=	0x0098
                    0099    228 G$SBUF$0$0 == 0x0099
                    0099    229 _SBUF	=	0x0099
                    00A2    230 G$AUXR1$0$0 == 0x00a2
                    00A2    231 _AUXR1	=	0x00a2
                    00A9    232 G$SADDR$0$0 == 0x00a9
                    00A9    233 _SADDR	=	0x00a9
                    00B9    234 G$SADEN$0$0 == 0x00b9
                    00B9    235 _SADEN	=	0x00b9
                    00BE    236 G$BRGR0$0$0 == 0x00be
                    00BE    237 _BRGR0	=	0x00be
                    00BF    238 G$BRGR1$0$0 == 0x00bf
                    00BF    239 _BRGR1	=	0x00bf
                    00BD    240 G$BRGCON$0$0 == 0x00bd
                    00BD    241 _BRGCON	=	0x00bd
                    00AC    242 G$CMP1$0$0 == 0x00ac
                    00AC    243 _CMP1	=	0x00ac
                    00AD    244 G$CMP2$0$0 == 0x00ad
                    00AD    245 _CMP2	=	0x00ad
                    0095    246 G$DIVM$0$0 == 0x0095
                    0095    247 _DIVM	=	0x0095
                    00E7    248 G$FMADRH$0$0 == 0x00e7
                    00E7    249 _FMADRH	=	0x00e7
                    00E6    250 G$FMADRL$0$0 == 0x00e6
                    00E6    251 _FMADRL	=	0x00e6
                    00E4    252 G$FMCON$0$0 == 0x00e4
                    00E4    253 _FMCON	=	0x00e4
                    00E5    254 G$FMDATA$0$0 == 0x00e5
                    00E5    255 _FMDATA	=	0x00e5
                    00DB    256 G$I2ADR$0$0 == 0x00db
                    00DB    257 _I2ADR	=	0x00db
                    00D8    258 G$I2CON$0$0 == 0x00d8
                    00D8    259 _I2CON	=	0x00d8
                    00DA    260 G$I2DAT$0$0 == 0x00da
                    00DA    261 _I2DAT	=	0x00da
                    00DD    262 G$I2SCLH$0$0 == 0x00dd
                    00DD    263 _I2SCLH	=	0x00dd
                    00DC    264 G$I2SCLL$0$0 == 0x00dc
                    00DC    265 _I2SCLL	=	0x00dc
                    00D9    266 G$I2STAT$0$0 == 0x00d9
                    00D9    267 _I2STAT	=	0x00d9
                    00F8    268 G$IP1$0$0 == 0x00f8
                    00F8    269 _IP1	=	0x00f8
                    00F7    270 G$IP1H$0$0 == 0x00f7
                    00F7    271 _IP1H	=	0x00f7
                    0094    272 G$KBCON$0$0 == 0x0094
                    0094    273 _KBCON	=	0x0094
                    0086    274 G$KBMASK$0$0 == 0x0086
                    0086    275 _KBMASK	=	0x0086
                    0093    276 G$KBPATN$0$0 == 0x0093
                    0093    277 _KBPATN	=	0x0093
                    0084    278 G$P0M1$0$0 == 0x0084
                    0084    279 _P0M1	=	0x0084
                    0085    280 G$P0M2$0$0 == 0x0085
                    0085    281 _P0M2	=	0x0085
                    0091    282 G$P1M1$0$0 == 0x0091
                    0091    283 _P1M1	=	0x0091
                    0092    284 G$P1M2$0$0 == 0x0092
                    0092    285 _P1M2	=	0x0092
                    00B1    286 G$P3M1$0$0 == 0x00b1
                    00B1    287 _P3M1	=	0x00b1
                    00B2    288 G$P3M2$0$0 == 0x00b2
                    00B2    289 _P3M2	=	0x00b2
                    00B5    290 G$PCONA$0$0 == 0x00b5
                    00B5    291 _PCONA	=	0x00b5
                    00F6    292 G$PT0AD$0$0 == 0x00f6
                    00F6    293 _PT0AD	=	0x00f6
                    00DF    294 G$RSTSRC$0$0 == 0x00df
                    00DF    295 _RSTSRC	=	0x00df
                    00D1    296 G$RTCCON$0$0 == 0x00d1
                    00D1    297 _RTCCON	=	0x00d1
                    00D2    298 G$RTCH$0$0 == 0x00d2
                    00D2    299 _RTCH	=	0x00d2
                    00D3    300 G$RTCL$0$0 == 0x00d3
                    00D3    301 _RTCL	=	0x00d3
                    00BA    302 G$SSTAT$0$0 == 0x00ba
                    00BA    303 _SSTAT	=	0x00ba
                    008F    304 G$TAMOD$0$0 == 0x008f
                    008F    305 _TAMOD	=	0x008f
                    0096    306 G$TRIM$0$0 == 0x0096
                    0096    307 _TRIM	=	0x0096
                    00A7    308 G$WDCON$0$0 == 0x00a7
                    00A7    309 _WDCON	=	0x00a7
                    00C1    310 G$WDL$0$0 == 0x00c1
                    00C1    311 _WDL	=	0x00c1
                    00C2    312 G$WFEED1$0$0 == 0x00c2
                    00C2    313 _WFEED1	=	0x00c2
                    00C3    314 G$WFEED2$0$0 == 0x00c3
                    00C3    315 _WFEED2	=	0x00c3
                    00B7    316 G$IP0H$0$0 == 0x00b7
                    00B7    317 _IP0H	=	0x00b7
                    00E8    318 G$IEN1$0$0 == 0x00e8
                    00E8    319 _IEN1	=	0x00e8
                            320 ;--------------------------------------------------------
                            321 ; special function bits
                            322 ;--------------------------------------------------------
                            323 	.area RSEG    (ABS,DATA)
   0000                     324 	.org 0x0000
                    00D0    325 G$PSW_0$0$0 == 0x00d0
                    00D0    326 _PSW_0	=	0x00d0
                    00D1    327 G$PSW_1$0$0 == 0x00d1
                    00D1    328 _PSW_1	=	0x00d1
                    00D2    329 G$PSW_2$0$0 == 0x00d2
                    00D2    330 _PSW_2	=	0x00d2
                    00D3    331 G$PSW_3$0$0 == 0x00d3
                    00D3    332 _PSW_3	=	0x00d3
                    00D4    333 G$PSW_4$0$0 == 0x00d4
                    00D4    334 _PSW_4	=	0x00d4
                    00D5    335 G$PSW_5$0$0 == 0x00d5
                    00D5    336 _PSW_5	=	0x00d5
                    00D6    337 G$PSW_6$0$0 == 0x00d6
                    00D6    338 _PSW_6	=	0x00d6
                    00D7    339 G$PSW_7$0$0 == 0x00d7
                    00D7    340 _PSW_7	=	0x00d7
                    008F    341 G$TCON_7$0$0 == 0x008f
                    008F    342 _TCON_7	=	0x008f
                    008E    343 G$TCON_6$0$0 == 0x008e
                    008E    344 _TCON_6	=	0x008e
                    008D    345 G$TCON_5$0$0 == 0x008d
                    008D    346 _TCON_5	=	0x008d
                    008C    347 G$TCON_4$0$0 == 0x008c
                    008C    348 _TCON_4	=	0x008c
                    008B    349 G$TCON_3$0$0 == 0x008b
                    008B    350 _TCON_3	=	0x008b
                    008A    351 G$TCON_2$0$0 == 0x008a
                    008A    352 _TCON_2	=	0x008a
                    0089    353 G$TCON_1$0$0 == 0x0089
                    0089    354 _TCON_1	=	0x0089
                    0088    355 G$TCON_0$0$0 == 0x0088
                    0088    356 _TCON_0	=	0x0088
                    00AF    357 G$IEN0_7$0$0 == 0x00af
                    00AF    358 _IEN0_7	=	0x00af
                    00AE    359 G$IEN0_6$0$0 == 0x00ae
                    00AE    360 _IEN0_6	=	0x00ae
                    00AD    361 G$IEN0_5$0$0 == 0x00ad
                    00AD    362 _IEN0_5	=	0x00ad
                    00AC    363 G$IEN0_4$0$0 == 0x00ac
                    00AC    364 _IEN0_4	=	0x00ac
                    00AB    365 G$IEN0_3$0$0 == 0x00ab
                    00AB    366 _IEN0_3	=	0x00ab
                    00AA    367 G$IEN0_2$0$0 == 0x00aa
                    00AA    368 _IEN0_2	=	0x00aa
                    00A9    369 G$IEN0_1$0$0 == 0x00a9
                    00A9    370 _IEN0_1	=	0x00a9
                    00A8    371 G$IEN0_0$0$0 == 0x00a8
                    00A8    372 _IEN0_0	=	0x00a8
                    00EA    373 G$IEN1_2$0$0 == 0x00ea
                    00EA    374 _IEN1_2	=	0x00ea
                    00E9    375 G$IEN1_1$0$0 == 0x00e9
                    00E9    376 _IEN1_1	=	0x00e9
                    00E8    377 G$IEN1_0$0$0 == 0x00e8
                    00E8    378 _IEN1_0	=	0x00e8
                    00FE    379 G$IP1_6$0$0 == 0x00fe
                    00FE    380 _IP1_6	=	0x00fe
                    00FA    381 G$IP1_2$0$0 == 0x00fa
                    00FA    382 _IP1_2	=	0x00fa
                    00F9    383 G$IP1_1$0$0 == 0x00f9
                    00F9    384 _IP1_1	=	0x00f9
                    00F8    385 G$IP1_0$0$0 == 0x00f8
                    00F8    386 _IP1_0	=	0x00f8
                    00BE    387 G$IP0_6$0$0 == 0x00be
                    00BE    388 _IP0_6	=	0x00be
                    00BD    389 G$IP0_5$0$0 == 0x00bd
                    00BD    390 _IP0_5	=	0x00bd
                    00BC    391 G$IP0_4$0$0 == 0x00bc
                    00BC    392 _IP0_4	=	0x00bc
                    00BB    393 G$IP0_3$0$0 == 0x00bb
                    00BB    394 _IP0_3	=	0x00bb
                    00BA    395 G$IP0_2$0$0 == 0x00ba
                    00BA    396 _IP0_2	=	0x00ba
                    00B9    397 G$IP0_1$0$0 == 0x00b9
                    00B9    398 _IP0_1	=	0x00b9
                    00B8    399 G$IP0_0$0$0 == 0x00b8
                    00B8    400 _IP0_0	=	0x00b8
                    0098    401 G$SCON_0$0$0 == 0x0098
                    0098    402 _SCON_0	=	0x0098
                    0099    403 G$SCON_1$0$0 == 0x0099
                    0099    404 _SCON_1	=	0x0099
                    009A    405 G$SCON_2$0$0 == 0x009a
                    009A    406 _SCON_2	=	0x009a
                    009B    407 G$SCON_3$0$0 == 0x009b
                    009B    408 _SCON_3	=	0x009b
                    009C    409 G$SCON_4$0$0 == 0x009c
                    009C    410 _SCON_4	=	0x009c
                    009D    411 G$SCON_5$0$0 == 0x009d
                    009D    412 _SCON_5	=	0x009d
                    009E    413 G$SCON_6$0$0 == 0x009e
                    009E    414 _SCON_6	=	0x009e
                    009F    415 G$SCON_7$0$0 == 0x009f
                    009F    416 _SCON_7	=	0x009f
                    00DE    417 G$I2CON_6$0$0 == 0x00de
                    00DE    418 _I2CON_6	=	0x00de
                    00DD    419 G$I2CON_5$0$0 == 0x00dd
                    00DD    420 _I2CON_5	=	0x00dd
                    00DC    421 G$I2CON_4$0$0 == 0x00dc
                    00DC    422 _I2CON_4	=	0x00dc
                    00DB    423 G$I2CON_3$0$0 == 0x00db
                    00DB    424 _I2CON_3	=	0x00db
                    00DA    425 G$I2CON_2$0$0 == 0x00da
                    00DA    426 _I2CON_2	=	0x00da
                    00D8    427 G$I2CON_0$0$0 == 0x00d8
                    00D8    428 _I2CON_0	=	0x00d8
                    0080    429 G$P0_0$0$0 == 0x0080
                    0080    430 _P0_0	=	0x0080
                    0081    431 G$P0_1$0$0 == 0x0081
                    0081    432 _P0_1	=	0x0081
                    0082    433 G$P0_2$0$0 == 0x0082
                    0082    434 _P0_2	=	0x0082
                    0083    435 G$P0_3$0$0 == 0x0083
                    0083    436 _P0_3	=	0x0083
                    0084    437 G$P0_4$0$0 == 0x0084
                    0084    438 _P0_4	=	0x0084
                    0085    439 G$P0_5$0$0 == 0x0085
                    0085    440 _P0_5	=	0x0085
                    0086    441 G$P0_6$0$0 == 0x0086
                    0086    442 _P0_6	=	0x0086
                    0087    443 G$P0_7$0$0 == 0x0087
                    0087    444 _P0_7	=	0x0087
                    0090    445 G$P1_0$0$0 == 0x0090
                    0090    446 _P1_0	=	0x0090
                    0091    447 G$P1_1$0$0 == 0x0091
                    0091    448 _P1_1	=	0x0091
                    0092    449 G$P1_2$0$0 == 0x0092
                    0092    450 _P1_2	=	0x0092
                    0093    451 G$P1_3$0$0 == 0x0093
                    0093    452 _P1_3	=	0x0093
                    0094    453 G$P1_4$0$0 == 0x0094
                    0094    454 _P1_4	=	0x0094
                    0095    455 G$P1_5$0$0 == 0x0095
                    0095    456 _P1_5	=	0x0095
                    0096    457 G$P1_6$0$0 == 0x0096
                    0096    458 _P1_6	=	0x0096
                    0097    459 G$P1_7$0$0 == 0x0097
                    0097    460 _P1_7	=	0x0097
                    00B0    461 G$P3_0$0$0 == 0x00b0
                    00B0    462 _P3_0	=	0x00b0
                    00B1    463 G$P3_1$0$0 == 0x00b1
                    00B1    464 _P3_1	=	0x00b1
                            465 ;--------------------------------------------------------
                            466 ; overlayable register banks
                            467 ;--------------------------------------------------------
                            468 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     469 	.ds 8
                            470 ;--------------------------------------------------------
                            471 ; overlayable bit register bank
                            472 ;--------------------------------------------------------
                            473 	.area BIT_BANK	(REL,OVR,DATA)
   0023                     474 bits:
   0023                     475 	.ds 1
                    8000    476 	b0 = bits[0]
                    8100    477 	b1 = bits[1]
                    8200    478 	b2 = bits[2]
                    8300    479 	b3 = bits[3]
                    8400    480 	b4 = bits[4]
                    8500    481 	b5 = bits[5]
                    8600    482 	b6 = bits[6]
                    8700    483 	b7 = bits[7]
                            484 ;--------------------------------------------------------
                            485 ; internal ram data
                            486 ;--------------------------------------------------------
                            487 	.area DSEG    (DATA)
                    0000    488 G$RAM$0$0 == 0x0000
                    0000    489 _RAM	=	0x0000
                    0010    490 G$timerbase$0$0 == 0x0010
                    0010    491 _timerbase	=	0x0010
                    0000    492 G$timercnt$0$0==.
   0024                     493 _timercnt::
   0024                     494 	.ds 16
                    0010    495 G$timerstate$0$0==.
   0034                     496 _timerstate::
   0034                     497 	.ds 16
                    0009    498 G$timer$0$0 == 0x0009
                    0009    499 _timer	=	0x0009
                    0009    500 G$delay_toggle$0$0 == 0x0009
                    0009    501 _delay_toggle	=	0x0009
                    0020    502 G$Tval$0$0==.
   0044                     503 _Tval::
   0044                     504 	.ds 1
                    000B    505 G$objects_move$0$0 == 0x000b
                    000B    506 _objects_move	=	0x000b
                    000C    507 G$objects_smove$0$0 == 0x000c
                    000C    508 _objects_smove	=	0x000c
                    000D    509 G$portbuffer$0$0 == 0x000d
                    000D    510 _portbuffer	=	0x000d
                    000E    511 G$oldportbuffer$0$0 == 0x000e
                    000E    512 _oldportbuffer	=	0x000e
                    000F    513 G$blocked$0$0 == 0x000f
                    000F    514 _blocked	=	0x000f
                    0021    515 G$zfstate$0$0==.
   0045                     516 _zfstate::
   0045                     517 	.ds 1
                    0022    518 G$oldblockvalue$0$0==.
   0046                     519 _oldblockvalue::
   0046                     520 	.ds 1
                    0023    521 G$kanal$0$0==.
   0047                     522 _kanal::
   0047                     523 	.ds 4
                    0027    524 G$knr$0$0==.
   004B                     525 _knr::
   004B                     526 	.ds 1
                    0028    527 G$ledport$0$0==.
   004C                     528 _ledport::
   004C                     529 	.ds 1
                            530 ;--------------------------------------------------------
                            531 ; overlayable items in internal ram 
                            532 ;--------------------------------------------------------
                            533 	.area OSEG    (OVR,DATA)
                            534 ;--------------------------------------------------------
                            535 ; indirectly addressable internal ram data
                            536 ;--------------------------------------------------------
                            537 	.area ISEG    (DATA)
                            538 ;--------------------------------------------------------
                            539 ; absolute internal ram data
                            540 ;--------------------------------------------------------
                            541 	.area IABS    (ABS,DATA)
                            542 	.area IABS    (ABS,DATA)
                            543 ;--------------------------------------------------------
                            544 ; bit data
                            545 ;--------------------------------------------------------
                            546 	.area BSEG    (BIT)
                    0000    547 G$portchanged$0$0==.
   0000                     548 _portchanged::
   0000                     549 	.ds 1
                    0001    550 G$state$0$0==.
   0001                     551 _state::
   0001                     552 	.ds 1
                    0002    553 G$handmode$0$0==.
   0002                     554 _handmode::
   0002                     555 	.ds 1
                            556 ;--------------------------------------------------------
                            557 ; paged external ram data
                            558 ;--------------------------------------------------------
                            559 	.area PSEG    (PAG,XDATA)
                            560 ;--------------------------------------------------------
                            561 ; external ram data
                            562 ;--------------------------------------------------------
                            563 	.area XSEG    (XDATA)
                            564 ;--------------------------------------------------------
                            565 ; absolute external ram data
                            566 ;--------------------------------------------------------
                            567 	.area XABS    (ABS,XDATA)
                            568 ;--------------------------------------------------------
                            569 ; external initialized ram data
                            570 ;--------------------------------------------------------
                            571 	.area XISEG   (XDATA)
                            572 	.area HOME    (CODE)
                            573 	.area GSINIT0 (CODE)
                            574 	.area GSINIT1 (CODE)
                            575 	.area GSINIT2 (CODE)
                            576 	.area GSINIT3 (CODE)
                            577 	.area GSINIT4 (CODE)
                            578 	.area GSINIT5 (CODE)
                            579 	.area GSINIT  (CODE)
                            580 	.area GSFINAL (CODE)
                            581 	.area CSEG    (CODE)
                            582 ;--------------------------------------------------------
                            583 ; global & static initialisations
                            584 ;--------------------------------------------------------
                            585 	.area HOME    (CODE)
                            586 	.area GSINIT  (CODE)
                            587 	.area GSFINAL (CODE)
                            588 	.area GSINIT  (CODE)
                            589 ;--------------------------------------------------------
                            590 ; Home
                            591 ;--------------------------------------------------------
                            592 	.area HOME    (CODE)
                            593 	.area HOME    (CODE)
                            594 ;--------------------------------------------------------
                            595 ; code
                            596 ;--------------------------------------------------------
                            597 	.area CSEG    (CODE)
                            598 ;------------------------------------------------------------
                            599 ;Allocation info for local variables in function 'write_value_req'
                            600 ;------------------------------------------------------------
                            601 ;objno                     Allocated to registers r7 
                            602 ;------------------------------------------------------------
                    0000    603 	G$write_value_req$0$0 ==.
                    0000    604 	C$fb_app_rollo11.c$73$0$0 ==.
                            605 ;	..\fb_app_rollo11.c:73: void write_value_req(unsigned char objno) 				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
                            606 ;	-----------------------------------------
                            607 ;	 function write_value_req
                            608 ;	-----------------------------------------
   020A                     609 _write_value_req:
                    0007    610 	ar7 = 0x07
                    0006    611 	ar6 = 0x06
                    0005    612 	ar5 = 0x05
                    0004    613 	ar4 = 0x04
                    0003    614 	ar3 = 0x03
                    0002    615 	ar2 = 0x02
                    0001    616 	ar1 = 0x01
                    0000    617 	ar0 = 0x00
   020A AF 82               618 	mov	r7,dpl
                    0002    619 	C$fb_app_rollo11.c$93$1$1 ==.
                            620 ;	..\fb_app_rollo11.c:93: if (objno<8 && !handmode) object_schalten(objno,telegramm[7]&0x01);	// Objektnummer 0-4 entspricht den Kanälen 1-4
   020C BF 08 00            621 	cjne	r7,#0x08,00113$
   020F                     622 00113$:
   020F 50 19               623 	jnc	00102$
   0211 20 02 16            624 	jb	_handmode,00102$
   0214 E5 5B               625 	mov	a,(_telegramm + 0x0007)
   0216 54 01               626 	anl	a,#0x01
   0218 24 FF               627 	add	a,#0xff
   021A 92 18               628 	mov  b0,c
   021C 92 F0               629 	mov	b[0],c
   021E C0 07               630 	push	ar7
   0220 85 F0 23            631 	mov	bits,b
   0223 8F 82               632 	mov	dpl,r7
   0225 12 04 95            633 	lcall	_object_schalten
   0228 D0 07               634 	pop	ar7
   022A                     635 00102$:
                    0020    636 	C$fb_app_rollo11.c$95$1$1 ==.
                            637 ;	..\fb_app_rollo11.c:95: if (objno>=16 && objno<=17)Sobject_schalten(objno,telegramm[7]&0x01);	// Objektnummer 16+17 entspricht den Sicherheitsfahrten 1 + 2
   022A BF 10 00            638 	cjne	r7,#0x10,00116$
   022D                     639 00116$:
   022D 40 13               640 	jc	00107$
   022F EF                  641 	mov	a,r7
   0230 24 EE               642 	add	a,#0xff - 0x11
   0232 40 0E               643 	jc	00107$
   0234 74 01               644 	mov	a,#0x01
   0236 55 5B               645 	anl	a,(_telegramm + 0x0007)
   0238 FE                  646 	mov	r6,a
   0239 C0 06               647 	push	ar6
   023B 8F 82               648 	mov	dpl,r7
   023D 12 03 2B            649 	lcall	_Sobject_schalten
   0240 15 81               650 	dec	sp
   0242                     651 00107$:
                    0038    652 	C$fb_app_rollo11.c$104$1$1 ==.
                    0038    653 	XG$write_value_req$0$0 ==.
   0242 22                  654 	ret
                            655 ;------------------------------------------------------------
                            656 ;Allocation info for local variables in function 'read_value_req'
                            657 ;------------------------------------------------------------
                            658 ;objno                     Allocated to registers r7 
                            659 ;------------------------------------------------------------
                    0039    660 	G$read_value_req$0$0 ==.
                    0039    661 	C$fb_app_rollo11.c$221$1$1 ==.
                            662 ;	..\fb_app_rollo11.c:221: void read_value_req(unsigned char objno)// Sendet nach Leseanfrage objektwert auf den BUS
                            663 ;	-----------------------------------------
                            664 ;	 function read_value_req
                            665 ;	-----------------------------------------
   0243                     666 _read_value_req:
   0243 AF 82               667 	mov	r7,dpl
                    003B    668 	C$fb_app_rollo11.c$223$1$1 ==.
                            669 ;	..\fb_app_rollo11.c:223: send_obj_value(objno+64);
   0245 74 40               670 	mov	a,#0x40
   0247 2F                  671 	add	a,r7
   0248 F5 82               672 	mov	dpl,a
   024A 12 13 D8            673 	lcall	_send_obj_value
                    0043    674 	C$fb_app_rollo11.c$237$1$1 ==.
                    0043    675 	XG$read_value_req$0$0 ==.
   024D 22                  676 	ret
                            677 ;------------------------------------------------------------
                            678 ;Allocation info for local variables in function 'read_obj_value'
                            679 ;------------------------------------------------------------
                            680 ;objno                     Allocated to registers r7 
                            681 ;ret_val                   Allocated to registers r6 
                            682 ;------------------------------------------------------------
                    0044    683 	G$read_obj_value$0$0 ==.
                    0044    684 	C$fb_app_rollo11.c$240$1$1 ==.
                            685 ;	..\fb_app_rollo11.c:240: unsigned long read_obj_value(unsigned char objno) 	// gibt den Wert eines Objektes zurueck
                            686 ;	-----------------------------------------
                            687 ;	 function read_obj_value
                            688 ;	-----------------------------------------
   024E                     689 _read_obj_value:
   024E AF 82               690 	mov	r7,dpl
                    0046    691 	C$fb_app_rollo11.c$242$1$1 ==.
                            692 ;	..\fb_app_rollo11.c:242: unsigned char ret_val=0;
   0250 7E 00               693 	mov	r6,#0x00
                    0048    694 	C$fb_app_rollo11.c$244$1$1 ==.
                            695 ;	..\fb_app_rollo11.c:244: if(objno<8) {
   0252 BF 08 00            696 	cjne	r7,#0x08,00113$
   0255                     697 00113$:
   0255 50 25               698 	jnc	00106$
                    004D    699 	C$fb_app_rollo11.c$245$2$2 ==.
                            700 ;	..\fb_app_rollo11.c:245: if(objects_move &(1<<objno)) ret_val=1;
   0257 8F F0               701 	mov	b,r7
   0259 05 F0               702 	inc	b
   025B 7C 01               703 	mov	r4,#0x01
   025D 7D 00               704 	mov	r5,#0x00
   025F 80 06               705 	sjmp	00116$
   0261                     706 00115$:
   0261 EC                  707 	mov	a,r4
   0262 2C                  708 	add	a,r4
   0263 FC                  709 	mov	r4,a
   0264 ED                  710 	mov	a,r5
   0265 33                  711 	rlc	a
   0266 FD                  712 	mov	r5,a
   0267                     713 00116$:
   0267 D5 F0 F7            714 	djnz	b,00115$
   026A AA 0B               715 	mov	r2,_objects_move
   026C 7B 00               716 	mov	r3,#0x00
   026E EA                  717 	mov	a,r2
   026F 52 04               718 	anl	ar4,a
   0271 EB                  719 	mov	a,r3
   0272 52 05               720 	anl	ar5,a
   0274 EC                  721 	mov	a,r4
   0275 4D                  722 	orl	a,r5
   0276 60 30               723 	jz	00107$
   0278 7E 01               724 	mov	r6,#0x01
   027A 80 2C               725 	sjmp	00107$
   027C                     726 00106$:
                    0072    727 	C$fb_app_rollo11.c$248$2$3 ==.
                            728 ;	..\fb_app_rollo11.c:248: if(objects_smove&(1<<(objno-16))) ret_val=1;
   027C 7D 00               729 	mov	r5,#0x00
   027E EF                  730 	mov	a,r7
   027F 24 F0               731 	add	a,#0xF0
   0281 FF                  732 	mov	r7,a
   0282 ED                  733 	mov	a,r5
   0283 34 FF               734 	addc	a,#0xFF
   0285 8F F0               735 	mov	b,r7
   0287 05 F0               736 	inc	b
   0289 7F 01               737 	mov	r7,#0x01
   028B 7D 00               738 	mov	r5,#0x00
   028D 80 06               739 	sjmp	00119$
   028F                     740 00118$:
   028F EF                  741 	mov	a,r7
   0290 2F                  742 	add	a,r7
   0291 FF                  743 	mov	r7,a
   0292 ED                  744 	mov	a,r5
   0293 33                  745 	rlc	a
   0294 FD                  746 	mov	r5,a
   0295                     747 00119$:
   0295 D5 F0 F7            748 	djnz	b,00118$
   0298 AB 0C               749 	mov	r3,_objects_smove
   029A 7C 00               750 	mov	r4,#0x00
   029C EB                  751 	mov	a,r3
   029D 52 07               752 	anl	ar7,a
   029F EC                  753 	mov	a,r4
   02A0 52 05               754 	anl	ar5,a
   02A2 EF                  755 	mov	a,r7
   02A3 4D                  756 	orl	a,r5
   02A4 60 02               757 	jz	00107$
   02A6 7E 01               758 	mov	r6,#0x01
   02A8                     759 00107$:
                    009E    760 	C$fb_app_rollo11.c$250$1$1 ==.
                            761 ;	..\fb_app_rollo11.c:250: return(ret_val);
   02A8 7F 00               762 	mov	r7,#0x00
   02AA 7D 00               763 	mov	r5,#0x00
   02AC 7C 00               764 	mov	r4,#0x00
   02AE 8E 82               765 	mov	dpl,r6
   02B0 8F 83               766 	mov	dph,r7
   02B2 8D F0               767 	mov	b,r5
   02B4 EC                  768 	mov	a,r4
                    00AB    769 	C$fb_app_rollo11.c$251$1$1 ==.
                    00AB    770 	XG$read_obj_value$0$0 ==.
   02B5 22                  771 	ret
                            772 ;------------------------------------------------------------
                            773 ;Allocation info for local variables in function 'write_obj_value'
                            774 ;------------------------------------------------------------
                            775 ;objvalue                  Allocated to stack - _bp -4
                            776 ;objno                     Allocated to registers r7 
                            777 ;------------------------------------------------------------
                    00AC    778 	G$write_obj_value$0$0 ==.
                    00AC    779 	C$fb_app_rollo11.c$254$1$1 ==.
                            780 ;	..\fb_app_rollo11.c:254: void write_obj_value(unsigned char objno,unsigned int objvalue)	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
                            781 ;	-----------------------------------------
                            782 ;	 function write_obj_value
                            783 ;	-----------------------------------------
   02B6                     784 _write_obj_value:
   02B6 C0 08               785 	push	_bp
   02B8 85 81 08            786 	mov	_bp,sp
   02BB AF 82               787 	mov	r7,dpl
                    00B3    788 	C$fb_app_rollo11.c$256$1$1 ==.
                            789 ;	..\fb_app_rollo11.c:256: if(objno<8) {// kurz und lanzeit
   02BD BF 08 00            790 	cjne	r7,#0x08,00115$
   02C0                     791 00115$:
   02C0 50 32               792 	jnc	00108$
                    00B8    793 	C$fb_app_rollo11.c$257$2$2 ==.
                            794 ;	..\fb_app_rollo11.c:257: if(objvalue==0) objects_move &= 0xFF-(1<<objno);
   02C2 E5 08               795 	mov	a,_bp
   02C4 24 FC               796 	add	a,#0xfc
   02C6 F8                  797 	mov	r0,a
   02C7 E6                  798 	mov	a,@r0
   02C8 08                  799 	inc	r0
   02C9 46                  800 	orl	a,@r0
   02CA 70 16               801 	jnz	00102$
   02CC 8F F0               802 	mov	b,r7
   02CE 05 F0               803 	inc	b
   02D0 74 01               804 	mov	a,#0x01
   02D2 80 02               805 	sjmp	00120$
   02D4                     806 00118$:
   02D4 25 E0               807 	add	a,acc
   02D6                     808 00120$:
   02D6 D5 F0 FB            809 	djnz	b,00118$
   02D9 FE                  810 	mov	r6,a
   02DA 74 FF               811 	mov	a,#0xFF
   02DC C3                  812 	clr	c
   02DD 9E                  813 	subb	a,r6
   02DE 52 0B               814 	anl	_objects_move,a
   02E0 80 46               815 	sjmp	00110$
   02E2                     816 00102$:
                    00D8    817 	C$fb_app_rollo11.c$258$2$2 ==.
                            818 ;	..\fb_app_rollo11.c:258: else objects_move |=1<<objno;
   02E2 8F F0               819 	mov	b,r7
   02E4 05 F0               820 	inc	b
   02E6 74 01               821 	mov	a,#0x01
   02E8 80 02               822 	sjmp	00123$
   02EA                     823 00121$:
   02EA 25 E0               824 	add	a,acc
   02EC                     825 00123$:
   02EC D5 F0 FB            826 	djnz	b,00121$
   02EF FE                  827 	mov	r6,a
   02F0 42 0B               828 	orl	_objects_move,a
   02F2 80 34               829 	sjmp	00110$
   02F4                     830 00108$:
                    00EA    831 	C$fb_app_rollo11.c$261$2$3 ==.
                            832 ;	..\fb_app_rollo11.c:261: objno-=16;// sicherheitsfahrt 16+17
   02F4 EF                  833 	mov	a,r7
   02F5 24 F0               834 	add	a,#0xF0
   02F7 FF                  835 	mov	r7,a
                    00EE    836 	C$fb_app_rollo11.c$262$2$3 ==.
                            837 ;	..\fb_app_rollo11.c:262: if(objvalue==0) objects_smove &= (0xFF-(1<<objno));
   02F8 E5 08               838 	mov	a,_bp
   02FA 24 FC               839 	add	a,#0xfc
   02FC F8                  840 	mov	r0,a
   02FD E6                  841 	mov	a,@r0
   02FE 08                  842 	inc	r0
   02FF 46                  843 	orl	a,@r0
   0300 70 16               844 	jnz	00105$
   0302 8F F0               845 	mov	b,r7
   0304 05 F0               846 	inc	b
   0306 74 01               847 	mov	a,#0x01
   0308 80 02               848 	sjmp	00127$
   030A                     849 00125$:
   030A 25 E0               850 	add	a,acc
   030C                     851 00127$:
   030C D5 F0 FB            852 	djnz	b,00125$
   030F FE                  853 	mov	r6,a
   0310 74 FF               854 	mov	a,#0xFF
   0312 C3                  855 	clr	c
   0313 9E                  856 	subb	a,r6
   0314 52 0C               857 	anl	_objects_smove,a
   0316 80 10               858 	sjmp	00110$
   0318                     859 00105$:
                    010E    860 	C$fb_app_rollo11.c$263$2$3 ==.
                            861 ;	..\fb_app_rollo11.c:263: else objects_smove |=1<<objno;
   0318 8F F0               862 	mov	b,r7
   031A 05 F0               863 	inc	b
   031C 74 01               864 	mov	a,#0x01
   031E 80 02               865 	sjmp	00130$
   0320                     866 00128$:
   0320 25 E0               867 	add	a,acc
   0322                     868 00130$:
   0322 D5 F0 FB            869 	djnz	b,00128$
   0325 FF                  870 	mov	r7,a
   0326 42 0C               871 	orl	_objects_smove,a
   0328                     872 00110$:
   0328 D0 08               873 	pop	_bp
                    0120    874 	C$fb_app_rollo11.c$265$1$1 ==.
                    0120    875 	XG$write_obj_value$0$0 ==.
   032A 22                  876 	ret
                            877 ;------------------------------------------------------------
                            878 ;Allocation info for local variables in function 'Sobject_schalten'
                            879 ;------------------------------------------------------------
                            880 ;val                       Allocated to stack - _bp -3
                            881 ;objno                     Allocated to registers r7 
                            882 ;k                         Allocated to registers r5 
                            883 ;zuordnung                 Allocated to registers r7 
                            884 ;sobj                      Allocated to registers r6 
                            885 ;blockstart                Allocated to registers r7 
                            886 ;blockend                  Allocated to registers r6 
                            887 ;action                    Allocated to registers r4 
                            888 ;------------------------------------------------------------
                    0121    889 	G$Sobject_schalten$0$0 ==.
                    0121    890 	C$fb_app_rollo11.c$267$1$1 ==.
                            891 ;	..\fb_app_rollo11.c:267: void Sobject_schalten(unsigned char objno,unsigned char val)// Schaltet die Sicherheitsfunktionen
                            892 ;	-----------------------------------------
                            893 ;	 function Sobject_schalten
                            894 ;	-----------------------------------------
   032B                     895 _Sobject_schalten:
   032B C0 08               896 	push	_bp
   032D 85 81 08            897 	mov	_bp,sp
                    0126    898 	C$fb_app_rollo11.c$271$1$1 ==.
                            899 ;	..\fb_app_rollo11.c:271: if (objno >18){				// wenn bypass aus delay timer...
   0330 E5 82               900 	mov	a,dpl
   0332 FF                  901 	mov	r7,a
   0333 24 ED               902 	add	a,#0xff - 0x12
   0335 50 0F               903 	jnc	00102$
                    012D    904 	C$fb_app_rollo11.c$272$2$2 ==.
                            905 ;	..\fb_app_rollo11.c:272: sobj=objno&0x01;	// dann sobj ausfiltern
   0337 74 01               906 	mov	a,#0x01
   0339 5F                  907 	anl	a,r7
   033A FE                  908 	mov	r6,a
                    0131    909 	C$fb_app_rollo11.c$273$2$2 ==.
                            910 ;	..\fb_app_rollo11.c:273: state=0;				//state so setzen damit sperre aktiv wird
   033B C2 01               911 	clr	_state
                    0133    912 	C$fb_app_rollo11.c$274$2$2 ==.
                            913 ;	..\fb_app_rollo11.c:274: val=0x01;		// dto für objektvalue
   033D E5 08               914 	mov	a,_bp
   033F 24 FD               915 	add	a,#0xfd
   0341 F8                  916 	mov	r0,a
   0342 76 01               917 	mov	@r0,#0x01
   0344 80 31               918 	sjmp	00103$
   0346                     919 00102$:
                    013C    920 	C$fb_app_rollo11.c$277$2$3 ==.
                            921 ;	..\fb_app_rollo11.c:277: sobj=objno-16;				//sobj ("Sicherheitsobjektnummer")ist also 0 für Sicherheit1, 1 für Si 2
   0346 EF                  922 	mov	a,r7
   0347 24 F0               923 	add	a,#0xF0
   0349 FE                  924 	mov	r6,a
                    0140    925 	C$fb_app_rollo11.c$278$2$3 ==.
                            926 ;	..\fb_app_rollo11.c:278: state=!((eeprom[0xE2])& (0x40<<sobj));//Polarität
   034A 90 1D E2            927 	mov	dptr,#(_eeprom + 0x00e2)
   034D E4                  928 	clr	a
   034E 93                  929 	movc	a,@a+dptr
   034F FD                  930 	mov	r5,a
   0350 8E F0               931 	mov	b,r6
   0352 05 F0               932 	inc	b
   0354 7B 40               933 	mov	r3,#0x40
   0356 7C 00               934 	mov	r4,#0x00
   0358 80 06               935 	sjmp	00132$
   035A                     936 00131$:
   035A EB                  937 	mov	a,r3
   035B 2B                  938 	add	a,r3
   035C FB                  939 	mov	r3,a
   035D EC                  940 	mov	a,r4
   035E 33                  941 	rlc	a
   035F FC                  942 	mov	r4,a
   0360                     943 00132$:
   0360 D5 F0 F7            944 	djnz	b,00131$
   0363 7A 00               945 	mov	r2,#0x00
   0365 ED                  946 	mov	a,r5
   0366 52 03               947 	anl	ar3,a
   0368 EA                  948 	mov	a,r2
   0369 52 04               949 	anl	ar4,a
   036B EB                  950 	mov	a,r3
   036C 4C                  951 	orl	a,r4
   036D B4 01 00            952 	cjne	a,#0x01,00133$
   0370                     953 00133$:
   0370 E4                  954 	clr	a
   0371 33                  955 	rlc	a
   0372 FB                  956 	mov	r3,a
   0373 24 FF               957 	add	a,#0xff
   0375 92 01               958 	mov	_state,c
   0377                     959 00103$:
                    016D    960 	C$fb_app_rollo11.c$281$1$1 ==.
                            961 ;	..\fb_app_rollo11.c:281: write_obj_value(objno & 0x1F ,val);		// Objektwert im userram speichern
   0377 E5 08               962 	mov	a,_bp
   0379 24 FD               963 	add	a,#0xfd
   037B F8                  964 	mov	r0,a
   037C 86 04               965 	mov	ar4,@r0
   037E 7D 00               966 	mov	r5,#0x00
   0380 53 07 1F            967 	anl	ar7,#0x1F
   0383 C0 06               968 	push	ar6
   0385 C0 04               969 	push	ar4
   0387 C0 05               970 	push	ar5
   0389 8F 82               971 	mov	dpl,r7
   038B 12 02 B6            972 	lcall	_write_obj_value
   038E 15 81               973 	dec	sp
   0390 15 81               974 	dec	sp
   0392 D0 06               975 	pop	ar6
                    018A    976 	C$fb_app_rollo11.c$283$1$1 ==.
                            977 ;	..\fb_app_rollo11.c:283: if (state^(__bit)val) zfstate=zfstate |(0x0F<<(sobj<<2));// setzen der sicherhfahrt 1 in zfstate, xor verknüpft die polarität
   0394 E5 08               978 	mov	a,_bp
   0396 24 FD               979 	add	a,#0xfd
   0398 F8                  980 	mov	r0,a
   0399 E6                  981 	mov	a,@r0
   039A 24 FF               982 	add	a,#0xff
   039C 92 18               983 	mov  b0,c
   039E 30 01 01            984 	jnb	_state,00134$
   03A1 B3                  985 	cpl	c
   03A2                     986 00134$:
   03A2 50 17               987 	jnc	00105$
   03A4 EE                  988 	mov	a,r6
   03A5 2E                  989 	add	a,r6
   03A6 25 E0               990 	add	a,acc
   03A8 FF                  991 	mov	r7,a
   03A9 8F F0               992 	mov	b,r7
   03AB 05 F0               993 	inc	b
   03AD 74 0F               994 	mov	a,#0x0F
   03AF 80 02               995 	sjmp	00138$
   03B1                     996 00136$:
   03B1 25 E0               997 	add	a,acc
   03B3                     998 00138$:
   03B3 D5 F0 FB            999 	djnz	b,00136$
   03B6 FF                 1000 	mov	r7,a
   03B7 42 45              1001 	orl	_zfstate,a
   03B9 80 21              1002 	sjmp	00106$
   03BB                    1003 00105$:
                    01B1   1004 	C$fb_app_rollo11.c$285$2$4 ==.
                           1005 ;	..\fb_app_rollo11.c:285: zfstate=zfstate & (0xFF-(0x0F<<(sobj<<2)));//in zfstate sind für sich1 0F und sich2 F0
   03BB EE                 1006 	mov	a,r6
   03BC 2E                 1007 	add	a,r6
   03BD 25 E0              1008 	add	a,acc
   03BF FF                 1009 	mov	r7,a
   03C0 8F F0              1010 	mov	b,r7
   03C2 05 F0              1011 	inc	b
   03C4 74 0F              1012 	mov	a,#0x0F
   03C6 80 02              1013 	sjmp	00141$
   03C8                    1014 00139$:
   03C8 25 E0              1015 	add	a,acc
   03CA                    1016 00141$:
   03CA D5 F0 FB           1017 	djnz	b,00139$
   03CD FF                 1018 	mov	r7,a
   03CE 74 FF              1019 	mov	a,#0xFF
   03D0 C3                 1020 	clr	c
   03D1 9F                 1021 	subb	a,r7
   03D2 52 45              1022 	anl	_zfstate,a
                    01CA   1023 	C$fb_app_rollo11.c$286$2$4 ==.
                           1024 ;	..\fb_app_rollo11.c:286: set_entriegeln(sobj + 9);// Update objekt macht refresh auf Zeit 9/10  Zyklusüberwachung
   03D4 74 09              1025 	mov	a,#0x09
   03D6 2E                 1026 	add	a,r6
   03D7 F5 82              1027 	mov	dpl,a
   03D9 12 0B AD           1028 	lcall	_set_entriegeln
   03DC                    1029 00106$:
                    01D2   1030 	C$fb_app_rollo11.c$288$1$1 ==.
                           1031 ;	..\fb_app_rollo11.c:288: zuordnung=eeprom[0xF1] & zfstate;//in zuordnung jetzt eine 1 für jede sicherheit 
   03DC 90 1D F1           1032 	mov	dptr,#(_eeprom + 0x00f1)
   03DF E4                 1033 	clr	a
   03E0 93                 1034 	movc	a,@a+dptr
   03E1 FF                 1035 	mov	r7,a
   03E2 E5 45              1036 	mov	a,_zfstate
   03E4 52 07              1037 	anl	ar7,a
                    01DC   1038 	C$fb_app_rollo11.c$289$1$1 ==.
                           1039 ;	..\fb_app_rollo11.c:289: blocked =zuordnung |((zuordnung >>4) | (zuordnung<<4)); //beide Sicherheitsergebnisse verodern..
   03E6 EF                 1040 	mov	a,r7
   03E7 C4                 1041 	swap	a
   03E8 4F                 1042 	orl	a,r7
   03E9 F5 0F              1043 	mov	_blocked,a
                    01E1   1044 	C$fb_app_rollo11.c$291$1$1 ==.
                           1045 ;	..\fb_app_rollo11.c:291: blockstart= blocked & ~oldblockvalue;//steigende Flanke der Blockade(sicherheit)
   03EB E5 46              1046 	mov	a,_oldblockvalue
   03ED F4                 1047 	cpl	a
   03EE FF                 1048 	mov	r7,a
   03EF E5 0F              1049 	mov	a,_blocked
   03F1 52 07              1050 	anl	ar7,a
                    01E9   1051 	C$fb_app_rollo11.c$292$1$1 ==.
                           1052 ;	..\fb_app_rollo11.c:292: blockend= ~blocked & oldblockvalue;	//fallende Flanke der Blockade(sicherheit)
   03F3 E5 0F              1053 	mov	a,_blocked
   03F5 F4                 1054 	cpl	a
   03F6 FE                 1055 	mov	r6,a
   03F7 E5 46              1056 	mov	a,_oldblockvalue
   03F9 52 06              1057 	anl	ar6,a
                    01F1   1058 	C$fb_app_rollo11.c$296$1$1 ==.
                           1059 ;	..\fb_app_rollo11.c:296: if (!handmode){
   03FB 30 02 03           1060 	jnb	_handmode,00142$
   03FE 02 04 92           1061 	ljmp	00119$
   0401                    1062 00142$:
                    01F7   1063 	C$fb_app_rollo11.c$297$2$5 ==.
                           1064 ;	..\fb_app_rollo11.c:297: oldblockvalue=blocked;
   0401 85 0F 46           1065 	mov	_oldblockvalue,_blocked
                    01FA   1066 	C$fb_app_rollo11.c$299$2$1 ==.
                           1067 ;	..\fb_app_rollo11.c:299: for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
   0404 7D 00              1068 	mov	r5,#0x00
   0406                    1069 00115$:
   0406 ED                 1070 	mov	a,r5
   0407 24 FC              1071 	add	a,#0xff - 0x03
   0409 50 03              1072 	jnc	00143$
   040B 02 04 92           1073 	ljmp	00119$
   040E                    1074 00143$:
                    0204   1075 	C$fb_app_rollo11.c$300$3$6 ==.
                           1076 ;	..\fb_app_rollo11.c:300: action=0;
   040E 7C 00              1077 	mov	r4,#0x00
                    0206   1078 	C$fb_app_rollo11.c$301$3$6 ==.
                           1079 ;	..\fb_app_rollo11.c:301: if(blockstart & 0x01){
   0410 EF                 1080 	mov	a,r7
   0411 30 E0 24           1081 	jnb	acc.0,00108$
                    020A   1082 	C$fb_app_rollo11.c$302$2$1 ==.
                           1083 ;	..\fb_app_rollo11.c:302: action=(eeprom[0xF0]>>(k<<1))&0x03;
   0414 C0 06              1084 	push	ar6
   0416 90 1D F0           1085 	mov	dptr,#(_eeprom + 0x00f0)
   0419 E4                 1086 	clr	a
   041A 93                 1087 	movc	a,@a+dptr
   041B FB                 1088 	mov	r3,a
   041C 8D 02              1089 	mov	ar2,r5
   041E E4                 1090 	clr	a
   041F CA                 1091 	xch	a,r2
   0420 25 E0              1092 	add	a,acc
   0422 CA                 1093 	xch	a,r2
   0423 33                 1094 	rlc	a
   0424 FE                 1095 	mov	r6,a
   0425 8A F0              1096 	mov	b,r2
   0427 05 F0              1097 	inc	b
   0429 EB                 1098 	mov	a,r3
   042A 80 02              1099 	sjmp	00146$
   042C                    1100 00145$:
   042C C3                 1101 	clr	c
   042D 13                 1102 	rrc	a
   042E                    1103 00146$:
   042E D5 F0 FB           1104 	djnz	b,00145$
   0431 FB                 1105 	mov	r3,a
   0432 74 03              1106 	mov	a,#0x03
   0434 5B                 1107 	anl	a,r3
   0435 FC                 1108 	mov	r4,a
                    022C   1109 	C$fb_app_rollo11.c$299$2$1 ==.
                           1110 ;	..\fb_app_rollo11.c:299: for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
   0436 D0 06              1111 	pop	ar6
                    022E   1112 	C$fb_app_rollo11.c$302$3$6 ==.
                           1113 ;	..\fb_app_rollo11.c:302: action=(eeprom[0xF0]>>(k<<1))&0x03;
   0438                    1114 00108$:
                    022E   1115 	C$fb_app_rollo11.c$304$3$6 ==.
                           1116 ;	..\fb_app_rollo11.c:304: if(blockend & 0x01){
   0438 EE                 1117 	mov	a,r6
   0439 30 E0 24           1118 	jnb	acc.0,00110$
                    0232   1119 	C$fb_app_rollo11.c$305$2$1 ==.
                           1120 ;	..\fb_app_rollo11.c:305: action=(eeprom[0xEF]>>(k<<1))&0x03;
   043C C0 06              1121 	push	ar6
   043E 90 1D EF           1122 	mov	dptr,#(_eeprom + 0x00ef)
   0441 E4                 1123 	clr	a
   0442 93                 1124 	movc	a,@a+dptr
   0443 FB                 1125 	mov	r3,a
   0444 8D 02              1126 	mov	ar2,r5
   0446 E4                 1127 	clr	a
   0447 CA                 1128 	xch	a,r2
   0448 25 E0              1129 	add	a,acc
   044A CA                 1130 	xch	a,r2
   044B 33                 1131 	rlc	a
   044C FE                 1132 	mov	r6,a
   044D 8A F0              1133 	mov	b,r2
   044F 05 F0              1134 	inc	b
   0451 EB                 1135 	mov	a,r3
   0452 80 02              1136 	sjmp	00149$
   0454                    1137 00148$:
   0454 C3                 1138 	clr	c
   0455 13                 1139 	rrc	a
   0456                    1140 00149$:
   0456 D5 F0 FB           1141 	djnz	b,00148$
   0459 FB                 1142 	mov	r3,a
   045A 74 03              1143 	mov	a,#0x03
   045C 5B                 1144 	anl	a,r3
   045D FC                 1145 	mov	r4,a
                    0254   1146 	C$fb_app_rollo11.c$299$2$1 ==.
                           1147 ;	..\fb_app_rollo11.c:299: for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
   045E D0 06              1148 	pop	ar6
                    0256   1149 	C$fb_app_rollo11.c$305$3$6 ==.
                           1150 ;	..\fb_app_rollo11.c:305: action=(eeprom[0xEF]>>(k<<1))&0x03;
   0460                    1151 00110$:
                    0256   1152 	C$fb_app_rollo11.c$307$3$6 ==.
                           1153 ;	..\fb_app_rollo11.c:307: if(action){
   0460 EC                 1154 	mov	a,r4
   0461 60 23              1155 	jz	00112$
                    0259   1156 	C$fb_app_rollo11.c$308$4$9 ==.
                           1157 ;	..\fb_app_rollo11.c:308: object_schalten(k+12,action>>1);
   0463 EC                 1158 	mov	a,r4
   0464 C3                 1159 	clr	c
   0465 13                 1160 	rrc	a
   0466 24 FF              1161 	add	a,#0xff
   0468 92 18              1162 	mov	b0,c
   046A 74 0C              1163 	mov	a,#0x0C
   046C 2D                 1164 	add	a,r5
   046D FC                 1165 	mov	r4,a
   046E A2 18              1166 	mov	c,b0
   0470 92 F0              1167 	mov	b[0],c
   0472 C0 07              1168 	push	ar7
   0474 C0 06              1169 	push	ar6
   0476 C0 05              1170 	push	ar5
   0478 85 F0 23           1171 	mov	bits,b
   047B 8C 82              1172 	mov	dpl,r4
   047D 12 04 95           1173 	lcall	_object_schalten
   0480 D0 05              1174 	pop	ar5
   0482 D0 06              1175 	pop	ar6
   0484 D0 07              1176 	pop	ar7
   0486                    1177 00112$:
                    027C   1178 	C$fb_app_rollo11.c$310$3$6 ==.
                           1179 ;	..\fb_app_rollo11.c:310: blockend=blockend>>1;
   0486 EE                 1180 	mov	a,r6
   0487 C3                 1181 	clr	c
   0488 13                 1182 	rrc	a
   0489 FE                 1183 	mov	r6,a
                    0280   1184 	C$fb_app_rollo11.c$311$3$6 ==.
                           1185 ;	..\fb_app_rollo11.c:311: blockstart=blockstart>>1;
   048A EF                 1186 	mov	a,r7
   048B C3                 1187 	clr	c
   048C 13                 1188 	rrc	a
   048D FF                 1189 	mov	r7,a
                    0284   1190 	C$fb_app_rollo11.c$299$2$5 ==.
                           1191 ;	..\fb_app_rollo11.c:299: for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
   048E 0D                 1192 	inc	r5
   048F 02 04 06           1193 	ljmp	00115$
   0492                    1194 00119$:
   0492 D0 08              1195 	pop	_bp
                    028A   1196 	C$fb_app_rollo11.c$314$2$1 ==.
                    028A   1197 	XG$Sobject_schalten$0$0 ==.
   0494 22                 1198 	ret
                           1199 ;------------------------------------------------------------
                           1200 ;Allocation info for local variables in function 'object_schalten'
                           1201 ;------------------------------------------------------------
                           1202 ;objstate                  Allocated to registers b0 
                           1203 ;objno                     Allocated to registers r7 
                           1204 ;port_pattern              Allocated to registers 
                           1205 ;objflags                  Allocated to registers r3 
                           1206 ;kwin                      Allocated to stack - _bp +1
                           1207 ;kwout                     Allocated to registers r5 
                           1208 ;faktor                    Allocated to registers r3 
                           1209 ;lz_ue                     Allocated to stack - _bp +2
                           1210 ;tmp                       Allocated to registers r6 
                           1211 ;delay_target              Allocated to registers r4 
                           1212 ;pluszeit                  Allocated to registers r2 
                           1213 ;off_disable               Allocated to registers 
                           1214 ;------------------------------------------------------------
                    028B   1215 	G$object_schalten$0$0 ==.
                    028B   1216 	C$fb_app_rollo11.c$320$2$1 ==.
                           1217 ;	..\fb_app_rollo11.c:320: void object_schalten(unsigned char objno, __bit objstate)	// Schaltet einen Ausgang gemäß objstate und den zugörigen Parametern
                           1218 ;	-----------------------------------------
                           1219 ;	 function object_schalten
                           1220 ;	-----------------------------------------
   0495                    1221 _object_schalten:
   0495 C0 08              1222 	push	_bp
   0497 85 81 08           1223 	mov	_bp,sp
   049A 05 81              1224 	inc	sp
   049C 05 81              1225 	inc	sp
   049E AF 82              1226 	mov	r7,dpl
                    0296   1227 	C$fb_app_rollo11.c$329$1$1 ==.
                           1228 ;	..\fb_app_rollo11.c:329: kwin = kanal[objno & 0x03]& 0x0f;// kwin heisst KanalWertIN. Bit 0+1 Relaise status, Bit 4+5 gewünschter Relaise status
   04A0 74 03              1229 	mov	a,#0x03
   04A2 5F                 1230 	anl	a,r7
   04A3 24 47              1231 	add	a,#_kanal
   04A5 F9                 1232 	mov	r1,a
   04A6 87 06              1233 	mov	ar6,@r1
   04A8 A8 08              1234 	mov	r0,_bp
   04AA 08                 1235 	inc	r0
   04AB 74 0F              1236 	mov	a,#0x0F
   04AD 5E                 1237 	anl	a,r6
   04AE F6                 1238 	mov	@r0,a
                    02A5   1239 	C$fb_app_rollo11.c$330$1$1 ==.
                           1240 ;	..\fb_app_rollo11.c:330: kwout=kwin;
   04AF A8 08              1241 	mov	r0,_bp
   04B1 08                 1242 	inc	r0
   04B2 86 05              1243 	mov	ar5,@r0
                    02AA   1244 	C$fb_app_rollo11.c$331$1$1 ==.
                           1245 ;	..\fb_app_rollo11.c:331: if (objstate) write_obj_value(objno & 0x07,1);		// Objektwert im userram speichern
   04B4 30 18 21           1246 	jnb	b0,00102$
   04B7 74 07              1247 	mov	a,#0x07
   04B9 5F                 1248 	anl	a,r7
   04BA F5 82              1249 	mov	dpl,a
   04BC C0 07              1250 	push	ar7
   04BE C0 05              1251 	push	ar5
   04C0 C0 23              1252 	push	bits
   04C2 74 01              1253 	mov	a,#0x01
   04C4 C0 E0              1254 	push	acc
   04C6 E4                 1255 	clr	a
   04C7 C0 E0              1256 	push	acc
   04C9 12 02 B6           1257 	lcall	_write_obj_value
   04CC 15 81              1258 	dec	sp
   04CE 15 81              1259 	dec	sp
   04D0 D0 23              1260 	pop	bits
   04D2 D0 05              1261 	pop	ar5
   04D4 D0 07              1262 	pop	ar7
   04D6 80 1D              1263 	sjmp	00103$
   04D8                    1264 00102$:
                    02CE   1265 	C$fb_app_rollo11.c$332$1$1 ==.
                           1266 ;	..\fb_app_rollo11.c:332: else write_obj_value(objno & 0x07,0);
   04D8 74 07              1267 	mov	a,#0x07
   04DA 5F                 1268 	anl	a,r7
   04DB F5 82              1269 	mov	dpl,a
   04DD C0 07              1270 	push	ar7
   04DF C0 05              1271 	push	ar5
   04E1 C0 23              1272 	push	bits
   04E3 E4                 1273 	clr	a
   04E4 C0 E0              1274 	push	acc
   04E6 C0 E0              1275 	push	acc
   04E8 12 02 B6           1276 	lcall	_write_obj_value
   04EB 15 81              1277 	dec	sp
   04ED 15 81              1278 	dec	sp
   04EF D0 23              1279 	pop	bits
   04F1 D0 05              1280 	pop	ar5
   04F3 D0 07              1281 	pop	ar7
   04F5                    1282 00103$:
                    02EB   1283 	C$fb_app_rollo11.c$333$1$1 ==.
                           1284 ;	..\fb_app_rollo11.c:333: objflags=read_objflags(objno&0x07);			// Objekt Flags lesen
   04F5 74 07              1285 	mov	a,#0x07
   04F7 5F                 1286 	anl	a,r7
   04F8 FC                 1287 	mov	r4,a
   04F9 F5 82              1288 	mov	dpl,a
   04FB C0 07              1289 	push	ar7
   04FD C0 05              1290 	push	ar5
   04FF C0 04              1291 	push	ar4
   0501 C0 23              1292 	push	bits
   0503 12 17 21           1293 	lcall	_read_objflags
   0506 AB 82              1294 	mov	r3,dpl
   0508 D0 23              1295 	pop	bits
   050A D0 04              1296 	pop	ar4
   050C D0 05              1297 	pop	ar5
   050E D0 07              1298 	pop	ar7
                    0306   1299 	C$fb_app_rollo11.c$334$1$1 ==.
                           1300 ;	..\fb_app_rollo11.c:334: port_pattern=0x01<<(objno&0x07);//port_pattern=0x01<<(objno&0x0F)
   0510 8C F0              1301 	mov	b,r4
   0512 05 F0              1302 	inc	b
   0514 74 01              1303 	mov	a,#0x01
   0516 80 02              1304 	sjmp	00195$
   0518                    1305 00193$:
   0518 25 E0              1306 	add	a,acc
   051A                    1307 00195$:
   051A D5 F0 FB           1308 	djnz	b,00193$
                    0313   1309 	C$fb_app_rollo11.c$337$1$1 ==.
                           1310 ;	..\fb_app_rollo11.c:337: if((port_pattern & blocked)==0 && (objflags&0x14)==0x14 ||(objno >=8)) {	// Objekt ist nicht gesperrt und Kommunikation zulässig (Bit 2 = communication enable) und Schreiben zulässig (Bit 4 = write enable)
   051D 55 0F              1311 	anl	a,_blocked
   051F 70 08              1312 	jnz	00161$
   0521 53 03 14           1313 	anl	ar3,#0x14
   0524 BB 14 02           1314 	cjne	r3,#0x14,00197$
   0527 80 08              1315 	sjmp	00158$
   0529                    1316 00197$:
   0529                    1317 00161$:
   0529 BF 08 00           1318 	cjne	r7,#0x08,00198$
   052C                    1319 00198$:
   052C 50 03              1320 	jnc	00199$
   052E 02 08 99           1321 	ljmp	00162$
   0531                    1322 00199$:
   0531                    1323 00158$:
                    0327   1324 	C$fb_app_rollo11.c$338$2$2 ==.
                           1325 ;	..\fb_app_rollo11.c:338: objno=objno&0x07;	// damit die bypassobjekte 8-15 wieder 0-7 sind!
   0531 53 07 07           1326 	anl	ar7,#0x07
                    032A   1327 	C$fb_app_rollo11.c$342$2$2 ==.
                           1328 ;	..\fb_app_rollo11.c:342: if (objno<0x04){			//+++++ kurzzeitobjekt +++++
   0534 BF 04 00           1329 	cjne	r7,#0x04,00200$
   0537                    1330 00200$:
   0537 40 03              1331 	jc	00201$
   0539 02 06 57           1332 	ljmp	00146$
   053C                    1333 00201$:
                    0332   1334 	C$fb_app_rollo11.c$343$3$3 ==.
                           1335 ;	..\fb_app_rollo11.c:343: delay_target = (eeprom[0xE8+(objno>>1)]>>(3*(objno&0x01))&0x07)|0x80;// zeitbasis aus eeprom holen
   053C EF                 1336 	mov	a,r7
   053D C3                 1337 	clr	c
   053E 13                 1338 	rrc	a
   053F 24 E8              1339 	add	a,#0xE8
   0541 90 1D 00           1340 	mov	dptr,#_eeprom
   0544 93                 1341 	movc	a,@a+dptr
   0545 FC                 1342 	mov	r4,a
   0546 74 01              1343 	mov	a,#0x01
   0548 5F                 1344 	anl	a,r7
   0549 75 F0 03           1345 	mov	b,#0x03
   054C A4                 1346 	mul	ab
   054D F5 F0              1347 	mov	b,a
   054F 05 F0              1348 	inc	b
   0551 EC                 1349 	mov	a,r4
   0552 80 02              1350 	sjmp	00203$
   0554                    1351 00202$:
   0554 C3                 1352 	clr	c
   0555 13                 1353 	rrc	a
   0556                    1354 00203$:
   0556 D5 F0 FB           1355 	djnz	b,00202$
   0559 54 07              1356 	anl	a,#0x07
   055B FC                 1357 	mov	r4,a
   055C 43 04 80           1358 	orl	ar4,#0x80
                    0355   1359 	C$fb_app_rollo11.c$344$3$3 ==.
                           1360 ;	..\fb_app_rollo11.c:344: faktor=eeprom[0xEA+objno];// faktor holen um dann auf 0 zu prüfen
   055F 74 EA              1361 	mov	a,#0xEA
   0561 2F                 1362 	add	a,r7
   0562 90 1D 00           1363 	mov	dptr,#_eeprom
   0565 93                 1364 	movc	a,@a+dptr
                    035C   1365 	C$fb_app_rollo11.c$345$3$3 ==.
                           1366 ;	..\fb_app_rollo11.c:345: pluszeit=faktor + (faktor>>5);// 3% zeit bei "auf" 
   0566 FB                 1367 	mov	r3,a
   0567 C4                 1368 	swap	a
   0568 03                 1369 	rr	a
   0569 54 07              1370 	anl	a,#0x07
   056B 2B                 1371 	add	a,r3
   056C FA                 1372 	mov	r2,a
                    0363   1373 	C$fb_app_rollo11.c$347$3$3 ==.
                           1374 ;	..\fb_app_rollo11.c:347: if (objstate==0){	//----- auf -----
   056D 20 18 71           1375 	jb	b0,00116$
                    0366   1376 	C$fb_app_rollo11.c$349$4$4 ==.
                           1377 ;	..\fb_app_rollo11.c:349: if (kwin&0x33){					// wenn faehrt,dann stop
   0570 A8 08              1378 	mov	r0,_bp
   0572 08                 1379 	inc	r0
   0573 E6                 1380 	mov	a,@r0
   0574 54 33              1381 	anl	a,#0x33
   0576 60 39              1382 	jz	00108$
                    036E   1383 	C$fb_app_rollo11.c$350$5$5 ==.
                           1384 ;	..\fb_app_rollo11.c:350: set_pause(objno,kwin&0x03);
   0578 A8 08              1385 	mov	r0,_bp
   057A 08                 1386 	inc	r0
   057B 74 03              1387 	mov	a,#0x03
   057D 56                 1388 	anl	a,@r0
   057E FE                 1389 	mov	r6,a
   057F C0 07              1390 	push	ar7
   0581 C0 06              1391 	push	ar6
   0583 8F 82              1392 	mov	dpl,r7
   0585 12 0B 50           1393 	lcall	_set_pause
   0588 15 81              1394 	dec	sp
   058A D0 07              1395 	pop	ar7
                    0382   1396 	C$fb_app_rollo11.c$352$5$5 ==.
                           1397 ;	..\fb_app_rollo11.c:352: kwout=kwin&0xCC;	// Fahrt in beide Richtungen stoppen
   058C A8 08              1398 	mov	r0,_bp
   058E 08                 1399 	inc	r0
   058F 74 CC              1400 	mov	a,#0xCC
   0591 56                 1401 	anl	a,@r0
   0592 FD                 1402 	mov	r5,a
                    0389   1403 	C$fb_app_rollo11.c$353$5$5 ==.
                           1404 ;	..\fb_app_rollo11.c:353: timerbase[objno]=0;	// kurzzeit löschen
   0593 EF                 1405 	mov	a,r7
   0594 24 10              1406 	add	a,#_timerbase
   0596 F8                 1407 	mov	r0,a
   0597 76 00              1408 	mov	@r0,#0x00
                    038F   1409 	C$fb_app_rollo11.c$354$5$5 ==.
                           1410 ;	..\fb_app_rollo11.c:354: timerstate[objno]=0;	// kurzzeit löschen
   0599 EF                 1411 	mov	a,r7
   059A 24 34              1412 	add	a,#_timerstate
   059C F8                 1413 	mov	r0,a
   059D 76 00              1414 	mov	@r0,#0x00
                    0395   1415 	C$fb_app_rollo11.c$355$5$5 ==.
                           1416 ;	..\fb_app_rollo11.c:355: timerbase[objno+4]=0;  // lanzeit löschen
   059F 74 04              1417 	mov	a,#0x04
   05A1 2F                 1418 	add	a,r7
   05A2 FE                 1419 	mov	r6,a
   05A3 24 10              1420 	add	a,#_timerbase
   05A5 F8                 1421 	mov	r0,a
   05A6 76 00              1422 	mov	@r0,#0x00
                    039E   1423 	C$fb_app_rollo11.c$356$5$5 ==.
                           1424 ;	..\fb_app_rollo11.c:356: timerstate[objno+4]=0;  // lanzeit löschen
   05A8 EE                 1425 	mov	a,r6
   05A9 24 34              1426 	add	a,#_timerstate
   05AB F8                 1427 	mov	r0,a
   05AC 76 00              1428 	mov	@r0,#0x00
   05AE 02 08 3C           1429 	ljmp	00147$
   05B1                    1430 00108$:
                    03A7   1431 	C$fb_app_rollo11.c$359$4$4 ==.
                           1432 ;	..\fb_app_rollo11.c:359: if ((!(kwin&0x33))&&(faktor)){	//wenn stillstand und faktor>0  dann step
   05B1 A8 08              1433 	mov	r0,_bp
   05B3 08                 1434 	inc	r0
   05B4 E6                 1435 	mov	a,@r0
   05B5 54 33              1436 	anl	a,#0x33
   05B7 60 03              1437 	jz	00207$
   05B9 02 08 3C           1438 	ljmp	00147$
   05BC                    1439 00207$:
   05BC EB                 1440 	mov	a,r3
   05BD 70 03              1441 	jnz	00208$
   05BF 02 08 3C           1442 	ljmp	00147$
   05C2                    1443 00208$:
                    03B8   1444 	C$fb_app_rollo11.c$360$5$6 ==.
                           1445 ;	..\fb_app_rollo11.c:360: kwout=kwin|0x10;
   05C2 A8 08              1446 	mov	r0,_bp
   05C4 08                 1447 	inc	r0
   05C5 74 10              1448 	mov	a,#0x10
   05C7 46                 1449 	orl	a,@r0
   05C8 FD                 1450 	mov	r5,a
                    03BF   1451 	C$fb_app_rollo11.c$361$5$6 ==.
                           1452 ;	..\fb_app_rollo11.c:361: kwout=kwout&0xDF;
   05C9 53 05 DF           1453 	anl	ar5,#0xDF
                    03C2   1454 	C$fb_app_rollo11.c$363$5$6 ==.
                           1455 ;	..\fb_app_rollo11.c:363: timerbase[objno]=delay_target;
   05CC EF                 1456 	mov	a,r7
   05CD 24 10              1457 	add	a,#_timerbase
   05CF F8                 1458 	mov	r0,a
   05D0 A6 04              1459 	mov	@r0,ar4
                    03C8   1460 	C$fb_app_rollo11.c$364$5$6 ==.
                           1461 ;	..\fb_app_rollo11.c:364: timercnt[objno]=pluszeit;
   05D2 EF                 1462 	mov	a,r7
   05D3 24 24              1463 	add	a,#_timercnt
   05D5 F8                 1464 	mov	r0,a
   05D6 A6 02              1465 	mov	@r0,ar2
                    03CE   1466 	C$fb_app_rollo11.c$365$5$6 ==.
                           1467 ;	..\fb_app_rollo11.c:365: timerstate[objno]=0x01;
   05D8 EF                 1468 	mov	a,r7
   05D9 24 34              1469 	add	a,#_timerstate
   05DB F8                 1470 	mov	r0,a
   05DC 76 01              1471 	mov	@r0,#0x01
   05DE 02 08 3C           1472 	ljmp	00147$
   05E1                    1473 00116$:
                    03D7   1474 	C$fb_app_rollo11.c$370$4$7 ==.
                           1475 ;	..\fb_app_rollo11.c:370: if (kwin&0x33){					// wenn faehrt, dann stop
   05E1 A8 08              1476 	mov	r0,_bp
   05E3 08                 1477 	inc	r0
   05E4 E6                 1478 	mov	a,@r0
   05E5 54 33              1479 	anl	a,#0x33
   05E7 60 3E              1480 	jz	00111$
                    03DF   1481 	C$fb_app_rollo11.c$371$5$8 ==.
                           1482 ;	..\fb_app_rollo11.c:371: set_pause(objno,kwin&0x03); //einsch. verz "pause" für eventuelle Faht in gegenrichtung
   05E9 A8 08              1483 	mov	r0,_bp
   05EB 08                 1484 	inc	r0
   05EC 74 03              1485 	mov	a,#0x03
   05EE 56                 1486 	anl	a,@r0
   05EF FE                 1487 	mov	r6,a
   05F0 C0 07              1488 	push	ar7
   05F2 C0 04              1489 	push	ar4
   05F4 C0 03              1490 	push	ar3
   05F6 C0 06              1491 	push	ar6
   05F8 8F 82              1492 	mov	dpl,r7
   05FA 12 0B 50           1493 	lcall	_set_pause
   05FD 15 81              1494 	dec	sp
   05FF D0 03              1495 	pop	ar3
   0601 D0 04              1496 	pop	ar4
   0603 D0 07              1497 	pop	ar7
                    03FB   1498 	C$fb_app_rollo11.c$372$5$8 ==.
                           1499 ;	..\fb_app_rollo11.c:372: kwout=kwin&0xCC;
   0605 A8 08              1500 	mov	r0,_bp
   0607 08                 1501 	inc	r0
   0608 74 CC              1502 	mov	a,#0xCC
   060A 56                 1503 	anl	a,@r0
   060B FD                 1504 	mov	r5,a
                    0402   1505 	C$fb_app_rollo11.c$375$5$8 ==.
                           1506 ;	..\fb_app_rollo11.c:375: timerbase[objno]=0;
   060C EF                 1507 	mov	a,r7
   060D 24 10              1508 	add	a,#_timerbase
   060F F8                 1509 	mov	r0,a
   0610 76 00              1510 	mov	@r0,#0x00
                    0408   1511 	C$fb_app_rollo11.c$376$5$8 ==.
                           1512 ;	..\fb_app_rollo11.c:376: timerstate[objno]=0;
   0612 EF                 1513 	mov	a,r7
   0613 24 34              1514 	add	a,#_timerstate
   0615 F8                 1515 	mov	r0,a
   0616 76 00              1516 	mov	@r0,#0x00
                    040E   1517 	C$fb_app_rollo11.c$377$5$8 ==.
                           1518 ;	..\fb_app_rollo11.c:377: timerbase[objno+4]=0;
   0618 74 04              1519 	mov	a,#0x04
   061A 2F                 1520 	add	a,r7
   061B FE                 1521 	mov	r6,a
   061C 24 10              1522 	add	a,#_timerbase
   061E F8                 1523 	mov	r0,a
   061F 76 00              1524 	mov	@r0,#0x00
                    0417   1525 	C$fb_app_rollo11.c$378$5$8 ==.
                           1526 ;	..\fb_app_rollo11.c:378: timerstate[objno+4]=0;
   0621 EE                 1527 	mov	a,r6
   0622 24 34              1528 	add	a,#_timerstate
   0624 F8                 1529 	mov	r0,a
   0625 76 00              1530 	mov	@r0,#0x00
   0627                    1531 00111$:
                    041D   1532 	C$fb_app_rollo11.c$380$4$7 ==.
                           1533 ;	..\fb_app_rollo11.c:380: if ((!(kwin&0x33))&&(faktor)){		// wenn stillstand dann step
   0627 A8 08              1534 	mov	r0,_bp
   0629 08                 1535 	inc	r0
   062A E6                 1536 	mov	a,@r0
   062B 54 33              1537 	anl	a,#0x33
   062D 60 03              1538 	jz	00211$
   062F 02 08 3C           1539 	ljmp	00147$
   0632                    1540 00211$:
   0632 EB                 1541 	mov	a,r3
   0633 70 03              1542 	jnz	00212$
   0635 02 08 3C           1543 	ljmp	00147$
   0638                    1544 00212$:
                    042E   1545 	C$fb_app_rollo11.c$381$5$9 ==.
                           1546 ;	..\fb_app_rollo11.c:381: kwout=kwin|0x20;
   0638 A8 08              1547 	mov	r0,_bp
   063A 08                 1548 	inc	r0
   063B 74 20              1549 	mov	a,#0x20
   063D 46                 1550 	orl	a,@r0
   063E FD                 1551 	mov	r5,a
                    0435   1552 	C$fb_app_rollo11.c$382$5$9 ==.
                           1553 ;	..\fb_app_rollo11.c:382: kwout=kwout&0xEF;
   063F 53 05 EF           1554 	anl	ar5,#0xEF
                    0438   1555 	C$fb_app_rollo11.c$384$5$9 ==.
                           1556 ;	..\fb_app_rollo11.c:384: timerbase[objno]=delay_target;
   0642 EF                 1557 	mov	a,r7
   0643 24 10              1558 	add	a,#_timerbase
   0645 F8                 1559 	mov	r0,a
   0646 A6 04              1560 	mov	@r0,ar4
                    043E   1561 	C$fb_app_rollo11.c$385$5$9 ==.
                           1562 ;	..\fb_app_rollo11.c:385: timercnt[objno]=faktor;
   0648 EF                 1563 	mov	a,r7
   0649 24 24              1564 	add	a,#_timercnt
   064B F8                 1565 	mov	r0,a
   064C A6 03              1566 	mov	@r0,ar3
                    0444   1567 	C$fb_app_rollo11.c$386$5$9 ==.
                           1568 ;	..\fb_app_rollo11.c:386: timerstate[objno]=0x02;
   064E EF                 1569 	mov	a,r7
   064F 24 34              1570 	add	a,#_timerstate
   0651 F8                 1571 	mov	r0,a
   0652 76 02              1572 	mov	@r0,#0x02
   0654 02 08 3C           1573 	ljmp	00147$
   0657                    1574 00146$:
                    044D   1575 	C$fb_app_rollo11.c$393$2$1 ==.
                           1576 ;	..\fb_app_rollo11.c:393: delay_target=(eeprom[0xFB+((objno&0x03)>>1)]>>(3*(objno&0x01))&0x07) | 0x80;// zeitbasis aus eeprom holen
   0657 C0 05              1577 	push	ar5
   0659 74 03              1578 	mov	a,#0x03
   065B 5F                 1579 	anl	a,r7
   065C FE                 1580 	mov	r6,a
   065D C3                 1581 	clr	c
   065E 13                 1582 	rrc	a
   065F 24 FB              1583 	add	a,#0xFB
   0661 90 1D 00           1584 	mov	dptr,#_eeprom
   0664 93                 1585 	movc	a,@a+dptr
   0665 FD                 1586 	mov	r5,a
   0666 74 01              1587 	mov	a,#0x01
   0668 5F                 1588 	anl	a,r7
   0669 75 F0 03           1589 	mov	b,#0x03
   066C A4                 1590 	mul	ab
   066D F5 F0              1591 	mov	b,a
   066F 05 F0              1592 	inc	b
   0671 ED                 1593 	mov	a,r5
   0672 80 02              1594 	sjmp	00214$
   0674                    1595 00213$:
   0674 C3                 1596 	clr	c
   0675 13                 1597 	rrc	a
   0676                    1598 00214$:
   0676 D5 F0 FB           1599 	djnz	b,00213$
   0679 54 07              1600 	anl	a,#0x07
   067B FD                 1601 	mov	r5,a
   067C 74 80              1602 	mov	a,#0x80
   067E 4D                 1603 	orl	a,r5
   067F FC                 1604 	mov	r4,a
                    0476   1605 	C$fb_app_rollo11.c$394$3$10 ==.
                           1606 ;	..\fb_app_rollo11.c:394: faktor = eeprom[0xDA+(objno&0x03)];
   0680 74 DA              1607 	mov	a,#0xDA
   0682 2E                 1608 	add	a,r6
   0683 90 1D 00           1609 	mov	dptr,#_eeprom
   0686 93                 1610 	movc	a,@a+dptr
                    047D   1611 	C$fb_app_rollo11.c$395$3$10 ==.
                           1612 ;	..\fb_app_rollo11.c:395: faktor = faktor + (faktor>>2);// +25% zeit bei langzeit 
   0687 FB                 1613 	mov	r3,a
   0688 03                 1614 	rr	a
   0689 03                 1615 	rr	a
   068A 54 3F              1616 	anl	a,#0x3F
   068C 2B                 1617 	add	a,r3
                    0483   1618 	C$fb_app_rollo11.c$396$3$10 ==.
                           1619 ;	..\fb_app_rollo11.c:396: pluszeit=faktor + (faktor>>5);// 3% zeit bei "auf" 
   068D FB                 1620 	mov	r3,a
   068E C4                 1621 	swap	a
   068F 03                 1622 	rr	a
   0690 54 07              1623 	anl	a,#0x07
   0692 2B                 1624 	add	a,r3
   0693 FA                 1625 	mov	r2,a
                    048A   1626 	C$fb_app_rollo11.c$397$3$10 ==.
                           1627 ;	..\fb_app_rollo11.c:397: lz_ue=((eeprom[0xF2]>>objno)&0x01);		//lz_ue bedeutet: langzeit unendlich
   0694 90 1D F2           1628 	mov	dptr,#(_eeprom + 0x00f2)
   0697 E4                 1629 	clr	a
   0698 93                 1630 	movc	a,@a+dptr
   0699 FE                 1631 	mov	r6,a
   069A 8F F0              1632 	mov	b,r7
   069C 05 F0              1633 	inc	b
   069E EE                 1634 	mov	a,r6
   069F 80 02              1635 	sjmp	00216$
   06A1                    1636 00215$:
   06A1 C3                 1637 	clr	c
   06A2 13                 1638 	rrc	a
   06A3                    1639 00216$:
   06A3 D5 F0 FB           1640 	djnz	b,00215$
   06A6 FE                 1641 	mov	r6,a
   06A7 A8 08              1642 	mov	r0,_bp
   06A9 08                 1643 	inc	r0
   06AA 08                 1644 	inc	r0
   06AB 74 01              1645 	mov	a,#0x01
   06AD 5E                 1646 	anl	a,r6
   06AE F6                 1647 	mov	@r0,a
                    04A5   1648 	C$fb_app_rollo11.c$398$2$1 ==.
                           1649 ;	..\fb_app_rollo11.c:398: if (objstate==0){// --- auf ----
   06AF D0 05              1650 	pop	ar5
   06B1 30 18 03           1651 	jnb	b0,00217$
   06B4 02 07 69           1652 	ljmp	00143$
   06B7                    1653 00217$:
                    04AD   1654 	C$fb_app_rollo11.c$399$4$11 ==.
                           1655 ;	..\fb_app_rollo11.c:399: if (kwin&0x11){		//läuft bereits, also nachtriggern
   06B7 A8 08              1656 	mov	r0,_bp
   06B9 08                 1657 	inc	r0
   06BA E6                 1658 	mov	a,@r0
   06BB 54 11              1659 	anl	a,#0x11
   06BD 60 35              1660 	jz	00121$
                    04B5   1661 	C$fb_app_rollo11.c$400$5$12 ==.
                           1662 ;	..\fb_app_rollo11.c:400: kwout=kwin|0x10;// auch hier neu setzen da in delay nach rechts kommt
   06BF A8 08              1663 	mov	r0,_bp
   06C1 08                 1664 	inc	r0
   06C2 74 10              1665 	mov	a,#0x10
   06C4 46                 1666 	orl	a,@r0
   06C5 FD                 1667 	mov	r5,a
                    04BC   1668 	C$fb_app_rollo11.c$401$5$12 ==.
                           1669 ;	..\fb_app_rollo11.c:401: timercnt[objno-4]=0;//kurzzeit löschen
   06C6 EF                 1670 	mov	a,r7
   06C7 24 FC              1671 	add	a,#0xFC
   06C9 FE                 1672 	mov	r6,a
   06CA 24 24              1673 	add	a,#_timercnt
   06CC F8                 1674 	mov	r0,a
   06CD 76 00              1675 	mov	@r0,#0x00
                    04C5   1676 	C$fb_app_rollo11.c$402$5$12 ==.
                           1677 ;	..\fb_app_rollo11.c:402: timerstate[objno-4]=0;
   06CF EE                 1678 	mov	a,r6
   06D0 24 34              1679 	add	a,#_timerstate
   06D2 F8                 1680 	mov	r0,a
   06D3 76 00              1681 	mov	@r0,#0x00
                    04CB   1682 	C$fb_app_rollo11.c$403$5$12 ==.
                           1683 ;	..\fb_app_rollo11.c:403: timerbase[objno-4]=0;
   06D5 EE                 1684 	mov	a,r6
   06D6 24 10              1685 	add	a,#_timerbase
   06D8 F8                 1686 	mov	r0,a
   06D9 76 00              1687 	mov	@r0,#0x00
                    04D1   1688 	C$fb_app_rollo11.c$404$5$12 ==.
                           1689 ;	..\fb_app_rollo11.c:404: if (!lz_ue){
   06DB A8 08              1690 	mov	r0,_bp
   06DD 08                 1691 	inc	r0
   06DE 08                 1692 	inc	r0
   06DF E6                 1693 	mov	a,@r0
   06E0 70 12              1694 	jnz	00121$
                    04D8   1695 	C$fb_app_rollo11.c$406$6$13 ==.
                           1696 ;	..\fb_app_rollo11.c:406: timerbase[objno]=delay_target;
   06E2 EF                 1697 	mov	a,r7
   06E3 24 10              1698 	add	a,#_timerbase
   06E5 F8                 1699 	mov	r0,a
   06E6 A6 04              1700 	mov	@r0,ar4
                    04DE   1701 	C$fb_app_rollo11.c$407$6$13 ==.
                           1702 ;	..\fb_app_rollo11.c:407: timercnt[objno]=pluszeit;
   06E8 EF                 1703 	mov	a,r7
   06E9 24 24              1704 	add	a,#_timercnt
   06EB F8                 1705 	mov	r0,a
   06EC A6 02              1706 	mov	@r0,ar2
                    04E4   1707 	C$fb_app_rollo11.c$408$6$13 ==.
                           1708 ;	..\fb_app_rollo11.c:408: timerstate[objno]=0x01;
   06EE EF                 1709 	mov	a,r7
   06EF 24 34              1710 	add	a,#_timerstate
   06F1 F8                 1711 	mov	r0,a
   06F2 76 01              1712 	mov	@r0,#0x01
   06F4                    1713 00121$:
                    04EA   1714 	C$fb_app_rollo11.c$411$4$11 ==.
                           1715 ;	..\fb_app_rollo11.c:411: if (!(kwin&0x33)){	//wenn stillstand, dann move
   06F4 A8 08              1716 	mov	r0,_bp
   06F6 08                 1717 	inc	r0
   06F7 E6                 1718 	mov	a,@r0
   06F8 54 33              1719 	anl	a,#0x33
   06FA 70 20              1720 	jnz	00125$
                    04F2   1721 	C$fb_app_rollo11.c$412$5$14 ==.
                           1722 ;	..\fb_app_rollo11.c:412: kwout=kwin|0x10;
   06FC A8 08              1723 	mov	r0,_bp
   06FE 08                 1724 	inc	r0
   06FF 74 10              1725 	mov	a,#0x10
   0701 46                 1726 	orl	a,@r0
   0702 FD                 1727 	mov	r5,a
                    04F9   1728 	C$fb_app_rollo11.c$415$5$14 ==.
                           1729 ;	..\fb_app_rollo11.c:415: if (!lz_ue){
   0703 A8 08              1730 	mov	r0,_bp
   0705 08                 1731 	inc	r0
   0706 08                 1732 	inc	r0
   0707 E6                 1733 	mov	a,@r0
   0708 70 12              1734 	jnz	00125$
                    0500   1735 	C$fb_app_rollo11.c$417$6$15 ==.
                           1736 ;	..\fb_app_rollo11.c:417: timerbase[objno]=delay_target;
   070A EF                 1737 	mov	a,r7
   070B 24 10              1738 	add	a,#_timerbase
   070D F8                 1739 	mov	r0,a
   070E A6 04              1740 	mov	@r0,ar4
                    0506   1741 	C$fb_app_rollo11.c$418$6$15 ==.
                           1742 ;	..\fb_app_rollo11.c:418: timercnt[objno]=pluszeit;
   0710 EF                 1743 	mov	a,r7
   0711 24 24              1744 	add	a,#_timercnt
   0713 F8                 1745 	mov	r0,a
   0714 A6 02              1746 	mov	@r0,ar2
                    050C   1747 	C$fb_app_rollo11.c$419$6$15 ==.
                           1748 ;	..\fb_app_rollo11.c:419: timerstate[objno]=0x01;
   0716 EF                 1749 	mov	a,r7
   0717 24 34              1750 	add	a,#_timerstate
   0719 F8                 1751 	mov	r0,a
   071A 76 01              1752 	mov	@r0,#0x01
   071C                    1753 00125$:
                    0512   1754 	C$fb_app_rollo11.c$423$4$11 ==.
                           1755 ;	..\fb_app_rollo11.c:423: if (kwin&0x22){		// wenn fahrt in andere richtung
   071C A8 08              1756 	mov	r0,_bp
   071E 08                 1757 	inc	r0
   071F E6                 1758 	mov	a,@r0
   0720 54 22              1759 	anl	a,#0x22
   0722 70 03              1760 	jnz	00223$
   0724 02 08 3C           1761 	ljmp	00147$
   0727                    1762 00223$:
                    051D   1763 	C$fb_app_rollo11.c$424$5$16 ==.
                           1764 ;	..\fb_app_rollo11.c:424: set_pause(objno,0x05);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
   0727 C0 07              1765 	push	ar7
   0729 C0 04              1766 	push	ar4
   072B C0 02              1767 	push	ar2
   072D 74 05              1768 	mov	a,#0x05
   072F C0 E0              1769 	push	acc
   0731 8F 82              1770 	mov	dpl,r7
   0733 12 0B 50           1771 	lcall	_set_pause
   0736 15 81              1772 	dec	sp
   0738 D0 02              1773 	pop	ar2
   073A D0 04              1774 	pop	ar4
   073C D0 07              1775 	pop	ar7
                    0534   1776 	C$fb_app_rollo11.c$425$5$16 ==.
                           1777 ;	..\fb_app_rollo11.c:425: kwout=kwin|0x10;
   073E A8 08              1778 	mov	r0,_bp
   0740 08                 1779 	inc	r0
   0741 74 10              1780 	mov	a,#0x10
   0743 46                 1781 	orl	a,@r0
   0744 FD                 1782 	mov	r5,a
                    053B   1783 	C$fb_app_rollo11.c$426$5$16 ==.
                           1784 ;	..\fb_app_rollo11.c:426: kwout=kwout&0xDF;
   0745 53 05 DF           1785 	anl	ar5,#0xDF
                    053E   1786 	C$fb_app_rollo11.c$427$5$16 ==.
                           1787 ;	..\fb_app_rollo11.c:427: if (!lz_ue){
   0748 A8 08              1788 	mov	r0,_bp
   074A 08                 1789 	inc	r0
   074B 08                 1790 	inc	r0
   074C E6                 1791 	mov	a,@r0
   074D 60 03              1792 	jz	00224$
   074F 02 08 3C           1793 	ljmp	00147$
   0752                    1794 00224$:
                    0548   1795 	C$fb_app_rollo11.c$429$6$17 ==.
                           1796 ;	..\fb_app_rollo11.c:429: timerbase[objno]=delay_target & 0x7F;// timer-run für den move löschen
   0752 EF                 1797 	mov	a,r7
   0753 24 10              1798 	add	a,#_timerbase
   0755 F9                 1799 	mov	r1,a
   0756 74 7F              1800 	mov	a,#0x7F
   0758 5C                 1801 	anl	a,r4
   0759 F7                 1802 	mov	@r1,a
                    0550   1803 	C$fb_app_rollo11.c$430$6$17 ==.
                           1804 ;	..\fb_app_rollo11.c:430: timercnt[objno]=pluszeit;
   075A EF                 1805 	mov	a,r7
   075B 24 24              1806 	add	a,#_timercnt
   075D F8                 1807 	mov	r0,a
   075E A6 02              1808 	mov	@r0,ar2
                    0556   1809 	C$fb_app_rollo11.c$431$6$17 ==.
                           1810 ;	..\fb_app_rollo11.c:431: timerstate[objno]=0x01;
   0760 EF                 1811 	mov	a,r7
   0761 24 34              1812 	add	a,#_timerstate
   0763 F8                 1813 	mov	r0,a
   0764 76 01              1814 	mov	@r0,#0x01
   0766 02 08 3C           1815 	ljmp	00147$
   0769                    1816 00143$:
                    055F   1817 	C$fb_app_rollo11.c$437$4$18 ==.
                           1818 ;	..\fb_app_rollo11.c:437: if (kwin&0x22){		//läuft bereits, also nachtriggern
   0769 A8 08              1819 	mov	r0,_bp
   076B 08                 1820 	inc	r0
   076C E6                 1821 	mov	a,@r0
   076D 54 22              1822 	anl	a,#0x22
   076F 60 35              1823 	jz	00133$
                    0567   1824 	C$fb_app_rollo11.c$438$5$19 ==.
                           1825 ;	..\fb_app_rollo11.c:438: kwout=kwin|0x20;// auch hier neu setzen da in delay nach rechts kommt
   0771 A8 08              1826 	mov	r0,_bp
   0773 08                 1827 	inc	r0
   0774 74 20              1828 	mov	a,#0x20
   0776 46                 1829 	orl	a,@r0
   0777 FD                 1830 	mov	r5,a
                    056E   1831 	C$fb_app_rollo11.c$439$5$19 ==.
                           1832 ;	..\fb_app_rollo11.c:439: timerbase[objno-4]=0; 
   0778 EF                 1833 	mov	a,r7
   0779 24 FC              1834 	add	a,#0xFC
   077B FE                 1835 	mov	r6,a
   077C 24 10              1836 	add	a,#_timerbase
   077E F8                 1837 	mov	r0,a
   077F 76 00              1838 	mov	@r0,#0x00
                    0577   1839 	C$fb_app_rollo11.c$440$5$19 ==.
                           1840 ;	..\fb_app_rollo11.c:440: timercnt[objno-4]=0;
   0781 EE                 1841 	mov	a,r6
   0782 24 24              1842 	add	a,#_timercnt
   0784 F8                 1843 	mov	r0,a
   0785 76 00              1844 	mov	@r0,#0x00
                    057D   1845 	C$fb_app_rollo11.c$441$5$19 ==.
                           1846 ;	..\fb_app_rollo11.c:441: timerstate[objno-4]=0;
   0787 EE                 1847 	mov	a,r6
   0788 24 34              1848 	add	a,#_timerstate
   078A F8                 1849 	mov	r0,a
   078B 76 00              1850 	mov	@r0,#0x00
                    0583   1851 	C$fb_app_rollo11.c$443$5$19 ==.
                           1852 ;	..\fb_app_rollo11.c:443: if (!lz_ue){
   078D A8 08              1853 	mov	r0,_bp
   078F 08                 1854 	inc	r0
   0790 08                 1855 	inc	r0
   0791 E6                 1856 	mov	a,@r0
   0792 70 12              1857 	jnz	00133$
                    058A   1858 	C$fb_app_rollo11.c$445$6$20 ==.
                           1859 ;	..\fb_app_rollo11.c:445: timerbase[objno]=delay_target;
   0794 EF                 1860 	mov	a,r7
   0795 24 10              1861 	add	a,#_timerbase
   0797 F8                 1862 	mov	r0,a
   0798 A6 04              1863 	mov	@r0,ar4
                    0590   1864 	C$fb_app_rollo11.c$446$6$20 ==.
                           1865 ;	..\fb_app_rollo11.c:446: timercnt[objno]=faktor;
   079A EF                 1866 	mov	a,r7
   079B 24 24              1867 	add	a,#_timercnt
   079D F8                 1868 	mov	r0,a
   079E A6 03              1869 	mov	@r0,ar3
                    0596   1870 	C$fb_app_rollo11.c$447$6$20 ==.
                           1871 ;	..\fb_app_rollo11.c:447: timerstate[objno]=0x02;
   07A0 EF                 1872 	mov	a,r7
   07A1 24 34              1873 	add	a,#_timerstate
   07A3 F8                 1874 	mov	r0,a
   07A4 76 02              1875 	mov	@r0,#0x02
   07A6                    1876 00133$:
                    059C   1877 	C$fb_app_rollo11.c$450$4$18 ==.
                           1878 ;	..\fb_app_rollo11.c:450: if (!(kwin&0x33)){	//wenn stillstand, dann move
   07A6 A8 08              1879 	mov	r0,_bp
   07A8 08                 1880 	inc	r0
   07A9 E6                 1881 	mov	a,@r0
   07AA 54 33              1882 	anl	a,#0x33
   07AC 70 35              1883 	jnz	00137$
                    05A4   1884 	C$fb_app_rollo11.c$451$5$21 ==.
                           1885 ;	..\fb_app_rollo11.c:451: kwout=kwin|0x20;// kanal setzen
   07AE A8 08              1886 	mov	r0,_bp
   07B0 08                 1887 	inc	r0
   07B1 74 20              1888 	mov	a,#0x20
   07B3 46                 1889 	orl	a,@r0
   07B4 FD                 1890 	mov	r5,a
                    05AB   1891 	C$fb_app_rollo11.c$454$5$21 ==.
                           1892 ;	..\fb_app_rollo11.c:454: timerbase[objno-4]=0; 
   07B5 EF                 1893 	mov	a,r7
   07B6 24 FC              1894 	add	a,#0xFC
   07B8 FE                 1895 	mov	r6,a
   07B9 24 10              1896 	add	a,#_timerbase
   07BB F8                 1897 	mov	r0,a
   07BC 76 00              1898 	mov	@r0,#0x00
                    05B4   1899 	C$fb_app_rollo11.c$455$5$21 ==.
                           1900 ;	..\fb_app_rollo11.c:455: timercnt[objno-4]=0;
   07BE EE                 1901 	mov	a,r6
   07BF 24 24              1902 	add	a,#_timercnt
   07C1 F8                 1903 	mov	r0,a
   07C2 76 00              1904 	mov	@r0,#0x00
                    05BA   1905 	C$fb_app_rollo11.c$456$5$21 ==.
                           1906 ;	..\fb_app_rollo11.c:456: timerstate[objno-4]=0;
   07C4 EE                 1907 	mov	a,r6
   07C5 24 34              1908 	add	a,#_timerstate
   07C7 F8                 1909 	mov	r0,a
   07C8 76 00              1910 	mov	@r0,#0x00
                    05C0   1911 	C$fb_app_rollo11.c$457$5$21 ==.
                           1912 ;	..\fb_app_rollo11.c:457: if (!lz_ue){
   07CA A8 08              1913 	mov	r0,_bp
   07CC 08                 1914 	inc	r0
   07CD 08                 1915 	inc	r0
   07CE E6                 1916 	mov	a,@r0
   07CF 70 12              1917 	jnz	00137$
                    05C7   1918 	C$fb_app_rollo11.c$459$6$22 ==.
                           1919 ;	..\fb_app_rollo11.c:459: timerbase[objno]=delay_target;
   07D1 EF                 1920 	mov	a,r7
   07D2 24 10              1921 	add	a,#_timerbase
   07D4 F8                 1922 	mov	r0,a
   07D5 A6 04              1923 	mov	@r0,ar4
                    05CD   1924 	C$fb_app_rollo11.c$460$6$22 ==.
                           1925 ;	..\fb_app_rollo11.c:460: timercnt[objno]=faktor;
   07D7 EF                 1926 	mov	a,r7
   07D8 24 24              1927 	add	a,#_timercnt
   07DA F8                 1928 	mov	r0,a
   07DB A6 03              1929 	mov	@r0,ar3
                    05D3   1930 	C$fb_app_rollo11.c$461$6$22 ==.
                           1931 ;	..\fb_app_rollo11.c:461: timerstate[objno]=0x02;
   07DD EF                 1932 	mov	a,r7
   07DE 24 34              1933 	add	a,#_timerstate
   07E0 F8                 1934 	mov	r0,a
   07E1 76 02              1935 	mov	@r0,#0x02
   07E3                    1936 00137$:
                    05D9   1937 	C$fb_app_rollo11.c$464$4$18 ==.
                           1938 ;	..\fb_app_rollo11.c:464: if (kwin&0x11){					// wenn fahrt in andere richtung
   07E3 A8 08              1939 	mov	r0,_bp
   07E5 08                 1940 	inc	r0
   07E6 E6                 1941 	mov	a,@r0
   07E7 54 11              1942 	anl	a,#0x11
   07E9 60 51              1943 	jz	00147$
                    05E1   1944 	C$fb_app_rollo11.c$465$5$23 ==.
                           1945 ;	..\fb_app_rollo11.c:465: set_pause(objno, 0x06);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
   07EB C0 07              1946 	push	ar7
   07ED C0 04              1947 	push	ar4
   07EF C0 03              1948 	push	ar3
   07F1 74 06              1949 	mov	a,#0x06
   07F3 C0 E0              1950 	push	acc
   07F5 8F 82              1951 	mov	dpl,r7
   07F7 12 0B 50           1952 	lcall	_set_pause
   07FA 15 81              1953 	dec	sp
   07FC D0 03              1954 	pop	ar3
   07FE D0 04              1955 	pop	ar4
   0800 D0 07              1956 	pop	ar7
                    05F8   1957 	C$fb_app_rollo11.c$466$5$23 ==.
                           1958 ;	..\fb_app_rollo11.c:466: kwout=kwin|0x20;
   0802 A8 08              1959 	mov	r0,_bp
   0804 08                 1960 	inc	r0
   0805 74 20              1961 	mov	a,#0x20
   0807 46                 1962 	orl	a,@r0
   0808 FD                 1963 	mov	r5,a
                    05FF   1964 	C$fb_app_rollo11.c$467$5$23 ==.
                           1965 ;	..\fb_app_rollo11.c:467: kwout=kwout&0xEF;
   0809 53 05 EF           1966 	anl	ar5,#0xEF
                    0602   1967 	C$fb_app_rollo11.c$469$5$23 ==.
                           1968 ;	..\fb_app_rollo11.c:469: timerbase[objno-4]=0; // kurzzeit löschen
   080C EF                 1969 	mov	a,r7
   080D 24 FC              1970 	add	a,#0xFC
   080F FE                 1971 	mov	r6,a
   0810 24 10              1972 	add	a,#_timerbase
   0812 F8                 1973 	mov	r0,a
   0813 76 00              1974 	mov	@r0,#0x00
                    060B   1975 	C$fb_app_rollo11.c$470$5$23 ==.
                           1976 ;	..\fb_app_rollo11.c:470: timercnt[objno-4]=0;
   0815 EE                 1977 	mov	a,r6
   0816 24 24              1978 	add	a,#_timercnt
   0818 F8                 1979 	mov	r0,a
   0819 76 00              1980 	mov	@r0,#0x00
                    0611   1981 	C$fb_app_rollo11.c$471$5$23 ==.
                           1982 ;	..\fb_app_rollo11.c:471: timerstate[objno-4]=0;
   081B EE                 1983 	mov	a,r6
   081C 24 34              1984 	add	a,#_timerstate
   081E F8                 1985 	mov	r0,a
   081F 76 00              1986 	mov	@r0,#0x00
                    0617   1987 	C$fb_app_rollo11.c$472$5$23 ==.
                           1988 ;	..\fb_app_rollo11.c:472: if (!lz_ue){
   0821 A8 08              1989 	mov	r0,_bp
   0823 08                 1990 	inc	r0
   0824 08                 1991 	inc	r0
   0825 E6                 1992 	mov	a,@r0
   0826 70 14              1993 	jnz	00147$
                    061E   1994 	C$fb_app_rollo11.c$474$6$24 ==.
                           1995 ;	..\fb_app_rollo11.c:474: timerbase[objno]=delay_target & 0x7F;// timer run des langzeit löschen
   0828 EF                 1996 	mov	a,r7
   0829 24 10              1997 	add	a,#_timerbase
   082B F9                 1998 	mov	r1,a
   082C 74 7F              1999 	mov	a,#0x7F
   082E 5C                 2000 	anl	a,r4
   082F F7                 2001 	mov	@r1,a
                    0626   2002 	C$fb_app_rollo11.c$475$6$24 ==.
                           2003 ;	..\fb_app_rollo11.c:475: timercnt[objno]=faktor;
   0830 EF                 2004 	mov	a,r7
   0831 24 24              2005 	add	a,#_timercnt
   0833 F8                 2006 	mov	r0,a
   0834 A6 03              2007 	mov	@r0,ar3
                    062C   2008 	C$fb_app_rollo11.c$476$6$24 ==.
                           2009 ;	..\fb_app_rollo11.c:476: timerstate[objno]=0x02;
   0836 EF                 2010 	mov	a,r7
   0837 24 34              2011 	add	a,#_timerstate
   0839 F8                 2012 	mov	r0,a
   083A 76 02              2013 	mov	@r0,#0x02
   083C                    2014 00147$:
                    0632   2015 	C$fb_app_rollo11.c$485$2$2 ==.
                           2016 ;	..\fb_app_rollo11.c:485: kwin=kwout;
   083C A8 08              2017 	mov	r0,_bp
   083E 08                 2018 	inc	r0
   083F A6 05              2019 	mov	@r0,ar5
                    0637   2020 	C$fb_app_rollo11.c$486$2$2 ==.
                           2021 ;	..\fb_app_rollo11.c:486: if (objno<=7){
   0841 EF                 2022 	mov	a,r7
   0842 24 F8              2023 	add	a,#0xff - 0x07
   0844 40 49              2024 	jc	00157$
                    063C   2025 	C$fb_app_rollo11.c$487$3$25 ==.
                           2026 ;	..\fb_app_rollo11.c:487: tmp=timerstate[((objno & 0x03)+11)]& 0x07;
   0846 74 03              2027 	mov	a,#0x03
   0848 5F                 2028 	anl	a,r7
   0849 24 0B              2029 	add	a,#0x0B
   084B 24 34              2030 	add	a,#_timerstate
   084D F9                 2031 	mov	r1,a
   084E 87 06              2032 	mov	ar6,@r1
   0850 53 06 07           2033 	anl	ar6,#0x07
                    0649   2034 	C$fb_app_rollo11.c$489$3$25 ==.
                           2035 ;	..\fb_app_rollo11.c:489: if ((tmp<4)&& (tmp & (kwout>>4) & 0x03)){
   0853 BE 04 00           2036 	cjne	r6,#0x04,00233$
   0856                    2037 00233$:
   0856 50 23              2038 	jnc	00149$
   0858 ED                 2039 	mov	a,r5
   0859 C4                 2040 	swap	a
   085A 54 0F              2041 	anl	a,#0x0F
   085C FC                 2042 	mov	r4,a
   085D 5E                 2043 	anl	a,r6
   085E 54 03              2044 	anl	a,#0x03
   0860 60 19              2045 	jz	00149$
                    0658   2046 	C$fb_app_rollo11.c$491$4$26 ==.
                           2047 ;	..\fb_app_rollo11.c:491: timerbase[(objno&0x03)+11]=0; 
   0862 74 03              2048 	mov	a,#0x03
   0864 5F                 2049 	anl	a,r7
   0865 24 0B              2050 	add	a,#0x0B
   0867 FC                 2051 	mov	r4,a
   0868 24 10              2052 	add	a,#_timerbase
   086A F8                 2053 	mov	r0,a
   086B 76 00              2054 	mov	@r0,#0x00
                    0663   2055 	C$fb_app_rollo11.c$492$4$26 ==.
                           2056 ;	..\fb_app_rollo11.c:492: timercnt[(objno&0x03)+11]=0;//gleiche Richtung: Pause löschen
   086D EC                 2057 	mov	a,r4
   086E 24 24              2058 	add	a,#_timercnt
   0870 F8                 2059 	mov	r0,a
   0871 76 00              2060 	mov	@r0,#0x00
                    0669   2061 	C$fb_app_rollo11.c$493$4$26 ==.
                           2062 ;	..\fb_app_rollo11.c:493: timerstate[(objno&0x03)+11]=0;
   0873 EC                 2063 	mov	a,r4
   0874 24 34              2064 	add	a,#_timerstate
   0876 F8                 2065 	mov	r0,a
   0877 76 00              2066 	mov	@r0,#0x00
                    066F   2067 	C$fb_app_rollo11.c$494$4$26 ==.
                           2068 ;	..\fb_app_rollo11.c:494: tmp=0;
   0879 7E 00              2069 	mov	r6,#0x00
   087B                    2070 00149$:
                    0671   2071 	C$fb_app_rollo11.c$497$3$25 ==.
                           2072 ;	..\fb_app_rollo11.c:497: if(tmp & 0x04){//wenn Pause wegen umschalten läuft,Kanal "ist" löschen.
   087B EE                 2073 	mov	a,r6
   087C 30 E2 05           2074 	jnb	acc.2,00154$
                    0675   2075 	C$fb_app_rollo11.c$499$4$27 ==.
                           2076 ;	..\fb_app_rollo11.c:499: kwout=kwout&0xF0;
   087F 53 05 F0           2077 	anl	ar5,#0xF0
   0882 80 0B              2078 	sjmp	00157$
   0884                    2079 00154$:
                    067A   2080 	C$fb_app_rollo11.c$502$4$28 ==.
                           2081 ;	..\fb_app_rollo11.c:502: if(!(tmp)){
   0884 EE                 2082 	mov	a,r6
   0885 70 08              2083 	jnz	00157$
                    067D   2084 	C$fb_app_rollo11.c$503$5$29 ==.
                           2085 ;	..\fb_app_rollo11.c:503: kwout=kwin>>4;//wenn keiene Pause Läuft, dann kanal "soll" in "ist" kopieren
   0887 A8 08              2086 	mov	r0,_bp
   0889 08                 2087 	inc	r0
   088A E6                 2088 	mov	a,@r0
   088B C4                 2089 	swap	a
   088C 54 0F              2090 	anl	a,#0x0F
   088E FD                 2091 	mov	r5,a
   088F                    2092 00157$:
                    0685   2093 	C$fb_app_rollo11.c$509$2$2 ==.
                           2094 ;	..\fb_app_rollo11.c:509: kanal[objno&0x03]=kwout;
   088F 74 03              2095 	mov	a,#0x03
   0891 5F                 2096 	anl	a,r7
   0892 24 47              2097 	add	a,#_kanal
   0894 F8                 2098 	mov	r0,a
   0895 A6 05              2099 	mov	@r0,ar5
                    068D   2100 	C$fb_app_rollo11.c$510$2$2 ==.
                           2101 ;	..\fb_app_rollo11.c:510: portchanged=1;
   0897 D2 00              2102 	setb	_portchanged
   0899                    2103 00162$:
   0899 85 08 81           2104 	mov	sp,_bp
   089C D0 08              2105 	pop	_bp
                    0694   2106 	C$fb_app_rollo11.c$514$2$1 ==.
                    0694   2107 	XG$object_schalten$0$0 ==.
   089E 22                 2108 	ret
                           2109 ;------------------------------------------------------------
                           2110 ;Allocation info for local variables in function 'delay_timer'
                           2111 ;------------------------------------------------------------
                           2112 ;objno                     Allocated to registers r7 
                           2113 ;delay_state               Allocated to registers r6 
                           2114 ;m                         Allocated to registers r5 
                           2115 ;timerflags                Allocated to registers r6 r7 
                           2116 ;------------------------------------------------------------
                    0695   2117 	G$delay_timer$0$0 ==.
                    0695   2118 	C$fb_app_rollo11.c$519$2$1 ==.
                           2119 ;	..\fb_app_rollo11.c:519: void delay_timer(void)	// zählt alle 8 ms die Variable Timer hoch und prüft Queue
                           2120 ;	-----------------------------------------
                           2121 ;	 function delay_timer
                           2122 ;	-----------------------------------------
   089F                    2123 _delay_timer:
                    0695   2124 	C$fb_app_rollo11.c$528$1$1 ==.
                           2125 ;	..\fb_app_rollo11.c:528: RTCCON=0x61;		// RTC Flag löschen
   089F 75 D1 61           2126 	mov	_RTCCON,#0x61
                    0698   2127 	C$fb_app_rollo11.c$530$1$1 ==.
                           2128 ;	..\fb_app_rollo11.c:530: timer++;
   08A2 74 01              2129 	mov	a,#0x01
   08A4 25 09              2130 	add	a,_timer
   08A6 F5 09              2131 	mov	_timer,a
   08A8 E4                 2132 	clr	a
   08A9 35 0A              2133 	addc	a,(_timer + 1)
   08AB F5 0A              2134 	mov	(_timer + 1),a
                    06A3   2135 	C$fb_app_rollo11.c$531$1$1 ==.
                           2136 ;	..\fb_app_rollo11.c:531: timerflags = timer&(~(timer-1));
   08AD E5 09              2137 	mov	a,_timer
   08AF 24 FF              2138 	add	a,#0xFF
   08B1 FE                 2139 	mov	r6,a
   08B2 E5 0A              2140 	mov	a,(_timer + 1)
   08B4 34 FF              2141 	addc	a,#0xFF
   08B6 FF                 2142 	mov	r7,a
   08B7 EE                 2143 	mov	a,r6
   08B8 F4                 2144 	cpl	a
   08B9 FE                 2145 	mov	r6,a
   08BA EF                 2146 	mov	a,r7
   08BB F4                 2147 	cpl	a
   08BC FF                 2148 	mov	r7,a
   08BD E5 09              2149 	mov	a,_timer
   08BF 52 06              2150 	anl	ar6,a
   08C1 E5 0A              2151 	mov	a,(_timer + 1)
   08C3 52 07              2152 	anl	ar7,a
                    06BB   2153 	C$fb_app_rollo11.c$534$4$4 ==.
                           2154 ;	..\fb_app_rollo11.c:534: for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
   08C5 7D 00              2155 	mov	r5,#0x00
   08C7                    2156 00138$:
   08C7 BD 10 00           2157 	cjne	r5,#0x10,00173$
   08CA                    2158 00173$:
   08CA 50 40              2159 	jnc	00141$
                    06C2   2160 	C$fb_app_rollo11.c$536$2$2 ==.
                           2161 ;	..\fb_app_rollo11.c:536: if(timerbase[m]& 0x80){// wenn run-bit gesetzt
   08CC ED                 2162 	mov	a,r5
   08CD 24 10              2163 	add	a,#_timerbase
   08CF F9                 2164 	mov	r1,a
   08D0 E7                 2165 	mov	a,@r1
   08D1 FC                 2166 	mov	r4,a
   08D2 30 E7 34           2167 	jnb	acc.7,00140$
                    06CB   2168 	C$fb_app_rollo11.c$537$3$3 ==.
                           2169 ;	..\fb_app_rollo11.c:537: if((timerbase[m]==0x82)||(timerflags & (timerflagmask[timerbase[m]&0x7f]))){// wenn das flag mit der gespeicherten base übereinstimmt						
   08D5 ED                 2170 	mov	a,r5
   08D6 24 10              2171 	add	a,#_timerbase
   08D8 F9                 2172 	mov	r1,a
   08D9 87 04              2173 	mov	ar4,@r1
   08DB BC 82 02           2174 	cjne	r4,#0x82,00176$
   08DE 80 1E              2175 	sjmp	00103$
   08E0                    2176 00176$:
   08E0 ED                 2177 	mov	a,r5
   08E1 24 10              2178 	add	a,#_timerbase
   08E3 F9                 2179 	mov	r1,a
   08E4 87 04              2180 	mov	ar4,@r1
   08E6 53 04 7F           2181 	anl	ar4,#0x7F
   08E9 EC                 2182 	mov	a,r4
   08EA 2C                 2183 	add	a,r4
   08EB FB                 2184 	mov	r3,a
   08EC 90 17 8A           2185 	mov	dptr,#_timerflagmask
   08EF 93                 2186 	movc	a,@a+dptr
   08F0 CB                 2187 	xch	a,r3
   08F1 A3                 2188 	inc	dptr
   08F2 93                 2189 	movc	a,@a+dptr
   08F3 FC                 2190 	mov	r4,a
   08F4 EE                 2191 	mov	a,r6
   08F5 52 03              2192 	anl	ar3,a
   08F7 EF                 2193 	mov	a,r7
   08F8 52 04              2194 	anl	ar4,a
   08FA EB                 2195 	mov	a,r3
   08FB 4C                 2196 	orl	a,r4
   08FC 60 0B              2197 	jz	00140$
   08FE                    2198 00103$:
                    06F4   2199 	C$fb_app_rollo11.c$538$4$4 ==.
                           2200 ;	..\fb_app_rollo11.c:538: if (timercnt[m]>0x00){// wenn der counter läuft...
   08FE ED                 2201 	mov	a,r5
   08FF 24 24              2202 	add	a,#_timercnt
   0901 F9                 2203 	mov	r1,a
   0902 E7                 2204 	mov	a,@r1
   0903 FC                 2205 	mov	r4,a
   0904 60 03              2206 	jz	00140$
                    06FC   2207 	C$fb_app_rollo11.c$539$5$5 ==.
                           2208 ;	..\fb_app_rollo11.c:539: timercnt[m]=timercnt[m]-1;// den timer [m]decrementieren
   0906 EC                 2209 	mov	a,r4
   0907 14                 2210 	dec	a
   0908 F7                 2211 	mov	@r1,a
   0909                    2212 00140$:
                    06FF   2213 	C$fb_app_rollo11.c$534$1$1 ==.
                           2214 ;	..\fb_app_rollo11.c:534: for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
   0909 0D                 2215 	inc	r5
   090A 80 BB              2216 	sjmp	00138$
   090C                    2217 00141$:
                    0702   2218 	C$fb_app_rollo11.c$550$5$14 ==.
                           2219 ;	..\fb_app_rollo11.c:550: for(objno=0;objno<=15;objno++) {
   090C 7F 00              2220 	mov	r7,#0x00
   090E                    2221 00142$:
   090E EF                 2222 	mov	a,r7
   090F 24 F0              2223 	add	a,#0xff - 0x0F
   0911 50 03              2224 	jnc	00179$
   0913 02 0A 08           2225 	ljmp	00145$
   0916                    2226 00179$:
                    070C   2227 	C$fb_app_rollo11.c$551$2$6 ==.
                           2228 ;	..\fb_app_rollo11.c:551: delay_state=timerstate[objno];			//status des timer-records
   0916 EF                 2229 	mov	a,r7
   0917 24 34              2230 	add	a,#_timerstate
   0919 F9                 2231 	mov	r1,a
                    0710   2232 	C$fb_app_rollo11.c$552$2$6 ==.
                           2233 ;	..\fb_app_rollo11.c:552: if(delay_state!=0x00) {					// 0x00 = delay Eintrag ist leer   
   091A E7                 2234 	mov	a,@r1
   091B FE                 2235 	mov	r6,a
   091C 70 03              2236 	jnz	00180$
   091E 02 0A 04           2237 	ljmp	00144$
   0921                    2238 00180$:
                    0717   2239 	C$fb_app_rollo11.c$553$3$7 ==.
                           2240 ;	..\fb_app_rollo11.c:553: if(timercnt[objno]==0 && (timerbase[objno]&0x80)) { 	// wenn der cnt null und run=1, also zeit ist abgelaufen...
   0921 EF                 2241 	mov	a,r7
   0922 24 24              2242 	add	a,#_timercnt
   0924 F8                 2243 	mov	r0,a
   0925 E6                 2244 	mov	a,@r0
   0926 60 03              2245 	jz	00181$
   0928 02 0A 04           2246 	ljmp	00144$
   092B                    2247 00181$:
   092B EF                 2248 	mov	a,r7
   092C 24 10              2249 	add	a,#_timerbase
   092E FD                 2250 	mov	r5,a
   092F C0 00              2251 	push	ar0
   0931 A8 05              2252 	mov	r0,ar5
   0933 86 05              2253 	mov	ar5,@r0
   0935 D0 00              2254 	pop	ar0
   0937 ED                 2255 	mov	a,r5
   0938 20 E7 03           2256 	jb	acc.7,00182$
   093B 02 0A 04           2257 	ljmp	00144$
   093E                    2258 00182$:
                    0734   2259 	C$fb_app_rollo11.c$554$4$8 ==.
                           2260 ;	..\fb_app_rollo11.c:554: if (objno<=7){// wenns ein kurz oder langzeit objekt ist...
   093E EF                 2261 	mov	a,r7
   093F 24 F8              2262 	add	a,#0xff - 0x07
   0941 40 26              2263 	jc	00109$
                    0739   2264 	C$fb_app_rollo11.c$555$5$9 ==.
                           2265 ;	..\fb_app_rollo11.c:555: timerbase[objno]=0;
   0943 EF                 2266 	mov	a,r7
   0944 24 10              2267 	add	a,#_timerbase
   0946 C0 00              2268 	push	ar0
   0948 F8                 2269 	mov	r0,a
   0949 76 00              2270 	mov	@r0,#0x00
   094B D0 00              2271 	pop	ar0
                    0743   2272 	C$fb_app_rollo11.c$556$5$9 ==.
                           2273 ;	..\fb_app_rollo11.c:556: timercnt[objno]=0;
                    0743   2274 	C$fb_app_rollo11.c$557$5$9 ==.
                           2275 ;	..\fb_app_rollo11.c:557: timerstate[objno]=0;
                    0743   2276 	C$fb_app_rollo11.c$558$5$9 ==.
                           2277 ;	..\fb_app_rollo11.c:558: kanal[objno&0x03]=0x00;
   094D E4                 2278 	clr	a
   094E F6                 2279 	mov	@r0,a
   094F F7                 2280 	mov	@r1,a
   0950 74 03              2281 	mov	a,#0x03
   0952 5F                 2282 	anl	a,r7
   0953 24 47              2283 	add	a,#_kanal
   0955 F8                 2284 	mov	r0,a
   0956 76 00              2285 	mov	@r0,#0x00
                    074E   2286 	C$fb_app_rollo11.c$559$5$9 ==.
                           2287 ;	..\fb_app_rollo11.c:559: set_pause(objno,(delay_state));// einsch. verz "pause" für eventuelle Fahrt in gegenrichtung
   0958 C0 07              2288 	push	ar7
   095A C0 06              2289 	push	ar6
   095C C0 06              2290 	push	ar6
   095E 8F 82              2291 	mov	dpl,r7
   0960 12 0B 50           2292 	lcall	_set_pause
   0963 15 81              2293 	dec	sp
   0965 D0 06              2294 	pop	ar6
   0967 D0 07              2295 	pop	ar7
   0969                    2296 00109$:
                    075F   2297 	C$fb_app_rollo11.c$562$4$8 ==.
                           2298 ;	..\fb_app_rollo11.c:562: if (objno==9 ){	//Sicherheit 1
   0969 BF 09 1A           2299 	cjne	r7,#0x09,00113$
                    0762   2300 	C$fb_app_rollo11.c$563$5$10 ==.
                           2301 ;	..\fb_app_rollo11.c:563: if (delay_state == 0x01){
   096C BE 01 17           2302 	cjne	r6,#0x01,00113$
                    0765   2303 	C$fb_app_rollo11.c$564$6$11 ==.
                           2304 ;	..\fb_app_rollo11.c:564: timerstate[9]=0x02;// wenn ziel erreicht in delrec sichern
   096F 75 3D 02           2305 	mov	(_timerstate + 0x0009),#0x02
                    0768   2306 	C$fb_app_rollo11.c$565$6$11 ==.
                           2307 ;	..\fb_app_rollo11.c:565: Sobject_schalten(48,1);// und Sicherheitsobjekt über bypass schalten
   0972 C0 07              2308 	push	ar7
   0974 C0 06              2309 	push	ar6
   0976 74 01              2310 	mov	a,#0x01
   0978 C0 E0              2311 	push	acc
   097A 75 82 30           2312 	mov	dpl,#0x30
   097D 12 03 2B           2313 	lcall	_Sobject_schalten
   0980 15 81              2314 	dec	sp
   0982 D0 06              2315 	pop	ar6
   0984 D0 07              2316 	pop	ar7
   0986                    2317 00113$:
                    077C   2318 	C$fb_app_rollo11.c$569$4$8 ==.
                           2319 ;	..\fb_app_rollo11.c:569: if (objno==10 ){	//Sicherheit 2
   0986 BF 0A 1A           2320 	cjne	r7,#0x0A,00117$
                    077F   2321 	C$fb_app_rollo11.c$570$5$12 ==.
                           2322 ;	..\fb_app_rollo11.c:570: if (delay_state == 0x01){
   0989 BE 01 17           2323 	cjne	r6,#0x01,00117$
                    0782   2324 	C$fb_app_rollo11.c$571$6$13 ==.
                           2325 ;	..\fb_app_rollo11.c:571: timerstate[10]=0x02;// wenn ziel erreicht in delrec sichern
   098C 75 3E 02           2326 	mov	(_timerstate + 0x000a),#0x02
                    0785   2327 	C$fb_app_rollo11.c$572$6$13 ==.
                           2328 ;	..\fb_app_rollo11.c:572: Sobject_schalten(49,1);// und Sicherheitsobjekt über bypass schalten
   098F C0 07              2329 	push	ar7
   0991 C0 06              2330 	push	ar6
   0993 74 01              2331 	mov	a,#0x01
   0995 C0 E0              2332 	push	acc
   0997 75 82 31           2333 	mov	dpl,#0x31
   099A 12 03 2B           2334 	lcall	_Sobject_schalten
   099D 15 81              2335 	dec	sp
   099F D0 06              2336 	pop	ar6
   09A1 D0 07              2337 	pop	ar7
   09A3                    2338 00117$:
                    0799   2339 	C$fb_app_rollo11.c$576$4$8 ==.
                           2340 ;	..\fb_app_rollo11.c:576: if ((objno>=11) && (objno<=14)){// die Pausezeit der Kanaele
   09A3 BF 0B 00           2341 	cjne	r7,#0x0B,00192$
   09A6                    2342 00192$:
   09A6 40 3D              2343 	jc	00121$
   09A8 EF                 2344 	mov	a,r7
   09A9 24 F1              2345 	add	a,#0xff - 0x0E
   09AB 40 38              2346 	jc	00121$
                    07A3   2347 	C$fb_app_rollo11.c$577$5$14 ==.
                           2348 ;	..\fb_app_rollo11.c:577: kanal[objno-11]=kanal[objno-11]>>4;			// die oberen 4 bit des kanals sind die neue value.
   09AD EF                 2349 	mov	a,r7
   09AE 24 F5              2350 	add	a,#0xF5
   09B0 24 47              2351 	add	a,#_kanal
   09B2 F9                 2352 	mov	r1,a
   09B3 E7                 2353 	mov	a,@r1
   09B4 C4                 2354 	swap	a
   09B5 54 0F              2355 	anl	a,#0x0F
   09B7 FD                 2356 	mov	r5,a
   09B8 F7                 2357 	mov	@r1,a
                    07AF   2358 	C$fb_app_rollo11.c$578$5$14 ==.
                           2359 ;	..\fb_app_rollo11.c:578: timerbase[objno]=0;
   09B9 EF                 2360 	mov	a,r7
   09BA 24 10              2361 	add	a,#_timerbase
   09BC F8                 2362 	mov	r0,a
   09BD 76 00              2363 	mov	@r0,#0x00
                    07B5   2364 	C$fb_app_rollo11.c$579$5$14 ==.
                           2365 ;	..\fb_app_rollo11.c:579: timercnt[objno]=0;			//timer loeschen
   09BF EF                 2366 	mov	a,r7
   09C0 24 24              2367 	add	a,#_timercnt
   09C2 F8                 2368 	mov	r0,a
   09C3 76 00              2369 	mov	@r0,#0x00
                    07BB   2370 	C$fb_app_rollo11.c$580$5$14 ==.
                           2371 ;	..\fb_app_rollo11.c:580: timerstate[objno]=0;
   09C5 EF                 2372 	mov	a,r7
   09C6 24 34              2373 	add	a,#_timerstate
   09C8 F8                 2374 	mov	r0,a
   09C9 76 00              2375 	mov	@r0,#0x00
                    07C1   2376 	C$fb_app_rollo11.c$581$5$14 ==.
                           2377 ;	..\fb_app_rollo11.c:581: if(timerstate[objno-7])timerbase[objno-7]|=0x80;// timer run-bit des zugehörigen Langzeitobjektes setzen
   09CB EF                 2378 	mov	a,r7
   09CC 24 F9              2379 	add	a,#0xF9
   09CE 24 34              2380 	add	a,#_timerstate
   09D0 F9                 2381 	mov	r1,a
   09D1 E7                 2382 	mov	a,@r1
   09D2 60 11              2383 	jz	00121$
   09D4 EF                 2384 	mov	a,r7
   09D5 24 F9              2385 	add	a,#0xF9
   09D7 FD                 2386 	mov	r5,a
   09D8 24 10              2387 	add	a,#_timerbase
   09DA F9                 2388 	mov	r1,a
   09DB ED                 2389 	mov	a,r5
   09DC 24 10              2390 	add	a,#_timerbase
   09DE F8                 2391 	mov	r0,a
   09DF 86 05              2392 	mov	ar5,@r0
   09E1 74 80              2393 	mov	a,#0x80
   09E3 4D                 2394 	orl	a,r5
   09E4 F7                 2395 	mov	@r1,a
   09E5                    2396 00121$:
                    07DB   2397 	C$fb_app_rollo11.c$583$4$8 ==.
                           2398 ;	..\fb_app_rollo11.c:583: if (objno>=15){// handmode kurz/langtele + einschaltverz + ausschaltverz
   09E5 BF 0F 00           2399 	cjne	r7,#0x0F,00196$
   09E8                    2400 00196$:
   09E8 40 18              2401 	jc	00130$
                    07E0   2402 	C$fb_app_rollo11.c$585$5$15 ==.
                           2403 ;	..\fb_app_rollo11.c:585: if (delay_state == 0x12) timerstate[15]=0x22; // wenn ziel 2 erreicht,  sichern
   09EA BE 12 03           2404 	cjne	r6,#0x12,00124$
   09ED 75 43 22           2405 	mov	(_timerstate + 0x000f),#0x22
   09F0                    2406 00124$:
                    07E6   2407 	C$fb_app_rollo11.c$586$5$15 ==.
                           2408 ;	..\fb_app_rollo11.c:586: if (delay_state == 0x01){
   09F0 BE 01 09           2409 	cjne	r6,#0x01,00126$
                    07E9   2410 	C$fb_app_rollo11.c$587$6$16 ==.
                           2411 ;	..\fb_app_rollo11.c:587: timerbase[15]=0x80 + 3;
   09F3 75 1F 83           2412 	mov	(_timerbase + 0x000f),#0x83
                    07EC   2413 	C$fb_app_rollo11.c$588$6$16 ==.
                           2414 ;	..\fb_app_rollo11.c:588: timerstate[15]=0x12;
   09F6 75 43 12           2415 	mov	(_timerstate + 0x000f),#0x12
                    07EF   2416 	C$fb_app_rollo11.c$589$6$16 ==.
                           2417 ;	..\fb_app_rollo11.c:589: timercnt[15]= 20;// wenn ziel 1 erreicht , sichern und restzeit fuer ziel 2 schreiben
   09F9 75 33 14           2418 	mov	(_timercnt + 0x000f),#0x14
   09FC                    2419 00126$:
                    07F2   2420 	C$fb_app_rollo11.c$592$5$15 ==.
                           2421 ;	..\fb_app_rollo11.c:592: if (delay_state == 0x04) timerstate[15]= 0x08;// wenn ziel erreicht , sichern
   09FC BE 04 03           2422 	cjne	r6,#0x04,00130$
   09FF 75 43 08           2423 	mov	(_timerstate + 0x000f),#0x08
   0A02                    2424 00130$:
                    07F8   2425 	C$fb_app_rollo11.c$594$4$8 ==.
                           2426 ;	..\fb_app_rollo11.c:594: portchanged=1;
   0A02 D2 00              2427 	setb	_portchanged
   0A04                    2428 00144$:
                    07FA   2429 	C$fb_app_rollo11.c$550$1$1 ==.
                           2430 ;	..\fb_app_rollo11.c:550: for(objno=0;objno<=15;objno++) {
   0A04 0F                 2431 	inc	r7
   0A05 02 09 0E           2432 	ljmp	00142$
   0A08                    2433 00145$:
                    07FE   2434 	C$fb_app_rollo11.c$604$1$1 ==.
                           2435 ;	..\fb_app_rollo11.c:604: if (eeprom[0xE5]& 0xC0){
   0A08 90 1D E5           2436 	mov	dptr,#(_eeprom + 0x00e5)
   0A0B E4                 2437 	clr	a
   0A0C 93                 2438 	movc	a,@a+dptr
   0A0D FF                 2439 	mov	r7,a
   0A0E 54 C0              2440 	anl	a,#0xC0
   0A10 60 03              2441 	jz	00146$
                    0808   2442 	C$fb_app_rollo11.c$605$2$17 ==.
                           2443 ;	..\fb_app_rollo11.c:605: handsteuerung();   // Handbetätigung nur jedes 8.mal ausführen
   0A12 12 0A 16           2444 	lcall	_handsteuerung
   0A15                    2445 00146$:
                    080B   2446 	C$fb_app_rollo11.c$609$2$1 ==.
                    080B   2447 	XG$delay_timer$0$0 ==.
   0A15 22                 2448 	ret
                           2449 ;------------------------------------------------------------
                           2450 ;Allocation info for local variables in function 'handsteuerung'
                           2451 ;------------------------------------------------------------
                           2452 ;n                         Allocated to registers r6 
                           2453 ;tmph                      Allocated to registers 
                           2454 ;key_pattern               Allocated to registers r7 
                           2455 ;Tasten                    Allocated to registers r7 
                           2456 ;------------------------------------------------------------
                    080C   2457 	G$handsteuerung$0$0 ==.
                    080C   2458 	C$fb_app_rollo11.c$684$2$1 ==.
                           2459 ;	..\fb_app_rollo11.c:684: void handsteuerung(void)
                           2460 ;	-----------------------------------------
                           2461 ;	 function handsteuerung
                           2462 ;	-----------------------------------------
   0A16                    2463 _handsteuerung:
                    080C   2464 	C$fb_app_rollo11.c$699$1$1 ==.
                           2465 ;	..\fb_app_rollo11.c:699: if((TMOD&0x0F)==0x02 && fb_state==0) {
   0A16 74 0F              2466 	mov	a,#0x0F
   0A18 55 89              2467 	anl	a,_TMOD
   0A1A FF                 2468 	mov	r7,a
   0A1B BF 02 02           2469 	cjne	r7,#0x02,00155$
   0A1E 80 03              2470 	sjmp	00156$
   0A20                    2471 00155$:
   0A20 02 0B 24           2472 	ljmp	00136$
   0A23                    2473 00156$:
   0A23 E5 77              2474 	mov	a,_fb_state
   0A25 60 03              2475 	jz	00157$
   0A27 02 0B 24           2476 	ljmp	00136$
   0A2A                    2477 00157$:
                    0820   2478 	C$fb_app_rollo11.c$709$2$2 ==.
                           2479 ;	..\fb_app_rollo11.c:709: while( (TMOD&0x0F)==0x02 && ( TL0>0x72));// PWM scannen um "Hand"-Tasten abzufragen
   0A2A                    2480 00102$:
   0A2A 74 0F              2481 	mov	a,#0x0F
   0A2C 55 89              2482 	anl	a,_TMOD
   0A2E FF                 2483 	mov	r7,a
   0A2F BF 02 06           2484 	cjne	r7,#0x02,00104$
   0A32 E5 8A              2485 	mov	a,_TL0
   0A34 24 8D              2486 	add	a,#0xff - 0x72
   0A36 40 F2              2487 	jc	00102$
   0A38                    2488 00104$:
                    082E   2489 	C$fb_app_rollo11.c$734$2$2 ==.
                           2490 ;	..\fb_app_rollo11.c:734: key_pattern=(0x01<<(delay_toggle&0x03));
   0A38 74 03              2491 	mov	a,#0x03
   0A3A 55 09              2492 	anl	a,_delay_toggle
   0A3C FF                 2493 	mov	r7,a
   0A3D 8F F0              2494 	mov	b,r7
   0A3F 05 F0              2495 	inc	b
   0A41 74 01              2496 	mov	a,#0x01
   0A43 80 02              2497 	sjmp	00163$
   0A45                    2498 00161$:
   0A45 25 E0              2499 	add	a,acc
   0A47                    2500 00163$:
   0A47 D5 F0 FB           2501 	djnz	b,00161$
                    0840   2502 	C$fb_app_rollo11.c$735$2$2 ==.
                           2503 ;	..\fb_app_rollo11.c:735: P0 = ~key_pattern;
   0A4A FF                 2504 	mov	r7,a
   0A4B F4                 2505 	cpl	a
   0A4C F5 80              2506 	mov	_P0,a
                    0844   2507 	C$fb_app_rollo11.c$736$2$2 ==.
                           2508 ;	..\fb_app_rollo11.c:736: P0_5=1;
   0A4E D2 85              2509 	setb	_P0_5
                    0846   2510 	C$fb_app_rollo11.c$737$2$2 ==.
                           2511 ;	..\fb_app_rollo11.c:737: if(!P0_5 && !ledport)ledport=0x08+(delay_toggle&0x03);	
   0A50 20 85 0C           2512 	jb	_P0_5,00106$
   0A53 E5 4C              2513 	mov	a,_ledport
   0A55 70 08              2514 	jnz	00106$
   0A57 74 03              2515 	mov	a,#0x03
   0A59 55 09              2516 	anl	a,_delay_toggle
   0A5B 24 08              2517 	add	a,#0x08
   0A5D F5 4C              2518 	mov	_ledport,a
   0A5F                    2519 00106$:
                    0855   2520 	C$fb_app_rollo11.c$739$2$2 ==.
                           2521 ;	..\fb_app_rollo11.c:739: P0=oldportbuffer; 
   0A5F 85 0E 80           2522 	mov	_P0,_oldportbuffer
                    0858   2523 	C$fb_app_rollo11.c$746$2$2 ==.
                           2524 ;	..\fb_app_rollo11.c:746: if (key_pattern==0x08)
   0A62 BF 08 02           2525 	cjne	r7,#0x08,00166$
   0A65 80 03              2526 	sjmp	00167$
   0A67                    2527 00166$:
   0A67 02 0B 24           2528 	ljmp	00136$
   0A6A                    2529 00167$:
                    0860   2530 	C$fb_app_rollo11.c$749$3$3 ==.
                           2531 ;	..\fb_app_rollo11.c:749: Tasten=ledport;
   0A6A AF 4C              2532 	mov	r7,_ledport
                    0862   2533 	C$fb_app_rollo11.c$750$3$3 ==.
                           2534 ;	..\fb_app_rollo11.c:750: ledport=0;
   0A6C 75 4C 00           2535 	mov	_ledport,#0x00
                    0865   2536 	C$fb_app_rollo11.c$754$3$3 ==.
                           2537 ;	..\fb_app_rollo11.c:754: if (Tasten & 0x08 ){
   0A6F EF                 2538 	mov	a,r7
   0A70 30 E3 13           2539 	jnb	acc.3,00123$
                    0869   2540 	C$fb_app_rollo11.c$755$4$4 ==.
                           2541 ;	..\fb_app_rollo11.c:755: if (!Tval ){// steigende Flanke des Tasters 
   0A73 E5 44              2542 	mov	a,_Tval
   0A75 60 03              2543 	jz	00169$
   0A77 02 0B 0F           2544 	ljmp	00124$
   0A7A                    2545 00169$:
                    0870   2546 	C$fb_app_rollo11.c$758$5$5 ==.
                           2547 ;	..\fb_app_rollo11.c:758: timerstate[15]=0x01;
   0A7A 75 43 01           2548 	mov	(_timerstate + 0x000f),#0x01
                    0873   2549 	C$fb_app_rollo11.c$759$5$5 ==.
                           2550 ;	..\fb_app_rollo11.c:759: timerbase[15]=0x80 + 2;
   0A7D 75 1F 82           2551 	mov	(_timerbase + 0x000f),#0x82
                    0876   2552 	C$fb_app_rollo11.c$760$5$5 ==.
                           2553 ;	..\fb_app_rollo11.c:760: timercnt[15]= 50;
   0A80 75 33 32           2554 	mov	(_timercnt + 0x000f),#0x32
   0A83 02 0B 0F           2555 	ljmp	00124$
   0A86                    2556 00123$:
                    087C   2557 	C$fb_app_rollo11.c$764$4$6 ==.
                           2558 ;	..\fb_app_rollo11.c:764: if ( Tval & 0x08){ // wenn tasten >7 und Tval <=7 also taste losgelassen...
   0A86 E5 44              2559 	mov	a,_Tval
   0A88 20 E3 03           2560 	jb	acc.3,00170$
   0A8B 02 0B 0F           2561 	ljmp	00124$
   0A8E                    2562 00170$:
                    0884   2563 	C$fb_app_rollo11.c$765$5$7 ==.
                           2564 ;	..\fb_app_rollo11.c:765: if (timerstate[15]&0x20){
   0A8E E5 43              2565 	mov	a,(_timerstate + 0x000f)
   0A90 30 E5 29           2566 	jnb	acc.5,00114$
                    0889   2567 	C$fb_app_rollo11.c$766$6$8 ==.
                           2568 ;	..\fb_app_rollo11.c:766: handmode = !handmode;
   0A93 B2 02              2569 	cpl	_handmode
                    088B   2570 	C$fb_app_rollo11.c$767$6$8 ==.
                           2571 ;	..\fb_app_rollo11.c:767: timerbase[15]=0;
   0A95 75 1F 00           2572 	mov	(_timerbase + 0x000f),#0x00
                    088E   2573 	C$fb_app_rollo11.c$768$6$8 ==.
                           2574 ;	..\fb_app_rollo11.c:768: timerstate[15]=0;
   0A98 75 43 00           2575 	mov	(_timerstate + 0x000f),#0x00
                    0891   2576 	C$fb_app_rollo11.c$769$6$8 ==.
                           2577 ;	..\fb_app_rollo11.c:769: timercnt[15]=0;
   0A9B 75 33 00           2578 	mov	(_timercnt + 0x000f),#0x00
                    0894   2579 	C$fb_app_rollo11.c$770$6$8 ==.
                           2580 ;	..\fb_app_rollo11.c:770: if (handmode){
   0A9E 30 02 14           2581 	jnb	_handmode,00111$
                    0897   2582 	C$fb_app_rollo11.c$771$7$9 ==.
                           2583 ;	..\fb_app_rollo11.c:771: for(n=0;n<=3;n++) kanal[n]=0x00;
   0AA1 7E 00              2584 	mov	r6,#0x00
   0AA3                    2585 00132$:
   0AA3 EE                 2586 	mov	a,r6
   0AA4 24 FC              2587 	add	a,#0xff - 0x03
   0AA6 40 09              2588 	jc	00135$
   0AA8 EE                 2589 	mov	a,r6
   0AA9 24 47              2590 	add	a,#_kanal
   0AAB F8                 2591 	mov	r0,a
   0AAC 76 00              2592 	mov	@r0,#0x00
   0AAE 0E                 2593 	inc	r6
   0AAF 80 F2              2594 	sjmp	00132$
   0AB1                    2595 00135$:
                    08A7   2596 	C$fb_app_rollo11.c$772$7$9 ==.
                           2597 ;	..\fb_app_rollo11.c:772: portchanged=1;
   0AB1 D2 00              2598 	setb	_portchanged
   0AB3 80 07              2599 	sjmp	00114$
   0AB5                    2600 00111$:
                    08AB   2601 	C$fb_app_rollo11.c$775$7$10 ==.
                           2602 ;	..\fb_app_rollo11.c:775: sobj_update();
   0AB5 C0 07              2603 	push	ar7
   0AB7 12 0B 25           2604 	lcall	_sobj_update
   0ABA D0 07              2605 	pop	ar7
   0ABC                    2606 00114$:
                    08B2   2607 	C$fb_app_rollo11.c$778$5$7 ==.
                           2608 ;	..\fb_app_rollo11.c:778: if (handmode){// wenn handmode aktiv...
   0ABC 30 02 47           2609 	jnb	_handmode,00119$
                    08B5   2610 	C$fb_app_rollo11.c$779$6$11 ==.
                           2611 ;	..\fb_app_rollo11.c:779: if (timerstate[15]&0x02){// status der zeit=2 also abgelaufen..
   0ABF E5 43              2612 	mov	a,(_timerstate + 0x000f)
   0AC1 30 E1 22           2613 	jnb	acc.1,00116$
                    08BA   2614 	C$fb_app_rollo11.c$780$7$12 ==.
                           2615 ;	..\fb_app_rollo11.c:780: object_schalten(((Tval&0x07)>>1)+12,(Tval&0x01));
   0AC4 E5 44              2616 	mov	a,_Tval
   0AC6 54 01              2617 	anl	a,#0x01
   0AC8 24 FF              2618 	add	a,#0xff
   0ACA 92 18              2619 	mov	b0,c
   0ACC 74 07              2620 	mov	a,#0x07
   0ACE 55 44              2621 	anl	a,_Tval
   0AD0 C3                 2622 	clr	c
   0AD1 13                 2623 	rrc	a
   0AD2 24 0C              2624 	add	a,#0x0C
   0AD4 F5 82              2625 	mov	dpl,a
   0AD6 A2 18              2626 	mov	c,b0
   0AD8 92 F0              2627 	mov	b[0],c
   0ADA C0 07              2628 	push	ar7
   0ADC 85 F0 23           2629 	mov	bits,b
   0ADF 12 04 95           2630 	lcall	_object_schalten
   0AE2 D0 07              2631 	pop	ar7
   0AE4 80 20              2632 	sjmp	00119$
   0AE6                    2633 00116$:
                    08DC   2634 	C$fb_app_rollo11.c$783$7$13 ==.
                           2635 ;	..\fb_app_rollo11.c:783: object_schalten(((Tval&0x07)>>1)+8,(Tval&0x01));
   0AE6 E5 44              2636 	mov	a,_Tval
   0AE8 54 01              2637 	anl	a,#0x01
   0AEA 24 FF              2638 	add	a,#0xff
   0AEC 92 18              2639 	mov	b0,c
   0AEE 74 07              2640 	mov	a,#0x07
   0AF0 55 44              2641 	anl	a,_Tval
   0AF2 C3                 2642 	clr	c
   0AF3 13                 2643 	rrc	a
   0AF4 24 08              2644 	add	a,#0x08
   0AF6 F5 82              2645 	mov	dpl,a
   0AF8 A2 18              2646 	mov	c,b0
   0AFA 92 F0              2647 	mov	b[0],c
   0AFC C0 07              2648 	push	ar7
   0AFE 85 F0 23           2649 	mov	bits,b
   0B01 12 04 95           2650 	lcall	_object_schalten
   0B04 D0 07              2651 	pop	ar7
   0B06                    2652 00119$:
                    08FC   2653 	C$fb_app_rollo11.c$787$5$7 ==.
                           2654 ;	..\fb_app_rollo11.c:787: timerbase[15]=0x80 + 3;//130ms
   0B06 75 1F 83           2655 	mov	(_timerbase + 0x000f),#0x83
                    08FF   2656 	C$fb_app_rollo11.c$788$5$7 ==.
                           2657 ;	..\fb_app_rollo11.c:788: timerstate[15]=0x04;
   0B09 75 43 04           2658 	mov	(_timerstate + 0x000f),#0x04
                    0902   2659 	C$fb_app_rollo11.c$789$5$7 ==.
                           2660 ;	..\fb_app_rollo11.c:789: timercnt[15]=116;//=15 Sekunden
   0B0C 75 33 74           2661 	mov	(_timercnt + 0x000f),#0x74
   0B0F                    2662 00124$:
                    0905   2663 	C$fb_app_rollo11.c$792$3$3 ==.
                           2664 ;	..\fb_app_rollo11.c:792: Tval=Tasten;
   0B0F 8F 44              2665 	mov	_Tval,r7
                    0907   2666 	C$fb_app_rollo11.c$794$3$3 ==.
                           2667 ;	..\fb_app_rollo11.c:794: if(timerstate[15]&0x08){
   0B11 E5 43              2668 	mov	a,(_timerstate + 0x000f)
   0B13 30 E3 0E           2669 	jnb	acc.3,00136$
                    090C   2670 	C$fb_app_rollo11.c$795$4$14 ==.
                           2671 ;	..\fb_app_rollo11.c:795: handmode=0;//handmode automatisch ausschalten
   0B16 C2 02              2672 	clr	_handmode
                    090E   2673 	C$fb_app_rollo11.c$797$4$14 ==.
                           2674 ;	..\fb_app_rollo11.c:797: timerbase[15]=0;
   0B18 75 1F 00           2675 	mov	(_timerbase + 0x000f),#0x00
                    0911   2676 	C$fb_app_rollo11.c$798$4$14 ==.
                           2677 ;	..\fb_app_rollo11.c:798: timerstate[15]=0;
   0B1B 75 43 00           2678 	mov	(_timerstate + 0x000f),#0x00
                    0914   2679 	C$fb_app_rollo11.c$799$4$14 ==.
                           2680 ;	..\fb_app_rollo11.c:799: timercnt[15]=0;
   0B1E 75 33 00           2681 	mov	(_timercnt + 0x000f),#0x00
                    0917   2682 	C$fb_app_rollo11.c$800$4$14 ==.
                           2683 ;	..\fb_app_rollo11.c:800: sobj_update();
   0B21 12 0B 25           2684 	lcall	_sobj_update
   0B24                    2685 00136$:
                    091A   2686 	C$fb_app_rollo11.c$805$1$1 ==.
                    091A   2687 	XG$handsteuerung$0$0 ==.
   0B24 22                 2688 	ret
                           2689 ;------------------------------------------------------------
                           2690 ;Allocation info for local variables in function 'sobj_update'
                           2691 ;------------------------------------------------------------
                    091B   2692 	G$sobj_update$0$0 ==.
                    091B   2693 	C$fb_app_rollo11.c$809$1$1 ==.
                           2694 ;	..\fb_app_rollo11.c:809: void sobj_update(void)
                           2695 ;	-----------------------------------------
                           2696 ;	 function sobj_update
                           2697 ;	-----------------------------------------
   0B25                    2698 _sobj_update:
                    091B   2699 	C$fb_app_rollo11.c$811$1$1 ==.
                           2700 ;	..\fb_app_rollo11.c:811: Sobject_schalten(16,read_obj_value(16)&0x01);
   0B25 75 82 10           2701 	mov	dpl,#0x10
   0B28 12 02 4E           2702 	lcall	_read_obj_value
   0B2B AC 82              2703 	mov	r4,dpl
   0B2D 53 04 01           2704 	anl	ar4,#0x01
   0B30 C0 04              2705 	push	ar4
   0B32 75 82 10           2706 	mov	dpl,#0x10
   0B35 12 03 2B           2707 	lcall	_Sobject_schalten
   0B38 15 81              2708 	dec	sp
                    0930   2709 	C$fb_app_rollo11.c$812$1$1 ==.
                           2710 ;	..\fb_app_rollo11.c:812: Sobject_schalten(17,read_obj_value(17)&0x01);
   0B3A 75 82 11           2711 	mov	dpl,#0x11
   0B3D 12 02 4E           2712 	lcall	_read_obj_value
   0B40 AC 82              2713 	mov	r4,dpl
   0B42 53 04 01           2714 	anl	ar4,#0x01
   0B45 C0 04              2715 	push	ar4
   0B47 75 82 11           2716 	mov	dpl,#0x11
   0B4A 12 03 2B           2717 	lcall	_Sobject_schalten
   0B4D 15 81              2718 	dec	sp
                    0945   2719 	C$fb_app_rollo11.c$813$1$1 ==.
                    0945   2720 	XG$sobj_update$0$0 ==.
   0B4F 22                 2721 	ret
                           2722 ;------------------------------------------------------------
                           2723 ;Allocation info for local variables in function 'set_pause'
                           2724 ;------------------------------------------------------------
                           2725 ;Pstate                    Allocated to stack - _bp -3
                           2726 ;objnr                     Allocated to registers r7 
                           2727 ;pause                     Allocated to registers r7 
                           2728 ;pauseobj                  Allocated to registers r6 
                           2729 ;------------------------------------------------------------
                    0946   2730 	G$set_pause$0$0 ==.
                    0946   2731 	C$fb_app_rollo11.c$814$1$1 ==.
                           2732 ;	..\fb_app_rollo11.c:814: void set_pause(unsigned char objnr,unsigned char Pstate)// setzt die Pausezeit und traegt Pstate in timerstate[ ] ein
                           2733 ;	-----------------------------------------
                           2734 ;	 function set_pause
                           2735 ;	-----------------------------------------
   0B50                    2736 _set_pause:
   0B50 C0 08              2737 	push	_bp
   0B52 85 81 08           2738 	mov	_bp,sp
   0B55 AF 82              2739 	mov	r7,dpl
                    094D   2740 	C$fb_app_rollo11.c$817$1$1 ==.
                           2741 ;	..\fb_app_rollo11.c:817: pauseobj=(objnr&0x03)+11;
   0B57 53 07 03           2742 	anl	ar7,#0x03
   0B5A 74 0B              2743 	mov	a,#0x0B
   0B5C 2F                 2744 	add	a,r7
                    0953   2745 	C$fb_app_rollo11.c$818$1$1 ==.
                           2746 ;	..\fb_app_rollo11.c:818: timerstate[pauseobj]=Pstate;
   0B5D FE                 2747 	mov	r6,a
   0B5E 24 34              2748 	add	a,#_timerstate
   0B60 F8                 2749 	mov	r0,a
   0B61 E5 08              2750 	mov	a,_bp
   0B63 24 FD              2751 	add	a,#0xfd
   0B65 F9                 2752 	mov	r1,a
   0B66 E7                 2753 	mov	a,@r1
   0B67 F6                 2754 	mov	@r0,a
                    095E   2755 	C$fb_app_rollo11.c$819$1$1 ==.
                           2756 ;	..\fb_app_rollo11.c:819: switch ((eeprom[0xEE]>>((objnr&0x03)<<1))&0x03) { // Dauer zwischen auf und ab
   0B68 90 1D EE           2757 	mov	dptr,#(_eeprom + 0x00ee)
   0B6B E4                 2758 	clr	a
   0B6C 93                 2759 	movc	a,@a+dptr
   0B6D FD                 2760 	mov	r5,a
   0B6E E4                 2761 	clr	a
   0B6F CF                 2762 	xch	a,r7
   0B70 25 E0              2763 	add	a,acc
   0B72 CF                 2764 	xch	a,r7
   0B73 33                 2765 	rlc	a
   0B74 FC                 2766 	mov	r4,a
   0B75 8F F0              2767 	mov	b,r7
   0B77 05 F0              2768 	inc	b
   0B79 ED                 2769 	mov	a,r5
   0B7A 80 02              2770 	sjmp	00112$
   0B7C                    2771 00111$:
   0B7C C3                 2772 	clr	c
   0B7D 13                 2773 	rrc	a
   0B7E                    2774 00112$:
   0B7E D5 F0 FB           2775 	djnz	b,00111$
   0B81 54 03              2776 	anl	a,#0x03
   0B83 FF                 2777 	mov	r7,a
   0B84 60 0A              2778 	jz	00101$
   0B86 BF 01 02           2779 	cjne	r7,#0x01,00114$
   0B89 80 09              2780 	sjmp	00102$
   0B8B                    2781 00114$:
                    0981   2782 	C$fb_app_rollo11.c$820$2$2 ==.
                           2783 ;	..\fb_app_rollo11.c:820: case 0:	// 0,5s
   0B8B BF 02 0E           2784 	cjne	r7,#0x02,00104$
   0B8E 80 08              2785 	sjmp	00103$
   0B90                    2786 00101$:
                    0986   2787 	C$fb_app_rollo11.c$821$2$2 ==.
                           2788 ;	..\fb_app_rollo11.c:821: pause=4 ;
   0B90 7F 04              2789 	mov	r7,#0x04
                    0988   2790 	C$fb_app_rollo11.c$822$2$2 ==.
                           2791 ;	..\fb_app_rollo11.c:822: break;
                    0988   2792 	C$fb_app_rollo11.c$823$2$2 ==.
                           2793 ;	..\fb_app_rollo11.c:823: case 1:	// 1s
   0B92 80 0A              2794 	sjmp	00105$
   0B94                    2795 00102$:
                    098A   2796 	C$fb_app_rollo11.c$824$2$2 ==.
                           2797 ;	..\fb_app_rollo11.c:824: pause=8 ;
   0B94 7F 08              2798 	mov	r7,#0x08
                    098C   2799 	C$fb_app_rollo11.c$825$2$2 ==.
                           2800 ;	..\fb_app_rollo11.c:825: break;
                    098C   2801 	C$fb_app_rollo11.c$826$2$2 ==.
                           2802 ;	..\fb_app_rollo11.c:826: case 2:	// 2s
   0B96 80 06              2803 	sjmp	00105$
   0B98                    2804 00103$:
                    098E   2805 	C$fb_app_rollo11.c$827$2$2 ==.
                           2806 ;	..\fb_app_rollo11.c:827: pause=16 ;
   0B98 7F 10              2807 	mov	r7,#0x10
                    0990   2808 	C$fb_app_rollo11.c$828$2$2 ==.
                           2809 ;	..\fb_app_rollo11.c:828: break;
                    0990   2810 	C$fb_app_rollo11.c$829$2$2 ==.
                           2811 ;	..\fb_app_rollo11.c:829: default:	// 5s
   0B9A 80 02              2812 	sjmp	00105$
   0B9C                    2813 00104$:
                    0992   2814 	C$fb_app_rollo11.c$830$2$2 ==.
                           2815 ;	..\fb_app_rollo11.c:830: pause=39 ;
   0B9C 7F 27              2816 	mov	r7,#0x27
                    0994   2817 	C$fb_app_rollo11.c$832$1$1 ==.
                           2818 ;	..\fb_app_rollo11.c:832: }
   0B9E                    2819 00105$:
                    0994   2820 	C$fb_app_rollo11.c$833$1$1 ==.
                           2821 ;	..\fb_app_rollo11.c:833: timercnt[pauseobj]=pause;
   0B9E EE                 2822 	mov	a,r6
   0B9F 24 24              2823 	add	a,#_timercnt
   0BA1 F8                 2824 	mov	r0,a
   0BA2 A6 07              2825 	mov	@r0,ar7
                    099A   2826 	C$fb_app_rollo11.c$834$1$1 ==.
                           2827 ;	..\fb_app_rollo11.c:834: timerbase[pauseobj]= 3 | 0x80;
   0BA4 EE                 2828 	mov	a,r6
   0BA5 24 10              2829 	add	a,#_timerbase
   0BA7 F8                 2830 	mov	r0,a
   0BA8 76 83              2831 	mov	@r0,#0x83
   0BAA D0 08              2832 	pop	_bp
                    09A2   2833 	C$fb_app_rollo11.c$836$1$1 ==.
                    09A2   2834 	XG$set_pause$0$0 ==.
   0BAC 22                 2835 	ret
                           2836 ;------------------------------------------------------------
                           2837 ;Allocation info for local variables in function 'set_entriegeln'
                           2838 ;------------------------------------------------------------
                           2839 ;zeitnr                    Allocated to registers r7 
                           2840 ;svbase                    Allocated to registers r6 
                           2841 ;------------------------------------------------------------
                    09A3   2842 	G$set_entriegeln$0$0 ==.
                    09A3   2843 	C$fb_app_rollo11.c$839$1$1 ==.
                           2844 ;	..\fb_app_rollo11.c:839: void set_entriegeln(unsigned char zeitnr)// Setzt die zyklische überwachungszeit
                           2845 ;	-----------------------------------------
                           2846 ;	 function set_entriegeln
                           2847 ;	-----------------------------------------
   0BAD                    2848 _set_entriegeln:
   0BAD AF 82              2849 	mov	r7,dpl
                    09A5   2850 	C$fb_app_rollo11.c$844$1$1 ==.
                           2851 ;	..\fb_app_rollo11.c:844: svbase=eeprom[0xD9]&0x0F;
   0BAF 90 1D D9           2852 	mov	dptr,#(_eeprom + 0x00d9)
   0BB2 E4                 2853 	clr	a
   0BB3 93                 2854 	movc	a,@a+dptr
                    09AA   2855 	C$fb_app_rollo11.c$845$1$1 ==.
                           2856 ;	..\fb_app_rollo11.c:845: if(svbase){
   0BB4 54 0F              2857 	anl	a,#0x0F
   0BB6 FE                 2858 	mov	r6,a
   0BB7 60 19              2859 	jz	00102$
                    09AF   2860 	C$fb_app_rollo11.c$846$2$2 ==.
                           2861 ;	..\fb_app_rollo11.c:846: timercnt[zeitnr]=svfaktorarray[svbase];
   0BB9 EF                 2862 	mov	a,r7
   0BBA 24 24              2863 	add	a,#_timercnt
   0BBC F9                 2864 	mov	r1,a
   0BBD EE                 2865 	mov	a,r6
   0BBE 90 17 96           2866 	mov	dptr,#_svfaktorarray
   0BC1 93                 2867 	movc	a,@a+dptr
   0BC2 FE                 2868 	mov	r6,a
   0BC3 F7                 2869 	mov	@r1,a
                    09BA   2870 	C$fb_app_rollo11.c$847$2$2 ==.
                           2871 ;	..\fb_app_rollo11.c:847: timerbase[zeitnr]=5 | 0x80;
   0BC4 EF                 2872 	mov	a,r7
   0BC5 24 10              2873 	add	a,#_timerbase
   0BC7 F8                 2874 	mov	r0,a
   0BC8 76 85              2875 	mov	@r0,#0x85
                    09C0   2876 	C$fb_app_rollo11.c$848$2$2 ==.
                           2877 ;	..\fb_app_rollo11.c:848: timerstate[zeitnr]=0x01;
   0BCA EF                 2878 	mov	a,r7
   0BCB 24 34              2879 	add	a,#_timerstate
   0BCD F8                 2880 	mov	r0,a
   0BCE 76 01              2881 	mov	@r0,#0x01
   0BD0 80 0C              2882 	sjmp	00104$
   0BD2                    2883 00102$:
                    09C8   2884 	C$fb_app_rollo11.c$851$2$3 ==.
                           2885 ;	..\fb_app_rollo11.c:851: timerbase[zeitnr]=0;
   0BD2 EF                 2886 	mov	a,r7
   0BD3 24 10              2887 	add	a,#_timerbase
   0BD5 F8                 2888 	mov	r0,a
   0BD6 76 00              2889 	mov	@r0,#0x00
                    09CE   2890 	C$fb_app_rollo11.c$852$2$3 ==.
                           2891 ;	..\fb_app_rollo11.c:852: timerstate[zeitnr]=0;
   0BD8 EF                 2892 	mov	a,r7
   0BD9 24 34              2893 	add	a,#_timerstate
   0BDB F8                 2894 	mov	r0,a
   0BDC 76 00              2895 	mov	@r0,#0x00
   0BDE                    2896 00104$:
                    09D4   2897 	C$fb_app_rollo11.c$855$1$1 ==.
                    09D4   2898 	XG$set_entriegeln$0$0 ==.
   0BDE 22                 2899 	ret
                           2900 ;------------------------------------------------------------
                           2901 ;Allocation info for local variables in function 'port_schalten'
                           2902 ;------------------------------------------------------------
                           2903 ;kmod                      Allocated to registers r7 
                           2904 ;------------------------------------------------------------
                    09D5   2905 	G$port_schalten$0$0 ==.
                    09D5   2906 	C$fb_app_rollo11.c$918$1$1 ==.
                           2907 ;	..\fb_app_rollo11.c:918: void port_schalten(void)		// Schaltet die Ports mit PWM, DUTY ist Pulsverhältnis
                           2908 ;	-----------------------------------------
                           2909 ;	 function port_schalten
                           2910 ;	-----------------------------------------
   0BDF                    2911 _port_schalten:
                    09D5   2912 	C$fb_app_rollo11.c$922$1$1 ==.
                           2913 ;	..\fb_app_rollo11.c:922: portbuffer=0;
   0BDF 75 0D 00           2914 	mov	_portbuffer,#0x00
                    09D8   2915 	C$fb_app_rollo11.c$923$1$1 ==.
                           2916 ;	..\fb_app_rollo11.c:923: if (eeprom[0xE4]& 0x80) kmod=0x01;		// bit 7 ist Kanal-mode
   0BE2 90 1D E4           2917 	mov	dptr,#(_eeprom + 0x00e4)
   0BE5 E4                 2918 	clr	a
   0BE6 93                 2919 	movc	a,@a+dptr
   0BE7 FF                 2920 	mov	r7,a
   0BE8 30 E7 04           2921 	jnb	acc.7,00102$
   0BEB 7F 01              2922 	mov	r7,#0x01
   0BED 80 02              2923 	sjmp	00103$
   0BEF                    2924 00102$:
                    09E5   2925 	C$fb_app_rollo11.c$924$1$1 ==.
                           2926 ;	..\fb_app_rollo11.c:924: else kmod=0x03;
   0BEF 7F 03              2927 	mov	r7,#0x03
   0BF1                    2928 00103$:
                    09E7   2929 	C$fb_app_rollo11.c$925$1$1 ==.
                           2930 ;	..\fb_app_rollo11.c:925: for (knr=0;knr<=0x03;knr++){
   0BF1 75 4B 00           2931 	mov	_knr,#0x00
   0BF4                    2932 00107$:
   0BF4 E5 4B              2933 	mov	a,_knr
   0BF6 24 FC              2934 	add	a,#0xff - 0x03
   0BF8 40 23              2935 	jc	00110$
                    09F0   2936 	C$fb_app_rollo11.c$926$2$2 ==.
                           2937 ;	..\fb_app_rollo11.c:926: portbuffer=portbuffer|((kanal[knr & kmod]& 0x03)<<(knr<<1));
   0BFA EF                 2938 	mov	a,r7
   0BFB 55 4B              2939 	anl	a,_knr
   0BFD 24 47              2940 	add	a,#_kanal
   0BFF F9                 2941 	mov	r1,a
   0C00 87 06              2942 	mov	ar6,@r1
   0C02 53 06 03           2943 	anl	ar6,#0x03
   0C05 E5 4B              2944 	mov	a,_knr
   0C07 25 4B              2945 	add	a,_knr
   0C09 FD                 2946 	mov	r5,a
   0C0A 8D F0              2947 	mov	b,r5
   0C0C 05 F0              2948 	inc	b
   0C0E EE                 2949 	mov	a,r6
   0C0F 80 02              2950 	sjmp	00121$
   0C11                    2951 00119$:
   0C11 25 E0              2952 	add	a,acc
   0C13                    2953 00121$:
   0C13 D5 F0 FB           2954 	djnz	b,00119$
   0C16 FE                 2955 	mov	r6,a
   0C17 42 0D              2956 	orl	_portbuffer,a
                    0A0F   2957 	C$fb_app_rollo11.c$925$1$1 ==.
                           2958 ;	..\fb_app_rollo11.c:925: for (knr=0;knr<=0x03;knr++){
   0C19 05 4B              2959 	inc	_knr
   0C1B 80 D7              2960 	sjmp	00107$
   0C1D                    2961 00110$:
                    0A13   2962 	C$fb_app_rollo11.c$991$1$1 ==.
                           2963 ;	..\fb_app_rollo11.c:991: if(portbuffer & ~oldportbuffer) {	// Vollstrom nur wenn ein relais eingeschaltet wird
   0C1D AE 0E              2964 	mov	r6,_oldportbuffer
   0C1F 7F 00              2965 	mov	r7,#0x00
   0C21 EE                 2966 	mov	a,r6
   0C22 F4                 2967 	cpl	a
   0C23 FE                 2968 	mov	r6,a
   0C24 EF                 2969 	mov	a,r7
   0C25 F4                 2970 	cpl	a
   0C26 FF                 2971 	mov	r7,a
   0C27 AC 0D              2972 	mov	r4,_portbuffer
   0C29 7D 00              2973 	mov	r5,#0x00
   0C2B EC                 2974 	mov	a,r4
   0C2C 52 06              2975 	anl	ar6,a
   0C2E ED                 2976 	mov	a,r5
   0C2F 52 07              2977 	anl	ar7,a
   0C31 EE                 2978 	mov	a,r6
   0C32 4F                 2979 	orl	a,r7
   0C33 60 1F              2980 	jz	00105$
                    0A2B   2981 	C$fb_app_rollo11.c$992$2$3 ==.
                           2982 ;	..\fb_app_rollo11.c:992: TR0=0;
   0C35 C2 8C              2983 	clr	_TCON_4
                    0A2D   2984 	C$fb_app_rollo11.c$993$2$3 ==.
                           2985 ;	..\fb_app_rollo11.c:993: AUXR1&=0xE9;	// PWM von Timer 0 nicht mehr auf Pin ausgeben
   0C37 53 A2 E9           2986 	anl	_AUXR1,#0xE9
                    0A30   2987 	C$fb_app_rollo11.c$996$2$3 ==.
                           2988 ;	..\fb_app_rollo11.c:996: PWM=0;			// Vollstrom an
   0C3A C2 92              2989 	clr	_P1_2
                    0A32   2990 	C$fb_app_rollo11.c$998$2$3 ==.
                           2991 ;	..\fb_app_rollo11.c:998: P0=portbuffer;		// Ports schalten
   0C3C 85 0D 80           2992 	mov	_P0,_portbuffer
                    0A35   2993 	C$fb_app_rollo11.c$999$2$3 ==.
                           2994 ;	..\fb_app_rollo11.c:999: TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
   0C3F C2 8D              2995 	clr	_TCON_5
                    0A37   2996 	C$fb_app_rollo11.c$1000$2$3 ==.
                           2997 ;	..\fb_app_rollo11.c:1000: TH0=0x00;		// 16ms (10ms=6fff)
                    0A37   2998 	C$fb_app_rollo11.c$1001$2$3 ==.
                           2999 ;	..\fb_app_rollo11.c:1001: TL0=0x00;
                    0A37   3000 	C$fb_app_rollo11.c$1002$2$3 ==.
                           3001 ;	..\fb_app_rollo11.c:1002: TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
   0C41 E4                 3002 	clr	a
   0C42 F5 8C              3003 	mov	_TH0,a
   0C44 F5 8A              3004 	mov	_TL0,a
   0C46 74 F0              3005 	mov	a,#0xF0
   0C48 55 89              3006 	anl	a,_TMOD
   0C4A 04                 3007 	inc	a
   0C4B F5 89              3008 	mov	_TMOD,a
                    0A43   3009 	C$fb_app_rollo11.c$1003$2$3 ==.
                           3010 ;	..\fb_app_rollo11.c:1003: TAMOD=0x00;
   0C4D 75 8F 00           3011 	mov	_TAMOD,#0x00
                    0A46   3012 	C$fb_app_rollo11.c$1004$2$3 ==.
                           3013 ;	..\fb_app_rollo11.c:1004: TR0=1;
   0C50 D2 8C              3014 	setb	_TCON_4
   0C52 80 03              3015 	sjmp	00106$
   0C54                    3016 00105$:
                    0A4A   3017 	C$fb_app_rollo11.c$1006$1$1 ==.
                           3018 ;	..\fb_app_rollo11.c:1006: else P0=portbuffer;
   0C54 85 0D 80           3019 	mov	_P0,_portbuffer
   0C57                    3020 00106$:
                    0A4D   3021 	C$fb_app_rollo11.c$1009$1$1 ==.
                           3022 ;	..\fb_app_rollo11.c:1009: oldportbuffer=portbuffer;
   0C57 85 0D 0E           3023 	mov	_oldportbuffer,_portbuffer
                    0A50   3024 	C$fb_app_rollo11.c$1010$1$1 ==.
                           3025 ;	..\fb_app_rollo11.c:1010: portchanged=0;
   0C5A C2 00              3026 	clr	_portchanged
                    0A52   3027 	C$fb_app_rollo11.c$1014$1$1 ==.
                    0A52   3028 	XG$port_schalten$0$0 ==.
   0C5C 22                 3029 	ret
                           3030 ;------------------------------------------------------------
                           3031 ;Allocation info for local variables in function 'bus_return'
                           3032 ;------------------------------------------------------------
                           3033 ;n                         Allocated to registers r7 
                           3034 ;------------------------------------------------------------
                    0A53   3035 	G$bus_return$0$0 ==.
                    0A53   3036 	C$fb_app_rollo11.c$1136$1$1 ==.
                           3037 ;	..\fb_app_rollo11.c:1136: void bus_return(void)		// Aktionen bei Busspannungswiederkehr
                           3038 ;	-----------------------------------------
                           3039 ;	 function bus_return
                           3040 ;	-----------------------------------------
   0C5D                    3041 _bus_return:
                    0A53   3042 	C$fb_app_rollo11.c$1139$1$1 ==.
                           3043 ;	..\fb_app_rollo11.c:1139: blocked=blockedsave;		// Ausgänge gesperrt?
   0C5D 90 1B FD           3044 	mov	dptr,#_blockedsave
   0C60 E4                 3045 	clr	a
   0C61 93                 3046 	movc	a,@a+dptr
   0C62 F5 0F              3047 	mov	_blocked,a
                    0A5A   3048 	C$fb_app_rollo11.c$1140$1$1 ==.
                           3049 ;	..\fb_app_rollo11.c:1140: timer=0;			// Timer-Variable, wird alle 8 ms inkrementiert
                    0A5A   3050 	C$fb_app_rollo11.c$1141$2$2 ==.
                           3051 ;	..\fb_app_rollo11.c:1141: for (n=0;n<=15;n++){// Löschen aller zeiten
   0C64 E4                 3052 	clr	a
   0C65 F5 09              3053 	mov	_timer,a
   0C67 F5 0A              3054 	mov	(_timer + 1),a
   0C69 FF                 3055 	mov	r7,a
   0C6A                    3056 00107$:
   0C6A EF                 3057 	mov	a,r7
   0C6B 24 F0              3058 	add	a,#0xff - 0x0F
   0C6D 40 15              3059 	jc	00110$
                    0A65   3060 	C$fb_app_rollo11.c$1142$2$2 ==.
                           3061 ;	..\fb_app_rollo11.c:1142: timerstate[n]=0;
   0C6F EF                 3062 	mov	a,r7
   0C70 24 34              3063 	add	a,#_timerstate
   0C72 F8                 3064 	mov	r0,a
   0C73 76 00              3065 	mov	@r0,#0x00
                    0A6B   3066 	C$fb_app_rollo11.c$1143$2$2 ==.
                           3067 ;	..\fb_app_rollo11.c:1143: timerbase[n]=0;
   0C75 EF                 3068 	mov	a,r7
   0C76 24 10              3069 	add	a,#_timerbase
   0C78 F8                 3070 	mov	r0,a
   0C79 76 00              3071 	mov	@r0,#0x00
                    0A71   3072 	C$fb_app_rollo11.c$1144$2$2 ==.
                           3073 ;	..\fb_app_rollo11.c:1144: timercnt[n]=0;
   0C7B EF                 3074 	mov	a,r7
   0C7C 24 24              3075 	add	a,#_timercnt
   0C7E F8                 3076 	mov	r0,a
   0C7F 76 00              3077 	mov	@r0,#0x00
                    0A77   3078 	C$fb_app_rollo11.c$1141$1$1 ==.
                           3079 ;	..\fb_app_rollo11.c:1141: for (n=0;n<=15;n++){// Löschen aller zeiten
   0C81 0F                 3080 	inc	r7
   0C82 80 E6              3081 	sjmp	00107$
   0C84                    3082 00110$:
                    0A7A   3083 	C$fb_app_rollo11.c$1146$1$1 ==.
                           3084 ;	..\fb_app_rollo11.c:1146: for (n=0;n<=3;n++){
   0C84 7F 00              3085 	mov	r7,#0x00
   0C86                    3086 00111$:
   0C86 EF                 3087 	mov	a,r7
   0C87 24 FC              3088 	add	a,#0xff - 0x03
   0C89 40 63              3089 	jc	00114$
                    0A81   3090 	C$fb_app_rollo11.c$1147$2$3 ==.
                           3091 ;	..\fb_app_rollo11.c:1147: if(((eeprom[0xF1]>>n)&0x11)==0 ){// wenn keine Sperrfunktion zugewiesen
   0C8B 90 1D F1           3092 	mov	dptr,#(_eeprom + 0x00f1)
   0C8E E4                 3093 	clr	a
   0C8F 93                 3094 	movc	a,@a+dptr
   0C90 FE                 3095 	mov	r6,a
   0C91 8F F0              3096 	mov	b,r7
   0C93 05 F0              3097 	inc	b
   0C95 EE                 3098 	mov	a,r6
   0C96 80 02              3099 	sjmp	00129$
   0C98                    3100 00128$:
   0C98 C3                 3101 	clr	c
   0C99 13                 3102 	rrc	a
   0C9A                    3103 00129$:
   0C9A D5 F0 FB           3104 	djnz	b,00128$
   0C9D 54 11              3105 	anl	a,#0x11
   0C9F 60 02              3106 	jz	00131$
   0CA1 80 11              3107 	sjmp	00102$
   0CA3                    3108 00131$:
                    0A99   3109 	C$fb_app_rollo11.c$1148$3$4 ==.
                           3110 ;	..\fb_app_rollo11.c:1148: blocked &= ~(0x11<<n);  // dann blocked löschen, damit nach umpara
   0CA3 8F F0              3111 	mov	b,r7
   0CA5 05 F0              3112 	inc	b
   0CA7 74 11              3113 	mov	a,#0x11
   0CA9 80 02              3114 	sjmp	00134$
   0CAB                    3115 00132$:
   0CAB 25 E0              3116 	add	a,acc
   0CAD                    3117 00134$:
   0CAD D5 F0 FB           3118 	djnz	b,00132$
   0CB0 F4                 3119 	cpl	a
   0CB1 FE                 3120 	mov	r6,a
   0CB2 52 0F              3121 	anl	_blocked,a
   0CB4                    3122 00102$:
                    0AAA   3123 	C$fb_app_rollo11.c$1150$2$3 ==.
                           3124 ;	..\fb_app_rollo11.c:1150: switch(eeprom[0xD9]& 0xC0){
   0CB4 90 1D D9           3125 	mov	dptr,#(_eeprom + 0x00d9)
   0CB7 E4                 3126 	clr	a
   0CB8 93                 3127 	movc	a,@a+dptr
   0CB9 FE                 3128 	mov	r6,a
   0CBA 53 06 C0           3129 	anl	ar6,#0xC0
   0CBD BE 40 02           3130 	cjne	r6,#0x40,00135$
   0CC0 80 05              3131 	sjmp	00103$
   0CC2                    3132 00135$:
                    0AB8   3133 	C$fb_app_rollo11.c$1151$3$5 ==.
                           3134 ;	..\fb_app_rollo11.c:1151: case 0x40:
   0CC2 BE 80 26           3135 	cjne	r6,#0x80,00113$
   0CC5 80 13              3136 	sjmp	00104$
   0CC7                    3137 00103$:
                    0ABD   3138 	C$fb_app_rollo11.c$1152$3$5 ==.
                           3139 ;	..\fb_app_rollo11.c:1152: object_schalten(n+12,0);
   0CC7 74 0C              3140 	mov	a,#0x0C
   0CC9 2F                 3141 	add	a,r7
   0CCA F5 82              3142 	mov	dpl,a
   0CCC C2 F0              3143 	clr	b[0]
   0CCE C0 07              3144 	push	ar7
   0CD0 85 F0 23           3145 	mov	bits,b
   0CD3 12 04 95           3146 	lcall	_object_schalten
   0CD6 D0 07              3147 	pop	ar7
                    0ACE   3148 	C$fb_app_rollo11.c$1153$3$5 ==.
                           3149 ;	..\fb_app_rollo11.c:1153: break;
                    0ACE   3150 	C$fb_app_rollo11.c$1154$3$5 ==.
                           3151 ;	..\fb_app_rollo11.c:1154: case 0x80:
   0CD8 80 11              3152 	sjmp	00113$
   0CDA                    3153 00104$:
                    0AD0   3154 	C$fb_app_rollo11.c$1155$3$5 ==.
                           3155 ;	..\fb_app_rollo11.c:1155: object_schalten(n+12,1);
   0CDA 74 0C              3156 	mov	a,#0x0C
   0CDC 2F                 3157 	add	a,r7
   0CDD F5 82              3158 	mov	dpl,a
   0CDF D2 F0              3159 	setb	b[0]
   0CE1 C0 07              3160 	push	ar7
   0CE3 85 F0 23           3161 	mov	bits,b
   0CE6 12 04 95           3162 	lcall	_object_schalten
   0CE9 D0 07              3163 	pop	ar7
                    0AE1   3164 	C$fb_app_rollo11.c$1158$2$3 ==.
                           3165 ;	..\fb_app_rollo11.c:1158: }
   0CEB                    3166 00113$:
                    0AE1   3167 	C$fb_app_rollo11.c$1146$1$1 ==.
                           3168 ;	..\fb_app_rollo11.c:1146: for (n=0;n<=3;n++){
   0CEB 0F                 3169 	inc	r7
   0CEC 80 98              3170 	sjmp	00111$
   0CEE                    3171 00114$:
                    0AE4   3172 	C$fb_app_rollo11.c$1162$1$1 ==.
                           3173 ;	..\fb_app_rollo11.c:1162: oldportbuffer=0; 	// auf 0 setzen, da sonst kein Vollstrom aktiviert wird
   0CEE 75 0E 00           3174 	mov	_oldportbuffer,#0x00
                    0AE7   3175 	C$fb_app_rollo11.c$1163$1$1 ==.
                           3176 ;	..\fb_app_rollo11.c:1163: portchanged=1;		// Post hinterlegen damit in delaytimer nach portschalten springt
   0CF1 D2 00              3177 	setb	_portchanged
                    0AE9   3178 	C$fb_app_rollo11.c$1165$1$1 ==.
                           3179 ;	..\fb_app_rollo11.c:1165: set_entriegeln(9);	// Überwachungszeit Sicherheitsfahrt
   0CF3 75 82 09           3180 	mov	dpl,#0x09
   0CF6 12 0B AD           3181 	lcall	_set_entriegeln
                    0AEF   3182 	C$fb_app_rollo11.c$1166$1$1 ==.
                           3183 ;	..\fb_app_rollo11.c:1166: set_entriegeln(10);	// dto
   0CF9 75 82 0A           3184 	mov	dpl,#0x0A
   0CFC 12 0B AD           3185 	lcall	_set_entriegeln
                    0AF5   3186 	C$fb_app_rollo11.c$1169$1$1 ==.
                    0AF5   3187 	XG$bus_return$0$0 ==.
   0CFF 22                 3188 	ret
                           3189 ;------------------------------------------------------------
                           3190 ;Allocation info for local variables in function 'restart_app'
                           3191 ;------------------------------------------------------------
                    0AF6   3192 	G$restart_app$0$0 ==.
                    0AF6   3193 	C$fb_app_rollo11.c$1171$1$1 ==.
                           3194 ;	..\fb_app_rollo11.c:1171: void restart_app(void) 		// Alle Applikations-Parameter zurücksetzen
                           3195 ;	-----------------------------------------
                           3196 ;	 function restart_app
                           3197 ;	-----------------------------------------
   0D00                    3198 _restart_app:
                    0AF6   3199 	C$fb_app_rollo11.c$1174$1$1 ==.
                           3200 ;	..\fb_app_rollo11.c:1174: Tval=0x00;
   0D00 75 44 00           3201 	mov	_Tval,#0x00
                    0AF9   3202 	C$fb_app_rollo11.c$1175$1$1 ==.
                           3203 ;	..\fb_app_rollo11.c:1175: handmode=0;
   0D03 C2 02              3204 	clr	_handmode
                    0AFB   3205 	C$fb_app_rollo11.c$1177$1$1 ==.
                           3206 ;	..\fb_app_rollo11.c:1177: P0=0;
   0D05 75 80 00           3207 	mov	_P0,#0x00
                    0AFE   3208 	C$fb_app_rollo11.c$1178$1$1 ==.
                           3209 ;	..\fb_app_rollo11.c:1178: P0M1=0x00;		// Port 0 Modus push-pull für Ausgang
   0D08 75 84 00           3210 	mov	_P0M1,#0x00
                    0B01   3211 	C$fb_app_rollo11.c$1183$1$1 ==.
                           3212 ;	..\fb_app_rollo11.c:1183: P0M2=0x0F;
   0D0B 75 85 0F           3213 	mov	_P0M2,#0x0F
                    0B04   3214 	C$fb_app_rollo11.c$1189$1$1 ==.
                           3215 ;	..\fb_app_rollo11.c:1189: TMOD=(TMOD & 0xF0) + 2;		// Timer 0 als PWM
   0D0E 74 F0              3216 	mov	a,#0xF0
   0D10 55 89              3217 	anl	a,_TMOD
   0D12 24 02              3218 	add	a,#0x02
   0D14 F5 89              3219 	mov	_TMOD,a
                    0B0C   3220 	C$fb_app_rollo11.c$1190$1$1 ==.
                           3221 ;	..\fb_app_rollo11.c:1190: TAMOD=0x01;
   0D16 75 8F 01           3222 	mov	_TAMOD,#0x01
                    0B0F   3223 	C$fb_app_rollo11.c$1191$1$1 ==.
                           3224 ;	..\fb_app_rollo11.c:1191: TH0=DUTY;		// Pulsverhältnis PWM
   0D19 75 8C 50           3225 	mov	_TH0,#0x50
                    0B12   3226 	C$fb_app_rollo11.c$1192$1$1 ==.
                           3227 ;	..\fb_app_rollo11.c:1192: AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
   0D1C 43 A2 10           3228 	orl	_AUXR1,#0x10
                    0B15   3229 	C$fb_app_rollo11.c$1193$1$1 ==.
                           3230 ;	..\fb_app_rollo11.c:1193: TR0=1;			// Timer 0 starten (PWM)
   0D1F D2 8C              3231 	setb	_TCON_4
                    0B17   3232 	C$fb_app_rollo11.c$1198$1$1 ==.
                           3233 ;	..\fb_app_rollo11.c:1198: ET0=0;			// Interrupt für Timer 0 sperren
   0D21 C2 A9              3234 	clr	_IEN0_1
                    0B19   3235 	C$fb_app_rollo11.c$1199$1$1 ==.
                           3236 ;	..\fb_app_rollo11.c:1199: IT0=1;
   0D23 D2 88              3237 	setb	_TCON_0
                    0B1B   3238 	C$fb_app_rollo11.c$1200$1$1 ==.
                           3239 ;	..\fb_app_rollo11.c:1200: blocked=0x00;		// Ausgänge nicht gesperrt
                    0B1B   3240 	C$fb_app_rollo11.c$1201$1$1 ==.
                           3241 ;	..\fb_app_rollo11.c:1201: timer=0;			// Timer-Variable, wird alle 8ms inkrementiert
                    0B1B   3242 	C$fb_app_rollo11.c$1204$1$1 ==.
                           3243 ;	..\fb_app_rollo11.c:1204: delay_toggle=0;
   0D25 E4                 3244 	clr	a
   0D26 F5 0F              3245 	mov	_blocked,a
   0D28 F5 09              3246 	mov	_timer,a
   0D2A F5 0A              3247 	mov	(_timer + 1),a
   0D2C F5 09              3248 	mov	_delay_toggle,a
                    0B24   3249 	C$fb_app_rollo11.c$1206$1$1 ==.
                           3250 ;	..\fb_app_rollo11.c:1206: EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
   0D2E C2 AF              3251 	clr	_IEN0_7
                    0B26   3252 	C$fb_app_rollo11.c$1207$1$1 ==.
                           3253 ;	..\fb_app_rollo11.c:1207: START_WRITECYCLE
   0D30 75 E4 00           3254 	mov	_FMCON,#0x00
                    0B29   3255 	C$fb_app_rollo11.c$1208$1$1 ==.
                           3256 ;	..\fb_app_rollo11.c:1208: WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
   0D33 75 E7 1D           3257 	mov	_FMADRH,#0x1D
   0D36 75 E6 03           3258 	mov	_FMADRL,#0x03
   0D39 75 E5 00           3259 	mov	_FMDATA,#0x00
                    0B32   3260 	C$fb_app_rollo11.c$1209$1$1 ==.
                           3261 ;	..\fb_app_rollo11.c:1209: WRITE_BYTE(0x01,0x04,0x04)
   0D3C 75 E7 1D           3262 	mov	_FMADRH,#0x1D
   0D3F 75 E6 04           3263 	mov	_FMADRL,#0x04
   0D42 75 E5 04           3264 	mov	_FMDATA,#0x04
                    0B3B   3265 	C$fb_app_rollo11.c$1213$1$1 ==.
                           3266 ;	..\fb_app_rollo11.c:1213: WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
   0D45 75 E7 1D           3267 	mov	_FMADRH,#0x1D
   0D48 75 E6 0C           3268 	mov	_FMADRL,#0x0C
   0D4B 75 E5 00           3269 	mov	_FMDATA,#0x00
                    0B44   3270 	C$fb_app_rollo11.c$1214$1$1 ==.
                           3271 ;	..\fb_app_rollo11.c:1214: WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
   0D4E 75 E7 1D           3272 	mov	_FMADRH,#0x1D
   0D51 75 E6 0D           3273 	mov	_FMADRL,#0x0D
   0D54 75 E5 FF           3274 	mov	_FMDATA,#0xFF
                    0B4D   3275 	C$fb_app_rollo11.c$1216$1$1 ==.
                           3276 ;	..\fb_app_rollo11.c:1216: STOP_WRITECYCLE
   0D57 75 E4 68           3277 	mov	_FMCON,#0x68
                    0B50   3278 	C$fb_app_rollo11.c$1217$1$1 ==.
                           3279 ;	..\fb_app_rollo11.c:1217: EA=1;						// Interrupts freigeben
   0D5A D2 AF              3280 	setb	_IEN0_7
                    0B52   3281 	C$fb_app_rollo11.c$1219$1$1 ==.
                           3282 ;	..\fb_app_rollo11.c:1219: RTCCON=0x60;		// RTC Flag löschen
   0D5C 75 D1 60           3283 	mov	_RTCCON,#0x60
                    0B55   3284 	C$fb_app_rollo11.c$1220$1$1 ==.
                           3285 ;	..\fb_app_rollo11.c:1220: RTCH=0x01;			// reload Real Time Clock
   0D5F 75 D2 01           3286 	mov	_RTCH,#0x01
                    0B58   3287 	C$fb_app_rollo11.c$1221$1$1 ==.
                           3288 ;	..\fb_app_rollo11.c:1221: RTCL=0xCD;			// 8ms
   0D62 75 D3 CD           3289 	mov	_RTCL,#0xCD
                    0B5B   3290 	C$fb_app_rollo11.c$1222$1$1 ==.
                           3291 ;	..\fb_app_rollo11.c:1222: RTCCON=0x61;
   0D65 75 D1 61           3292 	mov	_RTCCON,#0x61
                    0B5E   3293 	C$fb_app_rollo11.c$1223$1$1 ==.
                    0B5E   3294 	XG$restart_app$0$0 ==.
   0D68 22                 3295 	ret
                           3296 	.area CSEG    (CODE)
                           3297 	.area CONST   (CODE)
                    1BFD   3298 Ffb_app_rollo11$blockedsave$0$0 == 0x1bfd
                    1BFD   3299 _blockedsave	=	0x1bfd
                    0000   3300 G$timerflagmask$0$0 == .
   178A                    3301 _timerflagmask:
   178A 00 00              3302 	.byte #0x00,#0x00	; 0
   178C 00 00              3303 	.byte #0x00,#0x00	; 0
   178E 00 00              3304 	.byte #0x00,#0x00	; 0
   1790 08 00              3305 	.byte #0x08,#0x00	; 8
   1792 80 00              3306 	.byte #0x80,#0x00	; 128
   1794 00 08              3307 	.byte #0x00,#0x08	; 2048
                    000C   3308 G$svfaktorarray$0$0 == .
   1796                    3309 _svfaktorarray:
   1796 00                 3310 	.db #0x00	; 0
   1797 02                 3311 	.db #0x02	; 2
   1798 04                 3312 	.db #0x04	; 4
   1799 06                 3313 	.db #0x06	; 6
   179A 08                 3314 	.db #0x08	; 8
   179B 0A                 3315 	.db #0x0A	; 10
   179C 0C                 3316 	.db #0x0C	; 12
   179D 0E                 3317 	.db #0x0E	; 14
   179E 10                 3318 	.db #0x10	; 16
   179F 12                 3319 	.db #0x12	; 18
   17A0 14                 3320 	.db #0x14	; 20
   17A1 16                 3321 	.db #0x16	; 22
   17A2 24                 3322 	.db #0x24	; 36
   17A3 48                 3323 	.db #0x48	; 72	'H'
   17A4 6D                 3324 	.db #0x6D	; 109	'm'
   17A5 DA                 3325 	.db #0xDA	; 218
                           3326 	.area XINIT   (CODE)
                           3327 	.area CABS    (ABS,CODE)
