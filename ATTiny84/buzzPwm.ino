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
#define  buzzPin 7        // the PWM pin the buzzer is attached to
int volume = 0;           // how loud the buzzer is
int fadeAmount = 5;       // how many points to fade the buzzer volume by

int duty_cycle = 127;         // 0-255 so 50% = 127 approx

void setup()
{
  pinMode(buzzPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop()
{
  analogWrite(buzzPin, volume);

  // change the volume for next time through the loop:
  volume = volume + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (volume <= 0 || volume >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 1~100 milliseconds to see the volume effect
  delay(100);
}
