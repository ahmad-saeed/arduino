#include <Servo.h>
#include <math.h>
String messageBody;
bool messageDelivered = true;

Servo saeed, ahmad;
double l1, l2, theta1, theta2, d, h, cal1, cal2;


void setup() {
  cal1 = 305;
  cal2 = 165;


  saeed.attach(2);
  ahmad.attach(3);

  theta1 = 165;
  theta2 = 165;

  l1 = 5;
  l2 = 3;

  d = (l1 * cos(theta1 * 3.14 / 180)) + (l2 * cos(theta2 * 3.14 / 180));
  h = (l1 * sin(theta1 * 3.14 / 180)) + (l2 * sin(theta2 * 3.14 / 180));

  saeed.write(cal1 - theta1);
  ahmad.write(cal2 - theta2);
  Serial.begin(9600);

}

void loop() {

  if ( Serial.available() > 0 )  {
    messageBody += char(Serial.read());
    messageDelivered = false;
    delay(3);
  }
  else  {
    if (messageDelivered == false)    {
      //theta1 ++;
      //theta2 = acos((d - (l1 * cos(theta1*3.14/180))) / l2)*180/3.14;
      theta2 --;
      theta1 = asin((h - (l2 * sin(theta2 * 3.14 / 180))) / l1) * 180 / 3.14;

      messageDelivered = true;
      messageBody = "";
    }
  }

  saeed.write(cal1 - theta1);
  ahmad.write(cal2 - theta2);
}
