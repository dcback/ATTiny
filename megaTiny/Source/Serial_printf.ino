// Serial.printf Function
unsigned int ch = 65;

void setup() {
  Serial.begin(115200);

  Serial.println("Serial.printf vs Serial.print");
}

void loop() {
  Serial.printf("Run time = %ld, ASCII value = %d, character = %c\n", millis(), ch, ch);
  serialPrint();
  ch++;
  if (ch > 90) ch = 65;

  delay(1000);
}

void serialPrint() {
  Serial.print("Run time = "); Serial.print(millis()); Serial.print(", ");
  Serial.print("ASCII value = "); Serial.print(ch); Serial.print(", ");
  Serial.print("character = "); Serial.write(ch); Serial.println("");
}