/* https://github.com/MCUdude/MicroCore
  [Attiny 13 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK
        A2=PB4=4-|      |-1(~)=PB1=RX=MISO
            GND -|      |-0(~)=PB0=TX=MOSI
                  ------
*/
void setup()
{
  Serial.begin();     // Default 115200
}

void loop()
{
  unsigned int D0 = digitalRead(0);
  unsigned int D1 = digitalRead(1);
  unsigned int D2 = digitalRead(2);
  unsigned int D3 = digitalRead(3);
  unsigned int D4 = digitalRead(4);
  unsigned int D5 = digitalRead(5);

  Serial.print("D0["); Serial.print(D0); Serial.print("] ");
  Serial.print("D1["); Serial.print(D1); Serial.print("] ");
  Serial.print("D2["); Serial.print(D2); Serial.print("] ");
  Serial.print("D3["); Serial.print(D3); Serial.print("] ");
  Serial.print("D4["); Serial.print(D4); Serial.print("] ");
  Serial.print("D5["); Serial.print(D5); Serial.println("]");
  delay(1000);
}
