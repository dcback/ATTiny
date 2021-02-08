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

SoftwareSerial mySerial(rxPin, txPin);

int thisByte = 33;

void setup()
{
  mySerial.begin(9600);
  mySerial.println("ASCII Table");  // prints title with ending line break
}

void loop()
{
  mySerial.write(thisByte);

  mySerial.print(", dec: ");
  mySerial.print(thisByte, DEC);  // prints value as string in decimal (base 10):
  mySerial.print(" ");
  mySerial.print(thisByte);

  mySerial.print(", hex: ");
  mySerial.print(thisByte, HEX);  // prints value as string in hexadecimal (base 16):

  mySerial.print(", oct: ");
  mySerial.print(thisByte, OCT);  // prints value as string in octal (base 8);

  mySerial.print(", bin: ");
  mySerial.println(thisByte, BIN);// prints value as string in binary (base 2) also prints ending line break:

  // if printed last visible character '~' or 126, stop:
  if (thisByte == 126)  // you could also use if (thisByte == '~')
  {
    // This loop loops forever and does nothing
    while (true) {
      continue;
    }
  }
  thisByte++;   // go on to the next character
}
