/*
  [Attiny 25/45/85 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK=SCL
        A2=PB4=4-|      |-1(~)=PB1=MISO
             GND-|      |-0(~)=PB0=MOSI=SDA
                  ------
*/
#include <SoftwareSerial.h>

#define txPin           0     // PB0
#define rxPin           1     // PB1
#define analogreadPin   A1    // 2=PB2=A1=SCK, Analog input pin must use pinName A1
#define analogWritePin  1     // 1 Analog Write pin that the LED is attached to

SoftwareSerial mySerial(rxPin, txPin);

void setup()
{
  mySerial.begin(9600);            
  mySerial.println("[ATtiny13 analog R&W]");
}

void loop()
{
  unsigned int sensorValue = analogRead(analogreadPin);       // read the analog in value
  unsigned int pwmValue = map(sensorValue, 0, 1023, 0, 255);  // analogRead(0~1023), analogWrite(0~255)
  analogWrite(analogWritePin, pwmValue);                      // change the analog out value:

  mySerial.print("sensor = [");
  mySerial.print(sensorValue);
  mySerial.print("]\t PWM = [");
  mySerial.print(pwmValue);
  mySerial.println("]");

  delay(1000);
}
