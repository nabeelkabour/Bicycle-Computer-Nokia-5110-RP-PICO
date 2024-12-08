#include <BikeTime.h>
#include <Pins.h>
#include <Display.h>
#include <Input.h>
#include "Bicycle Computer.h"

uint16_t count = 0;
// float distance = 0;
uint32_t distance = 0;
float speed = 0;
uint16_t tire_circ = 2110;
// float tire_circ_km = 0.00211F;
// uint32_t poll_rate = 0;

time_ms prev_update_time = 0;

void BicycleComputer::pollHallsensor()
{
    static bool prev_reedswitch_value = HIGH;
    bool reedswitch_value;

    reedswitch_value = digitalRead(REED_SWITCH_PIN);

    if (reedswitch_value != prev_reedswitch_value)
    {
        if (reedswitch_value == HIGH)
        {
            ++count;
        }

        prev_reedswitch_value = reedswitch_value;
    }

   //count = inputData.encoderPos;
}

void BicycleComputer::measureSpeedDistance()
{
    time_ms now = millis();
    time_ms delta_time = now - prev_update_time;

    if (delta_time >= BC_MEASURE_INTERVAL)
    {
        if (count)
        {
            float revolutions = float(count) / float(BC_NUM_MAGNETS);
            //distance += revolutions * tire_circ_km;
            distance += revolutions * tire_circ;
            speed = revolutions * float(tire_circ) / float(delta_time) * 3.6F;

            if(speed > 9999.0F)
            {
                speed = 9999.0F;
            }

            count = 0;
            //encoder.step = 0;
        }
        else
        {
            speed = 0.0F;
        }

        Display::showSpeed();
        Display::showDistance();
        prev_update_time = now;
    }
}

void BicycleComputer::loop()
{
    pollHallsensor();
    measureSpeedDistance();
}