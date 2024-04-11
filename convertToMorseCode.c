//
// This program converts given string into morse code.
// Created by Tatsuya Yoshida on 2024-03-21.
//

//#include <emscripten.h> // used for compilation to convertToMorseCode.js
#include <stdio.h>
#include <string.h>

#define MAX_MORSE_LENGTH 1024

// table for morse code
const char* morseTable[36] = {
        // index 0 - 25 are for alphabetical character
        "10111", "111010101", "11101011101", "1110101", "1", "101011101", "111011101",
        "1010101", "101", "1011101110111", "111010111", "101110101", "1110111", "11101",
        "11101110111", "10111011101", "1110111010111", "1011101", "10101", "111",
        "1010111", "101010111", "101110111", "11101010111", "1110101110111", "11101110101",
        "10111011101110111", "101011101110111", "1010101110111", "10101010111", "101010101",
        "11101010101", "1110111010101", "111011101110101", "11101110111011101", "1110111011101110111"
};

// get corresponding morse code based on character
const char* getMorseCode(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morseTable[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morseTable[c - '0' + 26];
    }
    return ""; // return empty for characters not in the table
}

// convert given text into morse code and store it in a pointer of char
void storeMorseCode(const char* text, char* morseResult) {
    int index = 0;  // return
    int len = strlen(text);

    for (int i = 0; i < len; i++) {
        const char* morseChar;

        // retrieve next morse character
        if (text[i] != ' ') {
            morseChar = getMorseCode(text[i]);
        } else {
            morseChar = "0000000"; // add seven between
        }

        // add morseChar
        while (*morseChar && index < MAX_MORSE_LENGTH - 1) {
            morseResult[index++] = *morseChar++;
        }

        // add space between character
        if (text[i] != ' ' && index < MAX_MORSE_LENGTH - 4) {
            strcpy(&morseResult[index], "000");
            index += 3;
        }
    }
    // add '\0'
    morseResult[index] = '\0';
}

/**
 * different version of conversion used for compilation to convertToMorseCode.js
 */
//EMSCRIPTEN_KEEPALIVE
//char* convertToMorseCode(const char* text) {
//    int index = 0;  // return
//    int len = strlen(text);
//    static char morseResult[MAX_MORSE_LENGTH];
//
//    for (int i = 0; i < len; i++) {
//        const char* morseChar;
//
//        // retrieve next morse character
//        if (text[i] != ' ') {
//            morseChar = getMorseCode(text[i]);
//        } else {
//            morseChar = "0000000"; // add seven between
//        }
//
//        // add morseChar
//        while (*morseChar && index < MAX_MORSE_LENGTH - 1) {
//            morseResult[index++] = *morseChar++;
//        }
//
//        // add space between character
//        if (text[i] != ' ' && index < MAX_MORSE_LENGTH - 4) {
//            strcpy(&morseResult[index], "000");
//            index += 3;
//        }
//    }
//    // add '\0'
//    morseResult[index] = '\0';
//
//    return morseResult;
//}

//int main() {
//    char text[] = "HELLO WORLD"; // text to convert
//    char morseResult[MAX_MORSE_LENGTH]; // pointer to store converted result
//
//    printf("The given text is:\n%s\n\n", text);
//
//    storeMorseCode(text, morseResult);
//    printf("The corresponding morse code is:\n%s", morseResult);
//    printf("\n");
//    return 0;
//}
