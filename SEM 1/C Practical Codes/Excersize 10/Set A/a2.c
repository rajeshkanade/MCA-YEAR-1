//a2.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file in read mode
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int lines = 0, words = 0, characters = 0;
    char ch;
    int inWord = 0;

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        characters++; // Increment character count

        if (ch == '\n') {
            lines++; // Increment line count
        }

        // Check if the character is part of a word
        if (isspace(ch)) {
            inWord = 0; // End of a word
        } else if (!inWord) {
            inWord = 1; // Start of a new word
            words++;    // Increment word count
        }
    }

    // Close the file
    fclose(file);

    // Print the results
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);

    return 0;
}