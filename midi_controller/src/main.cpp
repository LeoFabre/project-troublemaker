#include <Arduino.h>
#include <Control_Surface.h>

USBMIDI_Interface midi_interface;

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 6
CD74HC4067 mux1 = {
    A0,
    {2, 3, 4, 5},
    6,
};

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 7
CD74HC4067 mux2 = {
    A0,
    {2, 3, 4, 5},
    7,
};

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 8
CD74HC4067 mux3 = {
    A0,
    {2, 3, 4, 5},
    8,
};

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 8
CD74HC4067 mux4 = {
    A0,
    {2, 3, 4, 5},
    9,
};

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 8
CD74HC4067 mux5 = {
    A0,
    {2, 3, 4, 5},
    10,
};

//Sampler controls
Button SamplerStop = {A9};
Button SamplerS1 = {32};
Button SamplerS2 = {31};
Button SamplerS3 = {30};
Button SamplerS4 = {29};
Button SamplerS5 = {28};
Button SamplerS6 = {A13};
Button SamplerS7 = {A12};
Button SamplerS8 = {A11};
Button SamplerS9 = {A10};
Button SamplerS10 = {12};
Button SamplerS11 = {11};
NoteButtons<12> samplerButtons(
    {
        SamplerStop,
        SamplerS1,
        SamplerS2,
        SamplerS3,
        SamplerS4,
        SamplerS5,
        SamplerS6,
        SamplerS7,
        SamplerS8,
        SamplerS9,
        SamplerS10,
        SamplerS11
    },
    {59, Channel_1}, // Adresse MIDI de base
    {1} // Incrément pour chaque bouton
);
CCPotentiometer SamplerSpeed = {mux1.pin(0), {0, Channel_1}};
CCPotentiometer SamplerReverb = {mux1.pin(1), {1, Channel_1}};
CCPotentiometer SamplerDelay = {mux1.pin(2), {2, Channel_1}};
CCPotentiometer SamplerGrain = {mux1.pin(3), {3, Channel_1}};
CCPotentiometer SamplerLevel = {mux1.pin(4), {4, Channel_1}};

//EQ controls
CCButton Eq1Switch = {A1, {0, Channel_2}};
CCPotentiometer Eq1Freq = {mux1.pin(5), {1, Channel_2}};
CCPotentiometer Eq1Gain = {mux1.pin(6), {2, Channel_2}};
CCPotentiometer Eq1Q = {mux1.pin(7), {3, Channel_2}};

CCButton Eq2Switch = {A2, {4, Channel_2}};
CCPotentiometer Eq2Freq = {mux1.pin(8), {5, Channel_2}};
CCPotentiometer Eq2Gain = {mux1.pin(9), {6, Channel_2}};
CCPotentiometer Eq2Q = {mux1.pin(10), {7, Channel_2}};

//Crossover controls
CCButton XSubSwitch = {A3, {0, Channel_3}};
CCPotentiometer XSubAtk = {mux1.pin(11), {1, Channel_3}};
CCPotentiometer XSubRel = {mux1.pin(12), {2, Channel_3}};
CCPotentiometer XSubTresh = {mux1.pin(13), {3, Channel_3}};
CCPotentiometer XSubGain = {mux1.pin(14), {4, Channel_3}};

CCButton XBassSwitch = {A4, {5, Channel_3}};
CCPotentiometer XBassAtk = {mux1.pin(15), {6, Channel_3}};
CCPotentiometer XBassRel = {mux2.pin(0), {7, Channel_3}};
CCPotentiometer XBassTresh = {mux2.pin(1), {8, Channel_3}};
CCPotentiometer XBassGain = {mux2.pin(2), {9, Channel_3}};

CCButton XMidSwitch = {A5, {10, Channel_3}};
CCPotentiometer XMidAtk = {mux2.pin(3), {11, Channel_3}};
CCPotentiometer XMidRel = {mux2.pin(4), {12, Channel_3}};
CCPotentiometer XMidTresh = {mux2.pin(5), {13, Channel_3}};
CCPotentiometer XMidGain = {mux2.pin(6), {14, Channel_3}};

