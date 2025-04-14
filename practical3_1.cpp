#include <iostream>
#include <vector>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    // Constructor with default bonus
    Employee(string n, double bSalary, double b = 1000.0) {
        name = n;
        basicSalary = bSalary;
        bonus = b;
    }

    // Inline function to calculate total salary
    inline double getTotalSalary() {
        return basicSalary + bonus;
    }

    // Display employee details
    void displayDetails() {
        cout << "\n--- Employee Details ---" << endl;
        cout << "Name         : " << name << endl;
        cout << "Basic Salary : $" << basicSalary << endl;
        cout << "Bonus        : $" << bonus << endl;
        cout << "Total Salary : $" << getTotalSalary() << endl;
    }
};

int main() {
    // Using vector to handle dynamic number of employees
    vector<Employee> employees;

    // Adding employees
    employees.push_back(Employee("Alice Smith", 5000));                  // Default bonus
    employees.push_back(Employee("Bob Johnson", 6000, 1500));            // Custom bonus
    employees.push_back(Employee("Charlie Williams", 7000, 2000));       // Custom bonus
    employees.push_back(Employee("Dana Brown", 4500));                   // Default bonus

    // Displaying all employee records
    for (int i = 0; i < employees.size(); i++) {
        employees[i].displayDetails();
    }

    return 0;
}
