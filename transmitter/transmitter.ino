
#include <SoftwareSerial.h>


const byte HC12RxdPin = 4; // "RXD" Pin on HC12
const byte HC12TxdPin = 5; // "TXD" Pin on HC12
const int switch_pin = 7;

SoftwareSerial HC12(HC12TxdPin, HC12RxdPin);

void setup() {
  HC12.begin(9600);
}

void loop() {
  
  if(digitalRead(switch_pin) == HIGH){
    HC12.write(5);
  }
  if(digitalRead(switch_pin) == LOW){
    HC12.write(1);
  }
  delay(50);
}
