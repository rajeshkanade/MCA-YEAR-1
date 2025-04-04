// Write the function for Linear Search , which accepts an array of n elements and a key as parameters and returns the position of key in the array and -1 if the key is not found. Accept n numbers from the user, store them in an array. Accept the key to be searched and search it using this function. Display appropriate messages.  


#include<stdio.h>
int SearchKeyElement(int arr[] , int key , int n){

    for(int i = 0 ; i < n ; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}
int main(){

    int n ;
    printf("Enter the value of n : ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d numbers : ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the number to find : ");
    scanf("%d",&key);


    int result = SearchKeyElement(arr,key,n);
    printf("element is found at %d position...",result+1);
    return 0;
}