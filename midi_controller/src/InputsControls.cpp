//
// Created by Leozor on 17/11/2024.
//

#include "InputsControls.h"
#include "Multiplexers.h"

CCPotentiometer InputAGain = {mux4.pin(0), {MIDI_CC::General_Purpose_Controller_5, Channel_6}};
CCPotentiometer InputADelaySend = {mux4.pin(2), {MIDI_CC::General_Purpose_Controller_5, Channel_7}};
CCPotentiometer InputAGrainSend = {mux4.pin(4), {MIDI_CC::General_Purpose_Controller_5, Channel_8}};
CCPotentiometer InputASubRoarSend = {mux4.pin(6), {MIDI_CC::General_Purpose_Controller_5, Channel_9}};
CCPotentiometer InputAReverbSend = {mux4.pin(8), {MIDI_CC::General_Purpose_Controller_5, Channel_10}};
CCPotentiometer InputAAuxSend = {mux4.pin(10), {MIDI_CC::General_Purpose_Controller_5, Channel_11}};

CCPotentiometer InputBGain = {mux4.pin(1), {MIDI_CC::General_Purpose_Controller_5, Channel_12}};
CCPotentiometer InputBDelaySend = {mux4.pin(3), {MIDI_CC::General_Purpose_Controller_5, Channel_13}};
CCPotentiometer InputBGrainSend = {mux4.pin(5), {MIDI_CC::General_Purpose_Controller_5, Channel_14}};
CCPotentiometer InputBSubRoarSend = {mux4.pin(7), {MIDI_CC::General_Purpose_Controller_5, Channel_15}};
CCPotentiometer InputBReverbSend = {mux4.pin(9), {MIDI_CC::General_Purpose_Controller_5, Channel_16}};
