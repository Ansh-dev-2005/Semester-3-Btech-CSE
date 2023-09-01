import java.util.Scanner;

public class Variables {
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int variable1 = sc.nextInt();
        System.out.println("Enter another number: ");
        int variable2 = sc.nextInt();
        System.out.println("The sum of the two numbers is: " + (variable1 + variable2));
    }
    
    
}
