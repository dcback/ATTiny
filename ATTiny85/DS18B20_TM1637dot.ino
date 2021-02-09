/* https://www.arduinoslovakia.eu/blog/2019/1/attiny85---teplomer-s-ds18b20?lang=en
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
#include <TM1637Display.h>

#define CLK   0
#define DIO   1
#define ONE_WIRE_BUS 3

TM1637Display display(CLK, DIO);

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  display.setBrightness(0x07);
  sensors.begin();
}
void loop(void)
{
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);
  display.showNumberDecEx(temp * 100, 0b01000000, false);

  delay(1000);
}
