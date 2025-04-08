// Question:
// Write a C program to read a list of records containing names and ages from an input file,
// sort the records alphabetically by name using the Merge Sort algorithm, 
// and write the sorted records to an output file. 
// Ensure the program handles a maximum of 1000 records and includes error handling for file operations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_RECORDS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Record;

void merge(Record arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    Record *L = (Record *)malloc(n1 * sizeof(Record));
    Record *R = (Record *)malloc(n2 * sizeof(Record));

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (strcmp(L[i].name, R[j].name) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(Record arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {
    FILE *inputFile = fopen("./input.txt", "r");
    FILE *outputFile = fopen("./output.txt", "w");

    if (!inputFile || !outputFile) {
        perror("Error opening file");
        return 1;
    }

    Record records[MAX_RECORDS];
    int count = 0;

    while (fscanf(inputFile, "%s %d", records[count].name, &records[count].age) != EOF) {
        count++;
        if (count >= MAX_RECORDS) {
            fprintf(stderr, "Too many records in the file.\n");
            fclose(inputFile);
            fclose(outputFile);
            return 1;
        }
    }

    mergeSort(records, 0, count - 1);

    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%s %d\n", records[i].name, records[i].age);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Data sorted and written to output.txt successfully.\n");
    return 0;
}