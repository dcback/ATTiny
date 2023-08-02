// SCK=PA3, MISO=PA2, MOSI=PA1, NSS=PA6, IRQ=PA7, RST=PA0

#include <SPI.h>
#include <LoRa.h>

#define csPin PIN_PA6
#define resetPin PIN_PA0
#define irqPin PIN_PA7

int counter = 0;

void setup() {
  pinMode(irqPin, OUTPUT);
  LoRa.setPins(csPin, resetPin, irqPin);  // CS, RST, IRQ Pin Set
  LoRa.begin(915E6);
}

void loop() {
  if (millis() % 2000 == 0) {
    // send packet
    LoRa.beginPacket();
    LoRa.print("hello ");
    LoRa.print(counter);
    LoRa.endPacket();
    counter++;
    digitalWrite(irqPin, !digitalRead(irqPin));
  }
}