#include<stdio.h>
#define MAX 10
typedef struct Term 
{
    int coef;
    int exp;
}Term;



void multiplyPolynomial(Term poly1[] , int size1 , Term poly2[] , int size2 , Term result[]){

    
    int k = 0;
    for(int i = 0 ; i < size1 ; i++){
        for(int j = 0 ; j < size2 ; j++){
            result[k].coef = poly1[i].coef * poly2[j].coef;
            result[k].exp = poly1[i].exp + poly2[j].exp;
            k++;
        }
        
    }
}

void displayPolynomial(Term poly[],int size){
    for(int i = 0 ; i < size ;i++){
        printf("%dx^%d",poly[i].coef,poly[i].exp);
    if(i < size - 1){
        printf(" + ");
    }
    }
}
int main(){


  struct Term poly1[] = {{3, 4}, {2, 3}, {5, 1},{7, 0}};

    struct Term poly2[] = {{1, 3}, {3, 2}, {2, 1}, {1, 0}};



  int size1 = sizeof(poly1) / sizeof(poly1[0]);
    int size2 = sizeof(poly2) / sizeof(poly2[0]);
 int resultSize ;

    // result polynomial declaration
    Term result[size1*size2];

    // printing first polynomial 
    printf("\n1st polynomial is : ");
    displayPolynomial(poly1,size1);

    // printing second polynomial 
    printf("\n2nd polynomial is : ");
    displayPolynomial(poly2,size2);

    // multiplying polynomial 
    multiplyPolynomial(poly1,size1,poly2,size2,result);

    // printing multiply polynomial 
    printf("\nResult Polynomial : ");
    displayPolynomial(result,(size1 * size2));
    printf("\n");


    return 0;
}