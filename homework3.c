#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

typedef enum {up, down} debounce_state_t;
typedef enum{off, red, green, yellow, blue, magenta, cyan, white} led_state_t;

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned int button = 0;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if(timer0Expired() == true){
            count0++;
        }


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if(timer1Expired() == true){
            button = fsmBoosterpackButtonS1(button);
        }


        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        fsmBoosterpackButtonS1(button);


        // TODO: If a completed, debounced button press has occurred, increment count1.
        if(fsmBoosterpackButtonS1(button) == true){
            count1++;
        }


    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    static led_state_t led = off;

    if(count == 1){
        led = red;
    }
    if(count == 2){
        led = green;
    }
    if(count == 3){
        led = yellow;
    }
    if(count == 4){
        led = blue;
    }
    if(count == 5){
        led = magenta;
    }
    if(count == 6){
        led = cyan;
    }
    if(count == 7){
        led = white;
    }
    if(count == 8){
        led = off;
        count = 0;
    }


    switch(led){
    case off:
        turnOff_LaunchpadLED2Red();
        count = 1;
        break;
    case red:
        turnOn_LaunchpadLED2Red();
        count = 2;
        break;
    case green:
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        count = 3;
        break;
    case yellow:
        turnOn_LaunchpadLED2Red();
        count = 4;
        break;
    case blue:
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();
        count = 5;
        break;
    case magenta:
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Blue();
        count = 6;
        break;
    case cyan:
        turnOff_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        count = 5;
        break;
    case white:
        turnOn_LaunchpadLED2Red();
        count = 0;
        break;
    }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
        static led_state_t led = off;

    switch(led){
    case off:
        turnOff_BoosterpackLEDRed();
        if(count == 1){
            led = red;
        }
        else
            led = off;
        break;
    case red:
        turnOn_BoosterpackLEDRed();
        if(count == 2){
            led = green;
        }
        break;
    case green:
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        if(count == 3){
            led = yellow;
        }
        break;
    case yellow:
        turnOn_BoosterpackLEDRed();
        if(count == 4){
            led = blue;
        }
        break;
    case blue:
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
        if(count == 5){
            led = magenta;
        }

        break;
    case magenta:
        turnOn_BoosterpackLEDRed();
        turnOn_BoosterpackLEDBlue();
        if(count == 6){
            led = cyan;
        }

        break;
    case cyan:
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        if(count == 7){
            led = white;
        }

        break;
    case white:
        turnOn_BoosterpackLEDRed();
        led = off;

        break;
    }
}


// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    bool pressed = false;

    static debounce_state_t button = up;

    switch(button){
    case up:
        pressed = false;
        if(checkStatus_BoosterpackS1() == PRESSED){
            button = down;
        }
        else
            button = up;
        break;
    case down:
        pressed = true;
        if(checkStatus_BoosterpackS1() == PRESSED){
            button = down;
        }
        else
            button = up;

        break;
    }

    return pressed;
}
