import java.util.Scanner;
interface Java_Array{
    void array_reverse();
    void array_copy();
    void array_max();
}

class ArrayOperation implements Java_Array{
    private int arr[];

    public ArrayOperation(int a[]){
        this.arr = a;
    }

    public void array_reverse(){
        int i,j,t=-1;

        i = 0;
        j = arr.length-1;
        while(i<j){
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;

            i++;
            j--;
        }
        System.out.println("\nReverse Array is: ");
        for(i=0;i<arr.length;i++){
            System.out.print(arr[i]+"\t");
        }
    }

    public void array_copy(){
        int i;
        int b[] = new int[arr.length];

        for(i=0;i<arr.length;i++){
            b[i] = arr[i];
        }
        System.out.println("\n\nCopied Array is: ");
        for(i=0;i<b.length;i++)
            System.out.print(b[i]+"\t");
        System.out.println();
    }

    public void array_max(){
        int i,max=0;
        for(i=0;i<arr.length;i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        System.out.println("\nMaximum array element is : "+max+"\n");
    }
}


class a1{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        Java_Array ja;

        System.out.print("\nEnter how many array elements: ");
        int n = sc.nextInt();

        int a[] = new int[n];
        System.out.println("\nEnter array elements one by one: ");
        for(int i=0;i<n;i++){
            a[i] = sc.nextInt();
        }

        ja = new ArrayOperation(a);
        ja.array_reverse();
        ja.array_copy();
        ja.array_max();
    }
}