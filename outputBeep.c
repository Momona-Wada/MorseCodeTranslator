//
// Created by tmaru on 3/23/2024.
//

#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN64)
#include <windows.h>
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
#define SLEEP(ms) usleep((ms) * 1000)
#endif

#define DOT_TIME 200 // ms
#define DASH_TIME 600 // ms
#define BLANK_TIME 200 // ms
#define FREQUENCY 700

void dot() {
#if defined(_WIN64)
    Beep(FREQUENCY, DOT_TIME);
#else
    system("printf '\\a'");
#endif
}

void dash() {
#if defined(_WIN64)
    Beep(FREQUENCY, DASH_TIME);
#else
    system("printf '\\a'");
#endif
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
        } else {
            SLEEP(BLANK_TIME);
            i++;
        }
    }
    return 0;
}
