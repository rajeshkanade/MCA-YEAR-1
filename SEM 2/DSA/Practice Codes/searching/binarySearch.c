#include<stdio.h>
#include<stdlib.h>
void getArr(int arr[],int n){
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
}


void binarySearch(int arr[],int n,int key){
    int startIndex = 0 , endIndex = n -1 ;
    int midIndex ;
    midIndex = (endIndex + startIndex)/2;
    int flag = 0;

    // printf("\n StartIndex is %d and element is %d",startIndex,arr[startIndex]);
    // printf("\n EndIndex is %d and element is %d",endIndex,arr[endIndex]);
    // printf("\n midIndex is %d and element is %d",midIndex,arr[midIndex]);

   while(startIndex != endIndex){
        if(arr[midIndex] == key)
            flag = 1;
            break;
        }else if(arr[midIndex] > key){
            endIndex = midIndex - 1;
            midIndex = (endIndex - startIndex)/2;
        }else if(arr[midIndex] < key){
            startIndex = midIndex + 1;
        }
        midIndex = (endIndex + startIndex)/2;
    }
    if(flag){
        printf("Element is Found !!!!");
    }else{
        printf("Element is not Found !!!!");
    }
}

void SortArray(int *arr , int n){
    int flag = 0;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
            if(arr[j] > arr[j+1]){
                flag = 1;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(!flag){
            break;
        }
    }
    printf("Run succesffuly ...");
    // binarySearch(arr,n,5);
}
int main(){
    int n;
    printf("Enter the value of N : ");
    scanf("%d",&n);
    int *arr = (int*) malloc(n*sizeof(int));
    getArr(arr,n);
    int key ; 
    printf("Enter the element to search : ");
    scanf("%d",&key);
    // SortArray(arr,n);
    binarySearch(arr,n,key);
}