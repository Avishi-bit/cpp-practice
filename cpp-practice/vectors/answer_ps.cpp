#include <iostream>
#include <vector>

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
    cin.ignore();

    bool found = false;

    for(int i=0;i<r_info.size();i++){

        for(int j=0;j<r_info[i].keywords.size();j++){

            if(r_info[i].keywords[j] == key){

                cout << "Paper ID: " << r_info[i].rpaper_id << endl;
                cout << "Topic: " << r_info[i].topic << endl;
                cout << "---------------------------------------------------------------";
                found = true;
                break;
            }
        }
    }

    if(!found)
        cout << "No paper found." << endl;
}

void keyword_freq(){

    string key;
    cin.ignore();
    cout << "Enter keyword: ";
    getline(cin,key);

    int count = 0;

    for(int i=0;i<r_info.size();i++){
        for(int j=0;j<r_info[i].keywords.size();j++){
            if(r_info[i].keywords[j] == key){
                count++;
                break;
            }
        }
    }

    cout << "Frequency: " << count << endl;
}

void common_res(){

    if(r_info.size() == 0){
        cout << "No papers available." << endl;
        return;
    }

    struct topic_count{
        string topic;
        int count;
    };

    vector<topic_count> topic_info;

    for(int i = 0; i < r_info.size(); i++){
        bool found = false;
        for(int j = 0; j < topic_info.size(); j++){
            if(r_info[i].topic == topic_info[j].topic){
                topic_info[j].count++;
                found = true;
                break;
            }
        }

        if(!found){
            topic_count temp;
            temp.topic = r_info[i].topic;
            temp.count = 1;
            topic_info.push_back(temp);
        }
    }

    int max_index = 0;

    for(int i = 1; i < topic_info.size(); i++){
        if(topic_info[i].count > topic_info[max_index].count)
            max_index = i;
    }

    cout << "Most Common Topic: "<< topic_info[max_index].topic << endl;
    cout << "Frequency: "<< topic_info[max_index].count << endl;
}

void add_paper(){

    rpaper p;

    p.rpaper_id = first_id;

    int num;
    cout << "Enter number of authors: "; cin >> num;
    cin.ignore();

    for(int i=0;i<num;i++){
        string author;
        cout << "Author " << i+1 << ": ";
        getline(cin,author);

        p.author_names.push_back(author);
    }

    cout << "Enter number of keywords: ";
    cin >> num;
    cin.ignore();

    for(int i=0;i<num;i++){
        string keyword;
        cout << "Keyword " << i+1 << ": ";
        getline(cin,keyword);

        p.keywords.push_back(keyword);
    }

    cout << "Enter abstract: ";
    getline(cin,p.abstract);

    cout << "Enter topic: ";
    getline(cin,p.topic);

    r_info.push_back(p);

    cout << "Paper added successfully." <<endl;
    first_id++;
}

void del_paper(){

    int id;
    cout << "Enter Paper ID: "; cin >> id;

    for(int i=0;i<r_info.size();i++){
        if(r_info[i].rpaper_id == id){
            r_info.erase(r_info.begin()+i);
            cout << "Paper deleted." <<endl;
            return;
        }
    }

    cout << "Paper not found." <<endl;
}

void edit_paper(){

    int id;
    cout << "Enter Paper ID: "; cin >> id;
    cin.ignore();

    int paper_idx = -1;
    for(int i = 0; i < r_info.size(); i++){
        if(r_info[i].rpaper_id == id){
            paper_idx = i;
            break;
        }
    }

    if(paper_idx == -1){
        cout << "Paper not found.";
        return;
    }

    int choice_1;

    do{

        cout << "========== EDIT MENU =========="<<endl;
        cout << "1. Edit Topic"<<endl;
        cout << "2. Edit Abstract"<<endl;
        cout << "3. Add Author"<<endl;
        cout << "4. Remove Author"<<endl;
        cout << "5. Add Keyword"<<endl;
        cout << "6. Remove Keyword"<<endl;
        cout << "7. Exit Editing"<<endl;

        cout << "Enter choice: "; cin >> choice_1;
        cin.ignore();

    } while (choice_1!=7);
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

}