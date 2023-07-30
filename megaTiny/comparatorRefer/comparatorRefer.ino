#include <Comparator.h>
#define sigOut PIN_PA1

bool var = 0;

void setup() {
  pinMode(sigOut, OUTPUT);  // sets the pin as output

  Serial.begin(115200);  // Initialize the serial communication

  // Configure relevant comparator parameters
  Comparator.input_p = comparator::in_p::in0;   // Use positive input 0(PIN_PA7)
  Comparator.input_n = comparator::in_n::in0;   // Use negative input 0(PIN_PA6)
  Comparator.output = comparator::out::enable;  // Enable output on    (PIN_PA3)

  // Initialize comparator
  Comparator.init();

  // Start comparator
  Comparator.start();
}

void loop() {
  if (millis() % 500 == 0) {
    digitalWrite(sigOut, !digitalRead(sigOut));
    delay(1);
  }
}
