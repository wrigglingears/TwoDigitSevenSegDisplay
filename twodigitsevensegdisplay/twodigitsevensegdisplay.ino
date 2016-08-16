#include <TwoDigitSevenSegDisplay.h>

SingleDigitPins pins[] = {
    {30, 31, 32, 33, 34, 35, 36, 37},
    {38, 39, 40, 41, 42, 43, 44, 45}
};

TwoDigitSevenSegDisplay errorDisplay(pins);

void setup() {
    errorDisplay.begin();
}

void loop() {
    
}