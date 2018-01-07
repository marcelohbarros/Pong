#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

/*
 *  This timer store the last time it was updated.
 *  It is used to compare the actual time and the last update time.
 */

class Timer
{
private:
    Uint32 ticks;
public:
    Timer();
    void update();
    Uint32 getTicks();
};

#endif // TIMER_H_INCLUDED
