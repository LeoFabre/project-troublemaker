//
// Created by Leozor on 17/11/2024.
//

#include "EqControls.h"
#include "Multiplexers.h"

CCButton Eq1Switch = {A1, {MIDI_CC::General_Purpose_Controller_2, Channel_1}};
CCPotentiometer Eq1Freq = {mux1.pin(5), {MIDI_CC::General_Purpose_Controller_2, Channel_2}};
CCPotentiometer Eq1Gain = {mux1.pin(6), {MIDI_CC::General_Purpose_Controller_2, Channel_3}};
CCPotentiometer Eq1Q = {mux1.pin(13), {MIDI_CC::General_Purpose_Controller_2, Channel_4}};

CCButton Eq2Switch = {A2, {MIDI_CC::General_Purpose_Controller_2, Channel_5}};
CCPotentiometer Eq2Freq = {mux1.pin(8), {MIDI_CC::General_Purpose_Controller_2, Channel_6}};
CCPotentiometer Eq2Gain = {mux1.pin(9), {MIDI_CC::General_Purpose_Controller_2, Channel_7}};
CCPotentiometer Eq2Q = {mux1.pin(10), {MIDI_CC::General_Purpose_Controller_2, Channel_8}};
