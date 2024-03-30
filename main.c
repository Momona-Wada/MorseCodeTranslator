//
// Created by Atsuko Uemura on 2024/03/30.
//

#include <stdio.h>
#include <string.h>
#include "getUserInput.h"
#include "convertToMorseCode.h"
#include "outputBeep.h"

int main() {
    char *text = getUserInput();
    char morseResult[MAX_MORSE_LENGTH]; // pointer to store converted result
    printf("The given text is:\n%s\n\n", text);

    storeMorseCode(text, morseResult);
    printf("The corresponding morse code is:\n%s", morseResult);
    printf("\n");

    outputBeep(morseResult);
    return 0;
}