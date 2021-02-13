/* https://github.com/MCUdude/MicroCore
  [Attiny 13 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK
        A2=PB4=4-|      |-1(~)=PB1=RX=MISO
            GND -|      |-0(~)=PB0=TX=MOSI
                  ------
*/
int thisByte = 33;

void setup()
{
  Serial.begin();
  Serial.println("ASCII Table");  // prints title with ending line break
}

void loop()
{
  Serial.write(thisByte);

  Serial.print(", dec: ");
  Serial.print(thisByte, DEC);  // prints value as string in decimal (base 10):
  Serial.print(" ");
  Serial.print(thisByte);

  Serial.print(", hex: ");
  Serial.print(thisByte, HEX);  // prints value as string in hexadecimal (base 16):

  Serial.print(", oct: ");
  Serial.print(thisByte, OCT);  // prints value as string in octal (base 8);

  Serial.print(", bin: ");
  Serial.println(thisByte, BIN);// prints value as string in binary (base 2) also prints ending line break:

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
