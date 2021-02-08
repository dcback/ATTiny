/*
  [Attiny 25/45/85 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK=SCL
        A2=PB4=4-|      |-1(~)=PB1=MISO
             GND-|      |-0(~)=PB0=MOSI=SDA
                  ------
*/
#include <Wire.h>
#include <cactus_io_BME280_I2C.h>
#include <SoftwareSerial.h>

#define txPin       3     // PB3
#define rxPin       4     // PB4

SoftwareSerial mySerial(rxPin, txPin);
BME280_I2C bme(0x76);                     // I2C using address 0x76

void setup()
{
  mySerial.begin(9600);
  bme.begin();
  bme.setTempCal(-1.0);
}

void loop()
{
  bme.readSensor();

  mySerial.print(F("Temperature: ")); mySerial.print(bme.getTemperature_C());
  mySerial.print("\t");
  mySerial.print(F("Humidity: ")); mySerial.println(bme.getHumidity());
  delay(3000);
}
