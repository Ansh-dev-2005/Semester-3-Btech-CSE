// PROBLEM STATEMENT 11: Wrtie a java program to count number of objects using static variable
// CODE: 
class ObjectCounter {
    static int count = 0;

    public ObjectCounter() {
        count++;
    }

    public static int getCount() {
        return count;
    }
}

public class Alakshendra11 {
    public static void main(String[] args) {
        ObjectCounter obj1 = new ObjectCounter();
        ObjectCounter obj2 = new ObjectCounter();
        ObjectCounter obj3 = new ObjectCounter();

        System.out.println("Number of objects created: " + ObjectCounter.getCount());
    }
}


