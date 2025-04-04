#include<stdio.h>
// #define pi 3.14;
int main(){
    int r , h;
    const float pi = 3.14;
    printf("\n Enter the radius and the height of the Cylinder : ");
    scanf("%d %d", &r , &h);

    float surface_area = pi *  ( r * r);
    float volume = pi * ( r * r )* h;

    printf("Surface area of cylinder is : %f \n " , surface_area);
    printf("Volume of cylinder is : %f \n " , volume);

    return 0;
}