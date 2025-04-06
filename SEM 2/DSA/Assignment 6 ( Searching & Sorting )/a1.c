/**
 * Question: Write a C program to read employee data (name, age, salary) from a file, 
 * sort the employees by their age using insertion sort, and display the sorted data.
 */

/**
 * @file a1.c
 * @brief This program reads employee data from a file, sorts the employees by age using 
 *        insertion sort, and displays the sorted data.
 * 
 * @details
 * The program performs the following steps:
 * 1. Reads employee data (name, age, salary) from a file named "employee.txt".
 * 2. Stores the data in an array of Employee structures.
 * 3. Sorts the array of employees by age using the insertion sort algorithm.
 * 4. Displays the sorted employee data in a tabular format.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float salary;
} Employee;

void insertionSort(Employee employees[], int n) {
    int i , j;
    for (i = 1; i < n; i++) {
        Employee key = employees[i];
        for (j = i - 1; j >= 0 && employees[j].age > key.age; j--) {
            employees[j + 1] = employees[j];
            employees[j] = key;
        }
        employees[j + 1] = key;
    }
}

int main() {
    FILE *file = fopen("employee.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file employee.txt\n");
        return 1;
    }

    Employee employees[MAX_EMPLOYEES];
    int count = 0;

    while (fscanf(file, "%s %d %f", employees[count].name, &employees[count].age, &employees[count].salary) == 3) {
        count++;
        if (count >= MAX_EMPLOYEES) {
            printf("Error: Maximum employee limit reached\n");
            break;
        }
    }
    fclose(file);

    insertionSort(employees, count);

    printf("Sorted Employee Data (by Age):\n");
    printf("Name\tAge\tSalary\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    return 0;
}