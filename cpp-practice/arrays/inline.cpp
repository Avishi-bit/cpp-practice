#include <iostream>
using namespace std;

int factorial(int b){
    if (b <= 1) {
        return 1;
    }
    else {
        return b * factorial(b - 1);
    }
}

inline int sq_number(int a){
    return (a*a);
}

int main(){
    int x;
    cout << "Number: ";
    cin >> x;
    int sq_ans = sq_number(x);
    cout << "Answer: " << sq_ans << endl;
    int fac_ans = factorial(x);
    cout << "Factorial: " << fac_ans << endl;
}