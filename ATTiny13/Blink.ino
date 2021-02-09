/* https://github.com/MCUdude/MicroCore
  [Attiny 13 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK=SCL
        A2=PB4=4-|      |-1(~)=PB1=RX=MISO
            GND -|      |-0(~)=PB0=TX=MOSI=SDA
                  ------
*/
#define ledPin    1   // PB1

bool  ledStatus = 0;

void setup()
{
  Serial.begin();     // Default 115200
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  Serial.println("LED On/Off in 1 sec.");
  digitalWrite(ledPin, ledStatus);
  delay(1000);
  ledStatus = !ledStatus;
}
