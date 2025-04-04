class day_exception extends Exception{
    date_expection(){
        System.out.println("Exception : date should be between 1 to 31");
    }
}
class month_exception extends Exception{
    date_expection(){
        System.out.println("Exception : date should be between 1 to 31");
    }
}
class year_exception extends Exception{
    date_expection(){
        System.out.println("Exception : date should be between 1 to 31");
    }
}

public class main extends string_expection{
        main(int date){
            super(date);
        }
    public static void main(String args[]) throws string_expection{
        int dd = Integer.parseInt(args[0]);
        int mm = Integer.parseInt(args[1]);
        int yy = Integer.parseInt(args[2]);
        try{
            if(dd > 0 && dd <= 31 ){
                throw new day_exception();
            }else if(mm > 0 && mm <= 12{
                throw new month_exception();
            }else if(yy > 1950 && yy <= 2024){
                throw new year_exception();
            }
        }catch(Exception e){
            System.out.println("Exception is "+ e);
        }class string_expection extends Exception{
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
}