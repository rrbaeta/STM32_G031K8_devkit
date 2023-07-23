#ifndef ISR_HPP
#define ISR_HPP

struct Timers
{
    bool t_10_ms;      //not in use
    bool t_100_ms;
    bool t_1_s;
};

//Global variables
extern Timers timers;

// function prototypes
void isr_init(void);

#endif /* ISR_HPP */