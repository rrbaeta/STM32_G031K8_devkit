#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include <Arduino.h>

#define BTN_1 !PB6

struct Buttons
{
    bool short_press;
    bool long_press;
    bool toggle_press; // reset where used

    bool debounced;
    uint8_t debounce_counter = 5;
};

// function prototypes
void read_buttons(void);

#endif /* BUTTONS_HPP */