// Technique One

#include <Servo.h>
Servo myservo;
int val, lval, diff, deltat, speedservo;
unsigned long ltime;
float speedpot;
void setup()
{
  myservo.attach(9);
  Serial.begin (9600);
}
void loop()
{
  val = map(analogRead(0), 0, 1023, 0, 250); // turn volt into angles to avoid noise and to make speed calculations
  diff = val - lval;
  if (abs(diff) < 1) {
    myservo.write(93);    // avoid noise
  }
  else {

    deltat = millis() - ltime;
    speedpot = ((float)diff / (float)deltat) * 100;
    speedpot = (int)speedpot;
    if (speedpot > 60) {
      speedpot = 60;
    }
    if (speedpot > 1) {
      speedservo = map(abs(speedpot), 0, 35, 93, 150);
    }
    else if (speedpot < 1) {
      speedservo = map(abs(speedpot), 0, 35, 93, 40);
      Serial.println(speedservo);
    }
    myservo.write(speedservo);
  }
  lval = val;
  ltime = millis();
  delay(150);
}
