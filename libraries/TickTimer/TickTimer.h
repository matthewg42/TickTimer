#ifndef TICKTIMER_H
#define TICKTIMER_H

//! @file TickTimer.h
//! @brief This file defines the TickTimer class

//! @class TickTimer 
//! An object which calls a callback when some number of ticks have passed.
class TickTimer {
public:
    //! @brief Create a TickTimer object 
    //! 
    //! @param timeoutCallack the function to call when the TickTimer object has counted the 
    //!                       required number of ticks.
    TickTimer(void (*timeoutCallack)());

    ~TickTimer();

    //! @brief Set the TickTimer going.
    //!
    //! @param ticks how many ticks will go by before the the callback is called
    //!              setting ticks to 0 will stop the TickTimer object without 
    //!              triggering the callback. Using 1 as the ticks value will cause 
    //!              the callbacl to be triggered on the next call to tick()
    void set(int ticks);

    //! tick() should be called whenever a tick has passed (typically once per loop() iteration)
    void tick();

private:
    int _onTicks;
    int _ticksLeft;
    void (*_callback)();

};

#endif // TICKTIMER_H
