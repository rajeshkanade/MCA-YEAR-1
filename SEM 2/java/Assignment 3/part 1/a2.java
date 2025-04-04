import java.util.Scanner;
import java.text.DecimalFormat;
abstract class Shape {
    double PI = 3.14;
    abstract void calc_area(DecimalFormat df);
    abstract void calc_volume(DecimalFormat df);
}

class Sphere extends Shape {
    private double radius;

    Sphere() {
        this.radius = 1.0;
    }

    Sphere(double radius) {
        this.radius = radius;
    }


    @Override 
    void calc_area(DecimalFormat df) {
        double area = 4 * PI * (radius * radius);
        System.out.println("Area of Sphere : " + df.format(area));
    }

    @Override 
    void calc_volume(DecimalFormat df) {
        double volume = 1.3 * PI * (radius * radius * radius);
        System.out.println("Volume of Sphere : " + df.format(volume));
    }
}

class Cone extends Shape {
    private double radius, height;

    Cone() {
        this.radius = 1.0; 
        this.height = 1.0;
    }

    Cone(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    @Override 
    void calc_area(DecimalFormat df) {
        double l = Math.sqrt(radius * radius + height * height);
        double area = PI * radius * (radius + l);
        System.out.println("Area of Cone : " + df.format(area));
    }

    @Override 
    void calc_volume(DecimalFormat df) {
        double volume = 1.0/3.0 * PI * (radius * radius * height);
        System.out.println("Volume of Cone : " + df.format(volume));
    }
}

class Cylinder extends Shape {
    private double radius, height; 

    Cylinder() {
        this.radius = 1.0; 
        this.height = 1.0;
    }

    Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    @Override 
    void calc_area(DecimalFormat df) {
        double area = 2 * PI * radius * (radius + height);
        System.out.println("Area of Cylinder : " + df.format(area));
    }

    @Override 
    void calc_volume(DecimalFormat df) {
        double volume = PI * (radius * radius) * height;
        System.out.println("Volume of Cylinder : " + df.format(volume));
    }
}

class Box extends Shape {
    private double length, breadth, height;

    Box() {
        this.length = 1.0; 
        this.breadth = 1.0;
        this.height = 1.0;
    }

    Box(double length, double breadth, double height) {
        this.length = length;
        this.breadth = breadth;
        this.height = height;
    }

    @Override 
    void calc_area(DecimalFormat df) {
        
        double area = 2 * ((length * breadth) + (length * height) + (breadth * height));
        System.out.println("Area of Box : " + df.format(area));
    }

    @Override 
    void calc_volume(DecimalFormat df) {
        double volume = length * breadth * height;
        System.out.println("Volume of Box : " + df.format(volume));
    }
}

public class a2 {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("0.00");
        
        System.out.print("Enter radius: ");
        double radius = scanner.nextDouble();
        
        System.out.print("Enter height: ");
        double height = scanner.nextDouble();
        
        System.out.print("Enter length: ");
        double length = scanner.nextDouble();
        
        System.out.print("Enter breadth: ");
        double breadth = scanner.nextDouble();

        Shape sphere = new Sphere(radius);
        Shape cone = new Cone(radius, height);
        Shape cylinder = new Cylinder(radius, height);
        Shape box = new Box(length, breadth, height);

        sphere.calc_area(df);
        sphere.calc_volume(df);
        System.out.println("");
        cone.calc_area(df);
        cone.calc_volume(df);
        System.out.println("");

        cylinder.calc_area(df);
        cylinder.calc_volume(df);
        System.out.println("");

        box.calc_area(df);
        box.calc_volume(df);
        System.out.println("");
        scanner.close();
    }
}
