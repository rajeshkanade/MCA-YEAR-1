#include<stdio.h>
int sumOfDigit(int n){
    if(n == 0){
        return 0;
    }
    else{
        return (n % 10) + sumOfDigit(n / 10);
    }
}
int main(){

    int n ;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    if(n > 10){

        printf("Sum = %d -> ",n);
        while(n > 9){
            int resultSum = sumOfDigit(n);
            printf("%d -> ", resultSum);
            n = resultSum;
        }
    }
    else{
        printf("Sum = %d",n);
    }
    return 0;
}