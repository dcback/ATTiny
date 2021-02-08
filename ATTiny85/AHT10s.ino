/*
  [Attiny 25/45/85 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK=SCL
        A2=PB4=4-|      |-1(~)=PB1=MISO
             GND-|      |-0(~)=PB0=MOSI=SDA
                  ------
*/
#include <AHT10.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#define txPin       3     // PB3
#define rxPin       4     // PB4

SoftwareSerial mySerial(rxPin, txPin);
AHT10 myAHT10(AHT10_ADDRESS_0X38);

void setup()
{
  mySerial.begin(9600);   
  myAHT10.begin() ;
}

void loop()
{
  mySerial.print(F("Temperature: ")); mySerial.print(myAHT10.readTemperature());
  mySerial.print("\t");
  mySerial.print(F("Humidity: ")); mySerial.println(myAHT10.readHumidity());
  delay(3000);
}
