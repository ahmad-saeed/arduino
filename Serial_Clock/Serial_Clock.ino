int mins=10;
int secs=0;
unsigned long lastTime;

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   if ((millis() - lastTime > 1000) )
  {
    lastTime = millis ();
  
if ( secs !=0 )
{
secs = secs-1;
}
else
{
secs = 59;
mins = mins - 1;
}
Serial.print(mins);
Serial.print(" : ");
Serial.println(secs);
  }
  
  
}
