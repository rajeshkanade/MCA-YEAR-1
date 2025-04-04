#include<stdio.h>
int main(){

    int n ;
    printf("Enter the number : ");
    scanf("%d",&n);
    int rem;
    while(n > 0){
        rem = n % 10;
        printf("%d\t" , rem);
        n /= 10;
    }
    return 0;
}