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
#define sensorPin   A1    // A1 = PB2 = 2, Analog input pin must use pinName A1

SoftwareSerial mySerial(rxPin, txPin);

// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

void setup() {
  mySerial.begin(9600);
  mySerial.println("[ATtiny Calibration]");

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);    // turn on LED to signal the start of the calibration period:

  // calibrate during the first five seconds
  while (millis() < 5000)
  {
    sensorValue = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax)
    {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin)
    {
      sensorMin = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW); // signal the end of the calibration period
}

void loop() {
  sensorValue = analogRead(sensorPin);  // read the sensor:
  mySerial.print("analogRead Value = [");
  mySerial.print(sensorValue);
  mySerial.println("]");

  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255); // apply the calibration to the sensor reading
  mySerial.print("map Value = [");
  mySerial.print(sensorValue);
  mySerial.println("]");

  sensorValue = constrain(sensorValue, 0, 255); // in case the sensor value is outside the range seen during calibration
  mySerial.print("constrain Value = [");
  mySerial.print(sensorValue);
  mySerial.println("]");
  mySerial.println("------------------------");

  analogWrite(ledPin, sensorValue); // fade the LED using the calibrated value:
  delay(1000);
}
