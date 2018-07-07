
void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  /*
    From 500 to 2500
   */

  digitalWrite(8, HIGH);
  delayMicroseconds(2500);
  digitalWrite(8, LOW);
  delay(20);

}
