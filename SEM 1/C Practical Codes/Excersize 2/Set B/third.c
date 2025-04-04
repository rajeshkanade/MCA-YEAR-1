// Displaying all perfect numbers below 500. 
// Perfect number are those number whose factor sum is equal to that specific number 
// eg. 6 = 1 + 2 + 3 = 6 

#include<stdio.h>
int main(){
    int sum = 0;
    for(int i = 1 ; i <= 500 ; i++){
       sum = 0;
        for(int j = 1 ; j <= i/2 ; j++){
            if(i % j == 0 ){
                sum = sum + j;
            }
        }
        if(sum == i){
            printf("%d\t",i);
        }
    }
    printf("\n");
    return 0;
}