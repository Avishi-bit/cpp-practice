//Congratulations! You are a winner. Claim your free offer now.
// tokenize the email and create a NLP processor that can detect spam.
// string stream - tokenizing--> vector of pairs ‹string, int› // ‹token, frequency›
// email.txt - read email content from text file.

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main(){

    // open the file
    fstream fp("email.txt");

    // check if file is open
    if(!fp){
        cout << "File cannot be opened.";
        return 0;
    }

    string word;
    vector<pair<string,int>> words;

    // vetor of spam words
    vector<string> spam_words = {
        "free",
        "winner",
        "offer",
        "claim",
        "money",
        "prize",
        "urgent"
    };

    // vector of extra characters
    vector<string> characters = {
        ".",
        ",",
        "!",
        "@",
        "#",
        "(",
        ")",
        ";",
        ":",
        "?"
    };

    while(fp >> word){
        
        //transform words to be matched to similar case
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        // cleaning of data
        // 1. extract only needed tokens - do away w articles, conjunctions etc.
        // 2. look for fancy special characters and remove them.

        //erasing the extra characters
        for(auto ch:characters){
            auto index = word.find(ch);
            if(index != string::npos){
                word.erase(index,1);
            }
        }

        // find if word is in spam words
        if(find(spam_words.begin(),spam_words.end(),word) != spam_words.end()){
            bool found = false;
            //browse through tokens
            for(auto& token: words){
                if(token.first == word){
                    token.second++;
                    found = true;
                    break;
                }
            }
            if (!found){
                words.push_back({word,1});
            }
        }
    }



    int spam_score = 0;
    for(auto token: words){
        cout << "Spam word: " << token.first << endl;
        cout << "Frequency: " << token.second << endl;
        spam_score += token.second;
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