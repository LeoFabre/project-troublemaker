//
// Created by Leozor on 17/11/2024.
//

#include "CrossoverControls.h"
#include "Multiplexers.h"

CCButton XSubSwitch = {A3, {MIDI_CC::General_Purpose_Controller_2, Channel_9}};
CCPotentiometer XSubAtk = {mux1.pin(11), {MIDI_CC::General_Purpose_Controller_2, Channel_10}};
CCPotentiometer XSubRel = {mux1.pin(12), {MIDI_CC::General_Purpose_Controller_2, Channel_12}};
CCPotentiometer XSubTresh = {mux1.pin(13), {MIDI_CC::General_Purpose_Controller_2, Channel_11}};
CCPotentiometer XSubGain = {mux1.pin(14), {MIDI_CC::General_Purpose_Controller_2, Channel_13}};

CCButton XBassSwitch = {A4, {MIDI_CC::General_Purpose_Controller_2, Channel_14}};
CCPotentiometer XBassAtk = {mux1.pin(15), {MIDI_CC::General_Purpose_Controller_2, Channel_15}};
CCPotentiometer XBassRel = {mux2.pin(0), {MIDI_CC::General_Purpose_Controller_2, Channel_16}};
CCPotentiometer XBassTresh = {mux2.pin(1), {MIDI_CC::General_Purpose_Controller_3, Channel_1}};
CCPotentiometer XBassGain = {mux2.pin(2), {MIDI_CC::General_Purpose_Controller_3, Channel_2}};

CCButton XMidSwitch = {A5, {MIDI_CC::General_Purpose_Controller_3, Channel_3}};
CCPotentiometer XMidAtk = {mux2.pin(3), {MIDI_CC::General_Purpose_Controller_3, Channel_4}};
CCPotentiometer XMidRel = {mux2.pin(4), {MIDI_CC::General_Purpose_Controller_3, Channel_5}};
CCPotentiometer XMidTresh = {mux2.pin(5), {MIDI_CC::General_Purpose_Controller_3, Channel_6}};
CCPotentiometer XMidGain = {mux2.pin(6), {MIDI_CC::General_Purpose_Controller_3, Channel_7}};

CCButton XHighSwitch = {A6, {MIDI_CC::General_Purpose_Controller_3, Channel_8}};
CCPotentiometer XHighAtk = {mux2.pin(7), {MIDI_CC::General_Purpose_Controller_3, Channel_9}};
CCPotentiometer XHighRel = {mux2.pin(8), {MIDI_CC::General_Purpose_Controller_3, Channel_10}};
CCPotentiometer XHighTresh = {mux2.pin(9), {MIDI_CC::General_Purpose_Controller_3, Channel_11}};
CCPotentiometer XHighGain = {mux2.pin(10), {MIDI_CC::General_Purpose_Controller_3, Channel_12}};