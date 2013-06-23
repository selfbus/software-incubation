                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Sun Jun 23 16:20:02 2013
                              5 ;--------------------------------------------------------
                              6 	.module fb_rollo11
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
   0013 02 0D 69            520 	ljmp	_X1_int
   0016                     521 	.ds	5
   001B 02 0D 99            522 	ljmp	_T1_int
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
                    0000    563 	C$fb_rollo11.c$48$0$0 ==.
                            564 ;	..\fb_rollo11.c:48: void main(void)
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
                    0000    577 	C$fb_rollo11.c$50$1$0 ==.
                            578 ;	..\fb_rollo11.c:50: unsigned char n,cmd,tasterpegel=0;
   007F 7F 00               579 	mov	r7,#0x00
                    0002    580 	C$fb_rollo11.c$58$1$0 ==.
                            581 ;	..\fb_rollo11.c:58: __bit wduf,tastergetoggelt=0;
   0081 C2 18               582 	clr	b0
                    0004    583 	C$fb_rollo11.c$59$1$1 ==.
                            584 ;	..\fb_rollo11.c:59: wduf=WDCON&0x02;
   0083 E5 A7               585 	mov	a,_WDCON
   0085 03                  586 	rr	a
   0086 54 01               587 	anl	a,#0x01
   0088 24 FF               588 	add	a,#0xff
   008A 92 19               589 	mov	b1,c
                    000D    590 	C$fb_rollo11.c$60$1$1 ==.
                            591 ;	..\fb_rollo11.c:60: restart_hw();							// Hardware zuruecksetzen
   008C C0 07               592 	push	ar7
   008E C0 23               593 	push	bits
   0090 12 17 37            594 	lcall	_restart_hw
   0093 D0 23               595 	pop	bits
   0095 D0 07               596 	pop	ar7
                    0018    597 	C$fb_rollo11.c$63$1$1 ==.
                            598 ;	..\fb_rollo11.c:63: TASTER=1;
   0097 D2 97               599 	setb	_P1_7
                    001A    600 	C$fb_rollo11.c$64$1$1 ==.
                            601 ;	..\fb_rollo11.c:64: if(!TASTER && wduf)cal=0;
   0099 20 97 03            602 	jb	_P1_7,00102$
   009C 20 19 05            603 	jb	b1,00103$
   009F                     604 00102$:
                    0020    605 	C$fb_rollo11.c$65$1$1 ==.
                            606 ;	..\fb_rollo11.c:65: else cal=trimsave;
   009F 90 1B FF            607 	mov	dptr,#_main_trimsave_1_1
   00A2 E4                  608 	clr	a
   00A3 93                  609 	movc	a,@a+dptr
   00A4                     610 00103$:
                    0025    611 	C$fb_rollo11.c$66$1$1 ==.
                            612 ;	..\fb_rollo11.c:66: TRIM = (TRIM+trimsave);
   00A4 90 1B FF            613 	mov	dptr,#_main_trimsave_1_1
   00A7 E4                  614 	clr	a
   00A8 93                  615 	movc	a,@a+dptr
   00A9 AD 96               616 	mov	r5,_TRIM
   00AB 2D                  617 	add	a,r5
   00AC FE                  618 	mov	r6,a
   00AD 8E 96               619 	mov	_TRIM,r6
                    0030    620 	C$fb_rollo11.c$67$1$1 ==.
                            621 ;	..\fb_rollo11.c:67: TRIM &= 0x3F;//oberen 2 bits ausblenden
   00AF 53 96 3F            622 	anl	_TRIM,#0x3F
                    0033    623 	C$fb_rollo11.c$72$1$1 ==.
                            624 ;	..\fb_rollo11.c:72: TASTER=0;
   00B2 C2 97               625 	clr	_P1_7
                    0035    626 	C$fb_rollo11.c$73$1$1 ==.
                            627 ;	..\fb_rollo11.c:73: if (!wduf){// BUS return verzögerung nur wenn nicht watchdog underflow
   00B4 20 19 21            628 	jb	b1,00109$
                    0038    629 	C$fb_rollo11.c$74$1$1 ==.
                            630 ;	..\fb_rollo11.c:74: for (n=0;n<50;n++) {		// Warten bis Bus stabil
   00B7 7E 00               631 	mov	r6,#0x00
   00B9                     632 00150$:
   00B9 BE 32 00            633 	cjne	r6,#0x32,00192$
   00BC                     634 00192$:
   00BC 50 1A               635 	jnc	00109$
                    003F    636 	C$fb_rollo11.c$75$3$3 ==.
                            637 ;	..\fb_rollo11.c:75: TR0=0;					// Timer 0 anhalten
   00BE C2 8C               638 	clr	_TCON_4
                    0041    639 	C$fb_rollo11.c$76$3$3 ==.
                            640 ;	..\fb_rollo11.c:76: TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
   00C0 90 1D 17            641 	mov	dptr,#(_eeprom + 0x0017)
   00C3 E4                  642 	clr	a
   00C4 93                  643 	movc	a,@a+dptr
   00C5 F5 8C               644 	mov	_TH0,a
                    0048    645 	C$fb_rollo11.c$77$3$3 ==.
                            646 ;	..\fb_rollo11.c:77: TL0=eeprom[ADDRTAB+2];
   00C7 90 1D 18            647 	mov	dptr,#(_eeprom + 0x0018)
   00CA E4                  648 	clr	a
   00CB 93                  649 	movc	a,@a+dptr
   00CC F5 8A               650 	mov	_TL0,a
                    004F    651 	C$fb_rollo11.c$78$3$3 ==.
                            652 ;	..\fb_rollo11.c:78: TF0=0;					// Überlauf-Flag zurücksetzen
   00CE C2 8D               653 	clr	_TCON_5
                    0051    654 	C$fb_rollo11.c$79$3$3 ==.
                            655 ;	..\fb_rollo11.c:79: TR0=1;					// Timer 0 starten
   00D0 D2 8C               656 	setb	_TCON_4
                    0053    657 	C$fb_rollo11.c$80$3$3 ==.
                            658 ;	..\fb_rollo11.c:80: while(!TF0);
   00D2                     659 00105$:
   00D2 30 8D FD            660 	jnb	_TCON_5,00105$
                    0056    661 	C$fb_rollo11.c$74$2$2 ==.
                            662 ;	..\fb_rollo11.c:74: for (n=0;n<50;n++) {		// Warten bis Bus stabil
   00D5 0E                  663 	inc	r6
   00D6 80 E1               664 	sjmp	00150$
   00D8                     665 00109$:
                    0059    666 	C$fb_rollo11.c$83$1$1 ==.
                            667 ;	..\fb_rollo11.c:83: WATCHDOG_INIT
   00D8 75 C1 FF            668 	mov	_WDL,#0xFF
   00DB C2 AF               669 	clr	_IEN0_7
   00DD 75 A7 E5            670 	mov	_WDCON,#0xE5
   00E0 75 C2 A5            671 	mov	_WFEED1,#0xA5
   00E3 75 C3 5A            672 	mov	_WFEED2,#0x5A
   00E6 D2 AF               673 	setb	_IEN0_7
                    0069    674 	C$fb_rollo11.c$84$1$1 ==.
                            675 ;	..\fb_rollo11.c:84: WATCHDOG_START
   00E8 C2 AF               676 	clr	_IEN0_7
   00EA 43 A7 04            677 	orl	_WDCON,#0x04
   00ED 75 C2 A5            678 	mov	_WFEED1,#0xA5
   00F0 75 C3 5A            679 	mov	_WFEED2,#0x5A
   00F3 D2 AF               680 	setb	_IEN0_7
                    0076    681 	C$fb_rollo11.c$85$1$1 ==.
                            682 ;	..\fb_rollo11.c:85: restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
   00F5 C0 07               683 	push	ar7
   00F7 C0 23               684 	push	bits
   00F9 12 0D 00            685 	lcall	_restart_app
   00FC D0 23               686 	pop	bits
   00FE D0 07               687 	pop	ar7
                    0081    688 	C$fb_rollo11.c$86$1$1 ==.
                            689 ;	..\fb_rollo11.c:86: if(!wduf)bus_return();							// Aktionen bei Busspannungswiederkehr
   0100 20 19 0B            690 	jb	b1,00111$
   0103 C0 07               691 	push	ar7
   0105 C0 23               692 	push	bits
   0107 12 0C 5D            693 	lcall	_bus_return
   010A D0 23               694 	pop	bits
   010C D0 07               695 	pop	ar7
   010E                     696 00111$:
                    008F    697 	C$fb_rollo11.c$87$1$1 ==.
                            698 ;	..\fb_rollo11.c:87: RS_INIT_115200
   010E 53 BD FE            699 	anl	_BRGCON,#0xFE
   0111 75 98 50            700 	mov	_SCON,#0x50
   0114 43 BA E0            701 	orl	_SSTAT,#0xE0
   0117 43 BD 02            702 	orl	_BRGCON,#0x02
   011A 75 BF 00            703 	mov	_BRGR1,#0x00
   011D 75 BE 30            704 	mov	_BRGR0,#0x30
   0120 43 BD 01            705 	orl	_BRGCON,#0x01
                    00A4    706 	C$fb_rollo11.c$88$1$1 ==.
                            707 ;	..\fb_rollo11.c:88: SBUF=0x55;
   0123 75 99 55            708 	mov	_SBUF,#0x55
                    00A7    709 	C$fb_rollo11.c$89$1$1 ==.
                            710 ;	..\fb_rollo11.c:89: do  {
   0126                     711 00147$:
                    00A7    712 	C$fb_rollo11.c$90$2$4 ==.
                            713 ;	..\fb_rollo11.c:90: WATCHDOG_FEED
   0126 C2 AF               714 	clr	_IEN0_7
   0128 75 C2 A5            715 	mov	_WFEED1,#0xA5
   012B 75 C3 5A            716 	mov	_WFEED2,#0x5A
   012E D2 AF               717 	setb	_IEN0_7
                    00B1    718 	C$fb_rollo11.c$92$2$4 ==.
                            719 ;	..\fb_rollo11.c:92: if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt
   0130 90 1D 0D            720 	mov	dptr,#(_eeprom + 0x000d)
   0133 E4                  721 	clr	a
   0134 93                  722 	movc	a,@a+dptr
   0135 FE                  723 	mov	r6,a
   0136 BE FF 70            724 	cjne	r6,#0xFF,00125$
   0139 20 11 6D            725 	jb	_connected,00125$
   013C E5 7B               726 	mov	a,_status60
   013E 20 E0 68            727 	jb	acc.0,00125$
                    00C2    728 	C$fb_rollo11.c$96$3$5 ==.
                            729 ;	..\fb_rollo11.c:96: */			if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf
   0141 74 80               730 	mov	a,#0x100 - 0x80
   0143 25 D1               731 	add	a,_RTCCON
   0145 50 0B               732 	jnc	00113$
   0147 C0 07               733 	push	ar7
   0149 C0 23               734 	push	bits
   014B 12 08 9F            735 	lcall	_delay_timer
   014E D0 23               736 	pop	bits
   0150 D0 07               737 	pop	ar7
   0152                     738 00113$:
                    00D3    739 	C$fb_rollo11.c$98$3$5 ==.
                            740 ;	..\fb_rollo11.c:98: if(TF0 && (TMOD & 0x0F)==0x01) {	// Vollstrom für Relais ausschalten und wieder PWM ein
   0152 30 8D 1F            741 	jnb	_TCON_5,00115$
   0155 74 0F               742 	mov	a,#0x0F
   0157 55 89               743 	anl	a,_TMOD
   0159 FE                  744 	mov	r6,a
   015A BE 01 17            745 	cjne	r6,#0x01,00115$
                    00DE    746 	C$fb_rollo11.c$100$4$6 ==.
                            747 ;	..\fb_rollo11.c:100: TMOD=(TMOD & 0xF0) + 2;			// Timer 0 als PWM
   015D 74 F0               748 	mov	a,#0xF0
   015F 55 89               749 	anl	a,_TMOD
   0161 24 02               750 	add	a,#0x02
   0163 F5 89               751 	mov	_TMOD,a
                    00E6    752 	C$fb_rollo11.c$101$4$6 ==.
                            753 ;	..\fb_rollo11.c:101: TAMOD=0x01;
   0165 75 8F 01            754 	mov	_TAMOD,#0x01
                    00E9    755 	C$fb_rollo11.c$102$4$6 ==.
                            756 ;	..\fb_rollo11.c:102: TH0=DUTY;
   0168 75 8C 50            757 	mov	_TH0,#0x50
                    00EC    758 	C$fb_rollo11.c$104$4$6 ==.
                            759 ;	..\fb_rollo11.c:104: TF0=0;
   016B C2 8D               760 	clr	_TCON_5
                    00EE    761 	C$fb_rollo11.c$106$4$6 ==.
                            762 ;	..\fb_rollo11.c:106: AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben
   016D 43 A2 10            763 	orl	_AUXR1,#0x10
                    00F1    764 	C$fb_rollo11.c$108$4$6 ==.
                            765 ;	..\fb_rollo11.c:108: PWM=1;			// PWM Pin muss auf 1 gesetzt werden, damit PWM geht !!!
   0170 D2 92               766 	setb	_P1_2
                    00F3    767 	C$fb_rollo11.c$110$4$6 ==.
                            768 ;	..\fb_rollo11.c:110: TR0=1;
   0172 D2 8C               769 	setb	_TCON_4
   0174                     770 00115$:
                    00F5    771 	C$fb_rollo11.c$117$3$5 ==.
                            772 ;	..\fb_rollo11.c:117: if (portchanged)port_schalten();	// Ausgänge schalten
   0174 30 00 0B            773 	jnb	_portchanged,00118$
   0177 C0 07               774 	push	ar7
   0179 C0 23               775 	push	bits
   017B 12 0B DF            776 	lcall	_port_schalten
   017E D0 23               777 	pop	bits
   0180 D0 07               778 	pop	ar7
   0182                     779 00118$:
                    0103    780 	C$fb_rollo11.c$146$3$5 ==.
                            781 ;	..\fb_rollo11.c:146: if (fb_state==0 && (TH1<0XC0) && (!wait_for_ack)&& blocked!=blockedsave) {
   0182 E5 77               782 	mov	a,_fb_state
   0184 70 23               783 	jnz	00125$
   0186 74 40               784 	mov	a,#0x100 - 0xC0
   0188 25 8D               785 	add	a,_TH1
   018A 40 1D               786 	jc	00125$
   018C 20 0D 1A            787 	jb	_wait_for_ack,00125$
   018F 90 1B FD            788 	mov	dptr,#_main_blockedsave_1_1
   0192 E4                  789 	clr	a
   0193 93                  790 	movc	a,@a+dptr
   0194 FE                  791 	mov	r6,a
   0195 B5 0F 02            792 	cjne	a,_blocked,00208$
   0198 80 0F               793 	sjmp	00125$
   019A                     794 00208$:
                    011B    795 	C$fb_rollo11.c$147$4$7 ==.
                            796 ;	..\fb_rollo11.c:147: START_WRITECYCLE;
   019A 75 E4 00            797 	mov	_FMCON,#0x00
                    011E    798 	C$fb_rollo11.c$148$4$7 ==.
                            799 ;	..\fb_rollo11.c:148: FMADRH= 0x1B;		
   019D 75 E7 1B            800 	mov	_FMADRH,#0x1B
                    0121    801 	C$fb_rollo11.c$149$4$7 ==.
                            802 ;	..\fb_rollo11.c:149: FMADRL= 0xFD; 
   01A0 75 E6 FD            803 	mov	_FMADRL,#0xFD
                    0124    804 	C$fb_rollo11.c$150$4$7 ==.
                            805 ;	..\fb_rollo11.c:150: FMDATA= blocked;
   01A3 85 0F E5            806 	mov	_FMDATA,_blocked
                    0127    807 	C$fb_rollo11.c$151$4$7 ==.
                            808 ;	..\fb_rollo11.c:151: STOP_WRITECYCLE;
   01A6 75 E4 68            809 	mov	_FMCON,#0x68
   01A9                     810 00125$:
                    012A    811 	C$fb_rollo11.c$158$2$4 ==.
                            812 ;	..\fb_rollo11.c:158: if (tel_arrived ) {//|| tel_sent
                    012A    813 	C$fb_rollo11.c$159$3$8 ==.
                            814 ;	..\fb_rollo11.c:159: tel_arrived=0;
   01A9 10 09 02            815 	jbc	_tel_arrived,00209$
   01AC 80 0F               816 	sjmp	00129$
   01AE                     817 00209$:
                    012F    818 	C$fb_rollo11.c$160$3$8 ==.
                            819 ;	..\fb_rollo11.c:160: tel_sent=0;
   01AE C2 0A               820 	clr	_tel_sent
                    0131    821 	C$fb_rollo11.c$161$3$8 ==.
                            822 ;	..\fb_rollo11.c:161: process_tel();
   01B0 C0 07               823 	push	ar7
   01B2 C0 23               824 	push	bits
   01B4 12 14 2B            825 	lcall	_process_tel
   01B7 D0 23               826 	pop	bits
   01B9 D0 07               827 	pop	ar7
   01BB 80 0A               828 	sjmp	00130$
   01BD                     829 00129$:
                    013E    830 	C$fb_rollo11.c$164$3$4 ==.
                            831 ;	..\fb_rollo11.c:164: for(n=0;n<100;n++);	// falls Hauptroutine keine Zeit verbraucht, der PROG LED etwas Zeit geben, damit sie auch leuchten kann
   01BD 7E 64               832 	mov	r6,#0x64
   01BF                     833 00156$:
   01BF 8E 05               834 	mov	ar5,r6
   01C1 1D                  835 	dec	r5
   01C2 8D 06               836 	mov	ar6,r5
   01C4 EE                  837 	mov	a,r6
   01C5 70 F8               838 	jnz	00156$
   01C7                     839 00130$:
                    0148    840 	C$fb_rollo11.c$167$2$4 ==.
                            841 ;	..\fb_rollo11.c:167: DEBUGPOINT
   01C7 30 98 0E            842 	jnb	_SCON_0,00135$
   01CA                     843 00131$:
   01CA 10 99 02            844 	jbc	_SCON_1,00212$
   01CD 80 FB               845 	sjmp	00131$
   01CF                     846 00212$:
   01CF E5 99               847 	mov	a,_SBUF
   01D1 24 00               848 	add	a,#_RAM
   01D3 F9                  849 	mov	r1,a
   01D4 87 99               850 	mov	_SBUF,@r1
   01D6 C2 98               851 	clr	_SCON_0
   01D8                     852 00135$:
                    0159    853 	C$fb_rollo11.c$232$2$4 ==.
                            854 ;	..\fb_rollo11.c:232: TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
   01D8 D2 97               855 	setb	_P1_7
                    015B    856 	C$fb_rollo11.c$233$2$4 ==.
                            857 ;	..\fb_rollo11.c:233: if(!TASTER){ // Taster gedrückt
   01DA 20 97 12            858 	jb	_P1_7,00145$
                    015E    859 	C$fb_rollo11.c$234$3$11 ==.
                            860 ;	..\fb_rollo11.c:234: if(tasterpegel<255)	tasterpegel++;
   01DD BF FF 00            861 	cjne	r7,#0xFF,00214$
   01E0                     862 00214$:
   01E0 50 03               863 	jnc	00139$
   01E2 0F                  864 	inc	r7
   01E3 80 12               865 	sjmp	00146$
   01E5                     866 00139$:
                    0166    867 	C$fb_rollo11.c$236$4$12 ==.
                            868 ;	..\fb_rollo11.c:236: if(!tastergetoggelt)status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
   01E5 20 18 03            869 	jb	b0,00137$
   01E8 63 7B 81            870 	xrl	_status60,#0x81
   01EB                     871 00137$:
                    016C    872 	C$fb_rollo11.c$237$4$12 ==.
                            873 ;	..\fb_rollo11.c:237: tastergetoggelt=1;
   01EB D2 18               874 	setb	b0
   01ED 80 08               875 	sjmp	00146$
   01EF                     876 00145$:
                    0170    877 	C$fb_rollo11.c$241$3$13 ==.
                            878 ;	..\fb_rollo11.c:241: if(tasterpegel>0) tasterpegel--;
   01EF EF                  879 	mov	a,r7
   01F0 60 03               880 	jz	00142$
   01F2 1F                  881 	dec	r7
   01F3 80 02               882 	sjmp	00146$
   01F5                     883 00142$:
                    0176    884 	C$fb_rollo11.c$242$3$13 ==.
                            885 ;	..\fb_rollo11.c:242: else tastergetoggelt=0;
   01F5 C2 18               886 	clr	b0
   01F7                     887 00146$:
                    0178    888 	C$fb_rollo11.c$244$2$4 ==.
                            889 ;	..\fb_rollo11.c:244: TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
   01F7 E5 7B               890 	mov	a,_status60
   01F9 54 01               891 	anl	a,#0x01
   01FB FE                  892 	mov	r6,a
   01FC B4 01 00            893 	cjne	a,#0x01,00218$
   01FF                     894 00218$:
   01FF E4                  895 	clr	a
   0200 33                  896 	rlc	a
   0201 FE                  897 	mov	r6,a
   0202 24 FF               898 	add	a,#0xff
   0204 92 97               899 	mov	_P1_7,c
                    0187    900 	C$fb_rollo11.c$245$1$1 ==.
                            901 ;	..\fb_rollo11.c:245: } while(1);
   0206 02 01 26            902 	ljmp	00147$
                    018A    903 	C$fb_rollo11.c$246$1$1 ==.
                    018A    904 	XG$main$0$0 ==.
   0209 22                  905 	ret
                            906 	.area CSEG    (CODE)
                            907 	.area CONST   (CODE)
                    1BFF    908 Lfb_rollo11.main$trimsave$1$1 == 0x1bff
                    1BFF    909 _main_trimsave_1_1	=	0x1bff
                    1BFD    910 Lfb_rollo11.main$blockedsave$1$1 == 0x1bfd
                    1BFD    911 _main_blockedsave_1_1	=	0x1bfd
                            912 	.area XINIT   (CODE)
                            913 	.area CABS    (ABS,CODE)
