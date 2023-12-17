# Zynthethet
The Zyntheth will be a 4-6 operator 16 voices FM synthesis synth. It will have DIN-5 MIDI In, Thru and Out (from the Arpeggio). It will also have a USB-based Midi interface. There will also be support for Ethernet based RTP-MIDI.

It will have a stereo output (3.5mm plug) and it is powered by a regular micro-USB phone charger (500mA is enough). The user interface is a 3.5 inch touch LCD and 5 rotary encoders.

# Hardware
The hardware consists of 5 different pcb's:

The power board, takes the power from the micro-USB and converts it to 3.3v for other modules to run on.
The UI board, has the display and a connection for 1 encoder board with 5 encoders. It also has a Teensy 4.1 micro controller with 8Mb extra flash for graphics.
The Audio board, is the audio generator board with a Teensy 4.1 with 16Mb added PSRAM for additional effects usage.
The Interface board, has an Teensy 4.1 with ethernet interface added. This board takes care of all signals in and out from the Zyntheth (apart from the audio signals). It will also take care of arpeggio note generation.
Encoder board, a board with 5 rotary encoder and a button fitted to it. It has a SPI interface connection to the UI board.

# Functionality
4-6 operators (similar to DX9/DX7) FM synthesis in multiple algorithmic configuration
Individual envelope for each operator
Configurable detune, volume, panning for each operator
General envelope
Filter, 5-band parametric equlizer
Multiple effects: chorus, reverb, echo/delay, BitChrusher, Granular, etc.
Dual configurable LFO, either frequency, detune och volume
Configurable midi channel

# Todo
Add USB Audio output.
