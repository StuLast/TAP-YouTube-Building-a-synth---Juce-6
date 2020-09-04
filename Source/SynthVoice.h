/*
  ==============================================================================
  ;
    SynthVoice.h
    Created: 4 Sep 2020 12:45:10pm
    Author:  stuar

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "maximilian.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound);
    void getParam(float attack);
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition);
    void stopNote(float velocity, bool allowTailOff);
    void pitchWheelMoved(int newPitchWheelValue);
    void controllerMoved(int controllerNumber, int newControllerValue);
    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples);

private:
    double level;
    double frequency;
    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;


};