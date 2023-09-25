// /**Wap in java
//  * to demonstrate inhertence
//  * 2 classes
//  * display properties that the child class has 
//  * grand father house
//  * gprop in protected
//  * Name:Ansh Garg
//  * Roll No:
//  * SAP ID: 500105940
//  */
import java.util.Scanner;

class grandfather {
    protected String gprop = "House";
    void gdisp() 
    {
        System.out.println("Grandfather lives in a house ");
    }
}

class father extends grandfather {
    String fprop = "Car";

    void fdisp() 
    {
        System.out.println("Father has a car");
    }
}

class son extends father {
    String sprop = "Bike";

    void sdisp() {
        System.out.println("Son has a bike");
        System.out.println("Son has: " + super.gprop); // Access gprop using super
    }
}

class p9
{
    public static void main(String[] args)
    {
        son s = new son();
        System.out.println("Son has: " + s.fprop);
        System.out.println("Son has: " + s.sprop);

        s.gdisp(); 
        s.fdisp(); 
        s.sdisp();
    }
}
