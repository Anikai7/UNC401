#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int staircase(int n) {
    if(n <= 1) return 1;
    return staircase(n-1) + staircase(n-2);
}

int main() {
    int n;
    cout << "Enter steps: ";
    cin >> n;

    // Time measurement
    auto start = high_resolution_clock::now();
    int result = staircase(n);
    auto stop = high_resolution_clock::now();

    cout << "\nWays for n=" << n << ": " << result;
    cout << "\nExecution time: " 
         << duration_cast<microseconds>(stop - start).count()
         << " μs" << endl;

    return 0;
}
