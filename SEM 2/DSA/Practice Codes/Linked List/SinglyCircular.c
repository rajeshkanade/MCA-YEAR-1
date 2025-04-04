#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->data = data;
    newNode->next = newNode;

    return newNode;
}
struct Node *createLinkedList(struct Node *head, int n)
{
    int data;
    for (int i = 1; i <= n; i++)
    {
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

struct Node* insertNodeAtBegin(struct Node* head, int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return head;
    }
    struct Node* temp = head;
    while(temp->next!= head){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    head = newNode;
    return head;
}

struct Node* insertNodeAtEnd(struct Node* head, int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return head;
    }
    struct Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertNodeAtMiddle(struct Node* head, int data , int loc){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        printf("List is empty cannot insert at Middle !!!!");
        return head;
    }
    struct Node* temp = head;
    for(int i = 1 ; i < loc - 1 ; i++){
        temp = temp->next;
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
        printf("List is Empty ...");
        return;
    }
    while (temp->next != head)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Create Linked List\n");
    printf("2. Insert Node At Begin \n");
    printf("3. Insert Node At End \n");
    printf("4. Insert Node At Middle \n");
    printf("5. Delete Node At Begin\n");
    printf("6. Delete Node At End\n");
    printf("7. Delete Node At Middle\n");
    printf("8. Search Node\n");
    printf("9. Print List\n");
    printf("10. Exit\n");
}



int main() {
    struct Node *head = NULL;
    int choice, data , pos;
    // head = createNode(10);
    // head = createLinkedList(head, 5);
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertNodeAtBegin(head, data);
                break;
            case 2:
                printf("Enter data to insert at the End : ");
                scanf("%d", &data);
                head = insertNodeAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert at middle: ");
                scanf("%d", &data);
                printf("Enter the position insert at : ");
                scanf("%d",&pos);
                head = insertNodeAtMiddle(head, data,pos);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                // head = deleteNodeAtBegin(head, data);
                break;
            case 5:
                printf("Enter data to search: ");
                scanf("%d", &data);
                // if (searchNode(head, data)) {
                //     printf("Node with data %d found.\n", data);
                // } else {
                //     printf("Node with data %d not found.\n", data);
                // }
                break;
            case 9:
                printNode(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
