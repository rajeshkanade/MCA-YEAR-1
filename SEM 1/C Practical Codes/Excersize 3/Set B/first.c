// Write the functtion isPrime, which accepts an integer as parameter and returns 1 if the number is prime and 0 otherwise. Use this function in main to display the first 10 prime numbers. 

#include<stdio.h>
int isPrime(int n){
    for(int i = 2 ; i <= n - 1 ; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
int main(){
    int count = 1; 
    int i = 1;
    while(count <= 10){

        if(isPrime(i)){
            printf("%d ",i);
            count++;
        }
        i++;
    }
    return 0;
}





