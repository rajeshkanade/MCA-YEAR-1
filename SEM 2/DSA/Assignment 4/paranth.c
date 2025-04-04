#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

StackNode* createStackNode(char data) {
    StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack* createStack() {
    Stack* newStack = (Stack*) malloc(sizeof(Stack));
    if (!newStack) {
        printf("Memory error\n");
        return NULL;
    }
    newStack->top = NULL;
    return newStack;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, char data) {
    StackNode* newNode = createStackNode(data);
    if (stack->top) {
        newNode->next = stack->top;
    }
    stack->top = newNode;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return '\0';
    }
    char data = stack->top->data;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int isWellParenthesized(char* expression) {
    Stack* stack = createStack();
    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            push(stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (isEmpty(stack)) {
                return 0;
            }
            char top = pop(stack);
            if ((expression[i] == ')' && top != '(') ||
                (expression[i] == '}' && top != '{') ||
                (expression[i] == ']' && top != '[')) {
                return 0;
            }
        }
    }
    if (isEmpty(stack)) {
        return 1;
    }
    return 0;
}

int main() {
    char expression[100];

    int choice;
    do {
        printf("Enter an expression: ");
        fgets(expression, sizeof(expression), stdin);
        expression[strcspn(expression, "\n")] = 0;
        if (isWellParenthesized(expression)) {
            printf("\n The expression is well parenthesized.\n");
        } else {
            printf("\n The expression is not well parenthesized.\n");
        }
        printf("\n Do you want to continue? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
        getchar();
    } while (choice == 1);
    return 0;
}