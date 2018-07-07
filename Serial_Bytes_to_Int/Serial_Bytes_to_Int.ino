char a[4];
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  if (Serial.available())
  {
    Serial.readBytes(a, 4);
    int someInt = atoi(a);
    Serial.println(someInt);
  }
}
