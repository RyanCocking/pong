@echo off
:start
echo Compiling...
g++ -Wall -c src\main.cpp src\ball.cpp src\paddle.cpp src\score.cpp  -IE:\Code\Libraries\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\include -Iinclude
echo Linking...
g++ main.o ball.o paddle.o score.o -o main -LE:\Code\Libraries\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
echo Done