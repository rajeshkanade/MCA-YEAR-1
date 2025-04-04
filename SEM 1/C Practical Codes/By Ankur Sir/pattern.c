#include<stdio.h>
int main(){
    printf("\n\n");
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 - i ; j++){
            printf(" ");
           
        }
         for(int k = i ; k <= i ; k++){
                printf("*");
            }
        for(int j = 0 ; j < i - 1; j++){
            printf(" ");
           
        }
        for(int j = 0 ; j < i  ; j++){
            printf(" ");
           
        }
        if(i == 0){
            printf("\n");
        }
        else{

        for(int k = i ; k <  i + 1 ; k++){
        
                printf("*");
        
            }
        printf("\n");
        }

        
    }
    for(int i = 1 ; i <= 4 ; i++){
            for(int j = 1; j < i + 1 ; j++){
                printf(" ");
            }
            printf("*");
            for(int k = 0 ; k < (7 - i * 2) ; k++ ){
                printf(" ");
            }
            if(i==4){
                printf("\n");
            }
            else{
            printf("*");
            }
            printf("\n");
        }

          printf("\n\n");
}