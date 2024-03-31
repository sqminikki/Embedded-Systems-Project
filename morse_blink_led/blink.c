#include <stdio.h>

#include "blink.h"

// Fill in the three functions to
// 1.) enable the output mode for onboard LED
// 2.) set the led to high
// 3.) set the led to low

// Write code to enable led

int DUO_LED = 25; //Initialize the GPIO pin for the LED
int wiringXValidGPIO(DUO_LED); //checks if the GPIO pin is valid

char *wiringXPIPlatform(void)


void initialize_led()
{
    // Code to initialize gpio port for LED
}

// Write code to turn led on
void turn_on_led()
{
    // Code to turn on the LED
}

// Write code to turn led off
void turn_off_led()
{
    // Code to turn off the LED
}

// This code that helps with testing
// no need to change unles you
// want to completely customize
void mock_initialize_led()
{
    printf("Mock Initialize LED\n");
}
void mock_led_high()
{
    printf("Mock LED ON\n");
}
void mock_led_low()
{
    printf("Mock LED OFF\n");
}