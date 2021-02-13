/*  https://github.com/platisd/ATtiny85-LCD-library
    https://kocoafab.cc/tutorial/view/727
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
