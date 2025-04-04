#include <stdio.h>
#include<stdlib.h>
void printArr(int arr[], int n){
  printf("Sorted array element are :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void getArr(int arr[],int n){
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
}
void bubbleSort(int arr[] , int n)
{
    int  cmpcnt = 0, swapcnt = 0 , flag;
    for (int i = 1; i < n ; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i ; j++)
        {
            cmpcnt++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapcnt++;
                flag = 1;
            }
           
        }
        // if data is given sorted then we have to break outer for to impove time compelxity;
        if(flag == 0){
            break;
        }
    }

    printArr(arr,n);
    printf("\n Comaparison count : %d", cmpcnt);
    printf("\n Swapped count : %d\n", swapcnt);
}
int main()
{
    int n ;
    printf("Enter the number of Element : ");
    scanf("%d",&n);
    int* arr = malloc(n*sizeof(int));
    getArr(arr,n);
    bubbleSort(arr,n);
}