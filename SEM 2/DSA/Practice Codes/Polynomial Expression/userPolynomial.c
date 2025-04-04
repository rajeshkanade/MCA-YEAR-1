#include <stdio.h>
#define MAX_SIZE 10
struct Term
{
    int coef;
    int exp;
};

void getPolynomials(struct Term poly1[], int size1 , struct Term poly2[] , int size2){

    printf("Enter the 1st polynomial : ");
        for(int i = 0 ; i < size1 ; i ++){
        scanf("%d%d",&poly1[i].coef, &poly1[i].exp);
    }

    printf("Enter the 2nd polynomial : ");
   for(int i = 0 ; i < size2 ; i ++){
        scanf("%d%d",&poly2[i].coef , &poly2[i].exp);
    }
}

void addPolynomials(struct Term poly1[] , int size1 , struct Term poly2[] , int size2 , struct Term result[]){

    int i = 0 , j = 0 , k = 0;

    while(i < size1 && j < size2){
        if(poly1[i].exp > poly2[j].exp){
            result[k++] = poly1[i++];
        }else if(poly2[j].exp > poly1[i].exp){
            result[k++] = poly2[j++];
        }else{

            // adding coefficint of term with same components  
            result[k].exp = poly1[i].exp;
            result[k++].coef = poly1[i++].coef + poly2[j++].coef;
        }
    }

    while(i < size1){
        result[k++] = poly1[i++];
    }
    while(j < size2){
        result[k++] = poly1[j++];
    }
}

void displayPolynomial(struct Term poly[], int size){
    int i = 0 ; 
    for(int i = 0 ; i < size ; i++){
        printf("%dx^%d", poly[i].coef,poly[i].exp);
        if(poly[i].exp == 0){
            break;
        }
        if(i < size - 1){
            printf(" + ");
        }
    }
}
int main()
{

    struct Term poly1[MAX_SIZE] ;

    struct Term poly2[MAX_SIZE] ;
    int size1,size2;
    printf("Enter the size of 1st polynomial : ");
    scanf("%d",&size1);
    printf("Enter the size of 2nd polynomial : ");
    scanf("%d",&size2);
    
    getPolynomials(poly1,size1,poly2,size2);

    struct Term result[size1 + size2];

    // perform polynomail operation addition :
    addPolynomials(poly1, size1, poly2, size2, result);

    // Displaying polynomial 1 :
    printf("\npolynomial 1 : ");
    displayPolynomial(poly1, size1);

    // Displaying polynomial 2 :

    printf("\npolynomial 2 : ");
    displayPolynomial(poly2, size2);

    // Displaying Result polynomial :

    printf("\nResult Polynomial :");
    displayPolynomial(result, (size1 + size2));
    return 0;
}