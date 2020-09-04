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

#define rxPin         PB4   // 4
#define txPin         PB3   // 3
#define analoginPin   A1    // A1 = PB2 = 2, Analog input pin must use pinName A1
#define analogoutPin  PB1   // 1 Analog output pin that the LED is attached to

SoftwareSerial mySerial(rxPin, txPin);

int sensorValue = 0;          // value read from the pot
int outputValue = 0;          // value output to the PWM (analog out)

void setup() {
  mySerial.begin(9600);
  mySerial.println("[ATtiny Analog-in to Analog-out(PWM)]");
}

void loop() {
  sensorValue = analogRead(analoginPin);  // read the analog in value
  outputValue = map(sensorValue, 0, 1023, 0, 255);  // map it to the range of the analog out
  analogWrite(analogoutPin, outputValue); // change the analog out value:

  mySerial.print("sensor = [");
  mySerial.print(sensorValue);
  mySerial.print("]\t output = [");
  mySerial.print(outputValue);
  mySerial.println("]");

  delay(2);     // ADC to settling time
  delay(1000);
}
