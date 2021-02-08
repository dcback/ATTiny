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
#include <AHT10.h>
#include <Wire.h>
#include <TM1637Display.h>

// FND Module connection pins (Digital Pins)
#define CLK 3
#define DIO 4

// The amount of time (in milliseconds) between tests
#define DELAY   3000

TM1637Display display(CLK, DIO);
AHT10 myAHT10(AHT10_ADDRESS_0X38);


void setup()
{
  display.clear();

  myAHT10.begin() ;
}

void loop()
{
  display.setBrightness(7);   // 0~7, 7(maxBright)
  float Temp = myAHT10.readTemperature() * 100.0;
  display.showNumberDecEx(Temp, 0b01000000, false, 4, 0);
  delay(DELAY);

  display.setBrightness(1);   // 0~7, 7(maxBright)
  float Humi = myAHT10.readHumidity() * 100.0;
  display.showNumberDecEx(Humi, 0b01000000, false, 4, 0);
  delay(DELAY);
}
