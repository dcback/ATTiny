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
#define analogPin   A1    // A1 = PB2 = 2, Analog input pin must use pinName A1
#define ledCount    5     // PB5

SoftwareSerial mySerial(rxPin, txPin);

int ledPins[] =
{
  0, 1, 3, 4, 5
};   // an array of pin numbers to which LEDs are attached


void setup() {
  mySerial.begin(9600);
  mySerial.println("[ATtiny analoRead to 5-LED bar graph]");
  // loop over the pin array and set them all to output:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {
  // read the potentiometer:
  int sensorReading = analogRead(analogPin);
  // map the result to a range from 0 to the number of LEDs:
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);

  mySerial.print("sensorValue : ");
  mySerial.print(sensorReading);
  mySerial.print("\t ledlevelValue : ");
  mySerial.println(ledLevel);

  // loop over the LED array:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // if the array element's index is less than ledLevel,
    // turn the pin for this element on:
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    }
    // turn off all pins higher than the ledLevel:
    else {
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
  delay(1000);
}
