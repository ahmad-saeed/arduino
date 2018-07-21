#include <SoftwareSerial.h>
SoftwareSerial espSerial(2, 3); // RX, TX

void sendRequest (String msg, String successMsg ="")
{
  String x = "";
  bool requestSent = false;
  while ( x != "OK")
  {
    if (!requestSent) 
    {
      espSerial.print(msg);
      espSerial.print("\r\n");
      requestSent = true;
    }
    if (espSerial.available())
    {
      requestSent = false;
      x = espSerial.readString();
      x = x.substring(x.length()-4,x.length()-2);
    }
  }
  if (successMsg != "") Serial.println(successMsg);
}

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Serial Monitor Initialized");
  espSerial.begin(115200);
  while (!espSerial); 
  Serial.println("ESP Serial Initialized");
  
  
  sendRequest("AT+CWMODE=1");
  sendRequest("AT+CWJAP=\"uncleGrandpa\",\"asdfqwer\"","Wifi Connected");  
  sendRequest("AT+CIPMUX=1","Multiple Connections Enabled");

  
  sendRequest("AT+CIPSTART=4,\"TCP\",\"api.twitter.com\",443","Connected to Twitter.com"); 
  //sendRequest("AT+CIPSTART=4,\"TCP\",\"192.168.1.4\",1025","Connected to Local Server");
  //sendRequest("AT+CIPSEND=4,346","Approved send request");
  espSerial.print("AT+CIPSEND=4,365");
  espSerial.print("\r\n");
  delay(2000);
  espSerial.println("POST /oauth2/token HTTP/1.1");
  espSerial.println("Content-Length: 29");
  espSerial.println("Accept-Encoding: identity");
  espSerial.println("Connection: close");
  espSerial.println("User-Agent: MyTwitterApp");
  espSerial.println("Host: api.twitter.com");
  espSerial.println("Content-Type: application/x-www-form-urlencoded;charset=UTF-8");
  espSerial.println("Authorization: Basic TTB2ZVNucWkyRlJNZ1BMWnI3UmJEdEVEdTpSdG5Mc1prUjhldDRMcWx4Tll3TTBxY3ptYWdmczF1TGxaWThxOHdQNDhzbVNGbTFqMg==");
  espSerial.println();
  espSerial.println("grant_type=client_credentials");
  
}

void loop() {
  if (espSerial.available())
  {
    Serial.println(espSerial.readString());
  }
  if (Serial.available())
  {
    espSerial.print(Serial.readString());
    //espSerial.print("\r\n");
  }

}
