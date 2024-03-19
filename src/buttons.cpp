#include "buttons.hpp"
#include "config.hpp"

#define DEBOUNCE_COUNTS 150
#define PRESSED_COUNTS 5

Buttons button_1;

// function prototypes
void debouce_button(Buttons *button, bool current_state);

void read_buttons(void) // all debounce operations are called here
{                       // developed with calls every 10ms
    debouce_button(&button_1, !digitalRead(BTN_1));
}

void debouce_button(Buttons *button, bool current_state)
{
    if (current_state)
    {
        if (button->debounce_counter)
        {
            button->debounce_counter--;
        }

        if (button->debounce_counter <= (DEBOUNCE_COUNTS - PRESSED_COUNTS)) // 50ms have passed
        {
            button->debounced = true;
        }

        if (!button->debounce_counter) // 1.5s have passed, so we set a long press
        {
            button->long_press = true;
            button->debounced = false;
        }
    }
    else if (button->debounced && !button->long_press)
    {
        button->debounced = false;
        button->short_press = true;
        button->toggle_press = true; // this is disabled when used
    }
    else
    {
        button->short_press = false;
        button->long_press = false;
        button->debounce_counter = DEBOUNCE_COUNTS;
    }
}