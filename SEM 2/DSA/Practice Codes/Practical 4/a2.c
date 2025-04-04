#include<stdio.h>
#define MAX_SIZE 10
typedef struct Stack{
    int top;
    int arr[MAX_SIZE];
}Stack;

void initialize(Stack *s){
    s->top = -1;
}

int isEmpty(Stack *s){
    if(s->top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(Stack *s){
    if(s->top == MAX_SIZE - 1){
        return 1;
    }
    return 0;
}
int peek(Stack *s){
    return s->arr[s->top];
}
void push(Stack *s, int n){
    if(isFull(s)){
        printf("\n Cannot insert stack is Full ...");
        return ;
    }
    s->top ++;
    s->arr[s->top] = n;
}

void pop(Stack *s ){
    if(isEmpty(s)){
        printf("\n Cannot pop stack is empty ....");
        return;
    }
    s->top --;

}

void printStack(Stack *s){
    for(int i = s->arr[0] ; i <= s->arr[s->top] ; i++){
        printf("%d ", i);
    }
}
int main(){
    Stack s;
    initialize(&s);
    push(&s , 1);
    push(&s , 2);
    push(&s , 3);
    push(&s , 4);

    printf("%d",peek(&s));

    printf("\n");
    printStack(&s);

    return 0;
}