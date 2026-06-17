#include <iostream>
#include <vector>

using namespace std;

int main(){
    int num[100]; //static array

    vector<int> nums; //tell vector kausa datatype hei, STL dynamoc array of datatype int, no size, not initialised.
    nums.reserve(1000); //memory allocation for the the first 1000 elements happens
    // inserting elements into a vector
    // 1. inserting at the end
    nums.push_back(20); //adds element to the end of the array, cannot add in bw anywhere though
    nums.push_back(23);
    nums.push_back(100);

    //2. inserting in bw
    nums.insert(nums.begin()+1,102); //no indexes, we only have to put in an iterator

    cout << nums[1] << endl;
    cout << nums.at(1)<< endl;

    cout << nums.capacity(); //total memory allocated for the vector
    cout << nums.size()<< endl; //no. of elements in vector

    //deleting from a vector
    //1. from the end
    nums.pop_back(); // removing the last element from the vector

    //2. delete in bw
    nums.erase(nums.begin()+2);
    //browsing through the vector
    //1. element based
    for (int elt: nums)
    {
        cout << elt<< endl;
    }

    for(auto i = nums.begin(); i!=nums.end();i++)
    {
        cout << *i<< endl;
    }
}