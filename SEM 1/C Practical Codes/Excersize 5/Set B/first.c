// 1. Write a program to merge two sorted arrays into a third array such that the third array is also in the sorted order  
#include<stdio.h>
int sortedArray(int arr1[] , int arr2[], int size1 , int size2){
    int mergeArr[size1 + size2];
    int k = 0, i = 0 , j = 0;
    while(i < size1){
        mergeArr[k++] = arr1[i++];
    }
    while(j < size2){
        mergeArr[k++] = arr2[j++];
    }

    for(int i = 0 ; i < size1 + size2 - 1 ; i++){
        for( j = i + 1 ; j <  size1 + size2 ; j++){
            if(mergeArr[i] > mergeArr[j]){
                int temp = mergeArr[i];
            mergeArr[i] = mergeArr[j];
            mergeArr[j] = temp;
            }
        }
    }
    for(int i = 0 ; i < size1 + size2 ; i++){
        printf("%d " , mergeArr[i]);
    }
}
int main(){

    int arr1[3] = {10,25,90};
    int arr2[5] = {9,16,22,26,100};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    sortedArray(arr1,arr2,size1,size2);
    return 0;
}