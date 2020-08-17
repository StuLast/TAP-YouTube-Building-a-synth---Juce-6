/*
  ==============================================================================

    SynthSound.cpp
    Created: 13 Aug 2020 1:59:44pm
    Author:  stuar

  ==============================================================================
*/

#include "SynthSound.h"

bool SynthSound::appliesToNote(int midiNoteNumber)
{
    return true;
}

bool SynthSound::appliesToChannel(int midinChannel)
{
    return true;
}
