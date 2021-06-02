#pragma once

#define FORWARD 1
#define REWERSE -1

#define DEBOUNCE_LIMIT 1  //Not needed when HW debounce exists

class Encoder
{
 public:
    Encoder();
    virtual ~Encoder();

    bool PushState(char newState);
    int GetSteps();
    void Reset();

 private:
    enum encState {
        waiting,
        counting,
        ready,
        reset
    };

    //char lastState;
    int accuSteps;
    int pulseCountsCW;
    int pulseCountsCCW;
    encState state;
};