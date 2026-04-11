#include <iostream>
using namespace std;

int main(){
    int my_numbers[5]= {10,20,25,30,50};

    // searching an array
    // search number = 30
    int search_token = 30;
    for (int cntr = 0; cntr < 5; cntr++){
        if (my_numbers[cntr] == search_token){
            cout << "value found at index: " << cntr << endl;
            break;
        }
    }

    int upper = sizeof(my_numbers)/sizeof(int)-1;
    int lower = 0;
    bool found = false;

    while (upper >= lower){
        int mid = lower + (upper-lower)/2;
        if(search_token > my_numbers[mid]){
            lower = mid + 1;
        }
        
        else if(search_token < my_numbers[mid]){
            upper = mid - 1;
        }
        
        else{
            cout << "Value found at index: " << mid << endl;
            found = true;
            break;
        }
    }

    if (!found){
        cout << "Value not found!" << endl;
    }
}