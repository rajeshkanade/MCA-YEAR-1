#include<stdio.h>
#define NUM_SUBJECTS 5
#define MAX_STUDENTS 10

typedef struct Student{
    char name[50];
    int roll_no;
    int marks[NUM_SUBJECTS];
    float percent;
}Student;


void getData(Student *s){

    int totalMarks = 0 ;
    
    printf("Enter the name : ");
    scanf("%s",s->name);
    printf("Enter the roll No :");
    scanf("%d",&s->roll_no);
    for(int i = 0 ; i < NUM_SUBJECTS ; i++){
        // enterMarksAgain : 
        printf("Enter the marks for %d subject (Out of 100)",i+1);
        scanf("%d",&s->marks[i]);
        if(s->marks[i] > 100 || s->marks[i] < 0){
            printf("Invalid marks please enter again : ");
            // goto enterMarksAgain;
        }
        totalMarks += s->marks[i];
    }
    s->percent = (float) totalMarks / (NUM_SUBJECTS * 100) * 100 ;
    // printf("\n\nPercentage is : %f",s->percent);

}

void displayData(Student s){
  printf("%s\t%d\t",s.name,s.roll_no);
  for(int i = 0 ; i < NUM_SUBJECTS ; i++){
    printf("%d ", s.marks[i]);
  }
  printf("\t%.2f",s.percent);
}

void displayMeritList(Student s[], int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(s[i].percent < s[j].percent){
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
int main(){
    int n ;
    Student s[MAX_STUDENTS];
    printf("Enter the number of student to enter (Max is %d)",MAX_STUDENTS);
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++){
        printf("Enter the details for %d Student : ", i+1);
        getData(&s[i]);
    }

    printf("\n\nDisplaying data of students : \n\n");
    printf("SrNo \tName \tRollNo\t    marks \t Percentage\t\n");
    for(int i = 0 ; i < n ; i++){
    printf("-------------------------------------------------------------\n");

        printf("%d\t",i+1);
        displayData(s[i]);
        printf("\n");
    }

    displayMeritList(s,n);
    printf("\n\nDisplaying data of students According to Merit list : \n\n");
    printf("SrNo \tName \tRollNo\t    marks \t Percentage\t\n");
    for(int i = 0 ; i < n ; i++){
    printf("-------------------------------------------------------------\n");

        printf("%d\t",i+1);
        displayData(s[i]);
        printf("\n");
    }
}