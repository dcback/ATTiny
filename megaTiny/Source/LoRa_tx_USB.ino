// MOSI=PA1, MISO=PA2, SCK=PA3, NSS=PA6, NRST=PA0, IRQ=PA7  

#include <SPI.h>
#include <LoRa.h>

#define csPin PIN_PA6
#define resetPin PIN_PA0
#define irqPin PIN_PA7

int counter = 0;

void setup() {
  LoRa.setPins(csPin, resetPin, irqPin);  // CS, RST, IRQ Pin Set
  LoRa.begin(915E6);
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
