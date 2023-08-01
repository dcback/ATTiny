#include <TM1637Display.h>

#define CLK PIN_PA2  // TM1637 CLK Pin
#define DIO PIN_PA3  // TM1637 DIO Pin

TM1637Display display(CLK, DIO);  // FND

void setup() {
  Serial.begin(115200);
  display.setBrightness(0);  // min(0) ~ max(7)
}

void loop() {
  for (int cnt = 0; cnt <= 9999; cnt++) {
    display.showNumberDec(cnt);  // display cnt value
    if (cnt % 100 == 0) Serial.println(cnt);
  }
}