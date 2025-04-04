#include<stdio.h>
int main()
{
    int arr[3][3] = {{7,1,9},{122,2,11},{4,5,6}};
     printf("Unsorted Row and Columns are : \n");
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(arr[i][j] > arr[i][j+1] && (j+1) < 3){
                int temp = arr[i][j];
                arr[i][j] = arr[i][j+1];
                arr[i][j+1] = temp;
            }
            if(arr[i][j] <  arr[i+1][j] && (i + 1) < 3){
                  int temp = arr[i+1][j];
                arr[i+1][j] = arr[i][j];
                arr[i][j] = temp;
            }
        }
    }
    printf("Sorted Row and Columns are : \n");
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}