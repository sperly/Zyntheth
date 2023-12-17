#include "midi.hpp"
#include "usb_midi.h"

void ZynthethMidi::Setup()
{
    //usbMIDI.setHandleNoteOff(handleKeypress);
    // {    
    //         usbMIDI.setHandleAfterTouchPoly(myAfterTouchPoly)
    //             usbMIDI.setHandleControlChange(myControlChange)
    //                 usbMIDI.setHandleProgramChange(myProgramChange)
    //                     usbMIDI.setHandleAfterTouch(myAfterTouch)
    //                         usbMIDI.setHandlePitchChange(myPitchChange)
    //                             usbMIDI.setHandleSystemExclusive(mySystemExclusiveChunk);
    // usbMIDI.setHandleTimeCodeQuarterFrame(myTimeCodeQuarterFrame);
    // usbMIDI.setHandleSongPosition(mySongPosition);
    // usbMIDI.setHandleSongSelect(mySongSelect);
    // usbMIDI.setHandleTuneRequest(myTuneRequest);
    // usbMIDI.setHandleClock(myClock);
    // usbMIDI.setHandleStart(myStart);
    // usbMIDI.setHandleContinue(myContinue);
    // usbMIDI.setHandleStop(myStop);
    // usbMIDI.setHandleActiveSensing(myActiveSensing);
    // usbMIDI.setHandleSystemReset(mySystemReset);
    // usbMIDI.setHandleRealTimeSystem(myRealTimeSystem);}
}

void ZynthethMidi::handleKeypress(uint8_t key, uint8_t sus, uint8_t vel)
{
}