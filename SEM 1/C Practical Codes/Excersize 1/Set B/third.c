#include<stdio.h>
int main(){
    int subject_marks[3];
    int sum = 0;
        printf("Enter the marks of 3 subjects : ");
    for(int i = 0 ; i < 3 ; i++){
        scanf("%d",&subject_marks[i]);
        sum += subject_marks[i];
    }

    printf("Average of marks is : %d \n", sum/3 );
    if((sum/3) >= 80){
        printf("Student is in First Class \n");
    }
    else if((sum/3) >= 60){
        printf("Student is in Second Class \n");
    }
    else if((sum/3) >= 40){
        printf("Student is in Third Class \n");
    }
    else{
        printf("Student Failed\n");

    }
}