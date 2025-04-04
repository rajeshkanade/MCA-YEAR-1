#include<stdio.h>
#include<math.h>
int isWhiteSpace(char ch){
    if(ch ==  ' '){
        return 1;

    }
    return 0;
}
int main(){

    char ch;
    int count = 0;
    printf("enter character : ");
    while((ch=getchar()) != 'Z'){
        if(isWhiteSpace(ch)){
            count++;
        }
    }
    printf("\ncount is : %d\n",count);
    
    return 0;
}
