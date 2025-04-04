#include<stdio.h>
int main(){
    int arr[] = {2,11,4,5,12,1,4,66,7,44,55};
    int n , flag = 0;
    printf("Enter number to search : ");
    scanf("%d",&n);

    for(int i = 0 ; i < (sizeof(arr)/4) ; i++){
        if(n == arr[i]){
            flag = 1;
            break;
        }
    }

    if(flag){
        printf("Element found !!!");
    }else{
        printf("Element not found !!!");
    }
}