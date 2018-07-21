#include <SoftwareSerial.h>
SoftwareSerial espSerial(3, 2); // RX, TX

int sendRequest (String msg, String expectedLastPhrase, String successMsg = "")
{
  String x = "";
  bool requestSent = false;
  expectedLastPhrase = expectedLastPhrase;
  while ( !x.endsWith(expectedLastPhrase))
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
    }
  }
  if (successMsg != "") Serial.println(successMsg);
}

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Serial Monitor Initialized");
  espSerial.begin(9600);    // Best option for software serial. Use AT+IPR=9600 to change.
  while (!espSerial);
  Serial.println("ESP Serial Initialized");


  sendRequest("AT+CWMODE=2", "OK\r\n", "Access Point ON");
  sendRequest("AT+CIPMUX=1", "OK\r\n", "Multiple Connections Enabled");
  sendRequest("AT+CIPSERVER=1,80", "OK\r\n", "Server Estblished at Port 80");
}

void loop() {
  if (espSerial.available())
  {
    String msg = espSerial.readString();

    if (msg.endsWith("F"))      Serial.println("Forward");
    else if (msg.endsWith("B")) Serial.println("Backward");
    else if (msg.endsWith("L")) Serial.println("Left");
    else if (msg.endsWith("R")) Serial.println("Right");
    else if (msg.endsWith("S")) Serial.println("Stop");
    else if ((msg.substring(2, 3) == ("C") && msg.substring(8, 9) == ("T")))
    {
      String clientID = msg.substring(0, 1);
      if (clientID != "0") return 0;
      Serial.println("Client Connected");
      //delay(2000);
      sendRequest("AT+CIPSEND=0,759", "> ", "Sending Data");
      espSerial.print("<html>");
      espSerial.print("<body>");
      espSerial.print("<form action=\"http://192.168.4.1:80\" method=\"POST\">");
      espSerial.print("<div><input type=\"text\" id=\"name\" name=\"ORDER\" value=\"F\" hidden /></div>");
      espSerial.print("<button>^</button></form>");
      espSerial.print("<form action=\"http://192.168.4.1:80\" method=\"POST\">");
      espSerial.print("<div><input type=\"text\" id=\"name\" name=\"ORDER\" value=\"B\" hidden /></div>");
      espSerial.print("<button>v</button></form>");
      espSerial.print("<form action=\"http://192.168.4.1:80\" method=\"POST\">");
      espSerial.print("<div><input type=\"text\" id=\"name\" name=\"ORDER\" value=\"R\" hidden /></div>");
      espSerial.print("<button>></button></form>");
      espSerial.print("<form action=\"http://192.168.4.1:80\" method=\"POST\">");
      espSerial.print("<div><input type=\"text\" id=\"name\" name=\"ORDER\" value=\"L\" hidden /></div>");
      espSerial.print("<button><</button></form>");
      espSerial.print("<form action=\"http://192.168.4.1:80\" method=\"POST\">");
      espSerial.print("<div><input type=\"text\" id=\"name\" name=\"ORDER\" value=\"S\" hidden /></div>");
      espSerial.print("<button>S</button></form>");
      espSerial.print("</html>");
      //delay(2000);
      Serial.println("Data Sent");
      //delay(2000);
      espSerial.print("AT+CIPCLOSE=0");
      espSerial.print("\r\n");
    }
    else
    {
      //Serial.print(msg);  // uncomment for debugging
    }

  }
  if (Serial.available())
  {
    espSerial.print(Serial.readString());
    espSerial.print("\r\n");
  }

}
