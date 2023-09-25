/**WAP in java
 * to demonstrate multiple inheritence using interfaces
 * interface A: has points as input parameters
 * interface B: has length as input parameters 
 * Create a class circle 
 * call both interfaces
 * circle has center (points) and radius (length)
 * display properties of 2 circles 
 * 2 objects
 * auto increment 
 * put values of each circle
 * display the parameters(properties)
 * Name:Ansh Garg
 * Roll No:22
 * SAP ID: 500105015
 */
import java.util.Scanner;

interface A {
    void points(int x, int y);
}

interface B {
    void length(int length);
}

class Circle implements A, B {
    private int centerX;
    private int centerY;
    private int radius;

    public void points(int x, int y) {
        centerX = x;
        centerY = y;
    }

    public void length(int length) {
        radius = length;
    }

    public void disp() {
        System.out.println("Center: (" + centerX + ", " + centerY + ")");
        System.out.println("Radius: " + radius);
    }
}

class userinput {
    public static Circle input(String circleName) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the details of " + circleName + " (x, y, length): ");
        int x = sc.nextInt();
        int y = sc.nextInt();
        int length = sc.nextInt();
        Circle circle = new Circle();
        circle.points(x, y);
        circle.length(length);
        return circle; // Do not close the Scanner here
    }
}


public class assign2 {
    public static void main(String[] args) {
        Circle c1 = userinput.input("Circle 1");
        Circle c2 = userinput.input("Circle 2");

        System.out.println("OUTPUT:\n");
        System.out.println("Circle 1:");
        c1.disp();

        System.out.println("\nCircle 2:");
        c2.disp();
    }
}