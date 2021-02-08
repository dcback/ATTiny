/*
  [Attiny 25/45/85 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK=SCL
        A2=PB4=4-|      |-1(~)=PB1=MISO
             GND-|      |-0(~)=PB0=MOSI=SDA
                  ------
*/
#include <AHT10.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#define txPin       3     // PB3
#define rxPin       4     // PB4

uint8_t readStatus = 0;

SoftwareSerial mySerial(rxPin, txPin);
AHT10 myAHT10(AHT10_ADDRESS_0X38);

void setup()
{
  mySerial.begin(9600);
  mySerial.println();

  while (myAHT10.begin() != true)
  {
    mySerial.println(F("AHT10 not connected or fail to load calibration coefficient")); //(F()) save string to flash & keeps dynamic memory free
    delay(5000);
  }
  mySerial.println(F("AHT10 OK"));

  //Wire.setClock(400000); //experimental I2C speed! 400KHz, default 100KHz
}

void loop()
{
  /* DEMO - 1, every temperature or humidity call will read 6 bytes over I2C, total 12 bytes */
  mySerial.println(F("DEMO 1: read 12-bytes, show 255 if communication error is occurred"));
  mySerial.print(F("Temperature: ")); mySerial.print(myAHT10.readTemperature()); mySerial.println(F(" +-0.3C")); //by default "AHT10_FORCE_READ_DATA"
  mySerial.print(F("Humidity...: ")); mySerial.print(myAHT10.readHumidity());    mySerial.println(F(" +-2%"));   //by default "AHT10_FORCE_READ_DATA"

  /* DEMO - 2, temperature call will read 6 bytes via I2C, humidity will use same 6 bytes */
  mySerial.println(F("DEMO 2: read 6 byte, show 255 if communication error is occurred"));
  mySerial.print(F("Temperature: ")); mySerial.print(myAHT10.readTemperature(AHT10_FORCE_READ_DATA)); mySerial.println(F(" +-0.3C"));
  mySerial.print(F("Humidity...: ")); mySerial.print(myAHT10.readHumidity(AHT10_USE_READ_DATA));      mySerial.println(F(" +-2%"));

  /* DEMO - 3, same as demo2 but different call procedure */
  mySerial.println(F("DEMO 3: read 6-bytes, show 255 if communication error is occurred"));

  readStatus = myAHT10.readRawData(); //read 6 bytes from AHT10 over I2C

  if (readStatus != AHT10_ERROR)
  {
    mySerial.print(F("Temperature: ")); mySerial.print(myAHT10.readTemperature(AHT10_USE_READ_DATA)); mySerial.println(F(" +-0.3C"));
    mySerial.print(F("Humidity...: ")); mySerial.print(myAHT10.readHumidity(AHT10_USE_READ_DATA));    mySerial.println(F(" +-2%"));
  }
  else
  {
    mySerial.print(F("Failed to read - reset: "));
    mySerial.println(myAHT10.softReset());         //reset 1-success, 0-failed
  }

  delay(10000); //recomended polling frequency 8sec..30sec
}
