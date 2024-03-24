//
// Created by tmaru on 3/23/2024.
//

#include <stdio.h>
#include <stdlib.h>

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

void dot() {
    PLAY_SOUND("sound/dot.mov");
}

void dash() {
    PLAY_SOUND("sound/dash.mov");
}

int main() {
    char text[] = "101010001110001110111010111";
    int i = 0;

    while (text[i] != '\0') {
        if (text[i] == '1') {
            if (text[i+1] == '1') {
                dash();
                i += 3;
            } else {
                dot();
                i++;
            }
        } else if (text[i+1] == '0') {
            SLEEP(BLANK_BETWEEN_CHARACTER);
            i += 3;
        } else {
            SLEEP(BLANK_BETWEEN_SYMBOL);
            i++;
        }
    }
    return 0;
}
