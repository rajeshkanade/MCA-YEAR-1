#include<stdio.h>
int main(){
    int side , l , b , h;
    printf("\n1. Area of Square ");
    printf("\n2. Area of Rectangle ");
    printf("\n3. Area of Triangle ");
    printf("\nEnter You choice : ");
    int choice;
    scanf("%d",&choice);
    

    switch(choice){
        case 1 : 
            printf("Enter the size length of square : ");
            scanf("%d",&side);
            printf("Area of Square : %d \n",(side * side));
            break;
        case 2 : 
            printf("Enter the length and breadth of Rectangle : ");
            scanf("%d%d",&l,&b);
            printf("Area of Rectangle : %d \n", (l * b));
            break;
        case 3 : 
            printf("Enter the height and base of Triangle : ");
            scanf("%d%d",&b,&h);
            float area = (b * h)/2;
            printf("Area of Triangle : %f \n",area);
            break;
        default : 
            printf("Enter the valid Choice !!!!!");
            break;
    }
    return 0;
}