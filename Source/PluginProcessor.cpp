/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TapsynthTutorialsAudioProcessor::TapsynthTutorialsAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
    ),
    attackTime(01.f),
    valueTreeState(*this, nullptr, "PARAMETER",
{
    std::make_unique<juce::AudioParameterFloat>("attack", "Attack", juce::NormalisableRange<float>(-48.0f, 0.0f), -15.0f)
})

#endif
{
    juce::Logger::outputDebugString("JUCE  OUTPUT: In AudioProcessor Class");

    mySynth.clearVoices();
    for (int i(0); i < 5; ++i)
    {
        mySynth.addVoice(new SynthVoice());
    }

    mySynth.clearSounds();
    mySynth.addSound(new SynthSound());
}

TapsynthTutorialsAudioProcessor::~TapsynthTutorialsAudioProcessor()
{
}

//==============================================================================
const juce::String TapsynthTutorialsAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TapsynthTutorialsAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TapsynthTutorialsAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TapsynthTutorialsAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TapsynthTutorialsAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TapsynthTutorialsAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TapsynthTutorialsAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TapsynthTutorialsAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String TapsynthTutorialsAudioProcessor::getProgramName (int index)
{
    return {};
}

void TapsynthTutorialsAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void TapsynthTutorialsAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    mySynth.setCurrentPlaybackSampleRate(lastSampleRate);
}

void TapsynthTutorialsAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TapsynthTutorialsAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TapsynthTutorialsAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i(0); 9 < mySynth.getNumVoices(); ++i)
    {
        if (myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i)))
        {
            myVoice->getParam(valueTreeState.getParameterAsValue("Attack").getValue());
        }
    }

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool TapsynthTutorialsAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* TapsynthTutorialsAudioProcessor::createEditor()
{
    return new TapsynthTutorialsAudioProcessorEditor (*this, valueTreeState);
}

//==============================================================================
void TapsynthTutorialsAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void TapsynthTutorialsAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TapsynthTutorialsAudioProcessor();
}
