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
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 3
#define DIO 4

#define readV0  A0
#define readV1  A1
#define readV2  A2
#define readV3  A3

// The amount of time (in milliseconds) between tests
#define DELAY   3000

TM1637Display display(CLK, DIO);

unsigned int V0 = 0;
unsigned int V1 = 0;
unsigned int V2 = 0;
unsigned int V3 = 0;

void setup()
{
  display.setBrightness(7); // 0~7, 7(maxBright)
  display.clear();

  pinMode(readV0, INPUT);
  pinMode(readV1, INPUT);
  pinMode(readV2, INPUT);
  pinMode(readV3, INPUT);
}

void loop()
{
  V1 = analogRead(readV1);
  float V1cal = V1 * (5.0 / 1023.0) * 100.0;
  display.showNumberDecEx(V1cal, 0b01000000, false, 4, 0);
  delay(DELAY);

  V2 = analogRead(readV2);
  float V2cal = V2 * (5.0 / 1023.0) * 100.0;
  display.showNumberDecEx(V2cal, 0b01000000, false, 4, 0);
  delay(DELAY);

  V3 = analogRead(readV3);
  float V3cal = V3 * (5.0 / 1023.0) * 100.0;
  display.showNumberDecEx(V3cal, 0b01000000, false, 4, 0);
  delay(DELAY);

  V0 = analogRead(readV0);
  float V0cal = V0 * (5.0 / 1023.0) * 100.0;
  display.showNumberDecEx(V0cal, 0b01000000, false, 4, 0);
  delay(DELAY);
}
