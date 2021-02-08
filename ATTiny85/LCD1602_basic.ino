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
#include <TinyWireM.h>
#include <LiquidCrystal_attiny.h>

#define GPIO_ADDR     0x3F                // 0x20 0x27 0x3F 
LiquidCrystal_I2C lcd(GPIO_ADDR, 16, 2);  // set address & 16 chars / 2 lines

void setup()
{
  lcd.init();         // initialize the lcd
  lcd.backlight();    // Backlight on
}

void loop()
{
  lcd.print("ABCDEFGHIJKLMNOP");  // ABCDEFGHIJKLMNOP Print
  lcd.setCursor(0, 1);            // LCD x=0, y=1 point cursor
  lcd.print("QRSTUVWXYZ012345");  // QRSTUVWXYZ012345 Print
  lcd.noDisplay();                // LCD Off
  delay(500);
  lcd.display();                  // LCD On
  delay(500);
}
