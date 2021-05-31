#include "Voice.hpp"

Voice::Voice()
{
    basePatchCords.push_back(std::make_unique<AudioConnection>(wave[0], 0, envelope[0], 0));
    basePatchCords.push_back(std::make_unique<AudioConnection>(wave[1], 0, envelope[1], 0));
    basePatchCords.push_back(std::make_unique<AudioConnection>(wave[2], 0, envelope[2], 0));
    basePatchCords.push_back(std::make_unique<AudioConnection>(wave[3], 0, envelope[3], 0));
    basePatchCords.push_back(std::make_unique<AudioConnection>(mixer_l, 0, amp_l, 0));
    basePatchCords.push_back(std::make_unique<AudioConnection>(mixer_r, 0, amp_r, 0));

    wave[0].begin(0.5, 440.0, 0);
    wave[1].begin(0.5, 440.0, 0);
    wave[2].begin(0.5, 440.0, 0);
    wave[3].begin(0.5, 440.0, 0);
}

Voice::~Voice()
{

}

void Voice::SetAlgorithm(short id)
{
    clearConnections();
    switch(id)
    {
        case 1:  // DX9 Algo 1
        {
            Serial.println("Setting Algo 1\r\n");
            patchCords.push_back(std::make_unique<AudioConnection>(envelope[0], 0, mixer_l, 0));
            patchCords.push_back(std::make_unique<AudioConnection>(envelope[1], 0, mixer_l, 1));
            patchCords.push_back(std::make_unique<AudioConnection>(envelope[2], 0, mixer_l, 2));
            patchCords.push_back(std::make_unique<AudioConnection>(envelope[3], 0, mixer_l, 3));

            patchCords.push_back(std::make_unique<AudioConnection>(envelope[0], 0, mixer_r, 0));
            patchCords.push_back(std::make_unique<AudioConnection>(envelope[1], 0, mixer_r, 1));
            patchCords.push_back(std::make_unique<AudioConnection>(envelope[2], 0, mixer_r, 2));
            patchCords.push_back(std::make_unique<AudioConnection>(envelope[3], 0, mixer_r, 3));
            break;
        }
        case 2:
        {
            patchCords.push_back(std::make_unique<AudioConnection>(envelope[3], 0, wave[3], 0));
            patchCords.push_back(std::make_unique<AudioConnection>(envelope[3], 0, wave[2], 1));
            patchCords.push_back(std::make_unique<AudioConnection>(envelope[2], 0, mixer_l, 0));
            patchCords.push_back(std::make_unique<AudioConnection>(envelope[2], 0, mixer_r, 0));
            //patchCords.push_back(std::make_unique<AudioConnection>(envelope[3], 0, mixer, 3));
            break;
        }
        case 3:
        {

            break;
        }
        case 4:
        {

            break;
        }
        case 5:
        {
            // patchCords.emplace_back(voice_envelope[3], 0, voice_waveform[3], 0);
            // patchCords.emplace_back(voice_envelope[3], 0, voice_waveform[2], 0);
            // patchCords.emplace_back(voice_envelope[2], 0, mainMixer, 1);
            // patchCords.emplace_back(voice_envelope[1], 0, voice_waveform[0], 0);
            // patchCords.emplace_back(voice_envelope[0], 0, mainMixer, 0);
            // break;
        }
        case 6:
        {
            // patchCords.emplace_back(voice_envelope[3], 0, voice_waveform[3], 0);
            // patchCords.emplace_back(voice_envelope[3], 0, voice_waveform[2], 0);
            // patchCords.emplace_back(voice_envelope[3], 0, voice_waveform[1], 0);
            // patchCords.emplace_back(voice_envelope[3], 0, voice_waveform[0], 0);
            // patchCords.emplace_back(voice_envelope[0], 0, mainMixer, 0);
            // patchCords.emplace_back(voice_envelope[1], 0, mainMixer, 1);
            // patchCords.emplace_back(voice_envelope[2], 0, mainMixer, 2);
            break;
        }
        case 7:
        {
            // patchCords.emplace_back(voice_envelope[3], 0, voice_waveform[3], 0);
            // patchCords.emplace_back(voice_envelope[3], 0, voice_waveform[2], 0);
            // patchCords.emplace_back(voice_envelope[0], 0, mainMixer, 0);
            // patchCords.emplace_back(voice_envelope[1], 0, mainMixer, 1);
            // patchCords.emplace_back(voice_envelope[2], 0, mainMixer, 2);
            break;
        }
        case 8:
        {
            // patchCords.emplace_back(voice_envelope[3], 0, voice_waveform[3], 0);
            // patchCords.emplace_back(voice_envelope[0], 0, mainMixer, 0);
            // patchCords.emplace_back(voice_envelope[1], 0, mainMixer, 1);
            // patchCords.emplace_back(voice_envelope[2], 0, mainMixer, 2);
            // patchCords.emplace_back(voice_envelope[3], 0, mainMixer, 3);
            break;
        }
        default:
        {
            patchCords.push_back(std::make_unique<AudioConnection>(envelope[0], 0, mixer_r, 0));
            patchCords.push_back(std::make_unique<AudioConnection>(envelope[0], 0, mixer_l, 0));
            // patchCords.push_back(std::make_unique<AudioConnection>(voice_envelope[1], 0, mainMixer, 1));
            // patchCords.push_back(std::make_unique<AudioConnection>(voice_envelope[2], 0, mainMixer, 2));
            // patchCords.push_back(std::make_unique<AudioConnection>(voice_envelope[3], 0, mainMixer, 3));
        }
    }
}

