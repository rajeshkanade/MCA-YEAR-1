import java.util.*;
import MScCAI.MScCAIMarks;
import MScCAII.MScCAIIMarks;


class Student {
   private int rollNo ;
   private String name;
   private int CAIMarks1Total;
   private int CAIMarks2Total;
   private int CAIIMarks1Total;
   private int CAIIMarks2Total;
   private int TotalMarks;
Scanner sc = new Scanner(System.in);
   void getStudent(){
            System.out.println("Enter the roll no : ");
            rollNo = sc.nextInt();
            System.out.println("Enter the Name : ");
            name = sc.next();
            System.out.println("Enter the MScCAIMarks 1 : ");
            CAIMarks1Total = sc.nextInt();
            System.out.println("Enter the MScCAIMarks 2 : ");
            CAIMarks2Total = sc.nextInt();
            
            System.out.println("Enter the MScCAIIMarks 1 : ");
            CAIIMarks1Total = sc.nextInt();
            System.out.println("Enter the MScCAIIMarks 2 ");
            CAIIMarks2Total = sc.nextInt();
            
    }

    void displayResult(){
        MScCAIMarks m1 = new MScCAIMarks(CAIMarks1Total,CAIMarks2Total);
        MScCAIIMarks m2 = new MScCAIIMarks(CAIIMarks1Total,CAIIMarks2Total);
        int TotalMarks = m1.TotalMarks() + m2.TotalMarks();
        char grade = calculateGrade(TotalMarks);
        System.out.println(rollNo + "\t" + name + "\t" + TotalMarks + "\t" + grade);
    }

    char calculateGrade(int TotalMarks){
        if(TotalMarks > 370){
            return 'O';
        }else if(TotalMarks > 280){
            return 'A';
        }else if(TotalMarks > 200){
            return 'B';
        }else if(TotalMarks > 120){
            return 'C';
        }else {
            return 'F';
        }
    }


}

public class a2{
    public static void main(String args[]){
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of n : ");
        n = sc.nextInt();
        Student s[] = new Student[n] ;

        for(int i = 0 ; i < n ; i++){
            s[i] = new Student();
            System.out.println("Enter Details for student " + (i+1));
            s[i].getStudent();
        }

        System.out.println("Student details : ");
        System.out.println("RollNo \t Name \t Total \t Grade: ");
        for(int i = 0 ; i < n ; i++){
            s[i].displayResult();

        }


    }
}