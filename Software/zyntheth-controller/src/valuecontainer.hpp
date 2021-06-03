#pragma once

#include "ILI9341_t3.h"
#include "config.hpp"

class ValueContainer
{
 public:
    struct controls_t
    {
        uint16_t localSteps[ENCODERS];
        uint16_t lastSteps[ENCODERS];
        uint8_t buttonpress[ENCODERS + 1];
        bool update[ENCODERS];
    };

    struct osc_t
    {
        uint8_t enabled;
        uint8_t waveform;
        float_t amplitude;
        float_t offset;
        float_t freqMod;
        float_t phaseMod;
        uint16_t freq;
        float_t delay;
        float_t attack;
        float_t hold;
        float_t decay;
        float_t sustain;
        float_t release;
    };

    ILI9341_t3 lcdHandler{15, 10, 16};
    controls_t Controls;
    osc_t oscillator[OSCILLATORS];
};
