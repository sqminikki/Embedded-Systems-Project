### Beginning of Embedded Systems Project

# Day 1:

#### 03/30/24 - Working on `morse.c`
- added parsing to `translate_to_morse` function.
- added "delimiter" `/` for spaces between words.
- added `morseOutput` & `morseOutputSize` to console printout for debugging.

# Day 2:

#### 03/31/24 - Finished `morse.c`
- Finished `translate_to_morse` function.

    - fixed the issue with alphanumerical characters
    - added space between morse code characters.

- Completed `morse_blink_led` function.

    - setup `"dit"` character LED timing
    - setup `"dah"` character LED timing
    - setup `"   "` character LED timing

- TESTED using test bench code...

    - test_AlphabeticInput: `PASS`
    - test_NumericInput: `PASS`
    - test_MixedAlphanumericInput: `PASS`
    - test_CanHandleSpaces: `PASS`
    - test_MixedCaseAlphanumericInput: `PASS`
    - test_NonRepresentableBinaryData: `PASS`
    - test_MorseTiming: `PASS`
