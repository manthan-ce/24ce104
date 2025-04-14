#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Constructor with no initial balance
    BankAccount(string name, int accNo) {
        accountHolder = name;
        accountNumber = accNo;
        balance = 0.0;
    }

    // Constructor with initial balance
    BankAccount(string name, int accNo, double initialBalance) {
        accountHolder = name;
        accountNumber = accNo;
        balance = initialBalance;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " into account " << accountNumber << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Withdraw money (check for sufficient balance)
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance in account " << accountNumber << endl;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << " from account " << accountNumber << endl;
        }
    }

    // Display account details
    void showSummary() {
        cout << "\n--- Account Summary ---" << endl;
        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

// Main program
int main() {
    // Create accounts using both constructors
    BankAccount acc1("John Doe", 101);                // No initial balance
    BankAccount acc2("Alice Smith", 102, 500.0);      // With initial balance

    // Perform operations
    acc1.deposit(200.0);
    acc1.withdraw(50.0);

    acc2.withdraw(600.0);  // Should fail (insufficient)
    acc2.deposit(300.0);
    acc2.withdraw(600.0);  // Should succeed

    // Display summaries
    acc1.showSummary();
    acc2.showSummary();

    return 0;
}
