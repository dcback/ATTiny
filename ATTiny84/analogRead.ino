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
