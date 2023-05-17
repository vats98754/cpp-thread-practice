#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex gLock;
static int shared_value = 0;

void shared_value_increment() {
    gLock.lock();
    try {
        ++shared_value;
        throw "dangerous... abort.";
    } catch (...) {
        cout << "Handle exception" << endl;
        return ;
    }
    gLock.unlock();
}

int main() {
    vector <thread> threads;
    for (int i = 0; i < 100; ++i) {
        threads.push_back(thread(shared_value_increment));
    }
    for (int i = 0; i < 100; ++i) {
        threads[i].join();
    }
    cout << "Shared value: " << shared_value << endl;

    return 0;
}