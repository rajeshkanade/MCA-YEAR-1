#include<stdio.h>
#define MAX 10
typedef struct Queue{
    int rear ;
    int front;
    int arr[MAX];
}Queue;
void initialize(Queue *queue){
    queue->rear = queue->front = -1;
}

int isFull(Queue *queue){
    if(queue->rear == MAX-1){
     return 1;
    }
    return 0;
}

int isEmpty(Queue *queue){
    if(queue->rear = -1){
        return 1;
    }
    return 0;
}

void enque(Queue *queue , int data){
    if(isFull(queue)){
        printf("Queue is Full !! Cannot Insert");
        return ;
    }
    queue->rear = queue->rear + 1;
    queue->arr[queue->rear] = data;
}
int main(){
    
    Queue queue ;
    initialize(&queue);
    return 0;
}