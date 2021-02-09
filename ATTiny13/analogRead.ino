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
  Serial.begin();     // Default 115200
}

void loop()
{
  unsigned int A0_value = analogRead(A0);
  unsigned int A1_value = analogRead(A1);
  unsigned int A2_value = analogRead(A2);
  unsigned int A3_value = analogRead(A3);
  Serial.print("A0_Value["); Serial.print(A0_value); Serial.print("] ");
  Serial.print("A1_Value["); Serial.print(A1_value); Serial.print("] ");
  Serial.print("A2_Value["); Serial.print(A2_value); Serial.print("] ");
  Serial.print("A3_Value["); Serial.print(A3_value); Serial.println("]");
  delay(1000);
}
