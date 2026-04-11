#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main(){
    double balance = 5000;
    int choice_1, choice_2;
    double amount = 0;
    int no_trans;
    bool atm_app = true;

    // starting time point

    auto start_time = high_resolution_clock::now();

    while (atm_app){
        cout << "---MENU---\n1.Check Balance\n2.Make transactions\n3.Exit" << endl;
        cout << "Choice: ";
        cin >> choice_1;

        switch(choice_1){
            case 1:
                cout << "Your Balance is: " << balance << endl;
                break;

            case 2:
                cout << "Number of transactions: ";
                cin >> no_trans;

                for (int i = 0; i < no_trans; i++){
                    cout << "---SUB-MENU---\n1.Deposit Amount\n2.Withdraw amount" << endl;
                    cout << "Choice: ";
                    cin >> choice_2;

                    switch(choice_2){
                        case 1: 
                            cout << "Enter amount: " << endl;
                            cin >> amount;
                            balance += amount;
                            break;

                        case 2:
                            cout << "Enter amount: " << endl;
                            cin >> amount;
                            while (amount > balance){
                                cout << "Invalid amount" << endl;
                                cout << "Enter amount: " << endl;
                                cin >> amount;
                            }
                            balance -= amount;
                            break;
                        
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                }
                break;

            case 3:
                cout << "Thank you!" << endl;
                atm_app = false;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    // stop time point
    auto stop_time = high_resolution_clock::now();
    
    //calculating gap bw start and stop:
    auto time_gap = duration_cast<microseconds>(stop_time - start_time);
    cout << "Time taken: " << time_gap.count() << endl;

}