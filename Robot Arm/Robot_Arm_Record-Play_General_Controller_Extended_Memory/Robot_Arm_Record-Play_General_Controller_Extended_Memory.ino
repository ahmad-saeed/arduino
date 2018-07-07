#define maxMemoryinBytes     2000000    /20  // it takes about 20 bytes per entry
#define delayRec             10
#define recordBtn            9
#define playBtn              10
#define LEDPlay              7
#define LEDRecord            8
#define servo_1              2
#define servo_2              3
#define servo_3              5
#define servo_4              6
#define playInLoop           true
#define commonCathodeLED     true


#include <Servo.h>
#include <SPI.h>
#include <SD.h>


File ram;
Servo servo1, servo2, servo3, servo4;
bool recording = false, playing = false, dataRecorded = false, justRecorded = false;
unsigned long i; String inStr; char c;

void setup() {
  pinMode(recordBtn, INPUT_PULLUP); pinMode(playBtn, INPUT_PULLUP);
  pinMode(LEDPlay, OUTPUT); digitalWrite(LEDPlay, !commonCathodeLED);
  pinMode(LEDRecord, OUTPUT); digitalWrite(LEDRecord, !commonCathodeLED);
  servo1.attach(servo_1); servo2.attach(servo_2); servo3.attach(servo_3); servo4.attach(servo_4);
  while (!SD.begin(4)) {};
}

void loop() {
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Buttons
  if ( digitalRead(recordBtn) == LOW ) {
    delay(200); /* debouncing*/    while ( digitalRead(recordBtn) == LOW) {} /* wait for button release*/
    recording = !recording;
    dataRecorded = true;

    if (recording)
    {
      ram.close();
      SD.remove("ram.txt");
      ram = SD.open("ram.txt", FILE_WRITE);
    }
    else {
      ram.println("777");
      ram.close();
      justRecorded = true;
    }
    playing = false;
    digitalWrite(LEDPlay, !commonCathodeLED);
    digitalWrite(LEDRecord, !digitalRead(LEDRecord));
  }
  else if ( digitalRead(playBtn) == LOW && !recording) {
    delay(200); /* debouncing*/    while ( digitalRead(playBtn) == LOW) {} /* wait for button release*/
    playing = !playing;
    if (justRecorded) ram = SD.open("ram.txt", FILE_READ);
    justRecorded = false;
    digitalWrite(LEDPlay, !digitalRead(LEDPlay));
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Functions
  if ( !playing ) {
    /////////////////////////////////////////////////////// controller code
    servo1.write(map(analogRead(0), 0, 1023, 0, 260));
    servo2.write(map(analogRead(1), 0, 1023, 0, 260));
    servo3.write(map(analogRead(2), 0, 1023, 0, 260));
    servo4.write(map(analogRead(3), 0, 1023, 40, 280));
    /////////////////////////////////////////////////////// recording
    if ( recording ) {
      ram.println(servo1.read());
      ram.println(servo2.read());
      ram.println(servo3.read());
      ram.println(servo4.read());
      delay(delayRec);
      i++;
      if ( i == maxMemoryinBytes ) {
        dataRecorded = true;
        recording = false;
        ram.println("777");
        ram.close();
        justRecorded = true;
        digitalWrite(LEDRecord, !commonCathodeLED);
        i = 0;
      }
    }
  }
  else if ( playing && dataRecorded ) {
    /////////////////////////////////////////////////////// playing
    int s = readln();
    if ( s == 777 ) {
      ram = SD.open("ram.txt", FILE_READ);
      if (!playInLoop) {
        playing = false;
        digitalWrite(LEDPlay, !commonCathodeLED);
      }
      return;
    }
    servo1.write(s);
    servo2.write(readln());
    servo3.write(readln());
    servo4.write(readln());
    delay(delayRec);

  }
}


int readln() {
  inStr = "";
  c = ram.read();
  while (c != '\n')
  {
    inStr += c;
    c = ram.read();
  }
  return inStr.toInt();
}
