#include <iostream>
using namespace std;

int add(int a, int b)
{
    return (a+b);
}

int subtract(int a, int b)
{
    return (a-b);
}

int multiply(int a, int b){
    return(a*b);
}

int divide(int a, int b){
    return(a/b);
}

int main(){
    //calculator +,-,*,/
    cout << "==========CALCULATOR===========" <<endl;
    cout<< "1. Add"<<endl;
    cout<< "2. Subtract"<<endl;
    cout<< "3. Multiply"<<endl;
    cout << "4. Divide" <<endl;

    int choice;
    cout<< "Enter choice: " ; cin>> choice;

    int num1, num2;

    cout << "number 1: " ; cin >> num1;
    cout << "number 2: "; cin >> num2;

    int (*operation)(int,int);

    switch(choice){
        case 1:
            operation = add;
            break;

        case 2:
            operation = subtract;
            break;

        case 3:
            operation = multiply;
            break;

        case 4:
            operation = divide;
            break;

        default:
            cout << "Invalid.";
    }

    int answer = operation(num1,num2);

    cout << "You answer is: " << answer;

}