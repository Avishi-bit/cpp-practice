#include <iostream>
#include <sstream> //string stream

using namespace std;

int main()
{
    string my_sentence = "I love learning c++";
    string token;

    // string - array of characters
    // stringstream - stream of tokens, array of words

    stringstream ss(my_sentence); //stringstream is a class in sstream, we are converting the var to a string stream

    while (ss >> token)
    {
        cout << token <<endl;
    }

}