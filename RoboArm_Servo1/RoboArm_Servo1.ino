#include <Servo.h>

Servo saeed;

void setup() {
  // put your setup code here, to run once:
saeed.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:

saeed.write (50);
delay(1000);
saeed.write (150);
delay (1000);

}
