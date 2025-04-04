#include<stdio.h>
#include<string.h>
int main(){
    char str[50], ch;
    printf("Enter the string : ");
    fgets(str,50,stdin);
    printf("Enter the character to remove from string : ");
    scanf("%c",&ch);
    for(int i = 0 ; i < strlen(str) - 1 ; i++){
        if(str[i] == ch){
            char temp = str[i];
            while(i < strlen(str) - 1){
                str[i] = str[i+1];
                i++;
            }
        }
    }

    printf("The String after character remove is : ");
    puts(str);
    return 0;
}