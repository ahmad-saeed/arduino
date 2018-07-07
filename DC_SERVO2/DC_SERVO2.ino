int desiredVolt = 512;
int currentVolt;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  currentVolt = analogRead(A0);
  if ( desiredVolt > currentVolt )
  { digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  }

  if ( desiredVolt < currentVolt )
  { digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  }
  if ( desiredVolt == currentVolt )
  { digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
}
