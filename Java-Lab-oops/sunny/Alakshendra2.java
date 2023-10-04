// PROBLEM STATEMENT 2: Write a java program to enter two numbers form command prompt to calculate the sum of numbers

import java.util.Scanner;

class Alakshendra2
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the first number:");
        int a=sc.nextInt();
        System.out.println("Enter the second number:");
        int b=sc.nextInt();
        int sum=a+b;
        System.out.println("Sum of two numbers:"+sum);
    }
}