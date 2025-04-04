class main{
    int a,b;
    public main(int a , int b){
        this.a = a;
        this.b = b;
    }
    public void add(){
        System.out.println("Addition of two number : "+(a+b));
    }
}
class sample{
    public static void main(String args[]){
        main obj1 = new main(2,3);
        obj1.add();
        main obj2 = new main(20,13);
        obj2.add();
        main obj3 = new main(22,13);
        obj3.add();


        int num = 2;
        char ch = 'A';
        float pi = 3;
        double pi2 = 3.1456723;
        String str = "rajesh";

        System.out.println("Integer : " + num);
        System.out.println("Charcter : " + ch);
        System.out.println("Float : " + pi);
        System.out.println("Double : " + pi2);
        System.out.println("String : " + str);
    }
} 