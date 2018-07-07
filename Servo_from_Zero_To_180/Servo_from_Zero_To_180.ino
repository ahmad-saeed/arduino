#include <Servo.h>
Servo one;
void setup() {
  // put your setup code here, to run once:
one.attach(2);
}

void loop() {
  // put your
  one.write(0);
  delay(5000);
  one.write(180);
  delay(5000);
}
