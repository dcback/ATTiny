/* http://homemadehardware.com/img/attiny85_pinout.jpeg
  [Attiny 25/45/85 Pinout]
                  ------
  5=PB5=A0=RESET-|      |-VCC
        3=PB3=A3-|      |-2=PB2=A1=SCK
        4=PB4=A2-|      |-1=PB1=MISO
            GND -|      |-0=PB0=MOSI
                  ------
*/
#include <SoftwareSerial.h>

#define rxPin       4     // PB4
#define txPin       3     // PB3
#define ledPin      1     // PB1 
#define buttonPin   2     // PB2  

SoftwareSerial mySerial(rxPin, txPin);

bool buttonState = 0;

void setup()
{
  mySerial.begin(9600);
  mySerial.println("[ATtiny Button & LED On/Off]");
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH)
  {
    digitalWrite(ledPin, LOW);    // turn LED on:
  }
  else
  {
    digitalWrite(ledPin, HIGH);   // turn LED off:
  }
  mySerial.print("buttonState bool[");
  mySerial.print(buttonState);
  mySerial.println("] ");

  delay(1000);
}
