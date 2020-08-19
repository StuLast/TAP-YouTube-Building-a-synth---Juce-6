/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TAPSynthTutorialAudioProcessorEditor::TAPSynthTutorialAudioProcessorEditor (TAPSynthTutorialAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    attackSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1, 5000.00);
    attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20.0, 10.0);
    attackSlider.setValue(0.1);
    sliderTree = make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "attack", attackSlider);
    addAndMakeVisible(&attackSlider);
}

TAPSynthTutorialAudioProcessorEditor::TAPSynthTutorialAudioProcessorEditor(TAPSynthTutorialAudioProcessor&, juce::AudioProcessorValueTreeState& vts)
{
}

TAPSynthTutorialAudioProcessorEditor::~TAPSynthTutorialAudioProcessorEditor()
{
}

//==============================================================================
void TAPSynthTutorialAudioProcessorEditor::paint (juce::Graphics& g)
{
    
}

void TAPSynthTutorialAudioProcessorEditor::resized()
{
    int margin = 20;
    attackSlider.setBounds(10, 10, 40, 100);
}

