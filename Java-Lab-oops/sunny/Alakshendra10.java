// Write a java program to demonstrate method overriding

class Alakshendra6 {
    public void display() {
        System.out.println("This is the display() method of the parent class");
    }
}

class Child extends Alakshendra6 {
    public void display() {
        System.out.println("This is the display() method of the child class");
    }
}

class Alakshendra {
    public static void main(String[] args) {
        Child child = new Child();
        child.display();
    }
}
