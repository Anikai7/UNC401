#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

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
}

void bubbleSort(vector<int> arr) {
    int comparisons = 0, swaps = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
}

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
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int l, int m, int r, int& comparisons, int& swaps) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        comparisons++;
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else {
            arr[k++] = right[j++];
            swaps++;
        }
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSortHelper(vector<int>& arr, int l, int r, int& comparisons, int& swaps) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m, comparisons, swaps);
        mergeSortHelper(arr, m + 1, r, comparisons, swaps);
        merge(arr, l, m, r, comparisons, swaps);
    }
}

void mergeSort(vector<int> arr) {
    int comparisons = 0, swaps = 0;
    mergeSortHelper(arr, 0, arr.size() - 1, comparisons, swaps);
}

int partition(vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; ++j) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

void quickSortHelper(vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);
        quickSortHelper(arr, low, pi - 1, comparisons, swaps);
        quickSortHelper(arr, pi + 1, high, comparisons, swaps);
    }
}

void quickSort(vector<int> arr) {
    int comparisons = 0, swaps = 0;
    quickSortHelper(arr, 0, arr.size() - 1, comparisons, swaps);
}

void timeAlgorithm(const string& name, void(*sortFunc)(vector<int>), vector<int> input) {
    auto start = high_resolution_clock::now();
    sortFunc(input);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << name << " time: " << duration << " ms" << endl;
}

vector<int> generateSorted(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = i;
    return v;
}

vector<int> generateReverse(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = n - i;
    return v;
}

vector<int> generateRandom(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = rand();
    return v;
}

int main() {
    vector<int> sizes = {10, 1000, 10000};

    for (int n : sizes) {
        cout << "\n====== Size: " << n << " ======\n";

        vector<int> best = generateSorted(n);
        vector<int> worst = generateReverse(n);
        vector<int> avg = generateRandom(n);

        cout << "\n-- Best Case (Sorted) --\n";
        timeAlgorithm("Selection Sort", selectionSort, best);
        timeAlgorithm("Bubble Sort", bubbleSort, best);
        timeAlgorithm("Insertion Sort", insertionSort, best);
        timeAlgorithm("Merge Sort", mergeSort, best);
        timeAlgorithm("Quick Sort", quickSort, best);

        cout << "\n-- Worst Case (Reverse) --\n";
        timeAlgorithm("Selection Sort", selectionSort, worst);
        timeAlgorithm("Bubble Sort", bubbleSort, worst);
        timeAlgorithm("Insertion Sort", insertionSort, worst);
        timeAlgorithm("Merge Sort", mergeSort, worst);
        timeAlgorithm("Quick Sort", quickSort, worst);

        cout << "\n-- Average Case (Random) --\n";
        timeAlgorithm("Selection Sort", selectionSort, avg);
        timeAlgorithm("Bubble Sort", bubbleSort, avg);
        timeAlgorithm("Insertion Sort", insertionSort, avg);
        timeAlgorithm("Merge Sort", mergeSort, avg);
        timeAlgorithm("Quick Sort", quickSort, avg);
    }

    return 0;
}
