#include <Arduino.h>

#include "isr.hpp"

void timer_1_isr(void)      //10ms
{
    volatile static bool ledOn = false;
    ledOn = !ledOn;
    digitalWrite(PC6, ledOn ? HIGH : LOW);

    printf("Hello World");
}

void isr_init(void)
{
    HardwareTimer timer_1(TIM1);

    // Configure timer
    timer_1.setPrescaleFactor(68); // Set prescaler to 68 => timer frequency = 68MHz/68 = 1000000 Hz
    timer_1.setOverflow(500000); // Set overflow to 10000 => timer frequency = 1000000 Hz / 10000 = 100 Hz
    timer_1.attachInterrupt(timer_1_isr);
    timer_1.refresh(); // Make register changes take effect
    timer_1.resume(); // Start
}