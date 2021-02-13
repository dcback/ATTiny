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
#include <Wire.h>
#include <cactus_io_BME280_I2C.h>
#include <AHT10.h>
#include <SoftwareSerial.h>

#define txPin       0     // PB0
#define rxPin       1     // PB1

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
  mySerial.print(F("[AHT10 ]"));
  mySerial.print(F("Temperature: ")); mySerial.print(myAHT10.readTemperature());
  mySerial.print("\t");
  mySerial.print(F("Humidity: ")); mySerial.println(myAHT10.readHumidity());

  bme.readSensor();
  mySerial.print(F("[BME280]"));
  mySerial.print(F("Temperature: ")); mySerial.print(bme.getTemperature_C());
  mySerial.print("\t");
  mySerial.print(F("Humidity: ")); mySerial.println(bme.getHumidity());

  delay(3000);
}
