// Fibonnacci printing from 0 to 100; 

#include<stdio.h>
int main(){
    
    int prev = 0 , next = 1 , sum = 0 ; 
    
    while(sum <= 100){
        printf("%d " , sum);
        prev = next ; 
        next = sum ; 
        sum = prev + next;
    }
}