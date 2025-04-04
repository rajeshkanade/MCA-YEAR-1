#include<stdio.h>
#include<stdlib.h>
void SwapTwoArr(int *p , int *q , int n , int m){
    if(n > m){
        for(int i = 0 ; i < n ; i ++){
        int temp = *(p+i);
        *(p+i) = *(q+i);
        *(q+i) = temp;
    }
    }else{
        for(int i = 0 ; i < m ; i ++){
        int temp = *(p+i);
        *(p+i) = *(q+i);
        *(q+i) = temp;
    }
    }
    printf("\nFirst Array After Swapping   : ");
    for(int i = 0 ; i < m ; i++){
        printf("%d ",*p+i);
    }
    printf("\nSecond Array After Swapping  : ");
    for(int i = 0 ; i < n ; i++){
        printf("%d ",*q+i);
    }
}
int main(){

    int *a , *b;
    int n,m ;
    printf("Enter the length of the array 1 : ");
    scanf("%d",&n);
    printf("Enter the length of the array 2 : ");
    scanf("%d",&m);
    a = (int*) malloc(n * sizeof(int));
    b = (int*) malloc(n * sizeof(int));
    printf("Enter %d element for array 1 : ",n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",a+i);
    }
    printf("Enter %d element for array 2 : ",n);
    for(int i = 0 ; i < m ; i++){
        scanf("%d",b+i);
    }
    printf("\nFirst Array before Swapping  : ");
    for(int i = 0 ; i < n ; i++){
        printf("%d ",*a+i);
    }
    printf("\nSecond Array before Swapping : ");
    for(int i = 0 ; i < m ; i++){
        printf("%d ",*b+i);
    }
    SwapTwoArr(a,b,n,m);
    return 0;
}