/*
 Sample code for the BH1750 Light sensor
  
 Connection:
 VCC-5v
 GND-GND
 SCL-SCL(PA2)
 SDA-SDA(PA1)
 ADD-NC
 */
#include <Wire.h>  //BH1750 IIC Mode
#include <math.h>
int BH1750address = 0x23;  //setting i2c address

byte buff[2];
void setup() {
  Wire.begin();
  Serial.begin(115200);  //init Serial rate
}

void loop() {
  uint16_t val = 0;
  BH1750_Init(BH1750address);
  delay(200);

  if (2 == BH1750_Read(BH1750address)) {
    val = ((buff[0] << 8) | buff[1]) / 1.2;
    Serial.print(val, DEC);
    Serial.println("[lx]");
  }
  delay(150);
}

int BH1750_Read(int address)  //
{
  int i = 0;
  Wire.beginTransmission(address);
  Wire.requestFrom(address, 2);
  while (Wire.available())  //
  {
    buff[i] = Wire.read();  // receive one byte
    i++;
  }
  Wire.endTransmission();
  return i;
}

void BH1750_Init(int address) {
  Wire.beginTransmission(address);
  Wire.write(0x10);  //1lx reolution 120ms
  Wire.endTransmission();
}