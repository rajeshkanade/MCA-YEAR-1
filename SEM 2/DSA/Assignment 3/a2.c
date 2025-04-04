#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

struct Node *createLinkedList(struct Node *head, int n)
{
    int data;
    for (int i = 1; i <= n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        struct Node *newNode = createNode(data);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    return head;
}

struct Node *insertNodeAtBegin(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
    return head;
}

struct Node *insertNodeAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    return head;
}

struct Node *insertNodeAtMiddle(struct Node *head, int data, int loc)
{
    if (loc <= 0)
    {
        printf("Invalid location\n");
        return head;
    }
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        printf("List is empty, cannot insert at Middle!\n");
        return head;
    }
    struct Node *temp = head;
    for (int i = 1; i < loc - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }
    if (temp->next == head)
    {
        printf("Invalid location\n");
        printf("Inserting at last position...\n");
        return insertNodeAtEnd(head, data);
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void printNode(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is Empty...\n");
        return;
    }
    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void displayMenu()
{
    printf("Menu:\n");
    printf("1. Create Linked List\n");
    printf("2. Insert Node At Begin\n");
    printf("3. Insert Node At End\n");
    printf("4. Insert Node At Middle\n");
    printf("5. Delete Node At Begin\n");
    printf("6. Delete Node At End\n");
    printf("7. Delete Node At Middle\n");
    printf("8. Print List\n");
    printf("9. Exit\n");
}

struct Node *deleteNodeAtBegin(struct Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    free(head);
    return temp->next;
}

struct Node *deleteNodeAtEnd(struct Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    struct Node *secondLast = head;
    while (secondLast->next->next != head)
    {
        secondLast = secondLast->next;
    }
    free(secondLast->next);
    secondLast->next = head;
    return head;
}

struct Node *deleteNodeAtMiddle(struct Node *head, int pos)
{
    if (pos <= 0 || head == NULL)
    {
        return head;
    }
    if (pos == 1)
    {
        return deleteNodeAtBegin(head);
    }
    struct Node *temp = head;
    for (int i = 1; temp->next != head && i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp->next == head)
    {
        printf("Position does not exist.\n");
        return head;
    }
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}

int main()
{
    struct Node *head = NULL;
    int choice, data, pos;

    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number of nodes to create: ");
            int n;
            scanf("%d", &n);
            head = createLinkedList(head, n);
            break;
        case 2:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            head = insertNodeAtBegin(head, data);
            break;
        case 3:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            head = insertNodeAtEnd(head, data);
            break;
        case 4:
            printf("Enter data to insert at middle: ");
            scanf("%d", &data);
            printf("Enter the position to insert at: ");
            scanf("%d", &pos);
            head = insertNodeAtMiddle(head, data, pos);
            break;
        case 5:
            head = deleteNodeAtBegin(head);
            break;
        case 6:
            head = deleteNodeAtEnd(head);
            break;
        case 7:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            head = deleteNodeAtMiddle(head, pos);
            break;
        case 8:
            printNode(head);
            break;
        case 9:
            printf("Exiting...\n"); // This line is redundant and can be removed
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);
}