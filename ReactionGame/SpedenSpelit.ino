#include "display.h"
#include "buttons.h"
#include "leds.h"
#include "SpedenSpelit.h"
#include "sound.h"
#include "constants.h"
#include <EEPROM.h>

// Use these 2 volatile variables for communicating between
// loop() function and interrupt handlers
volatile bool newTimerInterrupt = false;  // for timer interrupt handler
volatile int buttonNumber = -1;           // for buttons interrupt handler

//these variables are for random handler and timer ISR.
volatile int userNumbers[99]; // User inputs, max is 100
volatile int randomNumbers[99]; // random number, max is 100
volatile int userInputIndex = 0; // user input index
volatile int correctCount = 0; // keeps count of correct inputs
volatile int timerInterval = 15624; // set timer interval to 1 second (1hz)
volatile float changePercentage = 1.0; // counter for decreasing timer interval (in start it's 100%)
volatile int timerCount = 0; // keeps count of timer interrupts

//these variables are for highscore EEPROM
const int highScoreAddress = 0; 
volatile int highScore = 0;

//These variables are for button debounce
volatile bool buttonPressed = false; // flag for button press
unsigned long ledSetMillis = 0; // will store last time LED was set
unsigned long lastDebounceTime = 0; // last button press time
const unsigned long debounceDelay = 150; // Debounce time in milliseconds (probably have to change this for different buttons)
const long ledInterval = 250;  // interval at which to clear led (milliseconds)

void setup()
{
    Serial.begin(9600); // Initialize serial communication
    
    // use this when you first time start the game with new arduino board (sets the highscore to 0). Should be commented afterwards.
    // EEPROM.write(highScoreAddress, 0);

    //read high score from EEPROM
    highScore = EEPROM.read(highScoreAddress);

    // initialize modules
    initButtonsAndButtonInterrupts();
    initializeLeds();
    initializeDisplay();
    showResult(highScore);
    Serial.println(highScore);
    interrupts();
}

void loop() {
    unsigned long currentMillis = millis(); // For button debounce

    if (buttonPressed) {
      currentMillis = millis();
      Serial.print("Button pressed: "); //debug print
      Serial.println(buttonNumber); //debug print
      // check if enough time has passed after last button press
      // if too short time, print "Bouncing"
      if (currentMillis - lastDebounceTime < debounceDelay) {
      // lastDebounceTime = millis();
      Serial.println("Bouncing"); //debug print
      }
      else{
        if (buttonNumber == 4) { // Start the game, if buttonNumber == 4
          startTheGame();
                
          } else if (buttonNumber >= 0 && buttonNumber < 4) { // check the game
              checkGame(buttonNumber);
          }        
      }
      buttonNumber = -1;
      lastDebounceTime = millis(); // Save the last button press time
      buttonPressed = false; // clear the flag
    }

    if (newTimerInterrupt) {
      randomNumbers[timerCount] = random(0, 4); // Generate new random number
      ledSetMillis = millis();
      setLed(randomNumbers[timerCount]); // and activate corresponding led and sound
      soundLed(randomNumbers[timerCount]);
      
      Serial.print(timerCount); //debug print
      Serial.print(": "); //debug print
      Serial.println(randomNumbers[timerCount]); //debug print
      timerCount++; // Add to timeCount
      newTimerInterrupt = false; // Clear the flag 
    }

    currentMillis = millis();
    if (currentMillis - ledSetMillis >= ledInterval){
      clearAllLeds();
    }
}

void initializeTimer(void)
{
	// see requirements for the function from SpedenSpelit.h
    //Timer1 configuration
    noInterrupts(); // disable global interrupts  
    TCCR1A = 0;
    TCCR1B = 0;
    TCCR1B |= (1 << WGM12); // ctc mode
    TCCR1B |= (1 << CS12) | (1 << CS10); // prescaler 1024
    OCR1A = timerInterval; // Timer starts with 1 second (15624)

    //Timer1 interrupt
    TIMSK1 |= (1 << OCIE1A); // use timer1 COMPA interrupts

    interrupts(); // enable global interrupts

}
ISR(TIMER1_COMPA_vect)
  /*
  Communicate to loop() that it's time to make new random number.
  Increase timer interrupt rate after 10 interrupts.
  */
{    
    // randomNumbers[timerCount] = random(0, 4); // Generate new random number
  if (timerCount < 99) {
    newTimerInterrupt = true;

    if (timerCount % 10 == 0) //every tenth interrupt
    {
        // timerCount = 0; // set timer count to 0
        changePercentage *=0.9; //Reduce timer by 10%
        timerInterval = (int)(15624 * changePercentage); // New timer interval
        OCR1A = timerInterval; // update Timer1 interval
    } 
  } else {
    clearAllLeds();
  }
}


void checkGame(byte nbrOfButtonPush)
// see requirements for the function from SpedenSpelit.h
{
    // check if user input under 100
    if (userInputIndex < 99)
    {
        userNumbers[correctCount] = nbrOfButtonPush; // save user input to table

        // check if user input is correct
        if (nbrOfButtonPush != randomNumbers[correctCount])
        {
          userInputIndex = 101;
          Serial.println("Wrong input!");
          stopTheGame(); // stop the game if user input is incorrect
        }

        // if input is correct
        if (userInputIndex == correctCount)
        {
          if (userInputIndex == 98){ // if user input total is 99 stops the game
            correctCount++;
            stopTheGame();
            }
          else{
            correctCount++;
            userInputIndex++;
          }  
            showResult(correctCount); // call for display to show score
          //  Serial.print("Correct ");
          //  Serial.println(correctCount); // Debug-message to show score in serial monitor
        }
    }   
}

void initializeGame()
{
	// see requirements for the function from SpedenSpelit.h
    clearAllLeds();
    delay(1000); // Little delay in start of the game
    userInputIndex = 0; // Reset user input index
    correctCount = 0; // Reset correct count
    timerCount = 0; // Reset timerCount
    timerInterval = 15624; // set timer interval to 1 second (1hz)
    changePercentage = 1.0;
    TCNT1 = 0; // Reset Timer1
    PCMSK2 = B01111100;
    showResult(0);
    
}

void startTheGame()
{
    initializeGame(); // start initializegame() function
    initializeTimer();

    // newTimerInterrupt = true; // Start the timer
}

void stopTheGame()
{
  newTimerInterrupt = false; // stop the timer
  noInterrupts(); //No interrupts when changing ISR:s
  TIMSK1 = 0; // no timer1 COMPA interrupts

  PCMSK2 = B01000000;
  interrupts(); //Interrupts on
  showResults(); //Call showResults function
}

void showResults()
{
  // Show results and here we can add summary music and blink leds etc.
  Serial.println(correctCount); // debug message so show score in serial monitor
  showResult(correctCount);// Calls the 7-segment display to show results.
  soundGameEnd(correctCount, highScore); //call soundGameEnd with correctCount variable and higscore

  //check high score, if higher than current, update.
  if (correctCount > highScore) {
    highScore = correctCount;
    EEPROM.update(highScoreAddress, highScore);
    Serial.println("New high score"); //debug message
  }

}

// Button interrupt handler
ISR(PCINT2_vect) {
  // Some of the pins D2 - D5 has changed its state from 1 to 0 or 0 to 1, let's find out which.
  for(int i = 2; i < 7; i++) {
    byte luettu = digitalRead(i);

    if (luettu == LOW) {
      
      buttonNumber = i - 2;
      buttonPressed = true; 
    }
    
  }
}


