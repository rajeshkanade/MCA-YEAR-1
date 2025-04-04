class string_expection extends Exception{
    string_expection(String str){
        System.out.println("Exception : string length should be greater than 8 character ");
    }
}

public class main extends string_expection{
        main(String str){
            super(str);
        }
    public static void main(String args[]) throws string_expection{
        String str = args[0];
        try{
            if(str.length() < 8){
                throw new string_expection(str);
            }else{
                System.out.println("You Enter the valid string : "+ str);
            }
        }catch(Exception e){
            System.out.println("Exception is "+ e);
        }
    }
}