#include<stdio.h>
void printPosAndMsg(int arr[]){
     int positiveArr[10];
    int negativeArr[10];
    int pcnt = 0 , ncnt = 0;

    for(int i = 0 ; i < 10 ; i++){
        if(arr[i] > 0){
            positiveArr[pcnt++] = arr[i];
        }else{
            negativeArr[ncnt++]  = arr[i];
        }
    }
    printf("Positive number array is : ");
    for(int i = 0 ; i < pcnt ; i++){
        printf("%d " , positiveArr[i]);
    }
    printf("\n");
     printf("Negative number array is : ");
    for(int i = 0 ; i < ncnt ; i++){
        printf("%d " , negativeArr[i]);
    }
}
int main()
{
    int arr[10];
    printf("Enter any positive or negative 10 numbers : ");
    for(int i = 0 ; i < 10 ; i++){
        scanf("%d",&arr[i]);
    }
    printPosAndMsg(arr);
    return 0;
}