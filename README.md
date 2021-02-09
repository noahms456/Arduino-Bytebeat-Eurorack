# Arduino-Bytebeat-Eurorack
this is based on stimmer's code from the arduino forums, based on Viznut's work
see viznut's blog http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html
and http://www.youtube.com/watch?v=GtQdIYUtAHg&feature=related

So all this does is take the original code, add an X and Y input with pots, and a "function" selector with a button.

It's compiled and it works on my Uno, but the pushbutton function selector functionality does not respond. I think it's something to do with the looping nature of the writing to the pin 10, but I'm new to Arduino coding.

The first function is obnoxious and terrible with the X and Y changing, but it proves the concept.

Once i've hashed out why I can't get it to change functions, I'll send the thing out into the world and hope for the best!

A planned feature is the ability to slow the velocity of the noise generated, but I'm not quite sure how to do it, yet.
