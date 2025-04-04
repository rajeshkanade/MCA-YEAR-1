#include<stdio.h>
int main(){
    int l ,b , h;
    printf("Accept length , breadth and height : ");
    scanf("%d%d%d",&l,&b,&h);
    float surface_area = 2 * ((l*b) + (b * h) + (h * l));
    float volume = l * b * h;
    printf("Surface area of cubiod is : %.2f\n",surface_area);
    printf("volume of cubiod is : %.2f\n",volume);
}