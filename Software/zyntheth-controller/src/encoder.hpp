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
    //const signed char stateTable[4][4] = {/* 0b00 */{0, FORWARD, REWERSE, 0}, /* 0b01 */ {REWERSE, 0, 0, FORWARD}, /* 0b10 */ {FORWARD, 0, 0, REWERSE},  /* 0b11 */{0, REWERSE, FORWARD, 0}};
};