//
// Created by Tatsunori Marumo on 3/23/2024.
//

#if defined(_WIN64) // For Windows
#include <windows.h>
#define PLAY_SOUND(file) Beep(FREQUENCY, file == "sound/dot.mov" ? DOT_TIME : DASH_TIME)
#define SLEEP(ms) Sleep(ms) // Use sleep function for delay
#else // For non-Windows OS
#include <unistd.h>
#include <stdlib.h>
#define PLAY_SOUND(file) system("afplay " file) // Use afplay command for sound on Unix-based OS
#define SLEEP(ms) usleep((ms) * 1000) // Use usleep for delay, converting microseconds to miliseconds
#endif

#define DOT_TIME 100 // ms
#define DASH_TIME 300 // ms
#define BLANK_BETWEEN_SYMBOL 100 // ms
#define BLANK_BETWEEN_CHARACTER 300 // ms
#define FREQUENCY 750

void dot() {
    PLAY_SOUND("sound/dot.m4a");
}

void dash() {
    PLAY_SOUND("sound/dash.m4a");
}

void outputBeep(const char text[]) {
    int i = 0;

    while (text[i] != '\0') {
        if (text[i] == '1') {
            if (text[i+1] == '1') { // Check if the input is 111 (dash)
                dash();
                i += 3; // move pointer by three
            } else {
                dot();
                i++;
            }
        } else if (text[i+1] == '0') { // check if the input is 000 (blank between character)
            SLEEP(BLANK_BETWEEN_CHARACTER);
            i += 3; // move pointer by three (blank between symbol)
        } else {
            SLEEP(BLANK_BETWEEN_SYMBOL);
            i++;
        }
    }
}
