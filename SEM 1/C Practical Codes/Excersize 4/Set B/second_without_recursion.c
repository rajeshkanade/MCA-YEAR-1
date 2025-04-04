#include<stdio.h>
int main(){
    long int n; 
    int sum = 0;
    printf("Enter the Number : ");
    scanf("%d",&n);
    while(n > 10){
        int temp = n;
        sum = 0;
       while(temp != 0){
         int rem = temp % 10;
        sum = sum + rem;
        temp /= 10;
       }
       if(sum > 10){
        printf(" %d ->",sum);
       }
       else{
        printf(" %d " ,sum);

       }
       n = sum;
    }
}