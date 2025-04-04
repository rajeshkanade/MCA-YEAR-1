// Write a program to basic Set ADT Implementation Using arrays : Implement a set ADT using arrays that supports the following operations.

// Operation are  : Insert , Delete , Contains , Display

#include <stdio.h>
#define MAX 100

typedef struct ArrayADT
{
    int arr[MAX];
    int size;
} ArrayADT;

void insertElement(ArrayADT *a, int element, int index)
{
    int flag = 0;
    if (a->size >= MAX)
    {
        printf("\nArray is full !! Cannot insert the element !!!");
        return;
    }
    if (index < 0 || index > a->size)
    {
        printf("\nCannot insert the element !!! Index out of bond !!!");
        return;
    }
    for (int i = 0; i < a->size; i++)
    {
        if (a->arr[i] == element)
        {
            flag = 1;
        }
    }
    if (!flag)
    {

        for (int i = a->size; i > index; i--)
        {
            a->arr[i] = a->arr[i - 1];
        }
        a->arr[index] = element;
        a->size++;
    }
    else
    {
        printf("\nCannot insert the element !!!Element is already present in Array !!!! ");
    }
}

void deleteElement(ArrayADT *a, int index)
{
    if (a->size == 0)
    {
        printf("\ncannot delete element !!! becoz array is empty !!!!");
        return;
    }
    if (index < 0 || index > a->size)
    {
        printf("\nCannot delete Element cause !! array index out of bond !!!");
    }
    for (int i = index; i < a->size; i++)
    {
        a->arr[i] = a->arr[i + 1];
    }
    a->size--;
    printf("\nElement is deleted at %d index ", index);
}

int containsElement(ArrayADT *a, int element)
{
    int flag = 0;
    for (int i = 0; i < a->size; i++)
    {
        if (a->arr[i] == element)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("\n%d element exists !!!!", element);
    }
    else
    {
        printf("\n%d element not exists !!!!", element);
    }
    return 0;
}

void displayElements(ArrayADT *a)
{
    for (int i = 0; i < a->size; i++)
    {
        printf("%d ", a->arr[i]);
    }
}

void displayMenu()
{
    printf("\nMenu:\n");
    printf("\n1. Insert\n");
    printf("\n2. Delete\n");
    printf("\n3. Contains\n");
    printf("\n4. Display\n");
    printf("\n5. Exit\n");
}

int main()
{
    ArrayADT a;
    a.size = 0;
    int choice, data, index;

    do
    {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter element to insert: ");
            scanf("%d", &data);
            printf("\nEnter the index to insert element at: ");
            scanf("%d", &index);
            insertElement(&a, data, index);
            break;
        case 2:
            printf("\nEnter element index to delete : ");
            scanf("%d", &index);
            deleteElement(&a, index); // Placeholder call
            break;
        case 3:
            printf("\nEnter the element to check if exists : ");
            scanf("%d", &data);
            containsElement(&a, data); // Placeholder call
            break;
        case 4:
            displayElements(&a); // Placeholder call
            break;
        case 5:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
        printf("\n\n");
    } while (choice != 5);

    return 0;
}
