// @file async_buffer.cpp
#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

bool bufferedFileLoader(){
    size_t bytesLoaded = 0;
    while(bytesLoaded < 20000){
        cout << "thread: loading file..." << endl;
        this_thread::sleep_for(chrono::milliseconds(250));
        bytesLoaded += 1000;
    }
    return true;
}

int main(){

    future<bool> backgroundThread = async(launch::async, bufferedFileLoader);

    future_status status;
    // Our main program loop
    while(true){
        cout << "Main thread is running" << endl;
        // artificial sleep for our program
        this_thread::sleep_for(chrono::milliseconds(50));
        status = backgroundThread.wait_for(chrono::milliseconds(1));
        // If our data is ready, that is, our background
        // thread has completed
        if(status == future_status::ready){
            cout << "Our data is ready..." << endl;
            break;
        }

    }

    cout << "Program is complete" << endl;

    return 0;
}