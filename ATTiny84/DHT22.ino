/*
  [Attiny 44/84 Pinout]
                        ------
                   VCC-|      |-GND
                PB0=10-|      |-0=PA0=A0
                 PB1=9-|      |-1=PA1=A1
             RESET=PB3-|      |-2=PA2=A2
              PB2=8(~)-|      |-3=PA3=A3
           A7=PA7=7(~)-|      |-4=PA4=A4=SCK=SCL
  SDA=MOSI=A6=PA6=6(~)-|      |-5(~)=PA5=A5=MISO
                        ------
*/
#include <DHT.h>
#include <SoftwareSerial.h>

#define txPin       0     // PB0
#define rxPin       1     // PB1

SoftwareSerial mySerial(rxPin, txPin);

#define DHTPIN  10
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  mySerial.begin(9600);
  dht.begin();
}

void loop()
{
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();

  mySerial.print("temperature:");
  mySerial.print(temp);
  mySerial.print("\t");
  mySerial.print("humidity:");
  mySerial.println(humi);
  
  delay(1000);
}
