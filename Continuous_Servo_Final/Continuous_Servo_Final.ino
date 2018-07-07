int potDgr = 180;
int valPerCycl = 7;
int del=36;

int mpos, ppos, diff;
#include <Servo.h>
Servo myservo;

void setup() {
  myservo.attach(9);
  mpos = map(analogRead(0), 0, 1023, 0, potDgr);  }

void loop() {
  ppos = map(analogRead(0), 0, 1023, 0, potDgr);
  diff = mpos - ppos;
  if (abs(diff) < 15) {
    myservo.write(93);
  }
  else if (diff < 0) // pot > motor
  {
     myservo.write(130);
    delay(del);
     mpos=mpos+valPerCycl;
  }
  else if (diff > 0)
  {
    myservo.write(55);
    delay(del);
    mpos=mpos-valPerCycl;
  }
}
