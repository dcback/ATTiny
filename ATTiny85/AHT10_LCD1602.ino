/*  https://github.com/platisd/ATtiny85-LCD-library
    https://kocoafab.cc/tutorial/view/727
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
#include <TinyWireM.h>
#include <LiquidCrystal_attiny.h>

#define GPIO_ADDR     0x3F                // 0x20 0x27 0x3F 
LiquidCrystal_I2C lcd(GPIO_ADDR, 16, 2);  // set address & 16 chars / 2 lines

AHT10 myAHT10(AHT10_ADDRESS_0X38);

void setup()
{
  lcd.init();         // initialize the lcd
  lcd.backlight();    // Backlight on

  myAHT10.begin() ;
}

void loop()
{
  float Temp = myAHT10.readTemperature();
  float Humi = myAHT10.readHumidity();

  lcd.setCursor(0, 0);
  lcd.print("Temperat: ");
  lcd.print(Temp);
  lcd.setCursor(0, 1);
  lcd.print("Huminity: ");
  lcd.print(Humi);
  delay(3000);
}
