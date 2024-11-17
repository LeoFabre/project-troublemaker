//
// Created by Leozor on 17/11/2024.
//

#include "GrainControls.h"
#include "Multiplexers.h"

//Grain controls
CCPotentiometer GrainPitch = {mux3.pin(7), {MIDI_CC::General_Purpose_Controller_4, Channel_11}};
CCPotentiometer GrainFine = {mux3.pin(8), {MIDI_CC::General_Purpose_Controller_4, Channel_12}};
CCPotentiometer GrainSize = {mux3.pin(9), {MIDI_CC::General_Purpose_Controller_4, Channel_13}};
CCPotentiometer GrainTexture = {mux3.pin(10), {MIDI_CC::General_Purpose_Controller_4, Channel_14}};
CCPotentiometer GrainStretch = {mux3.pin(11), {MIDI_CC::General_Purpose_Controller_4, Channel_15}};
CCPotentiometer GrainFeedback = {mux3.pin(12), {MIDI_CC::General_Purpose_Controller_4, Channel_16}};
CCPotentiometer GrainShimmer = {mux3.pin(13), {MIDI_CC::General_Purpose_Controller_5, Channel_1}};
CCPotentiometer GrainHighCut = {mux3.pin(14), {MIDI_CC::General_Purpose_Controller_5, Channel_2}};
CCPotentiometer GrainLevel = {mux3.pin(15), {MIDI_CC::General_Purpose_Controller_5, Channel_3}};
CCButtonLatching GrainType = {A14, {MIDI_CC::General_Purpose_Controller_5, Channel_4}};
CCButtonLatching GrainPlayback = {A15, {MIDI_CC::General_Purpose_Controller_5, Channel_5}};