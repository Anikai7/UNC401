#include <iostream>
#include <vector>

using namespace std;

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

void selectionSort(vector<int> arr) {
    int comparisons = 0, swaps = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            swaps++;
        }
    }
    cout << "Selection Sort Result: ";
    printArray(arr);
    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << "\n\n";
}

void bubbleSort(vector<int> arr) {
    int comparisons = 0, swaps = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    cout << "Bubble Sort Result: ";
    printArray(arr);
    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << "\n\n";
}

void insertionSort(vector<int> arr) {
    int comparisons = 0, swaps = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        comparisons++;
        arr[j + 1] = key;
    }
    cout << "Insertion Sort Result: ";
    printArray(arr);
    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << "\n\n";
}

void merge(vector<int>& arr, int l, int m, int r, int& comparisons, int& swaps) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        comparisons++;
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            swaps++;  // Count as swap-like operation
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
    cout << "Merge Sort: ";
    printArray(arr);
    cout << "Comparisons: " << comparisons << ", Swaps (approx.): " << swaps << "\n\n";
}

int partition(vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    int pivot = arr[high];
    int i = low - 1;
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
    cout << "Quick Sort: ";
    printArray(arr);
    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << "\n\n";
}

// Main
int main() {
    vector<int> arr = {64, 25, 12, 22, 11, 90, 55, 43, 88, 19};

    selectionSort(arr);
    bubbleSort(arr);
    insertionSort(arr);
    mergeSort(arr);
    quickSort(arr);

    return 0;
}