/* #include <Servo.h>
Servo myservo;
int potpin = 0;
int val;
void setup()
{
myservo.attach(9);
}
void loop()
{
val = analogRead(potpin);  
         
         
val = map(val, 0, 1023, 0, 179); 
         
         
myservo.write(val);    
         
delay(15);      
}
*/
 #include <Servo.h>
Servo myservo;
int val;
void setup()
{
myservo.attach(9);
}
void loop()
{
myservo.write(93);          
delay(1000);
myservo.write(180);          
delay(666);
myservo.write(0);          
delay(666);
}
