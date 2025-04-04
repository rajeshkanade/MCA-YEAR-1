#include <stdio.h>
struct SparseMatrix
{
    int row;
    int col;
    int value;
};

void inputMatrix(int mat[10][10], int m, int n, struct SparseMatrix sparse[10])
{
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] != 0)
            {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = mat[i][j];
                k++;
            }
        }
    }
}

// void convertToSparse(int mat[10][10], int m, int n, struct SparseMatrix sparse[10])
// {
//     int k = 0;
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (mat[i][j] != 0)
//             {
//                 sparse[k].row = i;
//                 sparse[k].col = j;
//                 sparse[k].value = mat[i][j];
//                 k++;
//             }
//         }
//     }
// }

void displaySparseMatrix(struct SparseMatrix sparse[10], int n)
{
    printf("\nRow | col | value");
    printf("\n---------------------------");
    for (int i = 0; i < n; i++)
    {
        printf("\n %d  |  %d  |  %d  ", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}
int main()
{
    int n, m;
    printf("\nEnter the dimension of the Matrix (rows x columns) : ");
    scanf("%d%d", &m, &n);
    int mat[10][10];
    struct SparseMatrix sparse[10];
    int nonZeroCount = 0;

    printf("\nEnter matrix elements : %d * %d : \n", m, n);
    inputMatrix(mat, m, n, sparse);

    // Converting the matrix to sparse matrix representation
    // convertToSparse(mat, m, n, sparse);

    // count number of non-zero elements
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)

            if (mat[i][j] != 0)
            {
                nonZeroCount++;
            }
    }
    // Display the sparse matrix
    displaySparseMatrix(sparse, nonZeroCount);
    printf("\n");

    return 0;
}