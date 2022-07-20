
#include <SoftwareSerial.h>


const byte HC12RxdPin = A3; // "RXD" Pin on HC12
const byte HC12TxdPin = A2; // "TXD" Pin on HC12
const int RED_LED = 2;
const int GREEN_LED = 3;
const int BLUE_LED = 4;
bool ping;

SoftwareSerial HC12(HC12TxdPin, HC12RxdPin);

void setup() {
    HC12.begin(9600);
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);

    int clean = 0;
    HC12.write(clean);

    ping = true;
}

void loop() {  
  int programTally;
  int previewTally;
  
  if (ping){
      programTally = 0;
      previewTally = 1;
  }
  else{
      programTally = 1;
      previewTally = 0;
  }
  
  ping =  not ping;

  int transmission = programTally;
  transmission = transmission << 3;
  transmission = transmission | previewTally;
  HC12.write(transmission);
  
  digitalWrite(BLUE_LED, HIGH);
  delay(500);
  digitalWrite(BLUE_LED, LOW);
  delay(500);
}
