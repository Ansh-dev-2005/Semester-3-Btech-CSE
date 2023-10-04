public class HAssignment1 {
    static int staticVariable = 10;

    final int finalVariable = 20;

    static void staticMethod() {
        System.out.println("This is a static method.");
    }

    final void finalMethod() {
        System.out.println("This is a final method.");
    }

    public static void main(String[] args) {
        System.out.println("Static Variable: " + HAssignment1.staticVariable);
        HAssignment1.staticMethod();

        HAssignment1 example = new HAssignment1();

        System.out.println("Final Variable: " + example.finalVariable);
        example.finalMethod();

        HAssignment1.staticVariable = 30;
        System.out.println("Modified Static Variable: " + HAssignment1.staticVariable);


        final int modifiedFinalVariable = 40;
        System.out.println("Modified Final Variable: " + modifiedFinalVariable);
    }
}
