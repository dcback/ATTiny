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
#define ledPin      1     // PB1 can be used rxPin & ledPin

bool  ledState = 0;

SoftwareSerial mySerial(rxPin, txPin);

void setup()
{
  mySerial.begin(9600);   // Max speed:9600
  mySerial.println("[LED On/Off in 1 sec.]");
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  digitalWrite(ledPin, ledState);
  mySerial.print("LED-State : ");
  mySerial.println(ledState);
  delay(1000);

  ledState = !ledState;
}
