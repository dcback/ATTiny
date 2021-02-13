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
#include <IRremote.h>
#include <SoftwareSerial.h>

#define txPin       0     // PB0
#define rxPin       1     // PB1

SoftwareSerial mySerial(rxPin, txPin);

int irPin = 8;
IRrecv irrecv(irPin);
decode_results results;

void setup()
{
  mySerial.begin(9600);
  irrecv.enableIRIn();  // 리모콘 시작
}

void loop()
{
  if (irrecv.decode(&results))              // 리모콘 누른값이 없다면 패스
  {
    mySerial.print("results.decode_type : "); // 리모콘 타입
    mySerial.println(results.decode_type);

    mySerial.print("results.bits : ");        // 키값 길이
    mySerial.println(results.bits);

    mySerial.print("results.value : ");       // 키값
    mySerial.println(results.value);

    mySerial.print("results.value, HEX : ");  // 키값을 16진수로변환
    mySerial.println(results.value, HEX);

    irrecv.resume(); // 다음 값
  }
}
