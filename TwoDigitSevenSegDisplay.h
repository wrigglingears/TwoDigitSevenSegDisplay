/******************************************************************************
 * TwoDigitSevenSegDisplay Class Specification
 * Mattheus Lee mattheus.lee@gmail.com
 *****************************************************************************/

#ifndef TWODIGITSEVENSEGDISPLAY_CLASS_H
#define TWODIGITSEVENSEGDISPLAY_CLASS_H

#include <Arduino.h>

#define LED_ON HIGH
#define LED_OFF LOW

const uint8_t DIGIT_TO_WRITE_MAX = 12;
const uint8_t NUM_DIGITS = 2;
const uint8_t NUM_SEGMENTS = 7;
const uint8_t BLANK_DIGIT = 10;
const uint8_t DECIMAL_POINT = 11;
const uint8_t pinDigitsEnd = 12;

struct SingleDigitPins {
    uint8_t anodes[7];
    uint8_t dp;
    uint8_t cathode;
};

class TwoDigitSevenSegDisplay {
public:
    TwoDigitSevenSegDisplay(SingleDigitPins singleDigitPins[]);
    void begin();
    void displayNumber(uint8_t number);
    void blankDisplay();
    void writeDigit(uint8_t digitNum, uint8_t digitToWrite = BLANK_DIGIT);

private:
    SingleDigitPins* _singleDigitPins;
    uint8_t _pinDigits[7][10] = {
        {0, 2, 3, 5, 6, 7, 8, 9, pinDigitsEnd},
        {0, 1, 2, 3, 4, 7, 8, 9, pinDigitsEnd},
        {0, 1, 3, 4, 5, 6, 7, 8, 9, pinDigitsEnd},
        {0, 2, 3, 5, 6, 8, 9, pinDigitsEnd},
        {0, 2, 6, 8, pinDigitsEnd},
        {0, 4, 5, 6, 8, 9, pinDigitsEnd},
        {2, 3, 4, 5, 6, 8, 9, pinDigitsEnd}
    };

    void _setupPins();
    bool _segmentPrintsDigit(uint8_t segmentNum, uint8_t digitToWrite);
};

#endif // TWODIGITSEVENSEGDISPLAY_CLASS_H DEFINED