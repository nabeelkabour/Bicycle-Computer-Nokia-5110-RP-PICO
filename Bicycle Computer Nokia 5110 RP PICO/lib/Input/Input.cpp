#include "Input.h"
#include <BikeTime.h>

//PicoEncoder encoder;
InputHardware btnsEnc;
InputData inputData;

int32_t Input::counter = 0                                                                                                                                                                                                                                                                                      ;

void Input::setup()
{
    inputData.encoder.begin(ENC_A, ENC_B); 
}

void Input::update()
{
    inputData.backButton = btnsEnc.checkBackButton();
    inputData.confirmButton = btnsEnc.checkConfirmButton();

    static bool prevEncoderState = HIGH;

    bool encoderISR = digitalRead(ENC_A);

    if(encoderISR != prevEncoderState)
    {
        bool encState = digitalRead(ENC_A);
        if (encState != prevEncoderState and encState == LOW) 
        {
            if (digitalRead(ENC_B) != encState)  
            {
                ++counter;
            }
            else
            {
                --counter;
            }
            delay(20);
        }

        prevEncoderState = encState;
    }

    // return isPressed;
}

void Encoder::begin(int8_t _pinA, int8_t _pinB)
{
    pinA = _pinA;
    pinB = _pinB;

    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
}

void Encoder::update()
{
    int32_t state = digitalRead(pinA);
    if (state != lastState && state == LOW) 
    {
        flag = true;
        if (digitalRead(pinB) != state) 
        {
            dir = 1;
            counter++;
        }
        else 
        {
            dir = 0;
            counter--;
        }
    }
    lastState = state;
}

bool InputHardware::checkBackButton()
{
    bool isPressed = false;

    bool btnState = digitalRead(BACK_BTN);
    if (btnState != oldBtnState) 
    {
        oldBtnState = btnState;
        if (btnState == LOW)  
        {
            isPressed = true;
        }
        delay(20);
    }

    return isPressed;
}

bool InputHardware::checkConfirmButton()
{
    bool isPressed = false;

    bool btnState = digitalRead(ENC_BTN);
    if (btnState != oldConfirmBtnState) 
    {
        oldConfirmBtnState = btnState;
        if (btnState == LOW)  
        {
            isPressed = true;
        }
        delay(20);
    }

    return isPressed;
}