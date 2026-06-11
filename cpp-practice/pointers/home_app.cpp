#include <iostream>
using namespace std;

string lights[5] = {"OFF", "OFF", "OFF", "OFF", "OFF"};

string fridge = "ON";
string microwave = "OFF";

void turn_on_light(int light_no)
{
    lights[light_no - 1] = "ON";
    cout << "Light " << light_no << " turned ON." << endl;
}

void turn_off_light(int light_no)
{
    lights[light_no - 1] = "OFF";
    cout << "Light " << light_no << " turned OFF." << endl;
}


void fridge_on()
{
    fridge = "ON";
    cout << "Fridge ON." << endl;
}

void fridge_off()
{
    fridge = "OFF";
    cout << "Fridge OFF." << endl;
}

void microwave_on()
{
    microwave = "ON";
    cout << "Microwave ON." << endl;
}

void microwave_off()
{
    microwave = "OFF";
    cout << "Microwave OFF." << endl;
}

int main()
{
    int choice = -1;

    do
    {
        cout << endl;
        cout << "===============APPLIANCE MANAGEMENT SYSTEM=================" << endl;
        cout << "1. Turn on lights." << endl;
        cout << "2. Turn off lights." << endl;
        cout << "3. Dim lighting." << endl;
        cout << "4. Brighten lighting." << endl;
        cout << "5. Leaving Home." << endl;
        cout << "6. Coming Home." << endl;
        cout << "7. Manage appliances." << endl;
        cout << "8. Exit." << endl;

        cout << "Enter choice: ";
        cin >> choice;

        void (*operation)(int);

        switch(choice)
        {
            case 1:
            {
                int sub_choice;

                cout << "1. Turn on all lights." << endl;
                cout << "2. Turn on one light." << endl;

                cout << "Enter Choice: "; cin >> sub_choice;

                operation = turn_on_light;

                if(sub_choice == 1)
                {
                    for(int i = 1; i <= 5; i++)
                    {
                        operation(i);
                    }
                }
                else if(sub_choice == 2)
                {
                    int l_no;

                    cout << "Enter light number: ";
                    cin >> l_no;

                    operation(l_no);
                }

                break;
            }

            case 2:
            {
                int sub_choice;

                cout << "1. Turn off all lights." << endl;
                cout << "2. Turn off one light." << endl;

                cout << "Enter Choice: "; cin >> sub_choice;

                operation = turn_off_light;

                if(sub_choice == 1)
                {
                    for(int i = 1; i <= 5; i++)
                    {
                        operation(i);
                    }
                }
                else if(sub_choice == 2)
                {
                    int l_no;

                    cout << "Enter light number: ";
                    cin >> l_no;

                    operation(l_no);
                }

                break;
            }

            case 3:
            {
                operation = turn_off_light;

                for(int i = 3; i <= 5; i++)
                {
                    operation(i);
                }

                operation = turn_on_light;

                for(int i = 1; i <= 2; i++)
                {
                    operation(i);
                }

                cout << "Lighting Dimmed." << endl;

                break;
            }

            case 4:
            {
                operation = turn_on_light;

                for(int i = 1; i <= 5; i++)
                {
                    operation(i);
                }

                cout << "Lighting Brightened." << endl;

                break;
            }

            case 5:
            {
                operation = turn_off_light;

                for(int i = 1; i <= 5; i++)
                {
                    operation(i);
                }

                fridge = "ON";
                microwave = "OFF";
                cout << "Fridge: " << fridge << endl;
                cout << "Microwave: " << microwave << endl;
                cout << "Leaving Home Mode Activated." << endl;

                break;
            }

            case 6:
            {
                operation = turn_on_light;

                for(int i = 1; i <= 2; i++)
                {
                    operation(i);
                }

                fridge = "ON";
                microwave = "ON";
                cout << "Fridge: " << fridge << endl;
                cout << "Microwave: " << microwave << endl;
                
                cout << "Coming Home Mode Activated." << endl;

                break;
            }

            case 7:
            {
                int appliance_choice;
                void (*appliance_operation)();

                cout << "1. Turn Fridge ON" << endl;
                cout << "2. Turn Fridge OFF" << endl;
                cout << "3. Turn Microwave ON" << endl;
                cout << "4. Turn Microwave OFF" << endl;

                cin >> appliance_choice;

                switch(appliance_choice)
                {
                    case 1:
                        appliance_operation= fridge_on;
                        appliance_operation();
                        break;

                    case 2:
                        appliance_operation = fridge_off;
                        appliance_operation();
                        break;

                    case 3:
                        appliance_operation = microwave_on;
                        appliance_operation();
                        break;

                    case 4:
                        appliance_operation = microwave_off;
                        appliance_operation();
                        break;

                    default:
                        cout << "Invalid Choice." << endl;
                }

                break;
            }

            case 8:
                break;

            default:
                cout << "Invalid Choice." << endl;
        }

    } while(choice != 8);

    cout << "Thank you." << endl;

    return 0;
}