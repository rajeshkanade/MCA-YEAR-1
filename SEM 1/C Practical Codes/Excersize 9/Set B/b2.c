//b2.c

// #include <stdio.h>
// #include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two characters
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the string based on the order (0 for ascending, 1 for descending)
void sortString(char *str, int order) {
    int n = strlen(str);

    // Bubble sort algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((order == 0 && str[j] > str[j + 1]) || (order == 1 && str[j] < str[j + 1])) {
                swap(&str[j], &str[j + 1]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are provided
    if (argc != 3) {
        printf("Usage: %s <string> <0/1>\n", argv[0]);
        return 1;
    }

    char *inputStr = argv[1];         // Input string
    int order = atoi(argv[2]);         // Convert string to integer using atoi

    // Validate the order argument
    if (order != 0 && order != 1) {
        printf("Error: The second argument must be 0 or 1.\n");
        return 1;
    }

    // Sort the string based on the order
    sortString(inputStr, order);

    // Print the sorted string
    printf("Sorted String: %s\n", inputStr);

    return 0;
}