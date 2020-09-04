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

#define rxPin         PB4   // 4
#define txPin         PB3   // 3

SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  mySerial.begin(9600);
  while (!mySerial)
  {
    ;     // wait for serial port to connect. Needed for native USB port only
  }
  mySerial.println("[ASCII Table ~ Character Map]");  // prints title with ending line break
}

int thisByte = 33;    // = !

void loop() {

  mySerial.write(thisByte);

  mySerial.print(", dec: ");
  mySerial.print(thisByte, DEC); // prints value as string in decimal (base 10):
  mySerial.print(" ");
  mySerial.print(thisByte);

  mySerial.print(", hex: ");
  mySerial.print(thisByte, HEX); // prints value as string in hexadecimal (base 16):

  mySerial.print(", oct: ");
  mySerial.print(thisByte, OCT); // prints value as string in octal (base 8);

  mySerial.print(", bin: ");
  mySerial.println(thisByte, BIN); // prints value as string in binary (base 2) also prints ending line break:

  // if printed last visible character '~' or 126, stop:
  if (thisByte == 126)  // you could also use if (thisByte == '~') {
  {
    // This loop loops forever and does nothing
    while (true)
    {
      continue;
    }
  }
  thisByte++;   // go on to the next character
}
