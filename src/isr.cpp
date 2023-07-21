#include <Arduino.h>

#include "isr.hpp"

HardwareTimer timer_1(TIM1);

void timer_1_isr(void)      //10ms
{
    Serial.println("ISR");

    volatile static bool ledOn = false;
    ledOn = !ledOn;
    digitalWrite(PC6, (ledOn ? HIGH : LOW));

    timer_1.resume(); // Start
}

void isr_init(void)
{
    // Configure timer
    timer_1.setPrescaleFactor(64); // Set prescaler to 68 => timer frequency = 64MHz/64 = 1000000 Hz
    timer_1.setOverflow(10000); // Set overflow to 10000 => timer frequency = 1000000 Hz / 10000 = 100 Hz
    timer_1.attachInterrupt(timer_1_isr);
    timer_1.refresh(); // Make register changes take effect
    timer_1.resume(); // Start
}