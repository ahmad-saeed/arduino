String messageBody;
bool messageDelivered = true, turn = false;
int mode, R, G, B;
unsigned long lastTime;

#define LED_R 3
#define LED_G 5
#define LED_B 6
#define period 500

// mode 0 --> trun off everything  0#########
// mode 1 --> choosing a color     1123123123
// mode 2 --> alarm                2123123123

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {

  // main function [ DESK LAMP ]
  analogWrite(9, map(analogRead(A6), 0, 1023, 255,0) );
  // recieving serial message------------------------------------ //
  if ( Serial.available() > 0 )  {                                //
    messageBody += char(Serial.read());                           //
    messageDelivered = false;                                     //
    delay(3);                                                     //
  }                                                               //
  else  {                                                         //
    if (messageDelivered == false)    {                           //
      mode =  (messageBody.substring(0, 1)).toInt();              //
      R = (messageBody.substring(1, 4)).toInt();                  //
      G = (messageBody.substring(4, 7)).toInt();                  //
      B = (messageBody.substring(7, 10)).toInt();                 //
      messageDelivered = true;                                    //
      messageBody = "";                                           //
    }                                                             //
  } //----------------------------------------------------------- //


  if ( mode == 0 )
  {
    analogWrite(LED_R, 0);
    analogWrite(LED_G, 0);
    analogWrite(LED_B, 0);
  }

  if ( mode == 1 )
  {
    analogWrite(LED_R, R);
    analogWrite(LED_G, G);
    analogWrite(LED_B, B);
  }

  // blink every period
  if ( mode == 2 )
  {
    if  (( millis() - lastTime ) > period )
    {
      delay(10);
      lastTime = millis();
      turn = !turn;
    }
    if ( turn == false ) {
      analogWrite(LED_R, 0);
      analogWrite(LED_G, 0);
      analogWrite(LED_B, 0);
    }
    else if ( turn == true ) {
      analogWrite(LED_R, R);
      analogWrite(LED_G, G);
      analogWrite(LED_B, B);
    }
  }
 // Serial.println(analogRead(A4));

  // piezo kills everything
  if ( analogRead(A4) > 20 ) {
    mode = 0;
  }
  
}
