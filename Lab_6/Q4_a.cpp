#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> arr) {
    int comparisons = 0, swaps = 0;
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else break;
        }
        arr[j + 1] = key;
    }
    cout << "Insertion Sort:\n";
    cout << "Comparisons: " << comparisons << ", Swaps/Shifts: " << swaps << "\n";
}

void selectionSort(vector<int> arr) {
    int comparisons = 0, swaps = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            comparisons++;
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            swaps++;
        }
    }
    cout << "Selection Sort:\n";
    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << "\n";
}

int main() {
    vector<int> nearlySorted = {101, 102, 103, 105, 104, 106, 107, 109, 108, 110};
    cout << "[Nearly Sorted Scenario]\n";
    insertionSort(nearlySorted);
    selectionSort(nearlySorted);
    cout << "➡ Insertion Sort is better for nearly sorted data due to fewer comparisons and shifts.\n\n";
}
