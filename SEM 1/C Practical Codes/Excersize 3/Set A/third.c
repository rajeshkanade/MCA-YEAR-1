// Write a function isEven, which accepts an integer as parameter and retruns 1 if the number is even. and 0 otherwise. Use this function in main to accepts n numbers and check if they are even or odd.

#include<stdio.h>
#include<stdbool.h>
bool isEven(int no){
    if(no % 2 == 0){
        return 1;
    }else{
        return 0;
    }

}
int main(){
    int n ;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    int no[n];
    printf("Enter %d numbers : \n",n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&no[i]);
         if(isEven(no[i])){
        printf("%d Number is Even ...\n",no[i]);
    }else{
        printf("%d Number is Odd ...\n",no[i]);
    }
    }
   
    return 0;
}



