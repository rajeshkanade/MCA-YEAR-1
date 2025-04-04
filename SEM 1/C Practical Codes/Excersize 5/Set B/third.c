#include <stdio.h>
void checkSymmetric(int arr[2][2])
{

    int transposeArr[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            transposeArr[i][j] = arr[j][i];
        }
    }
    int flag = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (arr[i][j] != transposeArr[i][j])
            {
                flag = 1;
            }
        }
    }
    if (flag)
    {
        printf("\n Answer : Matrix is not Symmetric ..\n");
    }
    else
    {
        printf("\n Answer : Matrix is Symmetric ..\n");
    }
}

void findTrace(int arr[2][2]){
    int sum = 0;
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            if(i == j){
                sum += arr[i][j];
            }
        }
    }
    printf("\n\nTrace of Matrix is : %d",sum);
}

void checkUpper(int arr[2][2]){
   if(arr[0][1] == 0){
    printf("Matrix is Upper Triangular Matrix ...");
   }else{
    printf("Matrix is Not Upper Triangular Matrix ...");

   }
}
void checkLower(int arr[2][2]){
      if(arr[1][0] == 0){
    printf("Matrix is Lower Triangular Matrix ...");
   }else{
    printf("Matrix is Not Lower Triangular Matrix ...");

   }
}

void checkIdentity(int arr[2][2]){
    int flag1 = 0 , flag2 = 0;
    for(int i = 0 ; i < 2 ; i ++){
        for(int j = 0 ; j < 2 ; j ++){
            if(i == j && arr[i][j] == 1){
                flag1 = 1;
            }else if(i != j && arr[i][j] == 0){
                flag2 = 1;
            }
        }
    }
    if(flag1 == 1 && flag2 == 1){
        printf("Matrix is Identity matrix ...");
    }else{
        printf("Matrix is not Identity Matrix ...");
    }
}

int main()
{
    int arr[2][2];
    int ch;
    printf("Enter 2x2 matrix element : ");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    do
    {
        printf("\n0.To terminate.");
        printf("\n1.Check matrix is Symmetric.");
        printf("\n2.Display the trace of matrix.");
        printf("\n3.Check matrix is Upper triangular matrix.");
        printf("\n4.Check matrix is Lower triangular matrix.");
        printf("\n5.Check matrix is Identity matrix.");
        printf("\n\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            checkSymmetric(arr);
            break;
        case 2 : 
            findTrace(arr);
            break;
        case 3 : 
            checkUpper(arr);
            break;
        case 4 : 
            checkLower(arr);
            break;
        case 5: 
            checkIdentity(arr);
            break;
        default:
            break;
        }

    } while (ch != 0);
    return 0;
}