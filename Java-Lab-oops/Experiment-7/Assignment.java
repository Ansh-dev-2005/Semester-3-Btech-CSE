// 1)wap a program to handle another type of exception according to your choice
// 2)inlcude user input, this should create an exception
// 3)print the exception message to show that expetion is caught
// 4)Identify the exception handling keywords used in the program and why
// 5)Create a customised exception class for same code
import java.util.Scanner;


class MyException extends Exception {
    public MyException(String errorMessage) {
        super(errorMessage);
    }
}

class AnotherException extends Exception {
    public AnotherException(String errorMessage) {
        super(errorMessage);
    }
}

public class Assignment {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        try {
            if (num < 0) {
                throw new MyException("Number cannot be negative");
            } else if (num > 100) {
                throw new AnotherException("Number cannot be greater than 100");
            }
        } catch (MyException e) {
            System.out.println("MyException caught: " + e.getMessage());
        } catch (AnotherException e) {
            System.out.println("AnotherException caught: " + e.getMessage());
        }
    }
}