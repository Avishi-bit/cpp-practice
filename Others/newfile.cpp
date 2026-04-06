#include <iostream>
using namespace std;

double add(double & a, int & b) {
    return a+b;
}

int main() {
    double num1; int num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    double result = add(num1, num2);
    cout << "Sum = " << result;
    
    cout << endl;
    
    return 0;
}