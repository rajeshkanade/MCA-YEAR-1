#include <stdio.h>
#include <stdlib.h>

typedef struct Fraction {
    int numerator;
    int denominator;
}f;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void reduceFraction(f *frac) {
    int divisor = gcd(frac->numerator, frac->denominator);
    frac->numerator /= divisor;
    frac->denominator /= divisor;
    
    if (frac->denominator < 0) {
        frac->numerator = -frac->numerator;
        frac->denominator = -frac->denominator;
    }
}

float fractionValue(f *frac) {
    return (float)frac->numerator / frac->denominator;
}

void accept(f *fractions, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter numerator and denominator for fraction %d: ", i + 1);
        scanf("%d%d", &fractions[i].numerator, &fractions[i].denominator);
        
        // Validate the denominator
        while (fractions[i].denominator == 0) {
            printf("Denominator cannot be zero. Enter again: ");
            scanf("%d", &fractions[i].denominator);
        }

        // Reduce the fraction to its lowest terms
        reduceFraction(&fractions[i]);
    }
}

void displayAll(f *fractions, int n) {
    printf("\nAll fractions:\n");
    for (int i = 0; i < n; i++) {
        printf("%d/%d\n", fractions[i].numerator, fractions[i].denominator);
    }
}

// Function to display the largest fraction
void LargestFraction(f *fractions, int n) {
    int largest = 0;
    for (int i = 1; i < n; i++) {
        if (fractionValue(&fractions[i]) > fractionValue(&fractions[largest])) {
            largest = i;
        }
    }
    printf("\nLargest fraction: %d/%d\n", fractions[largest].numerator, fractions[largest].denominator);
}

void SmallestFraction(f *fractions, int n) {
    int smallest = 0;
    for (int i = 1; i < n; i++) {
        if (fractionValue(&fractions[i]) < fractionValue(&fractions[smallest])) {
            smallest = i;
        }
    }
    printf("\nSmallest fraction: %d/%d\n", fractions[smallest].numerator, fractions[smallest].denominator);
}

void sort(f *fractions, int n) {
    f temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (fractionValue(&fractions[i]) > fractionValue(&fractions[j])) {
                // Swap fractions
                temp = fractions[i];
                fractions[i] = fractions[j];
                fractions[j] = temp;
            }
        }
    }
    printf("\nFractions sorted in ascending order based on value:\n");
    displayAll(fractions, n);
}

int main() {
    int n, ch;
    f *fractions;

    printf("Enter the number of fractions: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n fractions
    fractions = (f *)malloc(n * sizeof(f));
    if (fractions == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Accept fraction details
    accept(fractions, n);

    do {
        printf("\nMenu:\n");
        printf("1. Display Largest Fraction\n");
        printf("2. Display Smallest Fraction\n");
        printf("3. Sort Fractions\n");
        printf("4. Display All Fractions\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                LargestFraction(fractions, n);
                break;

            case 2:
                SmallestFraction(fractions, n);
                break;

            case 3:
                sort(fractions, n);
                break;

            case 4:
                displayAll(fractions, n);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 5);

    return 0;
}

