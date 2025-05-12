#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int fib(int n) {
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Time measurement
    auto start = high_resolution_clock::now();
    int result = fib(n);
    auto stop = high_resolution_clock::now();

    cout << "\nFib(" << n << ") = " << result;
    cout << "\nExecution time: " 
         << duration_cast<microseconds>(stop - start).count()
         << " μs" << endl;

    return 0;
}
