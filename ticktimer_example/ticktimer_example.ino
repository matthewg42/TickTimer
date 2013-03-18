#include <TickTimer.h>

// We will have a "tick" about every 0.1 seconds.
// Every 50 ticks (~5 seconds) we'll start two timers:
//  timerBob will be set with a 20 tick timeout.
//  timerConnie will be set with a 30 tick timeout.
//
// timerBob and timerConnie will trigger bobCallback 
// and connieCallback when the correct number of ticks 
// have occurred (bob first, then connie).  The callbacks
// will print a message to the Serial interface.

int tickCounter = 0;
TickTimer timerBob(bobCallback);
TickTimer timerConnie(connieCallback);

void setup()
{
    Serial.begin(9600);
    delay(500);
    Serial.println("setup() complete");
}

void loop()
{
    // every 3 seconds
    if (tickCounter++ % 50 == 0) {
        Serial.println("Starting timers...");
        timerBob.set(20);
        timerConnie.set(30);
    }

    // our tick length is milliseconds
    delay(100);

    // We need to tell the timers a tick of time has passed...
    timerBob.tick();
    timerConnie.tick();

}

void bobCallback()
{
    Serial.println("bobCallback has been called...  timerBob has finished");
}

void connieCallback()
{
    Serial.println("connieCallback has been called...  timerConnie has finished");
}

