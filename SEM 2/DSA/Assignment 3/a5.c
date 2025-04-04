#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *createLinkedList(Node *head, int n)
{
    int data;
    printf("\nEnter %d data values : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        Node *newNode = createNode(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}

void displayNodes(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

Node *copyLinkedList(Node *head, Node *copy)
{
    Node *temp = head;

    while (temp != NULL)
    {
        Node *newNode = createNode(temp->data);
        if (copy == NULL)
        {
            copy = newNode;
        }
        else
        {
            Node *newTemp = copy;
            while (newTemp->next != NULL)
            {
                newTemp = newTemp->next;
            }
            newTemp->next = newNode;
        }
        temp = temp->next;
    }
    return copy;
}

Node* postiveLinkedList(Node* head, Node* p){

    Node* temp = head;
    
    while(temp != NULL){
        if(temp->data > 0){
                Node* newNode = createNode(temp->data);
            if(p == NULL){
                p = newNode;
            }else{
                Node* newTemp = p;
                while(newTemp -> next != NULL){
                    newTemp = newTemp -> next;
                }
                newTemp->next = newNode;
            }
        }
        temp = temp->next;
    }
    return p;
}
Node* negativeLinkedList(Node* head, Node* p){

    Node* temp = head;
    
    while(temp != NULL){
        if(temp->data < 0){
                Node* newNode = createNode(temp->data);
            if(p == NULL){
                p = newNode;
            }else{
                Node* newTemp = p;
                while(newTemp -> next != NULL){
                    newTemp = newTemp -> next;
                }
                newTemp->next = newNode;
            }
        }
        temp = temp->next;
    }
    return p;
}
int main()
{
    int n;
    Node *head = NULL;
    Node *copy = NULL;
    Node *p = NULL;
    Node *q = NULL;
    printf("\nEnter the value of n : ");
    scanf("%d", &n);
    printf("\n\n");

    head = createLinkedList(head, n);
    printf("\nDisplaing the linked list : ");
    displayNodes(head);
    copy = copyLinkedList(head, copy);
    printf("\nCopied Linked list : ");
    displayNodes(copy);
    printf("\nPositive Linked list is : ");
    p = postiveLinkedList( head ,p);
    displayNodes(p);
    printf("\nNegative Linked list is : ");
    q = negativeLinkedList( head ,q);
    displayNodes(q);
    printf("\n\n");
    return 0;
}