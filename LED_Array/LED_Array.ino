int x = 5;
int margin= 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  a();
  h();
}

void clearall()
{
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void a()
{
  // One 
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH); 
  digitalWrite(6,HIGH); 
  digitalWrite(7,HIGH);  
  delay(x);
  clearall();
  // Two
  digitalWrite(4,HIGH);  
  digitalWrite(8,HIGH);  
  delay(x);
  clearall();
  // Three
  digitalWrite(4,HIGH);  
  digitalWrite(8,HIGH);  
  delay(x);
  clearall();
  // Four
  digitalWrite(4,HIGH);  
  digitalWrite(8,HIGH);  
  delay(x);
  clearall();
  // Five  
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH); 
  digitalWrite(6,HIGH); 
  digitalWrite(7,HIGH);  
  delay(x);
  clearall();
  // margin
  delay (margin);
}

void h()
{
  // One 
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH); 
  digitalWrite(6,HIGH); 
  digitalWrite(7,HIGH);  
  digitalWrite(8,HIGH); 
  delay(x);
  clearall();
  // Two
  digitalWrite(4,HIGH);  
  delay(x);
  clearall();
  // Three
  digitalWrite(4,HIGH);  
  delay(x);
  clearall();
  // Four
  digitalWrite(4,HIGH);    
  delay(x);
  clearall();
  // Five  
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH); 
  digitalWrite(6,HIGH); 
  digitalWrite(7,HIGH);  
  digitalWrite(8,HIGH);
  delay(x);
  clearall();
  // margin
  delay (margin);
}


