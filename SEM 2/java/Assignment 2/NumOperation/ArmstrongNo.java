package NumOperation;
public class ArmstrongNo{
    
    public void checkArmStrong(int no){
        int temp = no;
        int rem , sum  = 0;
        int count = 0;
        
        while(no != 0){
            rem = no % 10;
            sum += rem * rem * rem;
            no = no/10;
        }
        if(sum == temp){
            System.out.println(""+ temp + " number is armstrong number ");
        }else{
            System.out.println(""+ temp + " number is not armstrong number ");
        }
    }
}