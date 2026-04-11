/* Exercise 1: Basic Pointer Operations
Create a program that:
Declares an integer variable and a pointer to it
Demonstrates address-of (&) and dereference (*) operators
Shows pointer arithmetic with an array
Implements a function that swaps two integers using pointers */


#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int *ptr = &x;

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Pointer: " << ptr << endl;
    cout << "Dereferencing pointer: " << *ptr << endl;

    int arr[5] = {1,2,3,4,5};
    int *p_arr = arr;

    cout << "Array using pointer arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << *(p_arr + i) << endl;
    }

    // swapping
    int a = 5;
    int b = 8;
    cout << "Initially: a = " << a << " b = " << b << endl;
    swap(&a, &b);
    cout << "After swap: a = " << a << " b = " << b << endl;
}