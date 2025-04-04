#include<stdio.h>
#include<string.h>
int main(){

    char str[10];
    printf("Enter the String : ");
    scanf("%s",str);
    int start = 0 , end = strlen(str) - 1 , flag = 0;
    while(start != end){
        if(str[start] == str[end]){
        start++ ;
        end --;
        }else{
            flag = 1;
            break;
        }

    }
    if(flag){
        printf("\n %s string is not pallendrome\n",str);
    }else{
        printf("\n %s string is pallendrome\n",str);
    }
    return 0;
}