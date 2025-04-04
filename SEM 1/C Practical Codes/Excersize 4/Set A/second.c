// Write a recursive function to calculate the x to the power y 

#include<stdio.h>
int findXtoPowerY(int x , int y){
    if(y == 0){
        return 1;
    }
    return x * findXtoPowerY(x,y-1);
}
int main(){
    int x , y;
    printf("Enter the value of x to the power y : ");
    scanf("%d%d",&x,&y);
    int result = findXtoPowerY(x,y);
    printf("%d to the power of %d is : %d\n",x,y,result);
}