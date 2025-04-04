//a1.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to reverse the case of a character
char reverseCase(char ch) {
    if (isupper(ch))
        return tolower(ch);
    else if (islower(ch))
        return toupper(ch);
    else
        return ch;
}

int main(int argc, char *argv[]) {
    // Check if exactly two filenames are provided
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    // Open the source file in read mode
    FILE *srcFile = fopen(argv[1], "r");
    if (srcFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    // Open the destination file in write mode
    FILE *destFile = fopen(argv[2], "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(srcFile); // Close the source file before exiting
        return 1;
    }

    char ch;
    // Read each character from the source file and write the reversed case to the destination file
    while ((ch = fgetc(srcFile)) != EOF) {
        fputc(reverseCase(ch), destFile);
    }

    // Close both files
    fclose(srcFile);
    fclose(destFile);

    printf("File copied with reversed case successfully.\n");
    return 0;
}