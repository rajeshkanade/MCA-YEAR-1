#include <stdio.h>
#define MAX 10

struct Term
{
    int exp;
    int coef;
};

void createPoly(struct Term poly1[], int size)
{
    printf("\nEnter %d size polynomial : ", size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d%d", &poly1[i].coef, &poly1[i].exp);
    }
}

void additionPolynomial(struct Term poly1[], int size1, struct Term poly2[], int size2, struct Term result[])
{
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (poly1[i].exp > poly2[j].exp)
        {
           result[k++] = poly1[i++];
        }
        else if (poly2[j].exp > poly1[i].exp)
        {
           result[k++] = poly2[j++];
        }
        else
        {
            result[k].exp = poly1[i].exp;
            result[k++].coef = poly1[i++].coef + poly2[j++].coef;
        }
    }

    while (i < size1)
    {
                   result[k++] = poly1[i++];

    }

    while (j < size2)
    {
       result[k++] = poly2[j++];
    }
    // *size3 = k;
}

void displayPolynomial(struct Term poly[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if(poly[i].exp == 0){
            printf("%d",poly[i].coef);
            break;
        }
            printf("%dx^%d", poly[i].coef, poly[i].exp);
        if (i < size - 1)
        {
            printf(" + ");
        }

    }
    printf("\n");
}

int main()
{
    struct Term poly1[10];
    struct Term poly2[10];

    int size1, size2;

    printf("\nEnter the size of poly 1 : ");
    scanf("%d", &size1);
    createPoly(poly1, size1);

    printf("\nEnter the size of poly 2 : ");
    scanf("%d", &size2);
    createPoly(poly2, size2);
    struct Term result[size1+size2];

    printf("\nPrinting poly 1 : ");
    displayPolynomial(poly1, size1);
    printf("\nPrinting poly 2 : ");
    displayPolynomial(poly2, size2);

    additionPolynomial(poly1, size1, poly2, size2, result);

    
    printf("\nPrinting poly 3 : ");
    displayPolynomial(result, (size1+size2));

    return 0;
}