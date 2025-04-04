#include<stdio.h>
#include<string.h>
int main(){
    char str[10];
    printf("Enter the String : ");
    scanf("%s",str);

    int flag = 0;
    int length = strlen(str);
    for(int i = 0 ; i < (length / 2 ) ; i++){
        if(str[i] == str[length - i - 1]){
            flag = 0;
        }else{
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("%s string is not pallendrome...",str);
    }else{
        printf("%s string is pallendrome...",str);
    }

    return 0;
}