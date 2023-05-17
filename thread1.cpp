#include <iostream>
#include <thread>

using namespace std;

void test(int x) {
    cout << "Hello from thread!" << endl;
    cout << "Argument passed in: " << x << endl;
}

int main() {
    thread myThread(&test, 100);
    myThread.join();

    cout << "Hello from the main thread!" << endl;

    return 0;
}