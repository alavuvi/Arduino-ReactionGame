# Arduino-ReactionGame

This was the first applied information technology project in Oulu University of Applied Science.
Rection game is an arduino based game written in c++.

How the game works:

The game starts when the user presses the start button. The leds start blinking in a random order in one second intervals. The user has to press the buttons in the corresponding order. The game speed increases after every ten led blinks. The 7-segment display shows user the current score. If the user presses the wrong button the game ends, game plays a short melody and the display shows the end score. Then you can try again. If user gets 99 points, the game will play Ode to joy. The game saves the high score in the arduino EEPROM memory.

Required components we used:
- 4 leds.
- 5 buttons
- 2 7-segment displays.
- 2 74Hc595 circuit boards.
- 4 breadboards.
- Jump wires.
- Resistors.
- Piezo buzzer.
- Arduino Uno R3.

See the game in action:
https://youtu.be/LEXwhmmTpp4

![60fca3d2-6a3b-474b-83bb-e0e01d506b23](https://github.com/user-attachments/assets/60c151c1-cb1d-4948-8b73-1c4cf9a40512)

Main responsibilities:

- Ville-Pekka Alavuotunki: Game logic - https://github.com/alavuvi/
- Tero Asilainen: Leds and sounds - https://github.com/TeroAsilainen/
- Erika Turtinen: Display - https://github.com/er1ka1
- Kata Niva: Buttons
