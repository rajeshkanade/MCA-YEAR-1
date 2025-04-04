#include<stdio.h>
int PrintSingleNoReverse(int n){
    if(n == 0){
        return 0;
    }
    printf("%d\t",(n%10));
    return PrintSingleNoReverse(n/10);
}
int main(){
    int n ;
    scanf("%d",&n);
    PrintSingleNoReverse(n);
}