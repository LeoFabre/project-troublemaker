#include <Arduino.h>
#include <Control_Surface.h>

USBMIDI_Interface midi_interface;

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 6
CD74HC4067 mux1 = {
    A10,
    {2, 3, 4, 5},
    6,
};

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 7
CD74HC4067 mux2 = {
    A10,
    {2, 3, 4, 5},
    7,
};

CCButton XHighSwitch = {mux2.pin(0), {MIDI_CC::General_Purpose_Controller_5, Channel_1}};
CCPotentiometer XHighAtk = {mux2.pin(1), {MIDI_CC::General_Purpose_Controller_5, Channel_2}};
CCPotentiometer XHighTresh = {mux2.pin(2), {MIDI_CC::General_Purpose_Controller_5, Channel_3}};
CCPotentiometer XHighRel = {mux2.pin(3), {MIDI_CC::General_Purpose_Controller_5, Channel_4}};
CCPotentiometer XHighGain = {mux2.pin(4), {MIDI_CC::General_Purpose_Controller_5, Channel_5}};

CCButton XMidSwitch = {mux2.pin(5), {MIDI_CC::General_Purpose_Controller_4, Channel_1}};
CCPotentiometer XMidAtk = {mux2.pin(6), {MIDI_CC::General_Purpose_Controller_4, Channel_2}};
CCPotentiometer XMidTresh = {mux2.pin(7), {MIDI_CC::General_Purpose_Controller_4, Channel_3}};
CCPotentiometer XMidRel = {mux2.pin(8), {MIDI_CC::General_Purpose_Controller_4, Channel_2}};
CCPotentiometer XMidGain = {mux2.pin(9), {MIDI_CC::General_Purpose_Controller_4, Channel_5}};

CCButton XBassSwitch = {mux2.pin(10), {MIDI_CC::General_Purpose_Controller_3, Channel_1}};
CCPotentiometer XBassAtk = {mux2.pin(11), {MIDI_CC::General_Purpose_Controller_3, Channel_2}};
CCPotentiometer XBassTresh = {mux2.pin(12), {MIDI_CC::General_Purpose_Controller_3, Channel_3}};
CCPotentiometer XBassRel = {mux2.pin(13), {MIDI_CC::General_Purpose_Controller_3, Channel_4}};
CCPotentiometer XBassGain = {mux2.pin(14), {MIDI_CC::General_Purpose_Controller_3, Channel_5}};

CCButton XSubSwitch = {mux1.pin(0), {MIDI_CC::General_Purpose_Controller_2, Channel_1}};
CCPotentiometer XSubAtk = {mux1.pin(1), {MIDI_CC::General_Purpose_Controller_2, Channel_2}};
CCPotentiometer XSubTresh = {mux1.pin(2), {MIDI_CC::General_Purpose_Controller_2, Channel_3}};
CCPotentiometer XSubRel = {mux1.pin(3), {MIDI_CC::General_Purpose_Controller_2, Channel_4}};
CCPotentiometer XSubGain = {mux1.pin(4), {MIDI_CC::General_Purpose_Controller_2, Channel_5}};

CCButton Eq2Switch = {mux1.pin(5), {MIDI_CC::General_Purpose_Controller_1, Channel_5}};
CCPotentiometer Eq2Freq = {mux1.pin(6), {MIDI_CC::General_Purpose_Controller_1, Channel_6}};
CCPotentiometer Eq2Gain = {mux1.pin(7), {MIDI_CC::General_Purpose_Controller_1, Channel_7}};
CCPotentiometer Eq2Q = {mux1.pin(8), {MIDI_CC::General_Purpose_Controller_1, Channel_8}};

CCPotentiometer InputGain = {mux1.pin(9), {MIDI_CC::General_Purpose_Controller_5, Channel_1}};

CCButton Eq1Switch = {mux1.pin(10), {MIDI_CC::General_Purpose_Controller_1, Channel_1}};
CCPotentiometer Eq1Freq = {mux1.pin(11), {MIDI_CC::General_Purpose_Controller_1, Channel_2}};
CCPotentiometer Eq1Gain = {mux1.pin(12), {MIDI_CC::General_Purpose_Controller_1, Channel_3}};
CCPotentiometer Eq1Q = {mux1.pin(13), {MIDI_CC::General_Purpose_Controller_1, Channel_4}};

void setup()
{
    Control_Surface.begin();
    Serial.begin(115200);
}

void loop()
{
    Control_Surface.loop();
}
