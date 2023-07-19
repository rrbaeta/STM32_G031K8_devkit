#ifndef BUTTONS_HPP
#define BUTTONS_HPP

struct Buttons
{
    bool short_press;
    bool long_press;
    bool toggle_press;      //reset where used

    bool old_short_press;
};

// function prototypes
void debouce_buttons(Buttons &button, bool current_state);


#endif /* BUTTONS_HPP */