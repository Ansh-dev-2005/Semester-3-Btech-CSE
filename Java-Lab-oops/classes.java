/**WAP in java 
 * Take user input for 3 students
 * insert roll no. name and display them
 * wrute seperate functions for insert and display
 * programm must have 2 classes
 * Name:Ansh Garg
 * Roll No:30
 * SAP ID: 500105940
 */
import java.util.Scanner;

class Student {
    int rollno;
    String name;

    void insert(int r, String n) {
        rollno = r;
        name = n;
    }

    void display() {
        System.out.println(rollno + " " + name);
    }
}

class TestStudent {
    public static void main(String[] args) {
        int num = 3;
        Scanner sc = new Scanner(System.in);
        Student[] arr = new Student[num];

        for (int i = 0; i < num; i++) {
            arr[i] = new Student();
            int j = i + 1;
            System.out.println("Student " + j + " details:");

            System.out.println("Enter Student rollno: ");
            int rollno = sc.nextInt();
            System.out.println("Enter Student name: ");
            String name = sc.next();

            arr[i].insert(rollno, name);
        }
        System.out.println("Student present in the database:");

        for (int i = 0; i < num; i++) {
            arr[i].display();
        }
    }
}
