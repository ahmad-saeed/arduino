void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,INPUT);
}

void loop() {  
  /*
if (digitalRead(10)==HIGH)
{
  delay(50);
  digitalWrite(12,HIGH);
}
else
{
  digitalWrite(12,LOW);
}
//*/8
digitalWrite(13,HIGH);
delay(50);
digitalWrite(13,LOW);
delay(500);

}
