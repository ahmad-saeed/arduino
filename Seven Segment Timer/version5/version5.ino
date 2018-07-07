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

int numInput= 600;
int numToWrite, n1, n2, n3, n4;
unsigned long lastTime;

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
pinMode ( 13, OUTPUT);
digitalWrite( 13 , LOW);
  digitalWrite( c1 , HIGH);
  digitalWrite( c2 , HIGH);
  digitalWrite( c3 , HIGH);
  digitalWrite( c4 , HIGH);
}

void loop() {
  // Counter
  if (numInput ==0)
  {
     digitalWrite( c1 , LOW);
  digitalWrite( c2 , LOW);
  digitalWrite( c3 , LOW);
  digitalWrite( c4 , LOW);
  y(0);
  
     digitalWrite( 13 , HIGH);
     delay(50);
     digitalWrite( 13 , LOW);
     delay(40);
     digitalWrite( 13 , HIGH);
     delay(50);
     digitalWrite( 13 , LOW);
     delay(40); 
     digitalWrite( 13 , HIGH);
     delay(50);
     digitalWrite( 13 , LOW);
     delay(1000);
     
}
else{
  if ((millis() - lastTime > 1000) )
  {
    numInput = numInput - 1;
    lastTime = millis ();
  }
  
 numToWrite =numInput;
 
  n4 = numToWrite%10;
  
  numToWrite = numToWrite / 10;
  n3 = numToWrite%10;

  numToWrite = numToWrite / 10;
  n2 = numToWrite%10;  

  numToWrite = numToWrite / 10;
  n1 = numToWrite%10;  
  
  digitalWrite( c4 , LOW);
  y(n4);
  delay(5);
  digitalWrite( c4 , HIGH);

  digitalWrite( c3 , LOW);
  y(n3);
  delay(5);
  digitalWrite( c3 , HIGH);

  digitalWrite( c2 , LOW);
  y(n2);
  delay(5);
  digitalWrite( c2 , HIGH);


  digitalWrite( c1 , LOW);
  y(n1);
  delay(5);
  digitalWrite( c1 , HIGH);
}}

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

