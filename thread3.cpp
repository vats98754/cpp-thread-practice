#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main() {
    auto lambda = [] (int x) {
        cout << "Hello from thread!" << endl;
        cout << "Argument passed in: " << x << endl;
    };
    vector <thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.push_back(thread(lambda, i));
    }
    for (int i = 0; i < 10; ++i) {
        cout << threads[i].get_id();
        threads[i].join();
    }
    cout << "Hello from the main thread!" << endl;

    return 0;
}