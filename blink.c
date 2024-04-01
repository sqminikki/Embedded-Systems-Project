#include <stdio.h>

#include "blink.h"
#include "wiringx.h"

// Fill in the three functions to
// 1.) enable the output mode for onboard LED
// 2.) set the led to high
// 3.) set the led to low

// Write code to enable led
void initialize_led()
{
    // Code to initialize gpio port for LED
    // int pinMode(int pin, pinmode_t mode);
    // pinMode(DUO_LED, OUTPUT);
    // int digitalRead(int pin);
    // int digitalWrite(int pin, enum digital_value_t value);
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