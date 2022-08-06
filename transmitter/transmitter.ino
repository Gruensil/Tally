
#include <SoftwareSerial.h>


const byte HC12RxdPin = A3; // "RXD" Pin on HC12
const byte HC12TxdPin = A2; // "TXD" Pin on HC12
const int RED_LED = 2;
const int GREEN_LED = 3;
const int BLUE_LED = 4;

int x;

SoftwareSerial HC12(HC12TxdPin, HC12RxdPin);

void setup() {
    HC12.begin(9600);
    Serial.begin(9600);
    Serial.setTimeout(1);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    digitalWrite(BLUE_LED, HIGH);

    delay(100);
}

void loop() {

  // int transmission = programTally;
  // transmission = transmission << 3;
  // transmission = transmission | previewTally;

  //while (!Serial.available());
  x = Serial.readString().toInt();
  HC12.write(4);  
  Serial.print(4);
  digitalWrite(GREEN_LED, HIGH);
  delay(20);
  digitalWrite(GREEN_LED, LOW);  
  delay(4000);
}
