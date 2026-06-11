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
    for (int month = 0; month< MONTHS; month++)
    {
        cout << "Sales data for the month " << month_names[month] << endl;
        for(int day = 0; day < no_of_days[month];  day++){
            cout << "Sales Data for Day " << (day+1) << ": ";
            cin >> sales[month][day];
        }
    }

    cout << "Data added successfully." << endl;
}

void display_sales()
{
    for(int month = 0; month < MONTHS; month++)
    {
        cout << month_names[month] << endl;

        for(int day = 0; day < no_of_days[month]; day++)
        {
            cout << "Day " << (day + 1) << ": " << sales[month][day] << endl;
        }
    }
}

int monthly_total(int month){
    int total = 0;

    for(int day = 0; day < no_of_days[month]; day++){
        total += sales[month][day];
    }

    return total;
}

void monthly_statistics()
{
    for(int month = 0; month < MONTHS; month++)
{
        cout << month_names[month] << " Total Sales: " << monthly_total(month) << endl;
    }
}

void monthly_average()
{
    for(int month = 0; month < MONTHS; month++)
    {
        double average = (double)monthly_total(month) / no_of_days[month];

        cout << month_names[month] << " Average Sales: " << average << endl;
    }
}

void edit_sales()
{
    int month, day, newSale;

    cout << "Enter Month Number (1-12): ";
    cin >> month;

    cout << "Enter Day Number: ";
    cin >> day;

    cout << "Enter New Sale Value: ";
    cin >> newSale;

    sales[month - 1][day - 1] = newSale;

    cout << "Sales data updated successfully." << endl ;
}

void highest_lowest_month()
{
    int highestMonth = 0;
    int lowestMonth = 0;

    int highestTotal = monthly_total(0);
    int lowestTotal = monthly_total(0);

    for(int month = 0; month < MONTHS; month++)
    {
        int total = monthly_total(month);

        if(total > highestTotal)
        {
            highestTotal = total;
            highestMonth = month;
        }

        if(total < lowestTotal)
        {
            lowestTotal = total;
            lowestMonth = month;
        }
    }

    cout << "Highest Sales Month: "<< month_names[highestMonth] << " (" << highestTotal << ")" << endl;

    cout << "Lowest Sales Month: "<< month_names[lowestMonth]<< " (" << lowestTotal << ")" << endl;
}

void search_sales()
{
    int value;
    bool found = false;

    cout << "Enter sales value to search: ";
    cin >> value;

    for(int month = 0; month < MONTHS; month++)
    {
        for(int day = 0; day < no_of_days[month]; day++)
        {
            if(sales[month][day] == value)
            {
                cout << "Found in " << month_names[month] << ", Day "<< (day + 1) << endl;
                found = true;
            }
        }
    }

    if(!found)
    {
        cout << "Value not found.\n";
    }
}


void deinitialize(){
    for (int i = 0; i< MONTHS; i++){
        delete[] sales[i];
    }

    delete[] sales;
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

            case 2:
                display_sales();
                break;

            case 3:
                monthly_statistics();
                break;

            case 4:
                monthly_average();
                break;

            case 5:
                edit_sales();
                break;

            case 6:
                highest_lowest_month();
                break;

            case 7:
                search_sales();
                break;

            case 8:
                deinitialize();
                exit(0);

            default:
                cout << "Invalid choice.\n";
        }   

    } while (user_choice != 8);
    
    deinitialize();
}