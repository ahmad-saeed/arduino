int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode ( a, OUTPUT);
  pinMode ( b, OUTPUT);
  pinMode ( c, OUTPUT);
  pinMode ( d, OUTPUT);
  pinMode ( e, OUTPUT);
  pinMode ( f, OUTPUT);
  pinMode ( g, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  writeNumber(0);
  delay(500);
  writeNumber(1);
  delay(500);
  writeNumber(2);
  delay(500);
  writeNumber(3);
  delay(500);
  writeNumber(4);
  delay(500);
  writeNumber(5);
  delay(500);
  writeNumber(6);
  delay(500);
  writeNumber(7);
  delay(500);
  writeNumber(8);
  delay(500);
  writeNumber(9);
  delay(500);
}

void writeNumber (int x) {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  if (x == 1 )
  {
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
  }
  if (x == 2 )
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(g, HIGH);
  }
  if (x == 3 )
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(g, HIGH);
  }
  if (x == 4 )
  {
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (x == 5 )
  {
    digitalWrite(a, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (x == 6)
  {
    digitalWrite(a, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (x == 7 )
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
  }
  if (x == 8 )
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (x == 9 )
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (x == 0 )
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
  }
}

