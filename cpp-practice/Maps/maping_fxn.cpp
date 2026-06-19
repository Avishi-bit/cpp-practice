//create a map of students, roll number and marks of 5 subjects

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct student{
    string name;
    vector<pair<string,int>> marks; 
    //make a pair so that u have the subject name and marks
};

map <int,student> student_list;

auto search_idx(int rollno){
    for(auto i = student_list.begin(); i != student_list.end(); i++){
        if((*i).first == rollno){
            return (i);
        }
    }

    return student_list.end();
}

void show_all(){
    for(auto std: student_list){
        cout << "Roll Number: " << std.first <<endl;
        cout << "Name: " << std.second.name << endl;
        for(auto subj: std.second.marks){
            cout << "Subject: " << subj.first << "     Marks: " << subj.second << endl;
        }
    }
}

void add_student(){
    student temp;
    int roll_no;

    cout << "Enter Roll Number: "; cin >> roll_no;
    cout << "Enter Name: "; cin >> temp.name;
    string name;
    int mark;
    while(true){
        cout << "Subject (Type EXIT to stop): "; cin >> name;

        if(name == "EXIT"){
            break;
        }

        cout << "Marks: ";cin >> mark;
        temp.marks.push_back({name,mark});
    }
    student_list.insert({roll_no,temp});
}

void del_student(){
    int r_no;
    cout << "Enter Roll Number: "; cin >> r_no;
    cin.ignore();

    auto ptr = search_idx(r_no);

    if(ptr == student_list.end()){
        cout << "Student not found" << endl;
        return;
    }

    cout << "Roll Number: " << (*ptr).first <<endl;
    cout << "Name: " << (*ptr).second.name << endl;
    for(auto subj: (*ptr).second.marks){
        cout << "Subject: " << subj.first << "     Marks: " << subj.second << endl;
    }

    student_list.erase(ptr);

    cout << "Student Deleted." <<endl;
}

void edit_student(){
    cout << "=============SUB MENU==============" <<endl;
    cout << "1. Edit Name" << endl;
    cout << "2. Edit Subjects" << endl;
    cout << "3. Edit Marks" << endl;
    cout << "4. Edit Roll Number" << endl;
    cout << "5. Exit" << endl;

    int choice_1;
    cout << "Enter choice: "; cin >> choice_1;
    cin.ignore();

}

int main(){
    
    int choice;
    do
    {
        //operations etc.
        cout << "=============MENU==============" <<endl;
        cout << "1. Display all Students"<<endl;
        cout << "2. Add a Student" << endl;
        cout << "3. Search a Student"<<endl;
        cout << "4. Remove a Student"<<endl;
        cout << "5. Edit a Student"<<endl;
        cout << "6. EXIT"<<endl;

        cout << "Enter Choice: "; cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                show_all();
                break;
            case 2:
                add_student();
                break;
            case 3:
            {
                int r_n;
                cout << "Enter Roll Number: "; cin >> r_n;
                cin.ignore();
                search_idx(r_n);
                auto ptr = search_idx(r_n);

                if(ptr == student_list.end()){
                    cout << "Student not found" << endl;
                    break;
                }

                cout << "Roll Number: " << (*ptr).first <<endl;
                cout << "Name: " << (*ptr).second.name << endl;
                for(auto subj: (*ptr).second.marks){
                    cout << "Subject: " << subj.first << "     Marks: " << subj.second << endl;
                }
                break;
            }
            case 4:
                del_student();
                break;
            case 5:
                edit_student();
                break;
            case 6:
                break;
            default:
                cout << "Invalid Choice" << endl;
        }

    } while (choice != 6);

    cout << "Thank you." << endl;

}