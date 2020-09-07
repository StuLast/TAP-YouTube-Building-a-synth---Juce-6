# Juce Tutorial 22 - Building a Synthesizer Part 4 (Controlling Parameters and UI)

### Menu

[Home](/README.md) | [Lesson Reference](/docs/lesson-reference/Lessons.md) | [std::unique_ptr](/docs/std-unique-ptr.md)

[Youtube Tutorial link](https://www.youtube.com/watch?v=ddqwAJilnes&list=PLLgJJsrdwhPxa6-02-CeHW8ocwSwl2jnu&index=23)


## Notes on Lesson 22

### canPlaySound() (time index 1:20)

The first bit of code written in this video sits in the SynthVoice::canPlaySound method.  The use of the dynamic_cast function here is not
to actually output a dynamically cast type, but to see if the dynamic_cast is possible.  In essence, the code is saying 

"If I can cast the  pointer to juce::SynthesiserSound argument 'sound' to a pointer to type SynthSound, then the object pointed to by 'sound' 
must be of type SynthSound and so will be able to play sound." - assuming of course we've implemented it properly.  

The reason the casting works is that in C++, along with many other object oriented programming languages, a derived type is both it's own type 
and the type that it is derived from.  For example, a dog type can be derived from a canine type, and so a dog is both of type dog and type canine.
This is one of the fundamental principles of polymorphism.  

The dynamic_cast approach to the dog analogy would be to say "Can the pointer to the type animal passed in as an argument be converted to a dog and therefore
have all the characteristics of a dog?" 

The dynamic_cast function either returns a dog or says it can't be done by returning a null ptr.  In the same way, our own code tries to convert the more general pointer to type SynthesiserSound to a more specific pointer to type SynthSound.  If it fails it will return a nullptr rather than a pointer to the converted type.

The remaining part of our code simply compares the result of the dynamic_cast.  If the result is not a nullptr, a boolean "true" will be returned, if the 
dynamic cast fails though a boolean "false" is returned. Note that the conversion isn't assigned to a variable or pointer it is just "thrown away" once the function has completed.

In English we can write this as:

    "Try to convert the more generic type SynthesiserSound (identified by "sound") into my derived type SynthSound. If it works, return true because it will be able to play sound.  If it fails, return false because it doesn't have the features of SynthSound."


###