CCButton XHighSwitch = {A6, {15, Channel_3}};
CCPotentiometer XHighAtk = {mux2.pin(7), {16, Channel_3}};
CCPotentiometer XHighRel = {mux2.pin(8), {17, Channel_3}};
CCPotentiometer XHighTresh = {mux2.pin(9), {18, Channel_3}};
CCPotentiometer XHighGain = {mux2.pin(10), {19, Channel_3}};

//Delay controls
CCPotentiometer DelayLFORate = {mux2.pin(11), {0, Channel_4}};
CCPotentiometer DelayLFODepth = {mux2.pin(12), {1, Channel_4}};
CCPotentiometer DelayTime = {mux2.pin(13), {2, Channel_4}};
CCPotentiometer DelayFeedback = {mux2.pin(14), {3, Channel_4}};
CCPotentiometer DelaySampleRate = {mux2.pin(15), {4, Channel_4}};
CCPotentiometer DelayLowCutResonance = {mux3.pin(0), {5, Channel_4}}; //Lowcut to be implemented
CCPotentiometer DelayLowCutFreq = {mux3.pin(1), {6, Channel_4}}; //Lowcut to be implemented
CCPotentiometer DelayHighCutResonance = {mux3.pin(2), {7, Channel_4}};
CCPotentiometer DelayHighCutFreq = {mux3.pin(3), {8, Channel_4}};
CCPotentiometer DelayStereoWidth = {mux3.pin(4), {9, Channel_4}};
CCPotentiometer DelayNoise = {mux3.pin(5), {10, Channel_4}};
CCPotentiometer DelayLevel = {mux3.pin(6), {11, Channel_4}};
CCButtonLatched DelayTapTempo = {A7, {12, Channel_4}};
CCButton DelayType = {A8, {13, Channel_4}};

//Grain controls
CCPotentiometer GrainPitch = {mux3.pin(7), {0, Channel_5}};
CCPotentiometer GrainFine = {mux3.pin(8), {1, Channel_5}};
CCPotentiometer GrainSize = {mux3.pin(9), {2, Channel_5}};
CCPotentiometer GrainTexture = {mux3.pin(10), {3, Channel_5}};
CCPotentiometer GrainStretch = {mux3.pin(11), {4, Channel_5}};
CCPotentiometer GrainFeedback = {mux3.pin(12), {5, Channel_5}};
CCPotentiometer GrainShimmer = {mux3.pin(13), {6, Channel_5}};
CCPotentiometer GrainHighCut = {mux3.pin(14), {7, Channel_5}};
CCPotentiometer GrainLevel = {mux3.pin(15), {8, Channel_5}};
CCButton GrainType = {A14, {9, Channel_5}};
CCButton GrainPlayback = {A15, {10, Channel_5}};

//Inputs controls
CCPotentiometer InputAGain = {mux4.pin(0), {0, Channel_6}};
CCPotentiometer InputADelaySend = {mux4.pin(2), {1, Channel_6}};
CCPotentiometer InputAGrainSend = {mux4.pin(4), {2, Channel_6}};
CCPotentiometer InputASubRoarSend = {mux4.pin(6), {3, Channel_6}};
CCPotentiometer InputAReverbSend = {mux4.pin(8), {4, Channel_6}};
// CCPotentiometer InputAAuxSend = {mux4.pin(10), {5, Channel_6}};

//no input b for now, stereo input only
// CCPotentiometer InputBGain = {mux4.pin(1), {6, Channel_12}};
// CCPotentiometer InputBDelaySend = {mux4.pin(3), {7, Channel_13}};
// CCPotentiometer InputBGrainSend = {mux4.pin(5), {8, Channel_14}};
// CCPotentiometer InputBSubRoarSend = {mux4.pin(7), {9, Channel_15}};
// CCPotentiometer InputBReverbSend = {mux4.pin(9), {10, Channel_16}};

