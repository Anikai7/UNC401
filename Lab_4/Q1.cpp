#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

// O(1) - Constant Time
void constantTime() {
    int x = 42;
}

// O(log n) - Logarithmic Time
void logarithmicTime(int n) {
    while (n > 1) {
        n /= 2;
    }
}

// O(√n) - Square Root Time
void squareRootTime(int n) {
    for (int i = 0; i < sqrt(n); i++);
}

// O(n) - Linear Time
void linearTime(int n) {
    for (int i = 0; i < n; i++);
}

// O(n log n) - Linearithmic Time (Merge Sort Implementation)
void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    inplace_merge(arr.begin() + l, arr.begin() + mid + 1, arr.begin() + r + 1);
}

void linearithmicTime(int n) {
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    mergeSort(arr, 0, n - 1);
}

// O(n^2) - Quadratic Time
void quadraticTime(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++);
    }
}

// O(n^3) - Cubic Time
void cubicTime(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++);
        }
    }
}

// O(2^n) - Exponential Time (Fibonacci)
int exponentialTime(int n) {
    if (n <= 1) return 1;
    return exponentialTime(n - 1) + exponentialTime(n - 2);
}

// O(n!) - Factorial Time (Recursive Factorial Computation)
long long factorialTime(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorialTime(n - 1);
}

// Function to measure execution time
long long measureTime(void (*func)(int), int n) {
    auto start = high_resolution_clock::now();
    func(n);
    auto stop = high_resolution_clock::now();
    return duration_cast<nanoseconds>(stop - start).count();
}

int main() {
    vector<int> ns = {1, 2, 3, 5, 10, 15, 20, 25, 50, 100};
    ofstream file("complexity_results.csv");
    file << "n,O(1),O(log n),O(√n),O(n),O(n log n),O(n^2),O(n^3),O(2^n),O(n!)\n";
    
    for (int n : ns) {
        file << n << ",";
        
        file << measureTime([](int) { constantTime(); }, 0) << ",";
        file << measureTime(logarithmicTime, n) << ",";
        file << measureTime(squareRootTime, n) << ",";
        file << measureTime(linearTime, n) << ",";
        file << measureTime(linearithmicTime, n) << ",";
        file << measureTime(quadraticTime, n) << ",";
        file << measureTime(cubicTime, n) << ",";
        
        if (n <= 20) {
            auto start = high_resolution_clock::now();
            exponentialTime(n);
            auto stop = high_resolution_clock::now();
            file << duration_cast<nanoseconds>(stop - start).count() << ",";
        } else {
            file << "-" << ",";
        }

        if (n <= 10) {
            auto start = high_resolution_clock::now();
            factorialTime(n);
            auto stop = high_resolution_clock::now();
            file << duration_cast<nanoseconds>(stop - start).count();
        } else {
            file << "!0";
        }

        file << "\n";
    }
    
    file.close();
    cout << "Results saved to complexity_results.csv" << endl;
    return 0;
}
