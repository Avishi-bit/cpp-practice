#include <iostream>
using namespace std;

int main(){
    int num = 20;
    double num2 = 345.667;
    int *p = nullptr;
    double* p2 = &num2;

// if i don;t wanna point it to anything, i point it arbitrarily to null
//primitive ways - p ---> NULL or p ---> 0 or p ---> nullptr
    cout << "Printing num: " << num << endl;
    cout << "Printing pointer: " << p << endl;
// * --> value of / value at
// & --> address of
    cout << "Printing address of num: " << &num << endl;
    cout << "Address of p: " << &p << endl;

    p = &num;
    cout << "Printing pointer: " << p << endl;
    cout << "Size of int p: " << sizeof(p) << endl;
    cout << "Size of double p: " << sizeof(p2) << endl;
    cout << "Size of int: " << sizeof(num) << endl;
    cout << "Size of double: " << sizeof(num2) << endl;

    int* new_ptr = nullptr;
    //cout << "Value pointed to by new_ptr: " << *new_ptr << endl; segmentation fault
    // to fix --> if(new_ptr != nullptr){}
    if (new_ptr != nullptr){
        cout << "Value pointed to by new_ptr: " << *new_ptr << endl;
    }

    int arr1[5] = {10,20,56,48,69};
    int* arr_p = arr1;

    for (int i = 0; i<5; i++){
        cout << *(arr_p+i) << endl;
    }

    for (int i = 0; i<5; i++){
        cout << *arr_p << endl;
        arr_p++;
    }

}
//0x - symbol for hexademical 
//segmentation fault = system crashed :P
// accessing a ptr --> accessing the value stored inside a ptr (always check when u access a ptr)