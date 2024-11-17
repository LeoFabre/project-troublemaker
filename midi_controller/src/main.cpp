#include <Arduino.h>
#include <Control_Surface.h>

//Check out these header files for the controls implementation.

#include "CrossoverControls.h"
#include "DelayControls.h"
#include "SamplerControls.h"
#include "EqControls.h"
#include "ReverbControls.h"
#include "InputsControls.h"

USBMIDI_Interface midi_interface;

void setup()
{
    Control_Surface.begin();
    Serial.begin(115200);
}

void loop()
{
    Control_Surface.loop();
}
