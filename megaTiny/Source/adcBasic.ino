// ATtinyx12 ADC Pin : PA0=A0 ~ PA7=A7

#define analogPin A1

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned int adcValue = analogRead(analogPin);

  Serial.print("adcValue: ");
  Serial.print(adcValue);
  Serial.print("\tanaValue: ");
  Serial.print(adcValue / 1023.0 * 4.66);
  Serial.println(" V");

  delay(100);
}