#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6
struct Stack
{
    int arr[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack)
{
    stack->top = -1;
}

int isEmpty(struct Stack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *stack)
{
    if (stack->top == MAX_SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// function to check the top value;
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty !!!");
        return -1;
    }
    return stack->arr[stack->top];
}

void push(struct Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack is full !!!");
        return;
    }
    else
    {
        stack->top++;
        stack->arr[stack->top] = data;
    }
}

//  fucnction to pop the stadk value and return the top of the stack;

// void pop(struct Stack* stack){
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty/Underflow Cannot Pop Element !!!!");
        return -1;
    }
    else
    {
        return stack->arr[stack->top--];
        // stack->top--;
        // stack->arr[stack->top];
    }
}

void printStack(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Is Empty ...!");
        return;
    }
    printf("Stack Elements are : ");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Stack stack;
    initialize(&stack);

    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 100);
    push(&stack, 200);
    push(&stack, 100);
    push(&stack, 100);
    push(&stack, 100);
    push(&stack, 100);
    push(&stack, 100);

    int res = peek(&stack);
    printf("Top is : %d\n", res);

    printStack(&stack);
    return 0;
}