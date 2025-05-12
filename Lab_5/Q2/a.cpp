#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void hanoi(int n, char source, char aux, char dest, int &moves) {
    if(n == 1) {
        moves++;
        return;
    }
    hanoi(n-1, source, dest, aux, moves);
    moves++;
    hanoi(n-1, aux, source, dest, moves);
}

int main() {
    int n, moves = 0;
    cout << "Enter number of disks: ";
    cin >> n;

    auto start = high_resolution_clock::now();
    hanoi(n, 'A', 'B', 'C', moves);
    auto stop = high_resolution_clock::now();

    cout << "\nTotal moves: " << moves << endl;
    cout << "Execution time: " 
         << duration_cast<microseconds>(stop - start).count()
         << " μs" << endl;

    return 0;
}
