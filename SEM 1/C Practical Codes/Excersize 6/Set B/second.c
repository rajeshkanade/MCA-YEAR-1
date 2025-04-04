
// Accept the number of rows (m) and comumns (n) for a matrix and dynamically allocate memory for the matrix. Accept and display the matrix using pointers.
// Hint : Use an array of pointers. 
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int row , col ;
    printf("Enter number of rows : ");
    scanf("%d",&row);
    printf("Enter number of columns : ");
    scanf("%d",&col);
    int **arr  = (int**) malloc( row * sizeof(int));
    for(int i = 0 ; i < row ; i++){
        *(arr+i) = (int*) malloc(col * sizeof(int));
    }
    printf("Enter the %d x %d array element : ",row , col);
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            scanf("%d",*(arr+i)+j);
        }
    }
    printf("Your  %d x %d array element are : \n",row , col);
    for(int i = 0 ; i < row ; i++){
        printf("|");
        for(int j = 0 ; j < col ; j++){
            printf(" %d |",**(arr+i)+j);
        }
        printf("\n-------------\n");
    }
    return 0;
}