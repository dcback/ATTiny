// https://github.com/SpenceKonde/megaTinyCore/blob/master/megaavr/extras/Ref_Analog.md

void setup() {
  Serial.begin(115200);
}

void loop() {
  analogReference(INTERNAL0V55);
  Serial.print("0V55 : ");
  Serial.println(getAnalogReference());

  analogReference(INTERNAL1V1);
  Serial.print("1V1 : ");
  Serial.println(getAnalogReference());

  analogReference(INTERNAL1V5);
  Serial.print("1V5 : ");
  Serial.println(getAnalogReference());

  analogReference(INTERNAL2V5);
  Serial.print("2V5 : ");
  Serial.println(getAnalogReference());

  analogReference(INTERNAL4V3);
  Serial.print("4V3 : ");
  Serial.println(getAnalogReference());

  analogReference(VDD);
  Serial.print("VDD : ");
  Serial.println(getAnalogReference());

  delay(1000);
}
