#include<stdio.h>
int main(){
    int id , emp_salary;
    printf("Enter employee ID : ");
    scanf("%d",&id);

    printf("Enter Employee Salary : ");
    scanf("%d",&emp_salary);

    float inhand_salary = emp_salary - (10 * emp_salary / 100) - (30 * emp_salary / 100) - (5 * emp_salary / 100);
    printf("\nEmployee ID                               : %d",id);
    printf("\n\nInhand salary of employee to go home is : %.2f\n\n",inhand_salary);
    return 0;
}