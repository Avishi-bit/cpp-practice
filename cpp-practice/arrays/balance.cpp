#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void atm_trans(double & balance) {
    int choice;
    double amount;
    

    cout << "\n1. Deposit\n2. Withdraw\nEnter choice: ";
    cin >> choice;

    switch(choice){
        case 1: 
            cout << "Amount: ";
            cin >> amount;
            balance += amount;
            break;

        case 2:
            cout << "Amount: ";
            cin >> amount;
            if (amount > balance){
                cout << "Invalid";
            }
            else{
                balance -= amount;
            }
            break;

        default:
            cout << "Invalid choice";

        }
    return;
}


int main(){
    double balance = 5000;
    int n;
     
    auto start_time = high_resolution_clock::now();
    
    cout << "Number of transactions: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        atm_trans(balance);
        cout << "balance: " << balance;
    }
    
    // stop time point
    auto stop_time = high_resolution_clock::now();
    
    //calculating gap bw start and stop:
    auto time_gap = duration_cast<microseconds>(stop_time - start_time);
    cout << "Time taken: " << time_gap.count() << endl;

    return 0;
}