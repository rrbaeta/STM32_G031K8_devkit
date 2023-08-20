#include <Arduino.h>

#include "config.hpp"

void gpio_config(void)
{
  pinMode(PC6, OUTPUT);
  pinMode(PA0, OUTPUT);
  pinMode(PB6, INPUT);
  pinMode(PB7, OUTPUT);
}