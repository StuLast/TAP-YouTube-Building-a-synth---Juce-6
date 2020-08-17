/*
  ==============================================================================

    SynthVoice.cpp
    Created: 13 Aug 2020 2:00:03pm
    Author:  stuar

  ==============================================================================
*/

#include "SynthVoice.h"

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound)
{
    return dynamic_cast<SynthSound*>(sound) != nullptr;
}

void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
    frequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);

    //@TODO remove debugging code
    std::string debugMessage = "Midi Note: " + std::to_string(midiNoteNumber) + ": Hz: " + std::to_string(frequency);
    juce::Logger::outputDebugString(debugMessage);
    std::cout << "Midi Note: " << midiNoteNumber << std::endl;
    std::cout << "Hz: " << frequency << std::endl;
    //@END debug code
}

void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
    clearCurrentNote();
}

void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{
}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{
}


