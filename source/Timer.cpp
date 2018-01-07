#include <SDL.h>
#include "Timer.h"

Timer::Timer()
{
    ticks = SDL_GetTicks();
}

void Timer::update()
{
    ticks = SDL_GetTicks();
    return;
}

Uint32 Timer::getTicks()
{
    return ticks;
}
