#include <Servo.h> 

Servo myservo;
void setup() {
  // put your setup code here, to run once:
myservo.attach(6);
}

void loop() {
  // put your main code here, to run repeatedly:
    myservo.write(20);              // tell servo to go to position in variable 'pos' 
    delay(1000);   
myservo.write(90);              // tell servo to go to position in variable 'pos' 
    delay(1000);  
    myservo.write(120);              // tell servo to go to position in variable 'pos' 
    delay(1000);  
}
