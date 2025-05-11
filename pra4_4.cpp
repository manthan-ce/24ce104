
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Base class: BankAccount
class BankAccount {
protected:
    int accountNumber;
    double balance;
    stack<double> transactionHistory; // Stores amounts for undo

public:
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {
        cout << "BankAccount created.\n";
    }

    virtual ~BankAccount() {
        cout << "BankAccount destroyed.\n";
    }

    virtual void deposit(double amount) {
        balance += amount;
        transactionHistory.push(amount); // positive for deposit
        cout << "Deposited: $" << amount << ", New Balance: $" << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactionHistory.push(-amount); // negative for withdrawal
            cout << "Withdrawn: $" << amount << ", New Balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << "\nBalance: $" << balance << endl;
    }

    void undoLastTransaction() {
        if (!transactionHistory.empty()) {
            double last = transactionHistory.top();
            balance -= last;  // reverse the transaction
            transactionHistory.pop();
            cout << "Last transaction undone. New Balance: $" << balance << endl;
        } else {
            cout << "No transactions to undo." << endl;
        }
    }
};

// Derived class: SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, double bal, double rate)
        : BankAccount(accNum, bal), interestRate(rate) {
        cout << "SavingsAccount created.\n";
    }

    ~SavingsAccount() {
        cout << "SavingsAccount destroyed.\n";
    }

    void display() const override {
        BankAccount::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Derived class: CurrentAccount
class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNum, double bal, double limit)
        : BankAccount(accNum, bal), overdraftLimit(limit) {
        cout << "CurrentAccount created.\n";
    }

    ~CurrentAccount() {
        cout << "CurrentAccount destroyed.\n";
    }

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            transactionHistory.push(-amount);
            cout << "Withdrawn: $" << amount << ", New Balance: $" << balance << endl;
        } else {
            cout << "Exceeded overdraft limit!" << endl;
        }
    }

    void display() const override {
        BankAccount::display();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

// Main function to test the banking system
int main() {
    cout << "\n--- Savings Account ---" << endl;
    SavingsAccount sa(1001, 500.0, 2.5);
    sa.deposit(200);
    sa.withdraw(100);
    sa.display();
    sa.undoLastTransaction();
    sa.display();

    cout << "\n--- Current Account ---" << endl;
    CurrentAccount ca(2001, 300.0, 150.0);
    ca.deposit(100);
    ca.withdraw(400); // within overdraft
    ca.withdraw(100); // should fail
    ca.display();
    ca.undoLastTransaction();
    ca.display();

    return 0;
}
