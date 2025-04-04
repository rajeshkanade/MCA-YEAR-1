#include<stdio.h>
#include<math.h>
int main(){
    int n ;
    float x ;
    printf("Enter the value of n : ") ;
    scanf("%d",&n);
    printf("Enter the value of x : ");
    scanf("%f",&x);

    float factorialNumber = 1;
    float xToPower ;
    float sum = 0;
    for(int i = 1 ; i <= n; i++){
        factorialNumber = factorialNumber * i;
        xToPower = pow(x,i);
        sum = sum + (factorialNumber/xToPower);
    }

    printf("Sum is : %.5f",sum);
}