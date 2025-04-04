// Write the menu driven program to perform the following operations on a charater type variable. 
// kcheck if it an alphabet.
// check if it is a digit. 
// check if it is lowercase. 
// check if it is uppercase.
// converts it into lowercase.
// converts it into uppercase.

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
    char c;
    int ch ;
    int acii;
    printf("\n\nEnter the value of c : ");
    scanf("%c",&c);
    do{
    printf("\n1.Check if it is alphabet");
    printf("\n2.Check if it is digit");
    printf("\n3.Check if it is lowercase");
    printf("\n4.Check if it is uppercase");
    printf("\n5.convert to uppercase");
    printf("\n6.convert to lowercase");

        printf("\n\nEnter you choice :");
    scanf("%d",&ch);
    switch(ch){
        case 2 :    if(isdigit(c)){
                     printf("%c  is an digit >>>\n",c);
                    }else{
                        printf("%c is not a digit",c);
                    }   
                    break;
        case 1 : 
                ((isalpha(c)) ? printf("%c is character ", c) : printf("%c is not a character",c));
                break;
        case 3 : if(islower(c)){

                    printf("%c is lowercase character \n",c);
                }else{
                    printf("%c is not a lowercase character");
                }
                break;
        case 4 : if(isupper(c)){

                    printf("%c is uppercase character \n",c);
                }else{
                    printf("%c is not a uppercase character");
                }
                break;
        case 5 : if(c >= 97 && c <=122){
         acii = c;
            acii = acii - 32;
            printf("%c is converted to uppercase %c \n",c,acii);
            break;
        }else{
            printf("%c is not a lowercase character\n",c);
        }
        case 6 : 
        if(c >=65 && c<=90){
            acii = c;
            acii = acii + 32;
            printf("%c is converted to lowercase %c \n",c,acii);break;

        }else{
            printf("%c is not a uppercase character\n",c);
        }
        default : 
            printf("Enter the valid choice \n");
    }    
    }while(ch != 0);
}