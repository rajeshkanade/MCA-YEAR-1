// Accept n integersw in array A. Pass this array and two counter variables to a function which will set the first counter to the total number of even values in the array and the other total number of odd values. Display these counts in main. 
// (Hint : pass the addresses of the counteres to the function)
#include<stdio.h>
#include<stdlib.h>
int checkEvenOdd(int *arr,int *evenCnt, int *oddCnt,int size){
    for(int i = 0 ; i < size ; i++){
        if(arr[i] % 2 == 0){
            *evenCnt += 1;
        }
        else{
            *oddCnt += 1;
        }
    }
}
int main(){
    int *arr;
    int n , evenCnt = 0 , oddCnt = 0;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    arr = (int*) malloc(n * sizeof(int));
    printf("Enter the %d Array elements : ",n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }

    checkEvenOdd(arr,&evenCnt,&oddCnt,n);
    printf("Total Even Numbers are : %d",evenCnt);
    printf("\nTotal Odd Numbers are : %d",oddCnt);
    printf("\n");
    return 0;
}