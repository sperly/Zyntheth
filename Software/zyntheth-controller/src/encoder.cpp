#include "encoder.hpp"
#include "Arduino.h"

Encoder::Encoder()
    : accuSteps{}, pulseCountsCW{}, pulseCountsCCW{}, state{waiting}
{
}

Encoder::~Encoder()
{
}

bool Encoder::PushState(char newState)
{
    bool update = false;

    if (0x01 == (newState & 0x03))
    {
        if (state == waiting) state = counting;
        pulseCountsCW++;
        pulseCountsCCW = 0;
    }
    else if (0x02 == (newState & 0x03))
    {
        if (state == waiting) state = counting;
        pulseCountsCCW++;
        pulseCountsCW = 0;
    }
    else if ((0x00 == (newState & 0x03)) && (state == ready))
    {
        state = waiting;
    }
    else if ((0x03 == (newState & 0x03)) && (state == counting))
    {
        state = ready;
        if (pulseCountsCCW > DEBOUNCE_LIMIT)
        {
            accuSteps -= 1;
            state          = ready;
            update         = true;
            pulseCountsCCW = 0;
            pulseCountsCW  = 0;
        }
        else if (pulseCountsCW > DEBOUNCE_LIMIT)
        {
            accuSteps += 1;
            state          = ready;
            update         = true;
            pulseCountsCCW = 0;
            pulseCountsCW  = 0;
        }
    }
    return update;
}

int Encoder::GetSteps()
{
    int retval = accuSteps;
    Reset();
    return retval;
}

void Encoder::Reset()
{
    accuSteps = 0;
}
