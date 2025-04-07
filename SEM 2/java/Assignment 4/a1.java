// Question: Write a Java program to create a custom thread class that extends the Thread class. 
// The thread should display its message, name, ID, priority, and state in an infinite loop with a 1-second delay between iterations. 
// Create two threads with different messages and names, and start them from the main method.

class MyThread extends Thread{
    private String message;
    MyThread(String message , String name){
        super(name);
        this.message = message;
        
    }

    public void run(){
        while(true){
            System.out.println("Message : " + message + "\nThread Name : " + getName() + "\nThread Id : " + getId() + "\n Thread Priority : " + getPriority() + "\nThread State : " + getState()   +"\n\n");
            try{
                Thread.sleep(1000);
            }catch(Exception e){
                e.printStackTrace();
            }
        }
    }
}

public class a1{
    public static void main(String args[]){
        MyThread t1 = new MyThread("I am Thread 1", "Thread 1");
        t1.start();
        MyThread t2 = new MyThread("I am Thread 2" , "Thread 2");
        t2.start();
    }
}