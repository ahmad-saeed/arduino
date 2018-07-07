#define STEP_A   2
#define DIR_A    3
#define CTRL_A1  4
#define CTRL_A2  5

#define STEP_B   9
#define DIR_B    10
#define CTRL_B1  11
#define CTRL_B2  12

#define period   1000


void setup() {
  pinMode(CTRL_A1, INPUT_PULLUP);
  pinMode(CTRL_A2, INPUT_PULLUP);
  pinMode(CTRL_B1, INPUT_PULLUP);
  pinMode(CTRL_B2, INPUT_PULLUP);

  pinMode(STEP_A, OUTPUT);
  pinMode(DIR_A, OUTPUT);
  pinMode(STEP_B, OUTPUT);
  pinMode(DIR_B, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if ( digitalRead(CTRL_A1) == LOW )
  {
    Serial.println("Right A");
    digitalWrite(DIR_A, HIGH);
    digitalWrite(STEP_A, HIGH);
    delayMicroseconds(period);
    digitalWrite(STEP_A, LOW);
  }

  if ( digitalRead(CTRL_A2) == LOW )
  {
    Serial.println("Left A");
    digitalWrite(DIR_A, LOW);
    digitalWrite(STEP_A, HIGH);
    delayMicroseconds(period);
    digitalWrite(STEP_A, LOW);
  }



  if ( digitalRead(CTRL_B1) == LOW )
  {
    Serial.println("Right B");
    digitalWrite(DIR_B, HIGH);
    digitalWrite(STEP_B, HIGH);
    delayMicroseconds(period);
    digitalWrite(STEP_B, LOW);
  }

  if ( digitalRead(CTRL_B2) == LOW )
  {
    Serial.println("Left B");
    digitalWrite(DIR_B, LOW);
    digitalWrite(STEP_B, HIGH);
    delayMicroseconds(period);
    digitalWrite(STEP_B, LOW);
  }
}
