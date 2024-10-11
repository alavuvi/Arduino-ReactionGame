#include "display.h"


void initializeDisplay(void)
{
  // Assign the pins to output mode
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  // Set all pins to LOW state 
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);
}


void writeByte(uint8_t num, bool last)
{
  
  // turn off the output so the pins don't light up while you're shifting bits:
  digitalWrite(latchPin, LOW);  
  //shift out the bits:
  shiftOut(dataPin, clockPin, MSBFIRST, number[num]);
  if(last == true) {
  // turn on the output so the LEDs can light up:
  digitalWrite(latchPin, HIGH);
  }
}

void writeHighAndLowNumber(uint8_t tens,uint8_t ones)
{
  writeByte(tens, false); 
  writeByte(ones, true);
}

void showResult(byte result)
{
  uint8_t tens = result / 10; //kymmenet
  uint8_t ones = result % 10; //ykkoset

  writeHighAndLowNumber(tens, ones);
}

