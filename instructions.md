# Morse Code Translator

## Introduction
This project involves creating a Morse code translator in C that controls an LED on the Milk-V Duo to blink Morse code representations of text inputs. The objective is to blend software development with hands-on hardware interaction, focusing on embedded systems programming, C language, and unit testing using Unity.

## Setup Instructions
1. Set up the Milk-V Duo embedded device.
2. Install Unity testing framework.

## Teams
You are allowed to pair up with another person or go solo.
If you are teaming up with another person, you must email your partner.

## Morse Code Timing

Morse code transmission is based on a standardized timing sequence which determines the length of each symbol (dot and dash) and the pauses between them. The timing is typically based on a basic unit of time, often referred to as a "dit" for the dot.

1. **Dot (Dit)**: The duration of a dot is 1 time unit.
2. **Dash (Dah)**: A dash is equal to 3 time units.
3. **Space Between Parts of the Same Letter**: The space between the dots and dashes within a letter is 1 time unit (the same duration as a dot).
4. **Space Between Letters**: The space between letters is 3 time units (the same duration as a dash).
5. **Space Between Words**: The space between words is 7 time units.

For example, in the transmission of the word "SOS":

- "S": 
  - Dot (1 unit)
  - Space (1 unit)
  - Dot (1 unit)
  - Space (1 unit)
  - Dot (1 unit)
- Space between "S" and "O" (3 units)
- "O": 
  - Dash (3 units)
  - Space (1 unit)
  - Dash (3 units)
  - Space (1 unit)
  - Dash (3 units)
- Space between "O" and "S" (3 units)
- "S": 
  - Dot (1 unit)
  - Space (1 unit)
  - Dot (1 unit)
  - Space (1 unit)
  - Dot (1 unit)


This timing must be accurately implemented in the software controlling the LED on the Duo device to ensure proper Morse code transmission.


## Sample Code

### Morse Code Translator Function
This is not finished!, it doesn't handle capital letters

```c
#include <stdio.h>
#include <string.h>

// Function to convert a character to Morse code
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
    else
    {
        return ""; // Return empty string for other characters
    }
}

// Function to convert a word to Morse code
// Use the delimiter / for any spaces between words
void translate_to_morse(const char *text, char *morseOutput, int morseOutputSize)
{
    // Loop through the text to convert each
    // charactor to morse code.
    // char_to_morse function is provided above but may not
    // handle all cases.
}
```

### Main Function
```c
#include <stdio.h>

#include "morse.h"

#define BUFSIZE 100

int main()
{
    char text[] = "hello";
    char morseOutput[BUFSIZE] = "";

    // Fill in the code for `translate_to_morse`
    translate_to_morse(text, morseOutput, BUFSIZE - 1);
    printf("Morse Code: %s\n", morseOutput);

    // Passe `morseOutput` to the morse_blink_led function
    // Update the morse_blink_led to blink accordingly
    morse_blink_led(morseOutput);

    return 0;
}
```

## Testing Guidelines
1. **Unit Testing with Unity**:
   - Write unit tests for the `char_to_morse` and `translate_to_morse` functions.
   - Ensure all characters are correctly translated to Morse code.
   - Write tests for `test_AlphabeticInput`, `test_NumericInput`, `test_MixedAlphanumericInput`, `test_NonRepresentableBinaryData`, `test_MorseTiming`, `test_MixedCase`
2. **Hardware Testing**:
   - Test the LED blinking on the Duo device to match the Morse code output.
   - Verify the timing and sequence of the LED blinks.

