#include <SPI.h>
#include <SD.h>
String inStr;
char c;
File myFile;

void setup() {
  Serial.begin(9600);
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  //////////////////////////////////////////////////////////////////////////////////////////////  Remove last file
  SD.remove("ram.txt");
  //////////////////////////////////////////////////////////////////////////////////////////////  Writing
  myFile = SD.open("ram.txt", FILE_WRITE);
  myFile.println("130");
  myFile.println("020");
  myFile.println("010");
  myFile.close();  // must close between read and write
  //////////////////////////////////////////////////////////////////////////////////////////////  Reading
  myFile = SD.open("ram.txt", FILE_READ); // clode and re-open
  Serial.println(readNxt()); //////////////  1st line
  Serial.println(readNxt()); //////////////  2nd line

  myFile = SD.open("ram.txt", FILE_READ); // clode and re-open
  Serial.println(readNxt()); //////////////  1st line again

  myFile = SD.open("ram.txt", FILE_READ); // clode and re-open
  Serial.println(readln(3)); //////////////  read certain line
  myFile.close();

}

int readNxt() {
  inStr = "";
  c = myFile.read();
  while (c != '\n')
  {
    inStr += c;
    c = myFile.read();
  }
  return inStr.toInt();
}

int readln(int x) {
  int i = 1;
  for ( i = 1; i < x; i++)   // pass lines
  {
    c = myFile.read();
    while (c != '\n')
    {
      c = myFile.read();
    }
  }
  inStr = "";
  c = myFile.read();
  while (c != '\n')
  {
    inStr += c;
    c = myFile.read();
  }
  return inStr.toInt();
}




void loop() {
  // put your main code here, to run repeatedly:

}
