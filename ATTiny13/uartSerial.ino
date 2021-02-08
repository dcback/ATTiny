/* https://github.com/MCUdude/MicroCore
  [Attiny 13 Pinout]
                  ------
  5=PB5=A0=RESET-|      |-VCC
        3=PB3=A3-|      |-2=PB2=A1=SCK
        4=PB4=A2-|      |-1=PB1=RX=MISO
            GND -|      |-0=PB0=TX=MOSI
                  ------
*/
void setup()
{
  Serial.begin();     // Default 115200
}

void loop()
{
  Serial.println("ATTiny13 Serial Print");
  delay(1000);
}
