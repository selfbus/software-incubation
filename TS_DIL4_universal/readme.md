TS_DIL4 Universal 
--
TS_DIL4_Universal is an Fork of [Taster4_universal] and has the same features. Additionaly it will support with [4sense_universal] the relative humidity and temperature with DHT sensors. Only one sensor type is supported! The sensor can be attachend to the Port: P1_1 (RXD).

####State
- DHT sensor support -> OK
- Temperature support -> OK
- Relative humidity support -> OK
- VD with DHT temperature and relative humidity support -> OK
- VD with selectable DHT sensor -> OK
- Ifdef the release targets for DS and DHT Sensors -> OK
- Release builds for DS and DHT -> OK
- Tested the DS release build with DS18b20 & DS1822 -> OK
- Tested the DS release build with DS18S20 -> OK
- Likely fixed: FW: Get and send the temperature and humidity is interrupted after a few weeks. Workarround: Reset unit. -> still testing
####ToDo:

- Long-Term Test

####KnownBugs:
- VD: The latest VD (V13) is buggy. Download and use --> [VD_V12]

###State: Release candidate

[Taster4_universal]:https://github.com/selfbus/software/tree/master/Taster4_universal
[4sense_universal]:https://github.com/selfbus/software-incubation/tree/master/4sense_universal
[VD_V12]:https://github.com/selfbus/software-incubation/tree/4216dbd6d4e9ac39c7a40b12112a82d9800dcc9a/TS_DIL4_universal/Releases
