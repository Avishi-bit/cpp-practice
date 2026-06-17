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
    cout << college_name.find(college_type); // if not found, returns -1

    string subjects = "c++, c, python, java, html";
    if(subjects.find("dhtml") == string::npos) //enum - not present(npos)
        cout << "not found";
    

    cout << subjects.substr(8, 6); //start at idx 8, and length 6 - gives python


    // inserting into strings
    string s = "Hello";
    cout << s.insert(5," World"); //can be inserted anywhere in the string
    
    // erasing from string 
    cout << s.erase(1,5); //starting idx, no. of letter u want removed, returns the deleted thing, here- Hello

    for (char ch: s){ //: - in
        cout << ch; // terminated apne aap only
    }

    // iterator based approach to browse through string
    // iterator = pointers to the first or last element of an array/data structure
    for (auto i = s.begin(); i != s.end(); i++){ // auto as diff systems have diff sizes for them
        cout << *i;
    }

    //convert string to int and int to string
    string s1 = "78";
    int age = stoi(s1);

    int mobile_no = 7042816494;
    string s2 = to_string(mobile_no);
    cout << s2;

    sort(s.begin(), s.end()); //sorts string alphabetically

    //converting case of string
    cout << s.tolower();
    s.toupper();
}   
