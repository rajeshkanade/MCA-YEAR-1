#include<stdio.h>
int main(){
    int start , end;
    printf("Enter the Starting number of table : ");
    scanf("%d",&start);
    printf("Enter the Ending number of the table : ");
    scanf("%d",&end);
    for(int i = 1 ; i <= 10; i++){
       for(int j = start ; j <=end ; j++){
        printf("%d * %d = %d\t",j,i,(j*i));
       }
       printf("\n");
    }
}