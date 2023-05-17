#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

using namespace std;

mutex gLock;
static atomic<int> shared_value = 0;

void shared_value_increment() {
    ++shared_value;
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