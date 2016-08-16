/******************************************************************************
 * TwoDigitSevenSegDisplay Class Implementation
 * Mattheus Lee mattheus.lee@gmail.com
 *****************************************************************************/

#include <TwoDigitSevenSegDisplay.h>

/*****************************Public Methods*****************************/

TwoDigitSevenSegDisplay::TwoDigitSevenSegDisplay() {
}

TwoDigitSevenSegDisplay::TwoDigitSevenSegDisplay(uint8_t pins[NUM_DIGITS][NUM_SEGMENTS]) {
    _setupPins(pins);
    for (uint8_t i = 0; i < NUM_DIGITS; ++i) {
        writeDigit(i, BLANK_DIGIT);
    }
}

void TwoDigitSevenSegDisplay::begin() {
    blankDisplay();
    for (uint8_t digitNum = 0; digitNum < NUM_DIGITS; ++digitNum) {
        for (uint8_t digit = 0; digit < 10; ++digit) {
            writeDigit(digitNum, digit);
            delay(200);
        }
    }
    blankDisplay();
}

void TwoDigitSevenSegDisplay::begin(uint8_t pins[NUM_DIGITS][NUM_SEGMENTS]) {
    _setupPins(pins);
    for (uint8_t i = 0; i < NUM_DIGITS; ++i) {
        writeDigit(i, BLANK_DIGIT);
    }
    blankDisplay();
    for (uint8_t digitNum = 0; digitNum < NUM_DIGITS; ++digitNum) {
        for (uint8_t digit = 0; digit < 10; ++digit) {
            writeDigit(digitNum, digit);
            delay(200);
        }
    }
    blankDisplay();
}

void TwoDigitSevenSegDisplay::displayNumber(uint8_t number) {
    number = constrain(number, 0, 99);
    uint8_t digit_0 = number % 10;
    uint8_t digit_1 = number / 10;
    if (digit_1 == 0) {
        digit_1 = BLANK_DIGIT;
        if (digit_0 == 0) {
            digit_0 = BLANK_DIGIT;
        }
    }
    writeDigit(0, digit_0);
    writeDigit(1, digit_1);
}

void TwoDigitSevenSegDisplay::blankDisplay() {
    writeDigit(0);
    writeDigit(1);
}

void TwoDigitSevenSegDisplay::writeDigit(uint8_t digitNum, uint8_t digitToWrite) {
    if (digitToWrite > DIGIT_TO_WRITE_MAX) {
        digitToWrite = BLANK_DIGIT;
    }
    if (digitToWrite == BLANK_DIGIT) {
        for (uint8_t segmentNum = 0; segmentNum < NUM_SEGMENTS; ++segmentNum) {
            digitalWrite(_pins[digitNum][segmentNum], LED_OFF);
        }
        return;
    }
    for (uint8_t segmentNum = 0; segmentNum < NUM_SEGMENTS; ++segmentNum) {
        if (_segmentPrintsDigit(segmentNum, digitToWrite)) {
            digitalWrite(_pins[digitNum][segmentNum], LED_ON);
        }
        else {
            digitalWrite(_pins[digitNum][segmentNum], LED_OFF);
        }
    }
}

/*****************************Private Methods*****************************/

void TwoDigitSevenSegDisplay::_setupPins(uint8_t pins[NUM_DIGITS][NUM_SEGMENTS]) {
    for (uint8_t digitNum = 0; digitNum < NUM_DIGITS; ++digitNum) {
        for (uint8_t segmentNum = 0; segmentNum < NUM_SEGMENTS; ++segmentNum) {
            _pins[digitNum][segmentNum] = pins[digitNum][segmentNum];
            pinMode(_pins[digitNum][segmentNum], OUTPUT);
            digitalWrite(_pins[digitNum][segmentNum], LED_OFF);
        }
    }
}

bool TwoDigitSevenSegDisplay::_segmentPrintsDigit(uint8_t segmentNum, uint8_t digitToWrite) {
    uint8_t i = 0;
    while (_pinDigits[segmentNum][i] != pinDigitsEnd) {
        if (_pinDigits[segmentNum][i] == digitToWrite) {
            return true;
        }
        ++i;
    }
    return false;
}

/*****************************External Methods*****************************/