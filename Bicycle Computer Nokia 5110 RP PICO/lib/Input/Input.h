#ifndef INPUT_H
#define INPUT_H

#include <Arduino.h>
#include <Pins.h>
#include <BikeTime.h>

namespace Input
{
    extern int32_t counter;

    void setup();
    void update();
}

class Encoder
{
    int8_t pinA;
    int8_t pinB;

    int32_t lastState = 1;
    bool flag = false;
    int32_t dir;

public:
    int32_t counter = 0;
    time_ms prevTime = 0;

    void begin(int8_t _pinA, int8_t _pinB);
    void update();
};

struct InputData
{
    bool backButton = false;
    bool confirmButton = false;

    bool backButtonFlag = false;
    time_ms backButtonPrevT = 0;
    time_ms confirmButtonPrevT = 0;

    Encoder encoder;
};

class InputHardware
{
    bool oldBtnState = true;   
    bool oldConfirmBtnState = true;
public:
    bool checkBackButton();
    bool checkConfirmButton();
};

extern InputHardware btnsEnc;
extern InputData inputData;

#endif