import java.util.Scanner;
class Student{
    int rollNo;
    String name;
    double percent;

    Student(){
        this.rollNo = 0;
        this.name = "";
        this.percent = 0.0;
    }
    
    Student(int rollNo, String name , Double percent){
        this.rollNo = rollNo;
        this.name = name;
        this.percent = percent;
    }

    static void sortStudent(Student s[]){
        int n = s.length;
        for(int i = 0 ; i < n - 1; i++){
            for(int j = 0 ; j < n - i - 1 ; j++){
                if(s[j].percent < s[j+1].percent){
                    Student temp = s[j];
                    s[j] = s[j+1];
                    s[j+1] = temp;
                }
            }
        }
    }
}

public class a3{
    public static void main(String args[]){
        int n , rollNo;
        String name ;
        double percent;
        Student s1 = new Student();
        System.out.println("Enter the value of n : ");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // creating the array 
        Student[] s = new Student[n];
        

        // Accepting the values :
        for(int i = 0 ; i < n ; i++){
            System.out.println("Enter roll no , name and percentage of student : ");
            rollNo = sc.nextInt();
            name = sc.next();
            percent = sc.nextDouble();
            s[i] = new Student(rollNo, name , percent);

        }
        Student.sortStudent(s);
         
         // displaying the students 
        for(int i = 0 ; i < n ;i++){
            System.out.println("roll no : "+s[i].rollNo);
            System.out.println("Name    : "+s[i].name);
            System.out.println("Percent : "+s[i].percent);
        }

    }
}