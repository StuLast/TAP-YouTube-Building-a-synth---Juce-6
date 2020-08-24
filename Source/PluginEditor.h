/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class TAPSynthTutorialAudioProcessorEditor :
    public juce::AudioProcessorEditor
{

typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

public:
    TAPSynthTutorialAudioProcessorEditor (TAPSynthTutorialAudioProcessor&, juce::AudioProcessorValueTreeState& vts);
    ~TAPSynthTutorialAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TAPSynthTutorialAudioProcessor& audioProcessor;
    juce::AudioProcessorValueTreeState& valueTreeState;
    juce::Slider attackSlider;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TAPSynthTutorialAudioProcessorEditor)
};
