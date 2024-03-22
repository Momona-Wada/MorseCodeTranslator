cmake_minimum_required(VERSION 3.27)
project(MorseCodeTranslator C)

set(CMAKE_C_STANDARD 11)

add_executable(getUserInput getUserInput.c)
add_executable(translateUserInputToMorseCode translateUserInputToMorseCode.c)
add_executable(outputMorseCode outputMorseCode.c)