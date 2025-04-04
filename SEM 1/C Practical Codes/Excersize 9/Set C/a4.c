//a4.c

#include<stdio.h>

#define EQUALSTR(x,y) ((strcmp(x,y)==0)?1:0)
int sumOfDigits(int x)
{
    int sum =0;
    do{
        int r = x%10;
        sum += r;
        x = x/10;
    }while(x!=0);
    return sum;
}
int main()
{
    char x[10],y[10];
    
    printf("Enter string x: ");
    gets(x);
    printf("Enter string y: ");
    gets(y);
    
    if(EQUALSTR(x,y))
    {
        printf("\nStrings are equal.");
    }
    else
    {
        printf("\nStrings are not equal.");
        //break;
    }
}