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
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>

#define txPin       0     // PB0
#define rxPin       1     // PB1

SoftwareSerial mySerial(rxPin, txPin);

#define ONE_WIRE_BUS  9  

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  mySerial.begin(9600);
  sensors.begin();
}
void loop(void)
{
  mySerial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperature readings
  mySerial.println("DONE");

  mySerial.print("Temperature is: ");
  mySerial.print(sensors.getTempCByIndex(0)); // 0 refers to the first IC on the wire
  delay(1000);
}
