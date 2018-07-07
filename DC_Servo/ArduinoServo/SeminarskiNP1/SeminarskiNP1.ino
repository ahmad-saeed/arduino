#include <Servo.h>
Servo servo;
String readString = "";
int motor1;
int motor2;
void setup(){
  Serial.begin(9600);
  servo.attach(36); 
  servo.write(90);
}
void loop(){
while (Serial.available() > 0){
delay(10);  
    if(Serial.available() >0) {
      char c = Serial.read();  
      readString += c; 
    }
    else servo.write(90);  
}
if (readString.length() == 6){  
String m1 = readString.substring(0, 3);
String m2 = readString.substring(3, 6);
char chararray1[6]; 
char chararray2[6];
m1.toCharArray(chararray1, sizeof(chararray1));
motor1 = atoi(chararray1);
m2.toCharArray(chararray2, sizeof(chararray2));
motor2 = atoi(chararray2);
if(motor2 < motor1){
  for(int i = motor2; i <= motor1; i++){
  servo.write(i);
  delay(10);
}}
if(motor2 > motor1){
  for(int i = motor2; i>= motor1; i--){
  servo.write(i);
  delay(10);
  }
}}
readString = "";
}
