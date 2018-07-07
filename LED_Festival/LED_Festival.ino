int sped = 150, led[8], btn[4], i = -1, o = 8, interval;
boolean mode, paused, canChange, s0, s1, s2, s3, pass;
unsigned long prev;

void setup() {
  led[0] = 2;  led[1] = 3;  led[2] = 4;  led[3] = 5;
  led[4] = 6;  led[5] = 7;  led[6] = 8;  led[7] = 9;
  btn[0] = 10;  btn[1] = 11;  btn[2] = 12;  btn[3] = 13;

  for (int x = 0; x < 8; x++)  pinMode(led[x], OUTPUT);
  for (int y = 0; y < 4; y++)  pinMode(btn[y], INPUT_PULLUP);
}

void loop() {
  ///////////////////////////////////////////////////////// Reading The Buttons
  if ( digitalRead(btn[0]) == LOW && s0 == false )  {
    delay(150); //debouncing
    mode = !mode;
    s0 = true;
    interval = 0;  }
  else if (digitalRead(btn[0]) == HIGH) s0 = false;

  if ( digitalRead(btn[1]) == LOW && s1 == false )  {
    delay(150); //debouncing
    sped = sped + 100;
    s1 = true;
    interval = 0;  }
  else if (digitalRead(btn[1]) == HIGH) s1 = false;
  
  if ( digitalRead(btn[2]) == LOW && sped > 50 && s2 == false )  {
    delay(150); //debouncing
    sped = sped - 100;
    s2 = true;
    interval = 0;  }
  else if (digitalRead(btn[2]) == HIGH) s2 = false;

  if ( digitalRead(btn[3]) == LOW && s3 == false )  {
    delay(150); //debouncing
    paused = !paused;
    s3 = true;
    prev = millis();
    digitalWrite (led[i], HIGH);  }
  else if ( digitalRead(btn[3]) == HIGH) s3 = false;

  ///////////////////////////////////////////////////////// Taking Actions
  if ( paused == true ) digitalWrite (led[i], LOW);
  else
  {
    interval = interval + millis() - prev;
    prev = millis();
    if ( interval >= sped || pass == true )
    {
      pass = false;
      interval = 0;
      if ( mode == false )
      {
        o = i;
        i ++;
        if ( i == 8 ) i = 0;
      }
      else if ( mode == true )
      {
        o = i;
        i--;
        if (i == -1 ) i = 7;
      }
      ///////////////////////////////////////////////////////// Applying On LEDs
      digitalWrite(led[i], HIGH);
      digitalWrite(led[o], LOW);
    }
  }
}
