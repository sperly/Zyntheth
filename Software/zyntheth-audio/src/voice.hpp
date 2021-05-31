#pragma once

#include <vector>
#include <memory>
#include <Audio.h>

#include "config.hpp"

class Voice{

public:
    Voice();
    ~Voice();

    void Balance(int bal);
    void Volume(float vol);
    void SetAlgorithm(short id);
    void SetDetune(int op, int cents);
    void SetWaveform(int op, int waveform);
    void SetAmplitude(int op, float amp);
    void SetFMod(int op, float oct);
    void SetPhMod(int op, float degrees);
    void SetDelay(int op, int ms);
    void SetAttack(int op, int ms);
    void SetHold(int op, int ms);
    void SetDecay(int op, int ms);
    void SetSustain(int op, float level);
    void SetRelease(int op, int ms);
    void PlayNote(int note);
    void StopNote();
    AudioAmplifier& GetOutputL();
    AudioAmplifier& GetOutputR();

private:
    AudioAmplifier amp_l;
    AudioAmplifier amp_r;
    AudioMixer4 mixer_r;
    AudioMixer4 mixer_l;
    AudioSynthWaveformModulated wave[OPERATORS];
    AudioEffectEnvelope envelope[OPERATORS];
    std::vector<std::unique_ptr<AudioConnection>> patchCords;
    std::vector<std::unique_ptr<AudioConnection>> basePatchCords;
    int balance = 50;
    float volume = 0.7;
    int algorithm = 1;
    int waveforms[OPERATORS] = {WAVEFORM_SINE, WAVEFORM_SINE, WAVEFORM_SINE, WAVEFORM_SINE};
    float amplitude[OPERATORS] = { 0.7, 0.7, 0.7, 0.7};
    float freq[OPERATORS] = {440.0, 440.0, 440.0, 440.0};
    int detune[OPERATORS] = {0, 0, 0, 0};
    void clearConnections();
};
