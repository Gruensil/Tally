#include <SoftwareSerial.h>


const byte HC12RxdPin = A3; // "RXD" Pin on HC12
const byte HC12TxdPin = A2; // "TXD" Pin on HC12
const int RED_LED = 2;
const int GREEN_LED = 3;
const int BLUE_LED = 4;

const int CAM_ID = 240;



SoftwareSerial HC12(HC12TxdPin, HC12RxdPin);

void setup() {
    HC12.begin(9600);
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
    
}

void loop() {
    if(HC12.available() > 0)
    {
        byte pgm = HC12.read();
        delay(100);
        byte prv = HC12.read();
        delay(100);
        Serial.println(pgm);
        Serial.println(prv);
        
//        byte val = HC12.read();
//        Serial.println(val);
//        for(int i = 0; i<8 ; i++)
//        {
//          bool b = val & 0x80; 
//          Serial.print(b);
//          val = val << 1;
//        }

//        Serial.print("\n");
        
//        int previewTally = input & 0b0000111;
//        int programTally = (input & 0b0111000) >> 3;


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
}
