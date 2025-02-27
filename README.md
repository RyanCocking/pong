# Pong

A clone of the classic arcade game, Pong. Written in C++ and SFML 2.6 as a learning exercise.

![pong](https://github.com/user-attachments/assets/46f89c26-967d-4bb1-88cd-0fb6ae8cd4d2)

## Compilation: Linux

        mkdir build
        cd build
        cmake ../
        make
        ./Pong
        
I haven't yet figured out a way to package it up statically.

## Compilation: Windows 10

* [Install a C++ compiler](https://code.visualstudio.com/docs/cpp/config-mingw)
* [Install the latest version of SFML](https://www.sfml-dev.org/download/sfml/3.0.0)
* [Build SFML on Windows](https://www.sfml-dev.org/tutorials/3.0/getting-started/build-from-source)
* Run `build.bat` from the command prompt (dynamic linking)

In order to run the game, all the linked `.dll` and `.a` libraries must be included
inside the same directory as the executable (although the `.bat` currently links
against `.a` libraries inside the SFML source directory on Windows).

I think in an ideal situation, you would first copy the relevant `.dll` and `.a`
libraries into a project directory, with some organisation, and then you would
link against those libraries when compiling from `build.bat`. This way, the entire
project could be moved to another Windows machine and work.
