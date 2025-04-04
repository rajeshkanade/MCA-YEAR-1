#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node *createLinkedList(struct Node *head, int n)
{
    int data;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        if (head == NULL)
        {
            head = newNode;
        }else{

        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        }
    }
    return head;
}

struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node *insertAtMiddle(struct Node *head, int data, int pos)
{
    if (pos == 1)
    {
        head = insertAtBeginning(head, data);
        return head;
    }
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of bonds . Inserting at the end position ...");
        head = insertAtEnd(head, data);
        return head;
    }
    if (temp->next == NULL)
    {
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    newNode->next->prev = newNode;
    temp->next = newNode;
    return head;
}

struct Node *deleteAtBeginning(struct Node *head)
{
    if (head == NULL)
    {
        printf("Deletion not possible as list is empty.");
        return head;
    }
    struct Node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("Deletion not possible as list is empty.");
        return head;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct Node *deleteAtMiddle(struct Node *head, int pos)
{
    if (head == NULL)
    {
        printf("Deletion not possible as list is empty.");
        return head;
    }
    struct Node *temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        temp->prev->next = NULL;
        free(temp);
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    return head;
}

void searchNode(struct Node * head , int key){
    struct Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            printf("\nNode is found with data %d",key);
            return;
        }
    }
    if(temp == NULL){
        printf("\nNode is not found with data %d key ",key);
    }

}

void reverseNode(struct Node* head){
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp ->next;
    }
    printf("\nNULL <-");
    while(temp != head){
        printf("%d <- ",temp->data);
        temp = temp -> prev;
    }
    printf("%d ",head->data);
}

void printNode(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty !! ");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {
    struct Node *head = NULL;
    int choice, data, pos;

    do {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Middle\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Middle\n");
        printf("8. Search Node\n");
        printf("9. Print List\n");
        printf("10. Reverse List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes to create: ");
                scanf("%d", &data);
                head = createLinkedList(head, data);
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 4:
                printf("Enter data to insert at middle: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertAtMiddle(head, data, pos);
                break;
            case 5:
                head = deleteAtBeginning(head);
                break;
            case 6:
                head = deleteAtEnd(head);
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = deleteAtMiddle(head, pos);
                break;
            case 8:
                printf("Enter key to search: ");
                scanf("%d", &data);
                searchNode(head, data);
                break;
            case 9:
                printNode(head);
                break;
            case 10:
                reverseNode(head);
                break;
            case 11:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 11);

    return 0;
}
