// ATtiny Pinout : PIN_PA6=0, PIN_PA7=1, PIN_PA1=2, PIN_PA2=3, PIN_PA3=4, PIN_PA0=5

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (millis() % 1000 == 0)
    Serial.printf("PIN_PA6=%d, PIN_PA7=%d, PIN_PA1=%d, PIN_PA2=%d, PIN_PA3=%d, PIN_PA0=%d\n",
                  PIN_PA6, PIN_PA7, PIN_PA1, PIN_PA2, PIN_PA3, PIN_PA0);
}