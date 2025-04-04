#include<stdio.h>
int main(){
    char a;
    printf("Enter the Character : ");
    scanf("%c",&a);

    if(a >= 48 && a<=58){
        printf(" Entered character %c is an %d\n",a,a);
    }
    else if(a >= 65 && a<=122){
        printf("Enter character is an alphabet \n");
        if(a >= 65 && a<=90){
            printf("Entered character is an Uppercase Alphabet : %c\n",a);
        }else{
            printf("Entered character is an Lowercase Alphabet : %c\n",a);
        }
    }
    // else if((a >= 33 && a<=47) || (a >=58 && a<=64) || (a >=91 && a <= 96) || (a >= 123 && a <= 126)){
    // }
    else{
        printf("Entered character is an Symbol : %c\n",a);

    }
    return 0 ;
}