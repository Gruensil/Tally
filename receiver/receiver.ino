#include <SoftwareSerial.h>


const byte HC12RxdPin = A3; // "RXD" Pin on HC12
const byte HC12TxdPin = A2; // "TXD" Pin on HC12
const int RED_LED = 2;
const int GREEN_LED = 3;
const int BLUE_LED = 4;

const int CAM_ID = 1;



SoftwareSerial HC12(HC12TxdPin, HC12RxdPin);

void setup() {
    HC12.begin(9600);
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
    
}

byte flipByte(byte c)
     {
       c = ((c>>1)&0x55)|((c<<1)&0xAA);
       c = ((c>>2)&0x33)|((c<<2)&0xCC);
       c = (c>>4) | (c<<4) ;

       return c;
     }

void loop() {
    if(HC12.available() > 0)
    {
        int input = HC12.read();
//        int input = flipByte(wronginput);
        int previewTally = input & 0b0000111;
        int programTally = (input & 0b0111000) >> 3;

        for(int i = 0; i < input; ++i){
          digitalWrite(RED_LED, HIGH);
          delay(100);
          digitalWrite(RED_LED, LOW);
          delay(100);
        }

//        if(programTally == CAM_ID){
//            digitalWrite(RED_LED, HIGH);
//        }else{
//            digitalWrite(RED_LED, LOW);
//        }
//        if(previewTally == CAM_ID){
//            digitalWrite(GREEN_LED, HIGH);
//        }else{
//            digitalWrite(GREEN_LED, LOW);
//        }
    }
}
