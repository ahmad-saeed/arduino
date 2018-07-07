int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;

int c1 = 8;
int c2 = 9;
int c3 = 10;
int c4 = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode ( a, OUTPUT);
  pinMode ( b, OUTPUT);
  pinMode ( c, OUTPUT);
  pinMode ( d, OUTPUT);
  pinMode ( e, OUTPUT);
  pinMode ( f, OUTPUT);
  pinMode ( g, OUTPUT);
  pinMode ( c1, OUTPUT);
  pinMode ( c2, OUTPUT);
  pinMode ( c3, OUTPUT);
  pinMode ( c4, OUTPUT);

  digitalWrite( c1 , HIGH);
  digitalWrite( c2 , HIGH);
  digitalWrite( c3 , HIGH);
  digitalWrite( c4 , HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite( c4 , LOW);
  y(4);
  delay(5);
  digitalWrite( c4 , HIGH);

  digitalWrite( c3 , LOW);
  y(9);
  delay(5);
  digitalWrite( c3 , HIGH);

  digitalWrite( c2 , LOW);
  y(9);
  delay(5);
  digitalWrite( c2 , HIGH);


  digitalWrite( c1 , LOW);
  y(1);
  delay(5);
  digitalWrite( c1 , HIGH);
}

void y (int x) {
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

