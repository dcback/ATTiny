/* https://github.com/MCUdude/MicroCore
  [Attiny 13 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK
        A2=PB4=4-|      |-1(~)=PB1=RX=MISO
            GND -|      |-0(~)=PB0=TX=MOSI
                  ------
*/
#define analogreadPin   A1    // 2=PB2=A1=SCK, Analog input pin must use pinName A1
#define analogWritePin  1     // 1 Analog Write pin that the LED is attached to

void setup()
{
  Serial.begin();             // Default 115200
  Serial.println("[ATtiny13 analog R&W]");
}

void loop()
{
  unsigned int sensorValue = analogRead(analogreadPin);       // read the analog in value
  unsigned int pwmValue = map(sensorValue, 0, 1023, 0, 255);  // analogRead(0~1023), analogWrite(0~255)
  analogWrite(analogWritePin, pwmValue);                      // change the analog out value:

  Serial.print("sensor = [");
  Serial.print(sensorValue);
  Serial.print("]\t PWM = [");
  Serial.print(pwmValue);
  Serial.println("]");

  delay(1000);
}
