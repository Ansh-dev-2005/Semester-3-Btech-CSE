class Account {
    private int accNo;
    private String name;
    private double balance;

    public void setData(int accNo, String name, double balance) {
        this.accNo = accNo;
        this.name = name;
        this.balance = balance;
    }

    public void display() {
        System.out.println("Account Number: " + accNo);
        System.out.println("Name: " + name);
        System.out.println("Balance: $" + balance);
    }

    public void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println("Withdrawal successful. New balance: $" + balance);
        } else {
            System.out.println("Insufficient funds. Withdrawal failed.");
        }
    }

    public void deposit(double amount) {
        balance += amount;
        System.out.println("Deposit successful. New balance: $" + balance);
    }
}

public class Alakshendra9 {
    public static void main(String[] args) {
        Account myAccount = new Account();
        myAccount.setData(1001, "John Doe", 1000.0);

        myAccount.display(); // Display account information

        myAccount.withdraw(500.0); // Withdraw $500
        myAccount.deposit(200.0); // Deposit $200

        myAccount.display(); // Display updated account information
    }
}
