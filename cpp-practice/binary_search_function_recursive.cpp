#include <iostream>
using namespace std;

int binary_search(int arr[],int lower, int upper, int to_search){
    if (lower>upper){
        return (-1);
    }
    int mid = lower +(upper - lower)/2;
    
    if(to_search > arr[mid]){
        binary_search(arr,mid+1,upper,to_search);
        }
        
    else if(to_search < arr[mid]){
        binary_search(arr,lower,mid-1,to_search);
    }
        
    else{
        return (mid);
    }
}

int main(){
    int arr_fxn[] = {34,65,195,200,345,600};
    int size_arr = sizeof(arr_fxn)/sizeof(int);

    int to_find;
    cout << "Enter number to find: ";
    cin >> to_find;

    int no_found = binary_search(arr_fxn,0,size_arr-1,to_find);

    if(no_found == -1){
        cout << "Not Found" << endl;
    }
    else{
        cout << "Found" << endl;
    }
}