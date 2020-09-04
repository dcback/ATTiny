/* http://homemadehardware.com/img/attiny85_pinout.jpeg
  [Attiny 25/45/85 Pinout]
                  ------
  5=PB5=A0=RESET-|      |-VCC
        3=PB3=A3-|      |-2=PB2=A1=SCK
        4=PB4=A2-|      |-1=PB1=MISO
            GND -|      |-0=PB0=MOSI
                  ------
*/
#include <SoftwareSerial.h>

#define rxPin       4     // PB4
#define txPin       3     // PB3
#define ledPin      1     // PB1

SoftwareSerial mySerial(rxPin, txPin);

void setup()
{
  pinMode(ledPin, OUTPUT);
  mySerial.begin(9600);
  mySerial.println("[ATtiny85 Pin Test]");
}

void loop()
{
  mySerial.print("PB0 = "); mySerial.println(PB0);    // 0
  mySerial.print("PB1 = "); mySerial.println(PB1);    // 1
  mySerial.print("PB2 = "); mySerial.println(PB2);    // 2
  mySerial.print("PB3 = "); mySerial.println(PB3);    // 3
  mySerial.print("PB4 = "); mySerial.println(PB4);    // 4
  mySerial.print("PB5 = "); mySerial.println(PB5);    // 5
  delay(1000);

  mySerial.print(PB0); mySerial.print(PB1); mySerial.print(PB2); mySerial.print(PB3); mySerial.print(PB4); mySerial.println(PB5);
  delay(1000);
  mySerial.println("-------");
}
