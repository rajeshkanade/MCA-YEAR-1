// Find the fibonacci series using recursion 
#include<stdio.h>
int calculateFibonaci(int n) {
    if( n == 1 || n == 2){
        return 1;
    }
    return calculateFibonaci(n-2)+calculateFibonaci(n-1);
}
int main(){
    int n ; 
    scanf("%d",&n);

    int result = calculateFibonaci(n);
    printf("%d",result);
}