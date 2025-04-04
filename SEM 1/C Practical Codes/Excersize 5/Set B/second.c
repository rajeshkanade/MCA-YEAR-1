#include<stdio.h>
int addMatrices(int a[3][3], int b[3][3]){
    int addMatrix[3][3];
    printf("\nAddition of Matrix is : \n");
    for(int i = 0 ; i < 3 ; i++){
        printf("|");
        for(int j = 0 ; j < 3 ; j++){
            addMatrix[i][j] = a[i][j] + b[i][j];
            printf(" %d |" , addMatrix[i][j]);
        }
        printf("\n----------------\n");
    }

    
}



int multiplyMatrix(int a[3][3], int b[3][3]){


    int multiMatrix[3][3];

      for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            multiMatrix[i][j] = 0;
        }
            
    }
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            for(int k = 0 ; k < 3 ; k++){

            multiMatrix[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("\nMultiply of matrix is : \n");
    for(int i = 0 ; i < 3 ; i++){
        printf("|");
        for(int j = 0 ; j < 3 ; j++){
            printf(" %d |",multiMatrix[i][j]);
        }
            printf("\n------------------\n");
    }
}
int main(){
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int b[3][3] = {{11,12,13},{14,15,16},{17,18,19}};

    addMatrices(a,b);
    multiplyMatrix(a,b);
    return 0;
}