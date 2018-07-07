#include <Servo.h>
String messageBody;
int v1, v2, v3, v4;
bool messageDelivered = true;
Servo s1, s2, s3, s4;


void setup() {
  v1 = 45;
  v2 = 45;
  v3 = 45;
  v4 = 45;
  Serial.begin(9600);
  s1.attach(2);
  s2.attach(3);
  s3.attach(4);
  s4.attach(5);
}

void loop() {
  
  if ( Serial.available() > 0 )  {
    messageBody += char(Serial.read());
    messageDelivered = false;
    delay(3);
  }
  else  {
    if (messageDelivered == false)    {
      Serial.println(messageBody);
      v1 = (messageBody.substring(0, 3)).toInt();
      v2 = (messageBody.substring(3, 6)).toInt();
      v3 = (messageBody.substring(6, 9)).toInt();
      v4 = (messageBody.substring(9, 12)).toInt();
      
      messageDelivered = true;
      messageBody = "";
    }
  }
  s1.write(v1);
  s2.write(v2);
  s3.write(v3);
  s4.write(v4);
  
}
