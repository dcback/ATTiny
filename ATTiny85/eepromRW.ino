/*
  [Attiny 25/45/85 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK=SCL
        A2=PB4=4-|      |-1(~)=PB1=MISO
             GND-|      |-0(~)=PB0=MOSI=SDA
                  ------
  https://github.com/MCUdude/MicroCore/tree/master/avr/libraries/EEPROM
  AVR processors EEPROM sizes :
  - Attiny13    : 64b EEPROM storage.
  - Attiny25~85 : 128~512b EEPROM storage.
  - Atmega 328P : 1kb EEPROM storage.
  - Atmega 2560 : 4kb EEPROM storage.
*/
#include <EEPROM.h>
#include <SoftwareSerial.h>

#define txPin           0     // PB0
#define rxPin           1     // PB1

SoftwareSerial mySerial(rxPin, txPin);

unsigned int address = 0;
byte value;

void setup() {
  mySerial.begin(9600);
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

    mySerial.print(address);
    mySerial.print("\t");
    mySerial.print(value, DEC);
    mySerial.println();
  }
}
