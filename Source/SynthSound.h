/*
  ==============================================================================

    SynthSound.h
    Created: 13 Aug 2020 1:59:44pm
    Author:  stuar

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:

    bool appliesToNote(int midiNoteNumber);
    bool appliesToChannel(int midinChannel);

private:
};