#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;

// global variables
mutex mtx;
// data structure of queue
// conditional variable
condition_variable cv;
queue<int> numbers_q;
// <> template braces


void producer_task(){
    // produce 10 numbers

    for (int i = 0; i<1000; i++){
        unique_lock<mutex> lock(mtx);

        // wait if the data structure is full
        cv.wait(lock, []{return numbers_q.size()<10;});

        numbers_q.push(i);
        cout << "Producer produced #" << i << ". Size of queue: " << numbers_q.size() << endl;

        cv.notify_one(); // notify consumer that producer did smtg
        lock.unlock();

        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer_task(){
    //consume whatever has been produces by the queue
    for (int i=0; i<=1000; i++){
        unique_lock<mutex> lock(mtx);

        //wait
        cv.wait(lock,[]{return !numbers_q.empty();});

        //consumer starts his work
        int temp_val = numbers_q.front();
        numbers_q.pop();
         cout << "consumer consumed#" << temp_val << ". Size of queue: " << numbers_q.size() << endl;
        //consumer's work done here
        cv.notify_one();
        lock.unlock();
        
        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(){
    thread producer(producer_task);
    thread consumer(consumer_task);

    cout << "I am the main program.";

    producer.join();
    consumer.join();

}