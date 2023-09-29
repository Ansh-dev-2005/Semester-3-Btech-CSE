// wap a java to demonstarate exception handling
// Author: Ansh Garg

class exp {
    public static float divide(int a, int b) {
        float c= a/b;
        return c;

    }
    public static void main(String[] args) {

        int a=1;
        int b=0;
        try {
            System.out.println("TRY Block entered");
            float d = divide(a,b);
            System.out.println("Division is: "+d);
        } catch (ArithmeticException ex) {
            System.out.println("CATCH Block entered");
            System.out.println(ex.getMessage());
        } finally {
            System.out.println("Divide Function Calling Done");
        }
        System.out.println("Program Ended");


            
        
    }
    
}
