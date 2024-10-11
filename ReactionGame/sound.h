#ifndef SOUND_H
#define SOUND_H
#include <arduino.h>

/*
  soundLed(byte) sets correct tone for each led number given as 0,1,2 or 3
  led number 0 corresponds to Note C3
  led number 1 => Note E3
  led number 2 => Note F3
  led number 3 => Note A3
  
  parameters:
  byte ledNumber is 0,1,2 or 3
*/
void soundLed(byte ledNumber);

/*
  noSound(void) subroutine mutes the buzzer
*/
void noSound(void);

/*
  soundAllLeds subroutine sets a chosen note for all leds
  Is this ever needed?
*/
void soundAllLeds(void);

/*
  soundGameEnd plays a melody based on player score:
  less than current High Score is a "fail",
  more is a "win",
  full score of 99 is worthy of Ode to Joy
*/
void soundGameEnd(int, int);

/*
  soundShow1() subroutine plays a melody, intended to replace show1() led routine
*/
void soundShow1(void);

/*
  soundShow2(int) subroutine plays rising notes, intended to replace show2() led routine

    Parameters:
  
  int rounds: This parameter determines how many times 0,1,2,3 sequence is shown 
*/
void soundShow2(int);

#endif