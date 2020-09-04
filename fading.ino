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
  mySerial.begin(9600);
  mySerial.println("[ATtiny fading up/down]");
}

void loop()
{
  // fade in from min to max in increments of 5 points:
  mySerial.println("fadein =>>>>>>>> 5 up");
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5)
  {
    analogWrite(ledPin, fadeValue);   // sets the value (range from 0 to 255):
    mySerial.print("[");
    mySerial.print(fadeValue);
    mySerial.print("]");
    delay(30);    // wait for 30 milliseconds to see the dimming effect
  }
  mySerial.println();
  delay(1000);

  // fade out from max to min in decrements of 5 points:
  mySerial.println("fadeout =>>>>>>> 5 down");
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5)
  {
    analogWrite(ledPin, fadeValue);   // sets the value (range from 0 to 255):
    mySerial.print("[");
    mySerial.print(fadeValue);
    mySerial.print("]");
    delay(30);    // wait for 30 milliseconds to see the dimming effect
  }
  mySerial.println();
  delay(1000);
}
