#include <stdio.h>
#define MAX 10
struct Term
{
    int exp;
    int coef;
};

void getPolynomial(struct Term poly[], int size)
{
    printf("\n\nEnter %d size polynomial : ", size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d%d", &poly[i].coef, &poly[i].exp);
    }
}

void displayPolynomial(struct Term poly[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (poly[i].exp == 0)
        {
            printf("%d", poly[i].coef);
            break;
        }
        printf("%dx^%d", poly[i].coef, poly[i].exp);
        if (i < size - 1)
        {
            printf(" + ");
        }
    }
}

void multiplyPolynomial(struct Term poly1[], int size1, struct Term poly2[], int size2, struct Term mulitply[])
{
    int i, j, k = 0;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            mulitply[k].coef = poly1[i].coef * poly2[j].coef;
            mulitply[k++].exp = poly1[i].exp + poly2[j].exp;
        }
    }
}

void addPolynomial(struct Term multiply[], int size1, struct Term result[])
{
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        int coef = multiply[i].coef;
        int exp = multiply[i].exp;
        int found = 0;
        for (int j = 0; j < k; j++)
        {
            if (result[j].exp == exp)
            {
                result[j].coef += coef;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            result[k].coef = coef;
            result[k++].exp = exp;
        }
    }
}

int main()
{
    int size1, size2;
    struct Term poly1[MAX];
    struct Term poly2[MAX];

    // getting and display the first polynomial
    printf("\nEnter the size of poly 1 : ");
    scanf("%d", &size1);
    getPolynomial(poly1, size1);

    // getting and display the second polynomial
    printf("\nEnter the size of poly 2 : ");
    scanf("%d", &size2);
    getPolynomial(poly2, size2);

    // declaring multiply and result poly(add polynomial)
    struct Term multiply[size1 * size2];
    struct Term result[size1 + size2];

    // getting and display the multiple polynomial
    multiplyPolynomial(poly1, size1, poly2, size2, multiply);

    // addition of polynomial
    addPolynomial(multiply, (size1 * size2), result);

    // displaying first polynomial 
    printf("\n1st polynomial : ");
    displayPolynomial(poly1, size1);
    
    // displaying second polynomial 
    printf("\n2nd polynomial : ");
    displayPolynomial(poly2, size2);

    // display multiplication polynomial 
    printf("\nMultiplication of polynomial is : ");
    displayPolynomial(multiply, (size1 * size2));

    // displaying multiplication polynomial after mu
    printf("\nAddition of polynomial is : ");
    displayPolynomial(result, (size1 + size2));

    printf("\n");
    printf("\n");

    return 0;
}