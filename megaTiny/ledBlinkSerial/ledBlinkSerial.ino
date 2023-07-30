// https://github.com/SpenceKonde/megaTinyCore/blob/master/megaavr/extras/ATtiny_x12.md

#define ledPin PIN_PA3
bool state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(ledPin, state);
  delay(500);
  state = !state;

  Serial.print("ledPin No = ");
  Serial.print(ledPin);
  Serial.print(", Status = ");
  Serial.println(digitalRead(ledPin));
//  Serial.printf("ledPin No = %d, Status = %d\n", PIN_PA3, digitalRead(ledPin));
}