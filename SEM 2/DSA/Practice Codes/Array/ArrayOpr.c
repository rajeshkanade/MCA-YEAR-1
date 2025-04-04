#include<stdio.h>
#define MAX 100
struct ArrayADT{
    int arr[MAX];
    int size;
};
void insertElement(struct ArrayADT* array, int element , int index);
void deleteElement(struct ArrayADT* array , int index);
void traverseArray(struct ArrayADT* array);
int searchElement(struct ArrayADT* array , int element);
int updateElement(struct ArrayADT* array , int element , int index);
void menu();

int main(){
    struct ArrayADT array;
    array.size = 0;
    int choice,element, index;

    while(1){
        menu();
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            // insert element 
            printf("\nEnter the elemnt to insert : ");
            scanf("%d",&element);
            printf("\nEnter index to insert at : ");
            scanf("%d",&index);
            insertElement(&array,element, index);
            break;
        case 2 : 
            // delete element 
            printf("\nEnter the index to delete Element at : ");
            scanf("%d",&index);
            deleteElement(&array, index);
            break;
        case 3 : 
            // tranverse array : 
            traverseArray(&array);
            break;
        case 4 : 
            // search array element 
            printf("\nEnter the element to search : ");
            scanf("%d",&element);
            index = searchElement(&array,element);
            if(index != -1){
                printf("\nElement found at index %d\n",index);

            }else{
                printf("\nElement not found ...");
            }
            break;
        case 5 : 
            // update array 
            printf("\nEnter array element to update : ");
            scanf("%d",&element);
            printf("\nEnter the index to update at : ");
            scanf("%d",&index);
            updateElement(&array,element,index);
            break;
        case 6 : 
            printf("\nExited ....");
            return(0);
            break;

        default:
            printf("\nEnter the valid choice !!!!!!");
            break;
        }
    }
    return 0;
}

// menu function to display menu 

void menu(){
    printf("\nMenu : \n");
    printf("\n1.Insert Element ");
    printf("\n2.Delete Element ");
    printf("\n3.Traverse Element ");
    printf("\n4.Search Element ");
    printf("\n5.Update Element ");
    printf("\n6.Exit ");
}

// Function to insert element in array. 

void insertElement(struct ArrayADT* array , int element , int index){
    if(array->size >= MAX){
        printf("\nCan't Insert value array is full !!!!");
        return;
    }
    if(index < 0 || index > array->size){
        printf("\nInvalid Index ...! Insertion failed \n");
        return;
        }
    
    for(int i = array->size ; i > index; i--){
        array->arr[i] = array->arr[i-1];
    }

    array->arr[index] = element;
    array->size++;
    printf("\nElement inserted at index %d \n.",index);
}

// Function to delete element in array 
void deleteElement(struct ArrayADT* array, int index){
    if(index , 0 || index >= array->size){
        printf("\nInvalid index ! Deletion Failed !");
        return;
    }

    for(int i = index ; i < array->size - 1; i++){
        array->arr[i] = array->arr[i+1];

    }
    array->size--;
    printf("\nElement deleted at index %d \n", index);
}

// Function to update the element in array.
int updateElement(struct ArrayADT* array , int element , int index){
    if(index < 0 || index >= array->size){
        printf("\nInvalid Index ! Update failed \n");
        return -1;
    }
    array->arr[index] = element;
    printf("\nElement at index %d updated to %d ", index , element);
    return index;
}

// Function to tranverse array 
void traverseArray(struct ArrayADT* array){
    if(array->size == 0){
        printf("\nArray is Empty !");
        return;
    }
    printf("\nArray Elements : ");
    for(int i = 0 ; i < array->size ; i++){
        printf("%d ",array->arr[i]);
    }
    printf("\n\n");
    
}

// Function to search an element in the array. 
int searchElement(struct ArrayADT* array , int element){
    for(int i = 0 ; i < array->size ; i++){
        if(array->arr[i] == element){
            return i;
        }
    }
    return - 1;
}
