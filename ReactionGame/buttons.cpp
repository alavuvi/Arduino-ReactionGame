#include "buttons.h"
#include "constants.h"


void initButtonsAndButtonInterrupts(void)
{
  // Set button pins as input with pull-up resistors
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);
  pinMode(button5Pin, INPUT_PULLUP);

  // Enable pin change interrupt for PCINT2
  PCICR |= (1 << PCIE2); 

  // Enable pin change interrupts for the specific pins
  PCMSK2 = B01000000; // Only the start button is in use to begin with
}





