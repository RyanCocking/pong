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

* [Play audio files from terminal](https://askubuntu.com/questions/920539/how-do-you-play-a-sound-from-the-terminal)
* [Play audio over an X server on WSL2](https://www.linuxuprising.com/2021/03/how-to-get-sound-pulseaudio-to-work-on.html)

You must set up WSL2 to enable audio over an X server, to avoid errors such as:

        play exampleSound.wav

        ALSA lib confmisc.c:767:(parse_card) cannot find card '0'               
        ALSA lib conf.c:4528:(_snd_config_evaluate) function snd_func_card_driver returned error: No such file or directory                             
        ALSA lib confmisc.c:392:(snd_func_concat) error evaluating strings      
        ALSA lib conf.c:4528:(_snd_config_evaluate) function snd_func_concat returned error: No such file or directory                                  
        ALSA lib confmisc.c:1246:(snd_func_refer) error evaluating name         
        ALSA lib conf.c:4528:(_snd_config_evaluate) function snd_func_refer returned error: No such file or directory                                   
        ALSA lib conf.c:5007:(snd_config_expand) Evaluate error: No such file or directory                                                              
        ALSA lib pcm.c:2495:(snd_pcm_open_noupdate) Unknown PCM default         
        play FAIL sox: Sorry, there is no default audio device configured 
