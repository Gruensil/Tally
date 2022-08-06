#include <SoftwareSerial.h>


const byte HC12RxdPin = A3; // "RXD" Pin on HC12
const byte HC12TxdPin = A2; // "TXD" Pin on HC12
const byte HC12SetPin = 9;

const int RED_LED = 2;
const int GREEN_LED = 3;
const int BLUE_LED = 4;

const int CAM_ID = 2;

String readStr;

SoftwareSerial HC12(HC12TxdPin, HC12RxdPin);

void setup() {
  HC12.begin(19200);
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  digitalWrite(BLUE_LED, HIGH);

  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  delay(1000);
  Serial.println("I am listening...");

  HC12.flush();

}

void loop() {
  while (!HC12.available());

  int input = HC12.read();
  delay(10);
  Serial.println(input);

  int prv = input & 0b00000111;
  int pgm = (input & 0b00111000) >> 3;
  if(pgm == CAM_ID){
     digitalWrite(RED_LED, HIGH);
  }else{
      digitalWrite(RED_LED, LOW);
  }
  if(prv == CAM_ID){
      digitalWrite(GREEN_LED, HIGH);
  }else{
      digitalWrite(GREEN_LED, LOW);
  }
}
