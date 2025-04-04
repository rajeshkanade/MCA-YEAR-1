// checking prime or not 

#include<stdio.h>
int main(){
    int no ;
    int flag = 0;
    printf("Enter the number : ");
    scanf("%d",&no);
    for(int i = 2 ; i < no ; i++){
        if(no % i == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("%d no is prime number " , no);
    }
    else{
        printf("%d no is not prime number " , no);

    }
}