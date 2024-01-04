/**

Name: Smitkumar Saraiya
UCID: 30151834

CPSC 359 Computing Machinery 2 

Assignment 3

SNES Device Drivers

-- CODE IS SOLELY WRITTEN BY ME AND IS MY PROPERTY. IF YOU WISH TO USE THIS CODE ANYWHERE THEN EMAIL ME AT xgongiv27@gmail.com ** weird email but it works
*/

#include "gpio.h"
#include "uart.h"
#include "snes.h"

// Pins that will be used in the read and write process for GPIO
#define CLK 11
#define LAT 9
#define DAT 10

// Void method to initialize GPIO pin for Input of Output
// Takes an integer pin to initilise and integer func to assign to the pin
// func is either 0 for input or 1 for output
void init_gpio(int pin, int func)
{
    unsigned int *gpio = (unsigned *) GPFSEL0;

    int index = pin / 10; 

    int bit_shift = (pin % 10) * 3;

    gpio[index] = (gpio[index] & ~(0b111 << bit_shift) ) | (func << bit_shift);

}

// Void mehtod that writes 1 or 0 to GPIO pin
// Takes an integer pin number and integer val to write to GPIO pin
void write_gpio(int pin_number, int val)
{
    if (val == 1)
    {
        // Write 1 to pin number
        (*GPSET0) = 1 << pin_number;        
    } else {
        // Write 0 to pin number
        (*GPCLR0) = 1 << pin_number;
    }

}


// Method to read from gpio pins.
// takes a pin number as parameter
// returns an integer
int read_gpio(int pin_number)
{
    // return value at GPLEV0 register that is rightshift by pin number then AND with 1
     return ((*GPLEV0) >> pin_number) & 1; 
}

// Method to initial SNES lines for output or input operation modes
void init_snes_lines() {

    // Initialise clock line to output
    init_gpio(CLK, 0);
    init_gpio(CLK, 1);

    // Initialise latch line to output
    init_gpio(LAT, 0);
    init_gpio(LAT, 1);

    // Initialise data line to input
    init_gpio(DAT, 0);

}


// Method to read from snes controller
// returns unsigned type

unsigned read_snes() {

    // Array to store button inputs
    unsigned int buttons[16];

    // Write 1 to clock and latch line to synchronize core with controller
    write_gpio(CLK, 1);
    write_gpio(LAT, 1);

    // Sleep for 12 microseconds
    sleep_microseconds(12);

    // Write 0 to latch
    write_gpio(LAT, 0);
                
    // Read for 16 buttons because there are 16 possible button inputs from the SNES controller
    // 4 of which are always high
    for(unsigned int i = 0; i < 16; i++){

        // Sleep for 6 microseconds
        sleep_microseconds(6);
        // Write 0 to clock to cmplete one clock cycle
        write_gpio(CLK, 0);
        // Sleep for 6 microseconds
        sleep_microseconds(6);
        // Read from data line to a variable b of unsigned int type
        unsigned int b = read_gpio(DAT);
        // Store b in the array of buttons
        buttons[i] = b;
        // Write 1 to clock
        write_gpio(CLK, 1);
    }
    
    // Declare a register of type unsigned int.
    // This will be used to sample button pressed.
    unsigned int results = 0;
    
    // Write the value of the buttons (either 1 or 0 which means pressed or not pressed) to the register
    for(int i = 0; i < 12; i++){
            results |= buttons[i] << (12 - i -1);
    }

    // Return the register

    return results;
}


// Method to stall program execution for some microseconds
// takes an integer as a parameter
void sleep_microseconds(int ms)
{
    // Assign clock address to temp clock pointer
    unsigned int *clkpotr = (unsigned int *) CLK_REG;
    // Assign current time at clock address to temp variable
    unsigned int ctime = *clkpotr;
    // Add microseconds to current time to get target time
    unsigned int  targettime = ctime + ms;
    // Run loop for target time.
    // The value at the clock register will increment until it is more that target time so that execution continues afterwards.
    while (targettime > *clkpotr);
}

