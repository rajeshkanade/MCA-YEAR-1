//a2.c

#include <stdio.h>
#include <string.h>

// Function to replace occurrences of 'oldChar' with 'newChar'
void replaceChar(char *str, char old, char new) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == old) {
            str[i] = new;
        }
    }
}

int main(int argc, char *argv[]) {
    
    if (argc != 4) {
        printf("Usage: %s <string> <char1> <char2>\n", argv[0]);
        return 1;
    }

    char *input = argv[1]; 
    char old = argv[2][0]; 
    char new = argv[3][0]; 

    replaceChar(input, old, new);

    printf("Modified String: %s\n", input);

    return 0;
}