#include<stdio.h>
int caluculate_GCD(int x , int y){
    int gcdNo = 1 ;
    if(x < y ){
        for(int i = x ; i >= 1 ; i--){
            if(x % i == 0 && y % i == 0){
               gcdNo = i ; 
               break;
            }
        }
    }else if ( y < x ){
        for(int i = y ; i >= 1 ; i--){
            if((x % i == 0) && (y % i == 0)){
                gcdNo = i;
                break;
            }
        }
    }
    return gcdNo;
}

int main(){
    int n1 , n2 ;
    printf("Enter the two numbers : ");
    scanf("%d%d",&n1,&n2);

    int result = caluculate_GCD(n1,n2);
    printf("GCD is : %d",result);
}



