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

#define txPin       0     // PB0
#define rxPin       1     // PB1

SoftwareSerial mySerial(rxPin, txPin);

void setup()
{
  mySerial.begin(9600);     
}

void loop()
{
  unsigned int A0_value = analogRead(A0);
  unsigned int A1_value = analogRead(A1);
  unsigned int A2_value = analogRead(A2);
  unsigned int A3_value = analogRead(A3);
  mySerial.print("A0_Value["); mySerial.print(A0_value); mySerial.print("] ");
  mySerial.print("A1_Value["); mySerial.print(A1_value); mySerial.print("] ");
  mySerial.print("A2_Value["); mySerial.print(A2_value); mySerial.print("] ");
  mySerial.print("A3_Value["); mySerial.print(A3_value); mySerial.println("]");
  delay(1000);
}
