/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SweetBellSynthAudioProcessorEditor::SweetBellSynthAudioProcessorEditor (SweetBellSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    
    attackSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1, 5000.00);
    attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20.0, 10.0);
    attackSlider.setValue(0.1);
    treeState = make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.state, "attack", attackSlider);
    addAndMakeVisible(&attackSlider);



}

SweetBellSynthAudioProcessorEditor::~SweetBellSynthAudioProcessorEditor()
{
}

//==============================================================================
void SweetBellSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    
}

void SweetBellSynthAudioProcessorEditor::resized()
{
    int margin = 20;
    attackSlider.setBounds(10, 10, 40, 100);

}

