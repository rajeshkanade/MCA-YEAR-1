#include<stdio.h>
#include<string.h>
int main(){
    char str[50], ch;
    char resultStr[50];
    printf("Enter the string : ");
    fgets(str,50,stdin);
    printf("Enter the character to remove from string : ");
    scanf("%c",&ch);
    for(int i = 0 ; i < strlen(str) - 1 ; i++){
        if(str[i] != ch){
            resultStr[i] = str[i] ;
        }else{
        }
    }

    printf("The String after character remove is : ");
    puts(resultStr);
    return 0;
}