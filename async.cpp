// @file async.cpp
#include <iostream>
#include <future>

using namespace std;

int square(int x){
    return x*x;
}

int main(){

    future<int> asyncFunction = async(&square,12);
    for(int i=0; i< 10; i++){
        cout << square(i) << endl;
    }

    // We are blocked at the 'get()' operation, until our
    // result has computed
    int result = asyncFunction.get();

    cout << "result is: " << result << endl;

    return 0;
}