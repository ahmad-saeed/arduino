#define A 2
#define Abar 3
#define B 4
#define Bbar 5

void setup() {
  // put your setup code here, to run once:
  pinMode(A, OUTPUT);
  pinMode(Abar, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(Bbar, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int s = 5;
  /*
    for (int thisPin = 0; thisPin < 200; thisPin++) {

      digitalWrite(2, HIGH); // A
      digitalWrite(3, LOW);  // A-
      digitalWrite(4, LOW);  // B
      digitalWrite(5, LOW);  // B-
      delay (s);

      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH); // B
      digitalWrite(5, LOW);
      delay (s);

      digitalWrite(2, LOW);
      digitalWrite(3, HIGH); // A-
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      delay (s);

      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH); // B-
      delay (s);
    }
    delay(5000);
    */
  for (int thisPin = 0; thisPin < 50; thisPin++) {
    Serial.println(thisPin);
    digitalWrite(A, HIGH);
    digitalWrite(Abar, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(Bbar, LOW);
    delay (s);

    digitalWrite(A, LOW);
    digitalWrite(Abar, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(Bbar, LOW);
    delay (s);

    digitalWrite(A, LOW);
    digitalWrite(Abar, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(Bbar, HIGH);
    delay (s);

    digitalWrite(A, HIGH);
    digitalWrite(Abar, LOW);
    digitalWrite(B, LOW);
    digitalWrite(Bbar, HIGH);
    delay (s);
  }
  delay(1000);
}
