void setup() {
  pinMode(7, OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  for (int i = 0; i < 200; i++) {
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(7, LOW);
    delay(5);
  }
  for (int i = 0; i < 200; i++) {
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(7, LOW);
    delay(5);
  }
}
