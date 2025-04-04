#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* initialize()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
}

struct Node *createNode(int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node *insertNodeAtMiddle(struct Node *head, int data, int pos)
{
    struct Node *newNode = createNode(data);
    struct Node *p;
    p = head;
    int i = 1;
    if(pos == 1){
        head = insertAtBeginning(head,data);
        return head;
    }
    while (i < pos - 1 && p != NULL)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
    {
        printf("\nPosition is not found ! Linked list has %d Nodes", i);
        return head;
    }

    newNode->next = p->next;
    p->next = newNode;
    return head;
}

struct Node *createLinkedList(struct Node *head, int n)
{
    struct Node *temp, *newNode;
    int data;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &data);

        if (head == NULL)
        {
            head = createNode(data);
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newNode = createNode(data);
            temp->next = newNode;
        }
    }
    return head;
}

struct Node *deleteNodeAtBeginning(struct Node *head)
{
    if (head == NULL)
    {
        printf("\nList is Empty ! Deletion is not possible !!!");
        return NULL;
    }
    struct Node *q = head;
    head = head->next;
    free(q);

    return head;
}

struct Node *deleteNodeAtEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("\nList is Empty ! Deletion not possible !!!");
        return NULL;
    }
    struct Node *p, *q;
    p = head;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    q = p->next;
    p->next = NULL;
    free(q);

    return head;
}

struct Node *deleteNodeAtMiddle(struct Node *head, int pos)
{
    if (head == NULL)
    {
        printf("\n List is Empty ! Deletion not possible !!!");
        return NULL;
    }
    struct Node *p, *q;
    p = head;
    int i = 1;
    while (i < (pos - 1) && p != NULL)
    {
        p = p->next;
        i++;
    }

    if (p == NULL)
    {
        printf("\nPosition is not found ! Linked list has %d Nodes", i);
        return head;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    printf("\n Middle node deleted successfully !");
    return head;
}

void searchNode(struct Node* head , int key){
    struct Node *p;
    p = head;
    while(p!= NULL){
        if(p->data == key){
            printf("\n Node is found !!!!");
            return;
        }
        p = p->next;
    }
    if(p == NULL){
        printf("\n Node is not found");
        return;
    }
}

struct Node *printNode(struct Node *head)
{
    struct Node *q = head;
    while (q != NULL)
    {
        printf("%d->", q->data);
        q = q->next;
    }
    printf("NULL\n");
}

void menu()
{
    printf("\n0.Exit.");
    printf("\n1.Create Node.");
    printf("\n2.Create Linked list using multiple nodes.");
    printf("\n3.Insert at Beginning");
    printf("\n4.Insert at End.");
    printf("\n5.Insert at Middle.");
    printf("\n6.Delete at Beginning.");
    printf("\n7.Delete at End.");
    printf("\n8.Delete at Middle.");
    printf("\n9.Search for Node.");
    printf("\n10.print Linked List.");
}

int main()
{
    int data, n, pos , key;
    struct Node *head;

    int ch;
    while (1)
    {
        menu();
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data to insert in node : ");
            scanf("%d", &data);
            head = createNode(data);
            break;
        case 2:
            printf("How many data you want to insert : ");
            scanf("%d", &n);
            head = createLinkedList(head, n);
            break;
        case 3:
            printf("enter the data to insert at begining : ");
            scanf("%d", &data);
            head = insertAtBeginning(head, data);
            break;
        case 4:
            printf("enter the data to insert at end : ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            break;
        case 5:
            printf("enter position to insert node  : ");
            scanf("%d", &pos);
            printf("\nEnter data to insert : ");
            scanf("%d", &data);
            head = insertNodeAtMiddle(head, data, pos);
            break;
        case 6:
            head = deleteNodeAtBeginning(head);
            printf("\n First node deleted successfully !");
            break;
        case 7:
            head = deleteNodeAtEnd(head);
            printf("\n Last node deleted successfully !");
            break;
        case 8:
            printf("Enter the position of element what to delete : ");
            scanf("%d", &pos);
            head = deleteNodeAtMiddle(head, pos);

            break;
        case 9 : 
            printf("Enter the element what to search : ");
            scanf("%d",&key);
            searchNode(head,key);
            break;
        case 10:
            printf("\nLinked list is : ");
            printNode(head);
            break;
        case 0:
            return 0;
        default:
            printf("Enter the valid choice !!!!!!! ");
            break;
        }
    }

    return 0;
}