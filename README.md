# The Audio Programmer You Tube Juce Tutorials 20 to 26 Adapted for Juce 6

### Menu

[Home](/README.md) | [Lesson Reference](/docs/lesson-reference/Lessons.md) | [std::unique_ptr](/docs/std-unique-ptr.md)

## Intro

### Acknowledgments

This Readme and the code in this repo have been pulled together to update The excellent Juce tutorials 
from [The Audio Programmer](https://theaudioprogrammer.com/), and those contained in the the [JUCE website](https://juce.com/) tutorials.  The purpose of this
is to update the Audio Programmer YouTube Juce series to make use of Juce 6, and the coding standards
it recommends.  

- [The Audio Programmer Juce Youtube Tutorials](https://www.youtube.com/playlist?list=PLLgJJsrdwhPxa6-02-CeHW8ocwSwl2jnu)
- [JUCE tutorials](https://docs.juce.com/learn/tutorials)

### Overall Guidance

-  The use of ```scopedPtr``` has now been superceded by ```std::unique_ptr<Type>```.  The benefits and complexities of this will be discussed elsewhere in the documentation.
-  Namespaces are now fully referenced in the code.  As a general rule, ```Using``` is no longer employed.  For Example you should see ```std::cout``` in the body of your code instead of ```using std``` then ```cout``` in the body of your code.  The intent here is to reduce the risk of namespace collisions.
-  For particularly long namespace or class references, you can use ```typedef```, keeping it to he most focused scope possible
(ie method first, then class).  

### Juce Plugin Host - Audio File Player Plugin for Juce 6

To aid with development, I've cobbled together a very basic but usable Audio File Player Pluginn for Juce 6.  A plugin already exists for Juce 5, but this fails to build on Juce 6.  Further information on this plugin can be found at https://github.com/Spyced-Concepts/AudioFilePlayerPlugin.

### YouTube Tutorial Specific Guidance

 - [Juce Tutorial 24 - Building a Synthesizer Part 4 (Controlling Parameters and UI)](docs/lesson-reference/juce-tutorial-24.md)



