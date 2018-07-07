String messageBody;
bool newMessage = false;
bool messageDelivered = true;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready!");
}

void loop() {
  if ( Serial.available() > 0 )  {
    newMessage = true;
    messageBody += char(Serial.read());
    messageDelivered = false;
    delay(3);  }         // This small delay is to give some time to Arduino to make sure that everything in the serial monitor has been written
  else  {
    newMessage = false;
    if ( newMessage == false & messageDelivered == false)    {
//    Serial.print("Serial Says: ");
      Serial.println(messageBody);
      messageDelivered = true;
      messageBody = "";    }
  }
}
