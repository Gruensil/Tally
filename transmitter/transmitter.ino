
#include <SoftwareSerial.h>
#include <SkaarhojPgmspace.h>
#include <ATEMbase.h>
#include <ATEMstd.h>


const byte HC12RxdPin = 4; // "RXD" Pin on HC12
const byte HC12TxdPin = 5; // "TXD" Pin on HC12
const int switch_pin = 7;
const int led_pin = 10;
const int cam_number = 4;

ATEMstd AtemSwitcher;

IPAddress switcherIp(192,168,0,125);

SoftwareSerial HC12(HC12TxdPin, HC12RxdPin);

void setup() {
  HC12.begin(9600);
//
//  AtemSwitcher.begin(switcherIp);
//  AtemSwitcher.serialOutput(0x80);
//  AtemSwitcher.connect();
}

void loop() {
  AtemSwitcher.runLoop();
  
  int programTally = 3;
  int previewTally = 1;
  
//  int programTally = AtemSwitcher.getProgramInput();
//  int previewTally = AtemSwitcher.getPreviewInput();
  
  if(digitalRead(switch_pin) == HIGH){
    programTally = 3;
  }
  if(digitalRead(switch_pin) == LOW){
    programTally = 2;
  }
  delay(50);

  if(programTally > cam_number || previewTally > cam_number){
    Serial.print("Cam number not valid.");
    return;
  }
  int transmission = programTally;
  transmission = transmission << 3;
  transmission = transmission | previewTally;
  HC12.write(transmission);
  delay(5000);
}
