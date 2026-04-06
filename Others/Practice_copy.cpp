#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void printing_stuff(){
    for (int i = 0; i <1000; i++){
        cout << "Ready";
    }
}
int main(){
    auto start_time = high_resolution_clock::now();

    printing_stuff();

    auto stop_time = high_resolution_clock::now();

    //calculating gap bw start and stop:
    auto time_gap = duration_cast<microseconds>(stop_time - start_time);
    cout << "Time taken: " << time_gap.count() << endl;
}