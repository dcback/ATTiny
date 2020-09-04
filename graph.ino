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

SoftwareSerial mySerial(rxPin, txPin);

void setup() 
{
  mySerial.begin(9600);
  mySerial.println("[ATtiny Graph]");
}

void loop() 
{
  // send the value of analog input :
  mySerial.println(analogRead(A1));
  // wait a bit for the analog-to-digital converter to stabilize after the last
  // reading:
  delay(2);
}
