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

void SynthVoice::getParam(float attack)
{
    juce::String message = "Attack reported to : " + std::to_string(attack);
    juce::Logger::outputDebugString(message);
    env1.setAttack(double(attack));
    env1.setDecay(500);
    env1.setSustain(0.8);
    env1.setRelease(2000);
}

void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
    env1.trigger = 1;

    level = velocity;
    frequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);

}

void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
    env1.trigger = 0;
    allowTailOff = true;
    if (velocity == 0) {
        clearCurrentNote();
    }
}

void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    



    for (int sample = 0; sample < numSamples; ++sample)
    {
        double theWave = osc1.saw(frequency);
        double theSound = env1.adsr(theWave, env1.trigger) * level;
        double filteredSound = filter1.lores(theSound, 200, 0.2);

        for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
        {
            outputBuffer.addSample(channel, startSample, filteredSound);
        }

        ++startSample;
    }
}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{
}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{
}


