#include <Servo.h>
Servo servo1, servo2, servo3, servo4;
uint8_t track1[240], track2[240], track3[240], track4[240];
uint8_t i = 0, recordBtn = 9, playBtn = 10, saveBtn = 11, LEDPlay = 12, LEDRecord = 13;
bool recording = false, playing = false;
int delayRec = 60;


void setup() {
  servo1.attach(2); servo2.attach(3); servo3.attach(4); servo4.attach(5);
  track1[239] = 255; track2[239] = 255; track3[239] = 255; track4[239] = 255;
  track1[0] = 255; track2[0] = 255; track3[0] = 255; track4[0] = 255;
  pinMode(recordBtn, INPUT); pinMode(playBtn, INPUT); pinMode(saveBtn, INPUT);
  pinMode(LEDPlay, OUTPUT); digitalWrite(LEDPlay, HIGH);
  pinMode(LEDRecord, OUTPUT); digitalWrite(LEDRecord, HIGH);
}

void loop() {
  if ( digitalRead(recordBtn) == HIGH ) {
    delay(100); // debouncing
    while ( digitalRead(recordBtn) == HIGH) {} // wait for button release

    if ( recording == false) {
      recording = true;
      playing = false;
      i = 0;
      digitalWrite(LEDRecord, LOW);
    }
    else if ( recording == true) {
      recording = false;
      playing = false;
      track1[i] = 255;
      track2[i] = 255;
      track3[i] = 255;
      track4[i] = 255;
      i = 0;
      digitalWrite(LEDRecord, HIGH);
    }
  }

  if ( digitalRead(playBtn) == HIGH && recording == false) {
    delay(100); // debouncing
    while ( digitalRead(playBtn) == HIGH) {} // wait for button release

    if ( playing == false) {
      recording = false;
      playing = true;
      digitalWrite(LEDPlay, LOW);
      if (track1[i] == 255) {
        i = 0;
      }
    }
    else if ( playing == true) {
      recording = false;
      playing = false;
      digitalWrite(LEDPlay, HIGH);
    }
  }

  // playing
  if ( recording == false && playing == true && i < 240 && track1[i] != 255  ) {
    servo1.write(track1[i]);
    servo2.write(track2[i]);
    servo3.write(track3[i]);
    servo4.write(track4[i]);
    delay(delayRec);
    i += 1;
  }

  // recording & animating
  else  if ( recording == true && playing == false && i < 240 ) {
    track1[i] = map(analogRead(0), 0, 1023, 0, 260);
    servo1.write(track1[i]);
    track2[i] = map(analogRead(1), 0, 1023, 0, 260);
    servo2.write(track2[i]);
    track3[i] = map(analogRead(2), 0, 1023, 0, 260);
    servo3.write(track3[i]);
    track4[i] = map(analogRead(3), 0, 1023, 40, 280);
    servo4.write(track4[i]);
    delay(delayRec);
    i += 1;
  }
  else { // move without recording or playing
    digitalWrite(LEDPlay, HIGH);
    digitalWrite(LEDRecord, HIGH);
    servo1.write(map(analogRead(0), 0, 1023, 0, 260));
    servo2.write(map(analogRead(1), 0, 1023, 0, 260));
    servo3.write(map(analogRead(2), 0, 1023, 0, 260));
    servo4.write(map(analogRead(3), 0, 1023, 40, 280));
  }
}
