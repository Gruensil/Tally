//#include <SoftwareSerial.h>
//
//
//const byte HC12RxdPin = 4; // "RXD" Pin on HC12
//const byte HC12TxdPin = 5; // "TXD" Pin on HC12
//const int LED_PIN = 2;
//
//SoftwareSerial HC12(HC12TxdPin, HC12RxdPin);
//
//void setup() {
//    HC12.begin(9600);
//    pinMode(LED_PIN, OUTPUT);
//}
//
//void loop() {
//    if(HC12.available() > 0)
//    {
//        int input = HC12.read();
//        if(input == 5)
//        {
//            digitalWrite(LED_PIN, HIGH);
//        }
//        else{
//            digitalWrite(LED_PIN, LOW);
//        }
//    }
//}
