#ifndef ISR_HPP
#define ISR_HPP

struct Timers
{
    bool t_10_ms;
    bool t_100_ms;
    bool t_1_s;
};


// function prototypes
void isr_init(void);

#endif /* ISR_HPP */