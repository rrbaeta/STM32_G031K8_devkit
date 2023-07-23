#include <Arduino.h>

#include "isr.hpp"

HardwareTimer timer_1(TIM1);
Timers timers = {0};

void timer_1_isr(void)      //100ms interrupt
{
    volatile static uint8_t counter_1_s = 10;

    timers.t_100_ms = true;

    counter_1_s--;
    if (!counter_1_s)
    {
        timers.t_1_s = true;
        counter_1_s = 10;
    }
}

void isr_init(void)
{
    // Configure timer
    timer_1.setOverflow(10, HERTZ_FORMAT); //10 Hz 100ms 
    timer_1.attachInterrupt(timer_1_isr);
    timer_1.refresh(); // Make register changes take effect
    timer_1.resume(); // Start
    
    Serial.print("Hz: ");
    Serial.println(timer_1.getTimerClkFreq(), DEC);
    Serial.print("Prescaler: ");
    Serial.println(timer_1.getPrescaleFactor(), DEC);
    Serial.print("Overflow: ");
    Serial.println(timer_1.getOverflow(), DEC);
}