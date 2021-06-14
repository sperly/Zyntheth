#include "Arduino.h"
#include "config.hpp"
#include "voice.hpp"
#include <Audio.h>
#include <memory>
#include <vector>

AudioControlSGTL5000 sgtl5000_1;
AudioOutputI2S i2s1;
AudioOutputUSB usbAudioOut;

//Calculate and design for scalability
Voice voices[POLYPHONY];

//Calculate and designa for scalability
//AudioMixer4 voiceMixers[MAIN_MIXERS];
DMAMEM std::vector<std::unique_ptr<AudioConnection>> patchcords;

void setupVoices()
{
    for (int voice = 0; voice < POLYPHONY; ++voice)
    {
        voices[voice].SetAlgorithm(1);

        for (int op = 0; op < OPERATORS; ++op)
        {
            voices[voice].SetAmplitude(op, 0.5);
            voices[voice].SetDetune(op, (op * 10));
            voices[voice].SetDelay(op, 0);
            voices[voice].SetAttack(op, 10);
            voices[voice].SetHold(op, 10);
            voices[voice].SetDecay(op, 20);
            voices[voice].SetSustain(op, 0.7);
            voices[voice].SetRelease(op, 800);
            voices[voice].SetFMod(op, 1);
        }
        voices[voice].Balance(50);
        voices[voice].Volume(0.7);

        voices[voice].SetWaveform(0, WAVEFORM_TRIANGLE);
        voices[voice].SetWaveform(1, WAVEFORM_SINE);
        voices[voice].SetWaveform(0, WAVEFORM_SQUARE);
        voices[voice].SetWaveform(0, WAVEFORM_SAWTOOTH);
    }
}

AudioMixer4 mixer_l;
AudioMixer4 mixer_r;

AudioConnection top2 = AudioConnection(mixer_l, 0, usbAudioOut, 0);
AudioConnection top3 = AudioConnection(mixer_r, 0, usbAudioOut, 1);

void MakeConnection()
{
    for (int voice = 0; voice < POLYPHONY; ++voice)
    {
        patchcords.push_back(std::make_unique<AudioConnection>(voices[voice].GetOutputL(), 0, mixer_l, voice));
        patchcords.push_back(std::make_unique<AudioConnection>(voices[voice].GetOutputR(), 0, mixer_r, voice));
    }
}

void ClearConnections()
{
    patchcords.clear();
}

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(9600);

    //while (!Serial) ; // wait for Arduino Serial Monitor

    delay(300);
    Serial.println("---* ZYNTHETH *---");

    AudioMemory(TOTAL_VOICES * 3);
    sgtl5000_1.enable();
    sgtl5000_1.volume(0.5);

    usbAudioOut.begin();

    setupVoices();
    MakeConnection();
}

void loop()
{
    digitalWriteFast(LED_BUILTIN, !digitalReadFast(LED_BUILTIN));

    voices[0].PlayNote(63);
    voices[1].PlayNote(67);
    voices[2].PlayNote(70);
    voices[3].PlayNote(75);

    delay(500);
    int usage     = AudioProcessorUsage();
    int mem_usage = AudioMemoryUsageMax();
    Serial.printf("Usage: %i%% - %i blocks\r\n", usage, mem_usage);

    voices[0].StopNote();
    voices[1].StopNote();
    voices[2].StopNote();
    voices[3].StopNote();

    delay(500);
}
