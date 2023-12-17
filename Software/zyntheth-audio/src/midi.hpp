#pragma once
#include <stdint.h>

class ZynthethMidi
{
 public:
    ZynthethMidi();

    void Setup();

 private:
    void handleKeypress(uint8_t key, uint8_t sus, uint8_t vel);
};