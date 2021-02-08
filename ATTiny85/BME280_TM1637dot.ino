/*  https://github.com/avishorp/TM1637
    https://robojax.com/learn/arduino/robojax-TM1637_display_manual.pdf
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
#include <TM1637Display.h>

// FND Module connection pins (Digital Pins)
#define CLK 3
#define DIO 4

#define DELAY   3000

TM1637Display display(CLK, DIO);
BME280_I2C bme(0x76);                     // I2C using address 0x76

void setup()
{
  bme.begin();
  bme.setTempCal(-1.0);
}

void loop()
{
  bme.readSensor();

  display.setBrightness(7);   // 0~7, 7(maxBright)
  float Temp = bme.getTemperature_C() * 100.0;
  display.showNumberDecEx(Temp, 0b01000000, false, 4, 0);
  delay(DELAY);

  display.setBrightness(1);   // 0~7, 7(maxBright)
  float Humi = bme.getHumidity() * 100.0;
  display.showNumberDecEx(Humi, 0b01000000, false, 4, 0);
  delay(DELAY);
}
