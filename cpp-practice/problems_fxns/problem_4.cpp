#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

double profit(double a,double b){
    return (b-a);
}

int main(){

    int max_profit = 0;
    double a[5] = {5000.00,7860.3,5046.455,6045.563,8962.00};
    auto start_time = high_resolution_clock::now();

    for(int i = 0; i < 4; i++){
        double profit_day = profit(a[i],a[i+1]);
        cout << "Profit on day " << i+1 << " is: $" << profit_day << endl;
        if (profit_day > max_profit){
            max_profit = profit_day;
        }
    }

    cout << "Max profit: $" << max_profit << endl;
    auto end_time = high_resolution_clock::now();
    auto time_gap = duration_cast<microseconds>(end_time - start_time);
    cout << "Time taken: " << time_gap.count() << endl;
}