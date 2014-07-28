IndieBoy
========

Simple C++ based game engine intended for use in the creation of 2D games.

Somewhat incomplete. See TODO.txt for list of things still needed.

To compile, use GCC 4.7.x (4.8.x will not work, due to bugs).
You'll have to enable C++11 features (Add the -std=c++11 flag to your compiler flags)
It only requires one library, SFML 2.1. Link in the following:
 libsfml-graphics
 libsfml-audio
 libsfml-window
 libsfml-system
 libsfml-main
 
To make distribution easier, you may want to statically link libgcc and libstdc++.
To do this, add the following linker options:
 -static-libgcc
 -static-libstdc++
 
Untested on Linux/Mac. May or may not work.
