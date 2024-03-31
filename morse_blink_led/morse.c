#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "morse.h"
#include "delay.h"
#include "blink.h"

const char *char_to_morse(char c)
{
    // Define Morse code for each alphabet and digit
    static const char *morseCode[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                                        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                                        "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
                                        "...--", "....-", ".....", "-....", "--...", "---..", "----."};

    if (c >= 'a' && c <= 'z')
    {
        return morseCode[c - 'a'];
    }
    else if (c >= '0' && c <= '9')
    {
        return morseCode[c - '0' + 26];
    }
    else if (c >='A' && c <= 'Z')
    {
        return morseCode[c - 'A'];
    }
    else
    {
        return ""; // Return empty string for other characters
    }
}

// Function to convert a word to Morse code
// Use the delimiter / for any spaces between words
void translate_to_morse(const char *text, char *morseOutput, int morseOutputSize)
{
    for(int i = 0; i < strlen(text); i++) // Loop through the text to convert each charactor to morse code.
    {
        if (text[i] == ' ')
        {
            strcat(morseOutput, "/"); // Add / for spaces between words
        }
        else
        {
            char *morse = char_to_morse(text[i]); // Get morse code for each charactor
            strcat(morseOutput, morse); // Add morse code for each charactor
            morseOutputSize = i; // Get the size of the morseOutput
        }
    }

    for(int i = 0; i < strlen(morseOutput); i++) //temporarily using printf to watch the output
    {
        printf("%c", morseOutput[i], morseOutputSize); // Print the morseOutput to the console
    }
    
    // Loop through the text to convert each
    // charactor to morse code.
    // char_to_morse function is provided above but may not
    // handle all cases.
}

void morse_blink_led(const char *morseCode)
{
    // Blink LED based on the timing needed
    // 1 Unit = 1 Second

    // Use LED_HIGH() to turn on led
    // Use LED_LOW() to turn off led
    LED_HIGH();
    LED_LOW();

    // int duration = 1 or w/e value you need
    // Use DELAY(duration) to sleep the appropriate units
    // Rmemeber 1 unit = 1 second for this assignment
}
