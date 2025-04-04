 import java.io.File;
 import java.util.Scanner;
 class file {
    String path = "";
    file(String path){
        this.path = path;
    }

    public void fileOpr(){
        File file = new File(path);

        if(!file.exists()){
            System.out.println("file is not exists");
            return;
        }

        int lineCnt = 0 , wordCnt = 0 , charCnt = 0;

        try{
            Scanner sc = new Scanner(file);

            while(sc.hasNextLine()){
                String line = sc.nextLine();
                lineCnt ++;
                charCnt = line.length();
                wordCnt = line.split("\\s+").length;
            }
        }catch(Exception e){
            e.printStackTrace();
        }

        System.out.println("line count : " + lineCnt + "\nword count : " + wordCnt + "\nchar count : " + charCnt);

    }
}

public class a4{
    public static void main(String args[]){
        String path = args[0];

        file f1 = new file(path);

        f1.fileOpr();
    }
}