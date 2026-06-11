#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){

    string file_name;
    cout << "Enter File Name: "; 
    getline(cin,file_name);
    
    ifstream fin(file_name);
    if (!fin){
        cout << "ERROR: File does not exist.";
        return;
    }

    else{
        int count = 0;
        string contents;
        fin >> contents;
        while (count!= contents.length()){
            if ( contents.find("abcd"))

        }

}