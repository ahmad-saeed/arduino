const int LED1 = 9 ;
const int LED2 = 10 ;
const int LED3 = 11 ;
const int LED4 = 12 ;
const int redLED = 3 ;
const int greenLED = 2 ;
boolean st = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1,OUTPUT);
  pinMode(LED2 ,OUTPUT);
  pinMode(LED3 ,OUTPUT);
  pinMode(LED4 ,OUTPUT);
  pinMode(redLED ,OUTPUT);
  pinMode(greenLED ,OUTPUT);
 digitalWrite(LED1,1);
 digitalWrite(LED2,1);
 digitalWrite(LED3,1);
 digitalWrite(LED4,1);
 digitalWrite(greenLED,1);
 digitalWrite(redLED,1);
}

void loop() {
  // put your main code here, to run repeatedly:


 digitalWrite(greenLED,1);
 digitalWrite(LED2,1);
 
 digitalWrite(redLED,0);
 analogWrite(LED1,220);
            delay(300); 
            

 digitalWrite(redLED,1);
 digitalWrite(LED1,1);

 digitalWrite(LED2,0);
 digitalWrite(greenLED,0);
            delay(300); 
            
            
digitalWrite(greenLED,1);
 digitalWrite(LED2,1);
 
  digitalWrite(LED1,0);
            delay(300); 
  digitalWrite(LED1,1);
  digitalWrite(LED2,0);
            delay(300); 
digitalWrite(LED2,1);
  digitalWrite(LED3,0);
            delay(300); 
            digitalWrite(LED3,1);
  digitalWrite(LED4,0);
            delay(300); 
              digitalWrite(LED4,1);
            delay(300); 

}
