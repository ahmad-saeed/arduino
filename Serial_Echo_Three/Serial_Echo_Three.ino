void setup() {
  Serial.begin(9600);
}

void loop() {
  int sa = Serial.available();
  if  ( sa > 0 ) {
    char sd[sa];
    for ( int a = 0 ; a < sa ; ++a )
    {
      sd[a] = char(Serial.read());
    }
    Serial.println(sd);
  }
}
