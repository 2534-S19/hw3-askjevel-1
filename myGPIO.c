/*
 * GPIO.c
 *
 *  Created on: Mar 2, 2020
 *      Author: Anders Skjeveland
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    P1DIR |= LP_LED1;
    P2DIR |= LED2_R;
    P2DIR |= LED2_G;
    P2DIR |= LED2_B;
    P2DIR |= BLED_R;
    P5DIR |= BLED_B;
    P2DIR |= BLED_G;


    P1DIR &= ~LAUNCHPAD_S1;
    P1DIR &= ~LAUNCHPAD_S2;
    P3DIR &= ~BOOSTER_S2;
    P5DIR &= ~BOOSTER_S1;

    P1REN |= LAUNCHPAD_S1;
    P1REN |= LAUNCHPAD_S2;
    P3REN |= BOOSTER_S2;
    P5REN |= BOOSTER_S1;

    P1OUT |= LAUNCHPAD_S1;
    P1OUT |= LAUNCHPAD_S2;
    P3OUT |= BOOSTER_S2;
    P5OUT |= BOOSTER_S1;

    turnOff_LaunchpadLED1();
    turnOff_LaunchpadLED2Red();
    turnOff_LaunchpadLED2Green();
    turnOff_LaunchpadLED2Blue();
    turnOff_BoosterpackLEDRed();
    turnOff_BoosterpackLEDGreen();
    turnOff_BoosterpackLEDBlue();

}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return ((P1IN & LAUNCHPAD_S1) == LAUNCHPAD_S1);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return ((P1IN & LAUNCHPAD_S2) == LAUNCHPAD_S2);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return ((P5IN & BOOSTER_S1) == BOOSTER_S1);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return ((P3IN & BOOSTER_S2) == BOOSTER_S2);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT = P1OUT |  LP_LED1;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT = P1OUT & ~LP_LED1;
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT = P2OUT | LED2_R;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT = P2OUT & ~LED2_R;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT = P2OUT | LED2_G;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT = P2OUT & ~LED2_G;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT = P2OUT | LED2_B;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT = P2OUT & ~LED2_B;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT = P2OUT | BLED_R;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT = P2OUT & ~BLED_R;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT = P2OUT | BLED_G;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT = P2OUT & ~BLED_G;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT = P5OUT | BLED_B;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT = P5OUT & ~BLED_B;
}
