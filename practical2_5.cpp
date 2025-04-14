#include <iostream>
#include <cmath>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:
    // Default constructor
    Loan() {
        loanID = 0;
        applicantName = "Unknown";
        loanAmount = 0.0;
        annualInterestRate = 0.0;
        tenureMonths = 0;
    }

    // Parameterized constructor
    Loan(int id, string name, double amount, double rate, int tenure) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = tenure;
    }

    // Calculate EMI
    double calculateEMI() {
        double monthlyRate = annualInterestRate / (12 * 100); // Convert annual to monthly
        if (monthlyRate == 0 || tenureMonths == 0)
            return 0;

        double numerator = loanAmount * monthlyRate * pow(1 + monthlyRate, tenureMonths);
        double denominator = pow(1 + monthlyRate, tenureMonths) - 1;

        return numerator / denominator;
    }

    // Display loan summary
    void displayLoanDetails() {
        cout << "\n--- Loan Summary ---" << endl;
        cout << "Loan ID           : " << loanID << endl;
        cout << "Applicant Name    : " << applicantName << endl;
        cout << "Loan Amount       : $" << loanAmount << endl;
        cout << "Interest Rate     : " << annualInterestRate << "%" << endl;
        cout << "Loan Tenure       : " << tenureMonths << " months" << endl;
        cout << "Monthly EMI       : $" << calculateEMI() << endl;
    }
};

int main() {
    // Create loans
    Loan loan1; // Default loan for testing
    Loan loan2(101, "Alice Johnson", 100000, 7.5, 60);  // 5 years loan
    Loan loan3(102, "Bob Smith", 50000, 10, 24);        // 2 years loan

    // Show loan details
    loan1.displayLoanDetails();
    loan2.displayLoanDetails();
    loan3.displayLoanDetails();

    return 0;
}
