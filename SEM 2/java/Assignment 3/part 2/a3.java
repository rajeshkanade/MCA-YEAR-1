import java.util.Scanner;

class Vehicle{
    private String company;
    private double price;

    public Vehicle(String company,double price){
        this.company = company;
        this.price = price;
    }

    public void display(){
        System.out.println("\nCompany: "+company);
        System.out.println("Price: "+price);
    }
}

class LMV extends Vehicle{
    private int mileage;

    public LMV(String company,double price,int mileage){
        super(company,price);
        this.mileage = mileage;
    }

    public void display(){
        super.display();
        System.out.println("Mileage: "+mileage);
    }
}

class  HMV extends Vehicle{
    private int capacity;

    public HMV(String company,double price,int capacity){
        super(company,price);
        this.capacity = capacity;
    }

    public void display(){
        super.display();
        System.out.println("Capacity: "+capacity);
    }
}

class a3{
    public static void main(String args[]){
        String company;
        int mileage,capacity,choice;
        double price;

        Scanner sc = new Scanner(System.in);
        
        System.out.print("\nEnter how many vehicle's: ");
        int n = sc.nextInt();

        Vehicle v[]=  new Vehicle[n];

        for(int i=0;i<n;i++){
            System.out.print("\nEnter "+(i+1)+" vehicle detail's: ");
            System.out.print("\nEnter Company: ");
            company = sc.next();
            System.out.print("Enter Price: ");
            price = sc.nextDouble();
            System.out.println("Enter your choice: ");
            System.out.println("1:LMV");
            System.out.println("2:HMV");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            if(choice==1){
                System.out.print("\nEnter Mileage: ");
                mileage = sc.nextInt(); 
                v[i] = new LMV(company,price,mileage);
            }
            else if(choice==2){
                System.out.print("Enter Capacity in tons: ");
                capacity = sc.nextInt();
                v[i] = new HMV(company,price,capacity);
            }
        }

        System.out.println("\nLight Motor Vehicle Detail's: ");
        for(Vehicle ob : v){
            if(ob instanceof LMV){
                ob.display();
            }
        }

        System.out.println("\nHeavy Motor Vehicle Detail's: ");
        for(Vehicle ob : v){
            if(ob instanceof HMV){
                ob.display();
            }
        }
    }
}