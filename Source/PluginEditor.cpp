/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainTutoAudioProcessorEditor::GainTutoAudioProcessorEditor (GainTutoAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    mGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mGainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
    mGainSlider.setRange(-60.0f, 0.0f, 0.01f);
    mGainSlider.setValue(-20.0f);
    mGainSlider.addListener(this);
    addAndMakeVisible(mGainSlider);
    setSize (400, 300);
}

GainTutoAudioProcessorEditor::~GainTutoAudioProcessorEditor()
{
}

//==============================================================================
void GainTutoAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(Colours::black);
}

void GainTutoAudioProcessorEditor::resized()
{
    mGainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
}

void GainTutoAudioProcessorEditor::sliderValueChanged(Slider* slider) {
    if (slider == &mGainSlider) {
        audioProcessor.mGain = mGainSlider.getValue();
    }
}