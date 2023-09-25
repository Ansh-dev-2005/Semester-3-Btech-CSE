/**WAP in java
 * to demonstrate a model of animal kingdom
 * animals are of 2 kind: birds and mammals
 *create bird object and mammal object and display its characteristics 
 * list of characteristics number of wings, nunber of limbs, nnumber of eyes 
 * demonstrate inheritence concept by identifying classes, identifying which characteristics will belongs to which class 
 * Name:Ansh Garg   
 * Roll No:
 * SAP ID: 500105940
 */
class Animal
{
    int numberOfLimbs=2;
    int numberOfEyes=2;
    public Animal(int numberOfLimbs, int numberOfEyes)
    {
        this.numberOfLimbs = numberOfLimbs;
        this.numberOfEyes = numberOfEyes;
    }
    public void displayCharacteristics()
    {
        System.out.println("Number of Limbs: " + numberOfLimbs);
        System.out.println("Number of Eyes: " + numberOfEyes);
    }
}
class Bird extends Animal
{
    int numberOfWings;

    Bird(int numberOfLimbs, int numberOfEyes, int numberOfWings)
    {
        super(numberOfLimbs, numberOfEyes);
        this.numberOfWings = numberOfWings;
    }
    public void displayCharacteristics()
    {
        super.displayCharacteristics();
        System.out.println("Number of Wings: " + numberOfWings);
    }
}
class Mammal extends Animal
{
    Mammal(int numberOfLimbs, int numberOfEyes)
    {
        super(numberOfLimbs, numberOfEyes);
    }
}

public class p10 {
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