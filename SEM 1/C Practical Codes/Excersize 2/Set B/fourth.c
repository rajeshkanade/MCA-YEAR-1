#include<stdio.h>
int main(){
    int n;
    char ch = 'A';
    printf("Enter the value of n : ");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 4 - i ; j++){
            printf("%c ",ch);
            ch++;
        }
        printf("\n");
    }
    return 0;
}