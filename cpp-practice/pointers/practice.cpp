#include <iostream>
using namespace std;

//use enums as they can be edited and changed as and when we wish
const int MONTHS = 12; //cannot be changed later
int no_of_days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string month_names[MONTHS] = {"Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};

int **sales = new int*[MONTHS];

void initialize(){
    //alocating memory for each internal array
    for (int i = 0; i< MONTHS; i++){
        sales[i] = new int[no_of_days[i]];

        //initializing data to zero
        for (int j = 0; j < no_of_days[i]; j++){
            sales[i][j] = 0;
        }
    }
}

void add_sales()
{
    cout << "here";
    for (int month = 0; month< MONTHS; month++)
    {
        cout << "Sales data for the month" << month_names[month] << endl;
        for(int day = 0; day < no_of_days[month];  day++){
            cout << "Sales Data for: Day " << (day+1);
            cin >> sales[month][day];
        }
    }

    cout << "Data added succesafully.";
}

int main(){

    initialize();
    int user_choice = -1;
    do
    {
        cout << "1. Enter Sales Data" << endl;
        cout << "2. Display All Sales Data." << endl;
        cout << "3. Monthly Sales Statistics" << endl;
        cout << "4. Monthly Average Statistics" << endl;
        cout << "5. Edit Sales Data" << endl;
        cout << "6. Highest/Lowest Sales Month" << endl;
        cout << "7. Seatch Sales Value" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: "; 
        cin >> user_choice; 
        cin.ignore();

        switch(user_choice){
            case 1:
                add_sales();
                break;

            case 8:
                exit(0);
        }

    } while (user_choice != 8);

}