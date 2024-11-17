//
// Created by Leozor on 17/11/2024.
//

#include "ReverbControls.h"
#include "Multiplexers.h"

CCPotentiometer ReverbLowCutFreq = {mux5.pin(6), {MIDI_CC::General_Purpose_Controller_6, Channel_10}};
CCPotentiometer ReverbHighCutFreq = {mux5.pin(7), {MIDI_CC::General_Purpose_Controller_6, Channel_11}};
CCPotentiometer ReverbDecay = {mux5.pin(8), {MIDI_CC::General_Purpose_Controller_6, Channel_12}};
CCPotentiometer ReverbPreDelay = {mux5.pin(9), {MIDI_CC::General_Purpose_Controller_6, Channel_13}};
CCPotentiometer ReverbRoomSize = {mux5.pin(10), {MIDI_CC::General_Purpose_Controller_6, Channel_14}};
CCPotentiometer ReverbBellResonance = {mux5.pin(11), {MIDI_CC::General_Purpose_Controller_6, Channel_15}};
CCPotentiometer ReverbBellFrequency = {mux5.pin(12), {MIDI_CC::General_Purpose_Controller_6, Channel_16}};
CCPotentiometer ReverbLFODepth = {mux5.pin(13), {MIDI_CC::General_Purpose_Controller_7, Channel_1}};
CCPotentiometer ReverbLFORate = {mux5.pin(14), {MIDI_CC::General_Purpose_Controller_7, Channel_2}};
CCPotentiometer ReverbLevel = {mux5.pin(15), {MIDI_CC::General_Purpose_Controller_7, Channel_3}};
