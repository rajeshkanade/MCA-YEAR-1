#include<stdio.h>
#include<stdlib.h>
// Structure Array 
    typedef struct point{
        int x;
        int y;
    }point;

    
int main(){

    int num[5];
    int num1[5] = {1,2};
    // for(int i = 0 ; i < 10; i++){
    //     printf("%d\n",num[i]);
    // }

    // Dynamic Array Declaration 

    int *arr = (int*)malloc(5*sizeof(int));
    //  for(int i = 0 ; i < 5; i++){
    //     printf("%d\n",arr[i]);
    // }
    // printf("\nCalloc : ");
    int *arr2 = (int*)calloc(5,sizeof(int));
    // for(int i = 0 ; i < 5 ; i++){
    //     printf("%d\n",arr2[i]);
    // }


    // Character Array : String 

    
    char str[] = "Hello World !";
    // printf("%s",str);


    // printf("\nUsing for Loop : ");
    // for(int i = 0 ;str[i]!= '\0' ; i++){
    //     printf("%c",str[i]);
    // }

    // Pointer array
    int *ptr[5] ;
    int b[3] = {1,2,3};
   for(int i = 0 ; i < 3 ; i++){
        ptr[i] = &b[i];
    }

    // for(int i = 0 ; i < 3 ; i++){
    //     printf("%u\n", ptr[i]);
    // }

    point p[3];

    for(int i = 0 ; i < 3 ; i++){
    printf("Enter the value of %d array of x and y : ",i+1);
    scanf("%d%d",&p[i].x,&p[i].y);

    }
    for(int i = 0 ; i < 3 ; i++){
    printf("Enter the value of %d array of x and y : \n",i+1);
    printf("x : %d y : %d\n",p[i].x,p[i].y);

    }



    return 0;
}