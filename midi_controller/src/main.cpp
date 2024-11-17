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

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 8
CD74HC4067 mux3 = {
    A10,
    {2, 3, 4, 5},
    8,
};

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 8
CD74HC4067 mux4 = {
    A10,
    {2, 3, 4, 5},
    9,
};

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 8
CD74HC4067 mux5 = {
    A10,
    {2, 3, 4, 5},
    10,
};

//Sampler controls
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

//EQ controls
CCButton Eq1Switch = {A1, {MIDI_CC::General_Purpose_Controller_2, Channel_1}};
CCPotentiometer Eq1Freq = {mux1.pin(5), {MIDI_CC::General_Purpose_Controller_2, Channel_2}};
CCPotentiometer Eq1Gain = {mux1.pin(6), {MIDI_CC::General_Purpose_Controller_2, Channel_3}};
CCPotentiometer Eq1Q = {mux1.pin(13), {MIDI_CC::General_Purpose_Controller_2, Channel_4}};

CCButton Eq2Switch = {A2, {MIDI_CC::General_Purpose_Controller_2, Channel_5}};
CCPotentiometer Eq2Freq = {mux1.pin(8), {MIDI_CC::General_Purpose_Controller_2, Channel_6}};
CCPotentiometer Eq2Gain = {mux1.pin(9), {MIDI_CC::General_Purpose_Controller_2, Channel_7}};
CCPotentiometer Eq2Q = {mux1.pin(10), {MIDI_CC::General_Purpose_Controller_2, Channel_8}};

//Crossover controls
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

//Delay controls
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

//Inputs controls
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

//Sub roar controls
CCPotentiometer SubRoarInGain = {mux4.pin(11), {MIDI_CC::General_Purpose_Controller_6, Channel_1}};
CCPotentiometer SubRoarLowPassFreq = {mux4.pin(12), {MIDI_CC::General_Purpose_Controller_6, Channel_2}};
CCPotentiometer SubRoarFold = {mux4.pin(13), {MIDI_CC::General_Purpose_Controller_6, Channel_3}};
CCPotentiometer SubRoarEmphasisFreq = {mux5.pin(0), {MIDI_CC::General_Purpose_Controller_6, Channel_4}};
CCPotentiometer SubRoarEmphasisGain = {mux5.pin(1), {MIDI_CC::General_Purpose_Controller_6, Channel_5}};
CCPotentiometer SubRoarReverbMix = {mux5.pin(2), {MIDI_CC::General_Purpose_Controller_6, Channel_6}};
CCPotentiometer SubRoarReverbRoomSize = {mux5.pin(3), {MIDI_CC::General_Purpose_Controller_6, Channel_7}};
CCPotentiometer SubRoarReverbDecay = {mux5.pin(4), {MIDI_CC::General_Purpose_Controller_6, Channel_8}};
CCPotentiometer SubRoarLevel = {mux5.pin(5), {MIDI_CC::General_Purpose_Controller_6, Channel_9}};

//Reverb controls
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

void setup()
{
    Control_Surface.begin();
    Serial.begin(115200);
}

void loop()
{
    Control_Surface.loop();
}
