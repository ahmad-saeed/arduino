void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

Serial.print(cos(x*3.14/180));
Serial.print(acos(.7)*180/3.14);
delay(10000);
}
