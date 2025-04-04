#include<stdio.h>
int main(){
    int withdraw;
    printf("Enter the amount to withdraw : ");
    scanf("%d",&withdraw);
    int one_notes = withdraw / 1;
    int five_notes = withdraw / 5;
    int ten_notes = withdraw / 10;

    printf("Total 1 notes required for %d is %d \n",withdraw,one_notes);
    printf("Total 5 notes required for %d is %d \n",withdraw,five_notes);
    printf("Total 10 notes required for %d is %d \n",withdraw,ten_notes);

}