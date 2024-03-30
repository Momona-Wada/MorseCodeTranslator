//
// Created by Tatsunori Marumo on 3/23/2024.
//

#if defined(_WIN64)
#include <windows.h>
#define PLAY_SOUND(file) Beep(FREQUENCY, file == "sound/dot.mov" ? DOT_TIME : DASH_TIME)
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
#include <stdlib.h>
#define PLAY_SOUND(file) system("afplay " file)
#define SLEEP(ms) usleep((ms) * 500)
#endif

#define DOT_TIME 200 // ms
#define DASH_TIME 600 // ms
#define BLANK_BETWEEN_SYMBOL 200 // ms
#define BLANK_BETWEEN_CHARACTER 600 // ms
#define FREQUENCY 700

void dot() {
    PLAY_SOUND("sound/dot.m4a");
}

void dash() {
    PLAY_SOUND("sound/dash.m4a");
}

void outputBeep(const char text[]) {
//    char text[] = "101010001110001110111010111";
    int i = 0;

    while (text[i] != '\0') {
        if (text[i] == '1') {
            if (text[i+1] == '1') { // Check if the input is 111
                dash();
                i += 3; // move pointer by three
            } else {
                dot();
                i++;
            }
        } else if (text[i+1] == '0') { // check if the input is 000
            SLEEP(BLANK_BETWEEN_CHARACTER);
            i += 3; // move pointer by three
        } else {
            SLEEP(BLANK_BETWEEN_SYMBOL);
            i++;
        }
    }
}

//int main() {
//    outputBeep();
//    return 0;
//}
