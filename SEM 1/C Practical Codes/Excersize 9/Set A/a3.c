//a3.c

#include<stdio.h>

#define EQUALINT(x,y) ((x==y)?1:0)
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
    int x,y;
    while(1)
    {
        printf("Enter an integer x: ");
        scanf("%d",&x);
        printf("Enter an integer y: ");
        scanf("%d",&y);
    
        int sumX = sumOfDigits(x);
        int sumY = sumOfDigits(y);
        
        if(EQUALINT(sumX,sumY))
        {
            printf("\nSums are equal.Continuing...");
        }
        else
        {
            printf("\nSums are not equal.Exiting...");
            break;
        }
    }
}