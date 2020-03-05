/*
 * homework3.h
 *
 *  Created on: Mar 4, 2020
 *      Author: Anders Skjeveland
 */



#ifndef HOMEWORK3_H_
#define HOMEWORK3_H_

// This function initializes the board by turning off the Watchdog Timer.
void initBoard();
// This function indexes a count value to an LED color on Launchpad LED2.
void changeLaunchpadLED2(unsigned int count);
// This function indexes a count value to an LED color on the Boosterpack LED.
void changeBoosterpackLED(unsigned int count);
// This function serves as a debounce state machine for Boosterpack button S1
bool fsmBoosterpackButtonS1(unsigned char buttonhistory);


// TODO: Define any constants that are local to homework.c using #define
#define PRESSED 0
#define UNPRESSED 1

#endif /* HOMEWORK3_H_ */
