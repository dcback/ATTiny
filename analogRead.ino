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

#define rxPin     4   // PB4
#define txPin     3   // PB3
#define ledPin    1   // PB1

SoftwareSerial mySerial(rxPin, txPin);

bool ledStatus = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  mySerial.begin(9600);
  mySerial.println("[ATtiny analoRead : ADC to Voltage]");
}

void loop() {
  int sensorValue = analogRead(A1);   // A1 name must use, ADC Value : 0~5V, 10bit(0~1023)
  mySerial.print("A0 sensorValue int[");
  mySerial.print(sensorValue);
  mySerial.print("]");
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5.0V):
  float voltage = sensorValue * (5 / 1023.0);
  mySerial.print(" -> Convert voltage[");
  mySerial.print(voltage);
  mySerial.println("V]");

  digitalWrite(ledPin, ledStatus);
  delay(1000);
  ledStatus = !ledStatus;
}
