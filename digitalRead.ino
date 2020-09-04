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
#define buttonPin   0     // PB0

SoftwareSerial mySerial(rxPin, txPin);

bool ledStatus = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  mySerial.begin(9600);
  mySerial.println("[ATtiny digitalRead]");

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  int buttonState = digitalRead(buttonPin);
  mySerial.print("buttonState bool[");
  mySerial.print(buttonState);
  mySerial.print("] ");
  mySerial.print("int[");
  mySerial.print(buttonState);
  mySerial.println("]");

  digitalWrite(ledPin, buttonState);
  delay(1000);
}
