#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void copy_string(char *str1, char *str2) {
    strcpy(str2, str1);
}

void concatenate_strings(char *str1, char *str2, char *result) {
    strcpy(result, str1);
    strcat(result, str2);
}

int count_occurrences(char *str, char letter) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == letter) {
            count++;
        }
    }
    return count;
}

void replace_occurrences(char *str, char old_letter, char new_letter) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == old_letter) {
            str[i] = new_letter;
        }
    }
}

int main() {
    char str1[100], str2[100], result[200];
    char letter, new_letter;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Copy one string to another\n");
        printf("2. Concatenate two strings\n");
        printf("3. Count the number of occurrences of a letter in a string\n");
        printf("4. Replace occurrences of a letter with another letter\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the str1 string: ");
                gets(str1);
               // printf("Enter the str2 string: ");
               // gets(str2);
                copy_string(str1, str2);
                printf("After copying, str2 string is: %s\n", str2);
                break;

            case 2:
                printf("Enter the first string: ");
                gets(str1);
                printf("Enter the second string: ");
                gets(str2);
                concatenate_strings(str1, str2, result);
                printf("After concatenation, the result is: %s\n", result);
                break;

            case 3:
                printf("Enter the string: ");
                gets(str1);
                printf("Enter the letter to count: ");
                scanf("%c", &letter);
                getchar();  // to consume the newline character left by scanf
                printf("The letter '%c' occurs %d times in the string.\n", letter, count_occurrences(str1, letter));
                break;

            case 4:
                printf("Enter the string: ");
                gets(str1);
                printf("Enter the letter to replace: ");
                scanf("%c", &letter);
                getchar();
                printf("Enter the new letter: ");
                scanf("%c", &new_letter);
                getchar();
                replace_occurrences(str1, letter, new_letter);
                printf("After replacing, the string is: %s\n", str1);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
