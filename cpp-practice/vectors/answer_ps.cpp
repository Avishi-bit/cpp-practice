/* Problem Statement
A university receives thousands of research papers.

Build a system that:
Stones papers.
Stores authors.
Stores keywords.
Searches papers by keyword.
Counts keyword frequencies.
Finds most common research topics.
Maintains dynamic collections.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct rpaper{
        int rpaper_id;
        vector<string> author_names;
        vector<string> keywords;
        string abstract;
        string topic;
};

vector<rpaper> r_info;
int first_id = 100;

void search_paper(){

    string key;

    cin.ignore();
    cout << "Enter keyword to search: ";
    getline(cin,key);

    bool found = false;

    for(auto& paper : r_info){
        if(find(paper.keywords.begin(),paper.keywords.end(),key) != paper.keywords.end()){
            cout << "Paper ID: "<< paper.rpaper_id << endl;
            cout << "Topic: "<< paper.topic << endl;
            cout << "---------------------------------------------------------------" << endl;
            found = true;
        }
    }

    if(!found){
        cout << "No paper found." << endl;
    }
}

void keyword_freq(){
    string key;
    cin.ignore();
    cout << "Enter keyword: ";
    getline(cin,key);

    int count = 0;
    for(const auto& paper : r_info){
        if(find(paper.keywords.begin(),paper.keywords.end(),key) != paper.keywords.end()){
            count++;
        }
    }

    cout << "Frequency: "<< count << endl;
}

void common_res(){

    if(r_info.empty()){
        cout << "No papers available."<< endl;
        return;
    }

    vector<pair<string,int>> topic_info;
    for(auto& paper : r_info){
        bool found = false;
        for(auto& topic : topic_info){
            if(topic.first == paper.topic){
                topic.second++;
                found = true;
                break;
            }
        }

        if(!found){
            topic_info.push_back({paper.topic,1});
        }
    }

    auto max_topic = topic_info.begin();
    for(auto i = topic_info.begin();i != topic_info.end();i++){
        if((*i).second > (*max_topic).second){
            max_topic = i;
        }
    }

    cout << "Most Common Topic: "<< (*max_topic).first<< endl;
    cout << "Frequency: "<< (*max_topic).second<< endl;
}

void add_paper(){

    cin.ignore();
    rpaper p;
    p.rpaper_id = first_id;
    
    string name;
    while(true){
        cout << "Author Name (Press Enter To Exit): ";
        getline(cin,name);
        
        if(name.empty()){
            break;
        }
        p.author_names.push_back(name);
    }

    string keyw;
    while(true){
        cout << "Keyword (Press Enter To Exit): ";
        getline(cin,keyw);

        if(keyw.empty()){
            break;
        }
        p.keywords.push_back(keyw);
    }

    cout << "Enter abstract: ";
    getline(cin,p.abstract);

    cout << "Enter topic: ";
    getline(cin,p.topic);

    r_info.push_back(p);

    cout << "Paper added successfully." << endl;
    first_id++;
}

void del_paper(){

    int id;
    cout << "Enter Paper ID: ";
    cin >> id;

    for(auto i = r_info.begin();i != r_info.end();i++){
        if((*i).rpaper_id == id){
            r_info.erase(i);
            cout << "Paper deleted."<< endl;
            return;
        }
    }

    cout << "Paper not found." << endl;
}

void edit_paper(){

    int id;
    cout << "Enter Paper ID: "; cin >> id;
    cin.ignore();

    auto found = r_info.end();
    for(auto i = r_info.begin();i != r_info.end();i++){
        if((*i).rpaper_id == id){
            found = i;
            break;
        }
    }

    if(found == r_info.end()){
        cout << "Paper not found." << endl;
        return;
    }

    int choice_1;

    do{
        cout << "========== EDIT MENU ===========" << endl;
        cout << "1.Edit Topic"<< endl;
        cout << "2.Edit Abstract" << endl;
        cout << "3.Add Author" << endl;
        cout << "4.Remove Author" << endl;
        cout << "5.Add Keyword" << endl;
        cout << "6.Remove Keyword" << endl;
        cout << "7.Exit Editing" << endl;

        cout << "Enter choice: "; cin >> choice_1;
        cin.ignore();

        switch(choice_1){
            case 1:
            {
                cout << "Enter New Topic: ";
                getline(cin,(*found).topic);
                cout << "Topic Updated."<< endl;
                break;
            }

            case 2:
            {
                cout << "Enter New Abstract: ";
                getline(cin,(*found).abstract);
                cout << "Abstract Updated." << endl;
                break;
            }

            case 3:
            {
                string author;
                cout << "Author Name: ";
                getline(cin,author);
                
                (*found).author_names.push_back(author);
                cout << "Author Added."<< endl;
                break;
            }

            case 4:
            {
                string author;
                cout << "Author Name To Remove: ";
                getline(cin,author);

                auto find_author = find((*found).author_names.begin(),(*found).author_names.end(),author);
                if(find_author != (*found).author_names.end()){
                    (*found).author_names.erase(find_author);
                    cout << "Author Removed."<< endl;
                }
                
                else{
                    cout << "Author Not Found." << endl;
                }
                break;
            }
            
            case 5:
            {
                string keyword;
                cout << "Keyword: ";
                getline(cin,keyword);
                
                (*found).keywords.push_back(keyword);
                cout << "Keyword Added." << endl;
                break;
            }

            case 6:
            {
                string keyword;
                cout << "Keyword To Remove: ";
                getline(cin,keyword);
                
                auto find_keyw = find((*found).keywords.begin(),(*found).keywords.end(),keyword);

                if(find_keyw != (*found).keywords.end()){
                    (*found).keywords.erase(find_keyw);
                    cout << "Keyword Removed." << endl;
                }
                else{
                    cout << "Keyword Not Found." << endl;
                }
                break;
            }

            case 7:
                break;

            default:
                cout << "Invalid Choice." << endl;
        }

    }while(choice_1 != 7);
}

int main(){

    int choice = -1;
    do{
        cout << "=================MENU==================" << endl;
        cout << "1. Search paper using keywords." << endl;
        cout << "2. Keyword Frequencies in papers." << endl;
        cout << "3. Most common research topics." << endl;
        cout << "4. Add a Paper." << endl;
        cout << "5. Delete a paper." << endl;
        cout << "6. Edit a Paper." << endl;
        cout << "7. Exit." << endl;

        cout << "Enter your choice: "; cin >> choice;

        switch(choice){
            case 1:
                search_paper();
                break;
            case 2:
                keyword_freq();
                break;
            case 3:
                common_res();
                break;
            case 4:
                add_paper();
                break;
            case 5:
                del_paper();
                break;
            case 6:
                edit_paper();
                break;
            case 7:
                break;
            default:
                cout << "Invalid choice.";
        }

    }while(choice!=7);

    cout << "Thank you.";
}

// change the for loops to iterators, use find and all