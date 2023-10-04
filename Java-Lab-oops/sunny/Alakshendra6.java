import java.util.Scanner;

public class Alakshendra6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the shape: ");
        String shape = sc.nextLine();
        if (shape.equals("triangle")) {
            System.out.println("Enter the base and height: ");
            int base = sc.nextInt();
            int height = sc.nextInt();
            System.out.println("The area of the triangle is " + area(base, height));
        } else if (shape.equals("circle")) {
            System.out.println("Enter the radius: ");
            int radius = sc.nextInt();
            System.out.println("The area of the circle is " + area(radius));
        } else if (shape.equals("rectangle")) {
            System.out.println("Enter the length and breadth: ");
            int length = sc.nextInt();
            int breadth = sc.nextInt();
            System.out.println("The area of the rectangle is " + areaRectangle(length, breadth));
        } else {
            System.out.println("Invalid shape");
        }
        sc.close();
    }

    public static int area(int base, int height) {
        return (base * height) / 2;
    }

    public static double area(int radius) {
        return Math.PI * radius * radius;
    }

    public static int areaRectangle(int length, int breadth) {
        return length * breadth;
    }
}
