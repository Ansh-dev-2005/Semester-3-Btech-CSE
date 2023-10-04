// PROBLEM STATEMENT 1:  Write a java program to print the details of product using parameterized constructor.
// CODE:
class Product
{
    int id;
    String name;
    Product(int id, String name)
    {
        this.id=id;
        this.name=name;
    }
    void show()
    {
        System.out.println("Id of the product:"+id);
        System.out.println("Name of the product:"+name);
}
}
class Alakshendra1
{
     public static void main(String[]args)
     {
         Product p1=new Product(101,"keyboard");
         Product p2=new Product(102,"mouse");
         p1.show();
         p2.show();
     }          }
