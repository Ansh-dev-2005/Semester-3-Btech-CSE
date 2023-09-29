public class Arithmetic {
public static void main (String[] args) {
int a=2, b=5;
System.out.printf("Multiply %d\n", a*b);
System.out.printf("Addition %d\n", a+b);
System.out.printf("Subtraction %d\n", a-b);
System.out.printf("Division %d\n", a/b);
System.out.printf("Left shift %d\n", a<<b);
System.out.printf("Right shift %d\n", a>>b);
int ans = a>>b;
System.out.println("Right shift "+ans);
}
}