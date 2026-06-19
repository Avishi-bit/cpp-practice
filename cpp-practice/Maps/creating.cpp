#include <iostream>
#include <map>


using namespace std;

int main(){
    map <int, string> students; // students[int] = string //students [100]
    // map starts making binary search tree
    // use vector and all for small data sets cause v high complexity, maps are much more lenient
    // RED BLACK TREE is a special type of BST, absolute balance (not exactly an AVL)
    // Map is stored as a red black tree --- read abt it

    students[100] = "Shivani";
    students[101] = "Avishi";

    students.insert({102,"Rahul"});

    //retrieve data
    cout << students[100] <<endl; //prints Shivani

    //data is always sorted in the map (the keys)

    for (auto s:students){
        cout << s.first << "-" << s.second << endl;
    }

    auto res = students.find(102);//returns the pointer to the node where the key value is stored

    if( res != students.end()){
        cout << res -> second << endl;
    }

    //erasing data
    students.erase(102);

    //size
    students.size();

    //create a map of students, roll number and marks of 5 subjects
}