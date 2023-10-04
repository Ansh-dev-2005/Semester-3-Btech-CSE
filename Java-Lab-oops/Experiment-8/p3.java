
// wap a program
// use random number generator function
// use random string generator function
// convert integer into string
// convert integer to float
// convert string to double
// write a program to reverse a string using reverse function
// write a program to reverse a string without using reverse function
// write a program to conver a byte array to string 3 diffrent encoding . print both the byte and string version (write appropiate print statement that 
// describe your output )
import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;
import java.util.Random;
import java.util.Scanner;

public class p3 {
    public static String generateRandomDoubleString(int length) {
        StringBuilder randomString = new StringBuilder(length);

        Random rand = new Random();
        boolean hasDecimalPoint = false;

        for (int i = 0; i < length; i++) {
            // Generate digits 0-9
            char digit = (char) (rand.nextInt(10) + '0');

            // Ensure only one decimal point is inserted
            if (!hasDecimalPoint && i > 0 && rand.nextDouble() < 0.3) {
                randomString.append('.');
                hasDecimalPoint = true;
            }

            randomString.append(digit);
        }

        return randomString.toString();
    }

    public static String reverseString(String str) {
        StringBuilder rev = new StringBuilder(str);
        return rev.reverse().toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();

        System.out.print("Enter a string: ");
        String str = sc.nextLine();

        int randomint = rand.nextInt();
        String randomdoublestring = generateRandomDoubleString(10);

        System.out.println("Random number: " + randomint);
        System.out.println("Random double string: " + randomdoublestring); // Generate a random double-like string
        System.out.println("Integer to string: " + Integer.toString(randomint));
        System.out.println("Integer to float: " + Float.toString(randomint)); // Corrected to float and used
                                                                              // Float.toString()

        // Convert a string to double
        try {
            double parsedDouble = Double.parseDouble(randomdoublestring);
            System.out.println("Random double string to double: " + parsedDouble);
        } catch (NumberFormatException e) {
            System.out.println("Error: Cannot convert the random double string to a double.");
        }

        System.out.println("Reverse string: " + new StringBuilder(str).reverse().toString());
        System.out.println("Reverse string with reverse(): " + reverseString(str));
        byte[] bytes = { 0x41, 0x42, 0x43, 0x44 };
        String byteString = new String(bytes, StandardCharsets.UTF_8);

        System.out.println("Byte array to string (UTF-8): " + byteString);
        System.out.println("Byte array to string (partially): " + new String(bytes, 0, 2, StandardCharsets.UTF_8));

        try {
            String customEncoding = new String(bytes, "ISO-8859-1"); // Example of a different encoding
            System.out.println("Byte array to string (custom encoding): " + customEncoding);
        } catch (UnsupportedEncodingException e) {
            System.out.println("Unsupported encoding exception: " + e.getMessage());
        } finally {
            sc.close();
        }
    }
}
