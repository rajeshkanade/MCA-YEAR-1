// Question: 
// Write a C program to perform the following operations on singly linked lists:
// 1. Create two separate linked lists (List 1 and List 2).
// 2. Print the elements of each list.
// 3. Merge the two lists into a single sorted list and print the result.
// 4. Merge the two lists into a single sorted list with unique elements and print the result.
// 5. Provide a menu-driven interface for the user to perform these operations.

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

Node* insertAtEnd(Node* node , int data){
    Node* newNode = createNode(data);
    if(node == NULL){
        node = newNode;
        return node;
    }
    Node* temp = node;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return node;
}

Node *createList(Node *list, int n)
{
    int data;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        Node *newNode = createNode(data);
        if (list == NULL)
        {
            list = newNode;
        }
        else
        {
            Node *temp = list;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return list;
}
void displayMenu()
{
    printf("Menu:\n");
    printf("1. Create List 1\n");
    printf("2. Create List 2\n");
    printf("3. Print List 1\n");
    printf("4. Print List 2\n");
    printf("5. MergeListPrint\n");
    printf("6. Merge Unique Elements\n");
    printf("7. Exit\n");
}

Node *mergeSortedList(Node *list1, Node *list2)
{
    Node *mergeList = NULL;
    Node *temp1 = list1;
    Node *temp2 = list2;
    while (temp1 != NULL && temp2 != NULL)
    {
            if (temp1->data <= temp2->data){
                mergeList = insertAtEnd(mergeList,temp1->data);
                temp1 = temp1->next;
            }
            else{
                mergeList = insertAtEnd(mergeList,temp2->data);
                temp2 = temp2->next;
            }
    }
    while(temp1 != NULL){
        mergeList = insertAtEnd(mergeList,temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        mergeList = insertAtEnd(mergeList,temp2->data);
        temp2 = temp2->next;
    }
    return mergeList;
}

Node *mergeUniqueElement(Node *list1, Node *list2)
{
    Node *mergeList = NULL;
    Node *temp1 = list1;
    Node *temp2 = list2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            mergeList = insertAtEnd(mergeList, temp1->data);
            temp1 = temp1->next;
        }
        else if (temp1->data > temp2->data)
        {
            mergeList = insertAtEnd(mergeList, temp2->data);
            temp2 = temp2->next;
        }
        else
        {
            mergeList = insertAtEnd(mergeList, temp1->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        mergeList = insertAtEnd(mergeList, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        mergeList = insertAtEnd(mergeList, temp2->data);
        temp2 = temp2->next;
    }

    return mergeList;
}

void printList(Node *list)
{
    Node *temp = list;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;
    Node *mergeList = NULL;
    int choice, n;

    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of elements for List 1: ");
            scanf("%d", &n);
            printf("Enter elements for List 1:\n");
            list1 = createList(list1, n);
            break;
        case 2:
            printf("Enter number of elements for List 2: ");
            scanf("%d", &n);
            printf("Enter elements for List 2:\n");
            list2 = createList(list2, n);
            break;
        case 3:
            printf("List 1: ");
            printList(list1);
            break;
        case 4:
            printf("List 2: ");
            printList(list2);
            break;
        case 5:
            printf("Combined Sorted List : ");
            mergeList = mergeSortedList(list1, list2);
            printList(mergeList);
            break;
        
        case 6:
            printf("Combined Sorted List : ");
            mergeList = mergeUniqueElement(list1, list2);
            printList(mergeList);
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
