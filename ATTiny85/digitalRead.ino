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
  unsigned int D0 = digitalRead(0);
  unsigned int D1 = digitalRead(1);
  unsigned int D2 = digitalRead(2);
  unsigned int D3 = digitalRead(3);
  unsigned int D4 = digitalRead(4);
  unsigned int D5 = digitalRead(5);

  mySerial.print("D0["); mySerial.print(D0); mySerial.print("] ");
  mySerial.print("D1["); mySerial.print(D1); mySerial.print("] ");
  mySerial.print("D2["); mySerial.print(D2); mySerial.print("] ");
  mySerial.print("D3["); mySerial.print(D3); mySerial.print("] ");
  mySerial.print("D4["); mySerial.print(D4); mySerial.print("] ");
  mySerial.print("D5["); mySerial.print(D5); mySerial.println("]");
  delay(1000);
}
