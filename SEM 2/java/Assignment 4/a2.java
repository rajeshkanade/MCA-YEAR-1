
import java.util.*;
class thread extends Thread{
    int sum = 0 , count = 0;
    public ArrayList<Integer> arr = new ArrayList<>();
    public void run(){
        for(int i = 1 ; i <= 100 ; i++){
            int randomNumber = (int) (Math.random() * 100);
            arr.add(randomNumber);
        }
    }
    public int getSum(){
        try{
        Thread.sleep(1000);
        for(int no : arr){
            sum += no;
            count += 1;
        }
        }catch(Exception e){
            e.printStackTrace();
        }

        return sum;
    }
}


public class a2{
    public static void main(String args[]){

        thread t[] = new thread[10];
        int totalSum = 0;
        for(int i = 0 ;  i < 10 ; i ++){
            t[i] = new thread();
            t[i].start();
            t[i].getSum();
            totalSum += t[i].getSum();
        }
        System.out.println("Total Sum : " + (totalSum));
        double average = (double)totalSum/1000;
        System.out.println("Average   : " + average);
    }
}