#include<stdio.h>
#include<stdlib.h>
void getArr(int arr[],int n){
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
}
void printArr(int arr[],int n){
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void insertionSort(int *arr,int n){
    int j;
    for(int i = 1 ; i < n ; i++){
        int temp = arr[i];
        for(j = i-1 ; j >= 0 && arr[j] > temp ; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }

}
int main(){

    int n;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n * sizeof(int));
    getArr(arr, n);
    printArr(arr,n);
    insertionSort(arr,n);
    printArr(arr,n);

    return 0;
}