#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c,descriminant,root1,root2;
    printf("Enter the values of a b and c : ");
    scanf("%f%f%f",&a,&b,&c);


    descriminant  = b * b - 4 * (a * c);

    if(descriminant > 0){
        root1 = ( -b + sqrt(descriminant / (2 * a)));
        root2 = (-b - sqrt(descriminant / (2 * a)));
        printf("The real root of equation is : %f and %f\n",root1,root2);

    }
    else if(descriminant == 0){
        root1 = root2 = -b/(2*a);
        printf("Roots are eqaul : %f and %f\n",root1,root2);
    }
    else{
        printf("Roots are Imaginary !!!\n");
    }

    return 0;

}