/* https://github.com/MCUdude/MicroCore
  [Attiny 13 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK
        A2=PB4=4-|      |-1(~)=PB1=RX=MISO
            GND -|      |-0(~)=PB0=TX=MOSI
                  ------
               
  https://github.com/MCUdude/MicroCore/tree/master/avr/libraries/EEPROM
  AVR processors EEPROM sizes :
  - Attiny13    : 64b EEPROM storage.
  - Attiny25~85 : 128~512b EEPROM storage.
  - Atmega 328P : 1kb EEPROM storage.
  - Atmega 2560 : 4kb EEPROM storage.
*/
#include <EEPROM.h>

unsigned int address = 0;
byte value;

void setup() {
  Serial.begin();
}

void loop() {

  for (address = 0; address < EEPROM.length(); address++)
  {
    unsigned int val = random(EEPROM.length());
    EEPROM.write(address, val);
  }

  for (address = 0; address < EEPROM.length(); address++)
  {
    value = EEPROM.read(address);

    Serial.print(address);
    Serial.print("\t");
    Serial.print(value, DEC);
    Serial.println();
    delay(100);
  }
}
