// Wap a program
// to demonstrate multiple inheritence using interfaces
// interface A has points as input parameter
// interface b has length as input parameter
// create a class circle 
// call both interfaces 
// circle has center(point) and radius (length)
// displate properties of 2 circle 2 objects
// auto increment 
// Put values of each circle 
//  display the parameter(properties)
//  * Name:Ansh Garg   
//  * Roll No:
//  * SAP ID: 500105940

interface A {
    void setCenter(int x, int y);
}

interface B {
    void setRadius(double length);
}

class Circle implements A, B {
    private static int nextId = 1;
    private int id;
    private int centerX, centerY;
    private double radius;

    public Circle() {
        id = nextId++;
    }

    public void setCenter(int x, int y) {
        centerX = x;
        centerY = y;
    }

    public void setRadius(double length) {
        radius = length;
    }

    public void displayProperties() {
        System.out.println("Circle " + id );
        System.out.println("Center: (" + centerX + ", " + centerY + ")");
        System.out.println("Radius Lenght: " + radius);
    }
}

public class assign {
    public static void main(String[] args) {
        Circle circle1 = new Circle();
        Circle circle2 = new Circle();

        

        circle1.setCenter(3, 4);
        circle1.setRadius(5.0);

        circle2.setCenter(-1, -2);
        circle2.setRadius(3.5);

        circle1.displayProperties();
        System.out.println();
        circle2.displayProperties();
    }
}
