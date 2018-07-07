String messageBody;
bool messageDelivered = true;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready!");
}

void loop() {
  if ( Serial.available() > 0 )  {
    messageBody += char(Serial.read());
    messageDelivered = false;
    delay(3); } // The code is slowed by a fraction of a second. Some Arduinos are so fast. The delay is to make sure that nothing is remaining in the serial monitor.
  else  {
    if (messageDelivered == false)    {
//      Serial.print("Serial Says: ");
      Serial.println(messageBody);
      messageDelivered = true;
      messageBody = "";    
    
  }
  }
}

