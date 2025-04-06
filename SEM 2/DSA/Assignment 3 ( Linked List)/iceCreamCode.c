#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the linked list
typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

// Function to insert a student into the linked list
void insertStudent(Node** head, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = *head;
    *head = newNode;
}

// Function to display the students in a set
void displaySet(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

// Function to compute and display the union of both sets
void unionSets(Node* setA, Node* setB) {
    Node* result = NULL;
    Node* current = setA;

    // Add all students from set A
    while (current != NULL) {
        insertStudent(&result, current->name);
        current = current->next;
    }

    // Add students from set B if not already in result
    current = setB;
    while (current != NULL) {
        Node* temp = result;
        int found = 0;
        while (temp != NULL) {
            if (strcmp(temp->name, current->name) == 0) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            insertStudent(&result, current->name);
        }
        current = current->next;
    }

    if (result == NULL) {
        printf("No students found in the union of both sets.\n");
    } else {
        printf("Union of both sets:\n");
        displaySet(result);
    }
}

// Function to compute and display the intersection of both sets
void intersectionSets(Node* setA, Node* setB) {
    Node* result = NULL;
    Node* current = setA;

    while (current != NULL) {
        Node* temp = setB;
        while (temp != NULL) {
            if (strcmp(current->name, temp->name) == 0) {
                insertStudent(&result, current->name);
                break;
            }
            temp = temp->next;
        }
        current = current->next;
    }

    if (result == NULL) {
        printf("No students found in the intersection of both sets.\n");
    } else {
        printf("Intersection of both sets:\n");
        displaySet(result);
    }
}

// Function to compute and display students who like only vanilla
void differenceVanilla(Node* setA, Node* setB) {
    Node* result = NULL;
    Node* current = setA;

    while (current != NULL) {
        Node* temp = setB;
        int found = 0;
        while (temp != NULL) {
            if (strcmp(current->name, temp->name) == 0) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            insertStudent(&result, current->name);
        }
        current = current->next;
    }

    if (result == NULL) {
        printf("No students found who like only vanilla.\n");
    } else {
        printf("Students who like only vanilla:\n");
        displaySet(result);
    }
}

// Function to compute and display students who like only butterscotch
void differenceButterscotch(Node* setA, Node* setB) {
    Node* result = NULL;
    Node* current = setB;

    while (current != NULL) {
        Node* temp = setA;
        int found = 0;
        while (temp != NULL) {
            if (strcmp(current->name, temp->name) == 0) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            insertStudent(&result, current->name);
        }
        current = current->next;
    }

    if (result == NULL) {
        printf("No students found who like only butterscotch.\n");
    } else {
        printf("Students who like only butterscotch:\n");
        displaySet(result);
    }
}

// Function to display all students
void displayAllStudents(Node* vanillaSet, Node* butterscotchSet) {
    printf("Students who like vanilla:\n");
    displaySet(vanillaSet);
    printf("Students who like butterscotch:\n");
    displaySet(butterscotchSet);
}

// Function to add student data
void addStudent(Node** vanillaSet, Node** butterscotchSet) {
    char name[50];
    int choice;

    printf("Enter the name of the student: ");
    scanf("%s", name);
    printf("Select the flavor preference:\n1. Vanilla\n2. Butterscotch\n");
    scanf("%d", &choice);

    if (choice == 1) {
        insertStudent(vanillaSet, name);
    } else if (choice == 2) {
        insertStudent(butterscotchSet, name);
    } else {
        printf("Invalid choice!\n");
    }
}

int main() {
    Node* vanillaSet = NULL;
    Node* butterscotchSet = NULL;
    int option;

    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Display Union of Sets\n");
        printf("3. Display Intersection of Sets\n");
        printf("4. Display Students who like only Vanilla\n");
        printf("5. Display Students who like only Butterscotch\n");
        printf("6. Display All Students\n");
        printf("7. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addStudent(&vanillaSet, &butterscotchSet);
                break;
            case 2:
                unionSets(vanillaSet, butterscotchSet);
                break;
            case 3:
                intersectionSets(vanillaSet, butterscotchSet);
                break;
            case 4:
                differenceVanilla(vanillaSet, butterscotchSet);
                break;
            case 5:
                differenceButterscotch(vanillaSet, butterscotchSet);
                break;
            case 6:
                displayAllStudents(vanillaSet, butterscotchSet);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 6);

    return 0;
}
