#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, int accNum, double initialBalance = 0.0) {
        accountHolderName = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds. Withdrawal denied." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: $" << balance << endl;
        }
    }

    // Check balance method
    void checkBalance() const {
        cout << "Account Balance: $" << balance << endl;
    }

    // Display account info (can be private if internal use only)
    void displayAccountInfo() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        checkBalance();
    }
};

// Main function to demonstrate functionality
int main() {
    BankAccount customer1("Alice Smith", 1001, 500.00);

    customer1.displayAccountInfo();
    cout << endl;

    customer1.deposit(250.00);
    customer1.withdraw(100.00);
    customer1.withdraw(1000.00);  // Should trigger insufficient funds
    customer1.checkBalance();

    return 0;
}
