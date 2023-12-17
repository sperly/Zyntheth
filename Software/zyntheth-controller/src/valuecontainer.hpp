#pragma once

#include <FlexCAN.h>
#include "ILI9341_t3n.h"
#include "SdFat.h"
#include "config.hpp"
#include "log.hpp"

class ValueContainer
{
 public:
    ValueContainer()
    {
        LOG_DEBUG("Initializing valuecontainer...");
        for (int i = 0; i < ENCODERS; i++)
        {
            Controls.localSteps[i] = 0;
            Controls.lastSteps[i]  = 0;
            Controls.update[i]     = false;
        }

        for (int i = 0; i < BUTTONS; i++)
        {
            Controls.buttonpress[i] = 0;
        }

        for (int i = 0; i < OSCILLATORS; ++i)
        {
            oscillator[i].waveform  = WAVEFORM_SINE;
            oscillator[i].amplitude = 0.7;
            oscillator[i].detune    = 0;
            oscillator[i].freqMod   = 0.0;
            oscillator[i].phaseMod  = 0.0;
            oscillator[i].freq      = 0;
            oscillator[i].delay     = DELAY_DEF;
            oscillator[i].attack    = ATTACK_DEF;
            oscillator[i].hold      = HOLD_DEF;
            oscillator[i].decay     = DECAY_DEF;
            oscillator[i].sustain   = SUSTAIN_DEF;
            oscillator[i].release   = RELEASE_DEF;
        }
        LOG_DEBUG("Initializing valuecontainer done.");
    }
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
        float_t detune;
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

    ILI9341_t3n lcdHandler{LCD_CS, LCD_DC, LCD_RST, LCD_MOSI, LCD_SCLK, LCD_MISO};
    controls_t Controls;
    osc_t oscillator[OSCILLATORS];

    SdFs sd;
};
