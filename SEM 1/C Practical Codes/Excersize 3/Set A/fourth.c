// Write a function, which accepts a character and integer n as parameter and display the next n characters.


#include<stdio.h>
void printsNCharaters(char ch , int no){
        printf("printing character from %c to nth number %d are : ",ch,no);
        int incr = 1;
    while(incr <= no){
        printf("%c ",ch);
        ch++;
        incr++;
    }
    printf("\n");
}
int main(){
    int n ;
    char c ;
    printf("Enter the character : ");
    scanf("%c",&c);
    printf("Enter the nth number : ");
    scanf("%d",&n);

    printsNCharaters(c,n);
    return 0;
}