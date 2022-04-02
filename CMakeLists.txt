# https://dane-bulat.medium.com/cmake-building-sfml-and-game-projects-on-linux-3947b3ba6e8
# https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html

cmake_minimum_required(VERSION 3.19)
project(Pong VERSION 0.1)

# pass desired cpp standard to compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

# set build type to Debug unless otherwise specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug 
        CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# get SFML header files and modules. This assumes it was installed using:
# sudo apt-get install libsfml-dev
set(SFML_HEADERS 
    ${SFML_INCLUDE_DIR}/System 
    ${SFML_INCLUDE_DIR}/Window 
    ${SFML_INCLUDE_DIR}/Graphics 
    ${SFML_INCLUDE_DIR}/Network 
    ${SFML_INCLUDE_DIR}/Audio)

set(SFML_LIBS 
    sfml-system 
    sfml-window 
    sfml-graphics)

# compile source files
set(CPP_FILES 
    ${PROJECT_SOURCE_DIR}/src/main.cpp 
    ${PROJECT_SOURCE_DIR}/src/paddle.cpp 
    ${PROJECT_SOURCE_DIR}/src/ball.cpp)
add_executable(Pong ${CPP_FILES})

target_include_directories(Pong PRIVATE
    ${SFML_HEADERS} 
    ${PROJECT_SOURCE_DIR}/include)

# link our executable to the libraries that we need
target_link_libraries(Pong ${SFML_LIBS})