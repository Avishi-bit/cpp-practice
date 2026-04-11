#include <iostream>
using namespace std;

void sort_array(int arr_to_p[][3], int n_rows, int n_col){
    //run loop to sort array, return nothing
    // hw
    // if a[i] > a[i+1], then store a[i] in some var, and make a[i] = a[i+1]

    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_col - 1; j++){
            for(int k = 0; k < n_col - j - 1; k++){
                if(arr_to_p[i][k] > arr_to_p[i][k+1]){
                    int temp = arr_to_p[i][k];
                    arr_to_p[i][k] = arr_to_p[i][k+1];
                    arr_to_p[i][k+1] = temp;
                }
            }
        }
    }
}

void print_array(int arr_to_p[][3], int n_rows, int n_col){
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j< n_col ; j++){
            cout << arr_to_p[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arr1[2][3] = {{8,2,4},{56,67,21}};

    sort_array(arr1,2,3);

    cout << "printing array: " << endl;
    print_array(arr1,2,3);
}