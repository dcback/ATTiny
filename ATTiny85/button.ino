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
#define ledPin          1     // PB1 can be used rxPin & ledPin
#define buttonPin       2     // PB2 

SoftwareSerial mySerial(rxPin, txPin);

bool buttonState = 0;

void setup()
{
  mySerial.begin(9600);
  mySerial.println("[ATTiny Button]");

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH)
  {
    digitalWrite(ledPin, HIGH);    // turn LED on:
  }
  else
  {
    digitalWrite(ledPin, LOW);   // turn LED off:
  }
  mySerial.print("buttonState[");
  mySerial.print(buttonState);
  mySerial.println("] ");

  delay(1000);
}
