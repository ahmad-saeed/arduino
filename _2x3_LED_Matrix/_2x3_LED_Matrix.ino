void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  clearall();
}

void loop() {
  // put your main code here, to run repeatedly:

  
  a1();
  delay(150);
  b1();
  delay(150);
  a2();
  delay(150);
  b2();
  delay(150);
  a3();
  delay(150);
  b3();
  delay(150);
  
  a1();
  delay(150);
  
  for (int n = 0; n < 50; n++) { 
    a1();
    delay(5);
    b2();
    delay(5);
  }
  for (int n = 0; n < 50; n++) { 
    a1();
    delay(5);
    b2();
    delay(5);
    a3();
    delay(5);
  }
  
  for (int n = 0; n < 50; n++) { 
    b1();
    delay(5);
    a2();
    delay(5);
    b3();
    delay(5);
  }
  
  for (int n = 0; n < 50; n++) { 
    if (n%2!=0)
    {
      a1();
      delay(5);
      b1();
      delay(5);
      a3();
      delay(5);
      b3();
      delay(5);
    }
    else
    {
      delay(20);
      a2();
      delay(5);
      b2();
      delay(20);
    }
  }
}

void clearall()
{ digitalWrite(4,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);}

void a1()
{ clearall();
  digitalWrite(2,LOW);
  digitalWrite(6,HIGH);}

void b1()
{ clearall();
  digitalWrite(4,LOW);
  digitalWrite(6,HIGH);}

void a2()
{ clearall();
  digitalWrite(2,LOW);
  digitalWrite(7,HIGH);}

void b2()
{ clearall();
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);}

void a3()
{ clearall();
  digitalWrite(2,LOW);
  digitalWrite(8,HIGH);}

void b3()
{ clearall();
  digitalWrite(4,LOW);
  digitalWrite(8,HIGH);}  
