# Blink LED using GPIO: The “Hello World” of Embedded Systems
## Introduction
The Blink LED project is a basic introduction to embedded systems programming. It involves turning an LED on and off in a regular pattern, using a General Purpose Input/Output (GPIO) pin of a microcontroller.

### Objective: Learn how to set up a development environment, write a basic program, and control an LED using a GPIO pin.

# Programming the Microcontroller
## 1. WiringX General API
Platform information

`char *wiringXPlatform(void)

// Example Usage`
char *platform_info = wiringXPlatform(void);
printf("platform info: %s\n", platform_info);

Validate if a GPIO pin is available.

`int DUO_LED = 25;
int wiringXValidGPIO(DUO_LED);`

// Example Usage
int pin_available = wiringXValidGPIO(int pin);
if (pin_available != 0) {
    // exit
}
To initialize the WiringX library for configuring and managing GPIO pins, the fixed syntax for Duo is as follows
int wiringXSetup(char *name, ...)

// Example Usage
wiringXSetup("duo", NULL);
Delay in Microseconds
void delayMicroseconds(unsigned int ms)

// Example Usage, sleep for 1s
delayMicroseconds(1000000);
Release system resources.
int wiringXGC(void)

// Example Usage
wiringXGC();
2. WiringX GPIO API
Set the pin working mode
int pinMode(int pin, pinmode_t mode)

// Set the working mode for the specified pin
// where pin is the pin number, and mode can be
//   PINMODE_INPUT input mode
//   PINMODE_OUTPUT output mode
//   PINMODE_INTERRUPT interrupt mode

// Example Usage
int DUO_LED = 25;
pinMode(DUO_LED, PINMODE_OUTPUT);
int digitalRead(int pin)

// Read the input value of the specified pin
// The `return` value is HIGH or LOW
int DUO_LED = 25;
int gpio_pin_val = digitalRead(DUO_LED);
printf("val: %d\n", gpio_pin_val);
int digitalWrite(int pin, enum digital_value_t value)

// Set the output value for the specified pin.
// value can be
//    HIGH high level
//    LOW low level

int DUO_LED = 25;
digitalWrite(DUO_LED, HIGH);
1. Example code in C
We’ll use the internal LED for now.
#include <stdio.h>
#include <unistd.h>

// WiringX API header
#include <wiringx.h>

int main() {
    // Internal LED is at pin 25.
    int DUO_LED = 25;

    // Initialize WiringX library for the `duo`
    if(wiringXSetup("duo", NULL) == -1) {
        // Release resources if there's an error
        // during intialization.
        wiringXGC();
        return -1;
    }

    // Verify the pin is available
    if(wiringXValidGPIO(DUO_LED) != 0) {
        printf("Invalid GPIO %d\n", DUO_LED);
        wiringXGC();
        return -1;
    }


    // Initialize the GPIO pin as PINMODE_OUTPUT
    pinMode(DUO_LED, PINMODE_OUTPUT);

    while(1) {
        printf("Duo LED GPIO (wiringX) %d: High\n", DUO_LED);
        digitalWrite(DUO_LED, HIGH);
        // can use sleep as well
        delayMicroseconds(1000000);

        printf("Duo LED GPIO (wiringX) %d: Low\n", DUO_LED);
        digitalWrite(DUO_LED, LOW);
        delayMicroseconds(1000000);
    }

    return 0;
}
Interacting with sysfs
In addition to using dedicated libraries for GPIO control in embedded systems, another approach is using the sysfs interface on Linux-based systems. sysfs exposes GPIO pins as files in the filesystem, allowing control through simple file operations. This method is particularly useful for scripting and automating hardware control without needing specific libraries.

Objective
Understand how to control GPIO pins using the sysfs interface on Linux-based embedded systems.

Sysfs GPIO Control
1. Accessing GPIO Pins
GPIO pins are accessed in sysfs at /sys/class/gpio. Each GPIO pin is represented as a directory, e.g., /sys/class/gpio/gpio440 for GPIO440.

GPIO0 corresponds to the linux group number 480
GPIO1 corresponds to the linux group number 448
GPIO2 corresponds to the linux group number 416
GPIO3 corresponds to the linux group number 384
PWR_GPIO corresponds to the linux group number 352
Use echo command in the console to export GPIO number N for manipulation
echo N > /sys/class/gpio/export
N Indicates the number of the GPIO to be operated. N = GPIO group number + offset value

What’s the GPIO number for the built-in LED?

2. Exporting GPIO Pin
Before using a GPIO pin, it must be exported to make it appear in the sysfs directory.

echo N > /sys/class/gpio/export
You can verify if it’s exported by checking if the if the file exists.

cat /sys/class/gpio/gpioN
3. Set the direction as output or input
echo out > /sys/class/gpio/gpioN/direction
echo in > /sys/class/gpio/gpioN/direction
4. Read the GPIO values
Use cat to read the value

cat /sys/class/gpio/gpioN/value
5. Set the GPIO values
output low:

echo 0 > /sys/class/gpio/gpioN/value
output high:

echo 1 > /sys/class/gpio/gpioN/value
6. Cleanup
After the resource is used, run the echo command on the console to release resources:

echo N > /sys/class/gpio/unexport
Using C?
Demo
