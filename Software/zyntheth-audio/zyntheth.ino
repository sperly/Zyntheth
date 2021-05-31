#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce.h>

#define TOTAL_VOICES 72
#define OPERATORSS 6
#define POLYPHONI  12
#define TOTAL_MIXERS 36

AudioControlSGTL5000 sgtl5000_1;
AudioSynthWavetable wavetable[TOTAL_VOICES];
AudioMixer4 mixer[TOTAL_MIXERS];
AudioOutputI2S i2s1;

struct voice_t {
  int wavetable_id;
  byte channel;
  byte note;
};

voice_t voices[TOTAL_VOICES];

void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);

  delay(300);
  Serial.println("Waveform Modulation Test");
  
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(120);

  // Comment these out if not using the audio adaptor board.
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8); // caution: very loud - use oscilloscope only!
}

void loop() {
 
  
}
