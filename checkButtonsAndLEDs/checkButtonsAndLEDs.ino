const int LED1 = 9 ;
const int LED2 = 10 ;
const int LED3 = 11 ;
const int LED4 = 12 ;
const int button1 = 5 ;
const int button2 = 6 ;
const int button3 = 7 ;
const int button4 = 8 ;
boolean isButton4Up = true;

void setup() {
  // put your setup code here, to run once:
pinMode(LED1,OUTPUT);

  pinMode(LED4 ,OUTPUT);
  pinMode(button1 ,INPUT);
 
  pinMode(button4 ,INPUT);
    Serial.begin(9600);
  pinMode(13 ,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);

if (digitalRead(button1)!=HIGH){
digitalWrite(LED1,HIGH);
Serial.write("1");
Serial.println();
delay(100);}
else{digitalWrite(LED1,LOW);}


if (digitalRead(button4)==HIGH &&  isButton4Up == true)
{digitalWrite(LED4,HIGH);
Serial.write("4");
Serial.println();
         isButton4Up = false;
}
else if (digitalRead(button4) == LOW)
       {
         isButton4Up = true;
         digitalWrite(LED4,LOW);
         delay(100);
       }

}
