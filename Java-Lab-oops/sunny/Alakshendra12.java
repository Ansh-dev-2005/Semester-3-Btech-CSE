class Person {
    protected String name;

    public Person(String name) {
        this.name = name;
    }
}

class Employee extends Person {
    private double annualSalary;
    private int startYear;
    private String nationalInsuranceNumber;

    public Employee(String name, double annualSalary, int startYear, String nationalInsuranceNumber) {
        super(name);
        this.annualSalary = annualSalary;
        this.startYear = startYear;
        this.nationalInsuranceNumber = nationalInsuranceNumber;
    }

    public void updateSalary(int currentYear) {
        int yearsWorked = currentYear - startYear;
        if (yearsWorked > 0) {
            double increasePercentage = yearsWorked * 0.05; // Assuming a 5% annual salary increase
            annualSalary += (annualSalary * increasePercentage);
        }
    }

    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Annual Salary: " + annualSalary);
        System.out.println("Start Year: " + startYear);
        System.out.println("National Insurance Number: " + nationalInsuranceNumber);
    }
}

public class Alakshendra12 {
    public static void main(String[] args) {
        Employee emp1 = new Employee("John Doe", 50000.0, 2010, "NI12345");
        Employee emp2 = new Employee("Jane Smith", 60000.0, 2015, "NI67890");

        emp1.displayInfo();
        System.out.println();

        emp2.displayInfo();
        System.out.println();

        emp1.updateSalary(2023);
        emp2.updateSalary(2023);

        emp1.displayInfo();
        System.out.println();

        emp2.displayInfo();
    }
}
