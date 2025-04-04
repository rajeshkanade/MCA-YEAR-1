// create a program to store and calculate the salary details of employees.  

#include<stdio.h>
typedef struct Employee{
    int emp_id ;
    char name[20];
    float basic_salary;
    float bonus;
}Employee;

void getEmp(Employee e[]){
    for(int i = 0 ; i < 3 ; i++){
    printf("\n\nEnter details for %d Employee : ", i+1);
    printf("\nEnter the employee id : ");
    scanf("%d",&e[i].emp_id);
    printf("\nEnter the employee Name : ");
    scanf("%s",&e[i].name);
    printf("\nEnter the employee basic salary : ");
    scanf("%f",&e[i].basic_salary);
    printf("\nEnter the employee bonus : ");
    scanf("%f",&e[i].bonus);
    }
}

void disEmp(Employee e[]){
    for(int i = 0 ; i < 3 ; i++){
        printf("\n%d\t%s\t%.2f\t%.2f",e[i].emp_id,e[i].name,e[i].basic_salary,e[i].bonus);
    printf("\n");
    }
}
int main(){
    Employee e[3];
    getEmp(e);

    printf("\nEmployees Details are : ");
    printf("\n--------------------------------------");
    disEmp(e);
    return 0;
}