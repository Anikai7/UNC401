#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int countBitstrings(int n) {
    if(n == 0) return 1;
    if(n == 1) return 2;
    return countBitstrings(n-1) + countBitstrings(n-2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Time measurement
    auto measure = [](int n) {
        auto start = high_resolution_clock::now();
        int result = countBitstrings(n);
        auto stop = high_resolution_clock::now();
        return pair(result, duration_cast<microseconds>(stop - start).count());
    };

    auto [result, time] = measure(n);
    cout << "\nCount for n=" << n << ": " << result << endl;
    cout << "Execution time: " << time << " μs\n";
    
    return 0;
}
