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
#define ledPin      5     // PB5 

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
