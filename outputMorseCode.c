
#include <stdio.h>
#include <string.h>

void playMorseSound(const char* morseString) {
    for (int i = 0; i < strlen(morseString); i++) {
        if (i == 0 && morseString[i] == '1' && morseString[i+1] == '0') {
            printf("%s\n", "dot was beeped");
        }
        else if ((morseString[i] == '1' && morseString[i+1] == '\0') ||
            (morseString[i] == '1' && morseString[i+1] == '0' && morseString[i-1] == '0')) {
            printf("%s\n", "dot was beeped");
        } else if (morseString[i] == '1' && morseString[i+1] == '1' && morseString[i+2] == '1') {
            printf("%s\n", "dash was beeped");
        } else if (morseString[i] == '1') {
            continue;
        }
        else if (morseString[i] == '0' && morseString[i+1] == '0' && morseString[i+2] == '0') {
            printf("%s\n", "This is long break");
        } else if ((morseString[i] == '0' && morseString[i-1] == '0' && morseString[i+1] == '0') ||
                   (morseString[i] == '0' && morseString[i-1] == '0' && morseString[i-2] == '0')) {
            continue;
        } else if (morseString[i] == '0') {
            printf("%s\n", "This is short break");
        }
    }
}

int main() {
    const char* morseString = "10001010111000";
    playMorseSound(morseString);
    return 0;
}
