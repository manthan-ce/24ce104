#include <iostream>
#include <vector>
#include <algorithm>  // For reverse function

using namespace std;

// Template function to find the maximum value in a collection
template <typename T>
T findMax(const vector<T>& collection) {
    T maxVal = collection[0];
    for (const T& elem : collection) {
        if (elem > maxVal) {
            maxVal = elem;
        }
    }
    return maxVal;
}

// Template function to reverse the collection
template <typename T>
void reverseCollection(vector<T>& collection) {
    reverse(collection.begin(), collection.end());
}

// Template function to display the collection
template <typename T>
void displayCollection(const vector<T>& collection) {
    for (const T& elem : collection) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    // Create collections of different types
    vector<int> intCollection = {1, 3, 5, 7, 2};
    vector<float> floatCollection = {1.5, 3.2, 5.7, 2.1};
    vector<char> charCollection = {'a', 'z', 'm', 't', 'g'};

    // Operations on integer collection
    cout << "Integer Collection: ";
    displayCollection(intCollection);
    cout << "Maximum value (int): " << findMax(intCollection) << endl;
    reverseCollection(intCollection);
    cout << "Reversed Integer Collection: ";
    displayCollection(intCollection);

    // Operations on float collection
    cout << "\nFloat Collection: ";
    displayCollection(floatCollection);
    cout << "Maximum value (float): " << findMax(floatCollection) << endl;
    reverseCollection(floatCollection);
    cout << "Reversed Float Collection: ";
    displayCollection(floatCollection);

    // Operations on char collection
    cout << "\nChar Collection: ";
    displayCollection(charCollection);
    cout << "Maximum value (char): " << findMax(charCollection) << endl;
    reverseCollection(charCollection);
    cout << "Reversed Char Collection: ";
    displayCollection(charCollection);

    return 0;
}
