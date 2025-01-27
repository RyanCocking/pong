# Pong

A clone of the classic arcade game, Pong. Written in C++ and SFML as a learning exercise.

## Compilation: Linux

        mkdir build
        cd build
        cmake ../
        make
        ./Pong
        
I haven't yet figured out a way to package it up statically for Linux.

## Compilation: Windows

On Windows 10, [install a C++ compiler via MYS2](https://code.visualstudio.com/docs/cpp/config-mingw). You will be able to run `gcc` and `g++` from the Windows command prompt.

Install the [version of SFML compiled with 64-bit MinGW](https://www.sfml-dev.org/download/sfml/2.5.1/), 
the same compiler you just installed.

[Build SFML on Windows](https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php) (you don't actually need to use CMake here).

Run `build.bat` from the command prompt. This is currently set up for dynamic linking.

In order to run the game, all the linked `.dll` and `.a` libraries must be included
inside the same directory as the executable (although the `.bat` currently links
against `.a` libraries inside the SFML source directory on Windows).

I think in an ideal situation, you would first copy the relevant `.dll` and `.a`
libraries into a project directory, with some organisation, and then you would
link against those libraries when compiling from `build.bat`. This way, the entire
project could be moved to another Windows machine and work.
