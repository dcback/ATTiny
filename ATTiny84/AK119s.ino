/*
  https://github.com/sui77/rc-switch/
  https://github.com/sui77/rc-switch/blob/master/examples/ReceiveDemo_Simple/ReceiveDemo_Simple.ino
/*
  [Attiny 44/84 Pinout]
                        ------
                   VCC-|      |-GND
                PB0=10-|      |-0=PA0=A0
                 PB1=9-|      |-1=PA1=A1
             RESET=PB3-|      |-2=PA2=A2
              PB2=8(~)-|      |-3=PA3=A3
           A7=PA7=7(~)-|      |-4=PA4=A4=SCK=SCL
  SDA=MOSI=A6=PA6=6(~)-|      |-5(~)=PA5=A5=MISO
                        ------
*/
#include <RCSwitch.h>
#include <SoftwareSerial.h>

#define txPin       0     // PB0
#define rxPin       1     // PB1

SoftwareSerial mySerial(rxPin, txPin);

RCSwitch mySwitch = RCSwitch();
unsigned int Value ;

void setup() {
  mySerial.begin(9600);       // Max speed : 9600
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => NANO@2, STM32@PA0 
}

void loop() {
  if (mySwitch.available()) {

    Value = mySwitch.getReceivedValue();

    mySerial.print("Received ");
    mySerial.print( mySwitch.getReceivedValue() ); 
    mySerial.print(":");
    mySerial.print( Value );
    mySerial.print(" / ");
    mySerial.print( mySwitch.getReceivedBitlength() );
    mySerial.print("bit ");
    mySerial.print("Protocol: ");
    mySerial.println( mySwitch.getReceivedProtocol() );

    mySwitch.resetAvailable();
  }
}
