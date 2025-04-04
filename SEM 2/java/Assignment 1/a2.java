class MyNumber{

    private int num;
    MyNumber(){
        num = 0;
    }
    MyNumber(int no){
        num = no;
    }
    void checkNo(){
        if(num > 0){
            System.out.println("Number is positive !");
        }else if(num < 0){
            System.out.println("Number is negative !");
       }else{
            System.out.println("Number is Zero");
       }
       if(num % 2 == 0){
            System.out.println("Number is even !");

       }else{
            System.out.println("Number is odd !");
       }
    }
}

public class a2{
    public static void main(String args[]){
        MyNumber n1 = new MyNumber();
        int num = Integer.parseInt(args[0]);
        MyNumber n2 = new MyNumber(num);
        n2.checkNo();

    }
}