# https://dane-bulat.medium.com/cmake-building-sfml-and-game-projects-on-linux-3947b3ba6e8
# https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html
# https://tomranner.org/post/cmake-config/

cmake_minimum_required(VERSION 3.19)
project(Pong)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_ASSET_DIR "${PROJECT_SOURCE_DIR}/assets")

# pass desired cpp standard to compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

# set build type to Debug unless otherwise specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug 
        CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# create a configuration header file from some input, allowing us to access
# certain cmake variables from within our source code.
configure_file("${PROJECT_SOURCE_DIR}/include/config.h.in" 
    "${PROJECT_BINARY_DIR}/include/config.h")

# get SFML header files and modules. This assumes it was installed using:
# sudo apt-get install libsfml-dev, and the include dir is already set.
set(SFML_HEADERS 
    "${SFML_INCLUDE_DIR}/System" 
    "${SFML_INCLUDE_DIR}/Window" 
    "${SFML_INCLUDE_DIR}/Graphics" 
    "${SFML_INCLUDE_DIR}/Network" 
    "${SFML_INCLUDE_DIR}/Audio")

set(SFML_LIBS 
    "sfml-system" 
    "sfml-window" 
    "sfml-graphics")

# compile source files
set(CPP_FILES 
    "${PROJECT_SOURCE_DIR}/src/main.cpp" 
    "${PROJECT_SOURCE_DIR}/src/paddle.cpp" 
    "${PROJECT_SOURCE_DIR}/src/ball.cpp")
add_executable(Pong "${CPP_FILES}")

target_include_directories(Pong PRIVATE
    "${SFML_HEADERS}" 
    "${PROJECT_SOURCE_DIR}/include")

# link our executable to the libraries that we need
target_link_libraries(Pong "${SFML_LIBS}")