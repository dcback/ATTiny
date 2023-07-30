// https://projecthub.arduino.cc/boaz/duty-cycle-calculator-and-frequency-meter-ebc4d9
// pwmPort@ATtinyx12 : 1, 2, 3, 4
// maxFreq@Measure = 100kHz

#define pwmGen 2    // 980Hz pulse generator arduino itself, PIN_PA1
#define signalIn 3  // signal input pin, PIN_PA2
#define ledPin 4    // signal input pin, PIN_PA3

unsigned long startTime;
float onTime, offTime;  // onTime & offTime variable got microsecond
float period;           // tota l time to one cycle onTime + offTime
float freq;             // freq = 1/period
float duty;             // duty = (TON/(TON+TOFF))*100 %

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  pinMode(pwmGen, OUTPUT);
  pinMode(signalIn, INPUT);
  analogWrite(pwmGen, 127);  //sample pulse 980Hz, 127/255 -> 50%
}

void loop() {
  startTime = micros();
  onTime = pulseIn(signalIn, HIGH);
  offTime = pulseIn(signalIn, LOW);
  period = onTime + offTime;
  duty = (onTime / period) * 100;
  freq = 1000000.0 / period;  // 1000000= microsecond 10^-6 goes to upper

  Serial.print("Frequency  = ");
  Serial.print(freq, 0);
  Serial.print(" Hz");
  Serial.print("\t");

  Serial.print("Duty = ");
  Serial.print(duty, 0);
  Serial.print("  %");
  Serial.println("\t");

  digitalWrite(ledPin, !digitalRead(ledPin));
  delay(1000);
}
