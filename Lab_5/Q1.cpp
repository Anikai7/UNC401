#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
using namespace chrono;

int T1(int n) {  // T(n) = T(n-1) + 1
    return (n <= 0) ? 0 : T1(n-1) + 1;
}

int T2(int n) {  // T(n) = T(n-1) + n
    return (n <= 0) ? 0 : T2(n-1) + n;
}

int T3(int n) {  // T(n) = T(n-1) + n²
    return (n <= 0) ? 0 : T3(n-1) + n*n;
}

int T4(int n) {  // T(n) = T(n-1) + log(n)
    return (n <= 0) ? 0 : T4(n-1) + log(n > 0 ? n : 1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    // Execution time measurement (Task e)
    auto measure = [](auto func, int n) {
        auto start = high_resolution_clock::now();
        func(n);
        auto stop = high_resolution_clock::now();
        return duration_cast<microseconds>(stop - start).count();
    };
    
    cout << "\nTime Analysis (μs):\n";
    cout << "n=" << n << "\t"
        << measure(T1, n) << " μs\t"
        << measure(T2, n) << " μs\t"
        << measure(T3, n) << " μs\t"
        << measure(T4, n) << " μs\n";
    
    // Base case verification (Task c)
    cout << "Small n values:\n";
    for(int i=0; i<=5; i++) {
        cout << "n=" << i << ": "
        << T1(i) << ", "
             << T2(i) << ", "
             << T3(i) << ", "
             << T4(i) << endl;
    }
    

    return 0;
}
