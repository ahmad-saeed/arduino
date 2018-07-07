#include <Servo.h>
Servo myservo;
int mini, maxi;
int n = 5;

void setup() {
  Serial.begin (9600);
  myservo.attach(9);


  for (int attempt = 0 ; attempt < n; attempt++)
  {
    myservo.write (180);
    delay(2000);
    mini += analogRead(0);
    myservo.write (0);
    delay(2000);
    maxi += analogRead(0);
  }

  // Results
  Serial.print("Max value is: ");    Serial.println(mini / n);
  Serial.print("Min value is: ");    Serial.println(maxi / n);
}


void loop() { }
