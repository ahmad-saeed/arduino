int clk=7;
int data=8;
void setup() {
  // put your setup code here, to run once:
pinMode(clk,OUTPUT);
pinMode(data,OUTPUT);
digitalWrite(clk,LOW);
digitalWrite(data,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
ryt(HIGH);
ryt(HIGH);
ryt(LOW);
ryt(HIGH);
delay(100);

ryt(HIGH);
ryt(HIGH);
ryt(HIGH);
ryt(LOW);
delay(100);

ryt(LOW);
ryt(HIGH);
ryt(HIGH);
ryt(HIGH);
delay(100);

ryt(HIGH);
ryt(LOW);
ryt(HIGH);
ryt(HIGH);
delay(100);
}


void ryt(bool x)
{
  digitalWrite(data,!x);
  digitalWrite(clk,HIGH);
  digitalWrite(clk,LOW);
}
