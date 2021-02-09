/* https://github.com/MCUdude/MicroCore
  [Attiny 13 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK=SCL
        A2=PB4=4-|      |-1(~)=PB1=RX=MISO
            GND -|      |-0(~)=PB0=TX=MOSI=SDA
                  ------
*/
#define ledPin      1     // PB1 
#define buttonPin   2     // PB2  

bool buttonState = 0;

void setup()
{
  Serial.begin();
  Serial.println("[ATtiny Button]");

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH)
  {
    digitalWrite(ledPin, HIGH);    // turn LED on:
  }
  else
  {
    digitalWrite(ledPin, LOW);   // turn LED off:
  }
  Serial.print("buttonState[");
  Serial.print(buttonState);
  Serial.println("] ");

  delay(1000);
}
