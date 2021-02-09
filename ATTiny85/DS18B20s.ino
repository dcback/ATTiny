/*
  [Attiny 25/45/85 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK=SCL
        A2=PB4=4-|      |-1(~)=PB1=MISO
             GND-|      |-0(~)=PB0=MOSI=SDA
                  ------
*/
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>

#define txPin       0     // PB0
#define rxPin       1     // PB1

SoftwareSerial mySerial(rxPin, txPin);

#define ONE_WIRE_BUS 3   

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
