//
// Created by Tatsunori Marumo on 3/23/2024.
//

#ifndef MORSECODETRANSLATOR_OUTPUTBEEP_H
#define MORSECODETRANSLATOR_OUTPUTBEEP_H

#if defined(_WIN64)
#include <windows.h>
#define PLAY_SOUND(file) Beep(FREQUENCY, file == "sound/dot.mov" ? DOT_TIME : DASH_TIME)
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
#define PLAY_SOUND(file) system("afplay " file)
#define SLEEP(ms) usleep((ms) * 1000)
#endif

#define DOT_TIME 200 // ms
#define DASH_TIME 600 // ms
#define BLANK_BETWEEN_SYMBOL 200 // ms
#define BLANK_BETWEEN_CHARACTER 600 // ms
#define FREQUENCY 700

void dot();
void dash();
void outputBeep(const char text[]);

#endif //MORSECODETRANSLATOR_OUTPUTBEEP_H
