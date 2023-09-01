import java.util.Scanner;

public class Fibonachi {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements: ");
        int n = sc.nextInt();
        
        if (n <= 0) {
            System.out.println("Invalid input. Please enter a positive integer.");
            return;
        }
        
        if (n == 1) {
            System.out.println("1");
            return;
        }
        
        System.out.println("1: 1");
        int prev = 1;
        int current = 1;
        
        for (int i = 2; i < n; i++) {
            int next = prev + current;
            if (next % 2 == 0) {
                System.out.println(i + ": " + next + "*");
            } else {
                System.out.println(i + ": " + next);
            }
            prev = current;
            current = next;
            
        }
    }
}
