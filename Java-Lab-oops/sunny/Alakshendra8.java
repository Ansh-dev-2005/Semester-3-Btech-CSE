class Electricity {
    int units;
    public Electricity(int units) {
        this.units = units;
    }
    public double calculateBill() {
        double bill = 0;
        if (units < 100) {
            bill = 1.20 * units;
        } else if (units < 200) {
            bill = (100 * 1.20) + ((units - 100) * 2);
        } else if (units < 300) {
            bill = (100 * 1.20) + (100 * 2) + ((units - 200) * 3);
        }
        return bill;
    }
}
public class Alakshendra8 {
    public static void main(String[] args) {
        int units = 250; // Change this value to test different units
        Electricity electricity = new Electricity(units);
        double bill = electricity.calculateBill();
        System.out.println("Total units used: " + units);
        System.out.println("Electricity bill: " + bill);
    }
}
