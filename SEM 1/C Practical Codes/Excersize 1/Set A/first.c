#include<stdio.h>
int main(){

    int emp_sal ;
    printf("Enter the employee salary : ");
    scanf("%d",&emp_sal);

    
    if(emp_sal > 150000 && emp_sal < 300000){
        float tax = 20 * (emp_sal /100);

        printf("Employee Salary is : %d and it contains 20 tax : %f",emp_sal,tax);

    }
    else if(emp_sal > 300000){
        float tax = 20 * (emp_sal /100);
        printf("Employee Salary is : %d and it contains 30 tax is : %d",emp_sal,tax);
    }
    else{
        printf("Employee Salary is : %d and it contains 0 tax",emp_sal);

    }
    return 0;
}