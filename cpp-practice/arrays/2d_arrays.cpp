#include <iostream>
using namespace std;

int main(){
    int arr1[2][3]={{10,20,30},{45,64,29}};
    int (*ptr)[3] = arr1;
    for (int n_row = 0; n_row < 2;n_row++){
        for (int n_col = 0; n_col <3; n_col++){
            cout<< arr1[n_row][n_col] << endl;
            cout << *(*(ptr + n_row) +n_col) << endl;
        }
    }

    int arr2[2][3][2]={{{10,20,30},{45,64,29}},{{50,78,34},{45,23,96}}};
    int (*ptr)[3][2] = arr2;
    arr2[1][2][1] = *(*(*arr2 +1)+2)+1)
}