//Sub roar controls
CCPotentiometer SubRoarInGain = {mux4.pin(11), {0, Channel_7}};
CCPotentiometer SubRoarLowPassFreq = {mux4.pin(12), {1, Channel_7}};
CCPotentiometer SubRoarFold = {mux4.pin(13), {2, Channel_7}};
CCPotentiometer SubRoarEmphasisFreq = {mux5.pin(0), {3, Channel_7}};
CCPotentiometer SubRoarEmphasisGain = {mux5.pin(1), {4, Channel_7}};
CCPotentiometer SubRoarReverbMix = {mux5.pin(2), {5, Channel_7}};
CCPotentiometer SubRoarReverbRoomSize = {mux5.pin(3), {6, Channel_7}};
CCPotentiometer SubRoarReverbDecay = {mux5.pin(4), {7, Channel_7}};
CCPotentiometer SubRoarLevel = {mux5.pin(5), {8, Channel_7}};

//Reverb controls
CCPotentiometer ReverbLowCutFreq = {mux5.pin(6), {0, Channel_8}};
CCPotentiometer ReverbHighCutFreq = {mux5.pin(7), {1, Channel_8}};
CCPotentiometer ReverbDecay = {mux5.pin(8), {2, Channel_8}};
CCPotentiometer ReverbPreDelay = {mux5.pin(9), {3, Channel_8}};
CCPotentiometer ReverbRoomSize = {mux5.pin(10), {4, Channel_8}};
CCPotentiometer ReverbBellResonance = {mux5.pin(11), {5, Channel_8}};
CCPotentiometer ReverbBellFrequency = {mux5.pin(12), {6, Channel_8}};
CCPotentiometer ReverbLFODepth = {mux5.pin(13), {7, Channel_8}};
CCPotentiometer ReverbLFORate = {mux5.pin(14), {8, Channel_8}};
CCPotentiometer ReverbLevel = {mux5.pin(15), {9, Channel_8}};

constexpr analog_t maxRawValue = CCPotentiometer::getMaxRawValue();
constexpr analog_t minimumValue = maxRawValue / 64;
constexpr analog_t maximumValue = maxRawValue - maxRawValue / 64;

analog_t fixDeadZoneAndInvertPot(analog_t raw) {
    // make sure that the analog value is between the minimum and maximum
    raw = constrain(raw, minimumValue, maximumValue);
    // map the value from [minimumValue, maximumValue] to [0, maxRawValue]
    analog_t fixedDeadZone = map(raw, minimumValue, maximumValue, 0, maxRawValue);
    // invert the value
    return maxRawValue - fixedDeadZone;
}

analog_t fixDeadZone(analog_t raw) {
    // make sure that the analog value is between the minimum and maximum
    raw = constrain(raw, minimumValue, maximumValue);
    // map the value from [minimumValue, maximumValue] to [0, maxRawValue]
    return map(raw, minimumValue, maximumValue, 0, maxRawValue);
}

