/**
 * @brief Implementation of a singly linked list with various operations such as insertion, deletion, and traversal.
 *
 * This program provides a menu-driven interface to perform the following operations on a singly linked list:
 * 1. Create a single node.
 * 2. Create a linked list with multiple nodes.
 * 3. Insert a node at the beginning of the list.
 * 4. Insert a node at the end of the list.
 * 5. Insert a node at a specific position in the list.
 * 6. Delete a node from the beginning of the list.
 * 7. Delete a node from the end of the list.
 * 8. Delete a node from a specific position in the list.
 * 9. Display the linked list.
 * 0. Exit the program.
 */
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
    for (int i = 1; i <= n; i++)
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

Node *insertAtBegin(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        printf("List is Empty insert at the First >>>");
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}
Node *insertAtMiddle(Node *head, int data, int pos)
{
    if(pos <= 0){
        printf("Invalid Position >>>");
        return head;
    }
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        printf("List is Empty insert at the First >>>");
        head = newNode;
        return head;
    }
    Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
Node *insertAtEnd(struct Node *head, int data)
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

Node *deleteAtBegin(Node *head)
{
    if (head == NULL)
    {
        printf("Deletion is not possible ... List is Empty....");
        return head;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node *deleteAtEnd(Node *head)
{
    if (head == NULL)
    {
        printf("deletion is not possible ..... List is Empty");
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *p = temp->next;
    temp->next = NULL;
    free(p);
    return head;
}

Node *deleteAtMiddle(Node *head, int pos)
{
    if (head == NULL)
    {
        printf("Deletion is not possible ... List is EMpty ...");
        return head;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    Node *p = temp->next;
    temp->next = p->next;
    free(p);
    return head;
}

void displayNodes(Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty ...");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
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
    printf("\n9.print Linked List.");
}

int main()
{

    int data, n, pos, key;
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
            head = insertAtBegin(head, data);
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
            head = insertAtMiddle(head, data, pos);
            break;
        case 6:
            head = deleteAtBegin(head);
            printf("\n First node deleted successfully !");
            break;
        case 7:
            head = deleteAtEnd(head);
            printf("\n Last node deleted successfully !");
            break;
        case 8:
            printf("Enter the position of element what to delete : ");
            scanf("%d", &pos);
            head = deleteAtMiddle(head, pos);
            break;

        case 9:
            printf("\nLinked list is : ");
            displayNodes(head);
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