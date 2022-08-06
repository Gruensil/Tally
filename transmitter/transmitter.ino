
#include <SoftwareSerial.h>


const byte HC12RxdPin = A3; // "RXD" Pin on HC12
const byte HC12TxdPin = A2; // "TXD" Pin on HC12
const int RED_LED = 2;
const int GREEN_LED = 3;
const int BLUE_LED = 4;

SoftwareSerial HC12(HC12TxdPin, HC12RxdPin);

void setup() {
    HC12.begin(19200);
    Serial.begin(9600);
    Serial.setTimeout(1);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    digitalWrite(BLUE_LED, HIGH);

    delay(100);
}

void loop() {

  while (!Serial.available());
  delay(10);
  int input = Serial.readString().toInt();
  // int programTally = Serial.readString().toInt();
  // int previewTally = programTally;

  // int transmission = programTally;
  // transmission = transmission << 3;
  // transmission = transmission | previewTally;

  HC12.write(input);
  Serial.println(input);
  digitalWrite(GREEN_LED, HIGH);
  delay(10);
  digitalWrite(GREEN_LED, LOW);  
  delay(10);
}