void setup()
{
    Control_Surface.begin();
    samplerButtons.begin();

    SamplerSpeed.map(fixDeadZoneAndInvertPot);
    SamplerReverb.map(fixDeadZoneAndInvertPot);
    SamplerDelay.map(fixDeadZoneAndInvertPot);
    SamplerGrain.map(fixDeadZoneAndInvertPot);
    SamplerLevel.map(fixDeadZoneAndInvertPot);

    Eq1Freq.map(fixDeadZoneAndInvertPot);
    Eq1Gain.map(fixDeadZoneAndInvertPot);
    Eq1Q.map(fixDeadZoneAndInvertPot);
    Eq2Freq.map(fixDeadZoneAndInvertPot);
    Eq2Gain.map(fixDeadZoneAndInvertPot);
    Eq2Q.map(fixDeadZoneAndInvertPot);

    XSubSwitch.invert();
    XSubAtk.map(fixDeadZoneAndInvertPot);
    XSubRel.map(fixDeadZoneAndInvertPot);
    XSubTresh.map(fixDeadZoneAndInvertPot);
    XSubGain.map(fixDeadZoneAndInvertPot);
    XBassSwitch.invert();
    XBassAtk.map(fixDeadZoneAndInvertPot);
    XBassRel.map(fixDeadZoneAndInvertPot);
    XBassTresh.map(fixDeadZoneAndInvertPot);
    XBassGain.map(fixDeadZoneAndInvertPot);
    XMidSwitch.invert();
    XMidAtk.map(fixDeadZoneAndInvertPot);
    XMidRel.map(fixDeadZoneAndInvertPot);
    XMidTresh.map(fixDeadZoneAndInvertPot);
    XMidGain.map(fixDeadZoneAndInvertPot);
    XHighSwitch.invert();
    XHighAtk.map(fixDeadZoneAndInvertPot);
    XHighRel.map(fixDeadZoneAndInvertPot);
    XHighTresh.map(fixDeadZoneAndInvertPot);
    XHighGain.map(fixDeadZoneAndInvertPot);

    DelayLFORate.map(fixDeadZoneAndInvertPot);
    DelayLFODepth.map(fixDeadZoneAndInvertPot);
    DelayTime.map(fixDeadZone);
    DelayFeedback.map(fixDeadZoneAndInvertPot);
    DelaySampleRate.map(fixDeadZoneAndInvertPot);
    DelayLowCutFreq.map(fixDeadZoneAndInvertPot);
    DelayLowCutResonance.map(fixDeadZoneAndInvertPot);
    DelayHighCutResonance.map(fixDeadZoneAndInvertPot);
    DelayHighCutFreq.map(fixDeadZoneAndInvertPot);
    DelayStereoWidth.map(fixDeadZoneAndInvertPot);
    DelayNoise.map(fixDeadZoneAndInvertPot);
    DelayLevel.map(fixDeadZoneAndInvertPot);

    GrainPitch.map(fixDeadZoneAndInvertPot);
    GrainFine.map(fixDeadZoneAndInvertPot);
    GrainSize.map(fixDeadZoneAndInvertPot);
    GrainTexture.map(fixDeadZoneAndInvertPot);
    GrainStretch.map(fixDeadZoneAndInvertPot);
    GrainFeedback.map(fixDeadZoneAndInvertPot);
    GrainShimmer.map(fixDeadZoneAndInvertPot);
    GrainHighCut.map(fixDeadZoneAndInvertPot);
    GrainLevel.map(fixDeadZoneAndInvertPot);
    GrainType.invert();
    GrainPlayback.invert();

    InputAGain.map(fixDeadZoneAndInvertPot);
    InputADelaySend.map(fixDeadZoneAndInvertPot);
    InputAGrainSend.map(fixDeadZoneAndInvertPot);
    InputASubRoarSend.map(fixDeadZoneAndInvertPot);
    InputAReverbSend.map(fixDeadZoneAndInvertPot);

    SubRoarInGain.map(fixDeadZoneAndInvertPot);
    SubRoarLowPassFreq.map(fixDeadZoneAndInvertPot);
    SubRoarFold.map(fixDeadZoneAndInvertPot);
    SubRoarEmphasisFreq.map(fixDeadZoneAndInvertPot);
    SubRoarEmphasisGain.map(fixDeadZoneAndInvertPot);
    SubRoarReverbMix.map(fixDeadZoneAndInvertPot);
    SubRoarReverbRoomSize.map(fixDeadZoneAndInvertPot);
    SubRoarReverbDecay.map(fixDeadZoneAndInvertPot);
    SubRoarLevel.map(fixDeadZoneAndInvertPot);

    ReverbLowCutFreq.map(fixDeadZoneAndInvertPot);
    ReverbHighCutFreq.map(fixDeadZoneAndInvertPot);
    ReverbDecay.map(fixDeadZoneAndInvertPot);
    ReverbPreDelay.map(fixDeadZoneAndInvertPot);
    ReverbRoomSize.map(fixDeadZoneAndInvertPot);
    ReverbBellResonance.map(fixDeadZoneAndInvertPot);
    ReverbBellFrequency.map(fixDeadZoneAndInvertPot);
    ReverbLFODepth.map(fixDeadZoneAndInvertPot);
    ReverbLFORate.map(fixDeadZoneAndInvertPot);
    ReverbLevel.map(fixDeadZoneAndInvertPot);

    Serial.begin(115200);
}

void loop()
{
    Control_Surface.loop();
    samplerButtons.update();
}
