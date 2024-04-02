char *wiringXPlatform(void); // Returns the platform name

int wiringXValidGPIO(int pin); // Check if the GPIO pin is valid

int wiringXSetup(char *name, ...); //Initialize the wiringx library

void delayMicroseconds(unsigned int ms); //Delay in microseconds

int wiringXGC(void); //Releases the GPIO pins