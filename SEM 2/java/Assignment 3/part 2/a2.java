interface CreditCardInterface {
    void viewCreditAmount();
    void useCard(double amount);
    void payCredit(double amount);
    void increaseLimit(double amount);
}


class SilverCardCustomer implements CreditCardInterface {
    String name;
    String cardNumber;
    double creditAmount;
    double creditLimit = 50000;

    SilverCardCustomer(String name, String cardNumber) {
        this.name = name;
        this.cardNumber = cardNumber;
        this.creditAmount = 0;
    }

    public void viewCreditAmount() {
        System.out.println(name + "'s Current Credit Amount: " + creditAmount);
    }

    public void useCard(double amount) {
        if (creditAmount + amount <= creditLimit) {
            creditAmount += amount;
            System.out.println("Transaction Successful. Used: " + amount);
        } else {
            System.out.println("Transaction Failed. Credit Limit Exceeded!");
        }
    }

    public void payCredit(double amount) {
        if (amount <= creditAmount) {
            creditAmount -= amount;
            System.out.println("Payment Successful. Paid: " + amount);
        } else {
            System.out.println("Payment Failed. Amount exceeds current credit balance.");
        }
    }

    // Increase Limit (Not applicable for Silver Card)
    public void increaseLimit(double amount) {
        System.out.println("Credit limit cannot be increased for Silver Card Customers.");
    }
}


// GoldCardCustomer Class (Inherits SilverCardCustomer)
class GoldCardCustomer extends SilverCardCustomer {
    private int increaseLimitCount = 0;

    GoldCardCustomer(String name, String cardNumber) {
        super(name, cardNumber);
        this.creditLimit = 100000;  // Override credit limit
    }

    // Override Increase Limit Method
    public void increaseLimit(double amount) {
        if (increaseLimitCount < 3 && amount <= 5000) {
            creditLimit += amount;
            increaseLimitCount++;
            System.out.println("Credit Limit Increased Successfully by " + amount + ". New Limit: " + creditLimit);
        } else if (increaseLimitCount >= 3) {
            System.out.println("Credit Limit Increase Failed. Maximum 3 limit increases allowed.");
        } else {
            System.out.println("Credit Limit Increase Failed. Amount exceeds the per-transaction limit of 5000.");
        }
    }
}


class a2 {
    public static void main(String[] args) {
        // Creating Silver Card Customer
        SilverCardCustomer silverCustomer = new SilverCardCustomer("Rajesh", "1234567890123456");
        silverCustomer.viewCreditAmount();
        silverCustomer.useCard(20000);  // Successful
        silverCustomer.useCard(40000);  // Fails due to limit
        silverCustomer.payCredit(5000); // Successful
        silverCustomer.increaseLimit(5000); // Not applicable for Silver Card
        silverCustomer.viewCreditAmount();

        System.out.println("\n------------------------------------------------\n");

        // Creating Gold Card Customer
        GoldCardCustomer goldCustomer = new GoldCardCustomer("Sujit", "6543210987654321");
        goldCustomer.viewCreditAmount();
        goldCustomer.useCard(80000);    // Successful
        goldCustomer.useCard(30000);    // Fails due to limit
        goldCustomer.payCredit(10000);  // Successful

        // Increasing Limit (3 times)
        goldCustomer.increaseLimit(3000);  // Successful
        goldCustomer.increaseLimit(5000);  // Successful
        goldCustomer.increaseLimit(4000);  // Successful
        goldCustomer.increaseLimit(2000);  // Fails (more than 3 attempts)

        goldCustomer.viewCreditAmount();
    }
}