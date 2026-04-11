#include <iostream>
using namespace std;

bool binary_search(int arr[],int size, int to_search){
    int lower = 0;
    int upper = size - 1;
    bool found = false;

    while (lower <= upper){
        int mid = lower +(upper - lower)/2;
        if(to_search > arr[mid]){
            lower = mid + 1;
        }
        
        else if(to_search < arr[mid]){
            upper = mid - 1;
        }
        
        else{
            found = true;
            break;
        }
    }

    return (found);

}

int main(){
    int arr_fxn[] = {34,65,195,200,345,600};
    int size_arr = sizeof(arr_fxn)/sizeof(int);

    int to_find;
    cout << "Enter number to find: ";
    cin >> to_find;

    bool no_found = binary_search(arr_fxn,size_arr,to_find);

    if(no_found){
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" << endl;
    }
}