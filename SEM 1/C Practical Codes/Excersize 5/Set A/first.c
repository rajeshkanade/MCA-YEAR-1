// Write a function to sort an array of n intergers. Accept n numbers from the user, store then in an array and sort them using this function. Display the sorted array. 

#include<stdio.h>
void sortedArray(int arr[], int n){
    int temp = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main(){

    int n = 10;
    printf("Enter the value n :");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d numbers : " , n);
    for(int i = 0; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    
    printf("Unsorted Array is : ");
   for(int i = 0 ; i < n ; i++){
    printf("%d ",arr[i]);
   }
    
    printf("\n");

   sortedArray(arr, n);
   printf("Sorted Array is : ");
   for(int i = 0 ; i < n ; i++){
    printf("%d ",arr[i]);
   }
    return 0;
}