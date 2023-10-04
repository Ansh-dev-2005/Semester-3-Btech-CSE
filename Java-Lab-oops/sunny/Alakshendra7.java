class Animal {
    String name;
    public void setName(String name) {
        this.name = name;
    }
    public void speak() {
        System.out.println("The animal makes a sound.");
    }
}
class Dog extends Animal {
    public void speak() {
        System.out.println("The dog barks.");
    }
}
public class Alakshendra7 {
    public static void main(String[] args) {
        Dog myDog = new Dog();
        myDog.setName("Max");

        System.out.println("Name of the dog: " + myDog.name);
        myDog.speak();
    }
}
