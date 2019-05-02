# Breakout
Breakout was a popular Arcade Game, created by Atari, Inc, written by  Nolan Bushnell, Steve Wozniak, and Steve Bristow.
## Abstract
This project is an implementation of the popular Arcade Game, developed by Atari, Inc.

Our implementation features a custom Physics engine, coded from scratch. We have taken inspiration for the gameplay from the original, but kept it as simple as possible.

## Proposed System
###### Todo: Update this section as new features arrive
 
The game currently consists of 5 rows of 10 bricks each. Once all bricks are destroyed, the ball keeps bouncing around indefinitely.

The color of each brick is randomly generated. The paddle is always Red, and the ball is always White.

Collision angles are all set to 45 degrees. The direction of the ball changes based on which side (left or right) of the paddles it collides with.
Other than that, collisions obey the laws of reflection. No friction, acceleration or retardation of any kind has been considered in the physics of the game.

Concepts of Object Oriented Programming, namely Data Encapsulation, Data Hiding, Inheritance and Polymorphism have been used heavily in the design. Each object of the game has a corresponding class associated with it.

A _Collider_ class has been used to simulate physical collisions. All collisions are handled by their callback interfaces, which are different for different pairs of colliding objects.

A _Color_ class is used as a placeholder for the RGB color values of different objects.

All classes, with exception of the above mentioned _Collider_ and _Color_, inherit from an abstract class _GameObject_. This class provides a set of functions used for interacting with the 2D cartesian surface, on which all objects are drawn. In OpenGL, this is the ViewPort.

The size of the ViewPort has been set to 600 pixels by 600 pixels.

All animations take place as translations. The OpenGL Library function `glTranslatef` has been used for this purpose. In an earlier implementation of this project, translation was achieved by manually calculating the new coordinates of the object to be animated.

A constant frame rate of 120 FPS has been used. This has been implemented using the `glutTimerFunc` callback. All controls are keyboard based. Mouse controls have not been implemented.

The `display` callback has been reserved for drawing purposes only. All calculations are done outside this function.

## System Requirements
### Software

- Operating Systems:
  - Supported
    - Windows
    - MacOS
    - Linux
    
  - Tested on
    - Windows 10
    - MacOS 10.13 High Sierra
    - Ubuntu 18.04 Bionic Beaver with GNOME 3 Desktop
    - Ubuntu 18.10 Cosmic Cuttlefish with GNOME 3 Desktop
    
- Compiler and Libraries
  - GNU g++ compiler version 6.5.0 x86_64
  - Microsoft Visual C++ compiler
  - C++11 standard libraries
  - OpenGL >= 1.0 with GLU and GLUT
  
- Build methods:
  - Linux shell command
  - Cmake makefile

- IDEs/Editors used:
  - CLion
  - XCode
  - Visual Studio
  - Gedit
  - Kate
  - Visual Studio Code
  - Sublime Text
  
### Hardware

- Supported Processor Architectures:
  - Intel x86_64
    
- Graphics Processors:
  - Supported
    - Intel Integrated Graphics
    - All Nvidia Graphics Processors
    - All AMD Graphics Processors
    - Misc Graphics Processors, compatible with x86_64 based processors
  
  - Tested on:
    - Intel Integrated Graphics
    - Nvidia GeForce 930M
    - Nvidia GeForce GTX 1080Ti
    
 - Miscellaneous hardware required:
   - Keyboard
   - Display with resolution >= 600 pixels by 600 pixels