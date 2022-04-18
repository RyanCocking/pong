# Pong

A clone of the classic arcade game, Pong.

## Compilation

        mkdir build
        cd build
        cmake ../
        make
        ./Pong

A static binary can be shared and run across Linux operating systems without being recompiled each time. 

Creating a static binary with SFML is a bit complicated; you must link against SFML static libraries **and** their dependencies. 
* [Compile a standalone static executable](https://stackoverflow.com/questions/3283021/compile-a-standalone-static-executable) 
* [SFML static compilation](https://www.sfml-dev.org/faq.php#build-link-static) 
* [CMake static compilation](https://stackoverflow.com/questions/24648357/compiling-a-static-executable-with-cmake)
  
Binaries compiled on Linux cannot be run on Windows.

## X server graphics

blahblah

## X server audio

I could not get audio to work over WSL2, even with the guides being relatively straightforward. Windows 11 features this as a default.
