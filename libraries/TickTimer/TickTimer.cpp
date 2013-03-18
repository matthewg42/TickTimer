#include <TickTimer.h>

TickTimer::TickTimer(void (*timeoutCallback)())
    : _ticksLeft(0)
{
    _callback = timeoutCallback;
}

TickTimer::~TickTimer()
{
}

void TickTimer::set(int ticks)
{
    _ticksLeft = ticks;
}

void TickTimer::tick()
{
    if (_ticksLeft == 1) {
        _ticksLeft = 0;
        _callback();
    }
    else if (_ticksLeft>0) {
        _ticksLeft--;
    }
}

