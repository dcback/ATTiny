/*
  [Attiny 44/84 Pinout]
                        ------
                   VCC-|      |-GND
                PB0=10-|      |-0=PA0=A0
                 PB1=9-|      |-1=PA1=A1
             RESET=PB3-|      |-2=PA2=A2
              PB2=8(~)-|      |-3=PA3=A3
           A7=PA7=7(~)-|      |-4=PA4=A4=SCK=SCL
  SDA=MOSI=A6=PA6=6(~)-|      |-5(~)=PA5=A5=MISO
                        ------
*/
#include <SoftwareSerial.h>

#define txPin       0     // PB0
#define rxPin       1     // PB1

SoftwareSerial mySerial(rxPin, txPin);

int ledPin  =   5;
int PIR     =   7;

void setup() {
  pinMode(ledPin, OUTPUT);   // initalize LED as an output
  pinMode(PIR, INPUT);    // initialize sensor as an input
  mySerial.begin(9600);     // initialize serial
}

void loop() {
  if (digitalRead(PIR) == HIGH) { // check if the sensor is HIGH
    digitalWrite(ledPin, HIGH);      // turn LED ON
    mySerial.println("Motion detected!");
    delay(100);                   // delay 100 milliseconds
  }
  else {
    digitalWrite(ledPin, LOW);       // turn LED OFF
    mySerial.println("Motion stopped!");
    delay(100);                   // delay 100 milliseconds
  }
}
