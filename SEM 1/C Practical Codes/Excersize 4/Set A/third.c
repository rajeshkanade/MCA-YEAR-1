// Find the factorial of number using recursion function  


#include<stdio.h>
int findFact(int n){
    if(n == 0){
        return 1;
    }
        return (n * findFact(n-1));
    
}
int main(){
    int n ; 
    scanf("%d",&n);

    int result = findFact(n);
    printf("Factorial of %d is %d ", n , result);
}