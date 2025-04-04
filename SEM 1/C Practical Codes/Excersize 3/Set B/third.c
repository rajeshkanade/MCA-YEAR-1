#include<stdio.h>
#include<math.h>
float calPower(float x , float i){
    return pow(x,i);
}
float calFactorial(float i){
    float fact = 1;
    for(float j = 1  ; j <= i ; j++){
        fact = fact * j;
    }
    return fact;
}
float main(){
    float x ;
    int  n ;
    printf("Enter the value of x : ");
    scanf("%f",&x);
    printf("Enter the value of n : ");
    scanf("%d",&n);
    float sum = 0 ; 
    for(int i = 0 ; i < n ; i++){
        int sign = (i % 2 == 0) ? -1 : 1; 
        
        sum += sign *(calPower(x,2 * i + 1)/calFactorial(2 * i + 1));
        // printf("%d ")
    }
    printf("sum : %f ", sum);


}