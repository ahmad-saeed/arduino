char x;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if ( Serial.available() > 0 )
  {
    x = char( Serial.read());
  }
  if ( x == '1')
  {
    digitalWrite(13, HIGH);
  }

  if ( x == '0')
  {
    digitalWrite(13, LOW);
  }
}
