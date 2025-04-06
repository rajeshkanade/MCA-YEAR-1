/*
implement a queue of integers usin a circular queue implementation and implement the following opeations.
a. add element
b. remove element
c. check isEmpty.
d. isFull
e. display
f. exit
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % SIZE == front;
}

// Function to add an element to the queue
void addElement(int element) {
    if (isFull()) {
        printf("Queue is full. Cannot add element.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = element;
    printf("Added %d to the queue.\n", element);
}

// Function to remove an element from the queue
void removeElement() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot remove element.\n");
        return;
    }
    printf("Removed %d from the queue.\n", queue[front]);
    if (front == rear) {
        front = rear = -1; // Queue becomes empty
    } else {
        front = (front + 1) % SIZE;
    }
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add element\n");
        printf("2. Remove element\n");
        printf("3. Check if queue is empty\n");
        printf("4. Check if queue is full\n");
        printf("5. Display queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add: ");
                scanf("%d", &element);
                addElement(element);
                break;
            case 2:
                removeElement();
                break;
            case 3:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
