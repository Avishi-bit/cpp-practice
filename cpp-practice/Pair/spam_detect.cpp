//Congratulations! You are a winner. Claim your free offer now.
// tokenize the email and create a NLP processor that can detect spam.
// string stream - tokenizing--> vector of pairs ‹string, int› // ‹token, frequency›
// email.txt - read email content from text file.

#include <iostream>
#include <utility>
#include <fstream>
#include <string>

using namespace std;

int main(){

    fstream fp("email.txt");

    if(!fp){
        cout << "File cannot be opened.";
    }

    string word;
    vector<pair<string,int>> words;
    while (fp >> word){
        
    }
}