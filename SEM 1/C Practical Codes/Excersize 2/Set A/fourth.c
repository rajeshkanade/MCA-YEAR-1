#include<stdio.h>
int main(){
    int no;
    int rev = 0 , rem = 0 ;

    printf("Enter the number : ");
    scanf("%d",&no);
    int temp = no;

    while( temp > 0){
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp = temp / 10;
        // printf("rev %d",rev);
    }
    if(no == rev){
        printf("%d number is pallendrome number !!!\n",no);
    }else{
        printf("%d number is not pallendrome number !!!\n",no);
    }

}


// 1 % 10 = 0

sum = 9;