void Voice::Balance(int bal)
{
    balance = bal;
    Volume(volume);
}

void Voice::Volume(float vol)
{
    volume = vol;
    float l_vol = (100.0 - balance)/100 * volume;
    float r_vol = ((float)balance)/100 * volume;
    amp_l.gain(l_vol);
    amp_r.gain(r_vol);
    Serial.printf("Setting volume L: %2.2f - R: %2.2f\r\n", l_vol, r_vol);
}

void  Voice::SetWaveform(int op, int wf)
{
    wave[op].begin(wf);
}

void Voice::SetAmplitude(int op, float amp)
{
    wave[op].amplitude(amp);
}

void Voice::SetFMod(int op, float oct)
{
    wave[op].frequencyModulation(oct);
}

void Voice::SetPhMod(int op, float degrees)
{
    wave[op].phaseModulation(degrees);
}

void Voice::SetDelay(int op, int ms)
{
    envelope[op].delay(ms);
}

void Voice::SetAttack(int op, int ms)
{
    envelope[op].attack(ms);
}

void Voice::SetHold(int op, int ms)
{
    envelope[op].hold(ms);
}

void Voice::SetDecay(int op, int ms)
{
    envelope[op].decay(ms);
}

void Voice::SetSustain(int op, float level)
{
    envelope[op].sustain(level);
}

void Voice::SetRelease(int op, int ms)
{
    envelope[op].release(ms);
}

void Voice::SetDetune(int op, int cents)
{
    Serial.printf("Setting Detune [%d]: %d cents\r\n", op,cents);
    detune[op] = cents;
}

void Voice::PlayNote(int note){
    float hertz = 440.0 * pow(2.0, (double)(note - 69)/12);
    
    AudioNoInterrupts();
    for(int op = 0; op < OPERATORS; ++op)
    {
        freq[op] = hertz + (hertz*((float)detune[op] / 1200.0));
        wave[op].frequency(freq[op]);
        envelope[op].noteOn();
    }
    AudioInterrupts();

    Serial.printf("Playing Note: %d(%.2f-%.2f-%.2f-%.2f)\r\n", note, freq[0], freq[1], freq[2], freq[3]);
}

void Voice::StopNote(){
    AudioNoInterrupts();
    for(int op = 0; op < OPERATORS; ++op)
    {
        envelope[op].noteOff();
    }
    AudioInterrupts();
}

AudioAmplifier& Voice::GetOutputL(){
    return amp_l;
}

AudioAmplifier& Voice::GetOutputR(){
    return amp_r;
}

void Voice::clearConnections()
{
    for(auto& con: patchCords)
    {
        con->disconnect();
    }
    patchCords.clear();
}