#include<stdio.h>
int main(){
    int n;
    printf("Enter the value of an n : ");
    scanf("%d",&n);
    int flag = 0;
    int arr[n];

    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }

    for(int i = 0; i < n ; i++){
        for(int j = 2 ; j < arr[i] ; j++){
            if(arr[i] % j != 0 ){
                flag = 0;
                
            }
            else{
                flag = 1;
                break;
            }
        }
        if(flag == 0 && arr[i] != 1){
        printf("%d ",arr[i]);
        }

    }

    
}