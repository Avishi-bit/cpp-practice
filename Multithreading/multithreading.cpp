#include <iostream>
#include <thread>

void thread_task1(){
    std::cout << "I am thread 1 running" << std::endl;
//thread needs to tun code in this fxn when it comes alive
}

void thread_task2(){
    std::cout << "I am thread 2 running" << std::endl;
//thread needs to tun code in this fxn when it comes alive
}

int main(){
    //std::thread --> class, i can create objects of this classto create as many threads as i want
    std::thread t1(thread_task1); //name of first thread - t1
                                    // second parameter = thread ID
    std::thread t2(thread_task2);

    std:: cout << "I am the main function" << std::endl;

    // in case the main function dies before the threads, we need to make the main to wait for the threads to finish
    t1.join(); //allows main to wait for t1 to finish
    t2.join();
}