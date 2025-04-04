#include<stdio.h>
#include<stdlib.h>
void printArr(int arr[], int n){
//   printf("Sorted array element are :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void getArr(int arr[],int n){
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
}
void selectionSort(int arr[], int n){
    for(int i = 0 ; i < n - 1; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(arr[i] > arr[j]){ 
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
       
    }
  printf("Sorted array element are :");

        printArr(arr,n);


}

// This is the actual way to write the selection sort algorithm. 
void selectionSort2(int arr[], int n){
    int j , cmpcnt = 0 , swpcnt = 0 , flag;
    for(int i = 0 ; i < n - 1; i++){
        int min = i;
        flag  = 0;
        for( j = i + 1 ; j < n ; j++){
            if(arr[min] > arr[j]){ 
                flag = 1;
                min = j;
                cmpcnt ++;
            }
        }
        if(flag == 0){
            break;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        swpcnt ++;
         printf("Iteration %d : ", i+1 );
        printArr(arr,n);
        printf("\n");
    }
  printf("Sorted array element are :");

    printArr(arr,n);
    printf("\n Compare Count : %d", cmpcnt);
    printf("\n Swapped Count : %d", swpcnt);
}
int main(){
    int n ;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    int *arr = malloc(n*sizeof(int));

    getArr(arr,n);
    // selectionSort(arr,n);
    selectionSort2(arr,n);


}