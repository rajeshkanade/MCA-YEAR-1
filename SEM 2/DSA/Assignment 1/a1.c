// write a program to store and display student information(name , roll no , marks in 3 subjects) using sturctures. 

#include<stdio.h>
typedef struct Student{
    char name[20];
    int rollNo ;
    int marks[3];
}Student;


void getStud(Student *s){
    printf("Enter the name : ");
    scanf("%s",&s->name);
    printf("Enter the Roll NO : ");
    scanf("%d",&s->rollNo);
    printf("Enter the marks for three Subject : ");
    for(int i = 0 ; i < 3 ; i++){
        scanf("%d",&s->marks[i]);
    }
}

void disStud(Student s){
    float avg ;
    printf("\n%d\t%s\t",s.rollNo,s.name);
    for(int i = 0 ; i < 3 ; i++){
        avg += s.marks[i];
        printf("%d  ",s.marks[i]);
        
    }
    printf("\t\t%.2f",(avg/3));
    printf("\n");
}
int main(){

    Student s;
    getStud(&s);

    printf("\nRollNo\tName\tMarks(3 Subject)\taverageMarks");
    printf("\n--------------------------------------------------------------");
    disStud(s); 

    return 0;
}           case 1:
                getStud(&s);
                break;
            case 2:
                disStud(s);
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
