#include<stdio.h>
int main(){
    int no ;
    printf("Enter the number : ");
    scanf("%d",&no);
    int rem = 0 , sum = 0 , count = 0;
    while(no > 0){
        rem = no % 10;
        sum = sum + rem;
        no = no / 10;
        count++;
    }
    printf("Sum of all the Digit is : %d\n", sum);
    printf("Total Digit are         : %d\n", count);
}