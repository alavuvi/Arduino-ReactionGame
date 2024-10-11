#include "sound.h"
#include "constants.h"
#include "leds.h"


  

void soundLed(byte ledNumber)
{
// set tone based on ledNumber
// add duration if necessary
int soundLedDuration = 100;
  switch (ledNumber){
    case 0:
      tone(soundPin, NOTE_C3, soundLedDuration);
      break;
    case 1:
      tone(soundPin, NOTE_E3, soundLedDuration);
      break;
    case 2:
      tone(soundPin, NOTE_F3, soundLedDuration);
      break;
    case 3:
      tone(soundPin, NOTE_A3, soundLedDuration);
      break;
  }
}


void noSound()
{
// mute the buzzer
  noTone(soundPin);
}

void soundAllLeds()
{
// play low C when all LEDs are HIGH
  tone(soundPin, NOTE_C2);
}

void soundGameEnd(int score, int limit){
  // if score is less than current High Score, aka limit, play a descending tritone
  if (score < limit){
    setAllLeds();
    tone(soundPin, NOTE_F2);
    delay(500);
    tone(soundPin, NOTE_B1, 2000);
    delay(2000);
    clearAllLeds();
  }

  // if score is between the High Score and 98, play a happy little tune
  else if (score >= limit && score < 99){
    setLed(0);
    tone(soundPin, NOTE_C3);
    delay(200);
    setLed(1);
    tone(soundPin, NOTE_E3);
    delay(200);
    setLed(2);
    tone(soundPin, NOTE_G3);
    delay(200);
    setLed(3);
    tone(soundPin, NOTE_C4, 200); // this note is shorter than the delay, also known as staccato
    delay(400);
    setLed(2);
    tone(soundPin, NOTE_G3);
    delay(200);
    setAllLeds();
    tone(soundPin, NOTE_C4, 800);
    delay(800);
    clearAllLeds();
  }

  // and full score is Ode to Joy by Beethoven
  else if (score == 99){
    // notes in the melody:
    int melody2[] = {
      NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4,
      NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
      NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,
      NOTE_E4, NOTE_D4, NOTE_D4, 0,

      NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4,
      NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
      NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,
      NOTE_D4, NOTE_C4, NOTE_C4,
    };
    // note durations: 4 = quarter note, 8 = eighth note, etc.:

    float melody2Durations[] = {
      4, 4, 4, 4,
      4, 4, 4, 4,
      4, 4, 4, 4,
      2.67, 8, 2.67, 8,

      4, 4, 4, 4,
      4, 4, 4, 4,
      4, 4, 4, 4,
      2.67, 8, 2

    };
    
    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 31; thisNote++) {
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1600 / melody2Durations[thisNote];

      tone(soundPin, melody2[thisNote], noteDuration);
      
      // change LED based on remainder of note index
      // except that one rest
      if (thisNote == 15){
        clearAllLeds();
      }
      // and set all LEDs on the last note
      else if (thisNote == 30){
        setAllLeds();
      }
      else{
        setLed(thisNote % 4);
      }
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 25% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.25;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noSound();
    }

  }
}







void soundShow1()
{
/*
  Based on example code in the public domain by Tom Igoe.
  https://www.arduino.cc/en/Tutorial/Tone

  Song composed by Tero Asilainen & Mikko Isomaa
*/

// notes in the melody:
// adjust so that each quarter note pulse has a note, despite original rhythm being tresillo
// also each pulse should have a sixteenth note prior to it, to turn all LEDs LOW
int melodyShow1[] = {
  NOTE_DS4, NOTE_G4, NOTE_G4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_GS4, NOTE_G4, NOTE_DS4, NOTE_G4, NOTE_G4,

  NOTE_AS4, NOTE_DS5, NOTE_DS5, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_F5, NOTE_DS5, NOTE_D5, NOTE_AS4, NOTE_AS4,

  NOTE_F4, NOTE_D5, NOTE_D5, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_DS5, NOTE_D5, NOTE_AS4, NOTE_G4, NOTE_G4,

  NOTE_DS4, NOTE_GS4, NOTE_GS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_G4, NOTE_AS4, NOTE_D5, NOTE_DS5, NOTE_DS5

};
// note durations: 4 = quarter note, 8 = eighth note, etc.:

float show1Durations[] = {
  5.33, 16, 8, 16, 16, 8, 16, 16, 8, 16, 16,
  5.33, 16, 8, 16, 16, 8, 16, 16, 8, 16, 16,
  5.33, 16, 8, 16, 16, 8, 16, 16, 8, 16, 16,
  5.33, 16, 8, 16, 16, 8, 16, 16, 8, 16, 16
};

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 44; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 2000 / show1Durations[thisNote];
    tone(soundPin, melodyShow1[thisNote], noteDuration);

    // handle the LEDs with this switch case by note index
    switch (thisNote){
    // all of these cases "fall through" to clearAllLeds
    case 0:
    case 4:
    case 7:
    case 10:
    case 12:
    case 15:
    case 18:
    case 21:
    case 23:
    case 26:
    case 29:
    case 32:
    case 34:
    case 37:
    case 40:
      // 0
      clearAllLeds();
      break;

    case 2:
      // 1
      digitalWrite(ledPin0, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      break;
    case 5:
      // 2
      digitalWrite(ledPin0, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      break;
    case 8:
      // 3
      digitalWrite(ledPin0, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      break;
    case 11:
      // 4
      digitalWrite(ledPin0, LOW);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      break;
    case 13:
      // 5
      digitalWrite(ledPin0, LOW);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      break;
    case 16:
      // 6
      digitalWrite(ledPin0, LOW);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      break;
    case 19:
      // 7
      digitalWrite(ledPin0, LOW);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      break;
    case 22:
      // 8
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      break;
    case 24:
      // 9
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      break;
    case 27:
      // 10
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      break;
    case 30:
      // 11
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      break;
    case 33:
      // 12
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      break;
    case 35:
      // 13
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      break;
    case 38:
      // 14
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      break;
    case 41:
      // 15
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      break;
    }

    // to distinguish the notes, set a minimum time between them.
    // note duration 1980*1.01 keeps the correct tempo of 120 bpm:
    int pauseBetweenNotes = noteDuration * 1.01;
    delay(pauseBetweenNotes);
    
  }
  // stop the tone playing:
  noSound();
}

void soundShow2(int rounds)
{
  // C major arpeggio
  // show2delay has the initial delay time
  int show2Delay = 1000;
  for (int i = 1; i <= rounds; i++){
    tone(soundPin, NOTE_C3);
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    delay((show2Delay/i)+1);// divide the delay to increase rate each round, + 1 to accomodate rounds > 1000
    
    tone(soundPin, NOTE_E3);
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    delay((show2Delay/i)+1);

    tone(soundPin, NOTE_G3);
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    delay((show2Delay/i)+1);

    tone(soundPin, NOTE_C4);
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    delay((show2Delay/i)+1);

    noTone(soundPin);
    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    delay((show2Delay/i)+1);
  } 
}