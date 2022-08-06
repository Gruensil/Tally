
int x;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1);

  pinMode(2, OUTPUT);
}
void loop() {
  while (!Serial.available());
  x = Serial.readString().toInt();
  for(int i = 0; i < x; ++i)
  {
    digitalWrite(2, HIGH);
    delay(200);
    digitalWrite(2, LOW);
    delay(200);
  }
  Serial.print(x + 1);
  delay(100);
}
