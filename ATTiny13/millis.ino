/* https://github.com/MCUdude/MicroCore
  [Attiny 13 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK
        A2=PB4=4-|      |-1(~)=PB1=RX=MISO
            GND -|      |-0(~)=PB0=TX=MOSI
                  ------
*/
#define ledPin      1     // PB1

bool ledState = LOW;
unsigned long previousMillis = 0;   // will store last time LED was updated
const long interval = 1000;         // interval at which to blink (milliseconds)

void setup()
{
  Serial.begin();
  Serial.println("[ATtiny13 millis]");
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;   // save the last time at blinked the LED
    digitalWrite(ledPin, ledState);   // set the LED with the ledState of the variable:
    Serial.print(currentMillis / 1000);
    Serial.print("초 : ");
    Serial.println(ledState);
    ledState = !ledState;
  }
}
