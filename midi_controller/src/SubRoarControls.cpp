//
// Created by Leozor on 17/11/2024.
//

#include "SubRoarControls.h"
#include "Multiplexers.h"

CCPotentiometer SubRoarInGain = {mux4.pin(11), {MIDI_CC::General_Purpose_Controller_6, Channel_1}};
CCPotentiometer SubRoarLowPassFreq = {mux4.pin(12), {MIDI_CC::General_Purpose_Controller_6, Channel_2}};
CCPotentiometer SubRoarFold = {mux4.pin(13), {MIDI_CC::General_Purpose_Controller_6, Channel_3}};
CCPotentiometer SubRoarEmphasisFreq = {mux5.pin(0), {MIDI_CC::General_Purpose_Controller_6, Channel_4}};
CCPotentiometer SubRoarEmphasisGain = {mux5.pin(1), {MIDI_CC::General_Purpose_Controller_6, Channel_5}};
CCPotentiometer SubRoarReverbMix = {mux5.pin(2), {MIDI_CC::General_Purpose_Controller_6, Channel_6}};
CCPotentiometer SubRoarReverbRoomSize = {mux5.pin(3), {MIDI_CC::General_Purpose_Controller_6, Channel_7}};
CCPotentiometer SubRoarReverbDecay = {mux5.pin(4), {MIDI_CC::General_Purpose_Controller_6, Channel_8}};
CCPotentiometer SubRoarLevel = {mux5.pin(5), {MIDI_CC::General_Purpose_Controller_6, Channel_9}};
