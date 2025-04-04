// Write a function which accepts a number and three flags as parameters. If the numbers is even, set the first flag to 1. If the number is prime, set the second flag to 1. If the number divisible by 3 or 7, set the third flag to 1. In main, accept an integer and use this function to check if it is even, prime and divisible by 3 or 7. (Hint : pass the addresses of flags to the function)

#include <stdio.h>
void threeFlagFunction(int n, int *firstFlag, int *secondFlag, int *thirdFlag)
{
    int isPrime = 0;
    if (n % 2 == 0)
    {
        *firstFlag = 1;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            *secondFlag = 0;
            break;
        }
        else{
            *secondFlag = 1;
        }
    }


    if (n % 3 == 0 || n % 7 == 0)
    {
        *thirdFlag = 1;
    }
}
int main()
{
    int n;
    printf("Enter the value of number : ");
    scanf("%d", &n);

    int firstFlag = 0, secondFlag = 0, thirdFlag = 0;
    threeFlagFunction(n, &firstFlag, &secondFlag, &thirdFlag);
    if (firstFlag)
    {
        printf("\n%d number is even ..",n);
    }
    else
    {
        printf("\n%d number not is even ..",n);
    }
    if (secondFlag)
    {
        printf("\n%d number is prime",n);
    }
    else
    {
        printf("\n%d number not is prime",n);
    }
    if (thirdFlag)
    {
        printf("\n%d number is divisible of 3 or 7",n);
    }
    else
    {
        printf("\n%d number is not divisible of 3 or 7",n);
    }

    return 0;
}