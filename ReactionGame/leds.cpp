#include "leds.h"
#include "sound.h"
#include "constants.h"


void initializeLeds()
{
// see requirements for this function from leds.h

  
// set each pin mode to output
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void setLed(byte ledNumber)
{
// see requirements for this function from leds.h
// set single LED HIGH based on ledNumber
  switch (ledNumber){
    case 0:
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      break;
    case 1:
      digitalWrite(ledPin0, LOW);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      break;
    case 2:
      digitalWrite(ledPin0, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      break;
    case 3:
      digitalWrite(ledPin0, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      break;
  }
}


void clearAllLeds()
{
// see requirements for this function from leds.h
// set all LEDs LOW
  digitalWrite(ledPin0, LOW);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
}

void setAllLeds()
{
// see requirements for this function from leds.h
// set all LEDs HIGH
  digitalWrite(ledPin0, HIGH);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
}


void show1()
{
// see requirements for this function from leds.h
// set LEDs HIGH in binary representation of numbers 0 - 15
// use variable showDelay to set time (in ms) LED is HIGH and LOW
int showDelay = 500;

// loop indefinitely
while(1){
// 0
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);
// "show" 0 for full duration 
delay(showDelay);

// 1
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, HIGH);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 2
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, HIGH);
digitalWrite(ledPin3, LOW);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 3
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, HIGH);
digitalWrite(ledPin3, HIGH);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 4
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, HIGH);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 5
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, HIGH);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, HIGH);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 6
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, HIGH);
digitalWrite(ledPin2, HIGH);
digitalWrite(ledPin3, LOW);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 7
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, HIGH);
digitalWrite(ledPin2, HIGH);
digitalWrite(ledPin3, HIGH);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 8
digitalWrite(ledPin0, HIGH);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 9
digitalWrite(ledPin0, HIGH);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, HIGH);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 10
digitalWrite(ledPin0, HIGH);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, HIGH);
digitalWrite(ledPin3, LOW);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 11
digitalWrite(ledPin0, HIGH);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, HIGH);
digitalWrite(ledPin3, HIGH);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 12
digitalWrite(ledPin0, HIGH);
digitalWrite(ledPin1, HIGH);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 13
digitalWrite(ledPin0, HIGH);
digitalWrite(ledPin1, HIGH);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, HIGH);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 14
digitalWrite(ledPin0, HIGH);
digitalWrite(ledPin1, HIGH);
digitalWrite(ledPin2, HIGH);
digitalWrite(ledPin3, LOW);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);

// 15
digitalWrite(ledPin0, HIGH);
digitalWrite(ledPin1, HIGH);
digitalWrite(ledPin2, HIGH);
digitalWrite(ledPin3, HIGH);
delay(showDelay);
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(showDelay);
}
}

void show2(int rounds)
{
  // show2delay has the initial delay time
  int show2Delay = 1000;
  for (int i = 1; i <= rounds; i++){
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    delay((show2Delay/i)+1);  // divide the delay to increase rate each round, + 1 to accomodate rounds > 1000
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    delay((show2Delay/i)+1);
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    delay((show2Delay/i)+1);
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    delay((show2Delay/i)+1);
    /*digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    delay((show2Delay/i)+1);
    */
  }
// see requirements for this function from leds.h  
}