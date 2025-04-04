// for running enter command 
// javac a3.java 
// java a3 "/exportspg/mca28/Rajesh's code/SEM 2/java/Assignment 4/MyFile/third.txt" 

import java.io.File;
class fileDirectoryChecker{
    String path= "";
    fileDirectoryChecker(String path){
        this.path = path;
    }

    public void checkFileOrDir(){
        File file = new File(path);
        if(!file.exists()){
            System.out.println("File not exisits !!!!!");
            return ;
        }


        if(file.isDirectory()){
            int count = 0;
            System.out.println("path : " + file.getAbsolutePath());
            File[] files = file.listFiles();
            for(File f : files){
                if(f.isFile()){
                    count ++;

                    if(f.getName().endsWith(".txt")){
                        System.out.println("File  : " + f.getName() );
                    }
                }
            }
            System.out.println("Total Files : " + count);
        }
        else if(file.isFile()){
            System.out.println("File Name : " + file.getName());
            System.out.println("File Size : " + file.length() + " bytes");
            System.out.println("Readable : " + file.canRead());
            System.out.println("Writable : " + file.canWrite());
            System.out.println("Excecutable : " + file.canExecute());

        }
    }
}

public class a3{
    public static void main(String args[]){

        String filePath = args[0];
        fileDirectoryChecker f1 = new fileDirectoryChecker(filePath);
        f1.checkFileOrDir();

    }
}