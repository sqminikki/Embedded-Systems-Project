#include <stdio.h>
#include <unistd.h>

// WiringX API Header
#include <wiringx.h>

int main()
{
    int DUO_LED = 25; //If 25 doesn't work, try 24...

    int wiringXSetup("duo", NULL);

    
    if (wiringXSetup("duo", NULL) == -1)
    {
        printf("Failed to initialize wiringX\n");
        wiringXGC();
        return -1;
    }

    if(wiringXValidGPIO(DUO_LED) != 0)
    {
        printf("Invalid GPIO\n");
        wiringXGC();
        return -1;
    }

    pinMODE(DUO_LED, PINMODE_OUTPUT);

    while(1)
    {
        printf("LED ON\n");
        digitalWrite(DUO_LED, HIGH);
        delayMicroseconds(1000000);

        printf("LED OFF\n");
        digitalWrite(DUO_LED, LOW);
        delayMicroseconds(1000000);
    }

    return 0;
}