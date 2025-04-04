#include<stdio.h>
int main(){
    int a = 10, b = 20;
    printf("values of a and b before interchange is \n a = %d , b = %d\n",a , b);
    int temp = a;
    a = b;
    b = temp;
    printf("values of a and b after interchange is \n a = %d , b = %d\n", a , b);

}