#include <iostream>
using namespace std;

// Class template for ArraySum
template <typename T>
class ArraySum {
private:
    T* arr;
    int size;

public:
    // Constructor
    ArraySum(T* a, int s) {
        arr = a;
        size = s;
    }

    // Method to calculate sum
    T sum() {
        T total = 0;
        for (int i = 0; i < size; i++) {
            total += arr[i];
        }
        return total;
    }
};

int main() {
    int n;

    // Integer array example
    cout << "Enter number of elements for integer array: ";
    cin >> n;
    int intArr[n];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) cin >> intArr[i];

    ArraySum<int> intSum(intArr, n);
    cout << "Sum of integer array: " << intSum.sum() << endl;

    // Float array example
    cout << "\nEnter number of elements for float array: ";
    cin >> n;
    float floatArr[n];
    cout << "Enter " << n << " float values:\n";
    for (int i = 0; i < n; i++) cin >> floatArr[i];

    ArraySum<float> floatSum(floatArr, n);
    cout << "Sum of float array: " << floatSum.sum() << endl;

    // Double array example
    cout << "\nEnter number of elements for double array: ";
    cin >> n;
    double doubleArr[n];
    cout << "Enter " << n << " double values:\n";
    for (int i = 0; i < n; i++) cin >> doubleArr[i];

    ArraySum<double> doubleSum(doubleArr, n);
    cout << "Sum of double array: " << doubleSum.sum() << endl;

    return 0;
}

