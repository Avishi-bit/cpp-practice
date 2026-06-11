#include <iostream>
#include <string>
using namespace std;

int main(){

    string college_name = "NSUT Engineering";
    // copy initialization (explicit object creation using operator overloading)
    //string college_name("NSUT");
    //implicit initialization
    //since string is a class, the name of variable acts as an object
    string name;
    //cin >> name; //will not read spaces
    // string is implemented using the pointer array in order to give us dynamacity
    cout << "Enter Name: ";
    getline(cin,name); //will read spaces

    cout << name.length() << endl; 
    cout << name.size() << endl;

    if (name.empty())
        cout << "String is empty";
    else
        cout << "String has letters";

    cout << name[0] <<endl; //first letter of string, treating name as char array.
    cout << name.at(0); //same as above, treats name as object of string class

    // for concatenation of strings
    // overloading of + opr

    string full_name = name + ": " + college_name;
    cout << full_name;

    name.append("abc");
    cout << "name";

    //comparison of strings is again operator overload
    // >,< compare letter by letter, compare ascii values, a<b, c>b
    string college_type = "Engineering";
    cout << college_name.find(college_type) // if not found, returns -1
    
}   