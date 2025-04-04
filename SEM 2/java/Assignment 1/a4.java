import java.util.Scanner;
class Matrix{
    int sum = 0;
    void getElements(int arr[][] , int rows , int cols){
                Scanner sc = new Scanner(System.in);
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                arr[i][j] = sc.nextInt();
            }

        }
    }
    int[][] addition(int a[][],int b[][]){
        int rows , cols;
        rows = cols = a.length;
        int[][] sum = new int[rows][cols];
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols; j++){
                sum[i][j] = a[i][j] + b[i][j];
            }
        }
        return sum;
     }
}


public class a4{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int rows ,cols ;

        System.out.println("Enter the no of rows and cols : ");
        rows = sc.nextInt();
        cols = sc.nextInt();
        int arr1[][] = new int[rows][cols];
        int arr2[][] = new int[rows][cols];
        int sum[][] = new int[rows][cols];

        Matrix m = new Matrix();

        System.out.println("Enter the " + rows + " * " + cols +" Elements for 1 matrix  : ");
        m.getElements(arr1,rows,cols);

        System.out.println("Enter the " + rows + " * " + cols +" Elements for 2 matrix  : ");
        m.getElements(arr2,rows,cols);

        sum = m.addition(arr1,arr2);
        System.out.println("Sum of the matrix is : ");
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                System.out.print(sum[i][j] +" ");
            }
            System.out.println("");
        }

    }
}