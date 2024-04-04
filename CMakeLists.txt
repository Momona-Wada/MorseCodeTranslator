cmake_minimum_required(VERSION 3.27)
project(MorseCodeTranslator C)

set(CMAKE_C_STANDARD 11)

#add_executable(getUserInput getUserInput.c)
#add_executable(convertToMorseCode convertToMorseCode.c getUserInput.h getUserInput.c
#        main.c
#        convertToMorseCode.h
#)
#add_executable(outputMorseCode outputMorseCode.c)
#add_executable(outputBeep outputBeep.c)
add_executable(main getUserInput.h getUserInput.c convertToMorseCode.h convertToMorseCode.c outputBeep.h outputBeep.c main.c
)