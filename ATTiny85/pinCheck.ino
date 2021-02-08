/*
  [Attiny 25/45/85 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK=SCL
        A2=PB4=4-|      |-1(~)=PB1=MISO
             GND-|      |-0(~)=PB0=MOSI=SDA
                  ------
*/
#include <SoftwareSerial.h>

#define txPin           0     // PB0
#define rxPin           1     // PB1

SoftwareSerial mySerial(rxPin, txPin);

void setup()
{
  mySerial.begin(9600);
}

void loop()
{
  mySerial.println("[ATTiny85 pinTest]");
  mySerial.print("PB0="); mySerial.println(PB0);    // 0
  mySerial.print("PB1="); mySerial.println(PB1);    // 1
  mySerial.print("PB2="); mySerial.println(PB2);    // 2
  mySerial.print("PB3="); mySerial.println(PB3);    // 3
  mySerial.print("PB4="); mySerial.println(PB4);    // 4
  mySerial.print("PB5="); mySerial.println(PB5);    // 5
  delay(1000);
}
