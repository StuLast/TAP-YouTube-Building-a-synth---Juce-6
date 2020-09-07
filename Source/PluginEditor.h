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
class TapsynthTutorialsAudioProcessorEditor  : public juce::AudioProcessorEditor
{
    typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

public:
    TapsynthTutorialsAudioProcessorEditor (TapsynthTutorialsAudioProcessor&, juce::AudioProcessorValueTreeState& vts);
    ~TapsynthTutorialsAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TapsynthTutorialsAudioProcessor& audioProcessor;
    juce::AudioProcessorValueTreeState& valueTreeState;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attackSliderAttachment;
    juce::Slider attackSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TapsynthTutorialsAudioProcessorEditor)
};
