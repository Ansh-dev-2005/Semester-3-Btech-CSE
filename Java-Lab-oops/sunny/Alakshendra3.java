// PROBLEM STATEMENT 3: Wite a java program to demonstrate method overloading.
// CODE:
class Alakshendra3 {
    public int add(int a, int b) {
        return a + b;
    }
    public int add(int a, int b, int c) {
        return a + b + c;
    }
    public double add(double a, double b) {
        return a + b;
    }
    public static void main(String[] args) {
        Alakshendra3 calculator = new Alakshendra3();
        int sum1 = calculator.add(10, 20);
        System.out.println("Sum of 10 and 20 is: " + sum1);
        int sum2 = calculator.add(10, 20, 30);
        System.out.println("Sum of 10, 20, and 30 is: " + sum2);
        double sum3 = calculator.add(2.5, 3.5);
        System.out.println("Sum of 2.5 and 3.5 is: " + sum3);
    }
}
