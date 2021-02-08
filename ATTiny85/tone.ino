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

#define rxPin       4     // PB4
#define txPin       3     // PB3
#define Speaker     1     // PB1

SoftwareSerial mySerial(rxPin, txPin);

// Notes
const int Note_C  = 239;
const int Note_CS = 225;
const int Note_D  = 213;
const int Note_DS = 201;
const int Note_E  = 190;
const int Note_F  = 179;
const int Note_FS = 169;
const int Note_G  = 159;
const int Note_GS = 150;
const int Note_A  = 142;
const int Note_AS = 134;
const int Note_B  = 127;

int durationValue = 500;
int i = 6;

void setup()
{
  mySerial.begin(9600);
  mySerial.println("[ATtiny Tone]");
  pinMode(Speaker, OUTPUT);
}

void loop()
{
  playTune();
  delay(1000);
}

void TinyTone(unsigned char divisor, unsigned char octave, unsigned long duration)
{
  TCCR1 = 0x90 | (8 - octave);    // for 1MHz clock
  // TCCR1 = 0x90 | (11-octave);  // for 8MHz clock
  OCR1C = divisor - 1;            // set the OCR
  delay(duration);
  TCCR1 = 0x90;                   // stop the counter
}

// Play a scale
void playTune(void)
{
  mySerial.print("도 "); TinyTone(Note_C, i, durationValue);
  mySerial.print("레 "); TinyTone(Note_D, i, durationValue);
  mySerial.print("미 "); TinyTone(Note_E, i, durationValue);
  mySerial.print("파 ");  TinyTone(Note_F, i, durationValue);
  mySerial.print("솔 "); TinyTone(Note_G, i, durationValue);
  mySerial.print("라 "); TinyTone(Note_A, i, durationValue);
  mySerial.print("시 "); TinyTone(Note_B, i, durationValue);
  mySerial.println("도"); TinyTone(Note_C, i + 1, durationValue);
}
