
#include <iostream>
using namespace std;

class Student {
private:
    int roll;
    char name[50];
    float marks[3];

public:
    Student() {
        roll = 0;
        name[0] = '\0';
        marks[0] = marks[1] = marks[2] = 0.0;
    }

    Student(int r, const char n[], float m1, float m2, float m3) {
        roll = r;
        int i = 0;
        while (n[i] != '\0' && i < 49) {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    float getAverage() {
        return (marks[0] + marks[1] + marks[2]) / 3;
    }

    void display() {
        cout << "Roll No: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
        cout << "Average: " << getAverage() << endl << endl;
    }
};

int main() {
    Student s1;
    Student s2(101, "abhi", 78.5, 85.0, 90.0);
    Student s3(102, "archit", 65.0, 70.5, 68.0);

    s1.display();
    s2.display();
    s3.display();

    return 0;
}

