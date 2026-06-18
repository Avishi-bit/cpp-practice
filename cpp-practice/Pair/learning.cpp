// practice file:  STL Pair

#include <iostream>
#include <utility>

using namespace std;

//int roll_no = 56

//{56, "Shivani"}
pair<int, string> student = {56,"Shivani"};


int main(){
    cout << student.first <<endl; //56
    cout << student.second <<endl; //Shivani

    auto student = make_pair(57,"Avishi");

    vector<pair<int,string>> students;
    students.push_back({109,"Shaam"});
    students.push_back({1681, "Anvi"});
}   