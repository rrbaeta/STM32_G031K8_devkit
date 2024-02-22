#include <Arduino.h>

#include "config.hpp"

void gpio_config(void)
{
  pinMode(PC6, OUTPUT);
  pinMode(PA0, OUTPUT);
  pinMode(PB6, INPUT);
  pinMode(PB7, OUTPUT);

  pinMode(LCD_RS, OUTPUT);
  pinMode(LCD_EN, OUTPUT);
  pinMode(LCD_DB4, OUTPUT);
  pinMode(LCD_DB5, OUTPUT);
  pinMode(LCD_DB6, OUTPUT);
  pinMode(LCD_DB7, OUTPUT);
}