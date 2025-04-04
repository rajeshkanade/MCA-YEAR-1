// Write a program to accept a decimal number and convert it to binary, octal and hexadecimal. Write the separate functions. 

#include<stdio.h>
void convertToBinary(int n){
    int arr[10];
    int cnt = 0;
    printf("\n Binary Number for %d is : ", n);
    while(n > 0){
        arr[cnt] = n % 2 ;
        n = n/2;
        cnt++;
    }
    for(int i = cnt-1 ; i >= 0 ; i--){
        printf("%d ", arr[i]);
    }
}
void convertTOOctal(int n){
    int arr[10];
    int cnt = 0; 
    while(n > 0){
        arr[cnt] = n % 8;
        n = n / 8;
        cnt++;
    }
    printf("\n Octal Number for %d is : ",n);
    for(int i = cnt - 1 ; i >= 0 ; i--){
        printf("%d",arr[i]);
    }
}
void convertToHexadecimal(int n){
    int arr[10];
    int cnt = 0; 
    printf("\n Hexadecimal for %d is : ",n);
    while(n > 0){
        arr[cnt] = n % 16;
        n = n / 16;
        cnt++;
    }
    for(int i = cnt - 1 ; i >= 0 ; i--){
        switch(arr[i]){
            case 10 : printf("A");
            break;
            case 11 : printf("B");
            break;
            case 12 : printf("C");
            break;
            case 13 : printf("D");
            break;
            case 14 : printf("E");
            break;
            case 15 : printf("F");
            break;
            default : 
                printf("%d",arr[i]);
            break;
        }
    }
}
int main(){
    int n ;
    printf("Enter the decimal Number : ");
    scanf("%d",&n);

    convertToBinary(n);
    convertTOOctal(n);
    convertToHexadecimal(n);
    return 0;

}