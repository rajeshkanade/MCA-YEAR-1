// Find GCD using the recursion function 

#include<stdio.h>
int caluculate_GCD(int x , int y){
    if(x == 0){
        return y ;
    }
    else if(y == 0){
        return x;
    }
    else{
        return caluculate_GCD(y, x % y);
    }
}
int main(){
    int x , y ;
    printf("Enter the number to find GCD : ");
    scanf("%d%d",&x , &y);

    int result = caluculate_GCD(x,y);
    printf("GCD is : %d",result);
}