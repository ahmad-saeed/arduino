#include <IRremote.h>

#define RECV_PIN  11
#define GND_PIN 10
#define VCC_PIN 9

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  // IR Initialization 
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

  // Sensor Power Pins 
  pinMode(GND_PIN, OUTPUT);
  digitalWrite(GND_PIN, LOW);
  pinMode(VCC_PIN, OUTPUT);
  digitalWrite(VCC_PIN, HIGH);

  // Program Outputs//////////////////////////////////////////////////////
  pinMode(13, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    
    ////////////////////////////////////////////////////////////////
    Serial.println(results.value);
    if ( results.value == 4198438303) 
    {
      digitalWrite(13, !digitalRead(13));
    }    

    
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
