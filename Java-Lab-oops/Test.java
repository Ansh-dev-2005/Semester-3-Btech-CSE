class Fact
{
    public int factorial(int n)
    {
        int f=1;
        while(n>0)
        {
            f=f*n;
            n--;
        }
        return f;

    }
}

public class Test {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Usage: java Test <number>");
            return;
        }
        Fact obj = new Fact();
        int x=Integer.parseInt(args[0]);
        System.out.println("Factorial of "+x+" is "+obj.factorial(x));
    }        
        
    
}
