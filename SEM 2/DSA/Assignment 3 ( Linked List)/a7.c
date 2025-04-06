// Question: Write a C program to manage two sets of students who like two different flavors of ice cream: Vanilla and Butterscotch. 
// The program should allow the user to perform the following operations:
// 1. Add students to the Vanilla set.
// 2. Add students to the Butterscotch set.
// 3. Display the set of students who like either Vanilla or Butterscotch or both.
// 4. Display the set of students who like both Vanilla and Butterscotch.
// 5. Display the set of students who like only Vanilla and not Butterscotch.
// 6. Display the set of students who like only Butterscotch and not Vanilla.
// 7. Print the details of both sets.
// 8. Exit the program.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student
{
    int rollNo;
    char name[20];
    char like[20];
    struct Student *next;
} Student;

Student *createNode(int rollNo, char name[], char like[])
{
    Student *newStudent = (Student *)malloc(sizeof(Student));
    newStudent->rollNo = rollNo;
    strcpy(newStudent->name, name);
    strcpy(newStudent->like, like);
    newStudent->next = NULL;
    return newStudent;
}

Student *createLinkedList(Student *Set, int n, char like[])
{
    int rollNo;
    char name[10];

    for (int i = 1; i <= n; i++)
    {
        printf("Enter details of %d student (rollNo , name )", i);
        scanf("%d", &rollNo);
        scanf("%s", &name);
        Student *newStudent = createNode(rollNo, name, like);
        if (Set == NULL)
        {
            Set = newStudent;
        }
        else
        {
            Student *temp = Set;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
    }
    return Set;
}

void printStudent(Student *Set)
{
    int count = 1;
    Student *temp = Set;
    while (temp != NULL)
    {
        printf("\nStudent %d details\n", count);
        printf("\nRoll NO : %d", temp->rollNo);
        printf("\nName    : %s", temp->name);
        printf("\nLikes   : %s ", temp->like);
        temp = temp->next;
        count++;
    }
}

void printOneStudent(Student *Set, int rollNo){
    Student *temp = Set;
    while(temp != NULL){
        if(temp->rollNo == rollNo){
            printf("\nStudent %d details\n", rollNo);
            printf("\nRoll NO : %d", temp->rollNo);
            printf("\nName    : %s", temp->name);
            printf("\nLikes   : %s ", temp->like);
            return;
        }
        temp = temp->next;
    }
}

void printALL(Student *setA , Student *setB){
    Student *tempA = setA;
    Student *tempB = setB;
    while(tempA != NULL && tempB != NULL){
        if(tempA->rollNo < tempB->rollNo){
            printOneStudent(tempA,tempA->rollNo);
            tempA = tempA->next;
        }else if(tempB->rollNo < tempA->rollNo){
            printOneStudent(tempB, tempB->rollNo);
            tempB = tempB->next;
        }else{
            printOneStudent(tempA, tempA->rollNo);
            tempA = tempA->next;
            tempB = tempB->next;
        }
        }
}

void printVanillaAndButterScotch(Student *setA , Student *setB){
    Student *tempA = setA;
    Student *tempB = setB;
    while(tempA != NULL && tempB != NULL){
        if(tempA->rollNo < tempB->rollNo){
            tempA = tempA->next;
        }else if(tempB->rollNo < tempA->rollNo){
            tempB = tempB->next;
        }else{
            printOneStudent(tempA, tempA->rollNo);
            tempA = tempA->next;
            tempB = tempB->next;
        }
    }
}

void printLikeBoth(Student *setA , Student *setB){
    Student *tempA = setA;
    Student *tempB = setB;
    while(tempA != NULL && tempB != NULL){
        if(tempA->rollNo < tempB->rollNo){
            tempA = tempA->next;
        }else if(tempB->rollNo < tempA->rollNo){
            tempB = tempB->next;
        }else{
            printOneStudent(tempA, tempA->rollNo);
            tempA = tempA->next;
            tempB = tempB->next;
        }
    }
}
int main()
{
    Student *setA = NULL;
    Student *setB = NULL;
    Student *temp1 = NULL;
    Student *temp2 = NULL;
    int n, choice;

    while (1)
    {
        printf("\n1. Vallena Ice Cream");
        printf("\n2. ButterScotch Ice Cream");
        printf("\n3. Set of students who like either vanilla or butterscotch or both");
        printf("\n4. Set of students who like both vanilla and butterscotch");
        printf("\n5. Set of students who like only vanilla and butterscotch");
        printf("\n6. Set of student who like only butterscotch not vanilla");
        printf("\n7. printing setA and setB");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of students who like Vallena ice: ");
            scanf("%d", &n);
            setA = createLinkedList(setA, n, "Vallena");
            printf("Students who like Vallena ice-cream: ");
            printStudent(setA);
            break;

        case 2:
            printf("Enter the number of students who like ButterScotch ice: ");
            scanf("%d", &n);
            setB = createLinkedList(setB, n, "ButterScotch");
            printf("Students who like ButterScotch ice-cream: ");
            printStudent(setB);
            break;

        case 3:
            printf("\nStudents likes vanilla or butter scotch or both : ");
            printALL(setA,setB);

        case 7:
            printf("\n Set A : ");
            printf("\n---------------------------");
            printStudent(setA);
            printf("\n Set B : ");
            printf("\n---------------------------");
            printStudent(setB);
            break;
        case 8:
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
