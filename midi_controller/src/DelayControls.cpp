//
// Created by Leozor on 17/11/2024.
//

#include "DelayControls.h"
#include "Multiplexers.h"

CCPotentiometer DelayLFORate = {mux2.pin(11), {MIDI_CC::General_Purpose_Controller_3, Channel_13}};
CCPotentiometer DelayLFODepth = {mux2.pin(12), {MIDI_CC::General_Purpose_Controller_3, Channel_14}};
CCPotentiometer DelayTime = {mux2.pin(13), {MIDI_CC::General_Purpose_Controller_3, Channel_15}};
CCPotentiometer DelayFeedback = {mux2.pin(14), {MIDI_CC::General_Purpose_Controller_3, Channel_16}};
CCPotentiometer DelaySampleRate = {mux2.pin(15), {MIDI_CC::General_Purpose_Controller_4, Channel_1}};
CCPotentiometer DelayLowCutResonance = {mux3.pin(0), {MIDI_CC::General_Purpose_Controller_4, Channel_2}};
CCPotentiometer DelayLowCutFreq = {mux3.pin(1), {MIDI_CC::General_Purpose_Controller_4, Channel_3}};
CCPotentiometer DelayHighCutResonance = {mux3.pin(2), {MIDI_CC::General_Purpose_Controller_4, Channel_4}};
CCPotentiometer DelayHighCutFreq = {mux3.pin(3), {MIDI_CC::General_Purpose_Controller_4, Channel_5}};
CCPotentiometer DelayStereoWidth = {mux3.pin(4), {MIDI_CC::General_Purpose_Controller_4, Channel_6}};
CCPotentiometer DelayNoise = {mux3.pin(5), {MIDI_CC::General_Purpose_Controller_4, Channel_7}};
CCPotentiometer DelayLevel = {mux3.pin(6), {MIDI_CC::General_Purpose_Controller_4, Channel_8}};
CCButtonLatched DelayTapTempo = {A7, {MIDI_CC::General_Purpose_Controller_4, Channel_9}};
CCButtonLatching DelayType = {A8, {MIDI_CC::General_Purpose_Controller_4, Channel_10}};