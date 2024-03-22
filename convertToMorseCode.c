//
// This program converts given string into morse code.
// Created by Tatsuya Yoshida on 2024-03-21.
//

#include <stdio.h>
#include <string.h>

// table for morse code
const char* morse_table[36] = {
        "10111", "111010101", "11101011101", "1110101", "1", "101011101", "111011101",
        "1010101", "101", "1011101110111", "111010111", "101110101", "1110111", "11101",
        "11101110111", "10111011101", "1110111010111", "1011101", "10101", "111",
        "1010111", "101010111", "101110111", "11101010111", "1110101110111", "11101110101",
        "10111011101110111", "101011101110111", "1010101110111", "10101010111", "101010101",
        "11101010101", "1110111010101", "111011101110101", "11101110111011101", "1110111011101110111"
};

// get corresponding morse code based on character
const char* get_morse_code(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    }
    return ""; // return empty for characters not in the table
}

// convert given text into morse code
void print_morse(const char* text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (text[i] != ' ') {
            printf("%s000", get_morse_code(text[i]));
        } else {
            printf("0000000"); // between words
        }
    }
}

int main() {
    char text[] = "HELLO WORLD"; // text to convert
    printf("The given text is:\n%s\n\n", text);
    printf("The corresponding morse code is:\n");
    print_morse(text);
    printf("\n");
    return 0;
}
