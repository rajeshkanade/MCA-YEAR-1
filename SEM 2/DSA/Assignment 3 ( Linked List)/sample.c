#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct Node{
    char name[20];
    struct Node* next;
};

struct Node* createNode(char name){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name , name);
    newNode->next = NULL;
}