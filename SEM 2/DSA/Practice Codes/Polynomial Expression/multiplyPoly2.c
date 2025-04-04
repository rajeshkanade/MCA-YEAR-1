#include <stdio.h>
#define MAX 10
typedef struct Term
{
    int coef;
    int exp;
} Term;

void getPolynomials(Term poly[], int size)
{

    for (int i = 0; i < size; i++)
    {
        scanf("%d%d", &poly[i].coef, &poly[i].exp);
    }
}

void displayPolynomial(Term poly[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%dx^%d", poly[i].coef, poly[i].exp);
        if (i < size - 1)
        {
            printf(" + ");
        }
    }
}

void multiplyPolynomial(Term poly1[], int size1, Term poly2[], int size2, Term result[], int *l)
{

    int multSize = size1 * size2;

    Term multiplyPoly[multSize];
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            multiplyPoly[k].coef = poly1[i].coef * poly2[j].coef;
            multiplyPoly[k].exp = poly1[i].exp + poly2[j].exp;
            // result[k].coef = poly1[i].coef * poly2[j].coef;
            // result[k].exp = poly1[i].exp + poly2[j].exp;
            k++;
        }
    }

    printf("\n Multiplication of polynomial is : ");
    displayPolynomial(multiplyPoly, multSize);
    // int l = 0;
    for (int i = 0; i < multSize; i++)
    {
        // printf("\n%dx^%d", multiplyPoly[i].coef, multiplyPoly[i].exp);

        for (int j = i + 1; j < multSize; j++)
        {
        // printf("\n%dx^%d", multiplyPoly[j].coef, multiplyPoly[j].exp);
            result[*l].coef = multiplyPoly[i].coef;
            result[*l].exp = multiplyPoly[i].exp;

            if (multiplyPoly[i].exp == multiplyPoly[j].exp)
            {
                printf("\nI am here ...");
                result[*l].coef += multiplyPoly[j].coef;
                result[*l].exp = multiplyPoly[i].exp;
            }
        }
        *l++;
    }
}

int main()
{

    // Term poly1[MAX];
    // Term poly2[MAX];
    // int size1;
    // int size2;

    struct Term poly1[] = {{3, 4}, {2, 3}, {5, 1}, {7, 0}};

    struct Term poly2[] = {{1, 3}, {3, 2}, {2, 1}, {1, 0}};

    // getting first polynomial
    // printf("\nEnter the size of Poly 1 : ");
    // scanf("%d",&size1);
    // printf("\nEnter 1st polynomial : ");
    // getPolynomials(poly1,size1);

    int size1 = sizeof(poly1) / sizeof(poly1[0]);
    int size2 = sizeof(poly2) / sizeof(poly2[0]);
    // getting second polynomial
    // printf("\nEnter the size of poly 2 : ");
    // scanf("%d",&size2);
    // printf("\nEnter 1st polynomial : ");
    // getPolynomials(poly2,size2);

    // result polynomial declaration
    Term result[size1 + size2];
    int resultSize = 0;

    // printing first polynomial
    printf("\n1st polynomial is : ");
    displayPolynomial(poly1, size1);

    // printing second polynomial
    printf("\n2nd polynomial is : ");
    displayPolynomial(poly2, size2);

    // multiplying polynomial
    multiplyPolynomial(poly1, size1, poly2, size2, result, &resultSize);

    // printing multiply polynomial
    printf("\nResult Polynomial : ");

    displayPolynomial(result, resultSize);
    printf("\n");

    return 0;
}