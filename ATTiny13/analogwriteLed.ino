/* https://github.com/MCUdude/MicroCore
  [Attiny 13 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK=SCL
        A2=PB4=4-|      |-1(~)=PB1=RX=MISO
            GND -|      |-0(~)=PB0=TX=MOSI=SDA
                  ------
*/
#define ledPin    1   // PB1

void setup()
{
  Serial.begin();     // Default 115200
  pinMode(ledPin, OUTPUT);
  Serial.println("PWM LED Control");
}

void loop()
{
  for (int pwmValue = 0; pwmValue <= 255; pwmValue++)
  {
    analogWrite(ledPin, pwmValue);
    Serial.print(pwmValue); Serial.print(" ");
    delay(50);
  }
  Serial.println();
}
