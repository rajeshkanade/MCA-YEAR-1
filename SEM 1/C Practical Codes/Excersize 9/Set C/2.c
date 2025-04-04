//2.c

#include<stdio.h>

#define INRANGE(m) (m>=1 && m<=12)
#define NEGATIVE(m) (m<0)
#define ISLOWER(c) (c>='a' && c<='z')
#define ISUPPER(c) (c>='A' && c<='Z')
#define ISALPHA(c) (ISLOWER(c) || ISLOWER(c))
#define ISDIGIT(c) (c>='0' && c<='9')

int main()
{
    int m;
    char c;
    printf("Enter an integer corresponding to the month: ");
    scanf("%d",&m);
   
    
    if(NEGATIVE(m))
    {
        printf("\nEnter the positive number.");
    }
    else
    {
        if(INRANGE(m))
        {
            printf("\nYou entered valid month.");
        }
    }
    // Clear input buffer to handle newline left by previous scanf
    while (getchar() != '\n');
    
    printf("\nEnter a character: ");
    c = getchar();
    if(ISALPHA(c))
    {
        printf("\nYou entered an alphabet.");    
        
    }
    else{
        
        if(ISDIGIT(c))
        {
            printf("\nYou entered a digit.");
        }
        
    }
}