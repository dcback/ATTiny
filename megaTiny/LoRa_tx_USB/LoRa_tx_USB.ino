#include <SPI.h>
#include <LoRa.h>

#define csPin PIN_PA6
#define resetPin PIN_PA0
#define irqPin PIN_PA7

int counter = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial)
    ;

  LoRa.setPins(csPin, resetPin, irqPin);  // CS, RST, IRQ Pin Set

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }
}

void loop() {
  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(3000);
}