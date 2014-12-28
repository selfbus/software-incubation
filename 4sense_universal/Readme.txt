4Sense Universal 

4Sense universal beinhaltet die 1-Wire Temperatursensor Unterstützung sowie DHT Temperatur- und Feuchtigkeitssensoren. 
In Header kann die jeweilige Unterstützung eingeschaltet werden. Es können alle Sensoren Gleichzeit verwenden werden. Je nach Anwendung kann aber auch das eine oder andere separat definiert und verwendet werden. Je nach Applikation können auch mehrere Sensoren und Sensor typen definiert und verwendet werden.

Aufnahme in die eigene Applikation:
Einfach die Entsprechende *.C als inlucde in die Applikation hinzufügen und anhand der Beispiel Projekte die 4Sense Funktionen verwenden.

ToDo: Beispiel Applikationen hinterlegen.

Unterstützte Sensoren:
- 1-Wire Sensoren: DS18S20, DS18B20, MAX31820, DS1822
- DHT Sensoren: DHT11, DHT21, DHT22, AM2302 


1-Wire Anschluss:
--------------
-   1-wire   -
--------------
 |    |    |
GND Data  VCC


DHT Anschluss:
-------------------
-       DHT       -
-------------------
 |    |    |    | 
VCC Data  NC   GND


Beispiel einer direkten Beschaltung:
Sensor --> LPC
---------------
VCC  <--> VCC
Data <--> PX_X
GND  <--> GND


28.10.2015 Erkan Colak