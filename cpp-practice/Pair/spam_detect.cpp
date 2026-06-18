//Congratulations! You are a winner. Claim your free offer now.
// tokenize the email and create a NLP processor that can detect spam.
// string stream - tokenizing--> vector of pairs ‹string, int› // ‹token, frequency›
// email.txt - read email content from text file.

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>

using namespace std;

int main(){

    fstream fp("email.txt");

    if(!fp){
        cout << "File cannot be opened.";
        return 0;
    }

    string word;

    vector<pair<string,int>> words;

    while(fp >> word){
        bool found = false;
        
        for(char& ch : word){
            ch = tolower(ch);
        }
        
        for(auto& token: words){
            if(token.first == word){
                token.second++;
                found = true;
                break;
            }
        }

        if(!found){
            words.push_back({word,1});
        }
    }

    vector<string> spam_words = {
        "free",
        "winner",
        "offer",
        "claim",
        "money",
        "prize",
        "urgent"
    };

    int spam_score = 0;
    for(auto token: words){
        for(auto spam: spam_words){
            if(token.first == spam){
                cout << "Spam word: " << token.first << endl;
                cout << "Frequency: " <<token.second << endl;
                spam_score += token.second;
            }
        }
    }

    cout << "Spam Score: " << spam_score << endl;

    if(spam_score >= 5){
        cout << "SPAM EMAIL DETECTED." << endl;
    }
    else{
        cout << "LIKELY NOT SPAM."<< endl;
    }

    fp.close();
}