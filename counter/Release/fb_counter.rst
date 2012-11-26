                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Sun Nov 25 23:48:41 2012
                              5 ;--------------------------------------------------------
                              6 	.module fb_counter
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _space
                             13 	.globl _bitmask_1
                             14 	.globl _main
                             15 	.globl _checklevel
                             16 	.globl _bus_return
                             17 	.globl _restart_app
                             18 	.globl _read_obj_value
                             19 	.globl _delay_timer
                             20 	.globl _pin_changed
                             21 	.globl _keypad_init
                             22 	.globl _process_tel
                             23 	.globl _restart_hw
                             24 	.globl _P3_1
                             25 	.globl _P3_0
                             26 	.globl _P1_7
                             27 	.globl _P1_6
                             28 	.globl _P1_5
                             29 	.globl _P1_4
                             30 	.globl _P1_3
                             31 	.globl _P1_2
                             32 	.globl _P1_1
                             33 	.globl _P1_0
                             34 	.globl _P0_7
                             35 	.globl _P0_6
                             36 	.globl _P0_5
                             37 	.globl _P0_4
                             38 	.globl _P0_3
                             39 	.globl _P0_2
                             40 	.globl _P0_1
                             41 	.globl _P0_0
                             42 	.globl _I2CON_0
                             43 	.globl _I2CON_2
                             44 	.globl _I2CON_3
                             45 	.globl _I2CON_4
                             46 	.globl _I2CON_5
                             47 	.globl _I2CON_6
                             48 	.globl _SCON_7
                             49 	.globl _SCON_6
                             50 	.globl _SCON_5
                             51 	.globl _SCON_4
                             52 	.globl _SCON_3
                             53 	.globl _SCON_2
                             54 	.globl _SCON_1
                             55 	.globl _SCON_0
                             56 	.globl _IP0_0
                             57 	.globl _IP0_1
                             58 	.globl _IP0_2
                             59 	.globl _IP0_3
                             60 	.globl _IP0_4
                             61 	.globl _IP0_5
                             62 	.globl _IP0_6
                             63 	.globl _IP1_0
                             64 	.globl _IP1_1
                             65 	.globl _IP1_2
                             66 	.globl _IP1_6
                             67 	.globl _IEN1_0
                             68 	.globl _IEN1_1
                             69 	.globl _IEN1_2
                             70 	.globl _IEN0_0
                             71 	.globl _IEN0_1
                             72 	.globl _IEN0_2
                             73 	.globl _IEN0_3
                             74 	.globl _IEN0_4
                             75 	.globl _IEN0_5
                             76 	.globl _IEN0_6
                             77 	.globl _IEN0_7
                             78 	.globl _TCON_0
                             79 	.globl _TCON_1
                             80 	.globl _TCON_2
                             81 	.globl _TCON_3
                             82 	.globl _TCON_4
                             83 	.globl _TCON_5
                             84 	.globl _TCON_6
                             85 	.globl _TCON_7
                             86 	.globl _PSW_7
                             87 	.globl _PSW_6
                             88 	.globl _PSW_5
                             89 	.globl _PSW_4
                             90 	.globl _PSW_3
                             91 	.globl _PSW_2
                             92 	.globl _PSW_1
                             93 	.globl _PSW_0
                             94 	.globl _IEN1
                             95 	.globl _IP0H
                             96 	.globl _WFEED2
                             97 	.globl _WFEED1
                             98 	.globl _WDL
                             99 	.globl _WDCON
                            100 	.globl _TRIM
                            101 	.globl _TAMOD
                            102 	.globl _SSTAT
                            103 	.globl _RTCL
                            104 	.globl _RTCH
                            105 	.globl _RTCCON
                            106 	.globl _RSTSRC
                            107 	.globl _PT0AD
                            108 	.globl _PCONA
                            109 	.globl _P3M2
                            110 	.globl _P3M1
                            111 	.globl _P1M2
                            112 	.globl _P1M1
                            113 	.globl _P0M2
                            114 	.globl _P0M1
                            115 	.globl _KBPATN
                            116 	.globl _KBMASK
                            117 	.globl _KBCON
                            118 	.globl _IP1H
                            119 	.globl _IP1
                            120 	.globl _I2STAT
                            121 	.globl _I2SCLL
                            122 	.globl _I2SCLH
                            123 	.globl _I2DAT
                            124 	.globl _I2CON
                            125 	.globl _I2ADR
                            126 	.globl _FMDATA
                            127 	.globl _FMCON
                            128 	.globl _FMADRL
                            129 	.globl _FMADRH
                            130 	.globl _DIVM
                            131 	.globl _CMP2
                            132 	.globl _CMP1
                            133 	.globl _BRGCON
                            134 	.globl _BRGR1
                            135 	.globl _BRGR0
                            136 	.globl _SADEN
                            137 	.globl _SADDR
                            138 	.globl _AUXR1
                            139 	.globl _SBUF
                            140 	.globl _SCON
                            141 	.globl _IP0
                            142 	.globl _IEN0
                            143 	.globl _TH1
                            144 	.globl _TH0
                            145 	.globl _TL1
                            146 	.globl _TL0
                            147 	.globl _TMOD
                            148 	.globl _TCON
                            149 	.globl _PCON
                            150 	.globl _DPH
                            151 	.globl _DPL
                            152 	.globl _SP
                            153 	.globl _B
                            154 	.globl _ACC
                            155 	.globl _PSW
                            156 	.globl _P3
                            157 	.globl _P1
                            158 	.globl _P0
                            159 	.globl _RAM
                            160 ;--------------------------------------------------------
                            161 ; special function registers
                            162 ;--------------------------------------------------------
                            163 	.area RSEG    (ABS,DATA)
   0000                     164 	.org 0x0000
                    0080    165 G$P0$0$0 == 0x0080
                    0080    166 _P0	=	0x0080
                    0090    167 G$P1$0$0 == 0x0090
                    0090    168 _P1	=	0x0090
                    00B0    169 G$P3$0$0 == 0x00b0
                    00B0    170 _P3	=	0x00b0
                    00D0    171 G$PSW$0$0 == 0x00d0
                    00D0    172 _PSW	=	0x00d0
                    00E0    173 G$ACC$0$0 == 0x00e0
                    00E0    174 _ACC	=	0x00e0
                    00F0    175 G$B$0$0 == 0x00f0
                    00F0    176 _B	=	0x00f0
                    0081    177 G$SP$0$0 == 0x0081
                    0081    178 _SP	=	0x0081
                    0082    179 G$DPL$0$0 == 0x0082
                    0082    180 _DPL	=	0x0082
                    0083    181 G$DPH$0$0 == 0x0083
                    0083    182 _DPH	=	0x0083
                    0087    183 G$PCON$0$0 == 0x0087
                    0087    184 _PCON	=	0x0087
                    0088    185 G$TCON$0$0 == 0x0088
                    0088    186 _TCON	=	0x0088
                    0089    187 G$TMOD$0$0 == 0x0089
                    0089    188 _TMOD	=	0x0089
                    008A    189 G$TL0$0$0 == 0x008a
                    008A    190 _TL0	=	0x008a
                    008B    191 G$TL1$0$0 == 0x008b
                    008B    192 _TL1	=	0x008b
                    008C    193 G$TH0$0$0 == 0x008c
                    008C    194 _TH0	=	0x008c
                    008D    195 G$TH1$0$0 == 0x008d
                    008D    196 _TH1	=	0x008d
                    00A8    197 G$IEN0$0$0 == 0x00a8
                    00A8    198 _IEN0	=	0x00a8
                    00B8    199 G$IP0$0$0 == 0x00b8
                    00B8    200 _IP0	=	0x00b8
                    0098    201 G$SCON$0$0 == 0x0098
                    0098    202 _SCON	=	0x0098
                    0099    203 G$SBUF$0$0 == 0x0099
                    0099    204 _SBUF	=	0x0099
                    00A2    205 G$AUXR1$0$0 == 0x00a2
                    00A2    206 _AUXR1	=	0x00a2
                    00A9    207 G$SADDR$0$0 == 0x00a9
                    00A9    208 _SADDR	=	0x00a9
                    00B9    209 G$SADEN$0$0 == 0x00b9
                    00B9    210 _SADEN	=	0x00b9
                    00BE    211 G$BRGR0$0$0 == 0x00be
                    00BE    212 _BRGR0	=	0x00be
                    00BF    213 G$BRGR1$0$0 == 0x00bf
                    00BF    214 _BRGR1	=	0x00bf
                    00BD    215 G$BRGCON$0$0 == 0x00bd
                    00BD    216 _BRGCON	=	0x00bd
                    00AC    217 G$CMP1$0$0 == 0x00ac
                    00AC    218 _CMP1	=	0x00ac
                    00AD    219 G$CMP2$0$0 == 0x00ad
                    00AD    220 _CMP2	=	0x00ad
                    0095    221 G$DIVM$0$0 == 0x0095
                    0095    222 _DIVM	=	0x0095
                    00E7    223 G$FMADRH$0$0 == 0x00e7
                    00E7    224 _FMADRH	=	0x00e7
                    00E6    225 G$FMADRL$0$0 == 0x00e6
                    00E6    226 _FMADRL	=	0x00e6
                    00E4    227 G$FMCON$0$0 == 0x00e4
                    00E4    228 _FMCON	=	0x00e4
                    00E5    229 G$FMDATA$0$0 == 0x00e5
                    00E5    230 _FMDATA	=	0x00e5
                    00DB    231 G$I2ADR$0$0 == 0x00db
                    00DB    232 _I2ADR	=	0x00db
                    00D8    233 G$I2CON$0$0 == 0x00d8
                    00D8    234 _I2CON	=	0x00d8
                    00DA    235 G$I2DAT$0$0 == 0x00da
                    00DA    236 _I2DAT	=	0x00da
                    00DD    237 G$I2SCLH$0$0 == 0x00dd
                    00DD    238 _I2SCLH	=	0x00dd
                    00DC    239 G$I2SCLL$0$0 == 0x00dc
                    00DC    240 _I2SCLL	=	0x00dc
                    00D9    241 G$I2STAT$0$0 == 0x00d9
                    00D9    242 _I2STAT	=	0x00d9
                    00F8    243 G$IP1$0$0 == 0x00f8
                    00F8    244 _IP1	=	0x00f8
                    00F7    245 G$IP1H$0$0 == 0x00f7
                    00F7    246 _IP1H	=	0x00f7
                    0094    247 G$KBCON$0$0 == 0x0094
                    0094    248 _KBCON	=	0x0094
                    0086    249 G$KBMASK$0$0 == 0x0086
                    0086    250 _KBMASK	=	0x0086
                    0093    251 G$KBPATN$0$0 == 0x0093
                    0093    252 _KBPATN	=	0x0093
                    0084    253 G$P0M1$0$0 == 0x0084
                    0084    254 _P0M1	=	0x0084
                    0085    255 G$P0M2$0$0 == 0x0085
                    0085    256 _P0M2	=	0x0085
                    0091    257 G$P1M1$0$0 == 0x0091
                    0091    258 _P1M1	=	0x0091
                    0092    259 G$P1M2$0$0 == 0x0092
                    0092    260 _P1M2	=	0x0092
                    00B1    261 G$P3M1$0$0 == 0x00b1
                    00B1    262 _P3M1	=	0x00b1
                    00B2    263 G$P3M2$0$0 == 0x00b2
                    00B2    264 _P3M2	=	0x00b2
                    00B5    265 G$PCONA$0$0 == 0x00b5
                    00B5    266 _PCONA	=	0x00b5
                    00F6    267 G$PT0AD$0$0 == 0x00f6
                    00F6    268 _PT0AD	=	0x00f6
                    00DF    269 G$RSTSRC$0$0 == 0x00df
                    00DF    270 _RSTSRC	=	0x00df
                    00D1    271 G$RTCCON$0$0 == 0x00d1
                    00D1    272 _RTCCON	=	0x00d1
                    00D2    273 G$RTCH$0$0 == 0x00d2
                    00D2    274 _RTCH	=	0x00d2
                    00D3    275 G$RTCL$0$0 == 0x00d3
                    00D3    276 _RTCL	=	0x00d3
                    00BA    277 G$SSTAT$0$0 == 0x00ba
                    00BA    278 _SSTAT	=	0x00ba
                    008F    279 G$TAMOD$0$0 == 0x008f
                    008F    280 _TAMOD	=	0x008f
                    0096    281 G$TRIM$0$0 == 0x0096
                    0096    282 _TRIM	=	0x0096
                    00A7    283 G$WDCON$0$0 == 0x00a7
                    00A7    284 _WDCON	=	0x00a7
                    00C1    285 G$WDL$0$0 == 0x00c1
                    00C1    286 _WDL	=	0x00c1
                    00C2    287 G$WFEED1$0$0 == 0x00c2
                    00C2    288 _WFEED1	=	0x00c2
                    00C3    289 G$WFEED2$0$0 == 0x00c3
                    00C3    290 _WFEED2	=	0x00c3
                    00B7    291 G$IP0H$0$0 == 0x00b7
                    00B7    292 _IP0H	=	0x00b7
                    00E8    293 G$IEN1$0$0 == 0x00e8
                    00E8    294 _IEN1	=	0x00e8
                            295 ;--------------------------------------------------------
                            296 ; special function bits
                            297 ;--------------------------------------------------------
                            298 	.area RSEG    (ABS,DATA)
   0000                     299 	.org 0x0000
                    00D0    300 G$PSW_0$0$0 == 0x00d0
                    00D0    301 _PSW_0	=	0x00d0
                    00D1    302 G$PSW_1$0$0 == 0x00d1
                    00D1    303 _PSW_1	=	0x00d1
                    00D2    304 G$PSW_2$0$0 == 0x00d2
                    00D2    305 _PSW_2	=	0x00d2
                    00D3    306 G$PSW_3$0$0 == 0x00d3
                    00D3    307 _PSW_3	=	0x00d3
                    00D4    308 G$PSW_4$0$0 == 0x00d4
                    00D4    309 _PSW_4	=	0x00d4
                    00D5    310 G$PSW_5$0$0 == 0x00d5
                    00D5    311 _PSW_5	=	0x00d5
                    00D6    312 G$PSW_6$0$0 == 0x00d6
                    00D6    313 _PSW_6	=	0x00d6
                    00D7    314 G$PSW_7$0$0 == 0x00d7
                    00D7    315 _PSW_7	=	0x00d7
                    008F    316 G$TCON_7$0$0 == 0x008f
                    008F    317 _TCON_7	=	0x008f
                    008E    318 G$TCON_6$0$0 == 0x008e
                    008E    319 _TCON_6	=	0x008e
                    008D    320 G$TCON_5$0$0 == 0x008d
                    008D    321 _TCON_5	=	0x008d
                    008C    322 G$TCON_4$0$0 == 0x008c
                    008C    323 _TCON_4	=	0x008c
                    008B    324 G$TCON_3$0$0 == 0x008b
                    008B    325 _TCON_3	=	0x008b
                    008A    326 G$TCON_2$0$0 == 0x008a
                    008A    327 _TCON_2	=	0x008a
                    0089    328 G$TCON_1$0$0 == 0x0089
                    0089    329 _TCON_1	=	0x0089
                    0088    330 G$TCON_0$0$0 == 0x0088
                    0088    331 _TCON_0	=	0x0088
                    00AF    332 G$IEN0_7$0$0 == 0x00af
                    00AF    333 _IEN0_7	=	0x00af
                    00AE    334 G$IEN0_6$0$0 == 0x00ae
                    00AE    335 _IEN0_6	=	0x00ae
                    00AD    336 G$IEN0_5$0$0 == 0x00ad
                    00AD    337 _IEN0_5	=	0x00ad
                    00AC    338 G$IEN0_4$0$0 == 0x00ac
                    00AC    339 _IEN0_4	=	0x00ac
                    00AB    340 G$IEN0_3$0$0 == 0x00ab
                    00AB    341 _IEN0_3	=	0x00ab
                    00AA    342 G$IEN0_2$0$0 == 0x00aa
                    00AA    343 _IEN0_2	=	0x00aa
                    00A9    344 G$IEN0_1$0$0 == 0x00a9
                    00A9    345 _IEN0_1	=	0x00a9
                    00A8    346 G$IEN0_0$0$0 == 0x00a8
                    00A8    347 _IEN0_0	=	0x00a8
                    00EA    348 G$IEN1_2$0$0 == 0x00ea
                    00EA    349 _IEN1_2	=	0x00ea
                    00E9    350 G$IEN1_1$0$0 == 0x00e9
                    00E9    351 _IEN1_1	=	0x00e9
                    00E8    352 G$IEN1_0$0$0 == 0x00e8
                    00E8    353 _IEN1_0	=	0x00e8
                    00FE    354 G$IP1_6$0$0 == 0x00fe
                    00FE    355 _IP1_6	=	0x00fe
                    00FA    356 G$IP1_2$0$0 == 0x00fa
                    00FA    357 _IP1_2	=	0x00fa
                    00F9    358 G$IP1_1$0$0 == 0x00f9
                    00F9    359 _IP1_1	=	0x00f9
                    00F8    360 G$IP1_0$0$0 == 0x00f8
                    00F8    361 _IP1_0	=	0x00f8
                    00BE    362 G$IP0_6$0$0 == 0x00be
                    00BE    363 _IP0_6	=	0x00be
                    00BD    364 G$IP0_5$0$0 == 0x00bd
                    00BD    365 _IP0_5	=	0x00bd
                    00BC    366 G$IP0_4$0$0 == 0x00bc
                    00BC    367 _IP0_4	=	0x00bc
                    00BB    368 G$IP0_3$0$0 == 0x00bb
                    00BB    369 _IP0_3	=	0x00bb
                    00BA    370 G$IP0_2$0$0 == 0x00ba
                    00BA    371 _IP0_2	=	0x00ba
                    00B9    372 G$IP0_1$0$0 == 0x00b9
                    00B9    373 _IP0_1	=	0x00b9
                    00B8    374 G$IP0_0$0$0 == 0x00b8
                    00B8    375 _IP0_0	=	0x00b8
                    0098    376 G$SCON_0$0$0 == 0x0098
                    0098    377 _SCON_0	=	0x0098
                    0099    378 G$SCON_1$0$0 == 0x0099
                    0099    379 _SCON_1	=	0x0099
                    009A    380 G$SCON_2$0$0 == 0x009a
                    009A    381 _SCON_2	=	0x009a
                    009B    382 G$SCON_3$0$0 == 0x009b
                    009B    383 _SCON_3	=	0x009b
                    009C    384 G$SCON_4$0$0 == 0x009c
                    009C    385 _SCON_4	=	0x009c
                    009D    386 G$SCON_5$0$0 == 0x009d
                    009D    387 _SCON_5	=	0x009d
                    009E    388 G$SCON_6$0$0 == 0x009e
                    009E    389 _SCON_6	=	0x009e
                    009F    390 G$SCON_7$0$0 == 0x009f
                    009F    391 _SCON_7	=	0x009f
                    00DE    392 G$I2CON_6$0$0 == 0x00de
                    00DE    393 _I2CON_6	=	0x00de
                    00DD    394 G$I2CON_5$0$0 == 0x00dd
                    00DD    395 _I2CON_5	=	0x00dd
                    00DC    396 G$I2CON_4$0$0 == 0x00dc
                    00DC    397 _I2CON_4	=	0x00dc
                    00DB    398 G$I2CON_3$0$0 == 0x00db
                    00DB    399 _I2CON_3	=	0x00db
                    00DA    400 G$I2CON_2$0$0 == 0x00da
                    00DA    401 _I2CON_2	=	0x00da
                    00D8    402 G$I2CON_0$0$0 == 0x00d8
                    00D8    403 _I2CON_0	=	0x00d8
                    0080    404 G$P0_0$0$0 == 0x0080
                    0080    405 _P0_0	=	0x0080
                    0081    406 G$P0_1$0$0 == 0x0081
                    0081    407 _P0_1	=	0x0081
                    0082    408 G$P0_2$0$0 == 0x0082
                    0082    409 _P0_2	=	0x0082
                    0083    410 G$P0_3$0$0 == 0x0083
                    0083    411 _P0_3	=	0x0083
                    0084    412 G$P0_4$0$0 == 0x0084
                    0084    413 _P0_4	=	0x0084
                    0085    414 G$P0_5$0$0 == 0x0085
                    0085    415 _P0_5	=	0x0085
                    0086    416 G$P0_6$0$0 == 0x0086
                    0086    417 _P0_6	=	0x0086
                    0087    418 G$P0_7$0$0 == 0x0087
                    0087    419 _P0_7	=	0x0087
                    0090    420 G$P1_0$0$0 == 0x0090
                    0090    421 _P1_0	=	0x0090
                    0091    422 G$P1_1$0$0 == 0x0091
                    0091    423 _P1_1	=	0x0091
                    0092    424 G$P1_2$0$0 == 0x0092
                    0092    425 _P1_2	=	0x0092
                    0093    426 G$P1_3$0$0 == 0x0093
                    0093    427 _P1_3	=	0x0093
                    0094    428 G$P1_4$0$0 == 0x0094
                    0094    429 _P1_4	=	0x0094
                    0095    430 G$P1_5$0$0 == 0x0095
                    0095    431 _P1_5	=	0x0095
                    0096    432 G$P1_6$0$0 == 0x0096
                    0096    433 _P1_6	=	0x0096
                    0097    434 G$P1_7$0$0 == 0x0097
                    0097    435 _P1_7	=	0x0097
                    00B0    436 G$P3_0$0$0 == 0x00b0
                    00B0    437 _P3_0	=	0x00b0
                    00B1    438 G$P3_1$0$0 == 0x00b1
                    00B1    439 _P3_1	=	0x00b1
                            440 ;--------------------------------------------------------
                            441 ; overlayable register banks
                            442 ;--------------------------------------------------------
                            443 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     444 	.ds 8
                            445 ;--------------------------------------------------------
                            446 ; overlayable bit register bank
                            447 ;--------------------------------------------------------
                            448 	.area BIT_BANK	(REL,OVR,DATA)
   0023                     449 bits:
   0023                     450 	.ds 1
                    8000    451 	b0 = bits[0]
                    8100    452 	b1 = bits[1]
                    8200    453 	b2 = bits[2]
                    8300    454 	b3 = bits[3]
                    8400    455 	b4 = bits[4]
                    8500    456 	b5 = bits[5]
                    8600    457 	b6 = bits[6]
                    8700    458 	b7 = bits[7]
                            459 ;--------------------------------------------------------
                            460 ; internal ram data
                            461 ;--------------------------------------------------------
                            462 	.area DSEG    (DATA)
                    0000    463 G$RAM$0$0 == 0x0000
                    0000    464 _RAM	=	0x0000
                            465 ;--------------------------------------------------------
                            466 ; overlayable items in internal ram 
                            467 ;--------------------------------------------------------
                            468 	.area OSEG    (OVR,DATA)
                            469 ;--------------------------------------------------------
                            470 ; Stack segment in internal ram 
                            471 ;--------------------------------------------------------
                            472 	.area	SSEG	(DATA)
   006E                     473 __start__stack:
   006E                     474 	.ds	1
                            475 
                            476 ;--------------------------------------------------------
                            477 ; indirectly addressable internal ram data
                            478 ;--------------------------------------------------------
                            479 	.area ISEG    (DATA)
                            480 ;--------------------------------------------------------
                            481 ; absolute internal ram data
                            482 ;--------------------------------------------------------
                            483 	.area IABS    (ABS,DATA)
                            484 	.area IABS    (ABS,DATA)
                            485 ;--------------------------------------------------------
                            486 ; bit data
                            487 ;--------------------------------------------------------
                            488 	.area BSEG    (BIT)
                            489 ;--------------------------------------------------------
                            490 ; paged external ram data
                            491 ;--------------------------------------------------------
                            492 	.area PSEG    (PAG,XDATA)
                            493 ;--------------------------------------------------------
                            494 ; external ram data
                            495 ;--------------------------------------------------------
                            496 	.area XSEG    (XDATA)
                            497 ;--------------------------------------------------------
                            498 ; absolute external ram data
                            499 ;--------------------------------------------------------
                            500 	.area XABS    (ABS,XDATA)
                            501 ;--------------------------------------------------------
                            502 ; external initialized ram data
                            503 ;--------------------------------------------------------
                            504 	.area XISEG   (XDATA)
                            505 	.area HOME    (CODE)
                            506 	.area GSINIT0 (CODE)
                            507 	.area GSINIT1 (CODE)
                            508 	.area GSINIT2 (CODE)
                            509 	.area GSINIT3 (CODE)
                            510 	.area GSINIT4 (CODE)
                            511 	.area GSINIT5 (CODE)
                            512 	.area GSINIT  (CODE)
                            513 	.area GSFINAL (CODE)
                            514 	.area CSEG    (CODE)
                            515 ;--------------------------------------------------------
                            516 ; interrupt vector 
                            517 ;--------------------------------------------------------
                            518 	.area HOME    (CODE)
   0000                     519 __interrupt_vect:
   0000 02 00 43            520 	ljmp	__sdcc_gsinit_startup
   0003 32                  521 	reti
   0004                     522 	.ds	7
   000B 32                  523 	reti
   000C                     524 	.ds	7
   0013 02 11 EC            525 	ljmp	_X1_int
   0016                     526 	.ds	5
   001B 02 12 1C            527 	ljmp	_T1_int
   001E                     528 	.ds	5
   0023 32                  529 	reti
   0024                     530 	.ds	7
   002B 32                  531 	reti
   002C                     532 	.ds	7
   0033 32                  533 	reti
   0034                     534 	.ds	7
   003B 02 03 EF            535 	ljmp	_keypad_isr
                            536 ;--------------------------------------------------------
                            537 ; global & static initialisations
                            538 ;--------------------------------------------------------
                            539 	.area HOME    (CODE)
                            540 	.area GSINIT  (CODE)
                            541 	.area GSFINAL (CODE)
                            542 	.area GSINIT  (CODE)
                            543 	.globl __sdcc_gsinit_startup
                            544 	.globl __sdcc_program_startup
                            545 	.globl __start__stack
                            546 	.globl __mcs51_genXINIT
                            547 	.globl __mcs51_genXRAMCLEAR
                            548 	.globl __mcs51_genRAMCLEAR
                            549 	.area GSFINAL (CODE)
   00A2 02 00 3E            550 	ljmp	__sdcc_program_startup
                            551 ;--------------------------------------------------------
                            552 ; Home
                            553 ;--------------------------------------------------------
                            554 	.area HOME    (CODE)
                            555 	.area HOME    (CODE)
   003E                     556 __sdcc_program_startup:
   003E 12 00 A5            557 	lcall	_main
                            558 ;	return from main will lock up
   0041 80 FE               559 	sjmp .
                            560 ;--------------------------------------------------------
                            561 ; code
                            562 ;--------------------------------------------------------
                            563 	.area CSEG    (CODE)
                            564 ;------------------------------------------------------------
                            565 ;Allocation info for local variables in function 'main'
                            566 ;------------------------------------------------------------
                            567 ;n                         Allocated to registers r6 
                            568 ;cmd                       Allocated to registers r6 
                            569 ;tasterpegel               Allocated to registers r7 
                            570 ;tmp                       Allocated to registers r5 
                            571 ;cal                       Allocated to stack - _bp +1
                            572 ;pin                       Allocated to registers 
                            573 ;wduf                      Allocated to registers b1 
                            574 ;tastergetoggelt           Allocated to registers b0 
                            575 ;------------------------------------------------------------
                    0000    576 	G$main$0$0 ==.
                    0000    577 	C$fb_counter.c$34$0$0 ==.
                            578 ;	..\fb_counter.c:34: void main(void)
                            579 ;	-----------------------------------------
                            580 ;	 function main
                            581 ;	-----------------------------------------
   00A5                     582 _main:
                    0007    583 	ar7 = 0x07
                    0006    584 	ar6 = 0x06
                    0005    585 	ar5 = 0x05
                    0004    586 	ar4 = 0x04
                    0003    587 	ar3 = 0x03
                    0002    588 	ar2 = 0x02
                    0001    589 	ar1 = 0x01
                    0000    590 	ar0 = 0x00
   00A5 C0 6D               591 	push	_bp
   00A7 85 81 6D            592 	mov	_bp,sp
   00AA 05 81               593 	inc	sp
                    0007    594 	C$fb_counter.c$36$1$0 ==.
                            595 ;	..\fb_counter.c:36: unsigned char n,cmd,tasterpegel=0,tmp;
   00AC 7F 00               596 	mov	r7,#0x00
                    0009    597 	C$fb_counter.c$47$1$0 ==.
                            598 ;	..\fb_counter.c:47: __bit wduf,tastergetoggelt=0;
   00AE C2 18               599 	clr	b0
                    000B    600 	C$fb_counter.c$48$1$1 ==.
                            601 ;	..\fb_counter.c:48: wduf=WDCON&0x02;
   00B0 E5 A7               602 	mov	a,_WDCON
   00B2 03                  603 	rr	a
   00B3 54 01               604 	anl	a,#0x01
   00B5 FE                  605 	mov	r6,a
   00B6 24 FF               606 	add	a,#0xff
   00B8 92 19               607 	mov	b1,c
                    0015    608 	C$fb_counter.c$49$1$1 ==.
                            609 ;	..\fb_counter.c:49: TASTER=1;
   00BA D2 97               610 	setb	_P1_7
                    0017    611 	C$fb_counter.c$50$1$1 ==.
                            612 ;	..\fb_counter.c:50: if(!TASTER && wduf)cal=0;
   00BC 20 97 0A            613 	jb	_P1_7,00102$
   00BF 30 19 07            614 	jnb	b1,00102$
   00C2 A8 6D               615 	mov	r0,_bp
   00C4 08                  616 	inc	r0
   00C5 76 00               617 	mov	@r0,#0x00
   00C7 80 0B               618 	sjmp	00103$
   00C9                     619 00102$:
                    0024    620 	C$fb_counter.c$51$1$1 ==.
                            621 ;	..\fb_counter.c:51: else cal=trimsave;
   00C9 90 1C FF            622 	mov	dptr,#_main_trimsave_1_1
   00CC E4                  623 	clr	a
   00CD 93                  624 	movc	a,@a+dptr
   00CE FD                  625 	mov	r5,a
   00CF A8 6D               626 	mov	r0,_bp
   00D1 08                  627 	inc	r0
   00D2 A6 05               628 	mov	@r0,ar5
   00D4                     629 00103$:
                    002F    630 	C$fb_counter.c$52$1$1 ==.
                            631 ;	..\fb_counter.c:52: TRIM = (TRIM+trimsave);
   00D4 90 1C FF            632 	mov	dptr,#_main_trimsave_1_1
   00D7 E4                  633 	clr	a
   00D8 93                  634 	movc	a,@a+dptr
   00D9 AC 96               635 	mov	r4,_TRIM
   00DB 2C                  636 	add	a,r4
   00DC FD                  637 	mov	r5,a
   00DD 8D 96               638 	mov	_TRIM,r5
                    003A    639 	C$fb_counter.c$53$1$1 ==.
                            640 ;	..\fb_counter.c:53: TRIM &= 0x3F;//oberen 2 bits ausblenden
   00DF 53 96 3F            641 	anl	_TRIM,#0x3F
                    003D    642 	C$fb_counter.c$55$1$1 ==.
                            643 ;	..\fb_counter.c:55: restart_hw();				// Hardware zurücksetzen
   00E2 C0 07               644 	push	ar7
   00E4 C0 23               645 	push	bits
   00E6 12 1B 29            646 	lcall	_restart_hw
   00E9 D0 23               647 	pop	bits
                    0046    648 	C$fb_counter.c$58$1$1 ==.
                            649 ;	..\fb_counter.c:58: BRGCON&=0xFE;	// Baudrate Generator stoppen
   00EB 53 BD FE            650 	anl	_BRGCON,#0xFE
                    0049    651 	C$fb_counter.c$59$1$1 ==.
                            652 ;	..\fb_counter.c:59: P1M1&=0xFC;		// RX und TX auf bidirectional setzen
   00EE 53 91 FC            653 	anl	_P1M1,#0xFC
                    004C    654 	C$fb_counter.c$60$1$1 ==.
                            655 ;	..\fb_counter.c:60: P1M2&=0xFC;
   00F1 53 92 FC            656 	anl	_P1M2,#0xFC
                    004F    657 	C$fb_counter.c$61$1$1 ==.
                            658 ;	..\fb_counter.c:61: SCON=0x50;		// Mode 1, receive enable
   00F4 75 98 50            659 	mov	_SCON,#0x50
                    0052    660 	C$fb_counter.c$62$1$1 ==.
                            661 ;	..\fb_counter.c:62: SSTAT|=0xE0;	// TI wird am Ende des Stopbits gesetzt und Interrupt nur bei RX und double TX buffer an
   00F7 43 BA E0            662 	orl	_SSTAT,#0xE0
                    0055    663 	C$fb_counter.c$63$1$1 ==.
                            664 ;	..\fb_counter.c:63: BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
   00FA 43 BD 02            665 	orl	_BRGCON,#0x02
                    0058    666 	C$fb_counter.c$64$1$1 ==.
                            667 ;	..\fb_counter.c:64: BRGR1=0x2f;	// Baudrate = cclk/((BRGR1,BRGR0)+16)
   00FD 75 BF 2F            668 	mov	_BRGR1,#0x2F
                    005B    669 	C$fb_counter.c$65$1$1 ==.
                            670 ;	..\fb_counter.c:65: BRGR0=0xf0;	// für 115200 0030 nehmen, autocal: 600bd= 0x2FF0
   0100 75 BE F0            671 	mov	_BRGR0,#0xF0
                    005E    672 	C$fb_counter.c$66$1$1 ==.
                            673 ;	..\fb_counter.c:66: BRGCON|=0x01;	// Baudrate Generator starten
   0103 43 BD 01            674 	orl	_BRGCON,#0x01
                    0061    675 	C$fb_counter.c$67$1$1 ==.
                            676 ;	..\fb_counter.c:67: SBUF=0x55;
   0106 75 99 55            677 	mov	_SBUF,#0x55
                    0064    678 	C$fb_counter.c$73$1$1 ==.
                            679 ;	..\fb_counter.c:73: restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
   0109 C0 23               680 	push	bits
   010B 12 11 52            681 	lcall	_restart_app
   010E D0 23               682 	pop	bits
                    006B    683 	C$fb_counter.c$74$1$1 ==.
                            684 ;	..\fb_counter.c:74: keypad_init();			// keyboard interrupt initialisieren
   0110 C0 23               685 	push	bits
   0112 12 11 40            686 	lcall	_keypad_init
   0115 D0 23               687 	pop	bits
   0117 D0 07               688 	pop	ar7
                    0074    689 	C$fb_counter.c$77$1$1 ==.
                            690 ;	..\fb_counter.c:77: portbuffer=0;			// wenn schalter ein, eine obj change erzeugen
   0119 75 24 00            691 	mov	_portbuffer,#0x00
                    0077    692 	C$fb_counter.c$78$1$1 ==.
                            693 ;	..\fb_counter.c:78: p0h=portbuffer;
   011C 75 25 00            694 	mov	_p0h,#0x00
                    007A    695 	C$fb_counter.c$83$1$1 ==.
                            696 ;	..\fb_counter.c:83: if(!wduf){
   011F 20 19 21            697 	jb	b1,00109$
                    007D    698 	C$fb_counter.c$85$1$1 ==.
                            699 ;	..\fb_counter.c:85: for (n=0;n<50;n++) {		// Warten bis Bus stabil
   0122 7D 00               700 	mov	r5,#0x00
   0124                     701 00186$:
   0124 BD 32 00            702 	cjne	r5,#0x32,00257$
   0127                     703 00257$:
   0127 50 1A               704 	jnc	00109$
                    0084    705 	C$fb_counter.c$86$3$3 ==.
                            706 ;	..\fb_counter.c:86: TR0=0;					// Timer 0 anhalten
   0129 C2 8C               707 	clr	_TCON_4
                    0086    708 	C$fb_counter.c$87$3$3 ==.
                            709 ;	..\fb_counter.c:87: TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
   012B 90 1D 17            710 	mov	dptr,#(_eeprom + 0x0017)
   012E E4                  711 	clr	a
   012F 93                  712 	movc	a,@a+dptr
   0130 F5 8C               713 	mov	_TH0,a
                    008D    714 	C$fb_counter.c$88$3$3 ==.
                            715 ;	..\fb_counter.c:88: TL0=eeprom[ADDRTAB+2];
   0132 90 1D 18            716 	mov	dptr,#(_eeprom + 0x0018)
   0135 E4                  717 	clr	a
   0136 93                  718 	movc	a,@a+dptr
   0137 F5 8A               719 	mov	_TL0,a
                    0094    720 	C$fb_counter.c$89$3$3 ==.
                            721 ;	..\fb_counter.c:89: TF0=0;					// Überlauf-Flag zurücksetzen
   0139 C2 8D               722 	clr	_TCON_5
                    0096    723 	C$fb_counter.c$90$3$3 ==.
                            724 ;	..\fb_counter.c:90: TR0=1;					// Timer 0 starten
   013B D2 8C               725 	setb	_TCON_4
                    0098    726 	C$fb_counter.c$91$3$3 ==.
                            727 ;	..\fb_counter.c:91: while(!TF0);
   013D                     728 00105$:
   013D 30 8D FD            729 	jnb	_TCON_5,00105$
                    009B    730 	C$fb_counter.c$85$2$2 ==.
                            731 ;	..\fb_counter.c:85: for (n=0;n<50;n++) {		// Warten bis Bus stabil
   0140 0D                  732 	inc	r5
   0141 80 E1               733 	sjmp	00186$
   0143                     734 00109$:
                    009E    735 	C$fb_counter.c$97$1$1 ==.
                            736 ;	..\fb_counter.c:97: if(!wduf)bus_return();			// Anwendungsspezifische Einstellungen zurücksetzen
   0143 20 19 0B            737 	jb	b1,00111$
   0146 C0 07               738 	push	ar7
   0148 C0 23               739 	push	bits
   014A 12 0B 6B            740 	lcall	_bus_return
   014D D0 23               741 	pop	bits
   014F D0 07               742 	pop	ar7
   0151                     743 00111$:
                    00AC    744 	C$fb_counter.c$99$1$1 ==.
                            745 ;	..\fb_counter.c:99: TASTER=1;// progled/taster
   0151 D2 97               746 	setb	_P1_7
                    00AE    747 	C$fb_counter.c$100$1$1 ==.
                            748 ;	..\fb_counter.c:100: do  {
   0153                     749 00183$:
                    00AE    750 	C$fb_counter.c$109$2$4 ==.
                            751 ;	..\fb_counter.c:109: if(APPLICATION_RUN){
   0153 90 1D 0D            752 	mov	dptr,#(_eeprom + 0x000d)
   0156 E4                  753 	clr	a
   0157 93                  754 	movc	a,@a+dptr
   0158 FD                  755 	mov	r5,a
   0159 BD FF 02            756 	cjne	r5,#0xFF,00261$
   015C 80 03               757 	sjmp	00262$
   015E                     758 00261$:
   015E 02 03 41            759 	ljmp	00140$
   0161                     760 00262$:
   0161 30 13 03            761 	jnb	_connected,00263$
   0164 02 03 41            762 	ljmp	00140$
   0167                     763 00263$:
   0167 E5 6C               764 	mov	a,_status60
   0169 30 E0 03            765 	jnb	acc.0,00264$
   016C 02 03 41            766 	ljmp	00140$
   016F                     767 00264$:
                    00CA    768 	C$fb_counter.c$110$3$5 ==.
                            769 ;	..\fb_counter.c:110: EKBI = 1;
   016F D2 E9               770 	setb	_IEN1_1
                    00CC    771 	C$fb_counter.c$112$3$5 ==.
                            772 ;	..\fb_counter.c:112: p0h=P0;				// prüfen ob ein Eingang sich geändert hat
   0171 85 80 25            773 	mov	_p0h,_P0
                    00CF    774 	C$fb_counter.c$116$3$5 ==.
                            775 ;	..\fb_counter.c:116: if (p0h!=portbuffer) 
   0174 E5 24               776 	mov	a,_portbuffer
   0176 B5 25 02            777 	cjne	a,_p0h,00265$
   0179 80 2D               778 	sjmp	00221$
   017B                     779 00265$:
                    00D6    780 	C$fb_counter.c$118$5$7 ==.
                            781 ;	..\fb_counter.c:118: for(n=1;n<4;n+=2)					// jeden Eingangspin einzel prüfen
   017B 7D 01               782 	mov	r5,#0x01
   017D                     783 00190$:
   017D BD 04 00            784 	cjne	r5,#0x04,00266$
   0180                     785 00266$:
   0180 50 23               786 	jnc	00193$
                    00DD    787 	C$fb_counter.c$120$5$7 ==.
                            788 ;	..\fb_counter.c:120: if ((p0h^portbuffer) & bitmask_1[n] )//kürzeste Version
   0182 E5 24               789 	mov	a,_portbuffer
   0184 65 25               790 	xrl	a,_p0h
   0186 FC                  791 	mov	r4,a
   0187 ED                  792 	mov	a,r5
   0188 90 1C 6A            793 	mov	dptr,#_bitmask_1
   018B 93                  794 	movc	a,@a+dptr
   018C FB                  795 	mov	r3,a
   018D 5C                  796 	anl	a,r4
   018E 60 11               797 	jz	00192$
                    00EB    798 	C$fb_counter.c$122$6$8 ==.
                            799 ;	..\fb_counter.c:122: pin_changed(n);				// Änderung verarbeiten
   0190 8D 82               800 	mov	dpl,r5
   0192 C0 07               801 	push	ar7
   0194 C0 05               802 	push	ar5
   0196 C0 23               803 	push	bits
   0198 12 04 28            804 	lcall	_pin_changed
   019B D0 23               805 	pop	bits
   019D D0 05               806 	pop	ar5
   019F D0 07               807 	pop	ar7
   01A1                     808 00192$:
                    00FC    809 	C$fb_counter.c$118$4$6 ==.
                            810 ;	..\fb_counter.c:118: for(n=1;n<4;n+=2)					// jeden Eingangspin einzel prüfen
   01A1 0D                  811 	inc	r5
   01A2 0D                  812 	inc	r5
   01A3 80 D8               813 	sjmp	00190$
   01A5                     814 00193$:
                    0100    815 	C$fb_counter.c$125$4$6 ==.
                            816 ;	..\fb_counter.c:125: portbuffer=p0h;					// neuen Portzustand in buffer speichern
   01A5 85 25 24            817 	mov	_portbuffer,_p0h
                    0103    818 	C$fb_counter.c$130$1$1 ==.
                            819 ;	..\fb_counter.c:130: while (precounter0 && timerbase[0]<0x80){// wenn precounter0 was gezählt hat und keine Löschanforderung besteht
   01A8                     820 00221$:
   01A8                     821 00120$:
   01A8 E5 3C               822 	mov	a,_precounter0
   01AA 70 03               823 	jnz	00269$
   01AC 02 02 3F            824 	ljmp	00225$
   01AF                     825 00269$:
   01AF 74 80               826 	mov	a,#0x100 - 0x80
   01B1 25 2F               827 	add	a,_timerbase
   01B3 50 03               828 	jnc	00270$
   01B5 02 02 3F            829 	ljmp	00225$
   01B8                     830 00270$:
                    0113    831 	C$fb_counter.c$131$4$9 ==.
                            832 ;	..\fb_counter.c:131: tmp=precounter0;
   01B8 AD 3C               833 	mov	r5,_precounter0
                    0115    834 	C$fb_counter.c$132$4$9 ==.
                            835 ;	..\fb_counter.c:132: if(read_obj_value(2)==0){ // Tarif 1
   01BA 75 82 02            836 	mov	dpl,#0x02
   01BD C0 07               837 	push	ar7
   01BF C0 05               838 	push	ar5
   01C1 C0 23               839 	push	bits
   01C3 12 0B 6C            840 	lcall	_read_obj_value
   01C6 AA 82               841 	mov	r2,dpl
   01C8 AB 83               842 	mov	r3,dph
   01CA AC F0               843 	mov	r4,b
   01CC FE                  844 	mov	r6,a
   01CD D0 23               845 	pop	bits
   01CF D0 05               846 	pop	ar5
   01D1 D0 07               847 	pop	ar7
   01D3 EA                  848 	mov	a,r2
   01D4 4B                  849 	orl	a,r3
   01D5 4C                  850 	orl	a,r4
   01D6 4E                  851 	orl	a,r6
                    0132    852 	C$fb_counter.c$133$5$10 ==.
                            853 ;	..\fb_counter.c:133: counter_moment[0]+=tmp;
   01D7 70 2F               854 	jnz	00117$
   01D9 8D 04               855 	mov	ar4,r5
   01DB FE                  856 	mov	r6,a
   01DC EC                  857 	mov	a,r4
   01DD 25 18               858 	add	a,_counter_moment
   01DF FC                  859 	mov	r4,a
   01E0 EE                  860 	mov	a,r6
   01E1 35 19               861 	addc	a,(_counter_moment + 1)
   01E3 FE                  862 	mov	r6,a
   01E4 8C 18               863 	mov	(_counter_moment + 0),r4
   01E6 8E 19               864 	mov	(_counter_moment + 1),r6
                    0143    865 	C$fb_counter.c$134$5$10 ==.
                            866 ;	..\fb_counter.c:134: counter_summe[0]+=tmp;
   01E8 8D 02               867 	mov	ar2,r5
   01EA E4                  868 	clr	a
   01EB FB                  869 	mov	r3,a
   01EC FC                  870 	mov	r4,a
   01ED FE                  871 	mov	r6,a
   01EE EA                  872 	mov	a,r2
   01EF 25 08               873 	add	a,_counter_summe
   01F1 FA                  874 	mov	r2,a
   01F2 EB                  875 	mov	a,r3
   01F3 35 09               876 	addc	a,(_counter_summe + 1)
   01F5 FB                  877 	mov	r3,a
   01F6 EC                  878 	mov	a,r4
   01F7 35 0A               879 	addc	a,(_counter_summe + 2)
   01F9 FC                  880 	mov	r4,a
   01FA EE                  881 	mov	a,r6
   01FB 35 0B               882 	addc	a,(_counter_summe + 3)
   01FD FE                  883 	mov	r6,a
   01FE 8A 08               884 	mov	(_counter_summe + 0),r2
   0200 8B 09               885 	mov	(_counter_summe + 1),r3
   0202 8C 0A               886 	mov	(_counter_summe + 2),r4
   0204 8E 0B               887 	mov	(_counter_summe + 3),r6
   0206 80 2E               888 	sjmp	00118$
   0208                     889 00117$:
                    0163    890 	C$fb_counter.c$138$5$11 ==.
                            891 ;	..\fb_counter.c:138: counter_moment[1]+=tmp;
   0208 8D 04               892 	mov	ar4,r5
   020A 7E 00               893 	mov	r6,#0x00
   020C EC                  894 	mov	a,r4
   020D 25 1A               895 	add	a,(_counter_moment + 0x0002)
   020F FC                  896 	mov	r4,a
   0210 EE                  897 	mov	a,r6
   0211 35 1B               898 	addc	a,((_counter_moment + 0x0002) + 1)
   0213 FE                  899 	mov	r6,a
   0214 8C 1A               900 	mov	((_counter_moment + 0x0002) + 0),r4
   0216 8E 1B               901 	mov	((_counter_moment + 0x0002) + 1),r6
                    0173    902 	C$fb_counter.c$139$5$11 ==.
                            903 ;	..\fb_counter.c:139: counter_summe[1]+=tmp;
   0218 8D 02               904 	mov	ar2,r5
   021A E4                  905 	clr	a
   021B FB                  906 	mov	r3,a
   021C FC                  907 	mov	r4,a
   021D FE                  908 	mov	r6,a
   021E EA                  909 	mov	a,r2
   021F 25 0C               910 	add	a,(_counter_summe + 0x0004)
   0221 FA                  911 	mov	r2,a
   0222 EB                  912 	mov	a,r3
   0223 35 0D               913 	addc	a,((_counter_summe + 0x0004) + 1)
   0225 FB                  914 	mov	r3,a
   0226 EC                  915 	mov	a,r4
   0227 35 0E               916 	addc	a,((_counter_summe + 0x0004) + 2)
   0229 FC                  917 	mov	r4,a
   022A EE                  918 	mov	a,r6
   022B 35 0F               919 	addc	a,((_counter_summe + 0x0004) + 3)
   022D FE                  920 	mov	r6,a
   022E 8A 0C               921 	mov	((_counter_summe + 0x0004) + 0),r2
   0230 8B 0D               922 	mov	((_counter_summe + 0x0004) + 1),r3
   0232 8C 0E               923 	mov	((_counter_summe + 0x0004) + 2),r4
   0234 8E 0F               924 	mov	((_counter_summe + 0x0004) + 3),r6
   0236                     925 00118$:
                    0191    926 	C$fb_counter.c$141$4$9 ==.
                            927 ;	..\fb_counter.c:141: precounter0-=tmp;
   0236 E5 3C               928 	mov	a,_precounter0
   0238 C3                  929 	clr	c
   0239 9D                  930 	subb	a,r5
   023A F5 3C               931 	mov	_precounter0,a
   023C 02 01 A8            932 	ljmp	00120$
                    019A    933 	C$fb_counter.c$143$1$1 ==.
                            934 ;	..\fb_counter.c:143: while(precounter1 && timerbase [2]<0x80){// wenn precounter1 was gezählt hat und keine Löschanforderung besteht
   023F                     935 00225$:
   023F                     936 00127$:
   023F E5 3D               937 	mov	a,_precounter1
   0241 70 03               938 	jnz	00272$
   0243 02 02 D6            939 	ljmp	00129$
   0246                     940 00272$:
   0246 74 80               941 	mov	a,#0x100 - 0x80
   0248 25 31               942 	add	a,(_timerbase + 0x0002)
   024A 50 03               943 	jnc	00273$
   024C 02 02 D6            944 	ljmp	00129$
   024F                     945 00273$:
                    01AA    946 	C$fb_counter.c$144$4$12 ==.
                            947 ;	..\fb_counter.c:144: tmp=precounter1;
   024F AD 3D               948 	mov	r5,_precounter1
                    01AC    949 	C$fb_counter.c$145$4$12 ==.
                            950 ;	..\fb_counter.c:145: if(read_obj_value(15)==0){ // Tarif 1
   0251 75 82 0F            951 	mov	dpl,#0x0F
   0254 C0 07               952 	push	ar7
   0256 C0 05               953 	push	ar5
   0258 C0 23               954 	push	bits
   025A 12 0B 6C            955 	lcall	_read_obj_value
   025D AA 82               956 	mov	r2,dpl
   025F AB 83               957 	mov	r3,dph
   0261 AC F0               958 	mov	r4,b
   0263 FE                  959 	mov	r6,a
   0264 D0 23               960 	pop	bits
   0266 D0 05               961 	pop	ar5
   0268 D0 07               962 	pop	ar7
   026A EA                  963 	mov	a,r2
   026B 4B                  964 	orl	a,r3
   026C 4C                  965 	orl	a,r4
   026D 4E                  966 	orl	a,r6
                    01C9    967 	C$fb_counter.c$146$5$13 ==.
                            968 ;	..\fb_counter.c:146: counter_moment[2]+=tmp;
   026E 70 2F               969 	jnz	00124$
   0270 8D 04               970 	mov	ar4,r5
   0272 FE                  971 	mov	r6,a
   0273 EC                  972 	mov	a,r4
   0274 25 1C               973 	add	a,(_counter_moment + 0x0004)
   0276 FC                  974 	mov	r4,a
   0277 EE                  975 	mov	a,r6
   0278 35 1D               976 	addc	a,((_counter_moment + 0x0004) + 1)
   027A FE                  977 	mov	r6,a
   027B 8C 1C               978 	mov	((_counter_moment + 0x0004) + 0),r4
   027D 8E 1D               979 	mov	((_counter_moment + 0x0004) + 1),r6
                    01DA    980 	C$fb_counter.c$147$5$13 ==.
                            981 ;	..\fb_counter.c:147: counter_summe[2]+=tmp;
   027F 8D 02               982 	mov	ar2,r5
   0281 E4                  983 	clr	a
   0282 FB                  984 	mov	r3,a
   0283 FC                  985 	mov	r4,a
   0284 FE                  986 	mov	r6,a
   0285 EA                  987 	mov	a,r2
   0286 25 10               988 	add	a,(_counter_summe + 0x0008)
   0288 FA                  989 	mov	r2,a
   0289 EB                  990 	mov	a,r3
   028A 35 11               991 	addc	a,((_counter_summe + 0x0008) + 1)
   028C FB                  992 	mov	r3,a
   028D EC                  993 	mov	a,r4
   028E 35 12               994 	addc	a,((_counter_summe + 0x0008) + 2)
   0290 FC                  995 	mov	r4,a
   0291 EE                  996 	mov	a,r6
   0292 35 13               997 	addc	a,((_counter_summe + 0x0008) + 3)
   0294 FE                  998 	mov	r6,a
   0295 8A 10               999 	mov	((_counter_summe + 0x0008) + 0),r2
   0297 8B 11              1000 	mov	((_counter_summe + 0x0008) + 1),r3
   0299 8C 12              1001 	mov	((_counter_summe + 0x0008) + 2),r4
   029B 8E 13              1002 	mov	((_counter_summe + 0x0008) + 3),r6
   029D 80 2E              1003 	sjmp	00125$
   029F                    1004 00124$:
                    01FA   1005 	C$fb_counter.c$150$5$14 ==.
                           1006 ;	..\fb_counter.c:150: counter_moment[3]+=tmp;
   029F 8D 04              1007 	mov	ar4,r5
   02A1 7E 00              1008 	mov	r6,#0x00
   02A3 EC                 1009 	mov	a,r4
   02A4 25 1E              1010 	add	a,(_counter_moment + 0x0006)
   02A6 FC                 1011 	mov	r4,a
   02A7 EE                 1012 	mov	a,r6
   02A8 35 1F              1013 	addc	a,((_counter_moment + 0x0006) + 1)
   02AA FE                 1014 	mov	r6,a
   02AB 8C 1E              1015 	mov	((_counter_moment + 0x0006) + 0),r4
   02AD 8E 1F              1016 	mov	((_counter_moment + 0x0006) + 1),r6
                    020A   1017 	C$fb_counter.c$151$5$14 ==.
                           1018 ;	..\fb_counter.c:151: counter_summe[3]+=tmp;
   02AF 8D 02              1019 	mov	ar2,r5
   02B1 E4                 1020 	clr	a
   02B2 FB                 1021 	mov	r3,a
   02B3 FC                 1022 	mov	r4,a
   02B4 FE                 1023 	mov	r6,a
   02B5 EA                 1024 	mov	a,r2
   02B6 25 14              1025 	add	a,(_counter_summe + 0x000c)
   02B8 FA                 1026 	mov	r2,a
   02B9 EB                 1027 	mov	a,r3
   02BA 35 15              1028 	addc	a,((_counter_summe + 0x000c) + 1)
   02BC FB                 1029 	mov	r3,a
   02BD EC                 1030 	mov	a,r4
   02BE 35 16              1031 	addc	a,((_counter_summe + 0x000c) + 2)
   02C0 FC                 1032 	mov	r4,a
   02C1 EE                 1033 	mov	a,r6
   02C2 35 17              1034 	addc	a,((_counter_summe + 0x000c) + 3)
   02C4 FE                 1035 	mov	r6,a
   02C5 8A 14              1036 	mov	((_counter_summe + 0x000c) + 0),r2
   02C7 8B 15              1037 	mov	((_counter_summe + 0x000c) + 1),r3
   02C9 8C 16              1038 	mov	((_counter_summe + 0x000c) + 2),r4
   02CB 8E 17              1039 	mov	((_counter_summe + 0x000c) + 3),r6
   02CD                    1040 00125$:
                    0228   1041 	C$fb_counter.c$153$4$12 ==.
                           1042 ;	..\fb_counter.c:153: precounter1-=tmp;
   02CD E5 3D              1043 	mov	a,_precounter1
   02CF C3                 1044 	clr	c
   02D0 9D                 1045 	subb	a,r5
   02D1 F5 3D              1046 	mov	_precounter1,a
   02D3 02 02 3F           1047 	ljmp	00127$
   02D6                    1048 00129$:
                    0231   1049 	C$fb_counter.c$158$3$5 ==.
                           1050 ;	..\fb_counter.c:158: if (RTCCON>=0x80){
   02D6 74 80              1051 	mov	a,#0x100 - 0x80
   02D8 25 D1              1052 	add	a,_RTCCON
   02DA 50 0B              1053 	jnc	00231$
                    0237   1054 	C$fb_counter.c$159$4$15 ==.
                           1055 ;	..\fb_counter.c:159: delay_timer();	// Realtime clock ueberlauf
   02DC C0 07              1056 	push	ar7
   02DE C0 23              1057 	push	bits
   02E0 12 05 02           1058 	lcall	_delay_timer
   02E3 D0 23              1059 	pop	bits
   02E5 D0 07              1060 	pop	ar7
                    0242   1061 	C$fb_counter.c$164$1$1 ==.
                           1062 ;	..\fb_counter.c:164: for (n=0;n<4;n+=2){
   02E7                    1063 00231$:
   02E7 7E 00              1064 	mov	r6,#0x00
   02E9                    1065 00194$:
   02E9 BE 04 00           1066 	cjne	r6,#0x04,00276$
   02EC                    1067 00276$:
   02EC 50 55              1068 	jnc	00141$
                    0249   1069 	C$fb_counter.c$165$4$16 ==.
                           1070 ;	..\fb_counter.c:165: if(timerbase[n]& 0x80){// wenn Löschanforderung besteht
   02EE EE                 1071 	mov	a,r6
   02EF 24 2F              1072 	add	a,#_timerbase
   02F1 F9                 1073 	mov	r1,a
   02F2 E7                 1074 	mov	a,@r1
   02F3 FD                 1075 	mov	r5,a
   02F4 30 E7 46           1076 	jnb	acc.7,00196$
                    0252   1077 	C$fb_counter.c$166$5$17 ==.
                           1078 ;	..\fb_counter.c:166: if (!TR1){// warten bis statemachine fertig ist...
   02F7 20 8E 43           1079 	jb	_TCON_6,00196$
                    0255   1080 	C$fb_counter.c$167$6$18 ==.
                           1081 ;	..\fb_counter.c:167: checklevel(1,(timerbase[n]& 0xC0)+n);//checkt hier alle, also auch solche die noch nicht die Zeit erreicht haben!!
   02FA 53 05 C0           1082 	anl	ar5,#0xC0
   02FD EE                 1083 	mov	a,r6
   02FE 2D                 1084 	add	a,r5
   02FF FD                 1085 	mov	r5,a
   0300 D2 F0              1086 	setb	b[0]
   0302 C0 07              1087 	push	ar7
   0304 C0 06              1088 	push	ar6
   0306 C0 23              1089 	push	bits
   0308 85 F0 23           1090 	mov	bits,b
   030B 8D 82              1091 	mov	dpl,r5
   030D 12 09 2D           1092 	lcall	_checklevel
   0310 D0 23              1093 	pop	bits
   0312 D0 06              1094 	pop	ar6
   0314 D0 07              1095 	pop	ar7
                    0271   1096 	C$fb_counter.c$168$6$18 ==.
                           1097 ;	..\fb_counter.c:168: if (timerbase[n]& 0x40){// wenn Tarif 2
   0316 EE                 1098 	mov	a,r6
   0317 24 2F              1099 	add	a,#_timerbase
   0319 F9                 1100 	mov	r1,a
   031A E7                 1101 	mov	a,@r1
   031B FD                 1102 	mov	r5,a
   031C 30 E6 0F           1103 	jnb	acc.6,00133$
                    027A   1104 	C$fb_counter.c$169$7$19 ==.
                           1105 ;	..\fb_counter.c:169: counter_moment[n+1]=0;//Tarif2 löschen
   031F EE                 1106 	mov	a,r6
   0320 04                 1107 	inc	a
   0321 25 E0              1108 	add	a,acc
   0323 FC                 1109 	mov	r4,a
   0324 24 18              1110 	add	a,#_counter_moment
   0326 F8                 1111 	mov	r0,a
   0327 76 00              1112 	mov	@r0,#0x00
   0329 08                 1113 	inc	r0
   032A 76 00              1114 	mov	@r0,#0x00
   032C 80 0B              1115 	sjmp	00134$
   032E                    1116 00133$:
                    0289   1117 	C$fb_counter.c$172$7$20 ==.
                           1118 ;	..\fb_counter.c:172: counter_moment[n]=0;// sonst Tarif1 löschen
   032E EE                 1119 	mov	a,r6
   032F 2E                 1120 	add	a,r6
   0330 FC                 1121 	mov	r4,a
   0331 24 18              1122 	add	a,#_counter_moment
   0333 F8                 1123 	mov	r0,a
   0334 76 00              1124 	mov	@r0,#0x00
   0336 08                 1125 	inc	r0
   0337 76 00              1126 	mov	@r0,#0x00
   0339                    1127 00134$:
                    0294   1128 	C$fb_counter.c$174$6$18 ==.
                           1129 ;	..\fb_counter.c:174: timerbase[n]&= 0x3F;// Löschanforderung und Tarifflag zurücksetzen
   0339 74 3F              1130 	mov	a,#0x3F
   033B 5D                 1131 	anl	a,r5
   033C F7                 1132 	mov	@r1,a
   033D                    1133 00196$:
                    0298   1134 	C$fb_counter.c$164$3$5 ==.
                           1135 ;	..\fb_counter.c:164: for (n=0;n<4;n+=2){
   033D 0E                 1136 	inc	r6
   033E 0E                 1137 	inc	r6
   033F 80 A8              1138 	sjmp	00194$
   0341                    1139 00140$:
                    029C   1140 	C$fb_counter.c$182$2$4 ==.
                           1141 ;	..\fb_counter.c:182: else   EKBI = 0; // wenn die aplikation nicht läuft keyboard int abschalten
   0341 C2 E9              1142 	clr	_IEN1_1
   0343                    1143 00141$:
                    029E   1144 	C$fb_counter.c$184$2$4 ==.
                           1145 ;	..\fb_counter.c:184: if (tel_arrived ) {//|| tel_sent 
                    029E   1146 	C$fb_counter.c$185$3$21 ==.
                           1147 ;	..\fb_counter.c:185: tel_arrived=0;
   0343 10 0B 02           1148 	jbc	_tel_arrived,00281$
   0346 80 0F              1149 	sjmp	00145$
   0348                    1150 00281$:
                    02A3   1151 	C$fb_counter.c$186$3$21 ==.
                           1152 ;	..\fb_counter.c:186: tel_sent=0;
   0348 C2 0C              1153 	clr	_tel_sent
                    02A5   1154 	C$fb_counter.c$187$3$21 ==.
                           1155 ;	..\fb_counter.c:187: process_tel();
   034A C0 07              1156 	push	ar7
   034C C0 23              1157 	push	bits
   034E 12 18 5C           1158 	lcall	_process_tel
   0351 D0 23              1159 	pop	bits
   0353 D0 07              1160 	pop	ar7
   0355 80 0A              1161 	sjmp	00146$
   0357                    1162 00145$:
                    02B2   1163 	C$fb_counter.c$190$3$4 ==.
                           1164 ;	..\fb_counter.c:190: for(n=0;n<100;n++);	// falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann
   0357 7E 64              1165 	mov	r6,#0x64
   0359                    1166 00200$:
   0359 8E 05              1167 	mov	ar5,r6
   035B 1D                 1168 	dec	r5
   035C 8D 06              1169 	mov	ar6,r5
   035E EE                 1170 	mov	a,r6
   035F 70 F8              1171 	jnz	00200$
   0361                    1172 00146$:
                    02BC   1173 	C$fb_counter.c$196$2$4 ==.
                           1174 ;	..\fb_counter.c:196: if (RI){
                    02BC   1175 	C$fb_counter.c$197$3$23 ==.
                           1176 ;	..\fb_counter.c:197: RI=0;
   0361 10 98 02           1177 	jbc	_SCON_0,00283$
   0364 80 53              1178 	sjmp	00171$
   0366                    1179 00283$:
                    02C1   1180 	C$fb_counter.c$198$3$23 ==.
                           1181 ;	..\fb_counter.c:198: cmd=SBUF;
   0366 AE 99              1182 	mov	r6,_SBUF
                    02C3   1183 	C$fb_counter.c$199$3$23 ==.
                           1184 ;	..\fb_counter.c:199: if(cmd=='c'){
   0368 BE 63 08           1185 	cjne	r6,#0x63,00151$
                    02C6   1186 	C$fb_counter.c$200$4$24 ==.
                           1187 ;	..\fb_counter.c:200: while(!TI);
   036B                    1188 00147$:
                    02C6   1189 	C$fb_counter.c$201$4$24 ==.
                           1190 ;	..\fb_counter.c:201: TI=0;
   036B 10 99 02           1191 	jbc	_SCON_1,00286$
   036E 80 FB              1192 	sjmp	00147$
   0370                    1193 00286$:
                    02CB   1194 	C$fb_counter.c$202$4$24 ==.
                           1195 ;	..\fb_counter.c:202: SBUF=0x55;
   0370 75 99 55           1196 	mov	_SBUF,#0x55
   0373                    1197 00151$:
                    02CE   1198 	C$fb_counter.c$204$3$23 ==.
                           1199 ;	..\fb_counter.c:204: if(cmd=='+'){
   0373 BE 2B 06           1200 	cjne	r6,#0x2B,00153$
                    02D1   1201 	C$fb_counter.c$205$4$25 ==.
                           1202 ;	..\fb_counter.c:205: TRIM--;
   0376 15 96              1203 	dec	_TRIM
                    02D3   1204 	C$fb_counter.c$206$4$25 ==.
                           1205 ;	..\fb_counter.c:206: cal--;
   0378 A8 6D              1206 	mov	r0,_bp
   037A 08                 1207 	inc	r0
   037B 16                 1208 	dec	@r0
   037C                    1209 00153$:
                    02D7   1210 	C$fb_counter.c$208$3$23 ==.
                           1211 ;	..\fb_counter.c:208: if(cmd=='-'){
   037C BE 2D 06           1212 	cjne	r6,#0x2D,00155$
                    02DA   1213 	C$fb_counter.c$209$4$26 ==.
                           1214 ;	..\fb_counter.c:209: TRIM++;
   037F 05 96              1215 	inc	_TRIM
                    02DC   1216 	C$fb_counter.c$210$4$26 ==.
                           1217 ;	..\fb_counter.c:210: cal++;
   0381 A8 6D              1218 	mov	r0,_bp
   0383 08                 1219 	inc	r0
   0384 06                 1220 	inc	@r0
   0385                    1221 00155$:
                    02E0   1222 	C$fb_counter.c$212$3$23 ==.
                           1223 ;	..\fb_counter.c:212: if(cmd=='w'){
   0385 BE 77 15           1224 	cjne	r6,#0x77,00157$
                    02E3   1225 	C$fb_counter.c$213$4$27 ==.
                           1226 ;	..\fb_counter.c:213: EA=0;
   0388 C2 AF              1227 	clr	_IEN0_7
                    02E5   1228 	C$fb_counter.c$214$4$27 ==.
                           1229 ;	..\fb_counter.c:214: START_WRITECYCLE;	//cal an 0x1CFF schreiben
   038A 75 E4 00           1230 	mov	_FMCON,#0x00
                    02E8   1231 	C$fb_counter.c$216$4$27 ==.
                           1232 ;	..\fb_counter.c:216: FMADRH= 0x1C;		
   038D 75 E7 1C           1233 	mov	_FMADRH,#0x1C
                    02EB   1234 	C$fb_counter.c$217$4$27 ==.
                           1235 ;	..\fb_counter.c:217: FMADRL= 0xFF; 
   0390 75 E6 FF           1236 	mov	_FMADRL,#0xFF
                    02EE   1237 	C$fb_counter.c$219$4$27 ==.
                           1238 ;	..\fb_counter.c:219: FMDATA=	cal;
   0393 A8 6D              1239 	mov	r0,_bp
   0395 08                 1240 	inc	r0
   0396 86 E5              1241 	mov	_FMDATA,@r0
                    02F3   1242 	C$fb_counter.c$220$4$27 ==.
                           1243 ;	..\fb_counter.c:220: STOP_WRITECYCLE;
   0398 75 E4 68           1244 	mov	_FMCON,#0x68
                    02F6   1245 	C$fb_counter.c$221$4$27 ==.
                           1246 ;	..\fb_counter.c:221: EA=1;				//int wieder freigeben
   039B D2 AF              1247 	setb	_IEN0_7
   039D                    1248 00157$:
                    02F8   1249 	C$fb_counter.c$223$3$23 ==.
                           1250 ;	..\fb_counter.c:223: if(cmd=='p')status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
   039D BE 70 03           1251 	cjne	r6,#0x70,00159$
   03A0 63 6C 81           1252 	xrl	_status60,#0x81
   03A3                    1253 00159$:
                    02FE   1254 	C$fb_counter.c$225$3$23 ==.
                           1255 ;	..\fb_counter.c:225: if(cmd=='v'){
   03A3 BE 76 08           1256 	cjne	r6,#0x76,00164$
                    0301   1257 	C$fb_counter.c$226$4$28 ==.
                           1258 ;	..\fb_counter.c:226: while(!TI);
   03A6                    1259 00160$:
                    0301   1260 	C$fb_counter.c$227$4$28 ==.
                           1261 ;	..\fb_counter.c:227: TI=0;
   03A6 10 99 02           1262 	jbc	_SCON_1,00297$
   03A9 80 FB              1263 	sjmp	00160$
   03AB                    1264 00297$:
                    0306   1265 	C$fb_counter.c$228$4$28 ==.
                           1266 ;	..\fb_counter.c:228: SBUF=VERSION;
   03AB 75 99 00           1267 	mov	_SBUF,#0x00
   03AE                    1268 00164$:
                    0309   1269 	C$fb_counter.c$230$3$23 ==.
                           1270 ;	..\fb_counter.c:230: if(cmd=='t'){
   03AE BE 74 08           1271 	cjne	r6,#0x74,00171$
                    030C   1272 	C$fb_counter.c$231$4$29 ==.
                           1273 ;	..\fb_counter.c:231: while(!TI);
   03B1                    1274 00165$:
                    030C   1275 	C$fb_counter.c$232$4$29 ==.
                           1276 ;	..\fb_counter.c:232: TI=0;
   03B1 10 99 02           1277 	jbc	_SCON_1,00300$
   03B4 80 FB              1278 	sjmp	00165$
   03B6                    1279 00300$:
                    0311   1280 	C$fb_counter.c$233$4$29 ==.
                           1281 ;	..\fb_counter.c:233: SBUF=TYPE;
   03B6 75 99 00           1282 	mov	_SBUF,#0x00
   03B9                    1283 00171$:
                    0314   1284 	C$fb_counter.c$238$2$4 ==.
                           1285 ;	..\fb_counter.c:238: TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
   03B9 D2 97              1286 	setb	_P1_7
                    0316   1287 	C$fb_counter.c$239$2$4 ==.
                           1288 ;	..\fb_counter.c:239: if(!TASTER){ // Taster gedrückt
   03BB 20 97 12           1289 	jb	_P1_7,00181$
                    0319   1290 	C$fb_counter.c$240$3$30 ==.
                           1291 ;	..\fb_counter.c:240: if(tasterpegel<255)	tasterpegel++;
   03BE BF FF 00           1292 	cjne	r7,#0xFF,00302$
   03C1                    1293 00302$:
   03C1 50 03              1294 	jnc	00175$
   03C3 0F                 1295 	inc	r7
   03C4 80 12              1296 	sjmp	00182$
   03C6                    1297 00175$:
                    0321   1298 	C$fb_counter.c$242$4$31 ==.
                           1299 ;	..\fb_counter.c:242: if(!tastergetoggelt)status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
   03C6 20 18 03           1300 	jb	b0,00173$
   03C9 63 6C 81           1301 	xrl	_status60,#0x81
   03CC                    1302 00173$:
                    0327   1303 	C$fb_counter.c$243$4$31 ==.
                           1304 ;	..\fb_counter.c:243: tastergetoggelt=1;
   03CC D2 18              1305 	setb	b0
   03CE 80 08              1306 	sjmp	00182$
   03D0                    1307 00181$:
                    032B   1308 	C$fb_counter.c$247$3$32 ==.
                           1309 ;	..\fb_counter.c:247: if(tasterpegel>0) tasterpegel--;
   03D0 EF                 1310 	mov	a,r7
   03D1 60 03              1311 	jz	00178$
   03D3 1F                 1312 	dec	r7
   03D4 80 02              1313 	sjmp	00182$
   03D6                    1314 00178$:
                    0331   1315 	C$fb_counter.c$248$3$32 ==.
                           1316 ;	..\fb_counter.c:248: else tastergetoggelt=0;
   03D6 C2 18              1317 	clr	b0
   03D8                    1318 00182$:
                    0333   1319 	C$fb_counter.c$250$2$4 ==.
                           1320 ;	..\fb_counter.c:250: TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
   03D8 E5 6C              1321 	mov	a,_status60
   03DA 54 01              1322 	anl	a,#0x01
   03DC FE                 1323 	mov	r6,a
   03DD B4 01 00           1324 	cjne	a,#0x01,00306$
   03E0                    1325 00306$:
   03E0 E4                 1326 	clr	a
   03E1 33                 1327 	rlc	a
   03E2 FE                 1328 	mov	r6,a
   03E3 24 FF              1329 	add	a,#0xff
   03E5 92 97              1330 	mov	_P1_7,c
                    0342   1331 	C$fb_counter.c$252$1$1 ==.
                           1332 ;	..\fb_counter.c:252: } while(1);
   03E7 02 01 53           1333 	ljmp	00183$
   03EA 15 81              1334 	dec	sp
   03EC D0 6D              1335 	pop	_bp
                    0349   1336 	C$fb_counter.c$253$1$1 ==.
                    0349   1337 	XG$main$0$0 ==.
   03EE 22                 1338 	ret
                           1339 	.area CSEG    (CODE)
                           1340 	.area CONST   (CODE)
                    0000   1341 G$bitmask_1$0$0 == .
   1C6A                    1342 _bitmask_1:
   1C6A 01                 1343 	.db #0x01	; 1
   1C6B 02                 1344 	.db #0x02	; 2
   1C6C 04                 1345 	.db #0x04	; 4
   1C6D 08                 1346 	.db #0x08	; 8
   1C6E 10                 1347 	.db #0x10	; 16
   1C6F 20                 1348 	.db #0x20	; 32
   1C70 40                 1349 	.db #0x40	; 64
   1C71 80                 1350 	.db #0x80	; 128
                    01CE   1351 G$space$0$0 == 0x01ce
                    01CE   1352 _space	=	0x01ce
                    1CFF   1353 Lfb_counter.main$trimsave$1$1 == 0x1cff
                    1CFF   1354 _main_trimsave_1_1	=	0x1cff
                           1355 	.area XINIT   (CODE)
                           1356 	.area CABS    (ABS,CODE)
