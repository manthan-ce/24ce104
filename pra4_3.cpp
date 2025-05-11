#include <iostream>
#include <string>
#include <queue>
using namespace std;

// Base class: Fuel
class Fuel {
protected:
    string fuelType;

public:
    Fuel(string fuelType) : fuelType(fuelType) {}

    void displayFuel() const {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// Base class: Brand
class Brand {
protected:
    string brandName;

public:
    Brand(string brandName) : brandName(brandName) {}

    void displayBrand() const {
        cout << "Brand: " << brandName << endl;
    }
};

// Derived class: Car inherits from both Fuel and Brand
class Car : public Fuel, public Brand {
public:
    Car(string fuelType, string brandName)
        : Fuel(fuelType), Brand(brandName) {}

    void displayInfo() const {
        displayBrand();
        displayFuel();
    }
};

// Function to simulate service queue
void processServiceQueue(queue<Car>& carQueue) {
    while (!carQueue.empty()) {
        cout << "Processing car:" << endl;
        carQueue.front().displayInfo();
        cout << "------------------------" << endl;
        carQueue.pop();
    }
}

// Main function
int main() {
    // Create several Car objects
    Car car1("Petrol", "Toyota");
    Car car2("Diesel", "Ford");
    Car car3("Electric", "Tesla");

    // Add cars to a queue
    queue<Car> serviceQueue;
    serviceQueue.push(car1);
    serviceQueue.push(car2);
    serviceQueue.push(car3);

    // Process the service queue
    cout << "=== Car Service Queue ===" << endl;
    processServiceQueue(serviceQueue);

    return 0;
}
