/*
  ==============================================================================

    SynthSound.h
    Created: 4 Sep 2020 12:44:48pm
    Author:  stuar

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote(int midiNoteNumber);
    bool appliesToChannel(int channelNumber);

private:
};