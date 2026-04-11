/* Exercise 2: Dynamic Array Management
Write a program that:
Dynamically allocates an array of integers based on user input size
Fills the array with values using pointer arithmetic
Implements functions to:
Find the maximum value
Calculate the average
Reverse the array
Properly deallocates all memory
*/

#include <iostream>
using namespace std;

int find_max(int *arr, int size) {
    int *ptr = arr;
    int max = *ptr;  

    for (int i = 0; i < size; i++) {
        if (*ptr > max) {
            max = *ptr;
        }
        ptr++;
    }
    return max;
}


double find_avg(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return (double)sum / size;
}

void rev_arr(int *arr, int size) {
    int i = 0;
    while (i < size / 2) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + (size - 1 - i));
        *(arr + (size - 1 - i)) = temp;
        i++;
    }
}

int main() {
    int size;

    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];

    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }

    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << "Max value: " << find_max(arr, size) << endl;
    cout << "Average value: " << find_avg(arr, size) << endl;

    rev_arr(arr, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    delete[] arr;
}