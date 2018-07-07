#define memory               356
#define delayRec             20
#define recordBtn            9
#define playBtn              10
#define LEDPlay              12
#define LEDRecord            13
#define servo_1              2
#define servo_2              3
#define servo_3              4
#define servo_4              5
#define playInLoop           false
#define commonCathodeLED     true

#include <Servo.h>
Servo servo1, servo2, servo3, servo4;
uint8_t track1[memory], track2[memory], track3[memory], track4[memory], i;
bool recording = false, playing = false;

void setup() {
  track1[0] = 255;
  pinMode(recordBtn, INPUT_PULLUP); pinMode(playBtn, INPUT_PULLUP);
  pinMode(LEDPlay, OUTPUT); digitalWrite(LEDPlay, !commonCathodeLED);      
  pinMode(LEDRecord, OUTPUT); digitalWrite(LEDRecord, !commonCathodeLED);
  servo1.attach(servo_1); servo2.attach(servo_2); servo3.attach(servo_3); servo4.attach(servo_4);
}

void loop() {
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Buttons
  if ( digitalRead(recordBtn) == LOW ) {
    delay(100); /* debouncing*/    while ( digitalRead(recordBtn) == LOW) {} /* wait for button release*/
    if (recording == true) track1[i] = 255;
    recording = !recording;
    playing = false;
    digitalWrite(LEDPlay, !commonCathodeLED);
    digitalWrite(LEDRecord, !digitalRead(LEDRecord));
    i = 0;
  }
  else if ( digitalRead(playBtn) == LOW && !recording) {
    delay(100); /* debouncing*/    while ( digitalRead(playBtn) == LOW) {} /* wait for button release*/
    playing = !playing;
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
      track1[i] = servo1.read();
      track2[i] = servo2.read();
      track3[i] = servo3.read();
      track4[i] = servo4.read();
      delay(delayRec);
      i += 1;
      if ( i == memory - 1 ) {
        recording = false;
        track1[i] = 255;
        digitalWrite(LEDRecord, !commonCathodeLED);
        i = 0;
      }
    }
  }
  else if ( playing && track1[i] != 255) {
    /////////////////////////////////////////////////////// playing
    servo1.write(track1[i]);
    servo2.write(track2[i]);
    servo3.write(track3[i]);
    servo4.write(track4[i]);
    delay(delayRec);
    i += 1;
    if ( track1[i] == 255 ) {
      i = 0;
      if (!playInLoop) {
        playing = false;
        digitalWrite(LEDPlay, !commonCathodeLED);
      }
    }
  }
}
