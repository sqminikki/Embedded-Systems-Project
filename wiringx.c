#include <stdio.h>
#include <unistd.h>

#include <wiringx.h>

int main()
{
    int DUO_LED = 25;

    if (wiringXSetup("duo", NULL) == -1)
    {
        printf("Failed to initialize wiringX\n");
       
        wiringXGC();

        return -1;
    }

    if 
}