class Animal {
    int numberOfLimbs;
    int numberOfEyes;

    public Animal(int numberOfLimbs, int numberOfEyes) {
        this.numberOfLimbs = numberOfLimbs;
        this.numberOfEyes = numberOfEyes;
    }

    public void displayCharacteristics() {
        System.out.println("Number of Limbs: " + numberOfLimbs);
        System.out.println("Number of Eyes: " + numberOfEyes);
    }
}

class Bird extends Animal {
    int numberOfWings;

    Bird(int numberOfLimbs, int numberOfEyes, int numberOfWings) {
        super(numberOfLimbs, numberOfEyes);
        this.numberOfWings = numberOfWings;
    }
    
    public void displayCharacteristics() {
        super.displayCharacteristics();
        System.out.println("Number of Wings: " + numberOfWings);
    }
}

class Mammal extends Animal {
    Mammal(int numberOfLimbs, int numberOfEyes) {
        super(numberOfLimbs, numberOfEyes);
    }
}

public class Ansh
{
    public static void main(String[] args)
    {
        Bird s = new Bird(2, 2, 2);
        System.out.println("Bird:");
        s.displayCharacteristics();
        System.out.println();

        Mammal d = new Mammal(4, 2);
        System.out.println("Mammal:");
        d.displayCharacteristics();
    }
}
