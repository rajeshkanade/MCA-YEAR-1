#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define N 100

typedef struct Employee {
    int id;
    char name[50];
    float salary;
}emp;

void accept(emp employees[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }
}

void searchByName(emp employees[], int n, char name[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            printf("Employee found:\n");
            printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
            return;
        }
    }
    printf("Employee with name %s not found.\n", name);
}

void searchById(emp employees[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (employees[i].id == id) {
            printf("Employee found:\n");
            printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void displayAll(emp employees[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

void AboveSalary(emp employees[], int n, float salary) {
    printf("Employees with salary greater than %.2f:\n", salary);
    for (int i = 0; i < n; i++) {
        if (employees[i].salary > salary) {
            printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
        }
    }
}

void MaxSalary(emp employees[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (employees[i].salary > employees[max].salary) {
            max = i;
        }
    }
    printf("Employee with the highest salary:\n");
    printf("ID: %d, Name: %s, Salary: %.2f\n", employees[max].id, employees[max].name, employees[max].salary);
}

int main() {
    emp employees[N];
    int n, ch, id;
    char name[50];
    float salary;

    // Accept number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Accept employee details
    accept(employees, n);

    do {
        printf("\nMenu:\n");
        printf("1. Search Employee by Name\n");
        printf("2. Search Employee by ID\n");
        printf("3. Display All Employees\n");
        printf("4. Display Employees with Salary Greater than a Value\n");
        printf("5. Display Employee with Maximum Salary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter Name to search: ");
                scanf("%s", name);
                searchByName(employees, n, name);
                break;

            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchById(employees, n, id);
                break;

            case 3:
                displayAll(employees, n);
                break;

            case 4:
                printf("Enter the salary value: ");
                scanf("%f", &salary);
                AboveSalary(employees, n, salary);
                break;

            case 5:
                MaxSalary(employees, n);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 6);

    return 0;
}

