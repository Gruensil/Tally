#include <SoftwareSerial.h>


const byte ArduTxdPin = 9;
const byte ArduRxdPin = 8;


SoftwareSerial Ardu(ArduTxdPin, ArduRxdPin);

void setup() {
  Ardu.begin(9600);
  Serial.begin(9600);
  
  Serial.println("Test starts...");
  delay(100);
  
}

void loop() {

  if (Ardu.available())
  {    
      Serial.println("I received something!");
      byte num = Ardu.read();
      Serial.println(num);
      delay(100);

/*
      int num0 = Ardu.parseInt();
      int num1 = Ardu.parseInt();
      Serial.println(num0);
      Serial.println(num1);

      if(Ardu.read() == '\n'){
        
      }
      delay(100);
      */
  }
}
