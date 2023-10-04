// Write a java program to calculate a length of a string without using length method. Sting should by entered through command prompt.

import java.util.Scanner;

public class Alakshendra5 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String string = sc.nextLine();
        int length = 0;
        for(char c : string.toCharArray()){
            length++;
        }
        System.out.println("The length of the string is " + length);
        sc.close();
    }
}