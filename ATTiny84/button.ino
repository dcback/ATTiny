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

#define ledPin          5     // PB5
#define buttonPin       2     // PB2 

SoftwareSerial mySerial(rxPin, txPin);

bool buttonState = 0;

void setup()
{
  mySerial.begin(9600);

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
