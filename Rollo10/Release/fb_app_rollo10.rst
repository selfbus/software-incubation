                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Mon Nov 19 19:58:42 2012
                              5 ;--------------------------------------------------------
                              6 	.module fb_app_rollo10
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _svfaktorarray
                             13 	.globl _timerflagmask
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
                            153 	.globl _handmode
                            154 	.globl _state
                            155 	.globl _portchanged
                            156 	.globl _ledport
                            157 	.globl _knr
                            158 	.globl _kanal
                            159 	.globl _oldblockvalue
                            160 	.globl _zfstate
                            161 	.globl _blocked
                            162 	.globl _oldportbuffer
                            163 	.globl _portbuffer
                            164 	.globl _objects_smove
                            165 	.globl _objects_move
                            166 	.globl _Tval
                            167 	.globl _delay_toggle
                            168 	.globl _timer
                            169 	.globl _timerstate
                            170 	.globl _timercnt
                            171 	.globl _timerbase
                            172 	.globl _RAM
                            173 	.globl _write_value_req
                            174 	.globl _read_value_req
                            175 	.globl _read_obj_value
                            176 	.globl _write_obj_value
                            177 	.globl _Sobject_schalten
                            178 	.globl _object_schalten
                            179 	.globl _delay_timer
                            180 	.globl _handsteuerung
                            181 	.globl _sobj_update
                            182 	.globl _set_pause
                            183 	.globl _set_entriegeln
                            184 	.globl _port_schalten
                            185 	.globl _bus_return
                            186 	.globl _restart_app
                            187 ;--------------------------------------------------------
                            188 ; special function registers
                            189 ;--------------------------------------------------------
                            190 	.area RSEG    (ABS,DATA)
   0000                     191 	.org 0x0000
                    0080    192 G$P0$0$0 == 0x0080
                    0080    193 _P0	=	0x0080
                    0090    194 G$P1$0$0 == 0x0090
                    0090    195 _P1	=	0x0090
                    00B0    196 G$P3$0$0 == 0x00b0
                    00B0    197 _P3	=	0x00b0
                    00D0    198 G$PSW$0$0 == 0x00d0
                    00D0    199 _PSW	=	0x00d0
                    00E0    200 G$ACC$0$0 == 0x00e0
                    00E0    201 _ACC	=	0x00e0
                    00F0    202 G$B$0$0 == 0x00f0
                    00F0    203 _B	=	0x00f0
                    0081    204 G$SP$0$0 == 0x0081
                    0081    205 _SP	=	0x0081
                    0082    206 G$DPL$0$0 == 0x0082
                    0082    207 _DPL	=	0x0082
                    0083    208 G$DPH$0$0 == 0x0083
                    0083    209 _DPH	=	0x0083
                    0087    210 G$PCON$0$0 == 0x0087
                    0087    211 _PCON	=	0x0087
                    0088    212 G$TCON$0$0 == 0x0088
                    0088    213 _TCON	=	0x0088
                    0089    214 G$TMOD$0$0 == 0x0089
                    0089    215 _TMOD	=	0x0089
                    008A    216 G$TL0$0$0 == 0x008a
                    008A    217 _TL0	=	0x008a
                    008B    218 G$TL1$0$0 == 0x008b
                    008B    219 _TL1	=	0x008b
                    008C    220 G$TH0$0$0 == 0x008c
                    008C    221 _TH0	=	0x008c
                    008D    222 G$TH1$0$0 == 0x008d
                    008D    223 _TH1	=	0x008d
                    00A8    224 G$IEN0$0$0 == 0x00a8
                    00A8    225 _IEN0	=	0x00a8
                    00B8    226 G$IP0$0$0 == 0x00b8
                    00B8    227 _IP0	=	0x00b8
                    0098    228 G$SCON$0$0 == 0x0098
                    0098    229 _SCON	=	0x0098
                    0099    230 G$SBUF$0$0 == 0x0099
                    0099    231 _SBUF	=	0x0099
                    00A2    232 G$AUXR1$0$0 == 0x00a2
                    00A2    233 _AUXR1	=	0x00a2
                    00A9    234 G$SADDR$0$0 == 0x00a9
                    00A9    235 _SADDR	=	0x00a9
                    00B9    236 G$SADEN$0$0 == 0x00b9
                    00B9    237 _SADEN	=	0x00b9
                    00BE    238 G$BRGR0$0$0 == 0x00be
                    00BE    239 _BRGR0	=	0x00be
                    00BF    240 G$BRGR1$0$0 == 0x00bf
                    00BF    241 _BRGR1	=	0x00bf
                    00BD    242 G$BRGCON$0$0 == 0x00bd
                    00BD    243 _BRGCON	=	0x00bd
                    00AC    244 G$CMP1$0$0 == 0x00ac
                    00AC    245 _CMP1	=	0x00ac
                    00AD    246 G$CMP2$0$0 == 0x00ad
                    00AD    247 _CMP2	=	0x00ad
                    0095    248 G$DIVM$0$0 == 0x0095
                    0095    249 _DIVM	=	0x0095
                    00E7    250 G$FMADRH$0$0 == 0x00e7
                    00E7    251 _FMADRH	=	0x00e7
                    00E6    252 G$FMADRL$0$0 == 0x00e6
                    00E6    253 _FMADRL	=	0x00e6
                    00E4    254 G$FMCON$0$0 == 0x00e4
                    00E4    255 _FMCON	=	0x00e4
                    00E5    256 G$FMDATA$0$0 == 0x00e5
                    00E5    257 _FMDATA	=	0x00e5
                    00DB    258 G$I2ADR$0$0 == 0x00db
                    00DB    259 _I2ADR	=	0x00db
                    00D8    260 G$I2CON$0$0 == 0x00d8
                    00D8    261 _I2CON	=	0x00d8
                    00DA    262 G$I2DAT$0$0 == 0x00da
                    00DA    263 _I2DAT	=	0x00da
                    00DD    264 G$I2SCLH$0$0 == 0x00dd
                    00DD    265 _I2SCLH	=	0x00dd
                    00DC    266 G$I2SCLL$0$0 == 0x00dc
                    00DC    267 _I2SCLL	=	0x00dc
                    00D9    268 G$I2STAT$0$0 == 0x00d9
                    00D9    269 _I2STAT	=	0x00d9
                    00F8    270 G$IP1$0$0 == 0x00f8
                    00F8    271 _IP1	=	0x00f8
                    00F7    272 G$IP1H$0$0 == 0x00f7
                    00F7    273 _IP1H	=	0x00f7
                    0094    274 G$KBCON$0$0 == 0x0094
                    0094    275 _KBCON	=	0x0094
                    0086    276 G$KBMASK$0$0 == 0x0086
                    0086    277 _KBMASK	=	0x0086
                    0093    278 G$KBPATN$0$0 == 0x0093
                    0093    279 _KBPATN	=	0x0093
                    0084    280 G$P0M1$0$0 == 0x0084
                    0084    281 _P0M1	=	0x0084
                    0085    282 G$P0M2$0$0 == 0x0085
                    0085    283 _P0M2	=	0x0085
                    0091    284 G$P1M1$0$0 == 0x0091
                    0091    285 _P1M1	=	0x0091
                    0092    286 G$P1M2$0$0 == 0x0092
                    0092    287 _P1M2	=	0x0092
                    00B1    288 G$P3M1$0$0 == 0x00b1
                    00B1    289 _P3M1	=	0x00b1
                    00B2    290 G$P3M2$0$0 == 0x00b2
                    00B2    291 _P3M2	=	0x00b2
                    00B5    292 G$PCONA$0$0 == 0x00b5
                    00B5    293 _PCONA	=	0x00b5
                    00F6    294 G$PT0AD$0$0 == 0x00f6
                    00F6    295 _PT0AD	=	0x00f6
                    00DF    296 G$RSTSRC$0$0 == 0x00df
                    00DF    297 _RSTSRC	=	0x00df
                    00D1    298 G$RTCCON$0$0 == 0x00d1
                    00D1    299 _RTCCON	=	0x00d1
                    00D2    300 G$RTCH$0$0 == 0x00d2
                    00D2    301 _RTCH	=	0x00d2
                    00D3    302 G$RTCL$0$0 == 0x00d3
                    00D3    303 _RTCL	=	0x00d3
                    00BA    304 G$SSTAT$0$0 == 0x00ba
                    00BA    305 _SSTAT	=	0x00ba
                    008F    306 G$TAMOD$0$0 == 0x008f
                    008F    307 _TAMOD	=	0x008f
                    0096    308 G$TRIM$0$0 == 0x0096
                    0096    309 _TRIM	=	0x0096
                    00A7    310 G$WDCON$0$0 == 0x00a7
                    00A7    311 _WDCON	=	0x00a7
                    00C1    312 G$WDL$0$0 == 0x00c1
                    00C1    313 _WDL	=	0x00c1
                    00C2    314 G$WFEED1$0$0 == 0x00c2
                    00C2    315 _WFEED1	=	0x00c2
                    00C3    316 G$WFEED2$0$0 == 0x00c3
                    00C3    317 _WFEED2	=	0x00c3
                    00B7    318 G$IP0H$0$0 == 0x00b7
                    00B7    319 _IP0H	=	0x00b7
                    00E8    320 G$IEN1$0$0 == 0x00e8
                    00E8    321 _IEN1	=	0x00e8
                            322 ;--------------------------------------------------------
                            323 ; special function bits
                            324 ;--------------------------------------------------------
                            325 	.area RSEG    (ABS,DATA)
   0000                     326 	.org 0x0000
                    00D0    327 G$PSW_0$0$0 == 0x00d0
                    00D0    328 _PSW_0	=	0x00d0
                    00D1    329 G$PSW_1$0$0 == 0x00d1
                    00D1    330 _PSW_1	=	0x00d1
                    00D2    331 G$PSW_2$0$0 == 0x00d2
                    00D2    332 _PSW_2	=	0x00d2
                    00D3    333 G$PSW_3$0$0 == 0x00d3
                    00D3    334 _PSW_3	=	0x00d3
                    00D4    335 G$PSW_4$0$0 == 0x00d4
                    00D4    336 _PSW_4	=	0x00d4
                    00D5    337 G$PSW_5$0$0 == 0x00d5
                    00D5    338 _PSW_5	=	0x00d5
                    00D6    339 G$PSW_6$0$0 == 0x00d6
                    00D6    340 _PSW_6	=	0x00d6
                    00D7    341 G$PSW_7$0$0 == 0x00d7
                    00D7    342 _PSW_7	=	0x00d7
                    008F    343 G$TCON_7$0$0 == 0x008f
                    008F    344 _TCON_7	=	0x008f
                    008E    345 G$TCON_6$0$0 == 0x008e
                    008E    346 _TCON_6	=	0x008e
                    008D    347 G$TCON_5$0$0 == 0x008d
                    008D    348 _TCON_5	=	0x008d
                    008C    349 G$TCON_4$0$0 == 0x008c
                    008C    350 _TCON_4	=	0x008c
                    008B    351 G$TCON_3$0$0 == 0x008b
                    008B    352 _TCON_3	=	0x008b
                    008A    353 G$TCON_2$0$0 == 0x008a
                    008A    354 _TCON_2	=	0x008a
                    0089    355 G$TCON_1$0$0 == 0x0089
                    0089    356 _TCON_1	=	0x0089
                    0088    357 G$TCON_0$0$0 == 0x0088
                    0088    358 _TCON_0	=	0x0088
                    00AF    359 G$IEN0_7$0$0 == 0x00af
                    00AF    360 _IEN0_7	=	0x00af
                    00AE    361 G$IEN0_6$0$0 == 0x00ae
                    00AE    362 _IEN0_6	=	0x00ae
                    00AD    363 G$IEN0_5$0$0 == 0x00ad
                    00AD    364 _IEN0_5	=	0x00ad
                    00AC    365 G$IEN0_4$0$0 == 0x00ac
                    00AC    366 _IEN0_4	=	0x00ac
                    00AB    367 G$IEN0_3$0$0 == 0x00ab
                    00AB    368 _IEN0_3	=	0x00ab
                    00AA    369 G$IEN0_2$0$0 == 0x00aa
                    00AA    370 _IEN0_2	=	0x00aa
                    00A9    371 G$IEN0_1$0$0 == 0x00a9
                    00A9    372 _IEN0_1	=	0x00a9
                    00A8    373 G$IEN0_0$0$0 == 0x00a8
                    00A8    374 _IEN0_0	=	0x00a8
                    00EA    375 G$IEN1_2$0$0 == 0x00ea
                    00EA    376 _IEN1_2	=	0x00ea
                    00E9    377 G$IEN1_1$0$0 == 0x00e9
                    00E9    378 _IEN1_1	=	0x00e9
                    00E8    379 G$IEN1_0$0$0 == 0x00e8
                    00E8    380 _IEN1_0	=	0x00e8
                    00FE    381 G$IP1_6$0$0 == 0x00fe
                    00FE    382 _IP1_6	=	0x00fe
                    00FA    383 G$IP1_2$0$0 == 0x00fa
                    00FA    384 _IP1_2	=	0x00fa
                    00F9    385 G$IP1_1$0$0 == 0x00f9
                    00F9    386 _IP1_1	=	0x00f9
                    00F8    387 G$IP1_0$0$0 == 0x00f8
                    00F8    388 _IP1_0	=	0x00f8
                    00BE    389 G$IP0_6$0$0 == 0x00be
                    00BE    390 _IP0_6	=	0x00be
                    00BD    391 G$IP0_5$0$0 == 0x00bd
                    00BD    392 _IP0_5	=	0x00bd
                    00BC    393 G$IP0_4$0$0 == 0x00bc
                    00BC    394 _IP0_4	=	0x00bc
                    00BB    395 G$IP0_3$0$0 == 0x00bb
                    00BB    396 _IP0_3	=	0x00bb
                    00BA    397 G$IP0_2$0$0 == 0x00ba
                    00BA    398 _IP0_2	=	0x00ba
                    00B9    399 G$IP0_1$0$0 == 0x00b9
                    00B9    400 _IP0_1	=	0x00b9
                    00B8    401 G$IP0_0$0$0 == 0x00b8
                    00B8    402 _IP0_0	=	0x00b8
                    0098    403 G$SCON_0$0$0 == 0x0098
                    0098    404 _SCON_0	=	0x0098
                    0099    405 G$SCON_1$0$0 == 0x0099
                    0099    406 _SCON_1	=	0x0099
                    009A    407 G$SCON_2$0$0 == 0x009a
                    009A    408 _SCON_2	=	0x009a
                    009B    409 G$SCON_3$0$0 == 0x009b
                    009B    410 _SCON_3	=	0x009b
                    009C    411 G$SCON_4$0$0 == 0x009c
                    009C    412 _SCON_4	=	0x009c
                    009D    413 G$SCON_5$0$0 == 0x009d
                    009D    414 _SCON_5	=	0x009d
                    009E    415 G$SCON_6$0$0 == 0x009e
                    009E    416 _SCON_6	=	0x009e
                    009F    417 G$SCON_7$0$0 == 0x009f
                    009F    418 _SCON_7	=	0x009f
                    00DE    419 G$I2CON_6$0$0 == 0x00de
                    00DE    420 _I2CON_6	=	0x00de
                    00DD    421 G$I2CON_5$0$0 == 0x00dd
                    00DD    422 _I2CON_5	=	0x00dd
                    00DC    423 G$I2CON_4$0$0 == 0x00dc
                    00DC    424 _I2CON_4	=	0x00dc
                    00DB    425 G$I2CON_3$0$0 == 0x00db
                    00DB    426 _I2CON_3	=	0x00db
                    00DA    427 G$I2CON_2$0$0 == 0x00da
                    00DA    428 _I2CON_2	=	0x00da
                    00D8    429 G$I2CON_0$0$0 == 0x00d8
                    00D8    430 _I2CON_0	=	0x00d8
                    0080    431 G$P0_0$0$0 == 0x0080
                    0080    432 _P0_0	=	0x0080
                    0081    433 G$P0_1$0$0 == 0x0081
                    0081    434 _P0_1	=	0x0081
                    0082    435 G$P0_2$0$0 == 0x0082
                    0082    436 _P0_2	=	0x0082
                    0083    437 G$P0_3$0$0 == 0x0083
                    0083    438 _P0_3	=	0x0083
                    0084    439 G$P0_4$0$0 == 0x0084
                    0084    440 _P0_4	=	0x0084
                    0085    441 G$P0_5$0$0 == 0x0085
                    0085    442 _P0_5	=	0x0085
                    0086    443 G$P0_6$0$0 == 0x0086
                    0086    444 _P0_6	=	0x0086
                    0087    445 G$P0_7$0$0 == 0x0087
                    0087    446 _P0_7	=	0x0087
                    0090    447 G$P1_0$0$0 == 0x0090
                    0090    448 _P1_0	=	0x0090
                    0091    449 G$P1_1$0$0 == 0x0091
                    0091    450 _P1_1	=	0x0091
                    0092    451 G$P1_2$0$0 == 0x0092
                    0092    452 _P1_2	=	0x0092
                    0093    453 G$P1_3$0$0 == 0x0093
                    0093    454 _P1_3	=	0x0093
                    0094    455 G$P1_4$0$0 == 0x0094
                    0094    456 _P1_4	=	0x0094
                    0095    457 G$P1_5$0$0 == 0x0095
                    0095    458 _P1_5	=	0x0095
                    0096    459 G$P1_6$0$0 == 0x0096
                    0096    460 _P1_6	=	0x0096
                    0097    461 G$P1_7$0$0 == 0x0097
                    0097    462 _P1_7	=	0x0097
                    00B0    463 G$P3_0$0$0 == 0x00b0
                    00B0    464 _P3_0	=	0x00b0
                    00B1    465 G$P3_1$0$0 == 0x00b1
                    00B1    466 _P3_1	=	0x00b1
                            467 ;--------------------------------------------------------
                            468 ; overlayable register banks
                            469 ;--------------------------------------------------------
                            470 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     471 	.ds 8
                            472 ;--------------------------------------------------------
                            473 ; overlayable bit register bank
                            474 ;--------------------------------------------------------
                            475 	.area BIT_BANK	(REL,OVR,DATA)
   0023                     476 bits:
   0023                     477 	.ds 1
                    8000    478 	b0 = bits[0]
                    8100    479 	b1 = bits[1]
                    8200    480 	b2 = bits[2]
                    8300    481 	b3 = bits[3]
                    8400    482 	b4 = bits[4]
                    8500    483 	b5 = bits[5]
                    8600    484 	b6 = bits[6]
                    8700    485 	b7 = bits[7]
                            486 ;--------------------------------------------------------
                            487 ; internal ram data
                            488 ;--------------------------------------------------------
                            489 	.area DSEG    (DATA)
                    0000    490 G$RAM$0$0 == 0x0000
                    0000    491 _RAM	=	0x0000
                    0010    492 G$timerbase$0$0 == 0x0010
                    0010    493 _timerbase	=	0x0010
                    0000    494 G$timercnt$0$0==.
   0024                     495 _timercnt::
   0024                     496 	.ds 16
                    0010    497 G$timerstate$0$0==.
   0034                     498 _timerstate::
   0034                     499 	.ds 16
                    0009    500 G$timer$0$0 == 0x0009
                    0009    501 _timer	=	0x0009
                    0009    502 G$delay_toggle$0$0 == 0x0009
                    0009    503 _delay_toggle	=	0x0009
                    0020    504 G$Tval$0$0==.
   0044                     505 _Tval::
   0044                     506 	.ds 1
                    000B    507 G$objects_move$0$0 == 0x000b
                    000B    508 _objects_move	=	0x000b
                    000C    509 G$objects_smove$0$0 == 0x000c
                    000C    510 _objects_smove	=	0x000c
                    000D    511 G$portbuffer$0$0 == 0x000d
                    000D    512 _portbuffer	=	0x000d
                    000E    513 G$oldportbuffer$0$0 == 0x000e
                    000E    514 _oldportbuffer	=	0x000e
                    000F    515 G$blocked$0$0 == 0x000f
                    000F    516 _blocked	=	0x000f
                    0021    517 G$zfstate$0$0==.
   0045                     518 _zfstate::
   0045                     519 	.ds 1
                    0022    520 G$oldblockvalue$0$0==.
   0046                     521 _oldblockvalue::
   0046                     522 	.ds 1
                    0023    523 G$kanal$0$0==.
   0047                     524 _kanal::
   0047                     525 	.ds 4
                    0027    526 G$knr$0$0==.
   004B                     527 _knr::
   004B                     528 	.ds 1
                    0028    529 G$ledport$0$0==.
   004C                     530 _ledport::
   004C                     531 	.ds 1
                            532 ;--------------------------------------------------------
                            533 ; overlayable items in internal ram 
                            534 ;--------------------------------------------------------
                            535 	.area OSEG    (OVR,DATA)
                            536 ;--------------------------------------------------------
                            537 ; indirectly addressable internal ram data
                            538 ;--------------------------------------------------------
                            539 	.area ISEG    (DATA)
                            540 ;--------------------------------------------------------
                            541 ; absolute internal ram data
                            542 ;--------------------------------------------------------
                            543 	.area IABS    (ABS,DATA)
                            544 	.area IABS    (ABS,DATA)
                            545 ;--------------------------------------------------------
                            546 ; bit data
                            547 ;--------------------------------------------------------
                            548 	.area BSEG    (BIT)
                    0000    549 G$portchanged$0$0==.
   0000                     550 _portchanged::
   0000                     551 	.ds 1
                    0001    552 G$state$0$0==.
   0001                     553 _state::
   0001                     554 	.ds 1
                    0002    555 G$handmode$0$0==.
   0002                     556 _handmode::
   0002                     557 	.ds 1
                            558 ;--------------------------------------------------------
                            559 ; paged external ram data
                            560 ;--------------------------------------------------------
                            561 	.area PSEG    (PAG,XDATA)
                            562 ;--------------------------------------------------------
                            563 ; external ram data
                            564 ;--------------------------------------------------------
                            565 	.area XSEG    (XDATA)
                            566 ;--------------------------------------------------------
                            567 ; absolute external ram data
                            568 ;--------------------------------------------------------
                            569 	.area XABS    (ABS,XDATA)
                            570 ;--------------------------------------------------------
                            571 ; external initialized ram data
                            572 ;--------------------------------------------------------
                            573 	.area XISEG   (XDATA)
                            574 	.area HOME    (CODE)
                            575 	.area GSINIT0 (CODE)
                            576 	.area GSINIT1 (CODE)
                            577 	.area GSINIT2 (CODE)
                            578 	.area GSINIT3 (CODE)
                            579 	.area GSINIT4 (CODE)
                            580 	.area GSINIT5 (CODE)
                            581 	.area GSINIT  (CODE)
                            582 	.area GSFINAL (CODE)
                            583 	.area CSEG    (CODE)
                            584 ;--------------------------------------------------------
                            585 ; global & static initialisations
                            586 ;--------------------------------------------------------
                            587 	.area HOME    (CODE)
                            588 	.area GSINIT  (CODE)
                            589 	.area GSFINAL (CODE)
                            590 	.area GSINIT  (CODE)
                            591 ;--------------------------------------------------------
                            592 ; Home
                            593 ;--------------------------------------------------------
                            594 	.area HOME    (CODE)
                            595 	.area HOME    (CODE)
                            596 ;--------------------------------------------------------
                            597 ; code
                            598 ;--------------------------------------------------------
                            599 	.area CSEG    (CODE)
                            600 ;------------------------------------------------------------
                            601 ;Allocation info for local variables in function 'write_value_req'
                            602 ;------------------------------------------------------------
                            603 ;objno                     Allocated to registers r4 
                            604 ;objflags                  Allocated to registers 
                            605 ;gapos                     Allocated to registers r7 
                            606 ;assno                     Allocated to registers r6 
                            607 ;n                         Allocated to registers r5 
                            608 ;gaposh                    Allocated to registers r4 
                            609 ;------------------------------------------------------------
                    0000    610 	G$write_value_req$0$0 ==.
                    0000    611 	C$fb_app_rollo10.c$73$0$0 ==.
                            612 ;	..\fb_app_rollo10.c:73: void write_value_req(void) 				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
                            613 ;	-----------------------------------------
                            614 ;	 function write_value_req
                            615 ;	-----------------------------------------
   020E                     616 _write_value_req:
                    0007    617 	ar7 = 0x07
                    0006    618 	ar6 = 0x06
                    0005    619 	ar5 = 0x05
                    0004    620 	ar4 = 0x04
                    0003    621 	ar3 = 0x03
                    0002    622 	ar2 = 0x02
                    0001    623 	ar1 = 0x01
                    0000    624 	ar0 = 0x00
                    0000    625 	C$fb_app_rollo10.c$80$1$1 ==.
                            626 ;	..\fb_app_rollo10.c:80: gapos=gapos_in_gat(telegramm[3],telegramm[4]);	// Position der Gruppenadresse in der Adresstabelle
   020E 85 57 82            627 	mov	dpl,(_telegramm + 0x0003)
   0211 C0 58               628 	push	(_telegramm + 0x0004)
   0213 12 12 0B            629 	lcall	_gapos_in_gat
   0216 AF 82               630 	mov	r7,dpl
   0218 15 81               631 	dec	sp
                    000C    632 	C$fb_app_rollo10.c$81$1$1 ==.
                            633 ;	..\fb_app_rollo10.c:81: if (gapos!=0xFF)	// =0xFF falls nicht vorhanden
   021A BF FF 03            634 	cjne	r7,#0xFF,00126$
   021D 02 02 B8            635 	ljmp	00115$
   0220                     636 00126$:
                    0012    637 	C$fb_app_rollo10.c$84$2$2 ==.
                            638 ;	..\fb_app_rollo10.c:84: assno=eeprom[ASSOCTABPTR];			// Erster Eintrag = Anzahl Einträge
   0220 90 1D 11            639 	mov	dptr,#(_eeprom + 0x0011)
   0223 E4                  640 	clr	a
   0224 93                  641 	movc	a,@a+dptr
   0225 FE                  642 	mov	r6,a
                    0018    643 	C$fb_app_rollo10.c$85$2$1 ==.
                            644 ;	..\fb_app_rollo10.c:85: for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
   0226 7D 00               645 	mov	r5,#0x00
   0228                     646 00111$:
   0228 C3                  647 	clr	c
   0229 ED                  648 	mov	a,r5
   022A 9E                  649 	subb	a,r6
   022B 40 03               650 	jc	00127$
   022D 02 02 B8            651 	ljmp	00115$
   0230                     652 00127$:
                    0022    653 	C$fb_app_rollo10.c$87$3$3 ==.
                            654 ;	..\fb_app_rollo10.c:87: gaposh=eeprom[eeprom[ASSOCTABPTR]+1+(n*2)];
   0230 90 1D 11            655 	mov	dptr,#(_eeprom + 0x0011)
   0233 E4                  656 	clr	a
   0234 93                  657 	movc	a,@a+dptr
   0235 FC                  658 	mov	r4,a
   0236 0C                  659 	inc	r4
   0237 ED                  660 	mov	a,r5
   0238 2D                  661 	add	a,r5
   0239 FB                  662 	mov	r3,a
   023A 2C                  663 	add	a,r4
   023B 90 1D 00            664 	mov	dptr,#_eeprom
   023E 93                  665 	movc	a,@a+dptr
   023F FC                  666 	mov	r4,a
                    0032    667 	C$fb_app_rollo10.c$88$3$3 ==.
                            668 ;	..\fb_app_rollo10.c:88: if(gapos==gaposh)					// Wenn Positionsnummer übereinstimmt
   0240 EF                  669 	mov	a,r7
   0241 B5 04 70            670 	cjne	a,ar4,00113$
                    0036    671 	C$fb_app_rollo10.c$90$4$4 ==.
                            672 ;	..\fb_app_rollo10.c:90: objno=eeprom[eeprom[ASSOCTABPTR]+2+(n*2)];				// Objektnummer
   0244 90 1D 11            673 	mov	dptr,#(_eeprom + 0x0011)
   0247 E4                  674 	clr	a
   0248 93                  675 	movc	a,@a+dptr
   0249 24 02               676 	add	a,#0x02
   024B 2B                  677 	add	a,r3
   024C 90 1D 00            678 	mov	dptr,#_eeprom
   024F 93                  679 	movc	a,@a+dptr
                    0042    680 	C$fb_app_rollo10.c$91$4$4 ==.
                            681 ;	..\fb_app_rollo10.c:91: objflags=read_objflags(objno);			// Objekt Flags lesen
   0250 FC                  682 	mov	r4,a
   0251 F5 82               683 	mov	dpl,a
   0253 C0 07               684 	push	ar7
   0255 C0 06               685 	push	ar6
   0257 C0 05               686 	push	ar5
   0259 C0 04               687 	push	ar4
   025B 12 16 A9            688 	lcall	_read_objflags
   025E D0 04               689 	pop	ar4
   0260 D0 05               690 	pop	ar5
   0262 D0 06               691 	pop	ar6
   0264 D0 07               692 	pop	ar7
                    0058    693 	C$fb_app_rollo10.c$93$4$4 ==.
                            694 ;	..\fb_app_rollo10.c:93: if (objno<8 && !handmode) object_schalten(objno,telegramm[7]&0x01);	// Objektnummer 0-4 entspricht den Kanälen 1-4
   0266 BC 08 00            695 	cjne	r4,#0x08,00130$
   0269                     696 00130$:
   0269 50 25               697 	jnc	00102$
   026B 20 02 22            698 	jb	_handmode,00102$
   026E E5 5B               699 	mov	a,(_telegramm + 0x0007)
   0270 54 01               700 	anl	a,#0x01
   0272 24 FF               701 	add	a,#0xff
   0274 92 18               702 	mov  b0,c
   0276 92 F0               703 	mov	b[0],c
   0278 C0 07               704 	push	ar7
   027A C0 06               705 	push	ar6
   027C C0 05               706 	push	ar5
   027E C0 04               707 	push	ar4
   0280 85 F0 23            708 	mov	bits,b
   0283 8C 82               709 	mov	dpl,r4
   0285 12 05 34            710 	lcall	_object_schalten
   0288 D0 04               711 	pop	ar4
   028A D0 05               712 	pop	ar5
   028C D0 06               713 	pop	ar6
   028E D0 07               714 	pop	ar7
   0290                     715 00102$:
                    0082    716 	C$fb_app_rollo10.c$95$4$4 ==.
                            717 ;	..\fb_app_rollo10.c:95: if (objno>=16 && objno<=17)Sobject_schalten(objno,telegramm[7]&0x01);	// Objektnummer 16+17 entspricht den Sicherheitsfahrten 1 + 2
   0290 BC 10 00            718 	cjne	r4,#0x10,00133$
   0293                     719 00133$:
   0293 40 1F               720 	jc	00113$
   0295 EC                  721 	mov	a,r4
   0296 24 EE               722 	add	a,#0xff - 0x11
   0298 40 1A               723 	jc	00113$
   029A 74 01               724 	mov	a,#0x01
   029C 55 5B               725 	anl	a,(_telegramm + 0x0007)
   029E FB                  726 	mov	r3,a
   029F C0 07               727 	push	ar7
   02A1 C0 06               728 	push	ar6
   02A3 C0 05               729 	push	ar5
   02A5 C0 03               730 	push	ar3
   02A7 8C 82               731 	mov	dpl,r4
   02A9 12 03 CA            732 	lcall	_Sobject_schalten
   02AC 15 81               733 	dec	sp
   02AE D0 05               734 	pop	ar5
   02B0 D0 06               735 	pop	ar6
   02B2 D0 07               736 	pop	ar7
   02B4                     737 00113$:
                    00A6    738 	C$fb_app_rollo10.c$85$2$2 ==.
                            739 ;	..\fb_app_rollo10.c:85: for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
   02B4 0D                  740 	inc	r5
   02B5 02 02 28            741 	ljmp	00111$
   02B8                     742 00115$:
                    00AA    743 	C$fb_app_rollo10.c$104$2$1 ==.
                    00AA    744 	XG$write_value_req$0$0 ==.
   02B8 22                  745 	ret
                            746 ;------------------------------------------------------------
                            747 ;Allocation info for local variables in function 'read_value_req'
                            748 ;------------------------------------------------------------
                            749 ;objno                     Allocated to registers r7 
                            750 ;objflags                  Allocated to registers r6 
                            751 ;objvalue                  Allocated to registers 
                            752 ;------------------------------------------------------------
                    00AB    753 	G$read_value_req$0$0 ==.
                    00AB    754 	C$fb_app_rollo10.c$220$2$1 ==.
                            755 ;	..\fb_app_rollo10.c:220: void read_value_req(void)// Sendet nach Leseanfrage objektwert auf den BUS
                            756 ;	-----------------------------------------
                            757 ;	 function read_value_req
                            758 ;	-----------------------------------------
   02B9                     759 _read_value_req:
                    00AB    760 	C$fb_app_rollo10.c$225$1$1 ==.
                            761 ;	..\fb_app_rollo10.c:225: objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
   02B9 85 57 82            762 	mov	dpl,(_telegramm + 0x0003)
   02BC C0 58               763 	push	(_telegramm + 0x0004)
   02BE 12 16 C1            764 	lcall	_find_first_objno
   02C1 AF 82               765 	mov	r7,dpl
   02C3 15 81               766 	dec	sp
                    00B7    767 	C$fb_app_rollo10.c$226$1$1 ==.
                            768 ;	..\fb_app_rollo10.c:226: if(objno!=0xFF) {	// falls Gruppenadresse nicht gefunden
   02C5 BF FF 02            769 	cjne	r7,#0xFF,00109$
   02C8 80 22               770 	sjmp	00105$
   02CA                     771 00109$:
                    00BC    772 	C$fb_app_rollo10.c$228$2$2 ==.
                            773 ;	..\fb_app_rollo10.c:228: objvalue=read_obj_value(objno);		// Objektwert aus USER-RAM lesen (Standard Einstellung)
   02CA 8F 82               774 	mov	dpl,r7
   02CC C0 07               775 	push	ar7
   02CE 12 02 ED            776 	lcall	_read_obj_value
   02D1 D0 07               777 	pop	ar7
                    00C5    778 	C$fb_app_rollo10.c$230$2$2 ==.
                            779 ;	..\fb_app_rollo10.c:230: objflags=read_objflags(objno);		// Objekt Flags lesen
   02D3 8F 82               780 	mov	dpl,r7
   02D5 C0 07               781 	push	ar7
   02D7 12 16 A9            782 	lcall	_read_objflags
   02DA AE 82               783 	mov	r6,dpl
   02DC D0 07               784 	pop	ar7
                    00D0    785 	C$fb_app_rollo10.c$232$2$2 ==.
                            786 ;	..\fb_app_rollo10.c:232: if((objflags&0x0C)==0x0C) send_obj_value(objno+64); //send_value(0,objno,objvalue);
   02DE 53 06 0C            787 	anl	ar6,#0x0C
   02E1 BE 0C 08            788 	cjne	r6,#0x0C,00105$
   02E4 74 40               789 	mov	a,#0x40
   02E6 2F                  790 	add	a,r7
   02E7 F5 82               791 	mov	dpl,a
   02E9 12 14 66            792 	lcall	_send_obj_value
   02EC                     793 00105$:
                    00DE    794 	C$fb_app_rollo10.c$234$1$1 ==.
                    00DE    795 	XG$read_value_req$0$0 ==.
   02EC 22                  796 	ret
                            797 ;------------------------------------------------------------
                            798 ;Allocation info for local variables in function 'read_obj_value'
                            799 ;------------------------------------------------------------
                            800 ;objno                     Allocated to registers r7 
                            801 ;ret_val                   Allocated to registers r6 
                            802 ;------------------------------------------------------------
                    00DF    803 	G$read_obj_value$0$0 ==.
                    00DF    804 	C$fb_app_rollo10.c$237$1$1 ==.
                            805 ;	..\fb_app_rollo10.c:237: unsigned long read_obj_value(unsigned char objno) 	// gibt den Wert eines Objektes zurueck
                            806 ;	-----------------------------------------
                            807 ;	 function read_obj_value
                            808 ;	-----------------------------------------
   02ED                     809 _read_obj_value:
   02ED AF 82               810 	mov	r7,dpl
                    00E1    811 	C$fb_app_rollo10.c$239$1$1 ==.
                            812 ;	..\fb_app_rollo10.c:239: unsigned char ret_val=0;
   02EF 7E 00               813 	mov	r6,#0x00
                    00E3    814 	C$fb_app_rollo10.c$241$1$1 ==.
                            815 ;	..\fb_app_rollo10.c:241: if(objno<8) {
   02F1 BF 08 00            816 	cjne	r7,#0x08,00113$
   02F4                     817 00113$:
   02F4 50 25               818 	jnc	00106$
                    00E8    819 	C$fb_app_rollo10.c$242$2$2 ==.
                            820 ;	..\fb_app_rollo10.c:242: if(objects_move &(1<<objno)) ret_val=1;
   02F6 8F F0               821 	mov	b,r7
   02F8 05 F0               822 	inc	b
   02FA 7C 01               823 	mov	r4,#0x01
   02FC 7D 00               824 	mov	r5,#0x00
   02FE 80 06               825 	sjmp	00116$
   0300                     826 00115$:
   0300 EC                  827 	mov	a,r4
   0301 2C                  828 	add	a,r4
   0302 FC                  829 	mov	r4,a
   0303 ED                  830 	mov	a,r5
   0304 33                  831 	rlc	a
   0305 FD                  832 	mov	r5,a
   0306                     833 00116$:
   0306 D5 F0 F7            834 	djnz	b,00115$
   0309 AA 0B               835 	mov	r2,_objects_move
   030B 7B 00               836 	mov	r3,#0x00
   030D EA                  837 	mov	a,r2
   030E 52 04               838 	anl	ar4,a
   0310 EB                  839 	mov	a,r3
   0311 52 05               840 	anl	ar5,a
   0313 EC                  841 	mov	a,r4
   0314 4D                  842 	orl	a,r5
   0315 60 30               843 	jz	00107$
   0317 7E 01               844 	mov	r6,#0x01
   0319 80 2C               845 	sjmp	00107$
   031B                     846 00106$:
                    010D    847 	C$fb_app_rollo10.c$245$2$3 ==.
                            848 ;	..\fb_app_rollo10.c:245: if(objects_smove&(1<<(objno-16))) ret_val=1;
   031B 7D 00               849 	mov	r5,#0x00
   031D EF                  850 	mov	a,r7
   031E 24 F0               851 	add	a,#0xF0
   0320 FF                  852 	mov	r7,a
   0321 ED                  853 	mov	a,r5
   0322 34 FF               854 	addc	a,#0xFF
   0324 8F F0               855 	mov	b,r7
   0326 05 F0               856 	inc	b
   0328 7F 01               857 	mov	r7,#0x01
   032A 7D 00               858 	mov	r5,#0x00
   032C 80 06               859 	sjmp	00119$
   032E                     860 00118$:
   032E EF                  861 	mov	a,r7
   032F 2F                  862 	add	a,r7
   0330 FF                  863 	mov	r7,a
   0331 ED                  864 	mov	a,r5
   0332 33                  865 	rlc	a
   0333 FD                  866 	mov	r5,a
   0334                     867 00119$:
   0334 D5 F0 F7            868 	djnz	b,00118$
   0337 AB 0C               869 	mov	r3,_objects_smove
   0339 7C 00               870 	mov	r4,#0x00
   033B EB                  871 	mov	a,r3
   033C 52 07               872 	anl	ar7,a
   033E EC                  873 	mov	a,r4
   033F 52 05               874 	anl	ar5,a
   0341 EF                  875 	mov	a,r7
   0342 4D                  876 	orl	a,r5
   0343 60 02               877 	jz	00107$
   0345 7E 01               878 	mov	r6,#0x01
   0347                     879 00107$:
                    0139    880 	C$fb_app_rollo10.c$247$1$1 ==.
                            881 ;	..\fb_app_rollo10.c:247: return(ret_val);
   0347 7F 00               882 	mov	r7,#0x00
   0349 7D 00               883 	mov	r5,#0x00
   034B 7C 00               884 	mov	r4,#0x00
   034D 8E 82               885 	mov	dpl,r6
   034F 8F 83               886 	mov	dph,r7
   0351 8D F0               887 	mov	b,r5
   0353 EC                  888 	mov	a,r4
                    0146    889 	C$fb_app_rollo10.c$248$1$1 ==.
                    0146    890 	XG$read_obj_value$0$0 ==.
   0354 22                  891 	ret
                            892 ;------------------------------------------------------------
                            893 ;Allocation info for local variables in function 'write_obj_value'
                            894 ;------------------------------------------------------------
                            895 ;objvalue                  Allocated to stack - _bp -4
                            896 ;objno                     Allocated to registers r7 
                            897 ;------------------------------------------------------------
                    0147    898 	G$write_obj_value$0$0 ==.
                    0147    899 	C$fb_app_rollo10.c$251$1$1 ==.
                            900 ;	..\fb_app_rollo10.c:251: void write_obj_value(unsigned char objno,unsigned int objvalue)	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
                            901 ;	-----------------------------------------
                            902 ;	 function write_obj_value
                            903 ;	-----------------------------------------
   0355                     904 _write_obj_value:
   0355 C0 08               905 	push	_bp
   0357 85 81 08            906 	mov	_bp,sp
   035A AF 82               907 	mov	r7,dpl
                    014E    908 	C$fb_app_rollo10.c$253$1$1 ==.
                            909 ;	..\fb_app_rollo10.c:253: if(objno<8) {// kurz und lanzeit
   035C BF 08 00            910 	cjne	r7,#0x08,00115$
   035F                     911 00115$:
   035F 50 32               912 	jnc	00108$
                    0153    913 	C$fb_app_rollo10.c$254$2$2 ==.
                            914 ;	..\fb_app_rollo10.c:254: if(objvalue==0) objects_move &= 0xFF-(1<<objno);
   0361 E5 08               915 	mov	a,_bp
   0363 24 FC               916 	add	a,#0xfc
   0365 F8                  917 	mov	r0,a
   0366 E6                  918 	mov	a,@r0
   0367 08                  919 	inc	r0
   0368 46                  920 	orl	a,@r0
   0369 70 16               921 	jnz	00102$
   036B 8F F0               922 	mov	b,r7
   036D 05 F0               923 	inc	b
   036F 74 01               924 	mov	a,#0x01
   0371 80 02               925 	sjmp	00120$
   0373                     926 00118$:
   0373 25 E0               927 	add	a,acc
   0375                     928 00120$:
   0375 D5 F0 FB            929 	djnz	b,00118$
   0378 FE                  930 	mov	r6,a
   0379 74 FF               931 	mov	a,#0xFF
   037B C3                  932 	clr	c
   037C 9E                  933 	subb	a,r6
   037D 52 0B               934 	anl	_objects_move,a
   037F 80 46               935 	sjmp	00110$
   0381                     936 00102$:
                    0173    937 	C$fb_app_rollo10.c$255$2$2 ==.
                            938 ;	..\fb_app_rollo10.c:255: else objects_move |=1<<objno;
   0381 8F F0               939 	mov	b,r7
   0383 05 F0               940 	inc	b
   0385 74 01               941 	mov	a,#0x01
   0387 80 02               942 	sjmp	00123$
   0389                     943 00121$:
   0389 25 E0               944 	add	a,acc
   038B                     945 00123$:
   038B D5 F0 FB            946 	djnz	b,00121$
   038E FE                  947 	mov	r6,a
   038F 42 0B               948 	orl	_objects_move,a
   0391 80 34               949 	sjmp	00110$
   0393                     950 00108$:
                    0185    951 	C$fb_app_rollo10.c$258$2$3 ==.
                            952 ;	..\fb_app_rollo10.c:258: objno-=16;// sicherheitsfahrt 16+17
   0393 EF                  953 	mov	a,r7
   0394 24 F0               954 	add	a,#0xF0
   0396 FF                  955 	mov	r7,a
                    0189    956 	C$fb_app_rollo10.c$259$2$3 ==.
                            957 ;	..\fb_app_rollo10.c:259: if(objvalue==0) objects_smove &= (0xFF-(1<<objno));
   0397 E5 08               958 	mov	a,_bp
   0399 24 FC               959 	add	a,#0xfc
   039B F8                  960 	mov	r0,a
   039C E6                  961 	mov	a,@r0
   039D 08                  962 	inc	r0
   039E 46                  963 	orl	a,@r0
   039F 70 16               964 	jnz	00105$
   03A1 8F F0               965 	mov	b,r7
   03A3 05 F0               966 	inc	b
   03A5 74 01               967 	mov	a,#0x01
   03A7 80 02               968 	sjmp	00127$
   03A9                     969 00125$:
   03A9 25 E0               970 	add	a,acc
   03AB                     971 00127$:
   03AB D5 F0 FB            972 	djnz	b,00125$
   03AE FE                  973 	mov	r6,a
   03AF 74 FF               974 	mov	a,#0xFF
   03B1 C3                  975 	clr	c
   03B2 9E                  976 	subb	a,r6
   03B3 52 0C               977 	anl	_objects_smove,a
   03B5 80 10               978 	sjmp	00110$
   03B7                     979 00105$:
                    01A9    980 	C$fb_app_rollo10.c$260$2$3 ==.
                            981 ;	..\fb_app_rollo10.c:260: else objects_smove |=1<<objno;
   03B7 8F F0               982 	mov	b,r7
   03B9 05 F0               983 	inc	b
   03BB 74 01               984 	mov	a,#0x01
   03BD 80 02               985 	sjmp	00130$
   03BF                     986 00128$:
   03BF 25 E0               987 	add	a,acc
   03C1                     988 00130$:
   03C1 D5 F0 FB            989 	djnz	b,00128$
   03C4 FF                  990 	mov	r7,a
   03C5 42 0C               991 	orl	_objects_smove,a
   03C7                     992 00110$:
   03C7 D0 08               993 	pop	_bp
                    01BB    994 	C$fb_app_rollo10.c$262$1$1 ==.
                    01BB    995 	XG$write_obj_value$0$0 ==.
   03C9 22                  996 	ret
                            997 ;------------------------------------------------------------
                            998 ;Allocation info for local variables in function 'Sobject_schalten'
                            999 ;------------------------------------------------------------
                           1000 ;val                       Allocated to stack - _bp -3
                           1001 ;objno                     Allocated to registers r7 
                           1002 ;k                         Allocated to registers r5 
                           1003 ;zuordnung                 Allocated to registers r7 
                           1004 ;sobj                      Allocated to registers r6 
                           1005 ;blockstart                Allocated to registers r7 
                           1006 ;blockend                  Allocated to registers r6 
                           1007 ;action                    Allocated to registers r4 
                           1008 ;------------------------------------------------------------
                    01BC   1009 	G$Sobject_schalten$0$0 ==.
                    01BC   1010 	C$fb_app_rollo10.c$264$1$1 ==.
                           1011 ;	..\fb_app_rollo10.c:264: void Sobject_schalten(unsigned char objno,unsigned char val)// Schaltet die Sicherheitsfunktionen
                           1012 ;	-----------------------------------------
                           1013 ;	 function Sobject_schalten
                           1014 ;	-----------------------------------------
   03CA                    1015 _Sobject_schalten:
   03CA C0 08              1016 	push	_bp
   03CC 85 81 08           1017 	mov	_bp,sp
                    01C1   1018 	C$fb_app_rollo10.c$268$1$1 ==.
                           1019 ;	..\fb_app_rollo10.c:268: if (objno >18){				// wenn bypass aus delay timer...
   03CF E5 82              1020 	mov	a,dpl
   03D1 FF                 1021 	mov	r7,a
   03D2 24 ED              1022 	add	a,#0xff - 0x12
   03D4 50 0F              1023 	jnc	00102$
                    01C8   1024 	C$fb_app_rollo10.c$269$2$2 ==.
                           1025 ;	..\fb_app_rollo10.c:269: sobj=objno&0x01;	// dann sobj ausfiltern
   03D6 74 01              1026 	mov	a,#0x01
   03D8 5F                 1027 	anl	a,r7
   03D9 FE                 1028 	mov	r6,a
                    01CC   1029 	C$fb_app_rollo10.c$270$2$2 ==.
                           1030 ;	..\fb_app_rollo10.c:270: state=0;				//state so setzen damit sperre aktiv wird
   03DA C2 01              1031 	clr	_state
                    01CE   1032 	C$fb_app_rollo10.c$271$2$2 ==.
                           1033 ;	..\fb_app_rollo10.c:271: val=0x01;		// dto für objektvalue
   03DC E5 08              1034 	mov	a,_bp
   03DE 24 FD              1035 	add	a,#0xfd
   03E0 F8                 1036 	mov	r0,a
   03E1 76 01              1037 	mov	@r0,#0x01
   03E3 80 31              1038 	sjmp	00103$
   03E5                    1039 00102$:
                    01D7   1040 	C$fb_app_rollo10.c$274$2$3 ==.
                           1041 ;	..\fb_app_rollo10.c:274: sobj=objno-16;				//sobj ("Sicherheitsobjektnummer")ist also 0 für Sicherheit1, 1 für Si 2
   03E5 EF                 1042 	mov	a,r7
   03E6 24 F0              1043 	add	a,#0xF0
   03E8 FE                 1044 	mov	r6,a
                    01DB   1045 	C$fb_app_rollo10.c$275$2$3 ==.
                           1046 ;	..\fb_app_rollo10.c:275: state=!((eeprom[0xE2])& (0x40<<sobj));//Polarität
   03E9 90 1D E2           1047 	mov	dptr,#(_eeprom + 0x00e2)
   03EC E4                 1048 	clr	a
   03ED 93                 1049 	movc	a,@a+dptr
   03EE FD                 1050 	mov	r5,a
   03EF 8E F0              1051 	mov	b,r6
   03F1 05 F0              1052 	inc	b
   03F3 7B 40              1053 	mov	r3,#0x40
   03F5 7C 00              1054 	mov	r4,#0x00
   03F7 80 06              1055 	sjmp	00132$
   03F9                    1056 00131$:
   03F9 EB                 1057 	mov	a,r3
   03FA 2B                 1058 	add	a,r3
   03FB FB                 1059 	mov	r3,a
   03FC EC                 1060 	mov	a,r4
   03FD 33                 1061 	rlc	a
   03FE FC                 1062 	mov	r4,a
   03FF                    1063 00132$:
   03FF D5 F0 F7           1064 	djnz	b,00131$
   0402 7A 00              1065 	mov	r2,#0x00
   0404 ED                 1066 	mov	a,r5
   0405 52 03              1067 	anl	ar3,a
   0407 EA                 1068 	mov	a,r2
   0408 52 04              1069 	anl	ar4,a
   040A EB                 1070 	mov	a,r3
   040B 4C                 1071 	orl	a,r4
   040C B4 01 00           1072 	cjne	a,#0x01,00133$
   040F                    1073 00133$:
   040F E4                 1074 	clr	a
   0410 33                 1075 	rlc	a
   0411 FB                 1076 	mov	r3,a
   0412 24 FF              1077 	add	a,#0xff
   0414 92 01              1078 	mov	_state,c
   0416                    1079 00103$:
                    0208   1080 	C$fb_app_rollo10.c$278$1$1 ==.
                           1081 ;	..\fb_app_rollo10.c:278: write_obj_value(objno & 0x1F ,val);		// Objektwert im userram speichern
   0416 E5 08              1082 	mov	a,_bp
   0418 24 FD              1083 	add	a,#0xfd
   041A F8                 1084 	mov	r0,a
   041B 86 04              1085 	mov	ar4,@r0
   041D 7D 00              1086 	mov	r5,#0x00
   041F 53 07 1F           1087 	anl	ar7,#0x1F
   0422 C0 06              1088 	push	ar6
   0424 C0 04              1089 	push	ar4
   0426 C0 05              1090 	push	ar5
   0428 8F 82              1091 	mov	dpl,r7
   042A 12 03 55           1092 	lcall	_write_obj_value
   042D 15 81              1093 	dec	sp
   042F 15 81              1094 	dec	sp
   0431 D0 06              1095 	pop	ar6
                    0225   1096 	C$fb_app_rollo10.c$280$1$1 ==.
                           1097 ;	..\fb_app_rollo10.c:280: if (state^(__bit)val) zfstate=zfstate |(0x0F<<(sobj<<2));// setzen der sicherhfahrt 1 in zfstate, xor verknüpft die polarität
   0433 E5 08              1098 	mov	a,_bp
   0435 24 FD              1099 	add	a,#0xfd
   0437 F8                 1100 	mov	r0,a
   0438 E6                 1101 	mov	a,@r0
   0439 24 FF              1102 	add	a,#0xff
   043B 92 18              1103 	mov  b0,c
   043D 30 01 01           1104 	jnb	_state,00134$
   0440 B3                 1105 	cpl	c
   0441                    1106 00134$:
   0441 50 17              1107 	jnc	00105$
   0443 EE                 1108 	mov	a,r6
   0444 2E                 1109 	add	a,r6
   0445 25 E0              1110 	add	a,acc
   0447 FF                 1111 	mov	r7,a
   0448 8F F0              1112 	mov	b,r7
   044A 05 F0              1113 	inc	b
   044C 74 0F              1114 	mov	a,#0x0F
   044E 80 02              1115 	sjmp	00138$
   0450                    1116 00136$:
   0450 25 E0              1117 	add	a,acc
   0452                    1118 00138$:
   0452 D5 F0 FB           1119 	djnz	b,00136$
   0455 FF                 1120 	mov	r7,a
   0456 42 45              1121 	orl	_zfstate,a
   0458 80 21              1122 	sjmp	00106$
   045A                    1123 00105$:
                    024C   1124 	C$fb_app_rollo10.c$282$2$4 ==.
                           1125 ;	..\fb_app_rollo10.c:282: zfstate=zfstate & (0xFF-(0x0F<<(sobj<<2)));//in zfstate sind für sich1 0F und sich2 F0
   045A EE                 1126 	mov	a,r6
   045B 2E                 1127 	add	a,r6
   045C 25 E0              1128 	add	a,acc
   045E FF                 1129 	mov	r7,a
   045F 8F F0              1130 	mov	b,r7
   0461 05 F0              1131 	inc	b
   0463 74 0F              1132 	mov	a,#0x0F
   0465 80 02              1133 	sjmp	00141$
   0467                    1134 00139$:
   0467 25 E0              1135 	add	a,acc
   0469                    1136 00141$:
   0469 D5 F0 FB           1137 	djnz	b,00139$
   046C FF                 1138 	mov	r7,a
   046D 74 FF              1139 	mov	a,#0xFF
   046F C3                 1140 	clr	c
   0470 9F                 1141 	subb	a,r7
   0471 52 45              1142 	anl	_zfstate,a
                    0265   1143 	C$fb_app_rollo10.c$283$2$4 ==.
                           1144 ;	..\fb_app_rollo10.c:283: set_entriegeln(sobj + 9);// Update objekt macht refresh auf Zeit 9/10  Zyklusüberwachung
   0473 74 09              1145 	mov	a,#0x09
   0475 2E                 1146 	add	a,r6
   0476 F5 82              1147 	mov	dpl,a
   0478 12 0C 49           1148 	lcall	_set_entriegeln
   047B                    1149 00106$:
                    026D   1150 	C$fb_app_rollo10.c$285$1$1 ==.
                           1151 ;	..\fb_app_rollo10.c:285: zuordnung=eeprom[0xF1] & zfstate;//in zuordnung jetzt eine 1 für jede sicherheit 
   047B 90 1D F1           1152 	mov	dptr,#(_eeprom + 0x00f1)
   047E E4                 1153 	clr	a
   047F 93                 1154 	movc	a,@a+dptr
   0480 FF                 1155 	mov	r7,a
   0481 E5 45              1156 	mov	a,_zfstate
   0483 52 07              1157 	anl	ar7,a
                    0277   1158 	C$fb_app_rollo10.c$286$1$1 ==.
                           1159 ;	..\fb_app_rollo10.c:286: blocked =zuordnung |((zuordnung >>4) | (zuordnung<<4)); //beide Sicherheitsergebnisse verodern..
   0485 EF                 1160 	mov	a,r7
   0486 C4                 1161 	swap	a
   0487 4F                 1162 	orl	a,r7
   0488 F5 0F              1163 	mov	_blocked,a
                    027C   1164 	C$fb_app_rollo10.c$288$1$1 ==.
                           1165 ;	..\fb_app_rollo10.c:288: blockstart= blocked & ~oldblockvalue;//steigende Flanke der Blockade(sicherheit)
   048A E5 46              1166 	mov	a,_oldblockvalue
   048C F4                 1167 	cpl	a
   048D FF                 1168 	mov	r7,a
   048E E5 0F              1169 	mov	a,_blocked
   0490 52 07              1170 	anl	ar7,a
                    0284   1171 	C$fb_app_rollo10.c$289$1$1 ==.
                           1172 ;	..\fb_app_rollo10.c:289: blockend= ~blocked & oldblockvalue;	//fallende Flanke der Blockade(sicherheit)
   0492 E5 0F              1173 	mov	a,_blocked
   0494 F4                 1174 	cpl	a
   0495 FE                 1175 	mov	r6,a
   0496 E5 46              1176 	mov	a,_oldblockvalue
   0498 52 06              1177 	anl	ar6,a
                    028C   1178 	C$fb_app_rollo10.c$293$1$1 ==.
                           1179 ;	..\fb_app_rollo10.c:293: if (!handmode){
   049A 30 02 03           1180 	jnb	_handmode,00142$
   049D 02 05 31           1181 	ljmp	00119$
   04A0                    1182 00142$:
                    0292   1183 	C$fb_app_rollo10.c$294$2$5 ==.
                           1184 ;	..\fb_app_rollo10.c:294: oldblockvalue=blocked;
   04A0 85 0F 46           1185 	mov	_oldblockvalue,_blocked
                    0295   1186 	C$fb_app_rollo10.c$296$2$1 ==.
                           1187 ;	..\fb_app_rollo10.c:296: for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
   04A3 7D 00              1188 	mov	r5,#0x00
   04A5                    1189 00115$:
   04A5 ED                 1190 	mov	a,r5
   04A6 24 FC              1191 	add	a,#0xff - 0x03
   04A8 50 03              1192 	jnc	00143$
   04AA 02 05 31           1193 	ljmp	00119$
   04AD                    1194 00143$:
                    029F   1195 	C$fb_app_rollo10.c$297$3$6 ==.
                           1196 ;	..\fb_app_rollo10.c:297: action=0;
   04AD 7C 00              1197 	mov	r4,#0x00
                    02A1   1198 	C$fb_app_rollo10.c$298$3$6 ==.
                           1199 ;	..\fb_app_rollo10.c:298: if(blockstart & 0x01){
   04AF EF                 1200 	mov	a,r7
   04B0 30 E0 24           1201 	jnb	acc.0,00108$
                    02A5   1202 	C$fb_app_rollo10.c$299$2$1 ==.
                           1203 ;	..\fb_app_rollo10.c:299: action=(eeprom[0xF0]>>(k<<1))&0x03;
   04B3 C0 06              1204 	push	ar6
   04B5 90 1D F0           1205 	mov	dptr,#(_eeprom + 0x00f0)
   04B8 E4                 1206 	clr	a
   04B9 93                 1207 	movc	a,@a+dptr
   04BA FB                 1208 	mov	r3,a
   04BB 8D 02              1209 	mov	ar2,r5
   04BD E4                 1210 	clr	a
   04BE CA                 1211 	xch	a,r2
   04BF 25 E0              1212 	add	a,acc
   04C1 CA                 1213 	xch	a,r2
   04C2 33                 1214 	rlc	a
   04C3 FE                 1215 	mov	r6,a
   04C4 8A F0              1216 	mov	b,r2
   04C6 05 F0              1217 	inc	b
   04C8 EB                 1218 	mov	a,r3
   04C9 80 02              1219 	sjmp	00146$
   04CB                    1220 00145$:
   04CB C3                 1221 	clr	c
   04CC 13                 1222 	rrc	a
   04CD                    1223 00146$:
   04CD D5 F0 FB           1224 	djnz	b,00145$
   04D0 FB                 1225 	mov	r3,a
   04D1 74 03              1226 	mov	a,#0x03
   04D3 5B                 1227 	anl	a,r3
   04D4 FC                 1228 	mov	r4,a
                    02C7   1229 	C$fb_app_rollo10.c$296$2$1 ==.
                           1230 ;	..\fb_app_rollo10.c:296: for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
   04D5 D0 06              1231 	pop	ar6
                    02C9   1232 	C$fb_app_rollo10.c$299$3$6 ==.
                           1233 ;	..\fb_app_rollo10.c:299: action=(eeprom[0xF0]>>(k<<1))&0x03;
   04D7                    1234 00108$:
                    02C9   1235 	C$fb_app_rollo10.c$301$3$6 ==.
                           1236 ;	..\fb_app_rollo10.c:301: if(blockend & 0x01){
   04D7 EE                 1237 	mov	a,r6
   04D8 30 E0 24           1238 	jnb	acc.0,00110$
                    02CD   1239 	C$fb_app_rollo10.c$302$2$1 ==.
                           1240 ;	..\fb_app_rollo10.c:302: action=(eeprom[0xEF]>>(k<<1))&0x03;
   04DB C0 06              1241 	push	ar6
   04DD 90 1D EF           1242 	mov	dptr,#(_eeprom + 0x00ef)
   04E0 E4                 1243 	clr	a
   04E1 93                 1244 	movc	a,@a+dptr
   04E2 FB                 1245 	mov	r3,a
   04E3 8D 02              1246 	mov	ar2,r5
   04E5 E4                 1247 	clr	a
   04E6 CA                 1248 	xch	a,r2
   04E7 25 E0              1249 	add	a,acc
   04E9 CA                 1250 	xch	a,r2
   04EA 33                 1251 	rlc	a
   04EB FE                 1252 	mov	r6,a
   04EC 8A F0              1253 	mov	b,r2
   04EE 05 F0              1254 	inc	b
   04F0 EB                 1255 	mov	a,r3
   04F1 80 02              1256 	sjmp	00149$
   04F3                    1257 00148$:
   04F3 C3                 1258 	clr	c
   04F4 13                 1259 	rrc	a
   04F5                    1260 00149$:
   04F5 D5 F0 FB           1261 	djnz	b,00148$
   04F8 FB                 1262 	mov	r3,a
   04F9 74 03              1263 	mov	a,#0x03
   04FB 5B                 1264 	anl	a,r3
   04FC FC                 1265 	mov	r4,a
                    02EF   1266 	C$fb_app_rollo10.c$296$2$1 ==.
                           1267 ;	..\fb_app_rollo10.c:296: for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
   04FD D0 06              1268 	pop	ar6
                    02F1   1269 	C$fb_app_rollo10.c$302$3$6 ==.
                           1270 ;	..\fb_app_rollo10.c:302: action=(eeprom[0xEF]>>(k<<1))&0x03;
   04FF                    1271 00110$:
                    02F1   1272 	C$fb_app_rollo10.c$304$3$6 ==.
                           1273 ;	..\fb_app_rollo10.c:304: if(action){
   04FF EC                 1274 	mov	a,r4
   0500 60 23              1275 	jz	00112$
                    02F4   1276 	C$fb_app_rollo10.c$305$4$9 ==.
                           1277 ;	..\fb_app_rollo10.c:305: object_schalten(k+12,action>>1);
   0502 EC                 1278 	mov	a,r4
   0503 C3                 1279 	clr	c
   0504 13                 1280 	rrc	a
   0505 24 FF              1281 	add	a,#0xff
   0507 92 18              1282 	mov	b0,c
   0509 74 0C              1283 	mov	a,#0x0C
   050B 2D                 1284 	add	a,r5
   050C FC                 1285 	mov	r4,a
   050D A2 18              1286 	mov	c,b0
   050F 92 F0              1287 	mov	b[0],c
   0511 C0 07              1288 	push	ar7
   0513 C0 06              1289 	push	ar6
   0515 C0 05              1290 	push	ar5
   0517 85 F0 23           1291 	mov	bits,b
   051A 8C 82              1292 	mov	dpl,r4
   051C 12 05 34           1293 	lcall	_object_schalten
   051F D0 05              1294 	pop	ar5
   0521 D0 06              1295 	pop	ar6
   0523 D0 07              1296 	pop	ar7
   0525                    1297 00112$:
                    0317   1298 	C$fb_app_rollo10.c$307$3$6 ==.
                           1299 ;	..\fb_app_rollo10.c:307: blockend=blockend>>1;
   0525 EE                 1300 	mov	a,r6
   0526 C3                 1301 	clr	c
   0527 13                 1302 	rrc	a
   0528 FE                 1303 	mov	r6,a
                    031B   1304 	C$fb_app_rollo10.c$308$3$6 ==.
                           1305 ;	..\fb_app_rollo10.c:308: blockstart=blockstart>>1;
   0529 EF                 1306 	mov	a,r7
   052A C3                 1307 	clr	c
   052B 13                 1308 	rrc	a
   052C FF                 1309 	mov	r7,a
                    031F   1310 	C$fb_app_rollo10.c$296$2$5 ==.
                           1311 ;	..\fb_app_rollo10.c:296: for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
   052D 0D                 1312 	inc	r5
   052E 02 04 A5           1313 	ljmp	00115$
   0531                    1314 00119$:
   0531 D0 08              1315 	pop	_bp
                    0325   1316 	C$fb_app_rollo10.c$311$2$1 ==.
                    0325   1317 	XG$Sobject_schalten$0$0 ==.
   0533 22                 1318 	ret
                           1319 ;------------------------------------------------------------
                           1320 ;Allocation info for local variables in function 'object_schalten'
                           1321 ;------------------------------------------------------------
                           1322 ;objstate                  Allocated to registers b0 
                           1323 ;objno                     Allocated to registers r7 
                           1324 ;port_pattern              Allocated to registers 
                           1325 ;objflags                  Allocated to registers r3 
                           1326 ;kwin                      Allocated to stack - _bp +1
                           1327 ;kwout                     Allocated to registers r5 
                           1328 ;faktor                    Allocated to registers r3 
                           1329 ;lz_ue                     Allocated to stack - _bp +2
                           1330 ;tmp                       Allocated to registers r6 
                           1331 ;delay_target              Allocated to registers r4 
                           1332 ;pluszeit                  Allocated to registers r2 
                           1333 ;off_disable               Allocated to registers 
                           1334 ;------------------------------------------------------------
                    0326   1335 	G$object_schalten$0$0 ==.
                    0326   1336 	C$fb_app_rollo10.c$317$2$1 ==.
                           1337 ;	..\fb_app_rollo10.c:317: void object_schalten(unsigned char objno, __bit objstate)	// Schaltet einen Ausgang gemäß objstate und den zugörigen Parametern
                           1338 ;	-----------------------------------------
                           1339 ;	 function object_schalten
                           1340 ;	-----------------------------------------
   0534                    1341 _object_schalten:
   0534 C0 08              1342 	push	_bp
   0536 85 81 08           1343 	mov	_bp,sp
   0539 05 81              1344 	inc	sp
   053B 05 81              1345 	inc	sp
   053D AF 82              1346 	mov	r7,dpl
                    0331   1347 	C$fb_app_rollo10.c$326$1$1 ==.
                           1348 ;	..\fb_app_rollo10.c:326: kwin = kanal[objno & 0x03]& 0x0f;// kwin heisst KanalWertIN. Bit 0+1 Relaise status, Bit 4+5 gewünschter Relaise status
   053F 74 03              1349 	mov	a,#0x03
   0541 5F                 1350 	anl	a,r7
   0542 24 47              1351 	add	a,#_kanal
   0544 F9                 1352 	mov	r1,a
   0545 87 06              1353 	mov	ar6,@r1
   0547 A8 08              1354 	mov	r0,_bp
   0549 08                 1355 	inc	r0
   054A 74 0F              1356 	mov	a,#0x0F
   054C 5E                 1357 	anl	a,r6
   054D F6                 1358 	mov	@r0,a
                    0340   1359 	C$fb_app_rollo10.c$327$1$1 ==.
                           1360 ;	..\fb_app_rollo10.c:327: kwout=kwin;
   054E A8 08              1361 	mov	r0,_bp
   0550 08                 1362 	inc	r0
   0551 86 05              1363 	mov	ar5,@r0
                    0345   1364 	C$fb_app_rollo10.c$328$1$1 ==.
                           1365 ;	..\fb_app_rollo10.c:328: if (objstate) write_obj_value(objno & 0x07,1);		// Objektwert im userram speichern
   0553 30 18 21           1366 	jnb	b0,00102$
   0556 74 07              1367 	mov	a,#0x07
   0558 5F                 1368 	anl	a,r7
   0559 F5 82              1369 	mov	dpl,a
   055B C0 07              1370 	push	ar7
   055D C0 05              1371 	push	ar5
   055F C0 23              1372 	push	bits
   0561 74 01              1373 	mov	a,#0x01
   0563 C0 E0              1374 	push	acc
   0565 E4                 1375 	clr	a
   0566 C0 E0              1376 	push	acc
   0568 12 03 55           1377 	lcall	_write_obj_value
   056B 15 81              1378 	dec	sp
   056D 15 81              1379 	dec	sp
   056F D0 23              1380 	pop	bits
   0571 D0 05              1381 	pop	ar5
   0573 D0 07              1382 	pop	ar7
   0575 80 1D              1383 	sjmp	00103$
   0577                    1384 00102$:
                    0369   1385 	C$fb_app_rollo10.c$329$1$1 ==.
                           1386 ;	..\fb_app_rollo10.c:329: else write_obj_value(objno & 0x07,0);
   0577 74 07              1387 	mov	a,#0x07
   0579 5F                 1388 	anl	a,r7
   057A F5 82              1389 	mov	dpl,a
   057C C0 07              1390 	push	ar7
   057E C0 05              1391 	push	ar5
   0580 C0 23              1392 	push	bits
   0582 E4                 1393 	clr	a
   0583 C0 E0              1394 	push	acc
   0585 C0 E0              1395 	push	acc
   0587 12 03 55           1396 	lcall	_write_obj_value
   058A 15 81              1397 	dec	sp
   058C 15 81              1398 	dec	sp
   058E D0 23              1399 	pop	bits
   0590 D0 05              1400 	pop	ar5
   0592 D0 07              1401 	pop	ar7
   0594                    1402 00103$:
                    0386   1403 	C$fb_app_rollo10.c$330$1$1 ==.
                           1404 ;	..\fb_app_rollo10.c:330: objflags=read_objflags(objno&0x07);			// Objekt Flags lesen
   0594 74 07              1405 	mov	a,#0x07
   0596 5F                 1406 	anl	a,r7
   0597 FC                 1407 	mov	r4,a
   0598 F5 82              1408 	mov	dpl,a
   059A C0 07              1409 	push	ar7
   059C C0 05              1410 	push	ar5
   059E C0 04              1411 	push	ar4
   05A0 C0 23              1412 	push	bits
   05A2 12 16 A9           1413 	lcall	_read_objflags
   05A5 AB 82              1414 	mov	r3,dpl
   05A7 D0 23              1415 	pop	bits
   05A9 D0 04              1416 	pop	ar4
   05AB D0 05              1417 	pop	ar5
   05AD D0 07              1418 	pop	ar7
                    03A1   1419 	C$fb_app_rollo10.c$331$1$1 ==.
                           1420 ;	..\fb_app_rollo10.c:331: port_pattern=0x01<<(objno&0x07);//port_pattern=0x01<<(objno&0x0F)
   05AF 8C F0              1421 	mov	b,r4
   05B1 05 F0              1422 	inc	b
   05B3 74 01              1423 	mov	a,#0x01
   05B5 80 02              1424 	sjmp	00195$
   05B7                    1425 00193$:
   05B7 25 E0              1426 	add	a,acc
   05B9                    1427 00195$:
   05B9 D5 F0 FB           1428 	djnz	b,00193$
                    03AE   1429 	C$fb_app_rollo10.c$334$1$1 ==.
                           1430 ;	..\fb_app_rollo10.c:334: if((port_pattern & blocked)==0 && (objflags&0x14)==0x14 ||(objno >=8)) {	// Objekt ist nicht gesperrt und Kommunikation zulässig (Bit 2 = communication enable) und Schreiben zulässig (Bit 4 = write enable)
   05BC 55 0F              1431 	anl	a,_blocked
   05BE 70 08              1432 	jnz	00161$
   05C0 53 03 14           1433 	anl	ar3,#0x14
   05C3 BB 14 02           1434 	cjne	r3,#0x14,00197$
   05C6 80 08              1435 	sjmp	00158$
   05C8                    1436 00197$:
   05C8                    1437 00161$:
   05C8 BF 08 00           1438 	cjne	r7,#0x08,00198$
   05CB                    1439 00198$:
   05CB 50 03              1440 	jnc	00199$
   05CD 02 09 38           1441 	ljmp	00162$
   05D0                    1442 00199$:
   05D0                    1443 00158$:
                    03C2   1444 	C$fb_app_rollo10.c$335$2$2 ==.
                           1445 ;	..\fb_app_rollo10.c:335: objno=objno&0x07;	// damit die bypassobjekte 8-15 wieder 0-7 sind!
   05D0 53 07 07           1446 	anl	ar7,#0x07
                    03C5   1447 	C$fb_app_rollo10.c$339$2$2 ==.
                           1448 ;	..\fb_app_rollo10.c:339: if (objno<0x04){			//+++++ kurzzeitobjekt +++++
   05D3 BF 04 00           1449 	cjne	r7,#0x04,00200$
   05D6                    1450 00200$:
   05D6 40 03              1451 	jc	00201$
   05D8 02 06 F6           1452 	ljmp	00146$
   05DB                    1453 00201$:
                    03CD   1454 	C$fb_app_rollo10.c$340$3$3 ==.
                           1455 ;	..\fb_app_rollo10.c:340: delay_target = (eeprom[0xE8+(objno>>1)]>>(3*(objno&0x01))&0x07)|0x80;// zeitbasis aus eeprom holen
   05DB EF                 1456 	mov	a,r7
   05DC C3                 1457 	clr	c
   05DD 13                 1458 	rrc	a
   05DE 24 E8              1459 	add	a,#0xE8
   05E0 90 1D 00           1460 	mov	dptr,#_eeprom
   05E3 93                 1461 	movc	a,@a+dptr
   05E4 FC                 1462 	mov	r4,a
   05E5 74 01              1463 	mov	a,#0x01
   05E7 5F                 1464 	anl	a,r7
   05E8 75 F0 03           1465 	mov	b,#0x03
   05EB A4                 1466 	mul	ab
   05EC F5 F0              1467 	mov	b,a
   05EE 05 F0              1468 	inc	b
   05F0 EC                 1469 	mov	a,r4
   05F1 80 02              1470 	sjmp	00203$
   05F3                    1471 00202$:
   05F3 C3                 1472 	clr	c
   05F4 13                 1473 	rrc	a
   05F5                    1474 00203$:
   05F5 D5 F0 FB           1475 	djnz	b,00202$
   05F8 54 07              1476 	anl	a,#0x07
   05FA FC                 1477 	mov	r4,a
   05FB 43 04 80           1478 	orl	ar4,#0x80
                    03F0   1479 	C$fb_app_rollo10.c$341$3$3 ==.
                           1480 ;	..\fb_app_rollo10.c:341: faktor=eeprom[0xEA+objno];// faktor holen um dann auf 0 zu prüfen
   05FE 74 EA              1481 	mov	a,#0xEA
   0600 2F                 1482 	add	a,r7
   0601 90 1D 00           1483 	mov	dptr,#_eeprom
   0604 93                 1484 	movc	a,@a+dptr
                    03F7   1485 	C$fb_app_rollo10.c$342$3$3 ==.
                           1486 ;	..\fb_app_rollo10.c:342: pluszeit=faktor + (faktor>>5);// 3% zeit bei "auf" 
   0605 FB                 1487 	mov	r3,a
   0606 C4                 1488 	swap	a
   0607 03                 1489 	rr	a
   0608 54 07              1490 	anl	a,#0x07
   060A 2B                 1491 	add	a,r3
   060B FA                 1492 	mov	r2,a
                    03FE   1493 	C$fb_app_rollo10.c$344$3$3 ==.
                           1494 ;	..\fb_app_rollo10.c:344: if (objstate==0){	//----- auf -----
   060C 20 18 71           1495 	jb	b0,00116$
                    0401   1496 	C$fb_app_rollo10.c$346$4$4 ==.
                           1497 ;	..\fb_app_rollo10.c:346: if (kwin&0x33){					// wenn faehrt,dann stop
   060F A8 08              1498 	mov	r0,_bp
   0611 08                 1499 	inc	r0
   0612 E6                 1500 	mov	a,@r0
   0613 54 33              1501 	anl	a,#0x33
   0615 60 39              1502 	jz	00108$
                    0409   1503 	C$fb_app_rollo10.c$347$5$5 ==.
                           1504 ;	..\fb_app_rollo10.c:347: set_pause(objno,kwin&0x03);
   0617 A8 08              1505 	mov	r0,_bp
   0619 08                 1506 	inc	r0
   061A 74 03              1507 	mov	a,#0x03
   061C 56                 1508 	anl	a,@r0
   061D FE                 1509 	mov	r6,a
   061E C0 07              1510 	push	ar7
   0620 C0 06              1511 	push	ar6
   0622 8F 82              1512 	mov	dpl,r7
   0624 12 0B EC           1513 	lcall	_set_pause
   0627 15 81              1514 	dec	sp
   0629 D0 07              1515 	pop	ar7
                    041D   1516 	C$fb_app_rollo10.c$349$5$5 ==.
                           1517 ;	..\fb_app_rollo10.c:349: kwout=kwin&0xCC;	// Fahrt in beide Richtungen stoppen
   062B A8 08              1518 	mov	r0,_bp
   062D 08                 1519 	inc	r0
   062E 74 CC              1520 	mov	a,#0xCC
   0630 56                 1521 	anl	a,@r0
   0631 FD                 1522 	mov	r5,a
                    0424   1523 	C$fb_app_rollo10.c$350$5$5 ==.
                           1524 ;	..\fb_app_rollo10.c:350: timerbase[objno]=0;	// kurzzeit löschen
   0632 EF                 1525 	mov	a,r7
   0633 24 10              1526 	add	a,#_timerbase
   0635 F8                 1527 	mov	r0,a
   0636 76 00              1528 	mov	@r0,#0x00
                    042A   1529 	C$fb_app_rollo10.c$351$5$5 ==.
                           1530 ;	..\fb_app_rollo10.c:351: timerstate[objno]=0;	// kurzzeit löschen
   0638 EF                 1531 	mov	a,r7
   0639 24 34              1532 	add	a,#_timerstate
   063B F8                 1533 	mov	r0,a
   063C 76 00              1534 	mov	@r0,#0x00
                    0430   1535 	C$fb_app_rollo10.c$352$5$5 ==.
                           1536 ;	..\fb_app_rollo10.c:352: timerbase[objno+4]=0;  // lanzeit löschen
   063E 74 04              1537 	mov	a,#0x04
   0640 2F                 1538 	add	a,r7
   0641 FE                 1539 	mov	r6,a
   0642 24 10              1540 	add	a,#_timerbase
   0644 F8                 1541 	mov	r0,a
   0645 76 00              1542 	mov	@r0,#0x00
                    0439   1543 	C$fb_app_rollo10.c$353$5$5 ==.
                           1544 ;	..\fb_app_rollo10.c:353: timerstate[objno+4]=0;  // lanzeit löschen
   0647 EE                 1545 	mov	a,r6
   0648 24 34              1546 	add	a,#_timerstate
   064A F8                 1547 	mov	r0,a
   064B 76 00              1548 	mov	@r0,#0x00
   064D 02 08 DB           1549 	ljmp	00147$
   0650                    1550 00108$:
                    0442   1551 	C$fb_app_rollo10.c$356$4$4 ==.
                           1552 ;	..\fb_app_rollo10.c:356: if ((!(kwin&0x33))&&(faktor)){	//wenn stillstand und faktor>0  dann step
   0650 A8 08              1553 	mov	r0,_bp
   0652 08                 1554 	inc	r0
   0653 E6                 1555 	mov	a,@r0
   0654 54 33              1556 	anl	a,#0x33
   0656 60 03              1557 	jz	00207$
   0658 02 08 DB           1558 	ljmp	00147$
   065B                    1559 00207$:
   065B EB                 1560 	mov	a,r3
   065C 70 03              1561 	jnz	00208$
   065E 02 08 DB           1562 	ljmp	00147$
   0661                    1563 00208$:
                    0453   1564 	C$fb_app_rollo10.c$357$5$6 ==.
                           1565 ;	..\fb_app_rollo10.c:357: kwout=kwin|0x10;
   0661 A8 08              1566 	mov	r0,_bp
   0663 08                 1567 	inc	r0
   0664 74 10              1568 	mov	a,#0x10
   0666 46                 1569 	orl	a,@r0
   0667 FD                 1570 	mov	r5,a
                    045A   1571 	C$fb_app_rollo10.c$358$5$6 ==.
                           1572 ;	..\fb_app_rollo10.c:358: kwout=kwout&0xDF;
   0668 53 05 DF           1573 	anl	ar5,#0xDF
                    045D   1574 	C$fb_app_rollo10.c$360$5$6 ==.
                           1575 ;	..\fb_app_rollo10.c:360: timerbase[objno]=delay_target;
   066B EF                 1576 	mov	a,r7
   066C 24 10              1577 	add	a,#_timerbase
   066E F8                 1578 	mov	r0,a
   066F A6 04              1579 	mov	@r0,ar4
                    0463   1580 	C$fb_app_rollo10.c$361$5$6 ==.
                           1581 ;	..\fb_app_rollo10.c:361: timercnt[objno]=pluszeit;
   0671 EF                 1582 	mov	a,r7
   0672 24 24              1583 	add	a,#_timercnt
   0674 F8                 1584 	mov	r0,a
   0675 A6 02              1585 	mov	@r0,ar2
                    0469   1586 	C$fb_app_rollo10.c$362$5$6 ==.
                           1587 ;	..\fb_app_rollo10.c:362: timerstate[objno]=0x01;
   0677 EF                 1588 	mov	a,r7
   0678 24 34              1589 	add	a,#_timerstate
   067A F8                 1590 	mov	r0,a
   067B 76 01              1591 	mov	@r0,#0x01
   067D 02 08 DB           1592 	ljmp	00147$
   0680                    1593 00116$:
                    0472   1594 	C$fb_app_rollo10.c$367$4$7 ==.
                           1595 ;	..\fb_app_rollo10.c:367: if (kwin&0x33){					// wenn faehrt, dann stop
   0680 A8 08              1596 	mov	r0,_bp
   0682 08                 1597 	inc	r0
   0683 E6                 1598 	mov	a,@r0
   0684 54 33              1599 	anl	a,#0x33
   0686 60 3E              1600 	jz	00111$
                    047A   1601 	C$fb_app_rollo10.c$368$5$8 ==.
                           1602 ;	..\fb_app_rollo10.c:368: set_pause(objno,kwin&0x03); //einsch. verz "pause" für eventuelle Faht in gegenrichtung
   0688 A8 08              1603 	mov	r0,_bp
   068A 08                 1604 	inc	r0
   068B 74 03              1605 	mov	a,#0x03
   068D 56                 1606 	anl	a,@r0
   068E FE                 1607 	mov	r6,a
   068F C0 07              1608 	push	ar7
   0691 C0 04              1609 	push	ar4
   0693 C0 03              1610 	push	ar3
   0695 C0 06              1611 	push	ar6
   0697 8F 82              1612 	mov	dpl,r7
   0699 12 0B EC           1613 	lcall	_set_pause
   069C 15 81              1614 	dec	sp
   069E D0 03              1615 	pop	ar3
   06A0 D0 04              1616 	pop	ar4
   06A2 D0 07              1617 	pop	ar7
                    0496   1618 	C$fb_app_rollo10.c$369$5$8 ==.
                           1619 ;	..\fb_app_rollo10.c:369: kwout=kwin&0xCC;
   06A4 A8 08              1620 	mov	r0,_bp
   06A6 08                 1621 	inc	r0
   06A7 74 CC              1622 	mov	a,#0xCC
   06A9 56                 1623 	anl	a,@r0
   06AA FD                 1624 	mov	r5,a
                    049D   1625 	C$fb_app_rollo10.c$372$5$8 ==.
                           1626 ;	..\fb_app_rollo10.c:372: timerbase[objno]=0;
   06AB EF                 1627 	mov	a,r7
   06AC 24 10              1628 	add	a,#_timerbase
   06AE F8                 1629 	mov	r0,a
   06AF 76 00              1630 	mov	@r0,#0x00
                    04A3   1631 	C$fb_app_rollo10.c$373$5$8 ==.
                           1632 ;	..\fb_app_rollo10.c:373: timerstate[objno]=0;
   06B1 EF                 1633 	mov	a,r7
   06B2 24 34              1634 	add	a,#_timerstate
   06B4 F8                 1635 	mov	r0,a
   06B5 76 00              1636 	mov	@r0,#0x00
                    04A9   1637 	C$fb_app_rollo10.c$374$5$8 ==.
                           1638 ;	..\fb_app_rollo10.c:374: timerbase[objno+4]=0;
   06B7 74 04              1639 	mov	a,#0x04
   06B9 2F                 1640 	add	a,r7
   06BA FE                 1641 	mov	r6,a
   06BB 24 10              1642 	add	a,#_timerbase
   06BD F8                 1643 	mov	r0,a
   06BE 76 00              1644 	mov	@r0,#0x00
                    04B2   1645 	C$fb_app_rollo10.c$375$5$8 ==.
                           1646 ;	..\fb_app_rollo10.c:375: timerstate[objno+4]=0;
   06C0 EE                 1647 	mov	a,r6
   06C1 24 34              1648 	add	a,#_timerstate
   06C3 F8                 1649 	mov	r0,a
   06C4 76 00              1650 	mov	@r0,#0x00
   06C6                    1651 00111$:
                    04B8   1652 	C$fb_app_rollo10.c$377$4$7 ==.
                           1653 ;	..\fb_app_rollo10.c:377: if ((!(kwin&0x33))&&(faktor)){		// wenn stillstand dann step
   06C6 A8 08              1654 	mov	r0,_bp
   06C8 08                 1655 	inc	r0
   06C9 E6                 1656 	mov	a,@r0
   06CA 54 33              1657 	anl	a,#0x33
   06CC 60 03              1658 	jz	00211$
   06CE 02 08 DB           1659 	ljmp	00147$
   06D1                    1660 00211$:
   06D1 EB                 1661 	mov	a,r3
   06D2 70 03              1662 	jnz	00212$
   06D4 02 08 DB           1663 	ljmp	00147$
   06D7                    1664 00212$:
                    04C9   1665 	C$fb_app_rollo10.c$378$5$9 ==.
                           1666 ;	..\fb_app_rollo10.c:378: kwout=kwin|0x20;
   06D7 A8 08              1667 	mov	r0,_bp
   06D9 08                 1668 	inc	r0
   06DA 74 20              1669 	mov	a,#0x20
   06DC 46                 1670 	orl	a,@r0
   06DD FD                 1671 	mov	r5,a
                    04D0   1672 	C$fb_app_rollo10.c$379$5$9 ==.
                           1673 ;	..\fb_app_rollo10.c:379: kwout=kwout&0xEF;
   06DE 53 05 EF           1674 	anl	ar5,#0xEF
                    04D3   1675 	C$fb_app_rollo10.c$381$5$9 ==.
                           1676 ;	..\fb_app_rollo10.c:381: timerbase[objno]=delay_target;
   06E1 EF                 1677 	mov	a,r7
   06E2 24 10              1678 	add	a,#_timerbase
   06E4 F8                 1679 	mov	r0,a
   06E5 A6 04              1680 	mov	@r0,ar4
                    04D9   1681 	C$fb_app_rollo10.c$382$5$9 ==.
                           1682 ;	..\fb_app_rollo10.c:382: timercnt[objno]=faktor;
   06E7 EF                 1683 	mov	a,r7
   06E8 24 24              1684 	add	a,#_timercnt
   06EA F8                 1685 	mov	r0,a
   06EB A6 03              1686 	mov	@r0,ar3
                    04DF   1687 	C$fb_app_rollo10.c$383$5$9 ==.
                           1688 ;	..\fb_app_rollo10.c:383: timerstate[objno]=0x02;
   06ED EF                 1689 	mov	a,r7
   06EE 24 34              1690 	add	a,#_timerstate
   06F0 F8                 1691 	mov	r0,a
   06F1 76 02              1692 	mov	@r0,#0x02
   06F3 02 08 DB           1693 	ljmp	00147$
   06F6                    1694 00146$:
                    04E8   1695 	C$fb_app_rollo10.c$390$2$1 ==.
                           1696 ;	..\fb_app_rollo10.c:390: delay_target=(eeprom[0xFB+((objno&0x03)>>1)]>>(3*(objno&0x01))&0x07) | 0x80;// zeitbasis aus eeprom holen
   06F6 C0 05              1697 	push	ar5
   06F8 74 03              1698 	mov	a,#0x03
   06FA 5F                 1699 	anl	a,r7
   06FB FE                 1700 	mov	r6,a
   06FC C3                 1701 	clr	c
   06FD 13                 1702 	rrc	a
   06FE 24 FB              1703 	add	a,#0xFB
   0700 90 1D 00           1704 	mov	dptr,#_eeprom
   0703 93                 1705 	movc	a,@a+dptr
   0704 FD                 1706 	mov	r5,a
   0705 74 01              1707 	mov	a,#0x01
   0707 5F                 1708 	anl	a,r7
   0708 75 F0 03           1709 	mov	b,#0x03
   070B A4                 1710 	mul	ab
   070C F5 F0              1711 	mov	b,a
   070E 05 F0              1712 	inc	b
   0710 ED                 1713 	mov	a,r5
   0711 80 02              1714 	sjmp	00214$
   0713                    1715 00213$:
   0713 C3                 1716 	clr	c
   0714 13                 1717 	rrc	a
   0715                    1718 00214$:
   0715 D5 F0 FB           1719 	djnz	b,00213$
   0718 54 07              1720 	anl	a,#0x07
   071A FD                 1721 	mov	r5,a
   071B 74 80              1722 	mov	a,#0x80
   071D 4D                 1723 	orl	a,r5
   071E FC                 1724 	mov	r4,a
                    0511   1725 	C$fb_app_rollo10.c$391$3$10 ==.
                           1726 ;	..\fb_app_rollo10.c:391: faktor = eeprom[0xDA+(objno&0x03)];
   071F 74 DA              1727 	mov	a,#0xDA
   0721 2E                 1728 	add	a,r6
   0722 90 1D 00           1729 	mov	dptr,#_eeprom
   0725 93                 1730 	movc	a,@a+dptr
                    0518   1731 	C$fb_app_rollo10.c$392$3$10 ==.
                           1732 ;	..\fb_app_rollo10.c:392: faktor = faktor + (faktor>>2);// +25% zeit bei langzeit 
   0726 FB                 1733 	mov	r3,a
   0727 03                 1734 	rr	a
   0728 03                 1735 	rr	a
   0729 54 3F              1736 	anl	a,#0x3F
   072B 2B                 1737 	add	a,r3
                    051E   1738 	C$fb_app_rollo10.c$393$3$10 ==.
                           1739 ;	..\fb_app_rollo10.c:393: pluszeit=faktor + (faktor>>5);// 3% zeit bei "auf" 
   072C FB                 1740 	mov	r3,a
   072D C4                 1741 	swap	a
   072E 03                 1742 	rr	a
   072F 54 07              1743 	anl	a,#0x07
   0731 2B                 1744 	add	a,r3
   0732 FA                 1745 	mov	r2,a
                    0525   1746 	C$fb_app_rollo10.c$394$3$10 ==.
                           1747 ;	..\fb_app_rollo10.c:394: lz_ue=((eeprom[0xF2]>>objno)&0x01);		//lz_ue bedeutet: langzeit unendlich
   0733 90 1D F2           1748 	mov	dptr,#(_eeprom + 0x00f2)
   0736 E4                 1749 	clr	a
   0737 93                 1750 	movc	a,@a+dptr
   0738 FE                 1751 	mov	r6,a
   0739 8F F0              1752 	mov	b,r7
   073B 05 F0              1753 	inc	b
   073D EE                 1754 	mov	a,r6
   073E 80 02              1755 	sjmp	00216$
   0740                    1756 00215$:
   0740 C3                 1757 	clr	c
   0741 13                 1758 	rrc	a
   0742                    1759 00216$:
   0742 D5 F0 FB           1760 	djnz	b,00215$
   0745 FE                 1761 	mov	r6,a
   0746 A8 08              1762 	mov	r0,_bp
   0748 08                 1763 	inc	r0
   0749 08                 1764 	inc	r0
   074A 74 01              1765 	mov	a,#0x01
   074C 5E                 1766 	anl	a,r6
   074D F6                 1767 	mov	@r0,a
                    0540   1768 	C$fb_app_rollo10.c$395$2$1 ==.
                           1769 ;	..\fb_app_rollo10.c:395: if (objstate==0){// --- auf ----
   074E D0 05              1770 	pop	ar5
   0750 30 18 03           1771 	jnb	b0,00217$
   0753 02 08 08           1772 	ljmp	00143$
   0756                    1773 00217$:
                    0548   1774 	C$fb_app_rollo10.c$396$4$11 ==.
                           1775 ;	..\fb_app_rollo10.c:396: if (kwin&0x11){		//läuft bereits, also nachtriggern
   0756 A8 08              1776 	mov	r0,_bp
   0758 08                 1777 	inc	r0
   0759 E6                 1778 	mov	a,@r0
   075A 54 11              1779 	anl	a,#0x11
   075C 60 35              1780 	jz	00121$
                    0550   1781 	C$fb_app_rollo10.c$397$5$12 ==.
                           1782 ;	..\fb_app_rollo10.c:397: kwout=kwin|0x10;// auch hier neu setzen da in delay nach rechts kommt
   075E A8 08              1783 	mov	r0,_bp
   0760 08                 1784 	inc	r0
   0761 74 10              1785 	mov	a,#0x10
   0763 46                 1786 	orl	a,@r0
   0764 FD                 1787 	mov	r5,a
                    0557   1788 	C$fb_app_rollo10.c$398$5$12 ==.
                           1789 ;	..\fb_app_rollo10.c:398: timercnt[objno-4]=0;//kurzzeit löschen
   0765 EF                 1790 	mov	a,r7
   0766 24 FC              1791 	add	a,#0xFC
   0768 FE                 1792 	mov	r6,a
   0769 24 24              1793 	add	a,#_timercnt
   076B F8                 1794 	mov	r0,a
   076C 76 00              1795 	mov	@r0,#0x00
                    0560   1796 	C$fb_app_rollo10.c$399$5$12 ==.
                           1797 ;	..\fb_app_rollo10.c:399: timerstate[objno-4]=0;
   076E EE                 1798 	mov	a,r6
   076F 24 34              1799 	add	a,#_timerstate
   0771 F8                 1800 	mov	r0,a
   0772 76 00              1801 	mov	@r0,#0x00
                    0566   1802 	C$fb_app_rollo10.c$400$5$12 ==.
                           1803 ;	..\fb_app_rollo10.c:400: timerbase[objno-4]=0;
   0774 EE                 1804 	mov	a,r6
   0775 24 10              1805 	add	a,#_timerbase
   0777 F8                 1806 	mov	r0,a
   0778 76 00              1807 	mov	@r0,#0x00
                    056C   1808 	C$fb_app_rollo10.c$401$5$12 ==.
                           1809 ;	..\fb_app_rollo10.c:401: if (!lz_ue){
   077A A8 08              1810 	mov	r0,_bp
   077C 08                 1811 	inc	r0
   077D 08                 1812 	inc	r0
   077E E6                 1813 	mov	a,@r0
   077F 70 12              1814 	jnz	00121$
                    0573   1815 	C$fb_app_rollo10.c$403$6$13 ==.
                           1816 ;	..\fb_app_rollo10.c:403: timerbase[objno]=delay_target;
   0781 EF                 1817 	mov	a,r7
   0782 24 10              1818 	add	a,#_timerbase
   0784 F8                 1819 	mov	r0,a
   0785 A6 04              1820 	mov	@r0,ar4
                    0579   1821 	C$fb_app_rollo10.c$404$6$13 ==.
                           1822 ;	..\fb_app_rollo10.c:404: timercnt[objno]=pluszeit;
   0787 EF                 1823 	mov	a,r7
   0788 24 24              1824 	add	a,#_timercnt
   078A F8                 1825 	mov	r0,a
   078B A6 02              1826 	mov	@r0,ar2
                    057F   1827 	C$fb_app_rollo10.c$405$6$13 ==.
                           1828 ;	..\fb_app_rollo10.c:405: timerstate[objno]=0x01;
   078D EF                 1829 	mov	a,r7
   078E 24 34              1830 	add	a,#_timerstate
   0790 F8                 1831 	mov	r0,a
   0791 76 01              1832 	mov	@r0,#0x01
   0793                    1833 00121$:
                    0585   1834 	C$fb_app_rollo10.c$408$4$11 ==.
                           1835 ;	..\fb_app_rollo10.c:408: if (!(kwin&0x33)){	//wenn stillstand, dann move
   0793 A8 08              1836 	mov	r0,_bp
   0795 08                 1837 	inc	r0
   0796 E6                 1838 	mov	a,@r0
   0797 54 33              1839 	anl	a,#0x33
   0799 70 20              1840 	jnz	00125$
                    058D   1841 	C$fb_app_rollo10.c$409$5$14 ==.
                           1842 ;	..\fb_app_rollo10.c:409: kwout=kwin|0x10;
   079B A8 08              1843 	mov	r0,_bp
   079D 08                 1844 	inc	r0
   079E 74 10              1845 	mov	a,#0x10
   07A0 46                 1846 	orl	a,@r0
   07A1 FD                 1847 	mov	r5,a
                    0594   1848 	C$fb_app_rollo10.c$412$5$14 ==.
                           1849 ;	..\fb_app_rollo10.c:412: if (!lz_ue){
   07A2 A8 08              1850 	mov	r0,_bp
   07A4 08                 1851 	inc	r0
   07A5 08                 1852 	inc	r0
   07A6 E6                 1853 	mov	a,@r0
   07A7 70 12              1854 	jnz	00125$
                    059B   1855 	C$fb_app_rollo10.c$414$6$15 ==.
                           1856 ;	..\fb_app_rollo10.c:414: timerbase[objno]=delay_target;
   07A9 EF                 1857 	mov	a,r7
   07AA 24 10              1858 	add	a,#_timerbase
   07AC F8                 1859 	mov	r0,a
   07AD A6 04              1860 	mov	@r0,ar4
                    05A1   1861 	C$fb_app_rollo10.c$415$6$15 ==.
                           1862 ;	..\fb_app_rollo10.c:415: timercnt[objno]=pluszeit;
   07AF EF                 1863 	mov	a,r7
   07B0 24 24              1864 	add	a,#_timercnt
   07B2 F8                 1865 	mov	r0,a
   07B3 A6 02              1866 	mov	@r0,ar2
                    05A7   1867 	C$fb_app_rollo10.c$416$6$15 ==.
                           1868 ;	..\fb_app_rollo10.c:416: timerstate[objno]=0x01;
   07B5 EF                 1869 	mov	a,r7
   07B6 24 34              1870 	add	a,#_timerstate
   07B8 F8                 1871 	mov	r0,a
   07B9 76 01              1872 	mov	@r0,#0x01
   07BB                    1873 00125$:
                    05AD   1874 	C$fb_app_rollo10.c$420$4$11 ==.
                           1875 ;	..\fb_app_rollo10.c:420: if (kwin&0x22){		// wenn fahrt in andere richtung
   07BB A8 08              1876 	mov	r0,_bp
   07BD 08                 1877 	inc	r0
   07BE E6                 1878 	mov	a,@r0
   07BF 54 22              1879 	anl	a,#0x22
   07C1 70 03              1880 	jnz	00223$
   07C3 02 08 DB           1881 	ljmp	00147$
   07C6                    1882 00223$:
                    05B8   1883 	C$fb_app_rollo10.c$421$5$16 ==.
                           1884 ;	..\fb_app_rollo10.c:421: set_pause(objno,0x05);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
   07C6 C0 07              1885 	push	ar7
   07C8 C0 04              1886 	push	ar4
   07CA C0 02              1887 	push	ar2
   07CC 74 05              1888 	mov	a,#0x05
   07CE C0 E0              1889 	push	acc
   07D0 8F 82              1890 	mov	dpl,r7
   07D2 12 0B EC           1891 	lcall	_set_pause
   07D5 15 81              1892 	dec	sp
   07D7 D0 02              1893 	pop	ar2
   07D9 D0 04              1894 	pop	ar4
   07DB D0 07              1895 	pop	ar7
                    05CF   1896 	C$fb_app_rollo10.c$422$5$16 ==.
                           1897 ;	..\fb_app_rollo10.c:422: kwout=kwin|0x10;
   07DD A8 08              1898 	mov	r0,_bp
   07DF 08                 1899 	inc	r0
   07E0 74 10              1900 	mov	a,#0x10
   07E2 46                 1901 	orl	a,@r0
   07E3 FD                 1902 	mov	r5,a
                    05D6   1903 	C$fb_app_rollo10.c$423$5$16 ==.
                           1904 ;	..\fb_app_rollo10.c:423: kwout=kwout&0xDF;
   07E4 53 05 DF           1905 	anl	ar5,#0xDF
                    05D9   1906 	C$fb_app_rollo10.c$424$5$16 ==.
                           1907 ;	..\fb_app_rollo10.c:424: if (!lz_ue){
   07E7 A8 08              1908 	mov	r0,_bp
   07E9 08                 1909 	inc	r0
   07EA 08                 1910 	inc	r0
   07EB E6                 1911 	mov	a,@r0
   07EC 60 03              1912 	jz	00224$
   07EE 02 08 DB           1913 	ljmp	00147$
   07F1                    1914 00224$:
                    05E3   1915 	C$fb_app_rollo10.c$426$6$17 ==.
                           1916 ;	..\fb_app_rollo10.c:426: timerbase[objno]=delay_target & 0x7F;// timer-run für den move löschen
   07F1 EF                 1917 	mov	a,r7
   07F2 24 10              1918 	add	a,#_timerbase
   07F4 F9                 1919 	mov	r1,a
   07F5 74 7F              1920 	mov	a,#0x7F
   07F7 5C                 1921 	anl	a,r4
   07F8 F7                 1922 	mov	@r1,a
                    05EB   1923 	C$fb_app_rollo10.c$427$6$17 ==.
                           1924 ;	..\fb_app_rollo10.c:427: timercnt[objno]=pluszeit;
   07F9 EF                 1925 	mov	a,r7
   07FA 24 24              1926 	add	a,#_timercnt
   07FC F8                 1927 	mov	r0,a
   07FD A6 02              1928 	mov	@r0,ar2
                    05F1   1929 	C$fb_app_rollo10.c$428$6$17 ==.
                           1930 ;	..\fb_app_rollo10.c:428: timerstate[objno]=0x01;
   07FF EF                 1931 	mov	a,r7
   0800 24 34              1932 	add	a,#_timerstate
   0802 F8                 1933 	mov	r0,a
   0803 76 01              1934 	mov	@r0,#0x01
   0805 02 08 DB           1935 	ljmp	00147$
   0808                    1936 00143$:
                    05FA   1937 	C$fb_app_rollo10.c$434$4$18 ==.
                           1938 ;	..\fb_app_rollo10.c:434: if (kwin&0x22){		//läuft bereits, also nachtriggern
   0808 A8 08              1939 	mov	r0,_bp
   080A 08                 1940 	inc	r0
   080B E6                 1941 	mov	a,@r0
   080C 54 22              1942 	anl	a,#0x22
   080E 60 35              1943 	jz	00133$
                    0602   1944 	C$fb_app_rollo10.c$435$5$19 ==.
                           1945 ;	..\fb_app_rollo10.c:435: kwout=kwin|0x20;// auch hier neu setzen da in delay nach rechts kommt
   0810 A8 08              1946 	mov	r0,_bp
   0812 08                 1947 	inc	r0
   0813 74 20              1948 	mov	a,#0x20
   0815 46                 1949 	orl	a,@r0
   0816 FD                 1950 	mov	r5,a
                    0609   1951 	C$fb_app_rollo10.c$436$5$19 ==.
                           1952 ;	..\fb_app_rollo10.c:436: timerbase[objno-4]=0; 
   0817 EF                 1953 	mov	a,r7
   0818 24 FC              1954 	add	a,#0xFC
   081A FE                 1955 	mov	r6,a
   081B 24 10              1956 	add	a,#_timerbase
   081D F8                 1957 	mov	r0,a
   081E 76 00              1958 	mov	@r0,#0x00
                    0612   1959 	C$fb_app_rollo10.c$437$5$19 ==.
                           1960 ;	..\fb_app_rollo10.c:437: timercnt[objno-4]=0;
   0820 EE                 1961 	mov	a,r6
   0821 24 24              1962 	add	a,#_timercnt
   0823 F8                 1963 	mov	r0,a
   0824 76 00              1964 	mov	@r0,#0x00
                    0618   1965 	C$fb_app_rollo10.c$438$5$19 ==.
                           1966 ;	..\fb_app_rollo10.c:438: timerstate[objno-4]=0;
   0826 EE                 1967 	mov	a,r6
   0827 24 34              1968 	add	a,#_timerstate
   0829 F8                 1969 	mov	r0,a
   082A 76 00              1970 	mov	@r0,#0x00
                    061E   1971 	C$fb_app_rollo10.c$440$5$19 ==.
                           1972 ;	..\fb_app_rollo10.c:440: if (!lz_ue){
   082C A8 08              1973 	mov	r0,_bp
   082E 08                 1974 	inc	r0
   082F 08                 1975 	inc	r0
   0830 E6                 1976 	mov	a,@r0
   0831 70 12              1977 	jnz	00133$
                    0625   1978 	C$fb_app_rollo10.c$442$6$20 ==.
                           1979 ;	..\fb_app_rollo10.c:442: timerbase[objno]=delay_target;
   0833 EF                 1980 	mov	a,r7
   0834 24 10              1981 	add	a,#_timerbase
   0836 F8                 1982 	mov	r0,a
   0837 A6 04              1983 	mov	@r0,ar4
                    062B   1984 	C$fb_app_rollo10.c$443$6$20 ==.
                           1985 ;	..\fb_app_rollo10.c:443: timercnt[objno]=faktor;
   0839 EF                 1986 	mov	a,r7
   083A 24 24              1987 	add	a,#_timercnt
   083C F8                 1988 	mov	r0,a
   083D A6 03              1989 	mov	@r0,ar3
                    0631   1990 	C$fb_app_rollo10.c$444$6$20 ==.
                           1991 ;	..\fb_app_rollo10.c:444: timerstate[objno]=0x02;
   083F EF                 1992 	mov	a,r7
   0840 24 34              1993 	add	a,#_timerstate
   0842 F8                 1994 	mov	r0,a
   0843 76 02              1995 	mov	@r0,#0x02
   0845                    1996 00133$:
                    0637   1997 	C$fb_app_rollo10.c$447$4$18 ==.
                           1998 ;	..\fb_app_rollo10.c:447: if (!(kwin&0x33)){	//wenn stillstand, dann move
   0845 A8 08              1999 	mov	r0,_bp
   0847 08                 2000 	inc	r0
   0848 E6                 2001 	mov	a,@r0
   0849 54 33              2002 	anl	a,#0x33
   084B 70 35              2003 	jnz	00137$
                    063F   2004 	C$fb_app_rollo10.c$448$5$21 ==.
                           2005 ;	..\fb_app_rollo10.c:448: kwout=kwin|0x20;// kanal setzen
   084D A8 08              2006 	mov	r0,_bp
   084F 08                 2007 	inc	r0
   0850 74 20              2008 	mov	a,#0x20
   0852 46                 2009 	orl	a,@r0
   0853 FD                 2010 	mov	r5,a
                    0646   2011 	C$fb_app_rollo10.c$451$5$21 ==.
                           2012 ;	..\fb_app_rollo10.c:451: timerbase[objno-4]=0; 
   0854 EF                 2013 	mov	a,r7
   0855 24 FC              2014 	add	a,#0xFC
   0857 FE                 2015 	mov	r6,a
   0858 24 10              2016 	add	a,#_timerbase
   085A F8                 2017 	mov	r0,a
   085B 76 00              2018 	mov	@r0,#0x00
                    064F   2019 	C$fb_app_rollo10.c$452$5$21 ==.
                           2020 ;	..\fb_app_rollo10.c:452: timercnt[objno-4]=0;
   085D EE                 2021 	mov	a,r6
   085E 24 24              2022 	add	a,#_timercnt
   0860 F8                 2023 	mov	r0,a
   0861 76 00              2024 	mov	@r0,#0x00
                    0655   2025 	C$fb_app_rollo10.c$453$5$21 ==.
                           2026 ;	..\fb_app_rollo10.c:453: timerstate[objno-4]=0;
   0863 EE                 2027 	mov	a,r6
   0864 24 34              2028 	add	a,#_timerstate
   0866 F8                 2029 	mov	r0,a
   0867 76 00              2030 	mov	@r0,#0x00
                    065B   2031 	C$fb_app_rollo10.c$454$5$21 ==.
                           2032 ;	..\fb_app_rollo10.c:454: if (!lz_ue){
   0869 A8 08              2033 	mov	r0,_bp
   086B 08                 2034 	inc	r0
   086C 08                 2035 	inc	r0
   086D E6                 2036 	mov	a,@r0
   086E 70 12              2037 	jnz	00137$
                    0662   2038 	C$fb_app_rollo10.c$456$6$22 ==.
                           2039 ;	..\fb_app_rollo10.c:456: timerbase[objno]=delay_target;
   0870 EF                 2040 	mov	a,r7
   0871 24 10              2041 	add	a,#_timerbase
   0873 F8                 2042 	mov	r0,a
   0874 A6 04              2043 	mov	@r0,ar4
                    0668   2044 	C$fb_app_rollo10.c$457$6$22 ==.
                           2045 ;	..\fb_app_rollo10.c:457: timercnt[objno]=faktor;
   0876 EF                 2046 	mov	a,r7
   0877 24 24              2047 	add	a,#_timercnt
   0879 F8                 2048 	mov	r0,a
   087A A6 03              2049 	mov	@r0,ar3
                    066E   2050 	C$fb_app_rollo10.c$458$6$22 ==.
                           2051 ;	..\fb_app_rollo10.c:458: timerstate[objno]=0x02;
   087C EF                 2052 	mov	a,r7
   087D 24 34              2053 	add	a,#_timerstate
   087F F8                 2054 	mov	r0,a
   0880 76 02              2055 	mov	@r0,#0x02
   0882                    2056 00137$:
                    0674   2057 	C$fb_app_rollo10.c$461$4$18 ==.
                           2058 ;	..\fb_app_rollo10.c:461: if (kwin&0x11){					// wenn fahrt in andere richtung
   0882 A8 08              2059 	mov	r0,_bp
   0884 08                 2060 	inc	r0
   0885 E6                 2061 	mov	a,@r0
   0886 54 11              2062 	anl	a,#0x11
   0888 60 51              2063 	jz	00147$
                    067C   2064 	C$fb_app_rollo10.c$462$5$23 ==.
                           2065 ;	..\fb_app_rollo10.c:462: set_pause(objno, 0x06);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
   088A C0 07              2066 	push	ar7
   088C C0 04              2067 	push	ar4
   088E C0 03              2068 	push	ar3
   0890 74 06              2069 	mov	a,#0x06
   0892 C0 E0              2070 	push	acc
   0894 8F 82              2071 	mov	dpl,r7
   0896 12 0B EC           2072 	lcall	_set_pause
   0899 15 81              2073 	dec	sp
   089B D0 03              2074 	pop	ar3
   089D D0 04              2075 	pop	ar4
   089F D0 07              2076 	pop	ar7
                    0693   2077 	C$fb_app_rollo10.c$463$5$23 ==.
                           2078 ;	..\fb_app_rollo10.c:463: kwout=kwin|0x20;
   08A1 A8 08              2079 	mov	r0,_bp
   08A3 08                 2080 	inc	r0
   08A4 74 20              2081 	mov	a,#0x20
   08A6 46                 2082 	orl	a,@r0
   08A7 FD                 2083 	mov	r5,a
                    069A   2084 	C$fb_app_rollo10.c$464$5$23 ==.
                           2085 ;	..\fb_app_rollo10.c:464: kwout=kwout&0xEF;
   08A8 53 05 EF           2086 	anl	ar5,#0xEF
                    069D   2087 	C$fb_app_rollo10.c$466$5$23 ==.
                           2088 ;	..\fb_app_rollo10.c:466: timerbase[objno-4]=0; // kurzzeit löschen
   08AB EF                 2089 	mov	a,r7
   08AC 24 FC              2090 	add	a,#0xFC
   08AE FE                 2091 	mov	r6,a
   08AF 24 10              2092 	add	a,#_timerbase
   08B1 F8                 2093 	mov	r0,a
   08B2 76 00              2094 	mov	@r0,#0x00
                    06A6   2095 	C$fb_app_rollo10.c$467$5$23 ==.
                           2096 ;	..\fb_app_rollo10.c:467: timercnt[objno-4]=0;
   08B4 EE                 2097 	mov	a,r6
   08B5 24 24              2098 	add	a,#_timercnt
   08B7 F8                 2099 	mov	r0,a
   08B8 76 00              2100 	mov	@r0,#0x00
                    06AC   2101 	C$fb_app_rollo10.c$468$5$23 ==.
                           2102 ;	..\fb_app_rollo10.c:468: timerstate[objno-4]=0;
   08BA EE                 2103 	mov	a,r6
   08BB 24 34              2104 	add	a,#_timerstate
   08BD F8                 2105 	mov	r0,a
   08BE 76 00              2106 	mov	@r0,#0x00
                    06B2   2107 	C$fb_app_rollo10.c$469$5$23 ==.
                           2108 ;	..\fb_app_rollo10.c:469: if (!lz_ue){
   08C0 A8 08              2109 	mov	r0,_bp
   08C2 08                 2110 	inc	r0
   08C3 08                 2111 	inc	r0
   08C4 E6                 2112 	mov	a,@r0
   08C5 70 14              2113 	jnz	00147$
                    06B9   2114 	C$fb_app_rollo10.c$471$6$24 ==.
                           2115 ;	..\fb_app_rollo10.c:471: timerbase[objno]=delay_target & 0x7F;// timer run des langzeit löschen
   08C7 EF                 2116 	mov	a,r7
   08C8 24 10              2117 	add	a,#_timerbase
   08CA F9                 2118 	mov	r1,a
   08CB 74 7F              2119 	mov	a,#0x7F
   08CD 5C                 2120 	anl	a,r4
   08CE F7                 2121 	mov	@r1,a
                    06C1   2122 	C$fb_app_rollo10.c$472$6$24 ==.
                           2123 ;	..\fb_app_rollo10.c:472: timercnt[objno]=faktor;
   08CF EF                 2124 	mov	a,r7
   08D0 24 24              2125 	add	a,#_timercnt
   08D2 F8                 2126 	mov	r0,a
   08D3 A6 03              2127 	mov	@r0,ar3
                    06C7   2128 	C$fb_app_rollo10.c$473$6$24 ==.
                           2129 ;	..\fb_app_rollo10.c:473: timerstate[objno]=0x02;
   08D5 EF                 2130 	mov	a,r7
   08D6 24 34              2131 	add	a,#_timerstate
   08D8 F8                 2132 	mov	r0,a
   08D9 76 02              2133 	mov	@r0,#0x02
   08DB                    2134 00147$:
                    06CD   2135 	C$fb_app_rollo10.c$482$2$2 ==.
                           2136 ;	..\fb_app_rollo10.c:482: kwin=kwout;
   08DB A8 08              2137 	mov	r0,_bp
   08DD 08                 2138 	inc	r0
   08DE A6 05              2139 	mov	@r0,ar5
                    06D2   2140 	C$fb_app_rollo10.c$483$2$2 ==.
                           2141 ;	..\fb_app_rollo10.c:483: if (objno<=7){
   08E0 EF                 2142 	mov	a,r7
   08E1 24 F8              2143 	add	a,#0xff - 0x07
   08E3 40 49              2144 	jc	00157$
                    06D7   2145 	C$fb_app_rollo10.c$484$3$25 ==.
                           2146 ;	..\fb_app_rollo10.c:484: tmp=timerstate[((objno & 0x03)+11)]& 0x07;
   08E5 74 03              2147 	mov	a,#0x03
   08E7 5F                 2148 	anl	a,r7
   08E8 24 0B              2149 	add	a,#0x0B
   08EA 24 34              2150 	add	a,#_timerstate
   08EC F9                 2151 	mov	r1,a
   08ED 87 06              2152 	mov	ar6,@r1
   08EF 53 06 07           2153 	anl	ar6,#0x07
                    06E4   2154 	C$fb_app_rollo10.c$486$3$25 ==.
                           2155 ;	..\fb_app_rollo10.c:486: if ((tmp<4)&& (tmp & (kwout>>4) & 0x03)){
   08F2 BE 04 00           2156 	cjne	r6,#0x04,00233$
   08F5                    2157 00233$:
   08F5 50 23              2158 	jnc	00149$
   08F7 ED                 2159 	mov	a,r5
   08F8 C4                 2160 	swap	a
   08F9 54 0F              2161 	anl	a,#0x0F
   08FB FC                 2162 	mov	r4,a
   08FC 5E                 2163 	anl	a,r6
   08FD 54 03              2164 	anl	a,#0x03
   08FF 60 19              2165 	jz	00149$
                    06F3   2166 	C$fb_app_rollo10.c$488$4$26 ==.
                           2167 ;	..\fb_app_rollo10.c:488: timerbase[(objno&0x03)+11]=0; 
   0901 74 03              2168 	mov	a,#0x03
   0903 5F                 2169 	anl	a,r7
   0904 24 0B              2170 	add	a,#0x0B
   0906 FC                 2171 	mov	r4,a
   0907 24 10              2172 	add	a,#_timerbase
   0909 F8                 2173 	mov	r0,a
   090A 76 00              2174 	mov	@r0,#0x00
                    06FE   2175 	C$fb_app_rollo10.c$489$4$26 ==.
                           2176 ;	..\fb_app_rollo10.c:489: timercnt[(objno&0x03)+11]=0;//gleiche Richtung: Pause löschen
   090C EC                 2177 	mov	a,r4
   090D 24 24              2178 	add	a,#_timercnt
   090F F8                 2179 	mov	r0,a
   0910 76 00              2180 	mov	@r0,#0x00
                    0704   2181 	C$fb_app_rollo10.c$490$4$26 ==.
                           2182 ;	..\fb_app_rollo10.c:490: timerstate[(objno&0x03)+11]=0;
   0912 EC                 2183 	mov	a,r4
   0913 24 34              2184 	add	a,#_timerstate
   0915 F8                 2185 	mov	r0,a
   0916 76 00              2186 	mov	@r0,#0x00
                    070A   2187 	C$fb_app_rollo10.c$491$4$26 ==.
                           2188 ;	..\fb_app_rollo10.c:491: tmp=0;
   0918 7E 00              2189 	mov	r6,#0x00
   091A                    2190 00149$:
                    070C   2191 	C$fb_app_rollo10.c$494$3$25 ==.
                           2192 ;	..\fb_app_rollo10.c:494: if(tmp & 0x04){//wenn Pause wegen umschalten läuft,Kanal "ist" löschen.
   091A EE                 2193 	mov	a,r6
   091B 30 E2 05           2194 	jnb	acc.2,00154$
                    0710   2195 	C$fb_app_rollo10.c$496$4$27 ==.
                           2196 ;	..\fb_app_rollo10.c:496: kwout=kwout&0xF0;
   091E 53 05 F0           2197 	anl	ar5,#0xF0
   0921 80 0B              2198 	sjmp	00157$
   0923                    2199 00154$:
                    0715   2200 	C$fb_app_rollo10.c$499$4$28 ==.
                           2201 ;	..\fb_app_rollo10.c:499: if(!(tmp)){
   0923 EE                 2202 	mov	a,r6
   0924 70 08              2203 	jnz	00157$
                    0718   2204 	C$fb_app_rollo10.c$500$5$29 ==.
                           2205 ;	..\fb_app_rollo10.c:500: kwout=kwin>>4;//wenn keiene Pause Läuft, dann kanal "soll" in "ist" kopieren
   0926 A8 08              2206 	mov	r0,_bp
   0928 08                 2207 	inc	r0
   0929 E6                 2208 	mov	a,@r0
   092A C4                 2209 	swap	a
   092B 54 0F              2210 	anl	a,#0x0F
   092D FD                 2211 	mov	r5,a
   092E                    2212 00157$:
                    0720   2213 	C$fb_app_rollo10.c$506$2$2 ==.
                           2214 ;	..\fb_app_rollo10.c:506: kanal[objno&0x03]=kwout;
   092E 74 03              2215 	mov	a,#0x03
   0930 5F                 2216 	anl	a,r7
   0931 24 47              2217 	add	a,#_kanal
   0933 F8                 2218 	mov	r0,a
   0934 A6 05              2219 	mov	@r0,ar5
                    0728   2220 	C$fb_app_rollo10.c$507$2$2 ==.
                           2221 ;	..\fb_app_rollo10.c:507: portchanged=1;
   0936 D2 00              2222 	setb	_portchanged
   0938                    2223 00162$:
   0938 85 08 81           2224 	mov	sp,_bp
   093B D0 08              2225 	pop	_bp
                    072F   2226 	C$fb_app_rollo10.c$511$2$1 ==.
                    072F   2227 	XG$object_schalten$0$0 ==.
   093D 22                 2228 	ret
                           2229 ;------------------------------------------------------------
                           2230 ;Allocation info for local variables in function 'delay_timer'
                           2231 ;------------------------------------------------------------
                           2232 ;objno                     Allocated to registers r7 
                           2233 ;delay_state               Allocated to registers r6 
                           2234 ;m                         Allocated to registers r5 
                           2235 ;timerflags                Allocated to registers r6 r7 
                           2236 ;------------------------------------------------------------
                    0730   2237 	G$delay_timer$0$0 ==.
                    0730   2238 	C$fb_app_rollo10.c$516$2$1 ==.
                           2239 ;	..\fb_app_rollo10.c:516: void delay_timer(void)	// zählt alle 65ms die Variable Timer hoch und prüft Queue
                           2240 ;	-----------------------------------------
                           2241 ;	 function delay_timer
                           2242 ;	-----------------------------------------
   093E                    2243 _delay_timer:
                    0730   2244 	C$fb_app_rollo10.c$525$1$1 ==.
                           2245 ;	..\fb_app_rollo10.c:525: RTCCON=0x61;		// RTC Flag löschen
   093E 75 D1 61           2246 	mov	_RTCCON,#0x61
                    0733   2247 	C$fb_app_rollo10.c$527$1$1 ==.
                           2248 ;	..\fb_app_rollo10.c:527: timer++;
   0941 74 01              2249 	mov	a,#0x01
   0943 25 09              2250 	add	a,_timer
   0945 F5 09              2251 	mov	_timer,a
   0947 E4                 2252 	clr	a
   0948 35 0A              2253 	addc	a,(_timer + 1)
   094A F5 0A              2254 	mov	(_timer + 1),a
                    073E   2255 	C$fb_app_rollo10.c$528$1$1 ==.
                           2256 ;	..\fb_app_rollo10.c:528: timerflags = timer&(~(timer-1));
   094C E5 09              2257 	mov	a,_timer
   094E 24 FF              2258 	add	a,#0xFF
   0950 FE                 2259 	mov	r6,a
   0951 E5 0A              2260 	mov	a,(_timer + 1)
   0953 34 FF              2261 	addc	a,#0xFF
   0955 FF                 2262 	mov	r7,a
   0956 EE                 2263 	mov	a,r6
   0957 F4                 2264 	cpl	a
   0958 FE                 2265 	mov	r6,a
   0959 EF                 2266 	mov	a,r7
   095A F4                 2267 	cpl	a
   095B FF                 2268 	mov	r7,a
   095C E5 09              2269 	mov	a,_timer
   095E 52 06              2270 	anl	ar6,a
   0960 E5 0A              2271 	mov	a,(_timer + 1)
   0962 52 07              2272 	anl	ar7,a
                    0756   2273 	C$fb_app_rollo10.c$531$4$4 ==.
                           2274 ;	..\fb_app_rollo10.c:531: for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
   0964 7D 00              2275 	mov	r5,#0x00
   0966                    2276 00138$:
   0966 BD 10 00           2277 	cjne	r5,#0x10,00173$
   0969                    2278 00173$:
   0969 50 40              2279 	jnc	00141$
                    075D   2280 	C$fb_app_rollo10.c$533$2$2 ==.
                           2281 ;	..\fb_app_rollo10.c:533: if(timerbase[m]& 0x80){// wenn run-bit gesetzt
   096B ED                 2282 	mov	a,r5
   096C 24 10              2283 	add	a,#_timerbase
   096E F9                 2284 	mov	r1,a
   096F E7                 2285 	mov	a,@r1
   0970 FC                 2286 	mov	r4,a
   0971 30 E7 34           2287 	jnb	acc.7,00140$
                    0766   2288 	C$fb_app_rollo10.c$534$3$3 ==.
                           2289 ;	..\fb_app_rollo10.c:534: if((timerbase[m]==0x82)||(timerflags & (timerflagmask[timerbase[m]&0x7f]))){// wenn das flag mit der gespeicherten base übereinstimmt						
   0974 ED                 2290 	mov	a,r5
   0975 24 10              2291 	add	a,#_timerbase
   0977 F9                 2292 	mov	r1,a
   0978 87 04              2293 	mov	ar4,@r1
   097A BC 82 02           2294 	cjne	r4,#0x82,00176$
   097D 80 1E              2295 	sjmp	00103$
   097F                    2296 00176$:
   097F ED                 2297 	mov	a,r5
   0980 24 10              2298 	add	a,#_timerbase
   0982 F9                 2299 	mov	r1,a
   0983 87 04              2300 	mov	ar4,@r1
   0985 53 04 7F           2301 	anl	ar4,#0x7F
   0988 EC                 2302 	mov	a,r4
   0989 2C                 2303 	add	a,r4
   098A FB                 2304 	mov	r3,a
   098B 90 17 CA           2305 	mov	dptr,#_timerflagmask
   098E 93                 2306 	movc	a,@a+dptr
   098F CB                 2307 	xch	a,r3
   0990 A3                 2308 	inc	dptr
   0991 93                 2309 	movc	a,@a+dptr
   0992 FC                 2310 	mov	r4,a
   0993 EE                 2311 	mov	a,r6
   0994 52 03              2312 	anl	ar3,a
   0996 EF                 2313 	mov	a,r7
   0997 52 04              2314 	anl	ar4,a
   0999 EB                 2315 	mov	a,r3
   099A 4C                 2316 	orl	a,r4
   099B 60 0B              2317 	jz	00140$
   099D                    2318 00103$:
                    078F   2319 	C$fb_app_rollo10.c$535$4$4 ==.
                           2320 ;	..\fb_app_rollo10.c:535: if (timercnt[m]>0x00){// wenn der counter läuft...
   099D ED                 2321 	mov	a,r5
   099E 24 24              2322 	add	a,#_timercnt
   09A0 F9                 2323 	mov	r1,a
   09A1 E7                 2324 	mov	a,@r1
   09A2 FC                 2325 	mov	r4,a
   09A3 60 03              2326 	jz	00140$
                    0797   2327 	C$fb_app_rollo10.c$536$5$5 ==.
                           2328 ;	..\fb_app_rollo10.c:536: timercnt[m]=timercnt[m]-1;// den timer [m]decrementieren
   09A5 EC                 2329 	mov	a,r4
   09A6 14                 2330 	dec	a
   09A7 F7                 2331 	mov	@r1,a
   09A8                    2332 00140$:
                    079A   2333 	C$fb_app_rollo10.c$531$1$1 ==.
                           2334 ;	..\fb_app_rollo10.c:531: for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
   09A8 0D                 2335 	inc	r5
   09A9 80 BB              2336 	sjmp	00138$
   09AB                    2337 00141$:
                    079D   2338 	C$fb_app_rollo10.c$547$5$14 ==.
                           2339 ;	..\fb_app_rollo10.c:547: for(objno=0;objno<=15;objno++) {
   09AB 7F 00              2340 	mov	r7,#0x00
   09AD                    2341 00142$:
   09AD EF                 2342 	mov	a,r7
   09AE 24 F0              2343 	add	a,#0xff - 0x0F
   09B0 50 03              2344 	jnc	00179$
   09B2 02 0A A7           2345 	ljmp	00145$
   09B5                    2346 00179$:
                    07A7   2347 	C$fb_app_rollo10.c$548$2$6 ==.
                           2348 ;	..\fb_app_rollo10.c:548: delay_state=timerstate[objno];			//status des timer-records
   09B5 EF                 2349 	mov	a,r7
   09B6 24 34              2350 	add	a,#_timerstate
   09B8 F9                 2351 	mov	r1,a
                    07AB   2352 	C$fb_app_rollo10.c$549$2$6 ==.
                           2353 ;	..\fb_app_rollo10.c:549: if(delay_state!=0x00) {					// 0x00 = delay Eintrag ist leer   
   09B9 E7                 2354 	mov	a,@r1
   09BA FE                 2355 	mov	r6,a
   09BB 70 03              2356 	jnz	00180$
   09BD 02 0A A3           2357 	ljmp	00144$
   09C0                    2358 00180$:
                    07B2   2359 	C$fb_app_rollo10.c$550$3$7 ==.
                           2360 ;	..\fb_app_rollo10.c:550: if(timercnt[objno]==0 && (timerbase[objno]&0x80)) { 	// wenn der cnt null und run=1, also zeit ist abgelaufen...
   09C0 EF                 2361 	mov	a,r7
   09C1 24 24              2362 	add	a,#_timercnt
   09C3 F8                 2363 	mov	r0,a
   09C4 E6                 2364 	mov	a,@r0
   09C5 60 03              2365 	jz	00181$
   09C7 02 0A A3           2366 	ljmp	00144$
   09CA                    2367 00181$:
   09CA EF                 2368 	mov	a,r7
   09CB 24 10              2369 	add	a,#_timerbase
   09CD FD                 2370 	mov	r5,a
   09CE C0 00              2371 	push	ar0
   09D0 A8 05              2372 	mov	r0,ar5
   09D2 86 05              2373 	mov	ar5,@r0
   09D4 D0 00              2374 	pop	ar0
   09D6 ED                 2375 	mov	a,r5
   09D7 20 E7 03           2376 	jb	acc.7,00182$
   09DA 02 0A A3           2377 	ljmp	00144$
   09DD                    2378 00182$:
                    07CF   2379 	C$fb_app_rollo10.c$551$4$8 ==.
                           2380 ;	..\fb_app_rollo10.c:551: if (objno<=7){// wenns ein kurz oder langzeit objekt ist...
   09DD EF                 2381 	mov	a,r7
   09DE 24 F8              2382 	add	a,#0xff - 0x07
   09E0 40 26              2383 	jc	00109$
                    07D4   2384 	C$fb_app_rollo10.c$552$5$9 ==.
                           2385 ;	..\fb_app_rollo10.c:552: timerbase[objno]=0;
   09E2 EF                 2386 	mov	a,r7
   09E3 24 10              2387 	add	a,#_timerbase
   09E5 C0 00              2388 	push	ar0
   09E7 F8                 2389 	mov	r0,a
   09E8 76 00              2390 	mov	@r0,#0x00
   09EA D0 00              2391 	pop	ar0
                    07DE   2392 	C$fb_app_rollo10.c$553$5$9 ==.
                           2393 ;	..\fb_app_rollo10.c:553: timercnt[objno]=0;
                    07DE   2394 	C$fb_app_rollo10.c$554$5$9 ==.
                           2395 ;	..\fb_app_rollo10.c:554: timerstate[objno]=0;
                    07DE   2396 	C$fb_app_rollo10.c$555$5$9 ==.
                           2397 ;	..\fb_app_rollo10.c:555: kanal[objno&0x03]=0x00;
   09EC E4                 2398 	clr	a
   09ED F6                 2399 	mov	@r0,a
   09EE F7                 2400 	mov	@r1,a
   09EF 74 03              2401 	mov	a,#0x03
   09F1 5F                 2402 	anl	a,r7
   09F2 24 47              2403 	add	a,#_kanal
   09F4 F8                 2404 	mov	r0,a
   09F5 76 00              2405 	mov	@r0,#0x00
                    07E9   2406 	C$fb_app_rollo10.c$556$5$9 ==.
                           2407 ;	..\fb_app_rollo10.c:556: set_pause(objno,(delay_state));// einsch. verz "pause" für eventuelle Fahrt in gegenrichtung
   09F7 C0 07              2408 	push	ar7
   09F9 C0 06              2409 	push	ar6
   09FB C0 06              2410 	push	ar6
   09FD 8F 82              2411 	mov	dpl,r7
   09FF 12 0B EC           2412 	lcall	_set_pause
   0A02 15 81              2413 	dec	sp
   0A04 D0 06              2414 	pop	ar6
   0A06 D0 07              2415 	pop	ar7
   0A08                    2416 00109$:
                    07FA   2417 	C$fb_app_rollo10.c$559$4$8 ==.
                           2418 ;	..\fb_app_rollo10.c:559: if (objno==9 ){	//Sicherheit 1
   0A08 BF 09 1A           2419 	cjne	r7,#0x09,00113$
                    07FD   2420 	C$fb_app_rollo10.c$560$5$10 ==.
                           2421 ;	..\fb_app_rollo10.c:560: if (delay_state == 0x01){
   0A0B BE 01 17           2422 	cjne	r6,#0x01,00113$
                    0800   2423 	C$fb_app_rollo10.c$561$6$11 ==.
                           2424 ;	..\fb_app_rollo10.c:561: timerstate[9]=0x02;// wenn ziel erreicht in delrec sichern
   0A0E 75 3D 02           2425 	mov	(_timerstate + 0x0009),#0x02
                    0803   2426 	C$fb_app_rollo10.c$562$6$11 ==.
                           2427 ;	..\fb_app_rollo10.c:562: Sobject_schalten(48,1);// und Sicherheitsobjekt über bypass schalten
   0A11 C0 07              2428 	push	ar7
   0A13 C0 06              2429 	push	ar6
   0A15 74 01              2430 	mov	a,#0x01
   0A17 C0 E0              2431 	push	acc
   0A19 75 82 30           2432 	mov	dpl,#0x30
   0A1C 12 03 CA           2433 	lcall	_Sobject_schalten
   0A1F 15 81              2434 	dec	sp
   0A21 D0 06              2435 	pop	ar6
   0A23 D0 07              2436 	pop	ar7
   0A25                    2437 00113$:
                    0817   2438 	C$fb_app_rollo10.c$566$4$8 ==.
                           2439 ;	..\fb_app_rollo10.c:566: if (objno==10 ){	//Sicherheit 2
   0A25 BF 0A 1A           2440 	cjne	r7,#0x0A,00117$
                    081A   2441 	C$fb_app_rollo10.c$567$5$12 ==.
                           2442 ;	..\fb_app_rollo10.c:567: if (delay_state == 0x01){
   0A28 BE 01 17           2443 	cjne	r6,#0x01,00117$
                    081D   2444 	C$fb_app_rollo10.c$568$6$13 ==.
                           2445 ;	..\fb_app_rollo10.c:568: timerstate[10]=0x02;// wenn ziel erreicht in delrec sichern
   0A2B 75 3E 02           2446 	mov	(_timerstate + 0x000a),#0x02
                    0820   2447 	C$fb_app_rollo10.c$569$6$13 ==.
                           2448 ;	..\fb_app_rollo10.c:569: Sobject_schalten(49,1);// und Sicherheitsobjekt über bypass schalten
   0A2E C0 07              2449 	push	ar7
   0A30 C0 06              2450 	push	ar6
   0A32 74 01              2451 	mov	a,#0x01
   0A34 C0 E0              2452 	push	acc
   0A36 75 82 31           2453 	mov	dpl,#0x31
   0A39 12 03 CA           2454 	lcall	_Sobject_schalten
   0A3C 15 81              2455 	dec	sp
   0A3E D0 06              2456 	pop	ar6
   0A40 D0 07              2457 	pop	ar7
   0A42                    2458 00117$:
                    0834   2459 	C$fb_app_rollo10.c$573$4$8 ==.
                           2460 ;	..\fb_app_rollo10.c:573: if ((objno>=11) && (objno<=14)){// die Pausezeit der Kanaele
   0A42 BF 0B 00           2461 	cjne	r7,#0x0B,00192$
   0A45                    2462 00192$:
   0A45 40 3D              2463 	jc	00121$
   0A47 EF                 2464 	mov	a,r7
   0A48 24 F1              2465 	add	a,#0xff - 0x0E
   0A4A 40 38              2466 	jc	00121$
                    083E   2467 	C$fb_app_rollo10.c$574$5$14 ==.
                           2468 ;	..\fb_app_rollo10.c:574: kanal[objno-11]=kanal[objno-11]>>4;			// die oberen 4 bit des kanals sind die neue value.
   0A4C EF                 2469 	mov	a,r7
   0A4D 24 F5              2470 	add	a,#0xF5
   0A4F 24 47              2471 	add	a,#_kanal
   0A51 F9                 2472 	mov	r1,a
   0A52 E7                 2473 	mov	a,@r1
   0A53 C4                 2474 	swap	a
   0A54 54 0F              2475 	anl	a,#0x0F
   0A56 FD                 2476 	mov	r5,a
   0A57 F7                 2477 	mov	@r1,a
                    084A   2478 	C$fb_app_rollo10.c$575$5$14 ==.
                           2479 ;	..\fb_app_rollo10.c:575: timerbase[objno]=0;
   0A58 EF                 2480 	mov	a,r7
   0A59 24 10              2481 	add	a,#_timerbase
   0A5B F8                 2482 	mov	r0,a
   0A5C 76 00              2483 	mov	@r0,#0x00
                    0850   2484 	C$fb_app_rollo10.c$576$5$14 ==.
                           2485 ;	..\fb_app_rollo10.c:576: timercnt[objno]=0;			//timer loeschen
   0A5E EF                 2486 	mov	a,r7
   0A5F 24 24              2487 	add	a,#_timercnt
   0A61 F8                 2488 	mov	r0,a
   0A62 76 00              2489 	mov	@r0,#0x00
                    0856   2490 	C$fb_app_rollo10.c$577$5$14 ==.
                           2491 ;	..\fb_app_rollo10.c:577: timerstate[objno]=0;
   0A64 EF                 2492 	mov	a,r7
   0A65 24 34              2493 	add	a,#_timerstate
   0A67 F8                 2494 	mov	r0,a
   0A68 76 00              2495 	mov	@r0,#0x00
                    085C   2496 	C$fb_app_rollo10.c$578$5$14 ==.
                           2497 ;	..\fb_app_rollo10.c:578: if(timerstate[objno-7])timerbase[objno-7]|=0x80;// timer run-bit des zugehörigen Langzeitobjektes setzen
   0A6A EF                 2498 	mov	a,r7
   0A6B 24 F9              2499 	add	a,#0xF9
   0A6D 24 34              2500 	add	a,#_timerstate
   0A6F F9                 2501 	mov	r1,a
   0A70 E7                 2502 	mov	a,@r1
   0A71 60 11              2503 	jz	00121$
   0A73 EF                 2504 	mov	a,r7
   0A74 24 F9              2505 	add	a,#0xF9
   0A76 FD                 2506 	mov	r5,a
   0A77 24 10              2507 	add	a,#_timerbase
   0A79 F9                 2508 	mov	r1,a
   0A7A ED                 2509 	mov	a,r5
   0A7B 24 10              2510 	add	a,#_timerbase
   0A7D F8                 2511 	mov	r0,a
   0A7E 86 05              2512 	mov	ar5,@r0
   0A80 74 80              2513 	mov	a,#0x80
   0A82 4D                 2514 	orl	a,r5
   0A83 F7                 2515 	mov	@r1,a
   0A84                    2516 00121$:
                    0876   2517 	C$fb_app_rollo10.c$580$4$8 ==.
                           2518 ;	..\fb_app_rollo10.c:580: if (objno>=15){// handmode kurz/langtele + einschaltverz + ausschaltverz
   0A84 BF 0F 00           2519 	cjne	r7,#0x0F,00196$
   0A87                    2520 00196$:
   0A87 40 18              2521 	jc	00130$
                    087B   2522 	C$fb_app_rollo10.c$582$5$15 ==.
                           2523 ;	..\fb_app_rollo10.c:582: if (delay_state == 0x12) timerstate[15]=0x22; // wenn ziel 2 erreicht in delrec sichern
   0A89 BE 12 03           2524 	cjne	r6,#0x12,00124$
   0A8C 75 43 22           2525 	mov	(_timerstate + 0x000f),#0x22
   0A8F                    2526 00124$:
                    0881   2527 	C$fb_app_rollo10.c$583$5$15 ==.
                           2528 ;	..\fb_app_rollo10.c:583: if (delay_state == 0x01){
   0A8F BE 01 09           2529 	cjne	r6,#0x01,00126$
                    0884   2530 	C$fb_app_rollo10.c$584$6$16 ==.
                           2531 ;	..\fb_app_rollo10.c:584: timerbase[15]=0x80 + 3;
   0A92 75 1F 83           2532 	mov	(_timerbase + 0x000f),#0x83
                    0887   2533 	C$fb_app_rollo10.c$585$6$16 ==.
                           2534 ;	..\fb_app_rollo10.c:585: timerstate[15]=0x12;
   0A95 75 43 12           2535 	mov	(_timerstate + 0x000f),#0x12
                    088A   2536 	C$fb_app_rollo10.c$586$6$16 ==.
                           2537 ;	..\fb_app_rollo10.c:586: timercnt[15]= 20;// wenn ziel 1 erreicht in delrec sichern und restzeit fuer ziel 2 schreiben
   0A98 75 33 14           2538 	mov	(_timercnt + 0x000f),#0x14
   0A9B                    2539 00126$:
                    088D   2540 	C$fb_app_rollo10.c$589$5$15 ==.
                           2541 ;	..\fb_app_rollo10.c:589: if (delay_state == 0x04) timerstate[15]= 0x08;// wenn ziel erreicht in delrec sichern
   0A9B BE 04 03           2542 	cjne	r6,#0x04,00130$
   0A9E 75 43 08           2543 	mov	(_timerstate + 0x000f),#0x08
   0AA1                    2544 00130$:
                    0893   2545 	C$fb_app_rollo10.c$591$4$8 ==.
                           2546 ;	..\fb_app_rollo10.c:591: portchanged=1;
   0AA1 D2 00              2547 	setb	_portchanged
   0AA3                    2548 00144$:
                    0895   2549 	C$fb_app_rollo10.c$547$1$1 ==.
                           2550 ;	..\fb_app_rollo10.c:547: for(objno=0;objno<=15;objno++) {
   0AA3 0F                 2551 	inc	r7
   0AA4 02 09 AD           2552 	ljmp	00142$
   0AA7                    2553 00145$:
                    0899   2554 	C$fb_app_rollo10.c$601$1$1 ==.
                           2555 ;	..\fb_app_rollo10.c:601: if (eeprom[0xE5]& 0xC0){
   0AA7 90 1D E5           2556 	mov	dptr,#(_eeprom + 0x00e5)
   0AAA E4                 2557 	clr	a
   0AAB 93                 2558 	movc	a,@a+dptr
   0AAC FF                 2559 	mov	r7,a
   0AAD 54 C0              2560 	anl	a,#0xC0
   0AAF 60 03              2561 	jz	00146$
                    08A3   2562 	C$fb_app_rollo10.c$602$2$17 ==.
                           2563 ;	..\fb_app_rollo10.c:602: handsteuerung();   // Handbetätigung nur jedes 8.mal ausführen
   0AB1 12 0A B5           2564 	lcall	_handsteuerung
   0AB4                    2565 00146$:
                    08A6   2566 	C$fb_app_rollo10.c$606$2$1 ==.
                    08A6   2567 	XG$delay_timer$0$0 ==.
   0AB4 22                 2568 	ret
                           2569 ;------------------------------------------------------------
                           2570 ;Allocation info for local variables in function 'handsteuerung'
                           2571 ;------------------------------------------------------------
                           2572 ;n                         Allocated to registers r6 
                           2573 ;tmph                      Allocated to registers 
                           2574 ;key_pattern               Allocated to registers r7 
                           2575 ;Tasten                    Allocated to registers r7 
                           2576 ;------------------------------------------------------------
                    08A7   2577 	G$handsteuerung$0$0 ==.
                    08A7   2578 	C$fb_app_rollo10.c$681$2$1 ==.
                           2579 ;	..\fb_app_rollo10.c:681: void handsteuerung(void)
                           2580 ;	-----------------------------------------
                           2581 ;	 function handsteuerung
                           2582 ;	-----------------------------------------
   0AB5                    2583 _handsteuerung:
                    08A7   2584 	C$fb_app_rollo10.c$696$1$1 ==.
                           2585 ;	..\fb_app_rollo10.c:696: if((TMOD&0x0F)==0x02 && fb_state==0) {
   0AB5 74 0F              2586 	mov	a,#0x0F
   0AB7 55 89              2587 	anl	a,_TMOD
   0AB9 FF                 2588 	mov	r7,a
   0ABA BF 02 02           2589 	cjne	r7,#0x02,00158$
   0ABD 80 03              2590 	sjmp	00159$
   0ABF                    2591 00158$:
   0ABF 02 0B C0           2592 	ljmp	00137$
   0AC2                    2593 00159$:
   0AC2 E5 77              2594 	mov	a,_fb_state
   0AC4 60 03              2595 	jz	00160$
   0AC6 02 0B C0           2596 	ljmp	00137$
   0AC9                    2597 00160$:
                    08BB   2598 	C$fb_app_rollo10.c$697$2$2 ==.
                           2599 ;	..\fb_app_rollo10.c:697: ET1=0;	
   0AC9 C2 AB              2600 	clr	_IEN0_3
                    08BD   2601 	C$fb_app_rollo10.c$698$2$2 ==.
                           2602 ;	..\fb_app_rollo10.c:698: while(  (!PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen
   0ACB                    2603 00102$:
   0ACB 30 92 FD           2604 	jnb	_P1_2,00102$
   0ACE E5 8A              2605 	mov	a,_TL0
   0AD0 24 8D              2606 	add	a,#0xff - 0x72
   0AD2 40 F7              2607 	jc	00102$
                    08C6   2608 	C$fb_app_rollo10.c$717$2$2 ==.
                           2609 ;	..\fb_app_rollo10.c:717: key_pattern=(0x01<<(delay_toggle&0x07));
   0AD4 74 07              2610 	mov	a,#0x07
   0AD6 55 09              2611 	anl	a,_delay_toggle
   0AD8 FF                 2612 	mov	r7,a
   0AD9 8F F0              2613 	mov	b,r7
   0ADB 05 F0              2614 	inc	b
   0ADD 74 01              2615 	mov	a,#0x01
   0ADF 80 02              2616 	sjmp	00165$
   0AE1                    2617 00163$:
   0AE1 25 E0              2618 	add	a,acc
   0AE3                    2619 00165$:
   0AE3 D5 F0 FB           2620 	djnz	b,00163$
                    08D8   2621 	C$fb_app_rollo10.c$718$2$2 ==.
                           2622 ;	..\fb_app_rollo10.c:718: P0 = ~key_pattern;
   0AE6 FF                 2623 	mov	r7,a
   0AE7 F4                 2624 	cpl	a
   0AE8 F5 80              2625 	mov	_P0,a
                    08DC   2626 	C$fb_app_rollo10.c$719$2$2 ==.
                           2627 ;	..\fb_app_rollo10.c:719: if (!P1_3){
   0AEA 20 93 0C           2628 	jb	_P1_3,00108$
                    08DF   2629 	C$fb_app_rollo10.c$720$3$3 ==.
                           2630 ;	..\fb_app_rollo10.c:720: if(!ledport) ledport=0x08+(delay_toggle&0x07);
   0AED E5 4C              2631 	mov	a,_ledport
   0AEF 70 08              2632 	jnz	00108$
   0AF1 74 07              2633 	mov	a,#0x07
   0AF3 55 09              2634 	anl	a,_delay_toggle
   0AF5 24 08              2635 	add	a,#0x08
   0AF7 F5 4C              2636 	mov	_ledport,a
   0AF9                    2637 00108$:
                    08EB   2638 	C$fb_app_rollo10.c$722$2$2 ==.
                           2639 ;	..\fb_app_rollo10.c:722: P0=oldportbuffer; 
   0AF9 85 0E 80           2640 	mov	_P0,_oldportbuffer
                    08EE   2641 	C$fb_app_rollo10.c$725$2$2 ==.
                           2642 ;	..\fb_app_rollo10.c:725: if (key_pattern==0x80){
   0AFC BF 80 02           2643 	cjne	r7,#0x80,00168$
   0AFF 80 03              2644 	sjmp	00169$
   0B01                    2645 00168$:
   0B01 02 0B C0           2646 	ljmp	00137$
   0B04                    2647 00169$:
                    08F6   2648 	C$fb_app_rollo10.c$726$3$4 ==.
                           2649 ;	..\fb_app_rollo10.c:726: Tasten=ledport;
   0B04 AF 4C              2650 	mov	r7,_ledport
                    08F8   2651 	C$fb_app_rollo10.c$727$3$4 ==.
                           2652 ;	..\fb_app_rollo10.c:727: ledport=0;
   0B06 75 4C 00           2653 	mov	_ledport,#0x00
                    08FB   2654 	C$fb_app_rollo10.c$731$3$4 ==.
                           2655 ;	..\fb_app_rollo10.c:731: if (Tasten & 0x08 ){
   0B09 EF                 2656 	mov	a,r7
   0B0A 30 E3 13           2657 	jnb	acc.3,00124$
                    08FF   2658 	C$fb_app_rollo10.c$732$4$5 ==.
                           2659 ;	..\fb_app_rollo10.c:732: if (!Tval ){// steigende Flanke des Tasters 
   0B0D E5 44              2660 	mov	a,_Tval
   0B0F 60 03              2661 	jz	00171$
   0B11 02 0B A9           2662 	ljmp	00125$
   0B14                    2663 00171$:
                    0906   2664 	C$fb_app_rollo10.c$735$5$6 ==.
                           2665 ;	..\fb_app_rollo10.c:735: timerstate[15]=0x01;
   0B14 75 43 01           2666 	mov	(_timerstate + 0x000f),#0x01
                    0909   2667 	C$fb_app_rollo10.c$736$5$6 ==.
                           2668 ;	..\fb_app_rollo10.c:736: timerbase[15]=0x80 + 2;
   0B17 75 1F 82           2669 	mov	(_timerbase + 0x000f),#0x82
                    090C   2670 	C$fb_app_rollo10.c$737$5$6 ==.
                           2671 ;	..\fb_app_rollo10.c:737: timercnt[15]= 50;
   0B1A 75 33 32           2672 	mov	(_timercnt + 0x000f),#0x32
   0B1D 02 0B A9           2673 	ljmp	00125$
   0B20                    2674 00124$:
                    0912   2675 	C$fb_app_rollo10.c$741$4$7 ==.
                           2676 ;	..\fb_app_rollo10.c:741: if ( Tval & 0x08){ // wenn tasten >7 und Tval <=7 also taste losgelassen...
   0B20 E5 44              2677 	mov	a,_Tval
   0B22 20 E3 03           2678 	jb	acc.3,00172$
   0B25 02 0B A9           2679 	ljmp	00125$
   0B28                    2680 00172$:
                    091A   2681 	C$fb_app_rollo10.c$742$5$8 ==.
                           2682 ;	..\fb_app_rollo10.c:742: if (timerstate[15]&0x20){
   0B28 E5 43              2683 	mov	a,(_timerstate + 0x000f)
   0B2A 30 E5 29           2684 	jnb	acc.5,00115$
                    091F   2685 	C$fb_app_rollo10.c$743$6$9 ==.
                           2686 ;	..\fb_app_rollo10.c:743: handmode = !handmode;
   0B2D B2 02              2687 	cpl	_handmode
                    0921   2688 	C$fb_app_rollo10.c$744$6$9 ==.
                           2689 ;	..\fb_app_rollo10.c:744: timerbase[15]=0;
   0B2F 75 1F 00           2690 	mov	(_timerbase + 0x000f),#0x00
                    0924   2691 	C$fb_app_rollo10.c$745$6$9 ==.
                           2692 ;	..\fb_app_rollo10.c:745: timerstate[15]=0;
   0B32 75 43 00           2693 	mov	(_timerstate + 0x000f),#0x00
                    0927   2694 	C$fb_app_rollo10.c$746$6$9 ==.
                           2695 ;	..\fb_app_rollo10.c:746: timercnt[15]=0;
   0B35 75 33 00           2696 	mov	(_timercnt + 0x000f),#0x00
                    092A   2697 	C$fb_app_rollo10.c$747$6$9 ==.
                           2698 ;	..\fb_app_rollo10.c:747: if (handmode){
   0B38 30 02 14           2699 	jnb	_handmode,00112$
                    092D   2700 	C$fb_app_rollo10.c$748$7$10 ==.
                           2701 ;	..\fb_app_rollo10.c:748: for(n=0;n<=3;n++) kanal[n]=0x00;
   0B3B 7E 00              2702 	mov	r6,#0x00
   0B3D                    2703 00133$:
   0B3D EE                 2704 	mov	a,r6
   0B3E 24 FC              2705 	add	a,#0xff - 0x03
   0B40 40 09              2706 	jc	00136$
   0B42 EE                 2707 	mov	a,r6
   0B43 24 47              2708 	add	a,#_kanal
   0B45 F8                 2709 	mov	r0,a
   0B46 76 00              2710 	mov	@r0,#0x00
   0B48 0E                 2711 	inc	r6
   0B49 80 F2              2712 	sjmp	00133$
   0B4B                    2713 00136$:
                    093D   2714 	C$fb_app_rollo10.c$749$7$10 ==.
                           2715 ;	..\fb_app_rollo10.c:749: portchanged=1;
   0B4B D2 00              2716 	setb	_portchanged
   0B4D 80 07              2717 	sjmp	00115$
   0B4F                    2718 00112$:
                    0941   2719 	C$fb_app_rollo10.c$752$7$11 ==.
                           2720 ;	..\fb_app_rollo10.c:752: sobj_update();
   0B4F C0 07              2721 	push	ar7
   0B51 12 0B C1           2722 	lcall	_sobj_update
   0B54 D0 07              2723 	pop	ar7
   0B56                    2724 00115$:
                    0948   2725 	C$fb_app_rollo10.c$755$5$8 ==.
                           2726 ;	..\fb_app_rollo10.c:755: if (handmode){// wenn handmode aktiv...
   0B56 30 02 47           2727 	jnb	_handmode,00120$
                    094B   2728 	C$fb_app_rollo10.c$756$6$12 ==.
                           2729 ;	..\fb_app_rollo10.c:756: if (timerstate[15]&0x02){// status der zeit=2 also abgelaufen..
   0B59 E5 43              2730 	mov	a,(_timerstate + 0x000f)
   0B5B 30 E1 22           2731 	jnb	acc.1,00117$
                    0950   2732 	C$fb_app_rollo10.c$757$7$13 ==.
                           2733 ;	..\fb_app_rollo10.c:757: object_schalten(((Tval&0x07)>>1)+12,(Tval&0x01==0x01));
   0B5E E5 44              2734 	mov	a,_Tval
   0B60 54 01              2735 	anl	a,#0x01
   0B62 24 FF              2736 	add	a,#0xff
   0B64 92 18              2737 	mov	b0,c
   0B66 74 07              2738 	mov	a,#0x07
   0B68 55 44              2739 	anl	a,_Tval
   0B6A C3                 2740 	clr	c
   0B6B 13                 2741 	rrc	a
   0B6C 24 0C              2742 	add	a,#0x0C
   0B6E F5 82              2743 	mov	dpl,a
   0B70 A2 18              2744 	mov	c,b0
   0B72 92 F0              2745 	mov	b[0],c
   0B74 C0 07              2746 	push	ar7
   0B76 85 F0 23           2747 	mov	bits,b
   0B79 12 05 34           2748 	lcall	_object_schalten
   0B7C D0 07              2749 	pop	ar7
   0B7E 80 20              2750 	sjmp	00120$
   0B80                    2751 00117$:
                    0972   2752 	C$fb_app_rollo10.c$760$7$14 ==.
                           2753 ;	..\fb_app_rollo10.c:760: object_schalten(((Tval&0x07)>>1)+8,(Tval&0x01==0x01));
   0B80 E5 44              2754 	mov	a,_Tval
   0B82 54 01              2755 	anl	a,#0x01
   0B84 24 FF              2756 	add	a,#0xff
   0B86 92 18              2757 	mov	b0,c
   0B88 74 07              2758 	mov	a,#0x07
   0B8A 55 44              2759 	anl	a,_Tval
   0B8C C3                 2760 	clr	c
   0B8D 13                 2761 	rrc	a
   0B8E 24 08              2762 	add	a,#0x08
   0B90 F5 82              2763 	mov	dpl,a
   0B92 A2 18              2764 	mov	c,b0
   0B94 92 F0              2765 	mov	b[0],c
   0B96 C0 07              2766 	push	ar7
   0B98 85 F0 23           2767 	mov	bits,b
   0B9B 12 05 34           2768 	lcall	_object_schalten
   0B9E D0 07              2769 	pop	ar7
   0BA0                    2770 00120$:
                    0992   2771 	C$fb_app_rollo10.c$764$5$8 ==.
                           2772 ;	..\fb_app_rollo10.c:764: timerbase[15]=0x80 + 3;//130ms
   0BA0 75 1F 83           2773 	mov	(_timerbase + 0x000f),#0x83
                    0995   2774 	C$fb_app_rollo10.c$765$5$8 ==.
                           2775 ;	..\fb_app_rollo10.c:765: timerstate[15]=0x04;
   0BA3 75 43 04           2776 	mov	(_timerstate + 0x000f),#0x04
                    0998   2777 	C$fb_app_rollo10.c$766$5$8 ==.
                           2778 ;	..\fb_app_rollo10.c:766: timercnt[15]=116;//=15 Sekunden
   0BA6 75 33 74           2779 	mov	(_timercnt + 0x000f),#0x74
   0BA9                    2780 00125$:
                    099B   2781 	C$fb_app_rollo10.c$769$3$4 ==.
                           2782 ;	..\fb_app_rollo10.c:769: Tval=Tasten;
   0BA9 8F 44              2783 	mov	_Tval,r7
                    099D   2784 	C$fb_app_rollo10.c$771$3$4 ==.
                           2785 ;	..\fb_app_rollo10.c:771: if(timerstate[15]&0x08){
   0BAB E5 43              2786 	mov	a,(_timerstate + 0x000f)
   0BAD 30 E3 0E           2787 	jnb	acc.3,00127$
                    09A2   2788 	C$fb_app_rollo10.c$772$4$15 ==.
                           2789 ;	..\fb_app_rollo10.c:772: handmode=0;//handmode automatisch ausschalten
   0BB0 C2 02              2790 	clr	_handmode
                    09A4   2791 	C$fb_app_rollo10.c$774$4$15 ==.
                           2792 ;	..\fb_app_rollo10.c:774: timerbase[15]=0;
   0BB2 75 1F 00           2793 	mov	(_timerbase + 0x000f),#0x00
                    09A7   2794 	C$fb_app_rollo10.c$775$4$15 ==.
                           2795 ;	..\fb_app_rollo10.c:775: timerstate[15]=0;
   0BB5 75 43 00           2796 	mov	(_timerstate + 0x000f),#0x00
                    09AA   2797 	C$fb_app_rollo10.c$776$4$15 ==.
                           2798 ;	..\fb_app_rollo10.c:776: timercnt[15]=0;
   0BB8 75 33 00           2799 	mov	(_timercnt + 0x000f),#0x00
                    09AD   2800 	C$fb_app_rollo10.c$777$4$15 ==.
                           2801 ;	..\fb_app_rollo10.c:777: sobj_update();
   0BBB 12 0B C1           2802 	lcall	_sobj_update
   0BBE                    2803 00127$:
                    09B0   2804 	C$fb_app_rollo10.c$779$3$4 ==.
                           2805 ;	..\fb_app_rollo10.c:779: ET1=1;
   0BBE D2 AB              2806 	setb	_IEN0_3
   0BC0                    2807 00137$:
                    09B2   2808 	C$fb_app_rollo10.c$782$1$1 ==.
                    09B2   2809 	XG$handsteuerung$0$0 ==.
   0BC0 22                 2810 	ret
                           2811 ;------------------------------------------------------------
                           2812 ;Allocation info for local variables in function 'sobj_update'
                           2813 ;------------------------------------------------------------
                    09B3   2814 	G$sobj_update$0$0 ==.
                    09B3   2815 	C$fb_app_rollo10.c$786$1$1 ==.
                           2816 ;	..\fb_app_rollo10.c:786: void sobj_update(void)
                           2817 ;	-----------------------------------------
                           2818 ;	 function sobj_update
                           2819 ;	-----------------------------------------
   0BC1                    2820 _sobj_update:
                    09B3   2821 	C$fb_app_rollo10.c$788$1$1 ==.
                           2822 ;	..\fb_app_rollo10.c:788: Sobject_schalten(16,read_obj_value(16)&0x01);
   0BC1 75 82 10           2823 	mov	dpl,#0x10
   0BC4 12 02 ED           2824 	lcall	_read_obj_value
   0BC7 AC 82              2825 	mov	r4,dpl
   0BC9 53 04 01           2826 	anl	ar4,#0x01
   0BCC C0 04              2827 	push	ar4
   0BCE 75 82 10           2828 	mov	dpl,#0x10
   0BD1 12 03 CA           2829 	lcall	_Sobject_schalten
   0BD4 15 81              2830 	dec	sp
                    09C8   2831 	C$fb_app_rollo10.c$789$1$1 ==.
                           2832 ;	..\fb_app_rollo10.c:789: Sobject_schalten(17,read_obj_value(17)&0x01);
   0BD6 75 82 11           2833 	mov	dpl,#0x11
   0BD9 12 02 ED           2834 	lcall	_read_obj_value
   0BDC AC 82              2835 	mov	r4,dpl
   0BDE 53 04 01           2836 	anl	ar4,#0x01
   0BE1 C0 04              2837 	push	ar4
   0BE3 75 82 11           2838 	mov	dpl,#0x11
   0BE6 12 03 CA           2839 	lcall	_Sobject_schalten
   0BE9 15 81              2840 	dec	sp
                    09DD   2841 	C$fb_app_rollo10.c$790$1$1 ==.
                    09DD   2842 	XG$sobj_update$0$0 ==.
   0BEB 22                 2843 	ret
                           2844 ;------------------------------------------------------------
                           2845 ;Allocation info for local variables in function 'set_pause'
                           2846 ;------------------------------------------------------------
                           2847 ;Pstate                    Allocated to stack - _bp -3
                           2848 ;objnr                     Allocated to registers r7 
                           2849 ;pause                     Allocated to registers r7 
                           2850 ;pauseobj                  Allocated to registers r6 
                           2851 ;------------------------------------------------------------
                    09DE   2852 	G$set_pause$0$0 ==.
                    09DE   2853 	C$fb_app_rollo10.c$791$1$1 ==.
                           2854 ;	..\fb_app_rollo10.c:791: void set_pause(unsigned char objnr,unsigned char Pstate)// setzt die Pausezeit und traegt Pstate in timerstate[ ] ein
                           2855 ;	-----------------------------------------
                           2856 ;	 function set_pause
                           2857 ;	-----------------------------------------
   0BEC                    2858 _set_pause:
   0BEC C0 08              2859 	push	_bp
   0BEE 85 81 08           2860 	mov	_bp,sp
   0BF1 AF 82              2861 	mov	r7,dpl
                    09E5   2862 	C$fb_app_rollo10.c$794$1$1 ==.
                           2863 ;	..\fb_app_rollo10.c:794: pauseobj=(objnr&0x03)+11;
   0BF3 53 07 03           2864 	anl	ar7,#0x03
   0BF6 74 0B              2865 	mov	a,#0x0B
   0BF8 2F                 2866 	add	a,r7
                    09EB   2867 	C$fb_app_rollo10.c$795$1$1 ==.
                           2868 ;	..\fb_app_rollo10.c:795: timerstate[pauseobj]=Pstate;
   0BF9 FE                 2869 	mov	r6,a
   0BFA 24 34              2870 	add	a,#_timerstate
   0BFC F8                 2871 	mov	r0,a
   0BFD E5 08              2872 	mov	a,_bp
   0BFF 24 FD              2873 	add	a,#0xfd
   0C01 F9                 2874 	mov	r1,a
   0C02 E7                 2875 	mov	a,@r1
   0C03 F6                 2876 	mov	@r0,a
                    09F6   2877 	C$fb_app_rollo10.c$796$1$1 ==.
                           2878 ;	..\fb_app_rollo10.c:796: switch ((eeprom[0xEE]>>((objnr&0x03)<<1))&0x03) { // Dauer zwischen auf und ab
   0C04 90 1D EE           2879 	mov	dptr,#(_eeprom + 0x00ee)
   0C07 E4                 2880 	clr	a
   0C08 93                 2881 	movc	a,@a+dptr
   0C09 FD                 2882 	mov	r5,a
   0C0A E4                 2883 	clr	a
   0C0B CF                 2884 	xch	a,r7
   0C0C 25 E0              2885 	add	a,acc
   0C0E CF                 2886 	xch	a,r7
   0C0F 33                 2887 	rlc	a
   0C10 FC                 2888 	mov	r4,a
   0C11 8F F0              2889 	mov	b,r7
   0C13 05 F0              2890 	inc	b
   0C15 ED                 2891 	mov	a,r5
   0C16 80 02              2892 	sjmp	00112$
   0C18                    2893 00111$:
   0C18 C3                 2894 	clr	c
   0C19 13                 2895 	rrc	a
   0C1A                    2896 00112$:
   0C1A D5 F0 FB           2897 	djnz	b,00111$
   0C1D 54 03              2898 	anl	a,#0x03
   0C1F FF                 2899 	mov	r7,a
   0C20 60 0A              2900 	jz	00101$
   0C22 BF 01 02           2901 	cjne	r7,#0x01,00114$
   0C25 80 09              2902 	sjmp	00102$
   0C27                    2903 00114$:
                    0A19   2904 	C$fb_app_rollo10.c$797$2$2 ==.
                           2905 ;	..\fb_app_rollo10.c:797: case 0:	// 0,5s
   0C27 BF 02 0E           2906 	cjne	r7,#0x02,00104$
   0C2A 80 08              2907 	sjmp	00103$
   0C2C                    2908 00101$:
                    0A1E   2909 	C$fb_app_rollo10.c$798$2$2 ==.
                           2910 ;	..\fb_app_rollo10.c:798: pause=4 ;
   0C2C 7F 04              2911 	mov	r7,#0x04
                    0A20   2912 	C$fb_app_rollo10.c$799$2$2 ==.
                           2913 ;	..\fb_app_rollo10.c:799: break;
                    0A20   2914 	C$fb_app_rollo10.c$800$2$2 ==.
                           2915 ;	..\fb_app_rollo10.c:800: case 1:	// 1s
   0C2E 80 0A              2916 	sjmp	00105$
   0C30                    2917 00102$:
                    0A22   2918 	C$fb_app_rollo10.c$801$2$2 ==.
                           2919 ;	..\fb_app_rollo10.c:801: pause=8 ;
   0C30 7F 08              2920 	mov	r7,#0x08
                    0A24   2921 	C$fb_app_rollo10.c$802$2$2 ==.
                           2922 ;	..\fb_app_rollo10.c:802: break;
                    0A24   2923 	C$fb_app_rollo10.c$803$2$2 ==.
                           2924 ;	..\fb_app_rollo10.c:803: case 2:	// 2s
   0C32 80 06              2925 	sjmp	00105$
   0C34                    2926 00103$:
                    0A26   2927 	C$fb_app_rollo10.c$804$2$2 ==.
                           2928 ;	..\fb_app_rollo10.c:804: pause=16 ;
   0C34 7F 10              2929 	mov	r7,#0x10
                    0A28   2930 	C$fb_app_rollo10.c$805$2$2 ==.
                           2931 ;	..\fb_app_rollo10.c:805: break;
                    0A28   2932 	C$fb_app_rollo10.c$806$2$2 ==.
                           2933 ;	..\fb_app_rollo10.c:806: default:	// 5s
   0C36 80 02              2934 	sjmp	00105$
   0C38                    2935 00104$:
                    0A2A   2936 	C$fb_app_rollo10.c$807$2$2 ==.
                           2937 ;	..\fb_app_rollo10.c:807: pause=39 ;
   0C38 7F 27              2938 	mov	r7,#0x27
                    0A2C   2939 	C$fb_app_rollo10.c$809$1$1 ==.
                           2940 ;	..\fb_app_rollo10.c:809: }
   0C3A                    2941 00105$:
                    0A2C   2942 	C$fb_app_rollo10.c$810$1$1 ==.
                           2943 ;	..\fb_app_rollo10.c:810: timercnt[pauseobj]=pause;
   0C3A EE                 2944 	mov	a,r6
   0C3B 24 24              2945 	add	a,#_timercnt
   0C3D F8                 2946 	mov	r0,a
   0C3E A6 07              2947 	mov	@r0,ar7
                    0A32   2948 	C$fb_app_rollo10.c$811$1$1 ==.
                           2949 ;	..\fb_app_rollo10.c:811: timerbase[pauseobj]= 3 | 0x80;
   0C40 EE                 2950 	mov	a,r6
   0C41 24 10              2951 	add	a,#_timerbase
   0C43 F8                 2952 	mov	r0,a
   0C44 76 83              2953 	mov	@r0,#0x83
   0C46 D0 08              2954 	pop	_bp
                    0A3A   2955 	C$fb_app_rollo10.c$813$1$1 ==.
                    0A3A   2956 	XG$set_pause$0$0 ==.
   0C48 22                 2957 	ret
                           2958 ;------------------------------------------------------------
                           2959 ;Allocation info for local variables in function 'set_entriegeln'
                           2960 ;------------------------------------------------------------
                           2961 ;zeitnr                    Allocated to registers r7 
                           2962 ;svbase                    Allocated to registers r6 
                           2963 ;------------------------------------------------------------
                    0A3B   2964 	G$set_entriegeln$0$0 ==.
                    0A3B   2965 	C$fb_app_rollo10.c$816$1$1 ==.
                           2966 ;	..\fb_app_rollo10.c:816: void set_entriegeln(unsigned char zeitnr)// Setzt die zyklische überwachungszeit
                           2967 ;	-----------------------------------------
                           2968 ;	 function set_entriegeln
                           2969 ;	-----------------------------------------
   0C49                    2970 _set_entriegeln:
   0C49 AF 82              2971 	mov	r7,dpl
                    0A3D   2972 	C$fb_app_rollo10.c$821$1$1 ==.
                           2973 ;	..\fb_app_rollo10.c:821: svbase=eeprom[0xD9]&0x0F;
   0C4B 90 1D D9           2974 	mov	dptr,#(_eeprom + 0x00d9)
   0C4E E4                 2975 	clr	a
   0C4F 93                 2976 	movc	a,@a+dptr
                    0A42   2977 	C$fb_app_rollo10.c$822$1$1 ==.
                           2978 ;	..\fb_app_rollo10.c:822: if(svbase){
   0C50 54 0F              2979 	anl	a,#0x0F
   0C52 FE                 2980 	mov	r6,a
   0C53 60 19              2981 	jz	00102$
                    0A47   2982 	C$fb_app_rollo10.c$823$2$2 ==.
                           2983 ;	..\fb_app_rollo10.c:823: timercnt[zeitnr]=svfaktorarray[svbase];
   0C55 EF                 2984 	mov	a,r7
   0C56 24 24              2985 	add	a,#_timercnt
   0C58 F9                 2986 	mov	r1,a
   0C59 EE                 2987 	mov	a,r6
   0C5A 90 17 D6           2988 	mov	dptr,#_svfaktorarray
   0C5D 93                 2989 	movc	a,@a+dptr
   0C5E FE                 2990 	mov	r6,a
   0C5F F7                 2991 	mov	@r1,a
                    0A52   2992 	C$fb_app_rollo10.c$824$2$2 ==.
                           2993 ;	..\fb_app_rollo10.c:824: timerbase[zeitnr]=5 | 0x80;
   0C60 EF                 2994 	mov	a,r7
   0C61 24 10              2995 	add	a,#_timerbase
   0C63 F8                 2996 	mov	r0,a
   0C64 76 85              2997 	mov	@r0,#0x85
                    0A58   2998 	C$fb_app_rollo10.c$825$2$2 ==.
                           2999 ;	..\fb_app_rollo10.c:825: timerstate[zeitnr]=0x01;
   0C66 EF                 3000 	mov	a,r7
   0C67 24 34              3001 	add	a,#_timerstate
   0C69 F8                 3002 	mov	r0,a
   0C6A 76 01              3003 	mov	@r0,#0x01
   0C6C 80 0C              3004 	sjmp	00104$
   0C6E                    3005 00102$:
                    0A60   3006 	C$fb_app_rollo10.c$828$2$3 ==.
                           3007 ;	..\fb_app_rollo10.c:828: timerbase[zeitnr]=0;
   0C6E EF                 3008 	mov	a,r7
   0C6F 24 10              3009 	add	a,#_timerbase
   0C71 F8                 3010 	mov	r0,a
   0C72 76 00              3011 	mov	@r0,#0x00
                    0A66   3012 	C$fb_app_rollo10.c$829$2$3 ==.
                           3013 ;	..\fb_app_rollo10.c:829: timerstate[zeitnr]=0;
   0C74 EF                 3014 	mov	a,r7
   0C75 24 34              3015 	add	a,#_timerstate
   0C77 F8                 3016 	mov	r0,a
   0C78 76 00              3017 	mov	@r0,#0x00
   0C7A                    3018 00104$:
                    0A6C   3019 	C$fb_app_rollo10.c$832$1$1 ==.
                    0A6C   3020 	XG$set_entriegeln$0$0 ==.
   0C7A 22                 3021 	ret
                           3022 ;------------------------------------------------------------
                           3023 ;Allocation info for local variables in function 'port_schalten'
                           3024 ;------------------------------------------------------------
                           3025 ;kmod                      Allocated to registers r7 
                           3026 ;------------------------------------------------------------
                    0A6D   3027 	G$port_schalten$0$0 ==.
                    0A6D   3028 	C$fb_app_rollo10.c$894$1$1 ==.
                           3029 ;	..\fb_app_rollo10.c:894: void port_schalten(void)		// Schaltet die Ports mit PWM, DUTY ist Pulsverhältnis
                           3030 ;	-----------------------------------------
                           3031 ;	 function port_schalten
                           3032 ;	-----------------------------------------
   0C7B                    3033 _port_schalten:
                    0A6D   3034 	C$fb_app_rollo10.c$898$1$1 ==.
                           3035 ;	..\fb_app_rollo10.c:898: portbuffer=0;
   0C7B 75 0D 00           3036 	mov	_portbuffer,#0x00
                    0A70   3037 	C$fb_app_rollo10.c$899$1$1 ==.
                           3038 ;	..\fb_app_rollo10.c:899: if (eeprom[0xE4]& 0x80) kmod=0x01;		// bit 7 ist Kanal-mode
   0C7E 90 1D E4           3039 	mov	dptr,#(_eeprom + 0x00e4)
   0C81 E4                 3040 	clr	a
   0C82 93                 3041 	movc	a,@a+dptr
   0C83 FF                 3042 	mov	r7,a
   0C84 30 E7 04           3043 	jnb	acc.7,00102$
   0C87 7F 01              3044 	mov	r7,#0x01
   0C89 80 02              3045 	sjmp	00103$
   0C8B                    3046 00102$:
                    0A7D   3047 	C$fb_app_rollo10.c$900$1$1 ==.
                           3048 ;	..\fb_app_rollo10.c:900: else kmod=0x03;
   0C8B 7F 03              3049 	mov	r7,#0x03
   0C8D                    3050 00103$:
                    0A7F   3051 	C$fb_app_rollo10.c$901$1$1 ==.
                           3052 ;	..\fb_app_rollo10.c:901: for (knr=0;knr<=0x03;knr++){
   0C8D 75 4B 00           3053 	mov	_knr,#0x00
   0C90                    3054 00107$:
   0C90 E5 4B              3055 	mov	a,_knr
   0C92 24 FC              3056 	add	a,#0xff - 0x03
   0C94 40 23              3057 	jc	00110$
                    0A88   3058 	C$fb_app_rollo10.c$902$2$2 ==.
                           3059 ;	..\fb_app_rollo10.c:902: portbuffer=portbuffer|((kanal[knr & kmod]& 0x03)<<(knr<<1));
   0C96 EF                 3060 	mov	a,r7
   0C97 55 4B              3061 	anl	a,_knr
   0C99 24 47              3062 	add	a,#_kanal
   0C9B F9                 3063 	mov	r1,a
   0C9C 87 06              3064 	mov	ar6,@r1
   0C9E 53 06 03           3065 	anl	ar6,#0x03
   0CA1 E5 4B              3066 	mov	a,_knr
   0CA3 25 4B              3067 	add	a,_knr
   0CA5 FD                 3068 	mov	r5,a
   0CA6 8D F0              3069 	mov	b,r5
   0CA8 05 F0              3070 	inc	b
   0CAA EE                 3071 	mov	a,r6
   0CAB 80 02              3072 	sjmp	00121$
   0CAD                    3073 00119$:
   0CAD 25 E0              3074 	add	a,acc
   0CAF                    3075 00121$:
   0CAF D5 F0 FB           3076 	djnz	b,00119$
   0CB2 FE                 3077 	mov	r6,a
   0CB3 42 0D              3078 	orl	_portbuffer,a
                    0AA7   3079 	C$fb_app_rollo10.c$901$1$1 ==.
                           3080 ;	..\fb_app_rollo10.c:901: for (knr=0;knr<=0x03;knr++){
   0CB5 05 4B              3081 	inc	_knr
   0CB7 80 D7              3082 	sjmp	00107$
   0CB9                    3083 00110$:
                    0AAB   3084 	C$fb_app_rollo10.c$967$1$1 ==.
                           3085 ;	..\fb_app_rollo10.c:967: if(portbuffer & ~oldportbuffer) {	// Vollstrom nur wenn ein relais eingeschaltet wird
   0CB9 AE 0E              3086 	mov	r6,_oldportbuffer
   0CBB 7F 00              3087 	mov	r7,#0x00
   0CBD EE                 3088 	mov	a,r6
   0CBE F4                 3089 	cpl	a
   0CBF FE                 3090 	mov	r6,a
   0CC0 EF                 3091 	mov	a,r7
   0CC1 F4                 3092 	cpl	a
   0CC2 FF                 3093 	mov	r7,a
   0CC3 AC 0D              3094 	mov	r4,_portbuffer
   0CC5 7D 00              3095 	mov	r5,#0x00
   0CC7 EC                 3096 	mov	a,r4
   0CC8 52 06              3097 	anl	ar6,a
   0CCA ED                 3098 	mov	a,r5
   0CCB 52 07              3099 	anl	ar7,a
   0CCD EE                 3100 	mov	a,r6
   0CCE 4F                 3101 	orl	a,r7
   0CCF 60 1F              3102 	jz	00105$
                    0AC3   3103 	C$fb_app_rollo10.c$968$2$3 ==.
                           3104 ;	..\fb_app_rollo10.c:968: TR0=0;
   0CD1 C2 8C              3105 	clr	_TCON_4
                    0AC5   3106 	C$fb_app_rollo10.c$969$2$3 ==.
                           3107 ;	..\fb_app_rollo10.c:969: AUXR1&=0xE9;	// PWM von Timer 0 nicht mehr auf Pin ausgeben
   0CD3 53 A2 E9           3108 	anl	_AUXR1,#0xE9
                    0AC8   3109 	C$fb_app_rollo10.c$972$2$3 ==.
                           3110 ;	..\fb_app_rollo10.c:972: PWM=0;			// Vollstrom an
   0CD6 C2 92              3111 	clr	_P1_2
                    0ACA   3112 	C$fb_app_rollo10.c$974$2$3 ==.
                           3113 ;	..\fb_app_rollo10.c:974: P0=portbuffer;		// Ports schalten
   0CD8 85 0D 80           3114 	mov	_P0,_portbuffer
                    0ACD   3115 	C$fb_app_rollo10.c$975$2$3 ==.
                           3116 ;	..\fb_app_rollo10.c:975: TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
   0CDB C2 8D              3117 	clr	_TCON_5
                    0ACF   3118 	C$fb_app_rollo10.c$976$2$3 ==.
                           3119 ;	..\fb_app_rollo10.c:976: TH0=0x00;		// 16ms (10ms=6fff)
                    0ACF   3120 	C$fb_app_rollo10.c$977$2$3 ==.
                           3121 ;	..\fb_app_rollo10.c:977: TL0=0x00;
                    0ACF   3122 	C$fb_app_rollo10.c$978$2$3 ==.
                           3123 ;	..\fb_app_rollo10.c:978: TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
   0CDD E4                 3124 	clr	a
   0CDE F5 8C              3125 	mov	_TH0,a
   0CE0 F5 8A              3126 	mov	_TL0,a
   0CE2 74 F0              3127 	mov	a,#0xF0
   0CE4 55 89              3128 	anl	a,_TMOD
   0CE6 04                 3129 	inc	a
   0CE7 F5 89              3130 	mov	_TMOD,a
                    0ADB   3131 	C$fb_app_rollo10.c$979$2$3 ==.
                           3132 ;	..\fb_app_rollo10.c:979: TAMOD=0x00;
   0CE9 75 8F 00           3133 	mov	_TAMOD,#0x00
                    0ADE   3134 	C$fb_app_rollo10.c$980$2$3 ==.
                           3135 ;	..\fb_app_rollo10.c:980: TR0=1;
   0CEC D2 8C              3136 	setb	_TCON_4
   0CEE 80 03              3137 	sjmp	00106$
   0CF0                    3138 00105$:
                    0AE2   3139 	C$fb_app_rollo10.c$982$1$1 ==.
                           3140 ;	..\fb_app_rollo10.c:982: else P0=portbuffer;
   0CF0 85 0D 80           3141 	mov	_P0,_portbuffer
   0CF3                    3142 00106$:
                    0AE5   3143 	C$fb_app_rollo10.c$985$1$1 ==.
                           3144 ;	..\fb_app_rollo10.c:985: oldportbuffer=portbuffer;
   0CF3 85 0D 0E           3145 	mov	_oldportbuffer,_portbuffer
                    0AE8   3146 	C$fb_app_rollo10.c$986$1$1 ==.
                           3147 ;	..\fb_app_rollo10.c:986: portchanged=0;
   0CF6 C2 00              3148 	clr	_portchanged
                    0AEA   3149 	C$fb_app_rollo10.c$990$1$1 ==.
                    0AEA   3150 	XG$port_schalten$0$0 ==.
   0CF8 22                 3151 	ret
                           3152 ;------------------------------------------------------------
                           3153 ;Allocation info for local variables in function 'bus_return'
                           3154 ;------------------------------------------------------------
                           3155 ;n                         Allocated to registers r7 
                           3156 ;------------------------------------------------------------
                    0AEB   3157 	G$bus_return$0$0 ==.
                    0AEB   3158 	C$fb_app_rollo10.c$1112$1$1 ==.
                           3159 ;	..\fb_app_rollo10.c:1112: void bus_return(void)		// Aktionen bei Busspannungswiederkehr
                           3160 ;	-----------------------------------------
                           3161 ;	 function bus_return
                           3162 ;	-----------------------------------------
   0CF9                    3163 _bus_return:
                    0AEB   3164 	C$fb_app_rollo10.c$1115$1$1 ==.
                           3165 ;	..\fb_app_rollo10.c:1115: blocked=blockedsave;		// Ausgänge gesperrt?
   0CF9 90 1B FD           3166 	mov	dptr,#_blockedsave
   0CFC E4                 3167 	clr	a
   0CFD 93                 3168 	movc	a,@a+dptr
   0CFE F5 0F              3169 	mov	_blocked,a
                    0AF2   3170 	C$fb_app_rollo10.c$1116$1$1 ==.
                           3171 ;	..\fb_app_rollo10.c:1116: timer=0;			// Timer-Variable, wird alle 8 ms inkrementiert
                    0AF2   3172 	C$fb_app_rollo10.c$1117$2$2 ==.
                           3173 ;	..\fb_app_rollo10.c:1117: for (n=0;n<=15;n++){// Löschen aller zeiten
   0D00 E4                 3174 	clr	a
   0D01 F5 09              3175 	mov	_timer,a
   0D03 F5 0A              3176 	mov	(_timer + 1),a
   0D05 FF                 3177 	mov	r7,a
   0D06                    3178 00107$:
   0D06 EF                 3179 	mov	a,r7
   0D07 24 F0              3180 	add	a,#0xff - 0x0F
   0D09 40 15              3181 	jc	00110$
                    0AFD   3182 	C$fb_app_rollo10.c$1118$2$2 ==.
                           3183 ;	..\fb_app_rollo10.c:1118: timerstate[n]=0;
   0D0B EF                 3184 	mov	a,r7
   0D0C 24 34              3185 	add	a,#_timerstate
   0D0E F8                 3186 	mov	r0,a
   0D0F 76 00              3187 	mov	@r0,#0x00
                    0B03   3188 	C$fb_app_rollo10.c$1119$2$2 ==.
                           3189 ;	..\fb_app_rollo10.c:1119: timerbase[n]=0;
   0D11 EF                 3190 	mov	a,r7
   0D12 24 10              3191 	add	a,#_timerbase
   0D14 F8                 3192 	mov	r0,a
   0D15 76 00              3193 	mov	@r0,#0x00
                    0B09   3194 	C$fb_app_rollo10.c$1120$2$2 ==.
                           3195 ;	..\fb_app_rollo10.c:1120: timercnt[n]=0;
   0D17 EF                 3196 	mov	a,r7
   0D18 24 24              3197 	add	a,#_timercnt
   0D1A F8                 3198 	mov	r0,a
   0D1B 76 00              3199 	mov	@r0,#0x00
                    0B0F   3200 	C$fb_app_rollo10.c$1117$1$1 ==.
                           3201 ;	..\fb_app_rollo10.c:1117: for (n=0;n<=15;n++){// Löschen aller zeiten
   0D1D 0F                 3202 	inc	r7
   0D1E 80 E6              3203 	sjmp	00107$
   0D20                    3204 00110$:
                    0B12   3205 	C$fb_app_rollo10.c$1122$1$1 ==.
                           3206 ;	..\fb_app_rollo10.c:1122: for (n=0;n<=3;n++){
   0D20 7F 00              3207 	mov	r7,#0x00
   0D22                    3208 00111$:
   0D22 EF                 3209 	mov	a,r7
   0D23 24 FC              3210 	add	a,#0xff - 0x03
   0D25 40 63              3211 	jc	00114$
                    0B19   3212 	C$fb_app_rollo10.c$1123$2$3 ==.
                           3213 ;	..\fb_app_rollo10.c:1123: if(((eeprom[0xF1]>>n)&0x11)==0 ){// wenn keine Sperrfunktion zugewiesen
   0D27 90 1D F1           3214 	mov	dptr,#(_eeprom + 0x00f1)
   0D2A E4                 3215 	clr	a
   0D2B 93                 3216 	movc	a,@a+dptr
   0D2C FE                 3217 	mov	r6,a
   0D2D 8F F0              3218 	mov	b,r7
   0D2F 05 F0              3219 	inc	b
   0D31 EE                 3220 	mov	a,r6
   0D32 80 02              3221 	sjmp	00129$
   0D34                    3222 00128$:
   0D34 C3                 3223 	clr	c
   0D35 13                 3224 	rrc	a
   0D36                    3225 00129$:
   0D36 D5 F0 FB           3226 	djnz	b,00128$
   0D39 54 11              3227 	anl	a,#0x11
   0D3B 60 02              3228 	jz	00131$
   0D3D 80 11              3229 	sjmp	00102$
   0D3F                    3230 00131$:
                    0B31   3231 	C$fb_app_rollo10.c$1124$3$4 ==.
                           3232 ;	..\fb_app_rollo10.c:1124: blocked &= ~(0x11<<n);  // dann blocked löschen, damit nach umpara
   0D3F 8F F0              3233 	mov	b,r7
   0D41 05 F0              3234 	inc	b
   0D43 74 11              3235 	mov	a,#0x11
   0D45 80 02              3236 	sjmp	00134$
   0D47                    3237 00132$:
   0D47 25 E0              3238 	add	a,acc
   0D49                    3239 00134$:
   0D49 D5 F0 FB           3240 	djnz	b,00132$
   0D4C F4                 3241 	cpl	a
   0D4D FE                 3242 	mov	r6,a
   0D4E 52 0F              3243 	anl	_blocked,a
   0D50                    3244 00102$:
                    0B42   3245 	C$fb_app_rollo10.c$1126$2$3 ==.
                           3246 ;	..\fb_app_rollo10.c:1126: switch(eeprom[0xD9]& 0xC0){
   0D50 90 1D D9           3247 	mov	dptr,#(_eeprom + 0x00d9)
   0D53 E4                 3248 	clr	a
   0D54 93                 3249 	movc	a,@a+dptr
   0D55 FE                 3250 	mov	r6,a
   0D56 53 06 C0           3251 	anl	ar6,#0xC0
   0D59 BE 40 02           3252 	cjne	r6,#0x40,00135$
   0D5C 80 05              3253 	sjmp	00103$
   0D5E                    3254 00135$:
                    0B50   3255 	C$fb_app_rollo10.c$1127$3$5 ==.
                           3256 ;	..\fb_app_rollo10.c:1127: case 0x40:
   0D5E BE 80 26           3257 	cjne	r6,#0x80,00113$
   0D61 80 13              3258 	sjmp	00104$
   0D63                    3259 00103$:
                    0B55   3260 	C$fb_app_rollo10.c$1128$3$5 ==.
                           3261 ;	..\fb_app_rollo10.c:1128: object_schalten(n+12,0);
   0D63 74 0C              3262 	mov	a,#0x0C
   0D65 2F                 3263 	add	a,r7
   0D66 F5 82              3264 	mov	dpl,a
   0D68 C2 F0              3265 	clr	b[0]
   0D6A C0 07              3266 	push	ar7
   0D6C 85 F0 23           3267 	mov	bits,b
   0D6F 12 05 34           3268 	lcall	_object_schalten
   0D72 D0 07              3269 	pop	ar7
                    0B66   3270 	C$fb_app_rollo10.c$1129$3$5 ==.
                           3271 ;	..\fb_app_rollo10.c:1129: break;
                    0B66   3272 	C$fb_app_rollo10.c$1130$3$5 ==.
                           3273 ;	..\fb_app_rollo10.c:1130: case 0x80:
   0D74 80 11              3274 	sjmp	00113$
   0D76                    3275 00104$:
                    0B68   3276 	C$fb_app_rollo10.c$1131$3$5 ==.
                           3277 ;	..\fb_app_rollo10.c:1131: object_schalten(n+12,1);
   0D76 74 0C              3278 	mov	a,#0x0C
   0D78 2F                 3279 	add	a,r7
   0D79 F5 82              3280 	mov	dpl,a
   0D7B D2 F0              3281 	setb	b[0]
   0D7D C0 07              3282 	push	ar7
   0D7F 85 F0 23           3283 	mov	bits,b
   0D82 12 05 34           3284 	lcall	_object_schalten
   0D85 D0 07              3285 	pop	ar7
                    0B79   3286 	C$fb_app_rollo10.c$1134$2$3 ==.
                           3287 ;	..\fb_app_rollo10.c:1134: }
   0D87                    3288 00113$:
                    0B79   3289 	C$fb_app_rollo10.c$1122$1$1 ==.
                           3290 ;	..\fb_app_rollo10.c:1122: for (n=0;n<=3;n++){
   0D87 0F                 3291 	inc	r7
   0D88 80 98              3292 	sjmp	00111$
   0D8A                    3293 00114$:
                    0B7C   3294 	C$fb_app_rollo10.c$1138$1$1 ==.
                           3295 ;	..\fb_app_rollo10.c:1138: oldportbuffer=0; 	// auf 0 setzen, da sonst kein Vollstrom aktiviert wird
   0D8A 75 0E 00           3296 	mov	_oldportbuffer,#0x00
                    0B7F   3297 	C$fb_app_rollo10.c$1139$1$1 ==.
                           3298 ;	..\fb_app_rollo10.c:1139: portchanged=1;		// Post hinterlegen damit in delaytimer nach portschalten springt
   0D8D D2 00              3299 	setb	_portchanged
                    0B81   3300 	C$fb_app_rollo10.c$1141$1$1 ==.
                           3301 ;	..\fb_app_rollo10.c:1141: set_entriegeln(9);	// Überwachungszeit Sicherheitsfahrt
   0D8F 75 82 09           3302 	mov	dpl,#0x09
   0D92 12 0C 49           3303 	lcall	_set_entriegeln
                    0B87   3304 	C$fb_app_rollo10.c$1142$1$1 ==.
                           3305 ;	..\fb_app_rollo10.c:1142: set_entriegeln(10);	// dto
   0D95 75 82 0A           3306 	mov	dpl,#0x0A
   0D98 12 0C 49           3307 	lcall	_set_entriegeln
                    0B8D   3308 	C$fb_app_rollo10.c$1145$1$1 ==.
                    0B8D   3309 	XG$bus_return$0$0 ==.
   0D9B 22                 3310 	ret
                           3311 ;------------------------------------------------------------
                           3312 ;Allocation info for local variables in function 'restart_app'
                           3313 ;------------------------------------------------------------
                    0B8E   3314 	G$restart_app$0$0 ==.
                    0B8E   3315 	C$fb_app_rollo10.c$1148$1$1 ==.
                           3316 ;	..\fb_app_rollo10.c:1148: void restart_app(void) 		// Alle Applikations-Parameter zurücksetzen
                           3317 ;	-----------------------------------------
                           3318 ;	 function restart_app
                           3319 ;	-----------------------------------------
   0D9C                    3320 _restart_app:
                    0B8E   3321 	C$fb_app_rollo10.c$1151$1$1 ==.
                           3322 ;	..\fb_app_rollo10.c:1151: Tval=0x00;
   0D9C 75 44 00           3323 	mov	_Tval,#0x00
                    0B91   3324 	C$fb_app_rollo10.c$1152$1$1 ==.
                           3325 ;	..\fb_app_rollo10.c:1152: handmode=0;
   0D9F C2 02              3326 	clr	_handmode
                    0B93   3327 	C$fb_app_rollo10.c$1154$1$1 ==.
                           3328 ;	..\fb_app_rollo10.c:1154: P0=0;
   0DA1 75 80 00           3329 	mov	_P0,#0x00
                    0B96   3330 	C$fb_app_rollo10.c$1155$1$1 ==.
                           3331 ;	..\fb_app_rollo10.c:1155: P0M1=0x00;		// Port 0 Modus push-pull für Ausgang
   0DA4 75 84 00           3332 	mov	_P0M1,#0x00
                    0B99   3333 	C$fb_app_rollo10.c$1156$1$1 ==.
                           3334 ;	..\fb_app_rollo10.c:1156: P0M2=0xFF;
   0DA7 75 85 FF           3335 	mov	_P0M2,#0xFF
                    0B9C   3336 	C$fb_app_rollo10.c$1161$1$1 ==.
                           3337 ;	..\fb_app_rollo10.c:1161: TMOD=(TMOD & 0xF0) + 2;		// Timer 0 als PWM
   0DAA 74 F0              3338 	mov	a,#0xF0
   0DAC 55 89              3339 	anl	a,_TMOD
   0DAE 24 02              3340 	add	a,#0x02
   0DB0 F5 89              3341 	mov	_TMOD,a
                    0BA4   3342 	C$fb_app_rollo10.c$1162$1$1 ==.
                           3343 ;	..\fb_app_rollo10.c:1162: TAMOD=0x01;
   0DB2 75 8F 01           3344 	mov	_TAMOD,#0x01
                    0BA7   3345 	C$fb_app_rollo10.c$1163$1$1 ==.
                           3346 ;	..\fb_app_rollo10.c:1163: TH0=DUTY;		// Pulsverhältnis PWM
   0DB5 75 8C 50           3347 	mov	_TH0,#0x50
                    0BAA   3348 	C$fb_app_rollo10.c$1164$1$1 ==.
                           3349 ;	..\fb_app_rollo10.c:1164: AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
   0DB8 43 A2 10           3350 	orl	_AUXR1,#0x10
                    0BAD   3351 	C$fb_app_rollo10.c$1165$1$1 ==.
                           3352 ;	..\fb_app_rollo10.c:1165: TR0=1;			// Timer 0 starten (PWM)
   0DBB D2 8C              3353 	setb	_TCON_4
                    0BAF   3354 	C$fb_app_rollo10.c$1170$1$1 ==.
                           3355 ;	..\fb_app_rollo10.c:1170: ET0=0;			// Interrupt für Timer 0 sperren
   0DBD C2 A9              3356 	clr	_IEN0_1
                    0BB1   3357 	C$fb_app_rollo10.c$1171$1$1 ==.
                           3358 ;	..\fb_app_rollo10.c:1171: IT0=1;
   0DBF D2 88              3359 	setb	_TCON_0
                    0BB3   3360 	C$fb_app_rollo10.c$1172$1$1 ==.
                           3361 ;	..\fb_app_rollo10.c:1172: blocked=0x00;		// Ausgänge nicht gesperrt
                    0BB3   3362 	C$fb_app_rollo10.c$1173$1$1 ==.
                           3363 ;	..\fb_app_rollo10.c:1173: timer=0;			// Timer-Variable, wird alle 8ms inkrementiert
                    0BB3   3364 	C$fb_app_rollo10.c$1176$1$1 ==.
                           3365 ;	..\fb_app_rollo10.c:1176: delay_toggle=0;
   0DC1 E4                 3366 	clr	a
   0DC2 F5 0F              3367 	mov	_blocked,a
   0DC4 F5 09              3368 	mov	_timer,a
   0DC6 F5 0A              3369 	mov	(_timer + 1),a
   0DC8 F5 09              3370 	mov	_delay_toggle,a
                    0BBC   3371 	C$fb_app_rollo10.c$1178$1$1 ==.
                           3372 ;	..\fb_app_rollo10.c:1178: EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
   0DCA C2 AF              3373 	clr	_IEN0_7
                    0BBE   3374 	C$fb_app_rollo10.c$1179$1$1 ==.
                           3375 ;	..\fb_app_rollo10.c:1179: START_WRITECYCLE
   0DCC 75 E4 00           3376 	mov	_FMCON,#0x00
                    0BC1   3377 	C$fb_app_rollo10.c$1180$1$1 ==.
                           3378 ;	..\fb_app_rollo10.c:1180: WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
   0DCF 75 E7 1D           3379 	mov	_FMADRH,#0x1D
   0DD2 75 E6 03           3380 	mov	_FMADRL,#0x03
   0DD5 75 E5 00           3381 	mov	_FMDATA,#0x00
                    0BCA   3382 	C$fb_app_rollo10.c$1181$1$1 ==.
                           3383 ;	..\fb_app_rollo10.c:1181: WRITE_BYTE(0x01,0x04,0x04)
   0DD8 75 E7 1D           3384 	mov	_FMADRH,#0x1D
   0DDB 75 E6 04           3385 	mov	_FMADRL,#0x04
   0DDE 75 E5 04           3386 	mov	_FMDATA,#0x04
                    0BD3   3387 	C$fb_app_rollo10.c$1182$1$1 ==.
                           3388 ;	..\fb_app_rollo10.c:1182: WRITE_BYTE(0x01,0x05,0x20)	// Devicetype 0x2070 = Jung Aktor 2138.10
   0DE1 75 E7 1D           3389 	mov	_FMADRH,#0x1D
   0DE4 75 E6 05           3390 	mov	_FMADRL,#0x05
   0DE7 75 E5 20           3391 	mov	_FMDATA,#0x20
                    0BDC   3392 	C$fb_app_rollo10.c$1183$1$1 ==.
                           3393 ;	..\fb_app_rollo10.c:1183: WRITE_BYTE(0x01,0x06,0x70)	
   0DEA 75 E7 1D           3394 	mov	_FMADRH,#0x1D
   0DED 75 E6 06           3395 	mov	_FMADRL,#0x06
   0DF0 75 E5 70           3396 	mov	_FMDATA,#0x70
                    0BE5   3397 	C$fb_app_rollo10.c$1184$1$1 ==.
                           3398 ;	..\fb_app_rollo10.c:1184: WRITE_BYTE(0x01,0x07,0x01)	// Versionnumber of application programm
   0DF3 75 E7 1D           3399 	mov	_FMADRH,#0x1D
   0DF6 75 E6 07           3400 	mov	_FMADRL,#0x07
   0DF9 75 E5 01           3401 	mov	_FMDATA,#0x01
                    0BEE   3402 	C$fb_app_rollo10.c$1185$1$1 ==.
                           3403 ;	..\fb_app_rollo10.c:1185: WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
   0DFC 75 E7 1D           3404 	mov	_FMADRH,#0x1D
   0DFF 75 E6 0C           3405 	mov	_FMADRL,#0x0C
   0E02 75 E5 00           3406 	mov	_FMDATA,#0x00
                    0BF7   3407 	C$fb_app_rollo10.c$1186$1$1 ==.
                           3408 ;	..\fb_app_rollo10.c:1186: WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
   0E05 75 E7 1D           3409 	mov	_FMADRH,#0x1D
   0E08 75 E6 0D           3410 	mov	_FMADRL,#0x0D
   0E0B 75 E5 FF           3411 	mov	_FMDATA,#0xFF
                    0C00   3412 	C$fb_app_rollo10.c$1187$1$1 ==.
                           3413 ;	..\fb_app_rollo10.c:1187: WRITE_BYTE(0x01,0x12,0x9A)	// COMMSTAB Pointer
   0E0E 75 E7 1D           3414 	mov	_FMADRH,#0x1D
   0E11 75 E6 12           3415 	mov	_FMADRL,#0x12
   0E14 75 E5 9A           3416 	mov	_FMDATA,#0x9A
                    0C09   3417 	C$fb_app_rollo10.c$1188$1$1 ==.
                           3418 ;	..\fb_app_rollo10.c:1188: STOP_WRITECYCLE
   0E17 75 E4 68           3419 	mov	_FMCON,#0x68
                    0C0C   3420 	C$fb_app_rollo10.c$1189$1$1 ==.
                           3421 ;	..\fb_app_rollo10.c:1189: EA=1;						// Interrupts freigeben
   0E1A D2 AF              3422 	setb	_IEN0_7
                    0C0E   3423 	C$fb_app_rollo10.c$1191$1$1 ==.
                           3424 ;	..\fb_app_rollo10.c:1191: RTCCON=0x60;		// RTC Flag löschen
   0E1C 75 D1 60           3425 	mov	_RTCCON,#0x60
                    0C11   3426 	C$fb_app_rollo10.c$1192$1$1 ==.
                           3427 ;	..\fb_app_rollo10.c:1192: RTCH=0x01;			// reload Real Time Clock
   0E1F 75 D2 01           3428 	mov	_RTCH,#0x01
                    0C14   3429 	C$fb_app_rollo10.c$1193$1$1 ==.
                           3430 ;	..\fb_app_rollo10.c:1193: RTCL=0xCD;			// 8ms
   0E22 75 D3 CD           3431 	mov	_RTCL,#0xCD
                    0C17   3432 	C$fb_app_rollo10.c$1194$1$1 ==.
                           3433 ;	..\fb_app_rollo10.c:1194: RTCCON=0x61;
   0E25 75 D1 61           3434 	mov	_RTCCON,#0x61
                    0C1A   3435 	C$fb_app_rollo10.c$1195$1$1 ==.
                    0C1A   3436 	XG$restart_app$0$0 ==.
   0E28 22                 3437 	ret
                           3438 	.area CSEG    (CODE)
                           3439 	.area CONST   (CODE)
                    1BFD   3440 Ffb_app_rollo10$blockedsave$0$0 == 0x1bfd
                    1BFD   3441 _blockedsave	=	0x1bfd
                    0000   3442 G$timerflagmask$0$0 == .
   17CA                    3443 _timerflagmask:
   17CA 00 00              3444 	.byte #0x00,#0x00	; 0
   17CC 00 00              3445 	.byte #0x00,#0x00	; 0
   17CE 00 00              3446 	.byte #0x00,#0x00	; 0
   17D0 08 00              3447 	.byte #0x08,#0x00	; 8
   17D2 80 00              3448 	.byte #0x80,#0x00	; 128
   17D4 00 08              3449 	.byte #0x00,#0x08	; 2048
                    000C   3450 G$svfaktorarray$0$0 == .
   17D6                    3451 _svfaktorarray:
   17D6 00                 3452 	.db #0x00	; 0
   17D7 02                 3453 	.db #0x02	; 2
   17D8 04                 3454 	.db #0x04	; 4
   17D9 06                 3455 	.db #0x06	; 6
   17DA 08                 3456 	.db #0x08	; 8
   17DB 0A                 3457 	.db #0x0A	; 10
   17DC 0C                 3458 	.db #0x0C	; 12
   17DD 0E                 3459 	.db #0x0E	; 14
   17DE 10                 3460 	.db #0x10	; 16
   17DF 12                 3461 	.db #0x12	; 18
   17E0 14                 3462 	.db #0x14	; 20
   17E1 16                 3463 	.db #0x16	; 22
   17E2 24                 3464 	.db #0x24	; 36
   17E3 48                 3465 	.db #0x48	; 72	'H'
   17E4 6D                 3466 	.db #0x6D	; 109	'm'
   17E5 DA                 3467 	.db #0xDA	; 218
                           3468 	.area XINIT   (CODE)
                           3469 	.area CABS    (ABS,CODE)
