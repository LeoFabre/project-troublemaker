//
// Created by Leozor on 17/11/2024.
//
#include "SamplerControls.h"

CCButton SamplerS1 = {11, {MIDI_CC::General_Purpose_Controller_1, Channel_1}};
CCButton SamplerS2 = {12, {MIDI_CC::General_Purpose_Controller_1, Channel_2}};
CCButton SamplerS3 = {A10, {MIDI_CC::General_Purpose_Controller_1, Channel_3}};
CCButton SamplerS4 = {A11, {MIDI_CC::General_Purpose_Controller_1, Channel_4}};
CCButton SamplerS5 = {A12, {MIDI_CC::General_Purpose_Controller_1, Channel_5}};
CCButton SamplerS6 = {A13, {MIDI_CC::General_Purpose_Controller_1, Channel_6}};
CCButton SamplerS7 = {28, {MIDI_CC::General_Purpose_Controller_1, Channel_7}};
CCButton SamplerS8 = {29, {MIDI_CC::General_Purpose_Controller_1, Channel_8}};
CCButton SamplerS9 = {30, {MIDI_CC::General_Purpose_Controller_1, Channel_9}};
CCButton SamplerS10 = {31, {MIDI_CC::General_Purpose_Controller_1, Channel_10}};
CCButton SamplerS11 = {32, {MIDI_CC::General_Purpose_Controller_1, Channel_11}};
CCButton SamplerStop = {A9, {MIDI_CC::General_Purpose_Controller_1, Channel_12}};
CCPotentiometer SamplerSpeed = {mux1.pin(0), {MIDI_CC::General_Purpose_Controller_1, Channel_13}};
CCPotentiometer SamplerReverb = {mux1.pin(1), {MIDI_CC::General_Purpose_Controller_1, Channel_14}};
CCPotentiometer SamplerDelay = {mux1.pin(2), {MIDI_CC::General_Purpose_Controller_1, Channel_15}};
CCPotentiometer SamplerGrain = {mux1.pin(3), {MIDI_CC::General_Purpose_Controller_1, Channel_16}};
CCPotentiometer SamplerLevel = {mux1.pin(4), {MIDI_CC::General_Purpose_Controller_2, Channel_1}};