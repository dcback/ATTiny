/* https://github.com/MCUdude/MicroCore
  [Attiny 13 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK=SCL
        A2=PB4=4-|      |-1(~)=PB1=RX=MISO
            GND -|      |-0(~)=PB0=TX=MOSI=SDA
                  ------
*/
void setup()
{
  Serial.begin();
}

void loop()
{
  Serial.println("[ATTiny13 pinTest]");
  Serial.print("PB0="); Serial.println(PB0);    // 0
  Serial.print("PB1="); Serial.println(PB1);    // 1
  Serial.print("PB2="); Serial.println(PB2);    // 2
  Serial.print("PB3="); Serial.println(PB3);    // 3
  Serial.print("PB4="); Serial.println(PB4);    // 4
  Serial.print("PB5="); Serial.println(PB5);    // 5
  delay(1000);
}
