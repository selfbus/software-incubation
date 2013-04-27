                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Sat Apr 27 17:57:21 2013
                              5 ;--------------------------------------------------------
                              6 	.module fb_rollo10
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _restart_app
                             14 	.globl _bus_return
                             15 	.globl _port_schalten
                             16 	.globl _delay_timer
                             17 	.globl _process_tel
                             18 	.globl _restart_hw
                             19 	.globl _P3_1
                             20 	.globl _P3_0
                             21 	.globl _P1_7
                             22 	.globl _P1_6
                             23 	.globl _P1_5
                             24 	.globl _P1_4
                             25 	.globl _P1_3
                             26 	.globl _P1_2
                             27 	.globl _P1_1
                             28 	.globl _P1_0
                             29 	.globl _P0_7
                             30 	.globl _P0_6
                             31 	.globl _P0_5
                             32 	.globl _P0_4
                             33 	.globl _P0_3
                             34 	.globl _P0_2
                             35 	.globl _P0_1
                             36 	.globl _P0_0
                             37 	.globl _I2CON_0
                             38 	.globl _I2CON_2
                             39 	.globl _I2CON_3
                             40 	.globl _I2CON_4
                             41 	.globl _I2CON_5
                             42 	.globl _I2CON_6
                             43 	.globl _SCON_7
                             44 	.globl _SCON_6
                             45 	.globl _SCON_5
                             46 	.globl _SCON_4
                             47 	.globl _SCON_3
                             48 	.globl _SCON_2
                             49 	.globl _SCON_1
                             50 	.globl _SCON_0
                             51 	.globl _IP0_0
                             52 	.globl _IP0_1
                             53 	.globl _IP0_2
                             54 	.globl _IP0_3
                             55 	.globl _IP0_4
                             56 	.globl _IP0_5
                             57 	.globl _IP0_6
                             58 	.globl _IP1_0
                             59 	.globl _IP1_1
                             60 	.globl _IP1_2
                             61 	.globl _IP1_6
                             62 	.globl _IEN1_0
                             63 	.globl _IEN1_1
                             64 	.globl _IEN1_2
                             65 	.globl _IEN0_0
                             66 	.globl _IEN0_1
                             67 	.globl _IEN0_2
                             68 	.globl _IEN0_3
                             69 	.globl _IEN0_4
                             70 	.globl _IEN0_5
                             71 	.globl _IEN0_6
                             72 	.globl _IEN0_7
                             73 	.globl _TCON_0
                             74 	.globl _TCON_1
                             75 	.globl _TCON_2
                             76 	.globl _TCON_3
                             77 	.globl _TCON_4
                             78 	.globl _TCON_5
                             79 	.globl _TCON_6
                             80 	.globl _TCON_7
                             81 	.globl _PSW_7
                             82 	.globl _PSW_6
                             83 	.globl _PSW_5
                             84 	.globl _PSW_4
                             85 	.globl _PSW_3
                             86 	.globl _PSW_2
                             87 	.globl _PSW_1
                             88 	.globl _PSW_0
                             89 	.globl _IEN1
                             90 	.globl _IP0H
                             91 	.globl _WFEED2
                             92 	.globl _WFEED1
                             93 	.globl _WDL
                             94 	.globl _WDCON
                             95 	.globl _TRIM
                             96 	.globl _TAMOD
                             97 	.globl _SSTAT
                             98 	.globl _RTCL
                             99 	.globl _RTCH
                            100 	.globl _RTCCON
                            101 	.globl _RSTSRC
                            102 	.globl _PT0AD
                            103 	.globl _PCONA
                            104 	.globl _P3M2
                            105 	.globl _P3M1
                            106 	.globl _P1M2
                            107 	.globl _P1M1
                            108 	.globl _P0M2
                            109 	.globl _P0M1
                            110 	.globl _KBPATN
                            111 	.globl _KBMASK
                            112 	.globl _KBCON
                            113 	.globl _IP1H
                            114 	.globl _IP1
                            115 	.globl _I2STAT
                            116 	.globl _I2SCLL
                            117 	.globl _I2SCLH
                            118 	.globl _I2DAT
                            119 	.globl _I2CON
                            120 	.globl _I2ADR
                            121 	.globl _FMDATA
                            122 	.globl _FMCON
                            123 	.globl _FMADRL
                            124 	.globl _FMADRH
                            125 	.globl _DIVM
                            126 	.globl _CMP2
                            127 	.globl _CMP1
                            128 	.globl _BRGCON
                            129 	.globl _BRGR1
                            130 	.globl _BRGR0
                            131 	.globl _SADEN
                            132 	.globl _SADDR
                            133 	.globl _AUXR1
                            134 	.globl _SBUF
                            135 	.globl _SCON
                            136 	.globl _IP0
                            137 	.globl _IEN0
                            138 	.globl _TH1
                            139 	.globl _TH0
                            140 	.globl _TL1
                            141 	.globl _TL0
                            142 	.globl _TMOD
                            143 	.globl _TCON
                            144 	.globl _PCON
                            145 	.globl _DPH
                            146 	.globl _DPL
                            147 	.globl _SP
                            148 	.globl _B
                            149 	.globl _ACC
                            150 	.globl _PSW
                            151 	.globl _P3
                            152 	.globl _P1
                            153 	.globl _P0
                            154 	.globl _RAM
                            155 ;--------------------------------------------------------
                            156 ; special function registers
                            157 ;--------------------------------------------------------
                            158 	.area RSEG    (ABS,DATA)
   0000                     159 	.org 0x0000
                    0080    160 G$P0$0$0 == 0x0080
                    0080    161 _P0	=	0x0080
                    0090    162 G$P1$0$0 == 0x0090
                    0090    163 _P1	=	0x0090
                    00B0    164 G$P3$0$0 == 0x00b0
                    00B0    165 _P3	=	0x00b0
                    00D0    166 G$PSW$0$0 == 0x00d0
                    00D0    167 _PSW	=	0x00d0
                    00E0    168 G$ACC$0$0 == 0x00e0
                    00E0    169 _ACC	=	0x00e0
                    00F0    170 G$B$0$0 == 0x00f0
                    00F0    171 _B	=	0x00f0
                    0081    172 G$SP$0$0 == 0x0081
                    0081    173 _SP	=	0x0081
                    0082    174 G$DPL$0$0 == 0x0082
                    0082    175 _DPL	=	0x0082
                    0083    176 G$DPH$0$0 == 0x0083
                    0083    177 _DPH	=	0x0083
                    0087    178 G$PCON$0$0 == 0x0087
                    0087    179 _PCON	=	0x0087
                    0088    180 G$TCON$0$0 == 0x0088
                    0088    181 _TCON	=	0x0088
                    0089    182 G$TMOD$0$0 == 0x0089
                    0089    183 _TMOD	=	0x0089
                    008A    184 G$TL0$0$0 == 0x008a
                    008A    185 _TL0	=	0x008a
                    008B    186 G$TL1$0$0 == 0x008b
                    008B    187 _TL1	=	0x008b
                    008C    188 G$TH0$0$0 == 0x008c
                    008C    189 _TH0	=	0x008c
                    008D    190 G$TH1$0$0 == 0x008d
                    008D    191 _TH1	=	0x008d
                    00A8    192 G$IEN0$0$0 == 0x00a8
                    00A8    193 _IEN0	=	0x00a8
                    00B8    194 G$IP0$0$0 == 0x00b8
                    00B8    195 _IP0	=	0x00b8
                    0098    196 G$SCON$0$0 == 0x0098
                    0098    197 _SCON	=	0x0098
                    0099    198 G$SBUF$0$0 == 0x0099
                    0099    199 _SBUF	=	0x0099
                    00A2    200 G$AUXR1$0$0 == 0x00a2
                    00A2    201 _AUXR1	=	0x00a2
                    00A9    202 G$SADDR$0$0 == 0x00a9
                    00A9    203 _SADDR	=	0x00a9
                    00B9    204 G$SADEN$0$0 == 0x00b9
                    00B9    205 _SADEN	=	0x00b9
                    00BE    206 G$BRGR0$0$0 == 0x00be
                    00BE    207 _BRGR0	=	0x00be
                    00BF    208 G$BRGR1$0$0 == 0x00bf
                    00BF    209 _BRGR1	=	0x00bf
                    00BD    210 G$BRGCON$0$0 == 0x00bd
                    00BD    211 _BRGCON	=	0x00bd
                    00AC    212 G$CMP1$0$0 == 0x00ac
                    00AC    213 _CMP1	=	0x00ac
                    00AD    214 G$CMP2$0$0 == 0x00ad
                    00AD    215 _CMP2	=	0x00ad
                    0095    216 G$DIVM$0$0 == 0x0095
                    0095    217 _DIVM	=	0x0095
                    00E7    218 G$FMADRH$0$0 == 0x00e7
                    00E7    219 _FMADRH	=	0x00e7
                    00E6    220 G$FMADRL$0$0 == 0x00e6
                    00E6    221 _FMADRL	=	0x00e6
                    00E4    222 G$FMCON$0$0 == 0x00e4
                    00E4    223 _FMCON	=	0x00e4
                    00E5    224 G$FMDATA$0$0 == 0x00e5
                    00E5    225 _FMDATA	=	0x00e5
                    00DB    226 G$I2ADR$0$0 == 0x00db
                    00DB    227 _I2ADR	=	0x00db
                    00D8    228 G$I2CON$0$0 == 0x00d8
                    00D8    229 _I2CON	=	0x00d8
                    00DA    230 G$I2DAT$0$0 == 0x00da
                    00DA    231 _I2DAT	=	0x00da
                    00DD    232 G$I2SCLH$0$0 == 0x00dd
                    00DD    233 _I2SCLH	=	0x00dd
                    00DC    234 G$I2SCLL$0$0 == 0x00dc
                    00DC    235 _I2SCLL	=	0x00dc
                    00D9    236 G$I2STAT$0$0 == 0x00d9
                    00D9    237 _I2STAT	=	0x00d9
                    00F8    238 G$IP1$0$0 == 0x00f8
                    00F8    239 _IP1	=	0x00f8
                    00F7    240 G$IP1H$0$0 == 0x00f7
                    00F7    241 _IP1H	=	0x00f7
                    0094    242 G$KBCON$0$0 == 0x0094
                    0094    243 _KBCON	=	0x0094
                    0086    244 G$KBMASK$0$0 == 0x0086
                    0086    245 _KBMASK	=	0x0086
                    0093    246 G$KBPATN$0$0 == 0x0093
                    0093    247 _KBPATN	=	0x0093
                    0084    248 G$P0M1$0$0 == 0x0084
                    0084    249 _P0M1	=	0x0084
                    0085    250 G$P0M2$0$0 == 0x0085
                    0085    251 _P0M2	=	0x0085
                    0091    252 G$P1M1$0$0 == 0x0091
                    0091    253 _P1M1	=	0x0091
                    0092    254 G$P1M2$0$0 == 0x0092
                    0092    255 _P1M2	=	0x0092
                    00B1    256 G$P3M1$0$0 == 0x00b1
                    00B1    257 _P3M1	=	0x00b1
                    00B2    258 G$P3M2$0$0 == 0x00b2
                    00B2    259 _P3M2	=	0x00b2
                    00B5    260 G$PCONA$0$0 == 0x00b5
                    00B5    261 _PCONA	=	0x00b5
                    00F6    262 G$PT0AD$0$0 == 0x00f6
                    00F6    263 _PT0AD	=	0x00f6
                    00DF    264 G$RSTSRC$0$0 == 0x00df
                    00DF    265 _RSTSRC	=	0x00df
                    00D1    266 G$RTCCON$0$0 == 0x00d1
                    00D1    267 _RTCCON	=	0x00d1
                    00D2    268 G$RTCH$0$0 == 0x00d2
                    00D2    269 _RTCH	=	0x00d2
                    00D3    270 G$RTCL$0$0 == 0x00d3
                    00D3    271 _RTCL	=	0x00d3
                    00BA    272 G$SSTAT$0$0 == 0x00ba
                    00BA    273 _SSTAT	=	0x00ba
                    008F    274 G$TAMOD$0$0 == 0x008f
                    008F    275 _TAMOD	=	0x008f
                    0096    276 G$TRIM$0$0 == 0x0096
                    0096    277 _TRIM	=	0x0096
                    00A7    278 G$WDCON$0$0 == 0x00a7
                    00A7    279 _WDCON	=	0x00a7
                    00C1    280 G$WDL$0$0 == 0x00c1
                    00C1    281 _WDL	=	0x00c1
                    00C2    282 G$WFEED1$0$0 == 0x00c2
                    00C2    283 _WFEED1	=	0x00c2
                    00C3    284 G$WFEED2$0$0 == 0x00c3
                    00C3    285 _WFEED2	=	0x00c3
                    00B7    286 G$IP0H$0$0 == 0x00b7
                    00B7    287 _IP0H	=	0x00b7
                    00E8    288 G$IEN1$0$0 == 0x00e8
                    00E8    289 _IEN1	=	0x00e8
                            290 ;--------------------------------------------------------
                            291 ; special function bits
                            292 ;--------------------------------------------------------
                            293 	.area RSEG    (ABS,DATA)
   0000                     294 	.org 0x0000
                    00D0    295 G$PSW_0$0$0 == 0x00d0
                    00D0    296 _PSW_0	=	0x00d0
                    00D1    297 G$PSW_1$0$0 == 0x00d1
                    00D1    298 _PSW_1	=	0x00d1
                    00D2    299 G$PSW_2$0$0 == 0x00d2
                    00D2    300 _PSW_2	=	0x00d2
                    00D3    301 G$PSW_3$0$0 == 0x00d3
                    00D3    302 _PSW_3	=	0x00d3
                    00D4    303 G$PSW_4$0$0 == 0x00d4
                    00D4    304 _PSW_4	=	0x00d4
                    00D5    305 G$PSW_5$0$0 == 0x00d5
                    00D5    306 _PSW_5	=	0x00d5
                    00D6    307 G$PSW_6$0$0 == 0x00d6
                    00D6    308 _PSW_6	=	0x00d6
                    00D7    309 G$PSW_7$0$0 == 0x00d7
                    00D7    310 _PSW_7	=	0x00d7
                    008F    311 G$TCON_7$0$0 == 0x008f
                    008F    312 _TCON_7	=	0x008f
                    008E    313 G$TCON_6$0$0 == 0x008e
                    008E    314 _TCON_6	=	0x008e
                    008D    315 G$TCON_5$0$0 == 0x008d
                    008D    316 _TCON_5	=	0x008d
                    008C    317 G$TCON_4$0$0 == 0x008c
                    008C    318 _TCON_4	=	0x008c
                    008B    319 G$TCON_3$0$0 == 0x008b
                    008B    320 _TCON_3	=	0x008b
                    008A    321 G$TCON_2$0$0 == 0x008a
                    008A    322 _TCON_2	=	0x008a
                    0089    323 G$TCON_1$0$0 == 0x0089
                    0089    324 _TCON_1	=	0x0089
                    0088    325 G$TCON_0$0$0 == 0x0088
                    0088    326 _TCON_0	=	0x0088
                    00AF    327 G$IEN0_7$0$0 == 0x00af
                    00AF    328 _IEN0_7	=	0x00af
                    00AE    329 G$IEN0_6$0$0 == 0x00ae
                    00AE    330 _IEN0_6	=	0x00ae
                    00AD    331 G$IEN0_5$0$0 == 0x00ad
                    00AD    332 _IEN0_5	=	0x00ad
                    00AC    333 G$IEN0_4$0$0 == 0x00ac
                    00AC    334 _IEN0_4	=	0x00ac
                    00AB    335 G$IEN0_3$0$0 == 0x00ab
                    00AB    336 _IEN0_3	=	0x00ab
                    00AA    337 G$IEN0_2$0$0 == 0x00aa
                    00AA    338 _IEN0_2	=	0x00aa
                    00A9    339 G$IEN0_1$0$0 == 0x00a9
                    00A9    340 _IEN0_1	=	0x00a9
                    00A8    341 G$IEN0_0$0$0 == 0x00a8
                    00A8    342 _IEN0_0	=	0x00a8
                    00EA    343 G$IEN1_2$0$0 == 0x00ea
                    00EA    344 _IEN1_2	=	0x00ea
                    00E9    345 G$IEN1_1$0$0 == 0x00e9
                    00E9    346 _IEN1_1	=	0x00e9
                    00E8    347 G$IEN1_0$0$0 == 0x00e8
                    00E8    348 _IEN1_0	=	0x00e8
                    00FE    349 G$IP1_6$0$0 == 0x00fe
                    00FE    350 _IP1_6	=	0x00fe
                    00FA    351 G$IP1_2$0$0 == 0x00fa
                    00FA    352 _IP1_2	=	0x00fa
                    00F9    353 G$IP1_1$0$0 == 0x00f9
                    00F9    354 _IP1_1	=	0x00f9
                    00F8    355 G$IP1_0$0$0 == 0x00f8
                    00F8    356 _IP1_0	=	0x00f8
                    00BE    357 G$IP0_6$0$0 == 0x00be
                    00BE    358 _IP0_6	=	0x00be
                    00BD    359 G$IP0_5$0$0 == 0x00bd
                    00BD    360 _IP0_5	=	0x00bd
                    00BC    361 G$IP0_4$0$0 == 0x00bc
                    00BC    362 _IP0_4	=	0x00bc
                    00BB    363 G$IP0_3$0$0 == 0x00bb
                    00BB    364 _IP0_3	=	0x00bb
                    00BA    365 G$IP0_2$0$0 == 0x00ba
                    00BA    366 _IP0_2	=	0x00ba
                    00B9    367 G$IP0_1$0$0 == 0x00b9
                    00B9    368 _IP0_1	=	0x00b9
                    00B8    369 G$IP0_0$0$0 == 0x00b8
                    00B8    370 _IP0_0	=	0x00b8
                    0098    371 G$SCON_0$0$0 == 0x0098
                    0098    372 _SCON_0	=	0x0098
                    0099    373 G$SCON_1$0$0 == 0x0099
                    0099    374 _SCON_1	=	0x0099
                    009A    375 G$SCON_2$0$0 == 0x009a
                    009A    376 _SCON_2	=	0x009a
                    009B    377 G$SCON_3$0$0 == 0x009b
                    009B    378 _SCON_3	=	0x009b
                    009C    379 G$SCON_4$0$0 == 0x009c
                    009C    380 _SCON_4	=	0x009c
                    009D    381 G$SCON_5$0$0 == 0x009d
                    009D    382 _SCON_5	=	0x009d
                    009E    383 G$SCON_6$0$0 == 0x009e
                    009E    384 _SCON_6	=	0x009e
                    009F    385 G$SCON_7$0$0 == 0x009f
                    009F    386 _SCON_7	=	0x009f
                    00DE    387 G$I2CON_6$0$0 == 0x00de
                    00DE    388 _I2CON_6	=	0x00de
                    00DD    389 G$I2CON_5$0$0 == 0x00dd
                    00DD    390 _I2CON_5	=	0x00dd
                    00DC    391 G$I2CON_4$0$0 == 0x00dc
                    00DC    392 _I2CON_4	=	0x00dc
                    00DB    393 G$I2CON_3$0$0 == 0x00db
                    00DB    394 _I2CON_3	=	0x00db
                    00DA    395 G$I2CON_2$0$0 == 0x00da
                    00DA    396 _I2CON_2	=	0x00da
                    00D8    397 G$I2CON_0$0$0 == 0x00d8
                    00D8    398 _I2CON_0	=	0x00d8
                    0080    399 G$P0_0$0$0 == 0x0080
                    0080    400 _P0_0	=	0x0080
                    0081    401 G$P0_1$0$0 == 0x0081
                    0081    402 _P0_1	=	0x0081
                    0082    403 G$P0_2$0$0 == 0x0082
                    0082    404 _P0_2	=	0x0082
                    0083    405 G$P0_3$0$0 == 0x0083
                    0083    406 _P0_3	=	0x0083
                    0084    407 G$P0_4$0$0 == 0x0084
                    0084    408 _P0_4	=	0x0084
                    0085    409 G$P0_5$0$0 == 0x0085
                    0085    410 _P0_5	=	0x0085
                    0086    411 G$P0_6$0$0 == 0x0086
                    0086    412 _P0_6	=	0x0086
                    0087    413 G$P0_7$0$0 == 0x0087
                    0087    414 _P0_7	=	0x0087
                    0090    415 G$P1_0$0$0 == 0x0090
                    0090    416 _P1_0	=	0x0090
                    0091    417 G$P1_1$0$0 == 0x0091
                    0091    418 _P1_1	=	0x0091
                    0092    419 G$P1_2$0$0 == 0x0092
                    0092    420 _P1_2	=	0x0092
                    0093    421 G$P1_3$0$0 == 0x0093
                    0093    422 _P1_3	=	0x0093
                    0094    423 G$P1_4$0$0 == 0x0094
                    0094    424 _P1_4	=	0x0094
                    0095    425 G$P1_5$0$0 == 0x0095
                    0095    426 _P1_5	=	0x0095
                    0096    427 G$P1_6$0$0 == 0x0096
                    0096    428 _P1_6	=	0x0096
                    0097    429 G$P1_7$0$0 == 0x0097
                    0097    430 _P1_7	=	0x0097
                    00B0    431 G$P3_0$0$0 == 0x00b0
                    00B0    432 _P3_0	=	0x00b0
                    00B1    433 G$P3_1$0$0 == 0x00b1
                    00B1    434 _P3_1	=	0x00b1
                            435 ;--------------------------------------------------------
                            436 ; overlayable register banks
                            437 ;--------------------------------------------------------
                            438 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     439 	.ds 8
                            440 ;--------------------------------------------------------
                            441 ; overlayable bit register bank
                            442 ;--------------------------------------------------------
                            443 	.area BIT_BANK	(REL,OVR,DATA)
   0023                     444 bits:
   0023                     445 	.ds 1
                    8000    446 	b0 = bits[0]
                    8100    447 	b1 = bits[1]
                    8200    448 	b2 = bits[2]
                    8300    449 	b3 = bits[3]
                    8400    450 	b4 = bits[4]
                    8500    451 	b5 = bits[5]
                    8600    452 	b6 = bits[6]
                    8700    453 	b7 = bits[7]
                            454 ;--------------------------------------------------------
                            455 ; internal ram data
                            456 ;--------------------------------------------------------
                            457 	.area DSEG    (DATA)
                    0000    458 G$RAM$0$0 == 0x0000
                    0000    459 _RAM	=	0x0000
                            460 ;--------------------------------------------------------
                            461 ; overlayable items in internal ram 
                            462 ;--------------------------------------------------------
                            463 	.area OSEG    (OVR,DATA)
                            464 ;--------------------------------------------------------
                            465 ; Stack segment in internal ram 
                            466 ;--------------------------------------------------------
                            467 	.area	SSEG	(DATA)
   007C                     468 __start__stack:
   007C                     469 	.ds	1
                            470 
                            471 ;--------------------------------------------------------
                            472 ; indirectly addressable internal ram data
                            473 ;--------------------------------------------------------
                            474 	.area ISEG    (DATA)
                            475 ;--------------------------------------------------------
                            476 ; absolute internal ram data
                            477 ;--------------------------------------------------------
                            478 	.area IABS    (ABS,DATA)
                            479 	.area IABS    (ABS,DATA)
                            480 ;--------------------------------------------------------
                            481 ; bit data
                            482 ;--------------------------------------------------------
                            483 	.area BSEG    (BIT)
                            484 ;--------------------------------------------------------
                            485 ; paged external ram data
                            486 ;--------------------------------------------------------
                            487 	.area PSEG    (PAG,XDATA)
                            488 ;--------------------------------------------------------
                            489 ; external ram data
                            490 ;--------------------------------------------------------
                            491 	.area XSEG    (XDATA)
                            492 ;--------------------------------------------------------
                            493 ; absolute external ram data
                            494 ;--------------------------------------------------------
                            495 	.area XABS    (ABS,XDATA)
                            496 ;--------------------------------------------------------
                            497 ; external initialized ram data
                            498 ;--------------------------------------------------------
                            499 	.area XISEG   (XDATA)
                            500 	.area HOME    (CODE)
                            501 	.area GSINIT0 (CODE)
                            502 	.area GSINIT1 (CODE)
                            503 	.area GSINIT2 (CODE)
                            504 	.area GSINIT3 (CODE)
                            505 	.area GSINIT4 (CODE)
                            506 	.area GSINIT5 (CODE)
                            507 	.area GSINIT  (CODE)
                            508 	.area GSFINAL (CODE)
                            509 	.area CSEG    (CODE)
                            510 ;--------------------------------------------------------
                            511 ; interrupt vector 
                            512 ;--------------------------------------------------------
                            513 	.area HOME    (CODE)
   0000                     514 __interrupt_vect:
   0000 02 00 23            515 	ljmp	__sdcc_gsinit_startup
   0003 32                  516 	reti
   0004                     517 	.ds	7
   000B 32                  518 	reti
   000C                     519 	.ds	7
   0013 02 0E 7D            520 	ljmp	_X1_int
   0016                     521 	.ds	5
   001B 02 0E AD            522 	ljmp	_T1_int
                            523 ;--------------------------------------------------------
                            524 ; global & static initialisations
                            525 ;--------------------------------------------------------
                            526 	.area HOME    (CODE)
                            527 	.area GSINIT  (CODE)
                            528 	.area GSFINAL (CODE)
                            529 	.area GSINIT  (CODE)
                            530 	.globl __sdcc_gsinit_startup
                            531 	.globl __sdcc_program_startup
                            532 	.globl __start__stack
                            533 	.globl __mcs51_genXINIT
                            534 	.globl __mcs51_genXRAMCLEAR
                            535 	.globl __mcs51_genRAMCLEAR
                            536 	.area GSFINAL (CODE)
   007C 02 00 1E            537 	ljmp	__sdcc_program_startup
                            538 ;--------------------------------------------------------
                            539 ; Home
                            540 ;--------------------------------------------------------
                            541 	.area HOME    (CODE)
                            542 	.area HOME    (CODE)
   001E                     543 __sdcc_program_startup:
   001E 12 00 7F            544 	lcall	_main
                            545 ;	return from main will lock up
   0021 80 FE               546 	sjmp .
                            547 ;--------------------------------------------------------
                            548 ; code
                            549 ;--------------------------------------------------------
                            550 	.area CSEG    (CODE)
                            551 ;------------------------------------------------------------
                            552 ;Allocation info for local variables in function 'main'
                            553 ;------------------------------------------------------------
                            554 ;n                         Allocated to registers r5 
                            555 ;cmd                       Allocated to registers r5 
                            556 ;tasterpegel               Allocated to registers r7 
                            557 ;cal                       Allocated to registers r6 
                            558 ;rm_count                  Allocated to registers 
                            559 ;wduf                      Allocated to registers b1 
                            560 ;tastergetoggelt           Allocated to registers b0 
                            561 ;------------------------------------------------------------
                    0000    562 	G$main$0$0 ==.
                    0000    563 	C$fb_rollo10.c$44$0$0 ==.
                            564 ;	..\fb_rollo10.c:44: void main(void)
                            565 ;	-----------------------------------------
                            566 ;	 function main
                            567 ;	-----------------------------------------
   007F                     568 _main:
                    0007    569 	ar7 = 0x07
                    0006    570 	ar6 = 0x06
                    0005    571 	ar5 = 0x05
                    0004    572 	ar4 = 0x04
                    0003    573 	ar3 = 0x03
                    0002    574 	ar2 = 0x02
                    0001    575 	ar1 = 0x01
                    0000    576 	ar0 = 0x00
                    0000    577 	C$fb_rollo10.c$46$1$0 ==.
                            578 ;	..\fb_rollo10.c:46: unsigned char n,cmd,tasterpegel=0;
   007F 7F 00               579 	mov	r7,#0x00
                    0002    580 	C$fb_rollo10.c$54$1$0 ==.
                            581 ;	..\fb_rollo10.c:54: __bit wduf,tastergetoggelt=0;
   0081 C2 18               582 	clr	b0
                    0004    583 	C$fb_rollo10.c$55$1$1 ==.
                            584 ;	..\fb_rollo10.c:55: wduf=WDCON&0x02;
   0083 E5 A7               585 	mov	a,_WDCON
   0085 03                  586 	rr	a
   0086 54 01               587 	anl	a,#0x01
   0088 24 FF               588 	add	a,#0xff
   008A 92 19               589 	mov	b1,c
                    000D    590 	C$fb_rollo10.c$56$1$1 ==.
                            591 ;	..\fb_rollo10.c:56: restart_hw();							// Hardware zuruecksetzen
   008C C0 07               592 	push	ar7
   008E C0 23               593 	push	bits
   0090 12 17 BF            594 	lcall	_restart_hw
   0093 D0 23               595 	pop	bits
   0095 D0 07               596 	pop	ar7
                    0018    597 	C$fb_rollo10.c$59$1$1 ==.
                            598 ;	..\fb_rollo10.c:59: TASTER=1;
   0097 D2 97               599 	setb	_P1_7
                    001A    600 	C$fb_rollo10.c$60$1$1 ==.
                            601 ;	..\fb_rollo10.c:60: if(!TASTER && wduf)cal=0;
   0099 20 97 07            602 	jb	_P1_7,00102$
   009C 30 19 04            603 	jnb	b1,00102$
   009F 7E 00               604 	mov	r6,#0x00
   00A1 80 07               605 	sjmp	00103$
   00A3                     606 00102$:
                    0024    607 	C$fb_rollo10.c$61$1$1 ==.
                            608 ;	..\fb_rollo10.c:61: else cal=trimsave;
   00A3 90 1B FF            609 	mov	dptr,#_main_trimsave_1_1
   00A6 E4                  610 	clr	a
   00A7 93                  611 	movc	a,@a+dptr
   00A8 FD                  612 	mov	r5,a
   00A9 FE                  613 	mov	r6,a
   00AA                     614 00103$:
                    002B    615 	C$fb_rollo10.c$62$1$1 ==.
                            616 ;	..\fb_rollo10.c:62: TRIM = (TRIM+trimsave);
   00AA 90 1B FF            617 	mov	dptr,#_main_trimsave_1_1
   00AD E4                  618 	clr	a
   00AE 93                  619 	movc	a,@a+dptr
   00AF AC 96               620 	mov	r4,_TRIM
   00B1 2C                  621 	add	a,r4
   00B2 FD                  622 	mov	r5,a
   00B3 8D 96               623 	mov	_TRIM,r5
                    0036    624 	C$fb_rollo10.c$63$1$1 ==.
                            625 ;	..\fb_rollo10.c:63: TRIM &= 0x3F;//oberen 2 bits ausblenden
   00B5 53 96 3F            626 	anl	_TRIM,#0x3F
                    0039    627 	C$fb_rollo10.c$68$1$1 ==.
                            628 ;	..\fb_rollo10.c:68: if (!wduf){// BUS return verzögerung nur wenn nicht watchdog underflow
   00B8 20 19 21            629 	jb	b1,00109$
                    003C    630 	C$fb_rollo10.c$69$1$1 ==.
                            631 ;	..\fb_rollo10.c:69: for (n=0;n<50;n++) {		// Warten bis Bus stabil
   00BB 7D 00               632 	mov	r5,#0x00
   00BD                     633 00170$:
   00BD BD 32 00            634 	cjne	r5,#0x32,00221$
   00C0                     635 00221$:
   00C0 50 1A               636 	jnc	00109$
                    0043    637 	C$fb_rollo10.c$70$3$3 ==.
                            638 ;	..\fb_rollo10.c:70: TR0=0;					// Timer 0 anhalten
   00C2 C2 8C               639 	clr	_TCON_4
                    0045    640 	C$fb_rollo10.c$71$3$3 ==.
                            641 ;	..\fb_rollo10.c:71: TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
   00C4 90 1D 17            642 	mov	dptr,#(_eeprom + 0x0017)
   00C7 E4                  643 	clr	a
   00C8 93                  644 	movc	a,@a+dptr
   00C9 F5 8C               645 	mov	_TH0,a
                    004C    646 	C$fb_rollo10.c$72$3$3 ==.
                            647 ;	..\fb_rollo10.c:72: TL0=eeprom[ADDRTAB+2];
   00CB 90 1D 18            648 	mov	dptr,#(_eeprom + 0x0018)
   00CE E4                  649 	clr	a
   00CF 93                  650 	movc	a,@a+dptr
   00D0 F5 8A               651 	mov	_TL0,a
                    0053    652 	C$fb_rollo10.c$73$3$3 ==.
                            653 ;	..\fb_rollo10.c:73: TF0=0;					// Überlauf-Flag zurücksetzen
   00D2 C2 8D               654 	clr	_TCON_5
                    0055    655 	C$fb_rollo10.c$74$3$3 ==.
                            656 ;	..\fb_rollo10.c:74: TR0=1;					// Timer 0 starten
   00D4 D2 8C               657 	setb	_TCON_4
                    0057    658 	C$fb_rollo10.c$75$3$3 ==.
                            659 ;	..\fb_rollo10.c:75: while(!TF0);
   00D6                     660 00105$:
   00D6 30 8D FD            661 	jnb	_TCON_5,00105$
                    005A    662 	C$fb_rollo10.c$69$2$2 ==.
                            663 ;	..\fb_rollo10.c:69: for (n=0;n<50;n++) {		// Warten bis Bus stabil
   00D9 0D                  664 	inc	r5
   00DA 80 E1               665 	sjmp	00170$
   00DC                     666 00109$:
                    005D    667 	C$fb_rollo10.c$78$1$1 ==.
                            668 ;	..\fb_rollo10.c:78: WATCHDOG_INIT
   00DC 75 C1 FF            669 	mov	_WDL,#0xFF
   00DF C2 AF               670 	clr	_IEN0_7
   00E1 75 A7 E5            671 	mov	_WDCON,#0xE5
   00E4 75 C2 A5            672 	mov	_WFEED1,#0xA5
   00E7 75 C3 5A            673 	mov	_WFEED2,#0x5A
   00EA D2 AF               674 	setb	_IEN0_7
                    006D    675 	C$fb_rollo10.c$79$1$1 ==.
                            676 ;	..\fb_rollo10.c:79: WATCHDOG_START
   00EC C2 AF               677 	clr	_IEN0_7
   00EE 43 A7 04            678 	orl	_WDCON,#0x04
   00F1 75 C2 A5            679 	mov	_WFEED1,#0xA5
   00F4 75 C3 5A            680 	mov	_WFEED2,#0x5A
   00F7 D2 AF               681 	setb	_IEN0_7
                    007A    682 	C$fb_rollo10.c$80$1$1 ==.
                            683 ;	..\fb_rollo10.c:80: restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
   00F9 C0 07               684 	push	ar7
   00FB C0 06               685 	push	ar6
   00FD C0 23               686 	push	bits
   00FF 12 0D F0            687 	lcall	_restart_app
   0102 D0 23               688 	pop	bits
   0104 D0 06               689 	pop	ar6
   0106 D0 07               690 	pop	ar7
                    0089    691 	C$fb_rollo10.c$81$1$1 ==.
                            692 ;	..\fb_rollo10.c:81: if(!wduf)bus_return();							// Aktionen bei Busspannungswiederkehr
   0108 20 19 0F            693 	jb	b1,00111$
   010B C0 07               694 	push	ar7
   010D C0 06               695 	push	ar6
   010F C0 23               696 	push	bits
   0111 12 0D 4D            697 	lcall	_bus_return
   0114 D0 23               698 	pop	bits
   0116 D0 06               699 	pop	ar6
   0118 D0 07               700 	pop	ar7
   011A                     701 00111$:
                    009B    702 	C$fb_rollo10.c$83$1$1 ==.
                            703 ;	..\fb_rollo10.c:83: BRGCON&=0xFE;	// Baudrate Generator stoppen
   011A 53 BD FE            704 	anl	_BRGCON,#0xFE
                    009E    705 	C$fb_rollo10.c$84$1$1 ==.
                            706 ;	..\fb_rollo10.c:84: P1M1&=0xFC;		// RX und TX auf bidirectional setzen
   011D 53 91 FC            707 	anl	_P1M1,#0xFC
                    00A1    708 	C$fb_rollo10.c$85$1$1 ==.
                            709 ;	..\fb_rollo10.c:85: P1M2&=0xFC;
   0120 53 92 FC            710 	anl	_P1M2,#0xFC
                    00A4    711 	C$fb_rollo10.c$86$1$1 ==.
                            712 ;	..\fb_rollo10.c:86: SCON=0x50;		// Mode 1, receive enable
   0123 75 98 50            713 	mov	_SCON,#0x50
                    00A7    714 	C$fb_rollo10.c$87$1$1 ==.
                            715 ;	..\fb_rollo10.c:87: SSTAT|=0xE0;	// TI wird am Ende des Stopbits gesetzt und Interrupt nur bei RX und double TX buffer an
   0126 43 BA E0            716 	orl	_SSTAT,#0xE0
                    00AA    717 	C$fb_rollo10.c$88$1$1 ==.
                            718 ;	..\fb_rollo10.c:88: BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
   0129 43 BD 02            719 	orl	_BRGCON,#0x02
                    00AD    720 	C$fb_rollo10.c$89$1$1 ==.
                            721 ;	..\fb_rollo10.c:89: BRGR1=0x2F;	// Baudrate = cclk/((BRGR1,BRGR0)+16)
   012C 75 BF 2F            722 	mov	_BRGR1,#0x2F
                    00B0    723 	C$fb_rollo10.c$90$1$1 ==.
                            724 ;	..\fb_rollo10.c:90: BRGR0=0xF0;	// für 115200 0030 nehmen, autocal: 600bd= 0x2FF0
   012F 75 BE F0            725 	mov	_BRGR0,#0xF0
                    00B3    726 	C$fb_rollo10.c$91$1$1 ==.
                            727 ;	..\fb_rollo10.c:91: BRGCON|=0x01;	// Baudrate Generator starten
   0132 43 BD 01            728 	orl	_BRGCON,#0x01
                    00B6    729 	C$fb_rollo10.c$92$1$1 ==.
                            730 ;	..\fb_rollo10.c:92: SBUF=0x55;
   0135 75 99 55            731 	mov	_SBUF,#0x55
                    00B9    732 	C$fb_rollo10.c$93$1$1 ==.
                            733 ;	..\fb_rollo10.c:93: do  {
   0138                     734 00167$:
                    00B9    735 	C$fb_rollo10.c$94$2$4 ==.
                            736 ;	..\fb_rollo10.c:94: WATCHDOG_FEED
   0138 C2 AF               737 	clr	_IEN0_7
   013A 75 C2 A5            738 	mov	_WFEED1,#0xA5
   013D 75 C3 5A            739 	mov	_WFEED2,#0x5A
   0140 D2 AF               740 	setb	_IEN0_7
                    00C3    741 	C$fb_rollo10.c$96$2$4 ==.
                            742 ;	..\fb_rollo10.c:96: if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt
   0142 90 1D 0D            743 	mov	dptr,#(_eeprom + 0x000d)
   0145 E4                  744 	clr	a
   0146 93                  745 	movc	a,@a+dptr
   0147 FD                  746 	mov	r5,a
   0148 BD FF 78            747 	cjne	r5,#0xFF,00125$
   014B 20 11 75            748 	jb	_connected,00125$
   014E E5 7B               749 	mov	a,_status60
   0150 20 E0 70            750 	jb	acc.0,00125$
                    00D4    751 	C$fb_rollo10.c$100$3$5 ==.
                            752 ;	..\fb_rollo10.c:100: */			if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf
   0153 74 80               753 	mov	a,#0x100 - 0x80
   0155 25 D1               754 	add	a,_RTCCON
   0157 50 0F               755 	jnc	00113$
   0159 C0 07               756 	push	ar7
   015B C0 06               757 	push	ar6
   015D C0 23               758 	push	bits
   015F 12 09 96            759 	lcall	_delay_timer
   0162 D0 23               760 	pop	bits
   0164 D0 06               761 	pop	ar6
   0166 D0 07               762 	pop	ar7
   0168                     763 00113$:
                    00E9    764 	C$fb_rollo10.c$102$3$5 ==.
                            765 ;	..\fb_rollo10.c:102: if(TF0 && (TMOD & 0x0F)==0x01) {	// Vollstrom für Relais ausschalten und wieder PWM ein
   0168 30 8D 1F            766 	jnb	_TCON_5,00115$
   016B 74 0F               767 	mov	a,#0x0F
   016D 55 89               768 	anl	a,_TMOD
   016F FD                  769 	mov	r5,a
   0170 BD 01 17            770 	cjne	r5,#0x01,00115$
                    00F4    771 	C$fb_rollo10.c$104$4$6 ==.
                            772 ;	..\fb_rollo10.c:104: TMOD=(TMOD & 0xF0) + 2;			// Timer 0 als PWM
   0173 74 F0               773 	mov	a,#0xF0
   0175 55 89               774 	anl	a,_TMOD
   0177 24 02               775 	add	a,#0x02
   0179 F5 89               776 	mov	_TMOD,a
                    00FC    777 	C$fb_rollo10.c$105$4$6 ==.
                            778 ;	..\fb_rollo10.c:105: TAMOD=0x01;
   017B 75 8F 01            779 	mov	_TAMOD,#0x01
                    00FF    780 	C$fb_rollo10.c$106$4$6 ==.
                            781 ;	..\fb_rollo10.c:106: TH0=DUTY;
   017E 75 8C 50            782 	mov	_TH0,#0x50
                    0102    783 	C$fb_rollo10.c$108$4$6 ==.
                            784 ;	..\fb_rollo10.c:108: TF0=0;
   0181 C2 8D               785 	clr	_TCON_5
                    0104    786 	C$fb_rollo10.c$110$4$6 ==.
                            787 ;	..\fb_rollo10.c:110: AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben
   0183 43 A2 10            788 	orl	_AUXR1,#0x10
                    0107    789 	C$fb_rollo10.c$112$4$6 ==.
                            790 ;	..\fb_rollo10.c:112: PWM=1;			// PWM Pin muss auf 1 gesetzt werden, damit PWM geht !!!
   0186 D2 92               791 	setb	_P1_2
                    0109    792 	C$fb_rollo10.c$114$4$6 ==.
                            793 ;	..\fb_rollo10.c:114: TR0=1;
   0188 D2 8C               794 	setb	_TCON_4
   018A                     795 00115$:
                    010B    796 	C$fb_rollo10.c$121$3$5 ==.
                            797 ;	..\fb_rollo10.c:121: if (portchanged)port_schalten();	// Ausgänge schalten
   018A 30 00 0F            798 	jnb	_portchanged,00118$
   018D C0 07               799 	push	ar7
   018F C0 06               800 	push	ar6
   0191 C0 23               801 	push	bits
   0193 12 0C CF            802 	lcall	_port_schalten
   0196 D0 23               803 	pop	bits
   0198 D0 06               804 	pop	ar6
   019A D0 07               805 	pop	ar7
   019C                     806 00118$:
                    011D    807 	C$fb_rollo10.c$150$3$5 ==.
                            808 ;	..\fb_rollo10.c:150: if (fb_state==0 && (TH1<0XC0) && (!wait_for_ack)&& blocked!=blockedsave) {
   019C E5 77               809 	mov	a,_fb_state
   019E 70 23               810 	jnz	00125$
   01A0 74 40               811 	mov	a,#0x100 - 0xC0
   01A2 25 8D               812 	add	a,_TH1
   01A4 40 1D               813 	jc	00125$
   01A6 20 0D 1A            814 	jb	_wait_for_ack,00125$
   01A9 90 1B FD            815 	mov	dptr,#_main_blockedsave_1_1
   01AC E4                  816 	clr	a
   01AD 93                  817 	movc	a,@a+dptr
   01AE FD                  818 	mov	r5,a
   01AF B5 0F 02            819 	cjne	a,_blocked,00237$
   01B2 80 0F               820 	sjmp	00125$
   01B4                     821 00237$:
                    0135    822 	C$fb_rollo10.c$151$4$7 ==.
                            823 ;	..\fb_rollo10.c:151: START_WRITECYCLE;
   01B4 75 E4 00            824 	mov	_FMCON,#0x00
                    0138    825 	C$fb_rollo10.c$152$4$7 ==.
                            826 ;	..\fb_rollo10.c:152: FMADRH= 0x1B;		
   01B7 75 E7 1B            827 	mov	_FMADRH,#0x1B
                    013B    828 	C$fb_rollo10.c$153$4$7 ==.
                            829 ;	..\fb_rollo10.c:153: FMADRL= 0xFD; 
   01BA 75 E6 FD            830 	mov	_FMADRL,#0xFD
                    013E    831 	C$fb_rollo10.c$154$4$7 ==.
                            832 ;	..\fb_rollo10.c:154: FMDATA= blocked;
   01BD 85 0F E5            833 	mov	_FMDATA,_blocked
                    0141    834 	C$fb_rollo10.c$155$4$7 ==.
                            835 ;	..\fb_rollo10.c:155: STOP_WRITECYCLE;
   01C0 75 E4 68            836 	mov	_FMCON,#0x68
   01C3                     837 00125$:
                    0144    838 	C$fb_rollo10.c$162$2$4 ==.
                            839 ;	..\fb_rollo10.c:162: if (tel_arrived ) {//|| tel_sent
                    0144    840 	C$fb_rollo10.c$163$3$8 ==.
                            841 ;	..\fb_rollo10.c:163: tel_arrived=0;
   01C3 10 09 02            842 	jbc	_tel_arrived,00238$
   01C6 80 13               843 	sjmp	00129$
   01C8                     844 00238$:
                    0149    845 	C$fb_rollo10.c$164$3$8 ==.
                            846 ;	..\fb_rollo10.c:164: tel_sent=0;
   01C8 C2 0A               847 	clr	_tel_sent
                    014B    848 	C$fb_rollo10.c$165$3$8 ==.
                            849 ;	..\fb_rollo10.c:165: process_tel();
   01CA C0 07               850 	push	ar7
   01CC C0 06               851 	push	ar6
   01CE C0 23               852 	push	bits
   01D0 12 14 EE            853 	lcall	_process_tel
   01D3 D0 23               854 	pop	bits
   01D5 D0 06               855 	pop	ar6
   01D7 D0 07               856 	pop	ar7
   01D9 80 0A               857 	sjmp	00130$
   01DB                     858 00129$:
                    015C    859 	C$fb_rollo10.c$168$3$4 ==.
                            860 ;	..\fb_rollo10.c:168: for(n=0;n<100;n++);	// falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann
   01DB 7D 64               861 	mov	r5,#0x64
   01DD                     862 00176$:
   01DD 8D 04               863 	mov	ar4,r5
   01DF 1C                  864 	dec	r4
   01E0 8C 05               865 	mov	ar5,r4
   01E2 ED                  866 	mov	a,r5
   01E3 70 F8               867 	jnz	00176$
   01E5                     868 00130$:
                    0166    869 	C$fb_rollo10.c$174$2$4 ==.
                            870 ;	..\fb_rollo10.c:174: if (RI){
                    0166    871 	C$fb_rollo10.c$175$3$10 ==.
                            872 ;	..\fb_rollo10.c:175: RI=0;
   01E5 10 98 02            873 	jbc	_SCON_0,00240$
   01E8 80 4A               874 	sjmp	00155$
   01EA                     875 00240$:
                    016B    876 	C$fb_rollo10.c$176$3$10 ==.
                            877 ;	..\fb_rollo10.c:176: cmd=SBUF;
   01EA AD 99               878 	mov	r5,_SBUF
                    016D    879 	C$fb_rollo10.c$177$3$10 ==.
                            880 ;	..\fb_rollo10.c:177: if(cmd=='c'){
   01EC BD 63 08            881 	cjne	r5,#0x63,00135$
                    0170    882 	C$fb_rollo10.c$178$4$11 ==.
                            883 ;	..\fb_rollo10.c:178: while(!TI);
   01EF                     884 00131$:
                    0170    885 	C$fb_rollo10.c$179$4$11 ==.
                            886 ;	..\fb_rollo10.c:179: TI=0;
   01EF 10 99 02            887 	jbc	_SCON_1,00243$
   01F2 80 FB               888 	sjmp	00131$
   01F4                     889 00243$:
                    0175    890 	C$fb_rollo10.c$180$4$11 ==.
                            891 ;	..\fb_rollo10.c:180: SBUF=0x55;
   01F4 75 99 55            892 	mov	_SBUF,#0x55
   01F7                     893 00135$:
                    0178    894 	C$fb_rollo10.c$182$3$10 ==.
                            895 ;	..\fb_rollo10.c:182: if(cmd=='+'){
   01F7 BD 2B 03            896 	cjne	r5,#0x2B,00137$
                    017B    897 	C$fb_rollo10.c$183$4$12 ==.
                            898 ;	..\fb_rollo10.c:183: TRIM--;
   01FA 15 96               899 	dec	_TRIM
                    017D    900 	C$fb_rollo10.c$184$4$12 ==.
                            901 ;	..\fb_rollo10.c:184: cal--;
   01FC 1E                  902 	dec	r6
   01FD                     903 00137$:
                    017E    904 	C$fb_rollo10.c$186$3$10 ==.
                            905 ;	..\fb_rollo10.c:186: if(cmd=='-'){
   01FD BD 2D 03            906 	cjne	r5,#0x2D,00139$
                    0181    907 	C$fb_rollo10.c$187$4$13 ==.
                            908 ;	..\fb_rollo10.c:187: TRIM++;
   0200 05 96               909 	inc	_TRIM
                    0183    910 	C$fb_rollo10.c$188$4$13 ==.
                            911 ;	..\fb_rollo10.c:188: cal++;
   0202 0E                  912 	inc	r6
   0203                     913 00139$:
                    0184    914 	C$fb_rollo10.c$190$3$10 ==.
                            915 ;	..\fb_rollo10.c:190: if(cmd=='w'){
   0203 BD 77 12            916 	cjne	r5,#0x77,00141$
                    0187    917 	C$fb_rollo10.c$191$4$14 ==.
                            918 ;	..\fb_rollo10.c:191: EA=0;
   0206 C2 AF               919 	clr	_IEN0_7
                    0189    920 	C$fb_rollo10.c$192$4$14 ==.
                            921 ;	..\fb_rollo10.c:192: START_WRITECYCLE;	//cal an 0x1bff schreiben
   0208 75 E4 00            922 	mov	_FMCON,#0x00
                    018C    923 	C$fb_rollo10.c$198$4$14 ==.
                            924 ;	..\fb_rollo10.c:198: FMADRH= 0x1B;		
   020B 75 E7 1B            925 	mov	_FMADRH,#0x1B
                    018F    926 	C$fb_rollo10.c$199$4$14 ==.
                            927 ;	..\fb_rollo10.c:199: FMADRL= 0xFF; 
   020E 75 E6 FF            928 	mov	_FMADRL,#0xFF
                    0192    929 	C$fb_rollo10.c$201$4$14 ==.
                            930 ;	..\fb_rollo10.c:201: FMDATA=	cal;
   0211 8E E5               931 	mov	_FMDATA,r6
                    0194    932 	C$fb_rollo10.c$202$4$14 ==.
                            933 ;	..\fb_rollo10.c:202: STOP_WRITECYCLE;
   0213 75 E4 68            934 	mov	_FMCON,#0x68
                    0197    935 	C$fb_rollo10.c$203$4$14 ==.
                            936 ;	..\fb_rollo10.c:203: EA=1;				//int wieder freigeben
   0216 D2 AF               937 	setb	_IEN0_7
   0218                     938 00141$:
                    0199    939 	C$fb_rollo10.c$205$3$10 ==.
                            940 ;	..\fb_rollo10.c:205: if(cmd=='p')status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
   0218 BD 70 03            941 	cjne	r5,#0x70,00143$
   021B 63 7B 81            942 	xrl	_status60,#0x81
   021E                     943 00143$:
                    019F    944 	C$fb_rollo10.c$222$3$10 ==.
                            945 ;	..\fb_rollo10.c:222: if(cmd=='v'){
   021E BD 76 08            946 	cjne	r5,#0x76,00148$
                    01A2    947 	C$fb_rollo10.c$223$4$15 ==.
                            948 ;	..\fb_rollo10.c:223: while(!TI);
   0221                     949 00144$:
                    01A2    950 	C$fb_rollo10.c$224$4$15 ==.
                            951 ;	..\fb_rollo10.c:224: TI=0;
   0221 10 99 02            952 	jbc	_SCON_1,00254$
   0224 80 FB               953 	sjmp	00144$
   0226                     954 00254$:
                    01A7    955 	C$fb_rollo10.c$225$4$15 ==.
                            956 ;	..\fb_rollo10.c:225: SBUF=VERSION;
   0226 75 99 0A            957 	mov	_SBUF,#0x0A
   0229                     958 00148$:
                    01AA    959 	C$fb_rollo10.c$227$3$10 ==.
                            960 ;	..\fb_rollo10.c:227: if(cmd=='t'){
   0229 BD 74 08            961 	cjne	r5,#0x74,00155$
                    01AD    962 	C$fb_rollo10.c$228$4$16 ==.
                            963 ;	..\fb_rollo10.c:228: while(!TI);
   022C                     964 00149$:
                    01AD    965 	C$fb_rollo10.c$229$4$16 ==.
                            966 ;	..\fb_rollo10.c:229: TI=0;
   022C 10 99 02            967 	jbc	_SCON_1,00257$
   022F 80 FB               968 	sjmp	00149$
   0231                     969 00257$:
                    01B2    970 	C$fb_rollo10.c$230$4$16 ==.
                            971 ;	..\fb_rollo10.c:230: SBUF=TYPE;
   0231 75 99 00            972 	mov	_SBUF,#0x00
   0234                     973 00155$:
                    01B5    974 	C$fb_rollo10.c$235$2$4 ==.
                            975 ;	..\fb_rollo10.c:235: TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
   0234 D2 97               976 	setb	_P1_7
                    01B7    977 	C$fb_rollo10.c$236$2$4 ==.
                            978 ;	..\fb_rollo10.c:236: if(!TASTER){ // Taster gedrückt
   0236 20 97 12            979 	jb	_P1_7,00165$
                    01BA    980 	C$fb_rollo10.c$237$3$17 ==.
                            981 ;	..\fb_rollo10.c:237: if(tasterpegel<255)	tasterpegel++;
   0239 BF FF 00            982 	cjne	r7,#0xFF,00259$
   023C                     983 00259$:
   023C 50 03               984 	jnc	00159$
   023E 0F                  985 	inc	r7
   023F 80 12               986 	sjmp	00166$
   0241                     987 00159$:
                    01C2    988 	C$fb_rollo10.c$239$4$18 ==.
                            989 ;	..\fb_rollo10.c:239: if(!tastergetoggelt)status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
   0241 20 18 03            990 	jb	b0,00157$
   0244 63 7B 81            991 	xrl	_status60,#0x81
   0247                     992 00157$:
                    01C8    993 	C$fb_rollo10.c$240$4$18 ==.
                            994 ;	..\fb_rollo10.c:240: tastergetoggelt=1;
   0247 D2 18               995 	setb	b0
   0249 80 08               996 	sjmp	00166$
   024B                     997 00165$:
                    01CC    998 	C$fb_rollo10.c$244$3$19 ==.
                            999 ;	..\fb_rollo10.c:244: if(tasterpegel>0) tasterpegel--;
   024B EF                 1000 	mov	a,r7
   024C 60 03              1001 	jz	00162$
   024E 1F                 1002 	dec	r7
   024F 80 02              1003 	sjmp	00166$
   0251                    1004 00162$:
                    01D2   1005 	C$fb_rollo10.c$245$3$19 ==.
                           1006 ;	..\fb_rollo10.c:245: else tastergetoggelt=0;
   0251 C2 18              1007 	clr	b0
   0253                    1008 00166$:
                    01D4   1009 	C$fb_rollo10.c$247$2$4 ==.
                           1010 ;	..\fb_rollo10.c:247: TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
   0253 E5 7B              1011 	mov	a,_status60
   0255 54 01              1012 	anl	a,#0x01
   0257 FD                 1013 	mov	r5,a
   0258 B4 01 00           1014 	cjne	a,#0x01,00263$
   025B                    1015 00263$:
   025B E4                 1016 	clr	a
   025C 33                 1017 	rlc	a
   025D FD                 1018 	mov	r5,a
   025E 24 FF              1019 	add	a,#0xff
   0260 92 97              1020 	mov	_P1_7,c
                    01E3   1021 	C$fb_rollo10.c$248$1$1 ==.
                           1022 ;	..\fb_rollo10.c:248: } while(1);
   0262 02 01 38           1023 	ljmp	00167$
                    01E6   1024 	C$fb_rollo10.c$249$1$1 ==.
                    01E6   1025 	XG$main$0$0 ==.
   0265 22                 1026 	ret
                           1027 	.area CSEG    (CODE)
                           1028 	.area CONST   (CODE)
                    1BFF   1029 Lfb_rollo10.main$trimsave$1$1 == 0x1bff
                    1BFF   1030 _main_trimsave_1_1	=	0x1bff
                    1BFD   1031 Lfb_rollo10.main$blockedsave$1$1 == 0x1bfd
                    1BFD   1032 _main_blockedsave_1_1	=	0x1bfd
                           1033 	.area XINIT   (CODE)
                           1034 	.area CABS    (ABS,CODE)
