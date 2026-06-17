#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string file_name;
    cout << "Enter file name: ";
    getline(cin, file_name);

    ifstream fin(file_name);

    if (!fin) {
        cout << "ERROR: File does not exist." <<endl;
        return -1;
    }


    int line_no = 1;
    string contents;
    
    while (getline(fin,contents))
    {
        int indxs_of_str[100];
        int count = 0;

        int idx_found = contents.find("abc");

        while (idx_found != -1)
        {
            indxs_of_str[count] = idx_found;
            count++;

            idx_found = contents.find("abc", idx_found + 1);
        }

        cout << "Occurrences: " << count << endl;

        for (int i = 0; i < count; i++)
        {
            cout << indxs_of_str[i] << " ";
        }   
    }

    int indxs_of_str[100];
    int count = 0;

    int idx_found = contents.find("abc");

    while (idx_found != -1)
    {
        indxs_of_str[count] = idx_found;
        count++;

        idx_found = contents.find("abc", idx_found + 1);
    }

    cout << "Occurrences: " << count << endl;

    for (int i = 0; i < count; i++)
    {
        cout << indxs_of_str[i] << " ";
    }
    cout << endl;
}