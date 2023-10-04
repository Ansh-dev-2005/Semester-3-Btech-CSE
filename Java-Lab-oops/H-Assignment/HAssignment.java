import java.util.ArrayList;
import java.util.List;

class Person implements Cloneable {
    String name;
    List<String> hobbies;

    public Person(String name, List<String> hobbies) {
        this.name = name;
        this.hobbies = hobbies;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        // Deep copy
        Person clonedPerson = (Person) super.clone();
        clonedPerson.hobbies = new ArrayList<>(this.hobbies);
        return clonedPerson;
    }
}

public class HAssignment {
    public static void main(String[] args) throws CloneNotSupportedException {
        List<String> hobbies = new ArrayList<>();
        hobbies.add("Reading");
        hobbies.add("Swimming");

        Person person1 = new Person("Alice", hobbies);

        Person person2 = (Person) person1.clone();

        person2.hobbies.add("Painting");

        System.out.println("Output for shallow copy:");
        System.out.println("Person 1 Hobbies: " + person1.hobbies);
        System.out.println("Person 2 Hobbies: " + person2.hobbies);

        List<String> hobbiesCopy = new ArrayList<>(person1.hobbies);
        Person person3 = new Person("Bob", hobbiesCopy);

        person3.hobbies.add("Cooking");


        System.out.println("\nOutput for deep copy:");
        System.out.println("\nPerson 1 Hobbies: " + person1.hobbies);
        System.out.println("Person 3 Hobbies: " + person3.hobbies);

   
    }
}