## Sample Test Code
```c
#include "unity.h"
#include "delay.h"
#include "morse.h"

extern int mock_delay_called;
extern int mock_delay_duration;

// if needed
void setUp(void)
{
    // Set up any required structures or variables before each test
}

// if needed
void tearDown(void)
{
    // Clean up after each test
}

// Test function for normal alphabetic input
void test_AlphabeticInput(void)
{
    char output[100];
    translate_to_morse("hello", output, 99);

    // hello
    char *expected = ".... . .-.. .-.. ---";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for numeric input
void test_NumericInput(void)
{
    char output[100];
    // Add test code for numeric input such as "123"
    translate_to_morse("123", output, 99);

    // 123
    char *expected = ".---- ..--- ...--";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for mixed alphanumeric input
void test_MixedAlphanumericInput(void)
{
    char output[100];
    // Add test code for numeric input such as "abc123"
    translate_to_morse("abc123", output, 99);

    // abc123
    char *expected = ".- -... -.-. .---- ..--- ...--";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for mixed case input
void test_MixedCaseAlphanumericInput(void)
{
    char output[100];
    // Add test code for numeric input such as "AbC123"
    translate_to_morse("AbC123", output, 99);

    // AbC123
    char *expected = ".- -... -.-. .---- ..--- ...--";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for words with spaces
void test_CanHandleSpaces(void)
{
    char output[100];
    // Add test code for numeric input such as "AbC123"
    translate_to_morse("Hello World", output, 99);

    // Hello World
    char *expected = ".... . .-.. .-.. --- / .-- --- .-. .-.. -..";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for non-representable binary data
void test_NonRepresentableBinaryData(void)
{
    // Nothing to do here, just showing example
    char output[100];
    char binaryData[] = {0x00, 0xFF, 0x55, 0x7F}; // Example binary data
    translate_to_morse(binaryData, output, 99);
    // Since Morse code is not defined for arbitrary binary data, we need to define expected behavior.
    // For example, if non-representable characters are translated as empty strings:
    TEST_ASSERT_EQUAL_STRING("", output);
}

#if !defined(RELEASE) && !defined(DEBUG)
// Test that we can blink an LED
void test_MorseTiming(void)
{
    // Initialize mock function variables
    mock_initialize();

    // Translate "SOS" to Morse code
    char output[150];
    translate_to_morse("SOS", output, sizeof(output) - 1);

    // Blink LED according to Morse code
    morse_blink_led(output);

    // printf("mock_delay_called: %d\n", mock_delay_called);
    // printf("mock_delay_duration: %d\n", mock_delay_duration);

    // Expected values
    int expected_delay_calls = 17;
    int expected_delay_duration = 27;

    // Assert the number of delay calls
    TEST_ASSERT_EQUAL(expected_delay_calls, mock_delay_called);

    // Assert the total duration of delays
    TEST_ASSERT_EQUAL(expected_delay_duration, mock_delay_duration);
}
#endif

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_AlphabeticInput);
    RUN_TEST(test_NumericInput);
    RUN_TEST(test_MixedAlphanumericInput);
    RUN_TEST(test_CanHandleSpaces);
    RUN_TEST(test_MixedCaseAlphanumericInput);
    RUN_TEST(test_NonRepresentableBinaryData);

#if !defined(RELEASE) && !defined(DEBUG)
    RUN_TEST(test_MorseTiming);
#endif

    return UNITY_END();
}
```

## Documentation
- Document your code thoroughly.
- Include comments to explain the logic and flow of the program.
- Write a brief summary of how your code works and any challenges you faced.

## TESTING
You can test this locally first, by default it compiles only the test file.
1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make`

This will compile a `test` binary. Run `./test` and you will see the success/fail output.
Complete the empty functions so the unit tests pass.

## Running on the milkv
Use your cross-compiler toolchain file as before.
The steps are typically
1. `mkdir build`
2. `cd build`
3. `cmake -DCMAKE_TOOLCHAIN_FILE=/app/milkv_duo.cmake ..`
4. `make` or `cmake --build .`

This will build a `test` binary you can push and run on the duo.

If you want to compile the actual binary, the steps are the same above except you will need to build in `Release` or `Debug`.

Change:

```bash
cmake -DCMAKE_TOOLCHAIN_FILE=/app/milkv_duo.cmake ..
```

To

```bash
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=/app/milkv_duo.cmake ..
```

or change `Release` to `Debug` if you want debug symbols.

You will now have a `morse_blink_led` binary to push and run on the duo.

## Troubleshooting builds
CMake doens't always like configuration changes, you might have to delete the `build` dir and run the appropriate cmake command again.
```bash
sudo rm -rf build
```
