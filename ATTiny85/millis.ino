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
#define ledPin          1     // PB1

SoftwareSerial mySerial(rxPin, txPin);

bool ledState = LOW;
unsigned long previousMillis = 0;   // will store last time LED was updated
const long interval = 1000;         // interval at which to blink (milliseconds)

void setup()
{
  mySerial.begin(9600);
  mySerial.println("[ATTiny85 millis]");
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;   // save the last time at blinked the LED
    digitalWrite(ledPin, ledState);   // set the LED with the ledState of the variable:
    mySerial.print(currentMillis / 1000);
    mySerial.print("초 : ");
    mySerial.println(ledState);
    ledState = !ledState;
  }
}
