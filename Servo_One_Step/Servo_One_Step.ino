#include <Servo.h>
Servo myservo;

void setup() { myservo.attach(9); }

void loop() {
 
    myservo.write(130);
        delay(10);
    myservo.write(93);
    delay(10);
 
}
