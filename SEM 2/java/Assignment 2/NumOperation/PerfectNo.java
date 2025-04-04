package NumOperation;

public class PerfectNo{

    public void checkPerfect(int no){
        int sum = 0;
        for(int i = 1 ; i <= no / 2 ; i++){
            if(no % i == 0){
                sum += i;
            }
        }
        if(sum == no){
            System.out.println("" + no + " Number is perfect No ");

        }else{
            System.out.println("" + no + " Number is not perfect No ");

        }
    }
}