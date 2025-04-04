#include <stdio.h>
#define MAX 10

typedef struct Term {
    int coef;
    int exp;
} Term;

void multiplyPolynomial(Term poly1[], int size1, Term poly2[], int size2, Term result[], int *resultSize) {
    Term temp[MAX * MAX];
    int k = 0;

    // Multiply the polynomials
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            temp[k].coef = poly1[i].coef * poly2[j].coef;
            temp[k].exp = poly1[i].exp + poly2[j].exp;
            k++;
        }
    }

    // Combine like terms
    *resultSize = 0;
    for (int i = 0; i < k; i++) {
        int found = 0;
        for (int j = 0; j < *resultSize; j++) {
            if (result[j].exp == temp[i].exp) {
                result[j].coef += temp[i].coef;
                found = 1;
                break;
            }
        }
        if (!found) {
            result[*resultSize] = temp[i];
            (*resultSize)++;
        }
    }
}

void displayPolynomial(Term poly[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%dx^%d", poly[i].coef, poly[i].exp);
        if (i < size - 1) {
            printf(" + ");
        }
    }
}

int main() {
    Term poly1[MAX], poly2[MAX], result[MAX * MAX];
    int size1, size2, resultSize;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &size1);
    printf("Enter the terms (coefficient and exponent):\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d%d", &poly1[i].coef, &poly1[i].exp);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &size2);
    printf("Enter the terms (coefficient and exponent):\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d%d", &poly2[i].coef, &poly2[i].exp);
    }

    multiplyPolynomial(poly1, size1, poly2, size2, result, &resultSize);
    printf("Result Polynomial: ");
    displayPolynomial(result, resultSize);
    printf("\n");

    return 0;
}
