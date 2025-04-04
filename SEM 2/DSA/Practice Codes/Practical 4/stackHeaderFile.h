#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

#define NEWNODE (node*)malloc(sizeof(node))


int isEmpty(node* head)
{
    if(head==NULL)
        return 1;
    return 0;
}

node* push(node* head,int x)
{
    node* temp;

    temp = NEWNODE;
    temp->data = x;
    temp->next = NULL;

    if(head==NULL)
    {
        head = temp;
        printf("\nData is pushed succesfully!");
    }
    else
    {
        temp->next = head;
        head = temp;
        printf("\nData is pushed succesfully!");
    }
    
    return head;
}

node* pop(node* head)
{
    int x;
    node* q;

    if(!isEmpty(head))    
    {
        q = head;
        printf("\nPopped element is: %d",q->data);
        head = head->next;
        free(q);
    }
    else
        printf("\nStack is empty");

    return head;
}

int peek(node* head)
{
    int x = -1;

    if(!isEmpty(head))
    {
        x = head->data;
    }
    else
        printf("\nStack is empty");

    return x;
}

void display(node* head)
{
    node* p;
    if(!isEmpty(head))
    {
        printf("\n");
        p = head;
        while(p!=NULL)
        {
            printf("%d\n",p->data);
            p = p->next;
        }
    }
    else
        printf("\nStack is empty");
}