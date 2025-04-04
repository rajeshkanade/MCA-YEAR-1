//b3.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// Function to display the entire file
void displayFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("\nContents of '%s':\n", filename);
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        printf("%s", line);
    }

    fclose(file);
}

// Function to display the nth line
void displayNthLine(const char *filename, int n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 1;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (lineNumber == n) {
            printf("Line %d: %s", n, line);
            fclose(file);
            return;
        }
        lineNumber++;
    }

    printf("Line %d not found!\n", n);
    fclose(file);
}

// Function to modify the nth line
void modifyNthLine(const char *filename, int n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 1;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (lineNumber == n) {
            printf("Enter new content for line %d: ", n);
            getchar();  // Clear the newline character from buffer
            fgets(line, MAX_LINE_LENGTH, stdin);
        }
        fputs(line, temp);
        lineNumber++;
    }

    fclose(file);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);

    printf("Line %d modified successfully!\n", n);
}

// Function to add n lines to the file
void addLines(const char *filename, int n) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Enter %d new lines:\n", n);
    getchar();  // Clear the newline character from buffer

    for (int i = 1; i <= n; i++) {
        printf("Line %d: ", i);
        fgets(line, MAX_LINE_LENGTH, stdin);
        fputs(line, file);
    }

    fclose(file);
    printf("%d lines added successfully!\n", n);
}

int main() {
    char filename[100];
    int choice, n;

    printf("Enter the filename: ");
    scanf("%s", filename);

    while (1) {
        printf("\n--- Simple Text Editor ---\n");
        printf("1. Display the file\n");
        printf("2. Display nth line\n");
        printf("3. Modify nth line\n");
        printf("4. Add n lines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFile(filename);
                break;
            case 2:
                printf("Enter the line number to display: ");
                scanf("%d", &n);
                displayNthLine(filename, n);
                break;
            case 3:
                printf("Enter the line number to modify: ");
                scanf("%d", &n);
                modifyNthLine(filename, n);
                break;
            case 4:
                printf("Enter the number of lines to add: ");
                scanf("%d", &n);
                addLines(filename, n);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}