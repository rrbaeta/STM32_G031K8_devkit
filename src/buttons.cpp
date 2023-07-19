#include "buttons.hpp"

Buttons button_1;

void debouce_buttons(Buttons &button, bool current_state)
{
    button.short_press = true;
}