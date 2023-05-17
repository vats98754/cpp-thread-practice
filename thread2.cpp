#include <iostream>
#include <thread>

using namespace std;

int main() {
    auto lambda = [] (int x) {
        cout << "Hello from thread!" << endl;
        cout << "Argument passed in: " << x << endl;
    };
    thread myThread(lambda, 100);
    myThread.join();

    cout << "Hello from the main thread!" << endl;

    return 0;
}