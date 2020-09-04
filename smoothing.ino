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
#define inputPin    A1    // PB2

#define numReadings   10

SoftwareSerial mySerial(rxPin, txPin);

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

void setup()
{
  mySerial.begin(9600);
  mySerial.println("[ATtiny85 Smoothing]");
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
  {
    readings[thisReading] = 0;
  }
}

void loop()
{
  total = total - readings[readIndex];  // subtract the last reading:
  readings[readIndex] = analogRead(inputPin); // read from the sensor:
  total = total + readings[readIndex];  // add the reading to the total:
  readIndex = readIndex + 1;  // advance to the next position in the array:

  if (readIndex >= numReadings) // if we're at the end of the array...
  {
    readIndex = 0;  // ...wrap around to the beginning:
  }

  average = total / numReadings;  // calculate the average:
  mySerial.println(average);    // send it to the computer as ASCII digits
  delay(1);        // delay in between reads for stability
  delay(1000);
}
