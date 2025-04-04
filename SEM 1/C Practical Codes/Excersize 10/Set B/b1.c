//b1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the student structure
struct student {
    int roll_no;
    char name[50];
    float percentage;
};

// Function to add a new student
void addStudent(FILE *file) {
    struct student s;
    FILE *temp = fopen("student.dat", "ab+"); // Open in append mode

    // Calculate the next roll number
    fseek(temp, 0, SEEK_END);
    int size = ftell(temp) / sizeof(struct student);
    s.roll_no = size + 1;

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name); // Read name with spaces
    printf("Enter Percentage: ");
    scanf("%f", &s.percentage);

    fwrite(&s, sizeof(struct student), 1, temp);
    fclose(temp);

    printf("Student added successfully!\n");
}

// Function to search a student by roll number
void searchStudentByRoll(FILE *file) {
    int roll;
    struct student s;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    rewind(file); // Go to the beginning of the file
    while (fread(&s, sizeof(struct student), 1, file)) {
        if (s.roll_no == roll) {
            printf("Roll No: %d, Name: %s, Percentage: %.2f\n", s.roll_no, s.name, s.percentage);
            return;
        }
    }
    printf("Student with Roll No %d not found!\n", roll);
}

// Function to modify student details by name
void modifyStudentByName(FILE *file) {
    char name[50];
    struct student s;
    int found = 0;

    printf("Enter Name to modify: ");
    scanf(" %[^\n]", name);

    FILE *temp = fopen("temp.dat", "wb");
    rewind(file);
    while (fread(&s, sizeof(struct student), 1, file)) {
        if (strcmp(s.name, name) == 0) {
            printf("Enter new details for %s\n", name);
            printf("Enter New Percentage: ");
            scanf("%f", &s.percentage);
            found = 1;
        }
        fwrite(&s, sizeof(struct student), 1, temp);
    }
    // fclose(file);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found)
        printf("Student details modified successfully!\n");
    else
        printf("Student with Name '%s' not found!\n", name);
}

// Function to delete a student by name or roll number
void deleteStudent(FILE *file, int option) {
    struct student s;
    int roll;
    char name[50];
    int found = 0;

    FILE *temp = fopen("temp.dat", "wb");
    rewind(file);

    if (option == 1) { // Delete by name
        printf("Enter Name to delete: ");
        scanf(" %[^\n]", name);

        while (fread(&s, sizeof(struct student), 1, file)) {
            if (strcmp(s.name, name) != 0) {
                fwrite(&s, sizeof(struct student), 1, temp);
            } else {
                found = 1;
            }
        }
    } else if (option == 2) { // Delete by roll number
        printf("Enter Roll Number to delete: ");
        scanf("%d", &roll);

        while (fread(&s, sizeof(struct student), 1, file)) {
            if (s.roll_no != roll) {
                fwrite(&s, sizeof(struct student), 1, temp);
            } else {
                found = 1;
            }
        }
    }

    // fclose(file);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found)
        printf("Student deleted successfully!\n");
    else
        printf("Student not found!\n");
}

// Function to display all students
void displayAllStudents(FILE *file) {
    struct student s;
    rewind(file);

    printf("\nAll Students:\n");
    printf("Roll No\tName\t\tPercentage\n");
    printf("-----------------------------------\n");
    while (fread(&s, sizeof(struct student), 1, file)) {
        printf("%d\t%s\t\t%.2f\n", s.roll_no, s.name, s.percentage);
    }
}

int main() {
    int choice;
    FILE *file;

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Search Student by Roll Number\n");
        printf("3. Modify Student by Name\n");
        printf("4. Delete Student by Name\n");
        printf("5. Delete Student by Roll Number\n");
        printf("6. Display All Students\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        file = fopen("student.dat", "rb+");
        if (file == NULL && choice != 1) {
            printf("Error: Could not open file.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(file);
                break;
            case 2:
                searchStudentByRoll(file);
                break;
            case 3:
                modifyStudentByName(file);
                break;
            case 4:
                deleteStudent(file, 1);
                break;
            case 5:
                deleteStudent(file, 2);
                break;
            case 6:
                displayAllStudents(file);
                break;
            case 7:
                fclose(file);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }

        fclose(file);
    }

    return 0;
}