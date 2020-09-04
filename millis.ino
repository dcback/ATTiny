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

SoftwareSerial mySerial(rxPin, txPin);

bool ledState = LOW;
unsigned long previousMillis = 0;   // will store last time LED was updated
const long interval = 1000;         // interval at which to blink (milliseconds)

void setup()
{
  mySerial.begin(9600);
  mySerial.println("[ATtiny millis]");
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;   // save the last time at blinked the LED

    if (ledState == LOW)    // if the LED is off turn it on and vice-versa:
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);   // set the LED with the ledState of the variable:
    mySerial.print(currentMillis / 1000);
    mySerial.print("초 : ");
    mySerial.println(ledState);
  }
}
