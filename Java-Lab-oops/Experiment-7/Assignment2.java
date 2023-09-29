// 1)wap a program to handle another type of exception according to your choice
// 2)inlcude user input, this should create an exception
// 3)print the exception message to show that expetion is caught
// 4)Identify the exception handling keywords used in the program and why

import java.util.Scanner;

public class Assignment2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = sc.nextLine();
        try {
            int num = Integer.parseInt(str);
            System.out.println("Number entered: " + num);
        } catch (NumberFormatException e) {
            System.out.println("NumberFormatException caught: " + e.getMessage());
        }
    }
}