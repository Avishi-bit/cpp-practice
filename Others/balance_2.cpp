#include <iostream>
using namespace std;

int main(){
    double balance = 5000;
    int choice_1;
    int choice_2;
    double amount = 0;
    int no_trans;
    bool atm_app = true;

    while (atm_app){
        choice_1 = 2;

        switch(choice_1){
            case 1:
                cout << "Your Balance is: " << balance << endl;
                break;

            case 2:
                no_trans = 3;

                for (int i = 0; i < no_trans; i++){

                    if(i == 0){
                        choice_2 = 1;
                        amount = 1000;
                    }
                    else if(i == 1){
                        choice_2 = 2;
                        amount = 2000;
                    }
                    else{
                        choice_2 = 2;
                        amount = 500;
                    }

                    switch(choice_2){
                        case 1: 
                            balance += amount;
                            cout << "Deposited: " << amount << endl;
                            break;

                        case 2:
                            while (amount > balance){
                                amount = 0;
                            }
                            balance -= amount;
                            cout << "Withdrawn: " << amount << endl;
                            break;
                    }

                    cout << "Balance: " << balance << endl;
                }
                break;

            case 3:
                cout << "Thank you!" << endl;
                atm_app = false;
                break;
        }

    }
}