#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node*));
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
}

int main(){


    return 0;
}