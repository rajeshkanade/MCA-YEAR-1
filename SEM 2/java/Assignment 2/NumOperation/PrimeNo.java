package NumOperation;

public class PrimeNo{

    public void checkPrime(int no){
        int flag = 0;
        for(int i = 2 ; i < no ; i++){
            if(no % i == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            System.out.println("" + no + " is not prime");
        }else{
            System.out.println("" + no + " is prime");
            
        }
    }
}