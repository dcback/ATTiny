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
#define ledPin          1     // PB1 Analog Write pin that the LED is attached to

SoftwareSerial mySerial(rxPin, txPin);

void setup()
{
  mySerial.begin(9600);     
  pinMode(ledPin, OUTPUT);
  mySerial.println("PWM LED Control");
}

void loop()
{
  for (int pwmValue = 0; pwmValue <= 255; pwmValue++)
  {
    analogWrite(ledPin, pwmValue);
    mySerial.print(pwmValue); mySerial.print(" ");
    delay(10);
  }
  mySerial.println();
}
