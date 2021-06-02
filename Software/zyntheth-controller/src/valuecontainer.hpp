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
        float_t freqModulation;
        float_t phase;
        uint16_t freq;
        uint16_t attack;
        uint16_t decay;
        float_t sustain;
        uint16_t release;
    };

    ILI9341_t3 lcdHandler{15, 10, 16};
    controls_t Controls;
    osc_t oscillator[OSCILLATORS];
};
