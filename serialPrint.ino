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

int intValue = 4095;            // FFF
unsigned int uintValue = 65535; // FFFF
float floatValue = 3.14;
char charName = 'A';
char* strName = "ABC 백동철";
bool ledStatus = LOW;

void setup()
{
  mySerial.begin(9600);
  mySerial.println("[ATtiny85 Serial Print]");
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  mySerial.print("Int : ");
  mySerial.println(intValue);
  mySerial.print("Unsigned int : ");
  mySerial.println(uintValue);
  mySerial.print("Float : ");
  mySerial.println(floatValue);
  mySerial.print("Char : ");
  mySerial.print(charName);
  mySerial.println();
  mySerial.print("String : ");
  mySerial.println(strName);
  mySerial.print("Base conv : 4095->");
  mySerial.println(intValue, HEX);
  mySerial.println("----------------------");

  digitalWrite(ledPin, ledStatus);
  delay(1000);
  ledStatus = !ledStatus;
}
