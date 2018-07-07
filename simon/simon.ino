const int LED1 = 10 ;
const int LED2 = 11 ;
const int LED3 = 12 ;
const int LED4 = 13 ;
const int button1 = 5 ;
const int button2 = 6 ;
const int button3 = 7 ;
const int button4 = 8 ;
const int redLED = 3 ;
const int greenLED = 2 ;
const int buzzer = 9;
int level = 0;
int turn = 1;
int composition[99];
int answer[99];
boolean isCompositionDone = false;
boolean isButton1Up = true;
boolean isButton2Up = true;
boolean isButton3Up = true;
boolean isButton4Up = true;
boolean checker = true;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(button1 , INPUT);
  pinMode(button2 , INPUT);
  pinMode(button3 , INPUT);
  pinMode(button4 , INPUT);
  pinMode(redLED , OUTPUT);
  pinMode(greenLED , OUTPUT);
  pinMode(buzzer , OUTPUT);
  randomSeed(analogRead(0));
  digitalWrite(LED1, 1);
  digitalWrite(LED2, 1);
  digitalWrite(LED3, 1);
  digitalWrite(LED4, 1);
  digitalWrite(greenLED, 1);
  digitalWrite(redLED, 1);
}
void loop() {
  if (level != 99)
  {
    if (isCompositionDone == false)
    {
      level++;
      composition[level] = random(LED1, (LED4 + 1));
       for (int i = 1; i <= level; i++)
      {
        digitalWrite(composition[i], LOW);
        delay(700);
        digitalWrite(composition[i], HIGH);
        if (i != level) {delay(300);}
      }
      isCompositionDone = true;
    }
    else
    {
      if (turn <= level)
      {
        if (digitalRead(button1) == HIGH &&  isButton1Up == true)
        {
          answer[turn] = LED1;
          isButton1Up = false;
          digitalWrite(LED1, LOW);
          delay(100);
        }
        else if (digitalRead(button1) == LOW &&  isButton1Up == false)
        {
          turn++;
          isButton1Up = true;
          digitalWrite(LED1, HIGH);
          delay(100);
        }
        if (digitalRead(button2) == HIGH &&  isButton2Up == true)
        {
          answer[turn] = LED2;
          isButton2Up = false;
          digitalWrite(LED2, LOW);
          delay(100);
        }
        else if (digitalRead(button2) == LOW &&  isButton2Up == false)
        {
          turn++;
          isButton2Up = true;
          digitalWrite(LED2, HIGH);
          delay(100);
        }
        if (digitalRead(button3) == HIGH &&  isButton3Up == true)
        {
          answer[turn] = LED3;
          isButton3Up = false;
          digitalWrite(LED3, LOW);
          delay(100);
        }
        else if (digitalRead(button3) == LOW &&  isButton3Up == false)
        {
          turn++;
          isButton3Up = true;
          digitalWrite(LED3, HIGH);
          delay(100);
        }
        if (digitalRead(button4) == HIGH &&  isButton4Up == true)
        {
          answer[turn] = LED4;
          isButton4Up = false;
          digitalWrite(LED4, LOW);
          delay(100);
        }
        else if (digitalRead(button4) == LOW &&  isButton4Up == false)
        {
          turn++;
          isButton4Up = true;
          digitalWrite(LED4, HIGH);
          delay(100);
        }
      }
      else
      {
        turn = 1;
        for (int i = 1; i <= level; i++)
        {
          if (composition[i] != answer [i])   { checker = false; }
        }
        if (checker == true)
        {
          isCompositionDone = false;
          rightAnswerTheme();
        }
        else
        {
          wrongAnswerTheme();
        }
      }
    }
  }
  else
  {
    digitalWrite(greenLED, 1);
    digitalWrite(LED2, 1);
    delay(300);
    digitalWrite(greenLED, 0);
    digitalWrite(LED2, 0);
    delay(300);
  }
}
void wrongAnswerTheme()
{
  digitalWrite(LED1, 0);
  digitalWrite(redLED, 0);
  analogWrite(buzzer, 180);
  delay(150);
  analogWrite(buzzer, 60);
  delay(150);
  digitalWrite(redLED, 1);
  digitalWrite(LED1, 1);
  analogWrite(buzzer, 180);
  delay(150);
  analogWrite(buzzer, 60);
  delay(150);
  digitalWrite(LED1, 0);
  digitalWrite(redLED, 0);
  analogWrite(buzzer, 180);
  delay(150);
  analogWrite(buzzer, 0);
  while (1)
  {
    digitalWrite(redLED, 1);
    digitalWrite(LED1, 1);
    delay(300);
    digitalWrite(LED1, 0);
    digitalWrite(redLED, 0);
    delay(300);
  }
}
void rightAnswerTheme()
{
  digitalWrite(greenLED, 0);
  digitalWrite(LED2, 0);
  analogWrite(buzzer, 255);
  delay(50);
  analogWrite(buzzer, 0);
  delay(50);
  analogWrite(buzzer, 255);
  delay(50);
  analogWrite(buzzer, 0);
  delay(50);
  analogWrite(buzzer, 255);
  delay(50);
  analogWrite(buzzer, 0);
  delay(300);
  digitalWrite(greenLED, 1);
  digitalWrite(LED2, 1);
  delay(500);
}

