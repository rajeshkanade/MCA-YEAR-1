#include<stdio.h>

#define Max_employee 20
#define Salary_A 80000
#define Salary_B 70000
#define Salary_C 50000


struct employee
{
    char name[20];
    int Eid;
    char class;
    double salary;
    double G_S;
};

void getData(struct employee *s)
{
    printf("\nEnter id of employee: ");
    scanf("%d",&s->Eid);

    printf("\nEnter name of employee: ");
    scanf("%s",s->name);

    do
    {
       printf("\nEnter class of employee: ");
       scanf(" %c",&s->class);
    }while(!(s->class=='A' || s->class=='B' || s->class=='C'));

    
    if(s->class=='A')
    {
	 s->salary=Salary_A;
    }

    else if(s->class=='B')
    {
         s->salary=Salary_B;
    }

    else
    {
         s->salary=Salary_C;
    }
 
    float HRA,PF,MA,TA,G_S;
    HRA=0.4*s->salary;
    PF=0.12*s->salary;
    MA=0.15*s->salary;
    TA=0.10*s->salary;
    s->G_S=s->salary+HRA+MA+TA;


}

void DisplayData(struct employee employees[],int n)
{
    for(int i=0;i<n;i++)
    {   
        printf("\n\t\tEmplyee Id: \t%d",employees[i].Eid);
        printf("\n\t\tName:%s \t\t",employees[i].name);
        printf("\n\t\tsalary:%.2lf\t\t",employees[i].salary);
        printf("\n\t\tG_salary:%.2lf\t\t",employees[i].G_S);
	printf("\n\t\tClass:%c \t\t",employees[i].class);


    }
}
void search(struct employee employees[],int n,int x)
{   int flag=0;
    for(int i=0;i<n;i++)
    {
       if(employees[i].Eid==x)
       {
	flag=1;
	printf("\nfound\n");
        printf("\n\t\tEmplyee Id: \t%d",employees[i].Eid);
        printf("\n\t\tName:%s \t\t",employees[i].name);
        printf("\n\t\tsalary:%.2lf\t\t",employees[i].salary);
        printf("\n\t\tG_salary:%.2lf\t\t",employees[i].G_S);
	printf("\n\t\tClass:%c \t\n",employees[i].class);

       }
      
       
    }
    if(!flag)
    {
      printf("\n not found");

    }

}



int main()
{
    struct employee employees[Max_employee];
    int n;

    printf("\nEnter number of employees[max %d]: ",Max_employee);
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("\nEnter details of employee: %d",(i+1));
        getData(&employees[i]);
    }

    printf("\n--------Employee data------------");

    DisplayData(employees,n);
    
    int id;
    printf("\nEnter emp id to display data: ");
    scanf("%d",&id);
    search(employees,n,id);

    return 0;
}
