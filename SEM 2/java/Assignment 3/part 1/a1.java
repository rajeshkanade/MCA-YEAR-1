// define class employee (having private id , name , department , salary ). define default and parameterized constructors. Create a subclass called as Manager(private member bonus). Define method display in both the classes. Create n object of the manager class and display the details of the manager having the maximum total salary (salary + bonus )

import java.util.*;
class Employee{
    private int id ;
    private String name;
    private String depart;
    public double salary;
    public Employee(){
        this.id = 0;
        this.name = "";
        this.depart = "";
        this.salary = 0.0;
    }
    public Employee (int id , String name , String depart , double salary){
         this.id = id;
        this.name = name; 
        this.depart = depart;
        this.salary = salary;
    }

    public double getSalary(){
        return salary;
    }
    public void display(){
        System.out.print(id + "\t" + name + "\t" + depart + "\t" + salary);
    }
}

class Manager extends Employee{
    private double bonus;
    public Manager(int id , String name , String depart , double salary ,double bonus){
        super(id,name,depart,salary);
        this.bonus = bonus;
        
    }
    public double getBonus(){
        return bonus;
    }
    public double getSalary(){
        return salary;
    }


public void display(){
    super.display();
    System.out.println("\t " + (getSalary() + getBonus()));
}

public static void  maximumBonusSalary(Manager m[]){
        double max = 0.0;
        int index = 0;
        for(int i = 0 ; i < m.length ; i++){
            if(m[i].getSalary() + m[i].getBonus() > max){
                max = m[i].getSalary() + m[i].getBonus();
                index = i;
            }
        }
     
        m[index].display();
}
}


public class a1{
    public static void main(String args[]){
        int n;
        int id ;
        String name,depart;
        double salary , bonus;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of n : ");
        n = sc.nextInt();
        Manager[] m = new Manager[n];
        for(int i = 0 ; i < n ;i++){
        System.out.println("Enter the details of " + (i+1) +" Manager");
            System.out.println("Enter the id : ");
            id = sc.nextInt();
            System.out.println("Enter the name : ");
            name = sc.next();
            System.out.println("Enter the department : ");
            depart = sc.next();
            System.out.println("Enter the salary : ");
            salary = sc.nextDouble();
            System.out.println("Enter the bonus : ");
            bonus = sc.nextDouble();
            m[i] = new Manager(id,name,depart,salary,bonus);
        }
        System.out.println("Details of manager are : ");
        System.out.println("Id}\tName\tDepart\tSalary\t");
        for(int i = 0 ; i < n ; i++){
            m[i].display();
        }
       System.out.println("Manager with highest Bonus Salary : ");
       Manager.maximumBonusSalary(m);

    }
}