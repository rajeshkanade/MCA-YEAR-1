#include<stdio.h>
#include<ctype.h>
int checkCharacter(char ch){
    
    if(isdigit(ch)){
        return 2;
    }
    else if(isalpha(ch)){
        return 1;
    }
    else if(isspace(ch)){
        return 4;
    }
    else{
        return 3;
    }
}

int main(){

    char ch ;
    int choice,alphaCount = 0 , numCount = 0 , symCount = 0,spaceCount = 0;
    printf("Enter the character and Press CTRL + D to Exit : ");
    while((ch = getchar()) != EOF){
        choice = checkCharacter(ch);
        switch(choice){
            case 1 : 
                alphaCount++;
                break;
            case 2 : 
                numCount++;
                break;
            case 3 : 
                symCount++;
                break;
            case 4 : 
                spaceCount++;
        }
    }

    printf("Alphabet are : %d \n",alphaCount);
    printf("Number are   : %d \n",numCount);
    printf("Symbols are  : %d \n",symCount);
    printf("Space are    : %d \n",spaceCount);
    return 0;
}