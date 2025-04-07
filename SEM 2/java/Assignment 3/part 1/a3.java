// Question: Write a Java program to implement an abstract class `Staff` with attributes `name` and `address`. 
// Create two subclasses `FullTimeStaff` and `PartTimeStaff` with additional attributes specific to each type. 
// Use an array to store multiple objects of these subclasses and display their details based on user input.

import java.util.*;
abstract class Staff{
    String name ,  address;
    abstract void displayStaff();
    Staff(String name , String address){
        this.name = name;
        this.address = address;
    }
}

class FullTimeStaff extends Staff{
    String department ;
    double salary;
    FullTimeStaff(String name, String address , String department , double salary){
            // this.name = name;
            // this.address = address;
        super(name,address);
        this.department = department;
        this.salary = salary;
    }

    @Override 
    void displayStaff(){
        System.out.println("name : " + name + "\t address : " + address +  "\t department : "+ department + "\t salary : " + salary);

    }
}

class PartTimeStaff extends Staff{
    int noOfHours;
    double ratePerHours;
    PartTimeStaff(String name, String address , int noOfHours , double ratePerHours){
        // this.name = name;
        // this.address = address;
        super(name,address)    ;

        this.noOfHours = noOfHours;
        this.ratePerHours = ratePerHours;
    }

     @Override 
    void displayStaff(){
        System.out.println("name : " + name + "\t address : " + address +  "\t noOfHours : "+ noOfHours + "\t ratePerHours : " + ratePerHours);
    }
}


public class a3{
    public static void main(String args[]){
        System.out.println("hello");
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of n : ");
        int n = sc.nextInt();
        Staff[] ps = new PartTimeStaff[n];
        Staff[] fs = new FullTimeStaff[n];
        int size1 = 0 , size2 = 0;
        for(int i = 0 ; i < n ; i ++){
            System.out.println("Enter 1 for creating object full time staff\n Enter 2 for creating object of part time staff");
            int choice = sc.nextInt();
            if(choice == 1){
                System.out.println("Enter the name : ");
                String name = sc.next();
                System.out.println("Enter the address : ");
                String address = sc.next();
                System.out.println("Enter the department : ");
                String department = sc.next();
                System.out.println("Enter the salary : ");
                int salary = sc.nextInt();
                fs[size1 ++] = new FullTimeStaff(name,address,department,salary);
            }
            else if(choice == 2){
                System.out.println("Enter the name : ");
                String name = sc.next();
                System.out.println("Enter the address : ");
                String address = sc.next();
                System.out.println("Enter the noOfHours : ");
                int noOfHours = sc.nextInt();
                System.out.println("Enter the ratePerHours : ");
                double ratePerHours = sc.nextDouble();
                ps[size2++] = new PartTimeStaff(name,address,noOfHours,ratePerHours);
                ;
            }else{
                System.exit(0);
            }
        }
        System.out.println("Displaying fullTime Staff details");
        for(int i = 0 ; i < size1 ; i ++){
            fs[i].displayStaff();
            }
        System.out.println("\nDisplaying partTime Staff details");
        for(int i = 0 ; i < size2 ; i ++){
            ps[i].displayStaff();
        }

    }
}
