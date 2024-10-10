#include <Arduino.h>
#include <Control_Surface.h>

USBMIDI_Interface midi_interface;

//Analog multiplexer on Arduino analog pin A0, enable pin on pin 6
CD74HC4067 mux1 = {
    A0,
    {2, 3, 4, 5},
    6,
};

//Analog multiplexer on Arduino analog pin A0, enable pin on pin 7
CD74HC4067 mux2 = {
    A0,
    {2, 3, 4, 5},
    7,
};

CCPotentiometer pot1 = {mux1.pin(0), {MIDI_CC::General_Purpose_Controller_1, Channel_1}};
CCPotentiometer pot2 = {mux1.pin(1), {MIDI_CC::General_Purpose_Controller_1, Channel_2}};
CCPotentiometer pot3 = {mux1.pin(2), {MIDI_CC::General_Purpose_Controller_1, Channel_3}};
CCPotentiometer pot4 = {mux1.pin(3), {MIDI_CC::General_Purpose_Controller_1, Channel_4}};
CCPotentiometer pot5 = {mux1.pin(4), {MIDI_CC::General_Purpose_Controller_1, Channel_5}};
CCPotentiometer pot6 = {mux1.pin(5), {MIDI_CC::General_Purpose_Controller_1, Channel_6}};
CCPotentiometer pot7 = {mux1.pin(6), {MIDI_CC::General_Purpose_Controller_1, Channel_7}};
CCPotentiometer pot8 = {mux1.pin(7), {MIDI_CC::General_Purpose_Controller_1, Channel_8}};

CCPotentiometer pot9 = {mux2.pin(0), {MIDI_CC::General_Purpose_Controller_1, Channel_9}};
CCPotentiometer pot10 = {mux2.pin(1), {MIDI_CC::General_Purpose_Controller_1, Channel_10}};
CCPotentiometer pot11 = {mux2.pin(2), {MIDI_CC::General_Purpose_Controller_1, Channel_11}};
CCPotentiometer pot12 = {mux2.pin(3), {MIDI_CC::General_Purpose_Controller_1, Channel_12}};
CCPotentiometer pot13 = {mux2.pin(4), {MIDI_CC::General_Purpose_Controller_1, Channel_13}};
CCPotentiometer pot14 = {mux2.pin(5), {MIDI_CC::General_Purpose_Controller_1, Channel_14}};
CCPotentiometer pot15 = {mux2.pin(6), {MIDI_CC::General_Purpose_Controller_1, Channel_15}};
CCPotentiometer pot16 = {mux2.pin(7), {MIDI_CC::General_Purpose_Controller_1, Channel_16}};

void setup()
{
    Control_Surface.begin();
    Serial.begin(115200);
    Serial.println("MIDI Controller Démarré sur Teensy");
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    Control_Surface.loop();
    Serial.println("the bitch is looping");
}
