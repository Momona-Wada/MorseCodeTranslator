/*
 * This program prompts the user to enter a message, and then converts the message to uppercase letters.
 *
 * Created by Momona Wada
 * Date: 2024-03-21
 */
#include <stdio.h>
#include <ctype.h>


char* getUserInput() {
    static char input[256];
    printf("Enter your message: ");
    fgets(input, sizeof(input), stdin);

    // convert all letters to uppercase
    for (int i = 0; input[i] != '\0'; i++) {
        input[i] = toupper(input[i]);
    }

    return input;
}
