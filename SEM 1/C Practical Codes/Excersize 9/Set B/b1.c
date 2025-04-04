#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the union of two strings
void findUnion(char *str1, char *str2) {
    int hash[256] = {0};  // To track the presence of characters (ASCII range)

    printf("Union: ");
    for (int i = 0; str1[i] != '\0'; i++) {
        if (hash[(int)str1[i]] == 0) {
            printf("%c", str1[i]);
            hash[(int)str1[i]] = 1;
        }
    }

    for (int i = 0; str2[i] != '\0'; i++) {
        if (hash[(int)str2[i]] == 0) {
            printf("%c", str2[i]);
            hash[(int)str2[i]] = 1;
        }
    }
    printf("\n");
}

// Function to find the intersection of two strings
void findIntersection(char *str1, char *str2) {
    int hash[256] = {0};  // To track the presence of characters in str1

    // Mark characters present in str1
    for (int i = 0; str1[i] != '\0'; i++) {
        hash[(int)str1[i]] = 1;
    }

    printf("Intersection: ");
    for (int i = 0; str2[i] != '\0'; i++) {
        if (hash[(int)str2[i]] == 1) {
            printf("%c", str2[i]);
            hash[(int)str2[i]] = 0;  // Avoid duplicate prints
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Check if exactly two arguments are provided
    if (argc != 3) {
        printf("Invalid number of arguments. Please provide exactly two strings.\n");
        return 1;
    }

    // Find and display the union and intersection of the two strings
    findUnion(argv[1], argv[2]);
    findIntersection(argv[1], argv[2]);

    return 0;
}
