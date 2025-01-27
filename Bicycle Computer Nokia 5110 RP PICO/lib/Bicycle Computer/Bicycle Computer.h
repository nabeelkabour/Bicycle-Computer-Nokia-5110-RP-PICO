#ifndef BICYCLE_COMPUTER_H
#define BICYCLE_COMPUTER_H

#include <Arduino.h>

#define BC_NUM_MAGNETS 1

extern uint16_t count;
//extern float distance;
extern uint32_t distance;
extern float speed;
//extern float tire_circ_km;
extern uint16_t tire_circ;
// extern uint32_t poll_rate;

namespace BicycleComputer
{
    void loop();
    void pollHallsensor();
    void measureSpeedDistance();
}

#endif