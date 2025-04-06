/*
Menu-driven program to implement queue (using array) operations:
a. Add element
b. Remove element
c. Check if queue is empty
d. Check if queue is full
e. Display queue
f. Exit
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to add an element to the queue
void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full. Cannot add element.\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    queue[++rear] = element;
    printf("Element %d added to the queue.\n", element);
}

// Function to remove an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot remove element.\n");
        return;
    }
    printf("Element %d removed from the queue.\n", queue[front]);
    if (front == rear) {
        front = rear = -1; // Reset queue when it becomes empty
    } else {
        front++;
    }
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("a. Add element\n");
        printf("b. Remove element\n");
        printf("c. Check if queue is empty\n");
        printf("d. Check if queue is full\n");
        printf("e. Display queue\n");
        printf("f. Exit\n");
        printf("Enter your choice: ");
        char ch;
        scanf(" %c", &ch);

        switch (ch) {
            case 'a':
                printf("Enter the element to add: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 'b':
                dequeue();
                break;
            case 'c':
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 'd':
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 'e':
                display();
                break;
            case 'f':
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}