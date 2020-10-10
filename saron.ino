// include MIDI library
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
 
// read digital pins number 2, 4, 7, 8, 12, 13
int pushButton2 = 2;
int pushButton4 = 4;
int pushButton7 = 7;
int pushButton8 = 8;
int pushButton12 = 12;
int pushButton13 = 13;
 
// checks if the button is pressed
int buttonState2 = 0;
int buttonState4 = 0;
int buttonState7 = 0;
int buttonState8 = 0;
int buttonState12 = 0;
int buttonState13 = 0;
 
// play/stop notes in relation to buttons pressed
int note2 = 0;
int note4 = 0;
int note7 = 0;
int note8 = 0;
int note12 = 0;
int note13 = 0;
 
void setup() {
  MIDI.begin(4);
  // 115200 hairless MIDI
  Serial.begin(115200);
  pinMode(pushButton2, INPUT);
  pinMode(pushButton4, INPUT);
  pinMode(pushButton7, INPUT);
  pinMode(pushButton8, INPUT);
  pinMode(pushButton12, INPUT);
  pinMode(pushButton13, INPUT);
}
 
void loop() {
  // read state of buttons
  int buttonState2 = digitalRead(pushButton2);
  int buttonState4 = digitalRead(pushButton4);
  int buttonState7 = digitalRead(pushButton7);

  // Button 2
 
  // when button pressed:
  if (buttonState2 == HIGH) {
    // if note not playing
    if (note2 == 0) {
      // play note (note number, velocity, channel)
      // more info: http://arduinomidilib.sourceforge.net/a00001.html
      // MIDI notes chart http://www.phys.unsw.edu.au/jw/notes.html
      // 55 = G3, 127 = trigger note with max volume
      MIDI.sendNoteOn(60,127,1);
      MIDI.sendNoteOff(62,0,1);
      // note is playing
      note2 = 1;
    }
  // when button released
  } else {
    // if note playing
    if (note2 == 1) {
      // if playing - stop
      MIDI.sendNoteOff(60,0,1);
      MIDI.sendNoteOff(62,0,1);
    }
    // if button released note is off
    note2 = 0;
  }
 
  // Button 4
  if (buttonState4 == HIGH) {
    if (note4 == 0) {
      MIDI.sendNoteOn(62,127,1);
      note4 = 1;
    }
  } else {
    if (note4 == 1) {
      MIDI.sendNoteOff(62,0,1);
    }
    note4 = 0;
  }
 
  // Button 7
  if (buttonState7 == HIGH) {
    if (note7 == 0) {
      MIDI.sendNoteOn(64,127,1);
      note7 = 1;
    }
  } else {
    if (note7 == 1) {
      MIDI.sendNoteOff(64,0,1);
    }
    note7 = 0;
  }
 
  delay(1);
}
