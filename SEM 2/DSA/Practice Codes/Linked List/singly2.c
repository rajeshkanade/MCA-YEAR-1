#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* initialize(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    return head;

}

struct Node* createNode(struct Node* head , int n){
    struct Node* temp , *f ;
    int data;
    for(int i = 1 ; i <= n ; i++){
        printf("Enter the data to insert for %d node : ", i);
        
        scanf("%d",&data);
        if(head == NULL){
            f = (struct Node*)malloc(sizeof(struct Node*));
            f->data = data;
            f->next = NULL;
            head = f;
        }else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }

            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    temp->next = newNode;

        }
    }
    
    return head;
}

struct Node* InsertAtBeginning(struct Node* head,int data){
    struct Node* newNode = createNode(head,data);
    newNode->next = head;
    head = newNode;
    return head;
    
}

struct Node* printNode(struct Node* head){
    struct Node* q = head;
    while(q!= NULL){
        printf("%d->",q->data);
        q = q->next;
    }
    printf("NULL\n");
}
nter element index to delete : ");
            scanf("%d",&index);
int main(){
    int n;
    struct Node* head;
    printf("enter the element to insert in linked list : ");
    scanf("%d",&n);
    head = createNode(head,n);
    
    
    // head = InsertAtBeginning(head,data);
    // printf("Linked list is : ");
    printNode(head);nter element index to delete : ");
            scanf("%d",&index);

    return 0;
}