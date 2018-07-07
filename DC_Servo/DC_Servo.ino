int pot1;
int pot2;
int maxi = 30;

void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
}

void loop() {
pot2=map(analogRead(1),0,1023,0,maxi);
pot1=map(analogRead(0),0,1023,0,maxi);
if (pot1>pot2)
{
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
}
else if (pot2>pot1)
{
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
}
else
{
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
}
}
