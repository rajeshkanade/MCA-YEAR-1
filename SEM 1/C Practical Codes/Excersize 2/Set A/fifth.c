#include<stdio.h>
int main(){
    int i=1,j=1;
    int count=1;
   
   for(int i=1;i<=4;i++){
    for(int j = 1 ; j <= 4-i;j++){
        printf(" ");
    }
    for(int k = i ; k <=i ; k++){
        printf("%d ",count);
        count++;
        for(int l = 1 ; l < i ; l++){
            printf("%d ",count);
            count++;
        }
    
    printf("\n");
   }
}