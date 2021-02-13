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
