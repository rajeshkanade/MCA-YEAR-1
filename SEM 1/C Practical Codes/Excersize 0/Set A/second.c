#include<stdio.h>
int main(){
    int x , y;
    printf("Enter the 2 coardinates : \n");
    scanf("%d%d",&x , &y);

    if(y > x ){
    int  dist_betw = y - x; 
    printf("Distance between : %d\n",dist_betw);

    }
    else{
        printf("we cannot find distance between x and y \n");
    }

}