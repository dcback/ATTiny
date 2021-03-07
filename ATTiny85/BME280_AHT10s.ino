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
#include <AHT10.h>
#include <SoftwareSerial.h>

#define txPin       0
#define rxPin       1

SoftwareSerial mySerial(rxPin, txPin);
BME280_I2C bme(0x76);
AHT10 myAHT10(AHT10_ADDRESS_0X38);

void setup()
{
  mySerial.begin(9600);

  bme.begin();
  bme.setTempCal(-1.0);

  myAHT10.begin();
}

void loop()
{
  mySerial.flush();  
  float Atemp = myAHT10.readTemperature();
  float Ahumi = myAHT10.readHumidity();

  bme.readSensor();
  float Btemp = bme.getTemperature_C();
  float Bhumi = bme.getHumidity();  

  mySerial.println("");
  mySerial.println(F("-----------------------------------------------"));
  mySerial.print(F("[AHT10 ]"));
  mySerial.print(F("Temperature: "));
  mySerial.print(Atemp);
  mySerial.print("\t");
  mySerial.print(F("Humidity: "));
  mySerial.println(Ahumi);

  mySerial.print(F("[BME280]"));
  mySerial.print(F("Temperature: "));
  mySerial.print(Btemp);
  mySerial.print("\t");
  mySerial.print(F("Humidity: "));
  mySerial.println(Bhumi);
  delay(1000);
}
