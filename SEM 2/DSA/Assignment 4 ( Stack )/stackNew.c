#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
}Stack;


Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void isEmpty(Stack* stack){
    if(stack->top == NULL){
        printf("Stack is empty\n");
    }else{
        printf("Stack is not empty\n");
    }
}

void push(Stack* stack , int data){
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack){
    if(stack->top == NULL){
        printf("Stack is empty\n");
        return;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    printf("Popped element is: %d\n", temp->data);
    free(temp);
}
    void display(Stack* stack){
    Node* temp = stack->top;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void main(){

    Stack stack;
    stack.top = NULL;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);
    pop(&stack);
    display(&stack);


}