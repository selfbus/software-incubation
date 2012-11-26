                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 19:35:53 2012
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
   0013 02 0E 29            520 	ljmp	_X1_int
   0016                     521 	.ds	5
   001B 02 0E 59            522 	ljmp	_T1_int
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
                            554 ;n                         Allocated to registers r6 
                            555 ;cmd                       Allocated to registers 
                            556 ;tasterpegel               Allocated to registers r7 
                            557 ;cal                       Allocated to registers 
                            558 ;rm_count                  Allocated to registers 
                            559 ;wduf                      Allocated to registers b1 
                            560 ;tastergetoggelt           Allocated to registers b0 
                            561 ;------------------------------------------------------------
                    0000    562 	G$main$0$0 ==.
                    0000    563 	C$fb_rollo10.c$43$0$0 ==.
                            564 ;	..\fb_rollo10.c:43: void main(void)
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
                    0000    577 	C$fb_rollo10.c$45$1$0 ==.
                            578 ;	..\fb_rollo10.c:45: unsigned char n,cmd,tasterpegel=0;
   007F 7F 00               579 	mov	r7,#0x00
                    0002    580 	C$fb_rollo10.c$53$1$0 ==.
                            581 ;	..\fb_rollo10.c:53: __bit wduf,tastergetoggelt=0;
   0081 C2 18               582 	clr	b0
                    0004    583 	C$fb_rollo10.c$54$1$1 ==.
                            584 ;	..\fb_rollo10.c:54: wduf=WDCON&0x02;
   0083 E5 A7               585 	mov	a,_WDCON
   0085 03                  586 	rr	a
   0086 54 01               587 	anl	a,#0x01
   0088 24 FF               588 	add	a,#0xff
   008A 92 19               589 	mov	b1,c
                    000D    590 	C$fb_rollo10.c$55$1$1 ==.
                            591 ;	..\fb_rollo10.c:55: restart_hw();							// Hardware zuruecksetzen
   008C C0 07               592 	push	ar7
   008E C0 23               593 	push	bits
   0090 12 17 66            594 	lcall	_restart_hw
   0093 D0 23               595 	pop	bits
   0095 D0 07               596 	pop	ar7
                    0018    597 	C$fb_rollo10.c$58$1$1 ==.
                            598 ;	..\fb_rollo10.c:58: TASTER=1;
   0097 D2 97               599 	setb	_P1_7
                    001A    600 	C$fb_rollo10.c$59$1$1 ==.
                            601 ;	..\fb_rollo10.c:59: if(!TASTER && wduf)cal=0;
   0099 20 97 03            602 	jb	_P1_7,00102$
   009C 20 19 05            603 	jb	b1,00103$
   009F                     604 00102$:
                    0020    605 	C$fb_rollo10.c$60$1$1 ==.
                            606 ;	..\fb_rollo10.c:60: else cal=trimsave;
   009F 90 1B FF            607 	mov	dptr,#_main_trimsave_1_1
   00A2 E4                  608 	clr	a
   00A3 93                  609 	movc	a,@a+dptr
   00A4                     610 00103$:
                    0025    611 	C$fb_rollo10.c$61$1$1 ==.
                            612 ;	..\fb_rollo10.c:61: TRIM = (TRIM+trimsave);
   00A4 90 1B FF            613 	mov	dptr,#_main_trimsave_1_1
   00A7 E4                  614 	clr	a
   00A8 93                  615 	movc	a,@a+dptr
   00A9 AD 96               616 	mov	r5,_TRIM
   00AB 2D                  617 	add	a,r5
   00AC FE                  618 	mov	r6,a
   00AD 8E 96               619 	mov	_TRIM,r6
                    0030    620 	C$fb_rollo10.c$62$1$1 ==.
                            621 ;	..\fb_rollo10.c:62: TRIM &= 0x3F;//oberen 2 bits ausblenden
   00AF 53 96 3F            622 	anl	_TRIM,#0x3F
                    0033    623 	C$fb_rollo10.c$67$1$1 ==.
                            624 ;	..\fb_rollo10.c:67: if (!wduf){// BUS return verzögerung nur wenn nicht watchdog underflow
   00B2 20 19 21            625 	jb	b1,00109$
                    0036    626 	C$fb_rollo10.c$68$1$1 ==.
                            627 ;	..\fb_rollo10.c:68: for (n=0;n<50;n++) {		// Warten bis Bus stabil
   00B5 7E 00               628 	mov	r6,#0x00
   00B7                     629 00150$:
   00B7 BE 32 00            630 	cjne	r6,#0x32,00192$
   00BA                     631 00192$:
   00BA 50 1A               632 	jnc	00109$
                    003D    633 	C$fb_rollo10.c$69$3$3 ==.
                            634 ;	..\fb_rollo10.c:69: TR0=0;					// Timer 0 anhalten
   00BC C2 8C               635 	clr	_TCON_4
                    003F    636 	C$fb_rollo10.c$70$3$3 ==.
                            637 ;	..\fb_rollo10.c:70: TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
   00BE 90 1D 17            638 	mov	dptr,#(_eeprom + 0x0017)
   00C1 E4                  639 	clr	a
   00C2 93                  640 	movc	a,@a+dptr
   00C3 F5 8C               641 	mov	_TH0,a
                    0046    642 	C$fb_rollo10.c$71$3$3 ==.
                            643 ;	..\fb_rollo10.c:71: TL0=eeprom[ADDRTAB+2];
   00C5 90 1D 18            644 	mov	dptr,#(_eeprom + 0x0018)
   00C8 E4                  645 	clr	a
   00C9 93                  646 	movc	a,@a+dptr
   00CA F5 8A               647 	mov	_TL0,a
                    004D    648 	C$fb_rollo10.c$72$3$3 ==.
                            649 ;	..\fb_rollo10.c:72: TF0=0;					// Überlauf-Flag zurücksetzen
   00CC C2 8D               650 	clr	_TCON_5
                    004F    651 	C$fb_rollo10.c$73$3$3 ==.
                            652 ;	..\fb_rollo10.c:73: TR0=1;					// Timer 0 starten
   00CE D2 8C               653 	setb	_TCON_4
                    0051    654 	C$fb_rollo10.c$74$3$3 ==.
                            655 ;	..\fb_rollo10.c:74: while(!TF0);
   00D0                     656 00105$:
   00D0 30 8D FD            657 	jnb	_TCON_5,00105$
                    0054    658 	C$fb_rollo10.c$68$2$2 ==.
                            659 ;	..\fb_rollo10.c:68: for (n=0;n<50;n++) {		// Warten bis Bus stabil
   00D3 0E                  660 	inc	r6
   00D4 80 E1               661 	sjmp	00150$
   00D6                     662 00109$:
                    0057    663 	C$fb_rollo10.c$77$1$1 ==.
                            664 ;	..\fb_rollo10.c:77: WATCHDOG_INIT
   00D6 75 C1 FF            665 	mov	_WDL,#0xFF
   00D9 C2 AF               666 	clr	_IEN0_7
   00DB 75 A7 E5            667 	mov	_WDCON,#0xE5
   00DE 75 C2 A5            668 	mov	_WFEED1,#0xA5
   00E1 75 C3 5A            669 	mov	_WFEED2,#0x5A
   00E4 D2 AF               670 	setb	_IEN0_7
                    0067    671 	C$fb_rollo10.c$78$1$1 ==.
                            672 ;	..\fb_rollo10.c:78: WATCHDOG_START
   00E6 C2 AF               673 	clr	_IEN0_7
   00E8 43 A7 04            674 	orl	_WDCON,#0x04
   00EB 75 C2 A5            675 	mov	_WFEED1,#0xA5
   00EE 75 C3 5A            676 	mov	_WFEED2,#0x5A
   00F1 D2 AF               677 	setb	_IEN0_7
                    0074    678 	C$fb_rollo10.c$79$1$1 ==.
                            679 ;	..\fb_rollo10.c:79: restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
   00F3 C0 07               680 	push	ar7
   00F5 C0 23               681 	push	bits
   00F7 12 0D 9C            682 	lcall	_restart_app
   00FA D0 23               683 	pop	bits
   00FC D0 07               684 	pop	ar7
                    007F    685 	C$fb_rollo10.c$80$1$1 ==.
                            686 ;	..\fb_rollo10.c:80: if(!wduf)bus_return();							// Aktionen bei Busspannungswiederkehr
   00FE 20 19 0B            687 	jb	b1,00111$
   0101 C0 07               688 	push	ar7
   0103 C0 23               689 	push	bits
   0105 12 0C F9            690 	lcall	_bus_return
   0108 D0 23               691 	pop	bits
   010A D0 07               692 	pop	ar7
   010C                     693 00111$:
                    008D    694 	C$fb_rollo10.c$82$1$1 ==.
                            695 ;	..\fb_rollo10.c:82: BRGCON&=0xFE;	// Baudrate Generator stoppen
   010C 53 BD FE            696 	anl	_BRGCON,#0xFE
                    0090    697 	C$fb_rollo10.c$83$1$1 ==.
                            698 ;	..\fb_rollo10.c:83: P1M1&=0xFC;		// RX und TX auf bidirectional setzen
   010F 53 91 FC            699 	anl	_P1M1,#0xFC
                    0093    700 	C$fb_rollo10.c$84$1$1 ==.
                            701 ;	..\fb_rollo10.c:84: P1M2&=0xFC;
   0112 53 92 FC            702 	anl	_P1M2,#0xFC
                    0096    703 	C$fb_rollo10.c$85$1$1 ==.
                            704 ;	..\fb_rollo10.c:85: SCON=0x50;		// Mode 1, receive enable
   0115 75 98 50            705 	mov	_SCON,#0x50
                    0099    706 	C$fb_rollo10.c$86$1$1 ==.
                            707 ;	..\fb_rollo10.c:86: SSTAT|=0xE0;	// TI wird am Ende des Stopbits gesetzt und Interrupt nur bei RX und double TX buffer an
   0118 43 BA E0            708 	orl	_SSTAT,#0xE0
                    009C    709 	C$fb_rollo10.c$87$1$1 ==.
                            710 ;	..\fb_rollo10.c:87: BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
   011B 43 BD 02            711 	orl	_BRGCON,#0x02
                    009F    712 	C$fb_rollo10.c$88$1$1 ==.
                            713 ;	..\fb_rollo10.c:88: BRGR1=0x00;	// Baudrate = cclk/((BRGR1,BRGR0)+16)
   011E 75 BF 00            714 	mov	_BRGR1,#0x00
                    00A2    715 	C$fb_rollo10.c$89$1$1 ==.
                            716 ;	..\fb_rollo10.c:89: BRGR0=0x30;	// für 115200 0030 nehmen, autocal: 600bd= 0x2FF0
   0121 75 BE 30            717 	mov	_BRGR0,#0x30
                    00A5    718 	C$fb_rollo10.c$90$1$1 ==.
                            719 ;	..\fb_rollo10.c:90: BRGCON|=0x01;	// Baudrate Generator starten
   0124 43 BD 01            720 	orl	_BRGCON,#0x01
                    00A8    721 	C$fb_rollo10.c$91$1$1 ==.
                            722 ;	..\fb_rollo10.c:91: SBUF=0x55;
   0127 75 99 55            723 	mov	_SBUF,#0x55
                    00AB    724 	C$fb_rollo10.c$92$1$1 ==.
                            725 ;	..\fb_rollo10.c:92: do  {
   012A                     726 00147$:
                    00AB    727 	C$fb_rollo10.c$93$2$4 ==.
                            728 ;	..\fb_rollo10.c:93: WATCHDOG_FEED
   012A C2 AF               729 	clr	_IEN0_7
   012C 75 C2 A5            730 	mov	_WFEED1,#0xA5
   012F 75 C3 5A            731 	mov	_WFEED2,#0x5A
   0132 D2 AF               732 	setb	_IEN0_7
                    00B5    733 	C$fb_rollo10.c$95$2$4 ==.
                            734 ;	..\fb_rollo10.c:95: if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt
   0134 90 1D 0D            735 	mov	dptr,#(_eeprom + 0x000d)
   0137 E4                  736 	clr	a
   0138 93                  737 	movc	a,@a+dptr
   0139 FE                  738 	mov	r6,a
   013A BE FF 70            739 	cjne	r6,#0xFF,00125$
   013D 20 11 6D            740 	jb	_connected,00125$
   0140 E5 7B               741 	mov	a,_status60
   0142 20 E0 68            742 	jb	acc.0,00125$
                    00C6    743 	C$fb_rollo10.c$99$3$5 ==.
                            744 ;	..\fb_rollo10.c:99: */			if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf
   0145 74 80               745 	mov	a,#0x100 - 0x80
   0147 25 D1               746 	add	a,_RTCCON
   0149 50 0B               747 	jnc	00113$
   014B C0 07               748 	push	ar7
   014D C0 23               749 	push	bits
   014F 12 09 3E            750 	lcall	_delay_timer
   0152 D0 23               751 	pop	bits
   0154 D0 07               752 	pop	ar7
   0156                     753 00113$:
                    00D7    754 	C$fb_rollo10.c$101$3$5 ==.
                            755 ;	..\fb_rollo10.c:101: if(TF0 && (TMOD & 0x0F)==0x01) {	// Vollstrom für Relais ausschalten und wieder PWM ein
   0156 30 8D 1F            756 	jnb	_TCON_5,00115$
   0159 74 0F               757 	mov	a,#0x0F
   015B 55 89               758 	anl	a,_TMOD
   015D FE                  759 	mov	r6,a
   015E BE 01 17            760 	cjne	r6,#0x01,00115$
                    00E2    761 	C$fb_rollo10.c$103$4$6 ==.
                            762 ;	..\fb_rollo10.c:103: TMOD=(TMOD & 0xF0) + 2;			// Timer 0 als PWM
   0161 74 F0               763 	mov	a,#0xF0
   0163 55 89               764 	anl	a,_TMOD
   0165 24 02               765 	add	a,#0x02
   0167 F5 89               766 	mov	_TMOD,a
                    00EA    767 	C$fb_rollo10.c$104$4$6 ==.
                            768 ;	..\fb_rollo10.c:104: TAMOD=0x01;
   0169 75 8F 01            769 	mov	_TAMOD,#0x01
                    00ED    770 	C$fb_rollo10.c$105$4$6 ==.
                            771 ;	..\fb_rollo10.c:105: TH0=DUTY;
   016C 75 8C 50            772 	mov	_TH0,#0x50
                    00F0    773 	C$fb_rollo10.c$107$4$6 ==.
                            774 ;	..\fb_rollo10.c:107: TF0=0;
   016F C2 8D               775 	clr	_TCON_5
                    00F2    776 	C$fb_rollo10.c$109$4$6 ==.
                            777 ;	..\fb_rollo10.c:109: AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben
   0171 43 A2 10            778 	orl	_AUXR1,#0x10
                    00F5    779 	C$fb_rollo10.c$111$4$6 ==.
                            780 ;	..\fb_rollo10.c:111: PWM=1;			// PWM Pin muss auf 1 gesetzt werden, damit PWM geht !!!
   0174 D2 92               781 	setb	_P1_2
                    00F7    782 	C$fb_rollo10.c$113$4$6 ==.
                            783 ;	..\fb_rollo10.c:113: TR0=1;
   0176 D2 8C               784 	setb	_TCON_4
   0178                     785 00115$:
                    00F9    786 	C$fb_rollo10.c$120$3$5 ==.
                            787 ;	..\fb_rollo10.c:120: if (portchanged)port_schalten();	// Ausgänge schalten
   0178 30 00 0B            788 	jnb	_portchanged,00118$
   017B C0 07               789 	push	ar7
   017D C0 23               790 	push	bits
   017F 12 0C 7B            791 	lcall	_port_schalten
   0182 D0 23               792 	pop	bits
   0184 D0 07               793 	pop	ar7
   0186                     794 00118$:
                    0107    795 	C$fb_rollo10.c$149$3$5 ==.
                            796 ;	..\fb_rollo10.c:149: if (fb_state==0 && (TH1<0XC0) && (!wait_for_ack)&& blocked!=blockedsave) {
   0186 E5 77               797 	mov	a,_fb_state
   0188 70 23               798 	jnz	00125$
   018A 74 40               799 	mov	a,#0x100 - 0xC0
   018C 25 8D               800 	add	a,_TH1
   018E 40 1D               801 	jc	00125$
   0190 20 0D 1A            802 	jb	_wait_for_ack,00125$
   0193 90 1B FD            803 	mov	dptr,#_main_blockedsave_1_1
   0196 E4                  804 	clr	a
   0197 93                  805 	movc	a,@a+dptr
   0198 FE                  806 	mov	r6,a
   0199 B5 0F 02            807 	cjne	a,_blocked,00208$
   019C 80 0F               808 	sjmp	00125$
   019E                     809 00208$:
                    011F    810 	C$fb_rollo10.c$150$4$7 ==.
                            811 ;	..\fb_rollo10.c:150: START_WRITECYCLE;
   019E 75 E4 00            812 	mov	_FMCON,#0x00
                    0122    813 	C$fb_rollo10.c$151$4$7 ==.
                            814 ;	..\fb_rollo10.c:151: FMADRH= 0x1B;		
   01A1 75 E7 1B            815 	mov	_FMADRH,#0x1B
                    0125    816 	C$fb_rollo10.c$152$4$7 ==.
                            817 ;	..\fb_rollo10.c:152: FMADRL= 0xFD; 
   01A4 75 E6 FD            818 	mov	_FMADRL,#0xFD
                    0128    819 	C$fb_rollo10.c$153$4$7 ==.
                            820 ;	..\fb_rollo10.c:153: FMDATA= blocked;
   01A7 85 0F E5            821 	mov	_FMDATA,_blocked
                    012B    822 	C$fb_rollo10.c$154$4$7 ==.
                            823 ;	..\fb_rollo10.c:154: STOP_WRITECYCLE;
   01AA 75 E4 68            824 	mov	_FMCON,#0x68
   01AD                     825 00125$:
                    012E    826 	C$fb_rollo10.c$161$2$4 ==.
                            827 ;	..\fb_rollo10.c:161: if (tel_arrived ) {//|| tel_sent
                    012E    828 	C$fb_rollo10.c$162$3$8 ==.
                            829 ;	..\fb_rollo10.c:162: tel_arrived=0;
   01AD 10 09 02            830 	jbc	_tel_arrived,00209$
   01B0 80 0F               831 	sjmp	00129$
   01B2                     832 00209$:
                    0133    833 	C$fb_rollo10.c$163$3$8 ==.
                            834 ;	..\fb_rollo10.c:163: tel_sent=0;
   01B2 C2 0A               835 	clr	_tel_sent
                    0135    836 	C$fb_rollo10.c$164$3$8 ==.
                            837 ;	..\fb_rollo10.c:164: process_tel();
   01B4 C0 07               838 	push	ar7
   01B6 C0 23               839 	push	bits
   01B8 12 14 99            840 	lcall	_process_tel
   01BB D0 23               841 	pop	bits
   01BD D0 07               842 	pop	ar7
   01BF 80 0A               843 	sjmp	00130$
   01C1                     844 00129$:
                    0142    845 	C$fb_rollo10.c$167$3$4 ==.
                            846 ;	..\fb_rollo10.c:167: for(n=0;n<100;n++);	// falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann
   01C1 7E 64               847 	mov	r6,#0x64
   01C3                     848 00156$:
   01C3 8E 05               849 	mov	ar5,r6
   01C5 1D                  850 	dec	r5
   01C6 8D 06               851 	mov	ar6,r5
   01C8 EE                  852 	mov	a,r6
   01C9 70 F8               853 	jnz	00156$
   01CB                     854 00130$:
                    014C    855 	C$fb_rollo10.c$170$2$4 ==.
                            856 ;	..\fb_rollo10.c:170: BREAKPOINT
   01CB 30 98 0E            857 	jnb	_SCON_0,00135$
   01CE                     858 00131$:
   01CE 10 99 02            859 	jbc	_SCON_1,00212$
   01D1 80 FB               860 	sjmp	00131$
   01D3                     861 00212$:
   01D3 E5 99               862 	mov	a,_SBUF
   01D5 24 00               863 	add	a,#_RAM
   01D7 F9                  864 	mov	r1,a
   01D8 87 99               865 	mov	_SBUF,@r1
   01DA C2 98               866 	clr	_SCON_0
   01DC                     867 00135$:
                    015D    868 	C$fb_rollo10.c$234$2$4 ==.
                            869 ;	..\fb_rollo10.c:234: TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
   01DC D2 97               870 	setb	_P1_7
                    015F    871 	C$fb_rollo10.c$235$2$4 ==.
                            872 ;	..\fb_rollo10.c:235: if(!TASTER){ // Taster gedrückt
   01DE 20 97 12            873 	jb	_P1_7,00145$
                    0162    874 	C$fb_rollo10.c$236$3$11 ==.
                            875 ;	..\fb_rollo10.c:236: if(tasterpegel<255)	tasterpegel++;
   01E1 BF FF 00            876 	cjne	r7,#0xFF,00214$
   01E4                     877 00214$:
   01E4 50 03               878 	jnc	00139$
   01E6 0F                  879 	inc	r7
   01E7 80 12               880 	sjmp	00146$
   01E9                     881 00139$:
                    016A    882 	C$fb_rollo10.c$238$4$12 ==.
                            883 ;	..\fb_rollo10.c:238: if(!tastergetoggelt)status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
   01E9 20 18 03            884 	jb	b0,00137$
   01EC 63 7B 81            885 	xrl	_status60,#0x81
   01EF                     886 00137$:
                    0170    887 	C$fb_rollo10.c$239$4$12 ==.
                            888 ;	..\fb_rollo10.c:239: tastergetoggelt=1;
   01EF D2 18               889 	setb	b0
   01F1 80 08               890 	sjmp	00146$
   01F3                     891 00145$:
                    0174    892 	C$fb_rollo10.c$243$3$13 ==.
                            893 ;	..\fb_rollo10.c:243: if(tasterpegel>0) tasterpegel--;
   01F3 EF                  894 	mov	a,r7
   01F4 60 03               895 	jz	00142$
   01F6 1F                  896 	dec	r7
   01F7 80 02               897 	sjmp	00146$
   01F9                     898 00142$:
                    017A    899 	C$fb_rollo10.c$244$3$13 ==.
                            900 ;	..\fb_rollo10.c:244: else tastergetoggelt=0;
   01F9 C2 18               901 	clr	b0
   01FB                     902 00146$:
                    017C    903 	C$fb_rollo10.c$246$2$4 ==.
                            904 ;	..\fb_rollo10.c:246: TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
   01FB E5 7B               905 	mov	a,_status60
   01FD 54 01               906 	anl	a,#0x01
   01FF FE                  907 	mov	r6,a
   0200 B4 01 00            908 	cjne	a,#0x01,00218$
   0203                     909 00218$:
   0203 E4                  910 	clr	a
   0204 33                  911 	rlc	a
   0205 FE                  912 	mov	r6,a
   0206 24 FF               913 	add	a,#0xff
   0208 92 97               914 	mov	_P1_7,c
                    018B    915 	C$fb_rollo10.c$247$1$1 ==.
                            916 ;	..\fb_rollo10.c:247: } while(1);
   020A 02 01 2A            917 	ljmp	00147$
                    018E    918 	C$fb_rollo10.c$248$1$1 ==.
                    018E    919 	XG$main$0$0 ==.
   020D 22                  920 	ret
                            921 	.area CSEG    (CODE)
                            922 	.area CONST   (CODE)
                    1BFF    923 Lfb_rollo10.main$trimsave$1$1 == 0x1bff
                    1BFF    924 _main_trimsave_1_1	=	0x1bff
                    1BFD    925 Lfb_rollo10.main$blockedsave$1$1 == 0x1bfd
                    1BFD    926 _main_blockedsave_1_1	=	0x1bfd
                            927 	.area XINIT   (CODE)
                            928 	.area CABS    (ABS,CODE)
