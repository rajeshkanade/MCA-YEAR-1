import java.io.*;
class SplitLines {
    String inputPath;
    SplitLines(String inputfile){
        this.inputPath = inputPath;
    }

    public void copyEvenOddLines(){
        File inputfile = new File(inputPath);
        if(!inputfile.exists()){
        System.out.println("File not found ...!");
        return ;
    }
    File evenFile = new File("./evenFile.txt");
    File oldFile = new File("./oddFile.txt");

    try{
        BufferedReader br = new BufferedReader(new FileReader(inputfile));
        BufferedWriter evenWrite = new BufferedWriter(new FileWriter(evenFile));
        BufferedWriter oddWrite = new BufferedWriter(new FileWriter(oldFile));
        String line;
        int lineNo = 1;
        while((line = br.readLine())!= null){
            if(lineNo % 2 == 0){
                evenWrite.write(line + "\n");
            }else{
                oddWrite.write(line + "\n");
            }
        }
    }catch(Exception e){
        e.printStackTrace();
    }
    }
    
}

public class a5{
    public static void main(String args[]){
        System.out.println(args[0]);
        File file = new File(args[0]);
        if(file.exists()){
            System.out.println("File Exists ");
        }else{
            System.out.println("File not exists");
        }
        // SplitLines sl = new SplitLines(args[0]);
        // sl.copyEvenOddLines();
    }
}