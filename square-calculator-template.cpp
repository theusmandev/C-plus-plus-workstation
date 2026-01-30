#include <iostream>
using namespace std;

// Template class to calculate square
template <typename T>
class SquareCalculator {
private:
    T number;

public:
    // Constructor
    SquareCalculator(T n) {
        number = n;
    }

    // Function to calculate square
    T square() {
        return number * number;
    }
};

int main() {
    // Integer example
    int i;
    cout << "Enter an integer: ";
    cin >> i;
    SquareCalculator<int> intSquare(i);
    cout << "Square of " << i << " is " << intSquare.square() << endl;

    // Float example
    float f;
    cout << "\nEnter a float: ";
    cin >> f;
    SquareCalculator<float> floatSquare(f);
    cout << "Square of " << f << " is " << floatSquare.square() << endl;

    // Double example
    double d;
    cout << "\nEnter a double: ";
    cin >> d;
    SquareCalculator<double> doubleSquare(d);
    cout << "Square of " << d << " is " << doubleSquare.square() << endl;

    return 0;
}

