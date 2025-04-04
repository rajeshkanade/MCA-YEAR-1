#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define N 100

typedef struct student {
    int rno;
    char name[50];
    float marks[3];   // Array for marks of 3 subjects
    float per;
}s;


float Percentage(float marks[]) {
    float total = 0;
    for (int i = 0; i < 3; i++) {
        total += marks[i];
    }
    return (total / 300.0) * 100;
}


void accept(s students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].rno);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Enter marks of 3 subjects: ");
        for (int j = 0; j < 3; j++) {
            scanf("%f", &students[i].marks[j]);
        }
        students[i].per = Percentage(students[i].marks);
    }
}

void search(s students[], int n, int rno) {
    for (int i = 0; i < n; i++) {
        if (students[i].rno == rno) {
            printf("Student found:\n");
            printf("Roll Number: %d, Name: %s, Percentage: %.2f%%\n", students[i].rno, students[i].name, students[i].per);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rno);
}


void modify(s students[], int n, int rno) {
    for (int i = 0; i < n; i++) {
        if (students[i].rno == rno) {
            printf("Enter new details for student whose Roll Number is %d:\n", rno);
            printf("New Name: ");
            scanf("%s", students[i].name);
            printf("Enter new marks of 3 subjects: ");
            for (int j = 0; j < 3; j++) {
                scanf("%f", &students[i].marks[j]);
            }
            students[i].per = Percentage(students[i].marks);
            printf("Details updated successfully.\n");
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rno);
}

// Function to display all student details
void displayAll(s students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nRoll Number: %d, Name: %s, Percentage: %.2f%%\n", students[i].rno, students[i].name, students[i].per);
    }
}

void AbovePercentage(s students[], int n, float per) {
    printf("Students with percentage greater than %.2f%%:\n", per);
    for (int i = 0; i < n; i++) {
        if (students[i].per > per) {
            printf("Roll Number: %d, Name: %s, Percentage: %.2f%%\n", students[i].rno, students[i].name, students[i].per);
        }
    }
}

void MaxPercentage(s students[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].per > students[max].per) {
            max = i;
        }
    }
    printf("Student with the highest percentage:\n");
    printf("Roll Number: %d, Name: %s, Percentage: %.2f%%\n", students[max].rno, students[max].name, students[max].per);
}

int main() {
    s students[N];
    int n, ch, rno;
    float per;
    // Accept number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Accept student details
    accept(students, n);

    do {
        printf("\nMenu:\n");
        printf("1. Search Student by Roll Number\n");
        printf("2. Modify Student Details\n");
        printf("3. Display All Students\n");
        printf("4. Display Students with Percentage Greater than a Value\n");
        printf("5. Display Student with Maximum Percentage\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter Roll Number to search: ");
                scanf("%d", &rno);
                search(students, n, rno);
                break;

            case 2:
                printf("Enter Roll Number to modify: ");
                scanf("%d", &rno);
                modify(students, n, rno);
                break;

            case 3:
                displayAll(students, n);
                break;

            case 4:
                printf("Enter the percentage value: ");
                scanf("%f", &per);
                AbovePercentage(students, n, per);
                break;

            case 5:
                MaxPercentage(students, n);
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
