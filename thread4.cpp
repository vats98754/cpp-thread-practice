#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main() {
    auto lambda = [] (int x) {
        cout << "Hello from thread!" << endl;
        cout << "Argument passed in: " << x << endl;
    };
    vector <jthread> jthreads;
    for (int i = 0; i < 10; ++i) {
        jthreads.push_back(jthread(lambda, i));
    }
    for (int i = 0; i < 10; ++i) {
        cout << jthreads[i].id;
        jthreads[i].join();
    }
    cout << "Hello from the main thread!" << endl;

    return 0;
}