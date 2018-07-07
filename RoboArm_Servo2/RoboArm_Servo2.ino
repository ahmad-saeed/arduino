#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;

void setup() {
s1.attach(3);
s2.attach(6);
s3.attach(9);
}

void loop() {
s1.write(map(analogRead(0),0,1023,0,250));
s2.write(map(analogRead(1),0,1023,0,250));
s3.write(map(analogRead(2),0,1023,0,250));

}
