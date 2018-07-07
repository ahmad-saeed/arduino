int row1 = 6;
int row2 = 7;
int row3 = 8;
int right = 2;
int left = 4;

void setup() {
  pinMode(row1,OUTPUT);
  pinMode(row2,OUTPUT);
  pinMode(row3,OUTPUT);
  pinMode(right,OUTPUT);
  pinMode(left,OUTPUT);       }

void clearall() { 
  digitalWrite(row1,LOW);
  digitalWrite(row2,LOW);
  digitalWrite(row3,LOW);
  digitalWrite(right,HIGH);
  digitalWrite(left,HIGH);   }
  
void loop() {
      clearall();
      digitalWrite(left,LOW);
      digitalWrite(right,LOW);
      digitalWrite(row1,HIGH);
      delay(500);
      digitalWrite(row1,LOW);
      digitalWrite(row2,HIGH);
      delay(500);
      digitalWrite(row2,LOW);
      digitalWrite(row3,HIGH);
      delay(500);
      
  for (int n = 0; n < 20; n++) { 
    if (n%2!=0)
    {
      clearall();
      digitalWrite(left,LOW);
      digitalWrite(right,LOW);
      digitalWrite(row1,HIGH);
      digitalWrite(row3,HIGH);
      delay(50);
    }
    else
    {
      clearall();
      digitalWrite(left,LOW);
      digitalWrite(right,LOW);
      digitalWrite(row2,HIGH);
      delay(100);
    }
  }
  

  for (int n = 0; n < 500; n++) { 
   clearall();
   digitalWrite(right,LOW);
   digitalWrite(row1,HIGH);
   delay(1);
   
   clearall();
   digitalWrite(left,LOW);
   digitalWrite(row2,HIGH);
   delay(1);

   clearall();
   digitalWrite(right,LOW);
   digitalWrite(row3,HIGH);
   delay(1);
  }
  
  for (int n = 0; n < 500; n++) { 
   clearall();
   digitalWrite(left,LOW);
   digitalWrite(row1,HIGH);
   delay(1);
   
   clearall();
   digitalWrite(right,LOW);
   digitalWrite(row2,HIGH);
   delay(1);

   clearall();
   digitalWrite(left,LOW);
   digitalWrite(row3,HIGH);
   delay(1);
  }
}


