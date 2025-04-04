// create class employee having parameters name , pos , salary and count the object created 

import java.util.*;

class Employee{
    static String name , pos;
    static float salary;
    static int count = 0;
   
    Employee(){
        count++;
    }
    Employee(String name , String pos , float salary){
        this.name = name;
        this.pos = pos;
        this.salary = salary;
        count++;

    }

    static void displayEmployee(){
        System.out.println("Name     : "+  name);
        System.out.println("Position : " + pos);
        System.out.println("Salary   : " + salary);
    }
  

}

public class a1{
      public static void main( String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter name of employee : ");
        String name = sc.nextLine();
        System.out.println("Enter position of employee : ");
        String position = sc.nextLine();
        System.out.println("Enter Salary of employee : ");
        float salary = sc.nextFloat();

        
        Employee e1 = new Employee();
        Employee e2 = new Employee(name , position , salary);
        System.out.println();
        Employee.displayEmployee();
        System.out.println("total obj created : " + Employee.count);
        
    }
}

