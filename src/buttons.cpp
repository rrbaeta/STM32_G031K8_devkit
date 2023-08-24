#include "buttons.hpp"

Buttons button_1;

// function prototypes
void debouce_button(Buttons &button, bool current_state);

void read_buttons(void) // all debounce operations are called here
{
    debouce_button(button_1, digitalRead(BTN_1));
}

void debouce_button(Buttons &button, bool current_state)
{
    if (current_state)
    {
        if (button.debounce_counter)
        {
            button.debounce_counter--;
        }

        if (!button.debounce_counter && current_state)
        {
            button.short_press = true;
        }
    }
    else
    {
        button.short_press = false;
        button.debounce_counter = 5;
    }
}