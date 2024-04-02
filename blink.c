#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#include "blink.h"
#include <wiringx.h>

// #define LOW 0
// #define HIGH 1 << 24

// Fill in the three functions to
// 1.) enable the output mode for onboard LED
// 2.) set the led to high
// 3.) set the led to low

int DUO_LED = 25;
// Write code to enable led
void initialize_led()
{
    printf("Initialize LED\n");

    // Code to initialize gpio port for LED
    // Initialize WiringX library for the `duo`
    if(wiringXSetup("duo", NULL) == -1) 
    {
        // Release resources if there's an error
        // during intialization.
        wiringXGC();
        return;
    }
    printf("Setting up LED\n");
    pinMode(DUO_LED, PINMODE_OUTPUT);
}

// Write code to turn led on
void turn_on_led()
{
    // Code to turn on the LED
    digitalWrite(DUO_LED, HIGH);
}

// Write code to turn led off
void turn_off_led()
{
    // Code to turn off the LED
    digitalWrite(DUO_LED, LOW);
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