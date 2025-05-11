#include <iostream>
#include <vector>
using namespace std;

// Base class: Shape
class Shape {
protected:
    double radius;

public:
    void setRadius(double r) {
        radius = r;
    }

    double getRadius() {
        return radius;
    }
};

// Derived class: Circle
class Circle : public Shape {
public:
    double getArea() {
        return 3.14159 * radius * radius;
    }
};

// Static method: using fixed array
void staticMethod() {
    Circle circles[3];  // Static size

    cout << "\nStatic Method (Array of 3 circles):\n";
    for (int i = 0; i < 3; i++) {
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        circles[i].setRadius(r);
    }

    for (int i = 0; i < 3; i++) {
        cout << "Area of circle " << i + 1 << ": " << circles[i].getArea() << endl;
    }
}

// Dynamic method: using vector
void dynamicMethod() {
    int n;
    cout << "\nEnter number of circles (Dynamic Method): ";
    cin >> n;

    vector<Circle> circles;

    for (int i = 0; i < n; i++) {
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;

        Circle c;
        c.setRadius(r);
        circles.push_back(c);
    }

    for (int i = 0; i < n; i++) {
        cout << "Area of circle " << i + 1 << ": " << circles[i].getArea() << endl;
    }
}

int main() {
    cout << "Circle Area Manager\n";

    staticMethod();   // Using array
    dynamicMethod();  // Using vector

    return 0;
}
