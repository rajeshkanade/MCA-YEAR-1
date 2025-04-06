/*
Question:
Write a C program to implement a doubly circular linked list with the following functionalities:
1. Insert a node at the beginning of the list.
2. Insert a node at the end of the list.
3. Insert a node at a specific position in the list.
4. Delete a node by its value.
5. Traverse and print the list in forward direction.
6. Traverse and print the list in backward direction.
7. Search for a node by its value.
8. Exit the program.

The program should provide a menu-driven interface for the user to perform these operations.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = newNode;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* tail = (*head)->prev;
    newNode->next = *head;
    newNode->prev = tail;
    tail->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* tail = (*head)->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = *head;
    (*head)->prev = newNode;
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        struct Node* tail = temp->prev;
        tail->next = temp->next;
        temp->next->prev = tail;
        free(temp);
        *head = tail->next;
    }
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) return;
    struct Node* tail = (*head)->prev;
    if (tail == *head) {
        free(tail);
        *head = NULL;
    } else {
        tail->prev->next = *head;
        (*head)->prev = tail->prev;
        free(tail);
    }
}

void deleteNodeAtMiddle(struct Node** head, int key) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    do {
        if (temp->data == key) {
            if (temp->next == temp) {
                *head = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (*head == temp) *head = temp->next;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    } while (temp != *head);
}

void traverseForward(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void traverseBackward(struct Node* head) {
    if (head == NULL) return;
    struct Node* tail = head->prev;
    struct Node* temp = tail;
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("\n");
}

struct Node* search(struct Node* head, int key) {
    if (head == NULL) return NULL;
    struct Node* temp = head;
    do {
        if (temp->data == key) return temp;
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Node by Value\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Position\n");
        printf("8. Traverse Forward\n");
        printf("9. Traverse Backward\n");
        printf("10. Search\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data and position to insert: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                printf("Enter data to delete by value: ");
                scanf("%d", &data);
                deleteNodeAtMiddle(&head, data);
                break;
            case 5:
                printf("Deleting node at the beginning.\n");
                deleteAtBeginning(&head);
                break;
            case 6:
                printf("Deleting node at the end.\n");
                deleteAtEnd(&head);
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                if (position == 0) {
                    deleteAtBeginning(&head);
                } else {
                    struct Node* temp = head;
                    for (int i = 0; i < position && temp->next != head; i++) {
                        temp = temp->next;
                    }
                    if (temp == head) {
                        printf("Invalid position.\n");
                    } else {
                        deleteNodeAtMiddle(&head, temp->data);
                    }
                }
                break;
            case 8:
                printf("Forward Traversal: ");
                traverseForward(head);
                break;
            case 9:
                printf("Backward Traversal: ");
                traverseBackward(head);
                break;
            case 10:
                printf("Enter data to search: ");
                scanf("%d", &data);
                struct Node* foundNode = search(head, data);
                if (foundNode) {
                    printf("Found: %d\n", foundNode->data);
                } else {
                    printf("Not Found\n");
                }
                break;
            case 11:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}