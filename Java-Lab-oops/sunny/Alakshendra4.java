// PROBLEM STATEMENT 4: Write a java program to find factorial of a number. Number should be entered through command prompt
// CODE:
import java.util.Scanner;

public class Alakshendra4 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int number = sc.nextInt();
        int factorial = 1;
        for(int i = 1; i <= number; i++){
            factorial *= i;
        }
        System.out.println("The factorial of " + number + " is " + factorial);
        sc.close();
    }
}
